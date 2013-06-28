/**HEADER*********************************************************************
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
* $FileName: bsp.h$
* $Version : 3.8.9.1$
* $Date    : Jul-17-2012$
*
* Comments:
*
*   This file includes all include files specific to this target system.
*
*END*************************************************************************/

#ifndef __bsp_h__
#define __bsp_h__   1


/* Platform specific files */
#include <psp.h>

/* Processor Expert files */
#include <PE_LDD.h>
#ifdef PE_LDD_VERSION
#include <Events.h>
#endif

#include <bsp_rev.h>
#include <twrmcf51jf.h>

/* Generic IO drivers */
#include <fio.h>
#include <io.h>
#include <io_mem.h>
#include <io_null.h>
#include <io_dun.h>

/* Clock manager */
#include <cm_cfplus.h>
#include <bsp_cm.h>
#include <cm.h>

/* Low power manager*/
#include <init_lpm.h>
#include <lpm_cfplus.h>
#include <lpm.h>

/* Core and System Modules */
#include <int_ctrl_mcfplus.h>

/* Memories and Memory Interfaces */
#include <flashx.h>
#include <flash_ftfl.h>
#include <flash_mcf51jf.h>

/* Security and Integrity Modules */
#include <crc_kn.h>

/* Analog drivers */
#include <adc_mcf51jf.h>
#include <adc.h>
#include <adc_kadc.h>

/* Timers */
#include <timer_mtim16.h>
#include <timer_lpt.h>

/* Communication Interfaces */
#include <serial.h>
#include <serl_kuart.h>
#include <i2c.h>
#include <i2c_ki2c.h>
#include <spi.h>
#include <spi_spi16.h>

#include <usb_dcd.h>
#include <usb_dcd_kn.h>

/* Human-Machine Interfaces */
#include <lwgpio_mcf51jf.h>
#include <lwgpio.h>
#include <io_gpio.h>

#include <hmi_uids.h>
#include <btnled.h>
#include <hmi_client.h>
#include <hmi_lwgpio_provider.h>
#include <hmi_tss_provider.h>
#include <hmi_provider.h>

/* Other drivers */
#include <sdcard.h>
#include <apccard.h>
#include <pccardflexbus.h>
#include <pcflash.h>

#include <usb_bsp.h>

/* New definitions of interrupt macros */
#define _int_init(irq, level, sublevel, unmask)
#define _int_enable_vector          _mcfplus_int_unmask
#define _int_disable_vector         _mcfplus_int_mask

#define _int_mask_all               _mcfplus_int_mask_all
#define _int_unmask_all             _mcfplus_int_unmask_all
#define _int_mask_vector            _mcfplus_int_mask
#define _int_unmask_vector          _mcfplus_int_unmask

#define _bsp_int_enable             _mcfplus_int_unmask
#define _bsp_int_disable            _mcfplus_int_mask
#define _bsp_int_init(irq, level, sublevel, unmask)

extern const LPM_CPU_OPERATION_MODE     LPM_CPU_OPERATION_MODES[];
extern const SDCARD_INIT_STRUCT         _bsp_sdcard0_init;

#ifdef __cplusplus
extern "C" {
#endif

/* Generic IO drivers */
/* Clock manager */
/* Low power manager*/
/* Core and System Modules */

/* Memories and Memory Interfaces */
_mqx_int _bsp_ftfx_io_init(_mqx_uint);

/* Security and Integrity Modules */

/* Analog drivers */
_mqx_int _bsp_adc_io_init(_mqx_uint adc_num);
_mqx_int _bsp_adc_channel_io_init(uint_16 source);

/* Timers */

/* Communication Interfaces */
_mqx_int _bsp_serial_io_init(uint_8 dev_num,  uint_8 flags);
_mqx_int _bsp_serial_rts_init(uint_8);
_mqx_int _bsp_spi_io_init (uint_8);
_mqx_int _bsp_i2c_io_init (uint_8);
_mqx_int _bsp_sdio_io_init (uint_8);
_mqx_int _bsp_usb_io_init(void);

/* Human-Machine Interfaces */
_mqx_int _bsp_gpio_io_init (uint_8,uint_8);
_mqx_int _bsp_gpio_io_init_new(void);

_mqx_int _bsp_tss_io_init(void);
HMI_CLIENT_STRUCT_PTR _bsp_btnled_init(void);
_mqx_int _bsp_btnled_set_twrpi(_mqx_int);
_mqx_int _bsp_btnled_get_twrpi(void);

/* Other drivers */

#ifdef __cplusplus
}
#endif

#endif  /* __bsp_h__ */
/* EOF */
