/**HEADER********************************************************************
* 
* Copyright (c) 2008-2012 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2008 Embedded Access Inc.;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
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
* $FileName: init_linflexd.c$
* $Version : 3.8.1.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains the definition for the baud rate for a serial channel
*
*
*END*********************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "bsp_prv.h"


const LINFLEXD_SERIAL_INIT_STRUCT _bsp_linflexd0_init = {
   /* Com port address    */ 0,
   /* queue size          */ BSPCFG_LINFLEXD0_QUEUE_SIZE,
   /* Clock speed         */ BSP_PERI1_CLOCK,
   /* Baud rate           */ BSPCFG_LINFLEXD0_BAUD_RATE,
   /* Bits per character  */ 8,                       // 7 or 8
   /* Parity              */ IO_SERIAL_PARITY_NONE,   // No parity only valid if bpc=8
   /* Stop bits           */ IO_SERIAL_STOP_BITS_1,   // Must be 1
   /* Int. Prio           */ BSPCFG_LINFLEXD0_PRIORITY
};


const LINFLEXD_SERIAL_INIT_STRUCT _bsp_linflexd1_init = {
   /* Com port address    */ 1,
   /* queue size          */ BSPCFG_LINFLEXD1_QUEUE_SIZE,
   /* Clock speed         */ BSP_PERI1_CLOCK,
   /* Baud rate           */ BSPCFG_LINFLEXD1_BAUD_RATE,
   /* Bits per character  */ 8,                       // 7 or 8
   /* Parity              */ IO_SERIAL_PARITY_NONE,   // No parity only valid if bpc=8
   /* Stop bits           */ IO_SERIAL_STOP_BITS_1,   // Must be 1
   /* Int. Prio           */ BSPCFG_LINFLEXD1_PRIORITY
};


const LINFLEXD_SERIAL_INIT_STRUCT _bsp_linflexd2_init = {
   /* Com port address    */ 2,
   /* queue size          */ BSPCFG_LINFLEXD2_QUEUE_SIZE,
   /* Clock speed         */ BSP_PERI1_CLOCK,
   /* Baud rate           */ BSPCFG_LINFLEXD2_BAUD_RATE,
   /* Bits per character  */ 8,                       // 7 or 8
   /* Parity              */ IO_SERIAL_PARITY_NONE,   // No parity only valid if bpc=8
   /* Stop bits           */ IO_SERIAL_STOP_BITS_1,   // Must be 1
   /* Int. Prio           */ BSPCFG_LINFLEXD2_PRIORITY,
};


const LINFLEXD_SERIAL_INIT_STRUCT _bsp_linflexd3_init = {
   /* Com port address    */ 3,
   /* queue size          */ BSPCFG_LINFLEXD3_QUEUE_SIZE,
   /* Clock speed         */ BSP_PERI1_CLOCK,
   /* Baud rate           */ BSPCFG_LINFLEXD3_BAUD_RATE,
   /* Bits per character  */ 8,                       // 7 or 8
   /* Parity              */ IO_SERIAL_PARITY_NONE,   // No parity only valid if bpc=8
   /* Stop bits           */ IO_SERIAL_STOP_BITS_1,   // Must be 1
   /* Int. Prio           */ BSPCFG_LINFLEXD3_PRIORITY
};
