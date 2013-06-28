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
* $Version : 3.8.8.0$
* $Date    : Sep-25-2012$
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

#include <pxs2010_cw.h>

const char _PTR_ _mqx_bsp_revision = REAL_NUM_TO_STR(BSP_REVISION);
const char _PTR_ _mqx_io_revision  = REAL_NUM_TO_STR(IO_REVISION);

/* Only use when debugging with JTAG and cache and MMU are interferring
** with the debugging
*/
//volatile uint_32 _mqx_monitor_type = MQX_MONITOR_TYPE_BDM;
volatile uint_32 _mqx_monitor_type = MQX_MONITOR_TYPE_NONE;
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

    _mqx_set_cpu_type(MQX_CPU);

    /* Set the bsp exit handler, called by _mqx_exit */
    _mqx_set_exit_handler(_bsp_exit_handler);

    /* Initialize the MPXSxx support functions */
    #if 0 /* Not required, MMU not used */
    _mpxsxx_initialize_support();
    #endif

    /* === Debugging is not allowed from here === */
    /* Initialize the interrupt handling */
    result = _psp_int_init(BSP_FIRST_INTERRUPT_VECTOR_USED, BSP_LAST_INTERRUPT_VECTOR_USED);
    /* === Debugging may now resume === */
    if (result != MQX_OK) {
        return result;
    }

    /* Initialize peripheral bridge */
    //_qpbridge_init(pbridge_mprot_config, ELEMENTS_OF(pbridge_mprot_config));

    /* Initialize Enhanced Interrupt Controller */
    result =  _qintc_install(_bsp_get_qintc_base_address(), PSP_EXCPT_EXTERNAL);
    if (result != MQX_OK) {
        return result;
    }

    /* enable processor recognition of External/Decrementer/Fit interrupts */
    _PSP_SET_SR (_PSP_GET_SR() | PSP_MSR_EE);

#if 0
    /* Install program exception handler */
    if (_int_install_isr(PSP_EXCPT_PROGRAM,
                         _psp_program_isr, NULL) == NULL)
    {
        return _task_get_error();
    }
#endif

#if BSPCFG_ENABLE_PIT_TIMER
    _qpit_timer_install_kernel(BSPCFG_TIMER_PIT_DEVICE, BSPCFG_TIMER_PIT_CHANNEL, BSP_ALARM_FREQUENCY, BSP_PERIPHERAL_CLOCK, BSPCFG_TIMER_INT_LEVEL);
    //_e200_decrementer_null_install();
#else
    _e200_decrementer_timer_install(BSP_ALARM_FREQUENCY, BSP_TIMEBASE_CLOCK);
#endif

    /*------------------------------------------------------------------------*/
    /*
    ** Setup MMU page tables
    */

    if (_mqx_monitor_type == MQX_MONITOR_TYPE_NONE) {
#ifndef BSP_CACHE_INHIBIT
        _icache_enable(0);
        _dcache_enable(0);
#endif
    } /* Endif */


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

#if BSPCFG_ENABLE_SPI2
    _io_spi_install("spi2:", &_bsp_spi2_init);
#endif

#if BSPCFG_ENABLE_FLASHX
    _io_flashx_install("flashx:", &_bsp_flashx_init);
#endif

#if BSPCFG_ENABLE_LWADC
#if BSPCFG_ENABLE_LWADC0
    _lwadc_init(&lwadc0_init);
#endif    
#if BSPCFG_ENABLE_LWADC1
    _lwadc_init(&lwadc1_init);
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
