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
* $FileName: init_uart5.c$
* $Version : 3.6.2.0$
* $Date    : Jun-4-2010$
*
* Comments:
*
*   This file contains the definition for the baud rate for the serial
*   channel
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"

const MCF54XX_UART_SERIAL_INIT_STRUCT _bsp_uart5_init = {
   /* queue size         */ BSPCFG_UART5_QUEUE_SIZE,
   /* Channel            */ MCF54XX_IO_UART5,
   /* Clock Speed        */ BSP_BUS_CLOCK,
   /* Interrupt Vector   */ BSP_UART5_INT_VECTOR,
   /* Interrupt Level    */ BSP_UART5_INT_LEVEL,
   /* Interrupt Sublevel */ 0,
   /* UMR1 Value         */ MCF54XX_UART_UMR1_NO_PARITY |
                            MCF54XX_UART_UMR1_8_BITS,
   /* UMR2 Value         */ MCF54XX_UART_UMR2_1_STOP_BIT,
   /* Baud rate          */ BSPCFG_UART5_BAUD_RATE
};

/* EOF */
