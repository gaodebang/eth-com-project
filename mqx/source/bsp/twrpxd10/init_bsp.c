/**HEADER********************************************************************
*
* Copyright (c) 2008-2011 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2011 Embedded Access Inc.;
* All Rights Reserved
*
***************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: init_bsp.c$
* $Version : 3.8.3.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This file contains the source functions for functions required to
*   specifically initialize the card.
*
*END************************************************************************/

#include "mqx_inc.h"
#include "bsp.h"
#include "bsp_prv.h"
#include "io_rev.h"
#include "bsp_rev.h"

#include <MPXD10_cw.h>

const char _PTR_ _mqx_bsp_revision = REAL_NUM_TO_STR(BSP_REVISION);
const char _PTR_ _mqx_io_revision  = REAL_NUM_TO_STR(IO_REVISION);

/* Only use when debugging with JTAG and cache and MMU are interferring
** with the debugging
*/
//volatile uint_32 _mqx_monitor_type = MQX_MONITOR_TYPE_BDM;
volatile uint_32 _mqx_monitor_type = MQX_MONITOR_TYPE_NONE;

#define BSP_CACHE_INHIBIT
#ifndef BSP_CACHE_INHIBIT
#error  "MPC560xS/MPXD10 uses e200z0h cachelessness core. BSP_CACHE_INHIBIT must be defined" 
#endif


#if BSP_USE_PAGE_TABLES
#error "MPC560xS/MPXD10 does not have MMU. BSP_USE_PAGE_TABLES must be disabled"
#endif


void CLOCK_ENABLE_ALL_PERIPH(void)
{
   /* Enbable all peripheral clocks */   
   
   CGM.SC_DC[2].B.DIV = BSP_SYSTEM_CLOCK / BSP_PERI3_CLOCK  -1;    /* Enable System Clock Divider */
   CGM.SC_DC[2].B.DE = 0x1;    /* Enable System Clock Divider */
   
   CGM.SC_DC[1].B.DIV = BSP_SYSTEM_CLOCK / BSP_PERI2_CLOCK  -1;    /* Enable System Clock Divider */
   CGM.SC_DC[1].B.DE = 0x1;    /* Enable System Clock Divider */

   CGM.SC_DC[0].B.DIV = BSP_SYSTEM_CLOCK / BSP_PERI1_CLOCK  -1;    /* Enable System Clock Divider */
   CGM.SC_DC[0].B.DE = 0x1;    /* Enable System Clock Divider */
   ME.RUNPC[0].R=0x000000FE; /* Peripheral ON in every mode */

   /* Re-enter in DRUN mode to update */
   ME.MCTL.R = 0x30005AF0;        /* Mode & Key */
   ME.MCTL.R = 0x3000A50F;        /* Mode & Key */
}

void Config_Clkout(int clk,int seldiv)
{
   SIU.PCR[103].R      = 0x0E00;         // PG12 clkout
   CGM.OCDS_SC.B.SELDIV = seldiv;
   CGM.OC_EN.R          = 1;           // Enable Output Clock
   CGM.OCDS_SC.B.SELCTL = clk;
}


