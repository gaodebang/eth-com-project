/**HEADER********************************************************************
*
* Copyright (c) 2012 Freescale Semiconductor;
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
* Comments:
*   This file contains the source functions for functions required to
*   specifically initialize the card.
*
*END************************************************************************/

#include "mqx_inc.h"
#include "bsp.h"
#include "bsp_prv.h"
#include "io_rev.h"
#include "bsp_rev.h"
#include "cortexa5.h"

#include "core_mutex.h"


const char _PTR_ _mqx_bsp_revision = REAL_NUM_TO_STR(BSP_REVISION);
const char _PTR_ _mqx_io_revision  = REAL_NUM_TO_STR(IO_REVISION);
_mem_pool_id _BSP_sram_pool;

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_enable_card
* Returned Value   : uint_32 result
* Comments         :
*   This function sets up operation of the card.
*
*END*----------------------------------------------------------------------*/
uint_32 _bsp_enable_card(void)
{
    uint_32_ptr L1PageTable;
    uint_32 result;
    uint_32 addr = 0;
    KERNEL_DATA_STRUCT_PTR kernel_data;

    _mqx_set_cpu_type(MQX_CPU);

#if MQX_EXIT_ENABLED
    _mqx_set_exit_handler(_bsp_exit_handler);
#endif

    _a5_initialize_support();

    result = _psp_int_init(BSP_FIRST_INTERRUPT_VECTOR_USED, BSP_LAST_INTERRUPT_VECTOR_USED);

    if (result != MQX_OK)
        return result;

    init_gic();

    result = _gt_install_kernel(BSP_TIMER, 0, BSP_ALARM_FREQUENCY, BSP_TIMER_FREQUENCY, BSP_TIMER_PRIORITY);

    /* Initialize the system ticks */
    //_GET_KERNEL_DATA(kernel_data);
    //kernel_data->TIMER_HW_REFERENCE = (BSP_SYSTEM_CLOCK / BSP_ALARM_FREQUENCY);

    if (_mqx_monitor_type == MQX_MONITOR_TYPE_NONE)
    {
        /* Enable MMU and L1 cache */
        /* alloc L1 mmu table */
        L1PageTable = _mem_alloc_align(MMU_TRANSLATION_TABLE_SIZE, MMU_TRANSLATION_TABLE_ALIGN);
        /* None cacheable is comon with strongly ordered. MMU doesnt work with another init configuration */
        _mmu_vinit(PSP_PAGE_TABLE_SECTION_SIZE(PSP_PAGE_TABLE_SECTION_SIZE_1MB) | PSP_PAGE_DESCR(PSP_PAGE_DESCR_ACCESS_RW_ALL) | PSP_PAGE_TYPE(PSP_PAGE_TYPE_STRONG_ORDER), (pointer)L1PageTable);
        /* add region in sram area */
        _mmu_add_vregion((pointer)__INTERNAL_SRAM_BASE, (pointer)__INTERNAL_SRAM_BASE, (_mem_size) 0x00100000, PSP_PAGE_TABLE_SECTION_SIZE(PSP_PAGE_TABLE_SECTION_SIZE_1MB) | PSP_PAGE_TYPE(PSP_PAGE_TYPE_CACHE_NON)   | PSP_PAGE_DESCR(PSP_PAGE_DESCR_ACCESS_RW_ALL));
        /* add cached region in ddr area */
        _mmu_add_vregion((pointer)__EXTERNAL_DDRAM_BASE, (pointer)__EXTERNAL_DDRAM_BASE, __EXTERNAL_DDRAM_SIZE, PSP_PAGE_TABLE_SECTION_SIZE(PSP_PAGE_TABLE_SECTION_SIZE_1MB) | PSP_PAGE_TYPE(PSP_PAGE_TYPE_CACHE_WBNWA) | PSP_PAGE_DESCR(PSP_PAGE_DESCR_ACCESS_RW_ALL));
         _mmu_venable();

        _DCACHE_ENABLE();
        _ICACHE_ENABLE();
    }
#if BSPCFG_HAS_SRAM_POOL
    /* Check if the Kernel data are placed in the SRAM or not (distinquish between SRAMDATA and DDRDATA targets) */
    if ( (((uint_32)__INTERNAL_SRAM_BASE) < (uint_32)BSP_DEFAULT_START_OF_KERNEL_MEMORY) &&
            (((uint_32)BSP_DEFAULT_START_OF_KERNEL_MEMORY) < ((uint_32)__INTERNAL_SRAM_BASE + (uint_32)__INTERNAL_SRAM_SIZE)))
    {
        /* SRAM Target, just reuse system pool*/
        _BSP_sram_pool  = _mem_get_system_pool_id();
    }
    else
    {
        /* DDR Target, create new pool in SRAM or use Uncached pool */
#if MQX_USE_UNCACHED_MEM && PSP_HAS_DATA_CACHE
        _GET_KERNEL_DATA(kernel_data);
        /* Uncached pool on this platform can be placed in SRAM. We can reuse uncached pool as SRAM pool */
        if ( (((uint_32)__INTERNAL_SRAM_BASE) < (uint_32)kernel_data->UNCACHED_POOL) &&
                (((uint_32)kernel_data->UNCACHED_POOL) < ((uint_32)__INTERNAL_SRAM_BASE + (uint_32)__INTERNAL_SRAM_SIZE)))
        {
            _BSP_sram_pool = (MEMPOOL_STRUCT_PTR) kernel_data->UNCACHED_POOL;
        }
        else
        {
            _BSP_sram_pool = _mem_create_pool(__SRAM_POOL_START, ((uint_32)__SRAM_POOL_END) - (uint_32) __SRAM_POOL_START);
        }
#else
        /* Uncached pool does not exist - create SRAM pool in SRAM area */
        _BSP_sram_pool = _mem_create_pool(__SRAM_POOL_START, ((uint_32)__SRAM_POOL_END) - (uint_32) __SRAM_POOL_START);
#endif
    }
#endif

#if BSPCFG_CORE_MUTEX
    extern const CORE_MUTEX_INIT_STRUCT _core_mutex_init_info;

    result = _core_mutex_install(&_core_mutex_init_info);
    if (result != MQX_OK) {
        return result;
    }
#endif

#if BSPCFG_ENABLE_IO_SUBSYSTEM
    result = _io_init();
    if (result != MQX_OK)
        return result;

    /* Init clock manager */
    _bsp_clock_manager_init();
    /* Install Device Drivers */
#if BSPCFG_ENABLE_TTYA
    _kuart_polled_install("ttya:", &_bsp_sci0_init, _bsp_sci0_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_ITTYA
   _kuart_int_install("ittya:", &_bsp_sci0_init, _bsp_sci0_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_TTYB
    _kuart_polled_install("ttyb:", &_bsp_sci1_init, _bsp_sci1_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_ITTYB
    _kuart_int_install("ittyb:", &_bsp_sci1_init, _bsp_sci1_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_TTYC
    _kuart_polled_install("ttyc:", &_bsp_sci2_init, _bsp_sci2_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_ITTYC
    _kuart_int_install("ittyc:", &_bsp_sci2_init, _bsp_sci2_init.QUEUE_SIZE);
#endif

#if BSPCFG_ENABLE_ESDHC
    _esdhc_install("esdhc1:", &_bsp_esdhc1_init);
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


    /* I2C Initialization */
#if BSPCFG_ENABLE_I2C0
    _qi2c_polled_install("i2c0:", &_bsp_i2c0_init);
#endif

#if BSPCFG_ENABLE_I2C1
    _qi2c_polled_install("i2c1:", &_bsp_i2c1_init);
#endif

#if BSPCFG_ENABLE_I2C2
    _qi2c_polled_install("i2c2:", &_bsp_i2c2_init);
#endif

#if BSPCFG_ENABLE_I2C3
    _qi2c_polled_install("i2c3:", &_bsp_i2c3_init);
#endif

#if BSPCFG_ENABLE_II2C0
    _qi2c_int_install("ii2c0:", &_bsp_i2c0_init);
#endif

#if BSPCFG_ENABLE_II2C1
    _qi2c_int_install("ii2c1:", &_bsp_i2c1_init);
#endif

#if BSPCFG_ENABLE_II2C2
    _qi2c_int_install("ii2c2:", &_bsp_i2c2_init);
#endif

#if BSPCFG_ENABLE_II2C3
    _qi2c_int_install("ii2c3:", &_bsp_i2c3_init);
#endif

#if BSPCFG_ENABLE_USB
#endif
#if BSPCFG_ENABLE_LWADC
    #if BSPCFG_ENABLE_LWADC0
         _lwadc_init(&lwadc0_init);
    #endif
    #if BSPCFG_ENABLE_LWADC1
         _lwadc_init(&lwadc1_init);
    #endif
#endif

#if BSPCFG_ENABLE_SAI
    result = _io_sai_int_install(&_bsp_sai_init);
#endif
    _io_serial_default_init();

#endif

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
void _bsp_exit_handler(void)
{
    _DCACHE_DISABLE();
    _ICACHE_DISABLE();
    _mmu_vdisable();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_hwticks
* Returned Value   : number of hw ticks since last interrupt
* Comments         : param unused
*
*END*----------------------------------------------------------------------*/
uint_32 _bsp_get_hwticks(pointer param)
{
   return 0;
}

pointer _bsp_vtop(pointer ptr)
{
    uint_32 addr = (uint_32)ptr;
    return ptr;
}

pointer _bsp_ptov(pointer ptr)
{
    uint_32 addr = (uint_32) ptr;
    return ptr;
}

void _bsp_aux_core_start(pointer m4_vect_base)
{
    SRC_GPR(2) = ((_mqx_uint*)m4_vect_base)[1];      // reset vector
    SRC_GPR(3) = ((_mqx_uint*)m4_vect_base)[0];      // stack pointer

    // start M4 core - enable clock
    _bsp_aux_core_clock(1);
}
