/**HEADER**********************************************************************
 *
 * Copyright (c) 2011 Freescale Semiconductor;
 * All Rights Reserved
 *
 ******************************************************************************
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
 ******************************************************************************
 *
 * $FileName: init_bsp.c$
 * $Version : 3.8.6.0$
 * $Date    : Jun-6-2012$
 *
 * Comments:
 *   This file contains the source functions for functions required to
 *   specifically initialize the card.
 *
 *END*************************************************************************/

#include "mqx_inc.h"
#include "bsp.h"
#include "bsp_prv.h"

const char _PTR_ _mqx_bsp_revision = REAL_NUM_TO_STR(BSP_REVISION);
const char _PTR_ _mqx_io_revision  = REAL_NUM_TO_STR(IO_REVISION);

static void    _bsp_setup_watchdog(void);

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

    _mqx_set_cpu_type(MQX_CPU);

#if MQX_EXIT_ENABLED
    /* Set the bsp exit handler, called by _mqx_exit */
    _mqx_set_exit_handler(_bsp_exit_handler);
#endif

    /* === Debugging is not allowed from here === */
    /* Initialize the interrupt handling */
    result = _psp_int_init(BSP_FIRST_INTERRUPT_VECTOR_USED, BSP_LAST_INTERRUPT_VECTOR_USED);
    /* === Debugging may now resume === */
    if (result != MQX_OK) {
        return result;
    }

    /* set possible new interrupt vector table - if MQX_ROM_VECTORS = 0 switch to
    ram interrupt table which was initialized in _psp_int_init) */
    (void)_int_set_vector_table(BSP_INTERRUPT_VECTOR_TABLE);

    /** bsp low level internal initialization. ***/
    _bsp_low_level_init();


    /* Initialize the system ticks */
    kernel_data->TIMER_HW_REFERENCE = (BSP_BUS_CLOCK / BSP_ALARM_FREQUENCY);
    /* Install the timer with interrupt */
    _mtim16_timer_install_kernel(BSP_TIMER, BSP_ALARM_FREQUENCY, BSP_BUS_CLOCK, BSPCFG_TIMER_INT_LEVEL, TRUE);


    /* MCG initialization and internal oscillators trimming */
    if (CM_ERR_OK != _bsp_set_clock_configuration(BSP_CLOCK_CONFIGURATION_AUTOTRIM))
    {
        return MQX_TIMER_ISR_INSTALL_FAIL;
    }

    if (CM_ERR_OK != _bsp_osc_autotrim())
    {
        return MQX_TIMER_ISR_INSTALL_FAIL;
    }

    /* Switch to startup clock configuration */
    if (CM_ERR_OK != _bsp_set_clock_configuration(BSP_CLOCK_CONFIGURATION_STARTUP))
    {
        return MQX_TIMER_ISR_INSTALL_FAIL;
    }


#if BSPCFG_ENABLE_CPP
   /* initialize C++ constructors */
   __cpp_init();
#endif  /* BSPCFG_ENABLE_CPP */


    /* Install low power support */
#if MQX_ENABLE_LOW_POWER
     /* PMPROT write once register is set in _bsp_low_level_init() */
    _lpm_install (LPM_CPU_OPERATION_MODES, LPM_OPERATION_MODE_RUN);
#endif /* MQX_ENABLE_LOW_POWER */

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
    _kuart_polled_install("ttya:", &_bsp_uart0_init, _bsp_uart0_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_ITTYA
    _kuart_int_install("ittya:", &_bsp_uart0_init, _bsp_uart0_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_TTYB
    _kuart_polled_install("ttyb:", &_bsp_uart1_init, _bsp_uart1_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_ITTYB
    _kuart_int_install("ittyb:", &_bsp_uart1_init, _bsp_uart1_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_SPI0
   _spi16_polled_install("spi0:", &_bsp_spi0_init);
#endif

#if BSPCFG_ENABLE_ISPI0
   _spi16_int_install("ispi0:", &_bsp_spi0_init);
#endif

#if BSPCFG_ENABLE_SPI1
   _spi16_polled_install("spi1:", &_bsp_spi1_init);
#endif

#if BSPCFG_ENABLE_ISPI1
   _spi16_int_install("ispi1:", &_bsp_spi1_init);
#endif

#if BSPCFG_ENABLE_I2C0
    _ki2c_polled_install("i2c0:", &_bsp_i2c0_init);
#endif
#if BSPCFG_ENABLE_II2C0
    _ki2c_int_install("ii2c0:", &_bsp_i2c0_init);
#endif

#if BSPCFG_ENABLE_I2C1
    _ki2c_polled_install("i2c1:", &_bsp_i2c1_init);
#endif
#if BSPCFG_ENABLE_II2C1
    _ki2c_int_install("ii2c1:", &_bsp_i2c1_init);
#endif

#if BSPCFG_ENABLE_I2C2
    _ki2c_polled_install("i2c2:", &_bsp_i2c2_init);
#endif
#if BSPCFG_ENABLE_II2C2
    _ki2c_int_install("ii2c2:", &_bsp_i2c2_init);
#endif

#if BSPCFG_ENABLE_I2C3
    _ki2c_polled_install("i2c3:", &_bsp_i2c3_init);
#endif
#if BSPCFG_ENABLE_II2C3
    _ki2c_int_install("ii2c3:", &_bsp_i2c3_init);
#endif

/* Install the USB DCD driver */
#if BSPCFG_ENABLE_USBDCD
    _kusb_dcd_polled_install("usbdcd:", &_bsp_usb_dcd_init);
#endif
#if BSPCFG_ENABLE_IUSBDCD
    _kusb_dcd_int_install("usbdcd:", &_bsp_usb_dcd_init);
#endif

#if BSPCFG_ENABLE_FLASHX
    _io_flashx_install("flashx:", &_bsp_flashx_init);
#endif

/* Install the PCCard Flash drivers */
#if BSPCFG_ENABLE_PCFLASH
    _io_pccardflexbus_install("pccarda:", (PCCARDFLEXBUS_INIT_STRUCT _PTR_) &_bsp_cfcard_init);
    _io_apcflash_install("pcflasha:");
#endif

/* Install the GPIO driver */
#if BSPCFG_ENABLE_GPIODEV
    _io_gpio_install("gpio:");
#endif

#if BSPCFG_ENABLE_ADC
    _io_adc_install("adc:", (pointer) &_bsp_adc0_init);
#endif


/* Install the CRC driver */
#if BSPCFG_ENABLE_CRC
    CRC_init();
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
    _int_mask_all();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_setup_watchdog
* Returned Value   : uint_32
* Comments         :
*   This function initializes the watchdog timer according to the definition
*   MCF51JF_WATCHDOG_INITIALIZATION in <BOARD_NAME>.h
*
*END*----------------------------------------------------------------------*/

static void _bsp_setup_watchdog
    (
        void
    )
{

    __RESET_WATCHDOG();

#if MCF51JF_WATCHDOG_INITIALIZATION != MCF51JF_WATCHDOG_DISABLED
    SIM_SOPT1 = 0
#if MCF51JF_WATCHDOG_INITIALIZATION == MCF51JF_WATCHDOG_RESET
#error User manual says SOPT should be set to zero always
             | SIM_COPC_COPT(0)
#endif
             | SIM_COPC_COPT(MCF51JF_WATCHDOG_DELAY)&(~ SIM_COPC_COPW_MASK)
             | SIM_COPC_COPW_MASK;
#endif
} /* Endbody */

/* EOF */
