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
* $Date    : Sep-27-2012$
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


const char _PTR_ _mqx_bsp_revision = REAL_NUM_TO_STR(BSP_REVISION);
const char _PTR_ _mqx_io_revision  = REAL_NUM_TO_STR(IO_REVISION);


/* Only use when debugging with JTAG and cache and MMU are interferring
** with the debugging
*/
 //volatile uint_32 _mqx_monitor_type = MQX_MONITOR_TYPE_BDM;
 volatile uint_32 _mqx_monitor_type = MQX_MONITOR_TYPE_NONE;
//#define BSP_CACHE_INHIBIT 1



const uint_32 pbridge_mprot_config[] = {
    CORE_0|CORE_1,
    CORE_0|CORE_1,
    CORECFG_DMA_0,
    CORECFG_FLEXRAY,
    CORECFG_ENET_0,
    CORECFG_PDI,
    CORECFG_DMA_1,
    0,
    CORE_0|CORE_1,
    CORE_0|CORE_1
};



extern void __boot(void);
extern void P1_Start(void * fn);


pointer _bsp_vtop(pointer ptr)
{
    uint_32 addr = (uint_32) ptr;

    if ( (addr >= MPXS30_SRAM_CORE_0_BASE) && (addr < MPXS30_SRAM_CORE_1_END) && (addr & BSP_VIRTIAL_MEMORY_BIT) ) {
        addr &= ~(BSP_VIRTIAL_MEMORY_BIT);
        if (_psp_core_num()!=0) {
            addr += (MPXS30_SRAM_CORE_1_BASE-MPXS30_SRAM_CORE_0_BASE);
        }
    }

    return (pointer) addr;
}



static uchar_ptr _bsp_vtopr(uchar_ptr ptr)
{
    uint_32 addr = (uint_32) ptr;

    if ( (addr >= MPXS30_SRAM_CORE_0_BASE) && (addr < MPXS30_SRAM_CORE_1_END) && (addr & BSP_VIRTIAL_MEMORY_BIT) ) {
        addr &= ~(BSP_VIRTIAL_MEMORY_BIT);
        if (_psp_core_num()==0) {
            addr += (MPXS30_SRAM_CORE_1_BASE-MPXS30_SRAM_CORE_0_BASE);
        }
     }

     return (uchar_ptr) addr;
}


