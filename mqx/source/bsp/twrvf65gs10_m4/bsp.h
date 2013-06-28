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
*
*   This file includes all include files specific to this target system.
*
*END************************************************************************/

#ifndef _bsp_h_
#define _bsp_h_ 1

#include <bsp_rev.h>
#include <psp.h>
#include <twrvf65gs10_m4.h>

#include <nvic.h>
#include <irouter_vybrid.h>

/* Clock manager */
#include <bsp_cm.h>

#include <fio.h>
#include <io.h>

#include <io_mem.h>

#include <serial.h>
#include <serl_kuart.h>

#include <lwgpio_vgpio.h>
#include <lwgpio.h>

#include <qi2c.h>
#include <i2c.h>
#include <i2c_qi2c.h>

#include <esdhc.h>
#include <sdcard.h>
#include <sdcard_esdhc.h>

#include <enet.h>
#include <macnet_vybrid.h>
#include <lwadc_vadc.h>

#include <spi.h>
#include <spi_dspi.h>

#include <usb_bsp.h>

#ifdef __cplusplus
extern "C" {
#endif

_mqx_int _bsp_adc_io_init(_mqx_uint input);
_mqx_int _bsp_adc_channel_io_init(uint_16 source);
_mqx_int _bsp_dspi_io_init(uint_32 dev_num);
_mqx_int _bsp_flexcan_io_init (uint_8);
_mqx_int _bsp_i2c_io_init( uint_32 );
_mqx_int _bsp_gpio_io_init( void );
_mqx_int _bsp_esdhc_io_init(_mqx_uint, _mqx_uint);
_mqx_int _bsp_rtc_io_init( void );
_mqx_int _bsp_serial_io_init( _mqx_uint dev_num, _mqx_uint flags);
_mqx_int _bsp_serial_rts_init( uint_32 );
_mqx_int _bsp_usb_io_init(void);
_mqx_int _bsp_enet_io_init(_mqx_uint);
_mqx_int _bsp_i2s_io_init(uint_32);
boolean  _bsp_get_mac_address(uint_32,uint_32,_enet_address);
_mqx_int _bsp_usb_host_io_init(struct usb_host_if_struct *usb_if);
_mqx_int _bsp_usb_dev_io_init(struct usb_dev_if_struct *usb_if);
void _bsp_usb_hs_disconnect_detection_enable(pointer host_handle);
void _bsp_usb_hs_disconnect_detection_disable(pointer host_handle);

extern const SDCARD_INIT_STRUCT _bsp_sdcard0_init;
//extern const LPM_CPU_OPERATION_MODE LPM_CPU_OPERATION_MODES[];

static inline uint_32 _bsp_int_init(_mqx_uint num, _mqx_uint prior, _mqx_uint subprior, boolean enable) {
	uint_32 res;

	if (MQX_OK == (res = _nvic_int_init(num, prior, enable))) {
		_irouter_routing(num, 1 << _psp_core_num(), enable);
	}

	return res;
}

#define _bsp_int_enable(num)                            _nvic_int_enable(num)
#define _bsp_int_disable(num)                           _nvic_int_disable(num)

#ifdef __cplusplus
}
#endif

#endif  /* _bsp_h_ */
/* EOF */