void ClockInit(uint32_t freq_in_mhz)
{
  uint32_t fvco, fextal, odf, idf, ndiv, prm;
  idf = 0;
  odf = 3;
  fextal = 8; /* External EXTAL = 8MHZ */
  
  CLOCK_ENABLE_ALL_PERIPH();
  
  /* Note: Clock init by using PLL0, clkout = 64Mhz */
  freq_in_mhz = 64; /* must in range 16~64Mhz */
  
  CGM.FXOSC_CTL.R = 0x00800001;
  // while(!CGM.OSC_CTL.B.S_OSC);        // Wait for clock to stabilise
  ME.DRUN.B.FXOSCON = 1; /* Switch on external osc */
  ME.DRUN.B.SYSCLK = 3; /* Select external osc */

  /* RE  enter the drun mode, to update the configuration */
  ME.MCTL.R = 0x30005AF0; /* Mode & Key */
  ME.MCTL.R = 0x3000A50F; /* Mode & Key inverted */
  while (ME.GS.B.S_MTRANS == 1)
    ; /* Wait for mode entry to complete */
  while (ME.GS.B.S_CURRENTMODE != 3)
    ; /* Check DRUN mode has been entered */

  /* Max bus 64Mhz, VCO 256-512Mhz */
  //fvco=freq_in_mhz*2^(odf+1) and fvco/freq_in_mhz=ndiv/(idf+1)
  prm = 1 << (odf + 1);
  fvco = freq_in_mhz * prm;
  while (fvco > 512) {
    odf--;
    prm = 1 << (odf + 1);
    fvco = freq_in_mhz * prm;
  }
  ndiv = fvco / fextal;

  CGM.FMPLL[0].CR.B.IDF = idf; /* Divide by 1 */
  CGM.FMPLL[0].CR.B.ODF = odf; /* Divide by 16 */
  CGM.FMPLL[0].CR.B.NDIV = ndiv; /* Loop divide by 64 */

  ME.DRUN.B.FMPLL0ON = 1; /* enable pll */
  ME.DRUN.B.FXOSCON = 1; /* system clock is IRC */
  ME.DRUN.B.SYSCLK = 0x3; /* system clock is IRC */

  /* RE enter the drun mode, to update the configuration */
  ME.MCTL.R = 0x30005AF0; /* Mode & Key */
  ME.MCTL.R = 0x3000A50F; /* Mode & Key inverted */
  while (ME.GS.B.S_MTRANS == 1)
    ; /* Wait for mode entry to complete */
  while (ME.GS.B.S_CURRENTMODE != 0x3)
    ; /* Check DRUN mode has been entered */

  /* wait for PLL to lock - will not lock before DRUN re-entry */
  while (CGM.FMPLL[0].CR.B.S_LOCK == 0)
    ;

  ME.DRUN.B.SYSCLK = 0x4; /* system clock is PLL */
  ME.MCTL.R = 0x30005AF0; /* Mode & Key */
  ME.MCTL.R = 0x3000A50F; /* Mode & Key inverted */
  while (ME.GS.B.S_MTRANS == 1)
    ; /* Wait for mode entry to complete */
  while (ME.GS.B.S_CURRENTMODE != 0x3)
    ; /* Check DRUN mode has been entered */

  while (ME.GS.B.S_SYSCLK != 4)
    ; /* fail is stuck here  */
#ifdef BSP_CLKOUT
  Config_Clkout(2, BSP_CLKOUT_DIV ); /* OUT */
#endif  

  
}
/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_enable_card
* Returned Value   : uint_32 result
* Comments         :
*   This function sets up operation of the card.
*
*END*----------------------------------------------------------------------*/