pointer _bsp_ptov(pointer ptr)
{
    uint_32 addr = (uint_32) ptr;

    if (_psp_core_num()==0) {
        if ( ( (addr>=MPXS30_SRAM_CORE_0_BASE) && (addr<MPXS30_SRAM_CORE_0_END)) ||
             ( (addr>=MPXS30_SRAM_CORE_1_BASE) && (addr<MPXS30_SRAM_CORE_1_END)) ) {

            addr |= BSP_VIRTIAL_MEMORY_BIT;
        }
    } else {
        if ( (addr>=MPXS30_SRAM_CORE_0_BASE) && (addr<MPXS30_SRAM_CORE_0_END)) {
            addr = (addr - MPXS30_SRAM_CORE_0_BASE + MPXS30_SRAM_CORE_1_BASE) | BSP_VIRTIAL_MEMORY_BIT;
        } else if ((addr>=MPXS30_SRAM_CORE_1_BASE)&&(addr<MPXS30_SRAM_CORE_1_END)) {
            addr = (addr - MPXS30_SRAM_CORE_1_BASE + MPXS30_SRAM_CORE_0_BASE) | BSP_VIRTIAL_MEMORY_BIT;
        }
    }

    return (pointer) addr;
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

    /* Enable Timer */
    _e200_enable_timer(BSP_TIMEBASE_USES_EXTERNAL_CLK);

    if (_psp_core_num()==0) {
        P1_Start( __boot);
    }

    _GET_KERNEL_DATA(kernel_data);

    _mqx_set_cpu_type(MQX_CPU);

    /* Set the bsp exit handler, called by _mqx_exit */
    _mqx_set_exit_handler(_bsp_exit_handler);

    /* Initialize the MPXSxx support functions */
    _mpxsxx_initialize_support();


    /* Initialize the interrupt handling */
    result =  _psp_int_init(BSP_FIRST_INTERRUPT_VECTOR_USED, BSP_LAST_INTERRUPT_VECTOR_USED);
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

#if BSPCFG_ENABLE_PIT_TIMER
    _qpit_timer_install_kernel(BSPCFG_TIMER_PIT_DEVICE, BSPCFG_TIMER_PIT_CHANNEL,BSP_ALARM_FREQUENCY, BSP_PERI1_CLOCK, BSPCFG_TIMER_INT_LEVEL);
    //_e200_decrementer_null_install();
#else
    _e200_decrementer_timer_install(BSP_ALARM_FREQUENCY, BSP_TIMEBASE_CLOCK);
#endif


    /*------------------------------------------------------------------------*/
    /*
    ** Setup MMU page tables
    */

    if (_mqx_monitor_type == MQX_MONITOR_TYPE_NONE) {
        _mmu_init(NULL);
        // First, mark the three TLBs that the boot code used as 'not-free'
        _mmu_reserve_tlb(BSP_FLASH_TLB);
        _mmu_reserve_tlb(BSP_RAM_TLB);
        _mmu_reserve_tlb(BSP_PERIPHERAL_TLB);

        // Next, add regions for RAM.
        //                        Physical Address                  Virtual Address              Size                    Attributes
        _mmu_add_virtual_region(_bsp_vtop(BSP_PRIVATE_RAM_START),  BSP_PRIVATE_RAM_START,       BSP_PRIVATE_RAM_SIZE,   BSP_PRIVATE_RAM_ATTR,        BSP_PID_MQX);
        _mmu_add_virtual_region(_bsp_vtop(BSP_SHARED_RAM_START),   BSP_SHARED_RAM_START,        BSP_SHARED_RAM_SIZE,    BSP_SHARED_RAM_ATTR,         BSP_PID_MQX);
        _mmu_add_virtual_region(_bsp_vtopr(BSP_PRIVATE_RAM_START), BSP_REMOTE_PRIVATE_RAM_START,BSP_PRIVATE_RAM_SIZE,   BSP_REMOTE_PRIVATE_RAM_ATTR, BSP_PID_MQX);
        _mmu_add_virtual_region(_bsp_vtopr(BSP_SHARED_RAM_START),  BSP_REMOTE_SHARED_RAM_START, BSP_SHARED_RAM_SIZE,    BSP_SHARED_RAM_ATTR,         BSP_PID_MQX);
        _mmu_add_virtual_region(_bsp_vtop(BSP_UNCACHED_DATA_START),BSP_UNCACHED_DATA_START,     BSP_UNCACHED_DATA_SIZE, BSP_UNCACHED_DATA_ATTR,      BSP_PID_MQX);

        // switch PID from 1 (boot) to 2 (MQX)
        _psp_set_pid(BSP_PID_MQX);

        // Reclaim the BOOT RAM TLB
        _mmu_release_tlb(BSP_RAM_TLB);

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
#endif

#if BSPCFG_CORE_MUTEX
    result = _core_mutex_install(&_core_mutex_init_info);
    if (result != MQX_OK) {
        return result;
    }
#endif

    /*------------------------------------------------------------------------*/
    /*
    ** Initialize the I/O Sub-system
    */
    #if BSPCFG_ENABLE_IO_SUBSYSTEM
        /* Initialize the I/O Sub-system */
        result = _io_init();
        if (result != MQX_OK) {
            return result;
        }

     #if PSP_HAS_DEVICE_PROTECTION
     if (!_bsp_lwgpio_enable_access(0)) {
         return MQX_INVALID_DEVICE;
     }
     #endif

        /* Install device drivers */
        #if BSPCFG_ENABLE_TTYA
            if (_psp_core_peripheral_enabled(CORECFG_LINFLEX_0)) {
                _linflexd_serial_polled_install("ttya:", &_bsp_linflexd0_init);
            }
        #endif
        #if BSPCFG_ENABLE_ITTYA
            if (_psp_core_peripheral_enabled(CORECFG_LINFLEX_0)) {
                _linflexd_serial_int_install("ittya:", &_bsp_linflexd0_init);
            }
        #endif

        #if BSPCFG_ENABLE_TTYB
            if (_psp_core_peripheral_enabled(CORECFG_LINFLEX_1)) {
                _linflexd_serial_polled_install("ttyb:", &_bsp_linflexd1_init);
            }
        #endif
        #if BSPCFG_ENABLE_ITTYB
            if (_psp_core_peripheral_enabled(CORECFG_LINFLEX_1)) {
                _linflexd_serial_int_install("ittyb:", &_bsp_linflexd1_init);
            }
        #endif

        #if BSPCFG_ENABLE_TTYC
            if (_psp_core_peripheral_enabled(CORECFG_LINFLEX_2)) {
                _linflexd_serial_polled_install("ttyc:", &_bsp_linflexd2_init);
            }
        #endif
        #if BSPCFG_ENABLE_ITTYC
            if (_psp_core_peripheral_enabled(CORECFG_LINFLEX_2)) {
                _linflexd_serial_int_install("ittyc:", &_bsp_linflexd2_init);
            }
        #endif

        #if BSPCFG_ENABLE_TTYD
            if (_psp_core_peripheral_enabled(CORECFG_LINFLEX_3)) {
                _linflexd_serial_polled_install("ttyd:", &_bsp_linflexd3_init);
            }
        #endif
        #if BSPCFG_ENABLE_ITTYD
            if (_psp_core_peripheral_enabled(CORECFG_LINFLEX_3)) {
            _linflexd_serial_int_install("ittyd:", &_bsp_linflexd3_init);
            }
        #endif

        #if BSPCFG_ENABLE_SPI0
            if (_psp_core_peripheral_enabled(CORECFG_SPI_0)) {
                _io_spi_install("spi0:", &_bsp_spi0_init);
            }
        #endif

        #if BSPCFG_ENABLE_SPI1
            if (_psp_core_peripheral_enabled(CORECFG_SPI_1)) {
                _io_spi_install("spi1:", &_bsp_spi1_init);
            }
        #endif

        #if BSPCFG_ENABLE_SPI2
            if (_psp_core_peripheral_enabled(CORECFG_SPI_2)) {
                _io_spi_install("spi2:", &_bsp_spi2_init);
            }
        #endif
        
        #if BSPCFG_ENABLE_I2C0
            if (_psp_core_peripheral_enabled(CORECFG_I2C_0)) {
                _qi2c_polled_install("i2c0:", &_bsp_i2c0_init);
            }
        #endif
        #if BSPCFG_ENABLE_II2C0
            if (_psp_core_peripheral_enabled(CORECFG_I2C_0)) {
                _qi2c_int_install("ii2c0:", &_bsp_i2c0_init);
            }
        #endif
        #if BSPCFG_ENABLE_I2C1
            if (_psp_core_peripheral_enabled(CORECFG_I2C_1)) {
                _qi2c_polled_install("i2c1:", &_bsp_i2c1_init);
            }
        #endif
        #if BSPCFG_ENABLE_II2C1
            if (_psp_core_peripheral_enabled(CORECFG_I2C_1)) {
                _qi2c_int_install("ii2c1:", &_bsp_i2c1_init);
            }
        #endif
        #if BSPCFG_ENABLE_I2C2
            if (_psp_core_peripheral_enabled(CORECFG_I2C_2)) {
                _qi2c_polled_install("i2c2:", &_bsp_i2c2_init);
            }
        #endif
        #if BSPCFG_ENABLE_II2C2
            if (_psp_core_peripheral_enabled(CORECFG_I2C_2)) {
                _qi2c_int_install("ii2c2:", &_bsp_i2c2_init);
            }
        #endif

        #if BSPCFG_ENABLE_FLASHX
            _io_flashx_install("flashx:", &_bsp_data_flashx_init);
            /* code flash support in alpha stage, not tested! */
            /* _io_flashx_install("flashx_code:", &_bsp_code_flashx_init); */
        #endif

        #if BSPCFG_ENABLE_LWADC
            #if BSPCFG_ENABLE_LWADC0
            if (_psp_core_peripheral_enabled(CORECFG_ADC_0)) {
                    _lwadc_init(&lwadc0_init);
            }
            #endif
            #if BSPCFG_ENABLE_LWADC1
                if (_psp_core_peripheral_enabled(CORECFG_ADC_1)) {
                    _lwadc_init(&lwadc1_init);
                }
            #endif
            #if BSPCFG_ENABLE_LWADC2
                if (_psp_core_peripheral_enabled(CORECFG_ADC_2)) {
                    _lwadc_init(&lwadc2_init);
                }
            #endif
            #if BSPCFG_ENABLE_LWADC3
                if (_psp_core_peripheral_enabled(CORECFG_ADC_3)) {
                    _lwadc_init(&lwadc3_init);
                }
            #endif
        #endif

        #ifdef BSP_DEFAULT_IO_CHANNEL_DEFINED
            /* Initialize the default serial I/O */
            _io_serial_default_init();
        #endif
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
