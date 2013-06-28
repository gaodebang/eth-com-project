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
* $FileName: bsp.h$
* $Version : 3.8.5.0$
* $Date    : Sep-27-2012$
*
* Comments:
*
*   This file includes all include files specific to this target system.
*
*END************************************************************************/
#ifndef __bsp_h__
#define __bsp_h__

#include <psp.h>         /* Processor specific files */
#include <twrpxs30.h>
#include <fio.h>         /* Files required for devices */
#include <io.h>

#include <bsp_cm.h>

#include <io_mem.h>
#include <io_null.h>

#include <serial.h>
#include <linflexd.h>
#include <serl_linflexd.h>

#include <qpbridge.h>
#include <qpbridge_mpxs30.h>

#include <qpit.h>
#include <timer_qpit.h>
#include <timer_e200dec.h>

#include <qintc.h>
#include <int_ctrl_qintc.h>

#include <lwgpio_siul.h>
#include <lwgpio.h>

#include <pxadc.h>
#include <lwadc_mpxsxx.h>
#include <lwadc_mpxs30.h>
#include <lwadc.h>

#include <enet.h>
#include <enet_wifi.h>
#include <ethernet.h>
#include <fec.h>
#include <fec_mpxs30.h>
#include <generic_phy.h>

#include <qi2c.h>
#include <i2c.h>
#include <i2c_qi2c.h>

#include <spi.h>
#include <spi_dspi.h>

#include <sdcard.h>
#include <sdcard_spi.h>

#include <flashx.h>
#include <flash_c90.h>
#include <flash_c90i.h>
#include <flash_mpxs30.h>

#include <flexcan_regs.h>
#include <flexcan.h>

#include <sema4.h>
#include <core_mutex_sema4.h>
#include <core_mutex.h>

/* I/O initialization controlled by initialization structures for each
** channel
*/
extern const LINFLEXD_SERIAL_INIT_STRUCT _bsp_linflexd0_init;
extern const LINFLEXD_SERIAL_INIT_STRUCT _bsp_linflexd1_init;
extern const LINFLEXD_SERIAL_INIT_STRUCT _bsp_linflexd2_init;
extern const LINFLEXD_SERIAL_INIT_STRUCT _bsp_linflexd3_init;

extern const SPI_INIT_STRUCT _bsp_spi0_init;
extern const SPI_INIT_STRUCT _bsp_spi1_init;
extern const SPI_INIT_STRUCT _bsp_spi2_init;

extern const QI2C_INIT_STRUCT _bsp_i2c0_init;
extern const QI2C_INIT_STRUCT _bsp_i2c1_init;
extern const QI2C_INIT_STRUCT _bsp_i2c2_init;
extern const SDCARD_INIT_STRUCT _bsp_sdcard0_init;

extern const CORE_MUTEX_INIT_STRUCT _core_mutex_init_info;

extern const FLASHX_INIT_STRUCT _bsp_data_flashx_init;
extern const FLASHX_INIT_STRUCT _bsp_code_flashx_init;

extern const LWADC_INIT_STRUCT lwadc0_init;
extern const LWADC_INIT_STRUCT lwadc1_init;
extern const LWADC_INIT_STRUCT lwadc2_init;
extern const LWADC_INIT_STRUCT lwadc3_init;

extern pointer _bsp_vtop(pointer ptr);
extern pointer _bsp_ptov(pointer ptr);

extern _mqx_int _bsp_flexcan_io_init(uint_32);

#endif
