/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
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
* $Version : 3.8.41.0$
* $Date    : Oct-4-2011$
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
#include "rtc.h"

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
{ /* Body */
   KERNEL_DATA_STRUCT_PTR   kernel_data;
   uint_32                  result;

   /* Set the CPU type */
   _mqx_set_cpu_type(MQX_CPU);

#if MQX_EXIT_ENABLED
   /* Set the bsp exit handler, called by _mqx_exit */
   _mqx_set_exit_handler(_bsp_exit_handler);
#endif

   /* Initialize the MCF5225 support functions */
   _mcf5225_initialize_support(0);

   /*
   ** Initialize the interrupt handling
   */
   /* Mask all interrupts */
   _mcf5225_int_mask_all();

   _int_set_vector_table(BSP_INTERRUPT_VECTOR_TABLE);

   result =  _psp_int_init(BSP_FIRST_INTERRUPT_VECTOR_USED,
      BSP_LAST_INTERRUPT_VECTOR_USED);
   if (result != MQX_OK) {
      return result;
   } /* Endif */

   /* Initialize the timer interrupt */
   _time_set_timer_vector(BSP_TIMER_INTERRUPT_VECTOR);
   if (_int_install_isr(BSP_TIMER_INTERRUPT_VECTOR, _bsp_timer_isr, NULL) == NULL)
   {
      return MQX_TIMER_ISR_INSTALL_FAIL;
   } /* Endif */

   _GET_KERNEL_DATA(kernel_data);

   kernel_data->TIMER_HW_REFERENCE = _pit_init_freq(BSP_TIMER, BSP_ALARM_FREQUENCY, BSP_SYSTEM_CLOCK/2, FALSE);

   _time_set_hwtick_function(_pit_get_hwticks, (pointer)BSP_TIMER);
   _time_set_hwticks_per_tick(kernel_data->TIMER_HW_REFERENCE);
   _time_set_ticks_per_sec(BSP_ALARM_FREQUENCY);

   _pit_unmask_int(BSP_TIMER);

#if BSPCFG_ENABLE_CPP
   /* initialize C++ constructors */
   __cpp_init();
#endif

   /* Initialize RTC and MQX time */
#if BSPCFG_ENABLE_RTCDEV
   _bsp_rtc_io_init ();
   _rtc_sync_with_mqx (TRUE);
#endif

#if BSPCFG_ENABLE_IO_SUBSYSTEM
   /* Initialize the I/O Sub-system */
   result = _io_init();
   if (result != MQX_OK) {
      return result;
   } /* Endif */

   /* Install device drivers */
#if BSPCFG_ENABLE_TTYA
   _mcf52xx_uart_serial_polled_install("ttya:", &_bsp_uart0_init,
      _bsp_uart0_init.QUEUE_SIZE);
#endif
#if BSPCFG_ENABLE_TTYB
   _mcf52xx_uart_serial_polled_install("ttyb:", &_bsp_uart1_init,
      _bsp_uart1_init.QUEUE_SIZE);
#endif
#if BSPCFG_ENABLE_TTYC
   _mcf52xx_uart_serial_polled_install("ttyc:", &_bsp_uart2_init,
      _bsp_uart2_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_ITTYA
   _mcf52xx_uart_serial_int_install("ittya:", &_bsp_uart0_init,
      _bsp_uart0_init.QUEUE_SIZE);
#endif
#if BSPCFG_ENABLE_ITTYB
   _mcf52xx_uart_serial_int_install("ittyb:", &_bsp_uart1_init,
      _bsp_uart1_init.QUEUE_SIZE);
#endif
#if BSPCFG_ENABLE_ITTYC
   _mcf52xx_uart_serial_int_install("ittyc:", &_bsp_uart2_init,
      _bsp_uart2_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_I2C0
   _mcf52xx_i2c_polled_install("i2c0:", &_bsp_i2c0_init);
#endif
#if BSPCFG_ENABLE_I2C1
   _mcf52xx_i2c_polled_install("i2c1:", &_bsp_i2c1_init);
#endif
#if BSPCFG_ENABLE_II2C0
   _mcf52xx_i2c_int_install("ii2c0:", &_bsp_i2c0_init);
#endif
#if BSPCFG_ENABLE_II2C1
   _mcf52xx_i2c_int_install("ii2c1:", &_bsp_i2c1_init);
#endif

#if BSPCFG_ENABLE_SPI0
   _mcf5xxx_qspi_polled_install("spi0:", &_bsp_qspi0_init);
#endif

#if BSPCFG_ENABLE_ISPI0
   _mcf5xxx_qspi_int_install("ispi0:", &_bsp_qspi0_init);
#endif

   /* Initialize the default serial I/O */
   _io_serial_default_init();
   
   /* Install the GPIO driver */
#if BSPCFG_ENABLE_GPIODEV   
   _io_gpio_install("gpio:");
#endif

/* install internal flash */
#if BSPCFG_ENABLE_FLASHX
    _io_flashx_install("flashx:", &_bsp_flashx_init);
#endif

   /* Install the PCCard Flash drivers */
#if BSPCFG_ENABLE_PCFLASH   
   _io_pccardflexbus_install("pccarda:", (PCCARDFLEXBUS_INIT_STRUCT _PTR_) &_bsp_cfcard_init);
   _io_apcflash_install("pcflasha:");
#endif

    /* ADC initialization */
#if BSPCFG_ENABLE_ADC
   _io_adc_install("adc:", NULL);
#endif


#endif

   
   /*
   ** Enable/disable the watchdog timer   
   ** The initialization mode is defined by BSP_WATCHDOG_INITIALIZATION macro
   */
   _bsp_setup_watchdog();

   return MQX_OK;

} /* Endbody */


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
{ /* Body */

   (void)_psp_set_sr(0x2700);
   _mcf5225_int_mask_all();

} /* Endbody */


/*ISR*********************************************************************
*
* Function Name    : _bsp_timer_isr
* Returned Value   : void
* Comments         :
*    The timer ISR is the interrupt handler for the clock tick.
*
*END**********************************************************************/

void _bsp_timer_isr
   (
      pointer dummy
   )
{ /* Body */
#if BSP_WATCHDOG_INITIALIZATION != BSP_WATCHDOG_DISABLED
   // Service the watchdog timer to verify we are still in control
   VMCF5225_STRUCT_PTR reg_ptr = _PSP_GET_IPSBAR();
   reg_ptr->SCM.CWSR = 0x55;
   reg_ptr->SCM.CWSR = 0xAA;
#endif

   _pit_clear_int(BSP_TIMER);
   _time_notify_kernel();

} /* Endbody */


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_setup_watchdog
* Returned Value   : uint_32
* Comments         :
*   This function initializes the watchdog timer according to the definition
*   BSP_WATCHDOG_INITIALIZATION 
*
*END*----------------------------------------------------------------------*/

static void _bsp_setup_watchdog
   (
      void
   )
{ /* Body */

   VMCF5225_STRUCT_PTR reg_ptr = _PSP_GET_IPSBAR();

   reg_ptr->SCM.CWCR = 0;

   if (reg_ptr->SCM.CWCR & MCF5225_SCM_CWCR_CWTAVAL) {
      reg_ptr->SCM.CWCR = MCF5225_SCM_CWCR_CWTAVAL;
   } /* Endif */
   if (reg_ptr->SCM.CWCR & MCF5225_SCM_CWCR_CWTIC) {
      reg_ptr->SCM.CWCR = MCF5225_SCM_CWCR_CWTIC;
   } /* Endif */

   // Clear the watchdog count
   reg_ptr->SCM.CWSR = 0x55;
   reg_ptr->SCM.CWSR = 0xAA;

#if BSP_WATCHDOG_INITIALIZATION != BSP_WATCHDOG_DISABLED
   reg_ptr->SCM.CWCR = 0
# if BSP_WATCHDOG_INITIALIZATION == BSP_WATCHDOG_RESET
# error User manual says CWRI should be set to zero always
      | MCF5225_SCM_CWCR_CWRI
# endif
      | MCF5225_SCM_CWCR_CWE
      | MCF5225_SCM_CWCR_CWT(BSP_WATCHDOG_DELAY);
#endif

} /* Endbody */


/* EOF */
