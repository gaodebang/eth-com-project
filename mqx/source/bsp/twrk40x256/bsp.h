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
* $Version : 3.8.26.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file includes all include files specific to this target system.
*
*END*************************************************************************/

#ifndef __bsp_h__
#define __bsp_h__   1

#include <psp.h>

/* Processor Expert files */
#include <PE_LDD.h>
#ifdef PE_LDD_VERSION
#include <Events.h>
#endif

#include <bsp_rev.h>
#include <twrk40x256.h>

/* Generic IO drivers */
#include <fio.h>
#include <io.h>
#include <io_mem.h>
#include <io_null.h>
#include <io_dun.h>

/* Clock manager */
#include <cm_kinetis.h>
#include <bsp_cm.h>
#include <cm.h>
/* Low power manager*/
#include <init_lpm.h>
#include <lpm_kinetis.h>
#include <lpm.h>

/* Core and System Modules */
/* Memories and Memory Interfaces */
#include <flashx.h>
#include <flash_ftfl.h>
#include <flash_mk40.h>

/* Security and Integrity Modules */
/* Analog drivers */
#include <adc_mk40.h>
#include <adc.h>
#include <adc_kadc.h>

/* Timers */
#include <timer_lpt.h>
#include <timer_qpit.h>
#include <krtc.h>
#include <rtc.h>

/* Communication Interfaces */
#include <serial.h>
#include <serl_kuart.h>
#include <i2c.h>
#include <i2c_ki2c.h>
#include <spi.h>
#include <spi_dspi.h>
#include <kinetis_fcan.h>
#include <kflexcan.h>
/* Human-Machine Interfaces */
#include <lwgpio_kgpio.h>
#include <lwgpio.h>
#include <io_gpio.h>
#include <io_gpio_kgpio.h>
#include <lcd_twrk40x256.h>


#include <i2s.h>
#include <i2s_ki2s.h>
#include <iodebug.h>
#include <tchres.h>
#include <hmi_uids.h>
#include <btnled.h>
#include <hmi_client.h>
#include <hmi_lwgpio_provider.h>
#include <hmi_tss_provider.h>
#include <hmi_provider.h>

/* Other drivers */
#include <esdhc.h>
#include <sdcard.h>
#include <sdcard_spi.h>
#include <sdcard_esdhc.h>
#include <apccard.h>
#include <pccardflexbus.h>
#include <pcflash.h>
#include <usb_bsp.h>

#ifdef __cplusplus
extern "C" {
#endif

_mqx_int _bsp_adc_io_init(_mqx_uint adc_num);
_mqx_int _bsp_adc_channel_io_init(uint_16 source);
_mqx_int _bsp_dspi_io_init(uint_32 dev_num);
_mqx_int _bsp_flexcan_io_init (uint_8);
_mqx_int _bsp_i2c_io_init( uint_32 );
_mqx_int _bsp_gpio_io_init( void );
_mqx_int _bsp_esdhc_io_init (uint_8, uint_16);
_mqx_int _bsp_rtc_io_init( void );
_mqx_int _bsp_serial_io_init(uint_8 dev_num,  uint_8 flags);
_mqx_int _bsp_serial_rts_init( uint_32 );
_mqx_int _bsp_usb_io_init(void);
_mqx_int _bsp_i2s_io_init(uint_32);
_mqx_int _bsp_lcd_io_init( void );
_mqx_int _bsp_ftfx_io_init(_mqx_uint);
HMI_CLIENT_STRUCT_PTR _bsp_btnled_init(void);
_mqx_int _bsp_tss_io_init(void);
_mqx_int _bsp_btnled_set_twrpi(_mqx_int);
_mqx_int _bsp_btnled_get_twrpi(void);

extern const SDCARD_INIT_STRUCT _bsp_sdcard0_init;
extern const LPM_CPU_OPERATION_MODE LPM_CPU_OPERATION_MODES[];

#define _bsp_int_init(num, prior, subprior, enable)     _nvic_int_init(num, prior, enable)
#define _bsp_int_enable(num)                            _nvic_int_enable(num)
#define _bsp_int_disable(num)                           _nvic_int_disable(num)

#ifdef __cplusplus
}
#endif

#endif  /* __bsp_h__ */
/* EOF */