uint_32 _bsp_enable_card
    (
        void
    )
{
    KERNEL_DATA_STRUCT_PTR        kernel_data;
    uint_32                       result;

    /* Init Clock first*/
    ClockInit(SYSTEM_CLOCK);
    
    _GET_KERNEL_DATA(kernel_data);

    _mqx_set_cpu_type(PSP_CPU_MPXD10);

    /* Set the bsp exit handler, called by _mqx_exit */
    _mqx_set_exit_handler(_bsp_exit_handler);

    /* === Debugging is not allowed from here === */
    /* Initialize the interrupt handling */
    result = _psp_int_init(BSP_FIRST_INTERRUPT_VECTOR_USED, BSP_LAST_INTERRUPT_VECTOR_USED);
    /* === Debugging may now resume === */
    if (result != MQX_OK) {
        return result;
    }
    result = _qintc_install(_bsp_get_qintc_base_address(), PSP_EXCPT_EXTERNAL);
    if (result != MQX_OK) {
        return result;
    }

    /* enable processor recognition of External/Decrementer/Fit interrupts */
    _PSP_SET_SR (_PSP_GET_SR() | PSP_MSR_EE);

#if 0
    /* Install program exception handler */
    if (_int_install_isr(PSP_EXCPT_PROGRAM, _psp_program_isr, NULL) == NULL)
    {
        return _task_get_error();
    }
#endif

#ifdef BSPCFG_TIMER_PIT_DEVICE
    _qpit_timer_install_kernel(BSPCFG_TIMER_PIT_DEVICE, BSPCFG_TIMER_PIT_CHANNEL, BSP_ALARM_FREQUENCY, BSP_SYSTEM_CLOCK, BSPCFG_TIMER_INT_LEVEL);
#else
    _e200_decrementer_timer_install(BSP_ALARM_FREQUENCY, BSP_TIMEBASE_CLOCK);
#endif

    
#if BSPCFG_ENABLE_CPP

    /* initialize C++ constructors */
#if defined(__DCC__) || defined(__HIGHC__)
    __init();
#elif defined(__CODEWARRIOR__)
    __cpp_init();
#endif

#endif //BSPCFG_ENABLE_CPP
    

#if BSPCFG_ENABLE_IO_SUBSYSTEM
    /*------------------------------------------------------------------------*/
    /*
    ** Initialize the I/O Sub-system
    */
    result = _io_init();
    if (result != MQX_OK) {
        return result;
    } /* Endif */

    /* Install device drivers */

#if BSPCFG_ENABLE_TTYA    
    _linflexd_serial_polled_install("ttya:", &_bsp_linflexd0_init);
#endif
#if BSPCFG_ENABLE_ITTYA
    _linflexd_serial_int_install("ittya:", &_bsp_linflexd0_init);
#endif

#if BSPCFG_ENABLE_TTYB
    _linflexd_serial_polled_install("ttyb:", &_bsp_linflexd1_init);
#endif
#if BSPCFG_ENABLE_ITTYB
    _linflexd_serial_int_install("ittyb:", &_bsp_linflexd1_init);
#endif
    
#if BSPCFG_ENABLE_SPI0
    _io_spi_install("spi0:", &_bsp_spi0_init);
#endif

#if BSPCFG_ENABLE_SPI1
    _io_spi_install("spi1:", &_bsp_spi1_init);
#endif

#if BSPCFG_ENABLE_FLASHX
    _io_flashx_install("flashx:", &_bsp_data_flashx_init);
     /* code flash */
     /* _io_flashx_install("flashx_code:", &_bsp_code_flashx_init); */
#endif

#if BSPCFG_ENABLE_I2C0
    _qi2c_polled_install("i2c0:", &_bsp_i2c0_init);
#endif
    
#if BSPCFG_ENABLE_II2C0
    _qi2c_int_install("ii2c0:", &_bsp_i2c0_init);
#endif

#if BSPCFG_ENABLE_I2C1
    _qi2c_polled_install("i2c1:", &_bsp_i2c1_init);
#endif
    
#if BSPCFG_ENABLE_II2C1
   _qi2c_int_install("ii2c1:", &_bsp_i2c1_init);
#endif

#if BSPCFG_ENABLE_I2C2
    _qi2c_polled_install("i2c2:", &_bsp_i2c2_init);
#endif

#if BSPCFG_ENABLE_II2C2
   _qi2c_int_install("ii2c2:", &_bsp_i2c2_init);
#endif
   
#if BSPCFG_ENABLE_I2C3
    _qi2c_polled_install("i2c3:", &_bsp_i2c3_init);
#endif

#if BSPCFG_ENABLE_II2C3
   _qi2c_int_install("ii2c3:", &_bsp_i2c3_init);
#endif

#if BSPCFG_ENABLE_RTCDEV
   _rtc_init (RTC_INIT_FLAG_CLEAR | RTC_INIT_FLAG_RESET | RTC_INIT_FLAG_ENABLE);
#endif
   
#if BSPCFG_ENABLE_LWADC
   _lwadc_init(&_lwadc0_init);
#endif
      
    /* Initialize the default serial I/O */
   _io_serial_default_init();

#endif /* BSPCFG_ENABLE_IO_SUBSYSTEM */

    return MQX_OK;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_exit_handler
* Returned Value   : none
* Comments         :
*    This function is called when MQX exits
*
*END*----------------------------------------------------------------------*/

void _bsp_exit_handler
    (
        void
    )
{
#ifndef BSP_CACHE_INHIBIT
    _dcache_flush();
    _dcache_disable();
    _icache_disable();
#endif
}
/* EOF */
