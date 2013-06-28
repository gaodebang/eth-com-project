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
* $Version : 3.8.2.0$
* $Date    : Oct-1-2012$
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

#include <pxn2020_cw.h>

const char _PTR_ _mqx_bsp_revision = REAL_NUM_TO_STR(BSP_REVISION);
const char _PTR_ _mqx_io_revision  = REAL_NUM_TO_STR(IO_REVISION);

/* Only use when debugging with JTAG and cache and MMU are interferring
** with the debugging
*/
//volatile uint_32 _mqx_monitor_type = MQX_MONITOR_TYPE_BDM;
extern volatile uint_32 _mqx_monitor_type;
#define BSP_CACHE_INHIBIT  1


#if BSP_USE_PAGE_TABLES

/* Defined in link.met */
extern uchar __PAGE_TABLE_START;
extern uchar __PAGE_TABLE_SIZE;
extern uchar __VIRTUAL_MEMORY_START;
extern uchar __VIRTUAL_MEMORY_SIZE;

PSP_MMU_VINIT_STRUCT mmu_init = {
    /* MMU_PAGE_TABLE_BASE  */ &__PAGE_TABLE_START,
    /* MMU_PAGE_TABLE_SIZE  */ (uint_32)&__PAGE_TABLE_SIZE,

/* Needed for virtual contexts */
    /* UNMAPPED_MEMORY_BASE */ &__VIRTUAL_MEMORY_START,
    /* UNMAPPED_MEMORY_SIZE */ (uint_32)&__VIRTUAL_MEMORY_SIZE
};

#endif


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

    _GET_KERNEL_DATA(kernel_data);

    _mqx_set_cpu_type(PSP_CPU_MPXN20);

    /* Set the bsp exit handler, called by _mqx_exit */
    _mqx_set_exit_handler(_bsp_exit_handler);

    /* Initialize the MPXNxx MMU support functions */
    _mpxnxx_initialize_support();

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

#if BSPCFG_ENABLE_PIT_TIMER
    _qpit_timer_install_kernel(BSPCFG_TIMER_PIT_DEVICE, BSPCFG_TIMER_PIT_CHANNEL, BSP_ALARM_FREQUENCY, BSP_SYSTEM_CLOCK, BSPCFG_TIMER_INT_LEVEL);
#else
    _e200_decrementer_timer_install(BSP_ALARM_FREQUENCY, BSP_TIMEBASE_CLOCK);
#endif

    /*------------------------------------------------------------------------*/
    /*
     ** Setup MMU page tables
     */

    if (_mqx_monitor_type == MQX_MONITOR_TYPE_NONE) {
        _mmu_init(NULL);
        /* First, mark the three TLBs that the boot code used as 'not-free' */
        _mmu_reserve_tlb(BSP_FLASH_TLB);
        _mmu_reserve_tlb(BSP_INT_SRAM_TLB);
        
        /* Periph B Modules */
        _mmu_reserve_tlb(BSP_PERIPHERAL_TLB); 
        _mmu_reserve_tlb(BSP_EXT_RAM_TLB);

        _mmu_reserve_tlb(BSP_PERIPHERAL_A_TLB);
        
        /* Next, add regions for RAM.
         **                        Physical Address       Virtual Address              Size                    Attributes
         */
        //_mmu_add_virtual_region((BSP_PRIVATE_RAM_START),  BSP_PRIVATE_RAM_START,       BSP_PRIVATE_RAM_SIZE,   BSP_PRIVATE_RAM_ATTR,        BSP_PID_MQX);                
        //_mmu_add_virtual_region((BSP_UNCACHED_DATA_START),BSP_UNCACHED_DATA_START,     BSP_UNCACHED_DATA_SIZE, BSP_UNCACHED_DATA_ATTR,      BSP_PID_MQX);
                
        /* switch PID from 1 (boot) to 2 (MQX) */
        /*_psp_set_pid(BSP_PID_MQX);*/
               
         /*Reclaim the BOOT RAM TLB*/        
        /*_mmu_release_tlb(BSP_RAM_TLB);*/

#ifndef BSP_CACHE_INHIBIT
        _icache_enable(0);
        _dcache_enable(0);
#endif
    } 

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
    _lin_serial_polled_install("ttya:", &_bsp_lin0_init);
#endif
#if BSPCFG_ENABLE_ITTYA
    _lin_serial_int_install("ittya:", &_bsp_lin0_init);
#endif


#if BSPCFG_ENABLE_TTYB
    _lin_serial_polled_install("ttyb:", &_bsp_lin1_init);
#endif
#if BSPCFG_ENABLE_ITTYB
    _lin_serial_int_install("ittyb:", &_bsp_lin1_init);
#endif

    
#if BSPCFG_ENABLE_TTYC
    _lin_serial_polled_install("ttyc:", &_bsp_lin2_init);
#endif
#if BSPCFG_ENABLE_ITTYC
    _lin_serial_int_install("ittyc:", &_bsp_lin2_init);
#endif

    
#if BSPCFG_ENABLE_TTYD
    _lin_serial_polled_install("ttyd:", &_bsp_lin3_init);
#endif
#if BSPCFG_ENABLE_ITTYD
    _lin_serial_int_install("ittyd:", &_bsp_lin3_init);
#endif

    
#if BSPCFG_ENABLE_TTYE
    _lin_serial_polled_install("ttye:", &_bsp_lin4_init);
#endif
#if BSPCFG_ENABLE_ITTYE
    _lin_serial_int_install("ittye:", &_bsp_lin4_init);
#endif

    
#if BSPCFG_ENABLE_TTYF
    _lin_serial_polled_install("ttyf:", &_bsp_lin5_init);
#endif
#if BSPCFG_ENABLE_ITTYF
    _lin_serial_int_install("ittyf:", &_bsp_lin5_init);
#endif


#if BSPCFG_ENABLE_SPI0
    _io_spi_install("spi0:", &_bsp_spi0_init);
#endif

#if BSPCFG_ENABLE_SPI1
    _io_spi_install("spi1:", &_bsp_spi1_init);
#endif

#if BSPCFG_ENABLE_SPI2
    _io_spi_install("spi2:", &_bsp_spi2_init);
#endif

#if BSPCFG_ENABLE_SPI3
    _io_spi_install("spi3:", &_bsp_spi3_init);
#endif

    
#if BSPCFG_ENABLE_FLASHX
    _io_flashx_install("flashx:", &_bsp_flashx_init);
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
   #if BSPCFG_ENABLE_LWADC0
      _lwadc_init(&lwadc0_init);
   #endif
#endif
      
    /* Initialize the default serial I/O */
    _io_serial_default_init();

#endif // BSPCFG_ENABLE_IO_SUBSYSTEM

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
