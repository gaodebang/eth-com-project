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
* $Version : 3.8.3.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This file includes all include files specific to this target system.
*
*END************************************************************************/
#ifndef __bsp_h__
#define __bsp_h__

#include <psp.h>         /* Processor specific files */
#include <twrpxd10.h>
#include <fio.h>         /* Files required for devices */
#include <io.h>

#include <bsp_cm.h>

#include <serial.h>
#include <linflexd.h>
#include <serl_linflexd.h>

#include <qrtc.h>
#include <rtc.h>

#include <qpit.h>
#include <timer_qpit.h>


#include <flexcan.h>
#include <flexcan_regs.h>

#include <pxadc.h>
#include <lwadc_mpxadc.h>
#include <lwadc_mpxd10.h>

#include <qintc.h>
#include <int_ctrl_qintc.h>

#include <lwgpio_siul.h>
#include <lwgpio.h>

#include <spi.h>
#include <spi_dspi.h>

#include <qi2c.h>
#include <i2c.h>
#include <i2c_qi2c.h>

#include <sdcard.h>
#include <sdcard_spi.h>

#include <flashx.h>
#include <flash_c90.h>

#include <flash_mpxd10.h>

#include <flexcan_regs.h>
#include <flexcan.h>
#include <io_mem.h>

#include "MPXD10_cw.h"

#define _bsp_int_disable(v)     _qintc_set_prio(v, 0)
//#define _bsp_int_enable(v)      /* Interrupt controller driver does not support this functionality */
#define _bsp_int_init(v,l,s,e)  _qintc_set_prio(v, (e)?(l) : 0)

extern const SDCARD_INIT_STRUCT _bsp_sdcard0_init;


#endif
/* EOF */
