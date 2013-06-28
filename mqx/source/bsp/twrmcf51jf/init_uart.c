/**HEADER*********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
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
* $FileName: init_uart.c$
* $Version : 3.8.3.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains the definition for the baud rate for the serial
*   channel
*
*END*************************************************************************/

#include "mqx.h"
#include "bsp.h"



#if MQX_ENABLE_LOW_POWER
const KUART_OPERATION_MODE_STRUCT _bsp_uart0_operation_modes[LPM_OPERATION_MODES] =
{
    /* LPM_OPERATION_MODE_RUN */
    {
        IO_PERIPHERAL_PIN_MUX_ENABLE | IO_PERIPHERAL_CLOCK_ENABLE | IO_PERIPHERAL_MODULE_ENABLE,
        0,
        0,
        0
    },

    /* LPM_OPERATION_MODE_WAIT */
    {
        IO_PERIPHERAL_PIN_MUX_ENABLE | IO_PERIPHERAL_CLOCK_ENABLE | IO_PERIPHERAL_MODULE_ENABLE,
        0,
        0,
        0
    },

    /* LPM_OPERATION_MODE_SLEEP */
    {
        IO_PERIPHERAL_PIN_MUX_ENABLE | IO_PERIPHERAL_CLOCK_ENABLE | IO_PERIPHERAL_MODULE_ENABLE | IO_PERIPHERAL_WAKEUP_ENABLE | IO_PERIPHERAL_WAKEUP_SLEEPONEXIT_DISABLE,
        0,
        0,
        0
    },

    /* LPM_OPERATION_MODE_STOP */
    {
        IO_PERIPHERAL_PIN_MUX_DISABLE | IO_PERIPHERAL_CLOCK_DISABLE,
        0,
        0,
        0
    }
};

const KUART_OPERATION_MODE_STRUCT _bsp_uart1_operation_modes[LPM_OPERATION_MODES] =
{
    /* LPM_OPERATION_MODE_RUN */
    {
        IO_PERIPHERAL_PIN_MUX_ENABLE | IO_PERIPHERAL_CLOCK_ENABLE | IO_PERIPHERAL_MODULE_ENABLE,
        0,
        0,
        0
    },

    /* LPM_OPERATION_MODE_WAIT */
    {
        IO_PERIPHERAL_PIN_MUX_ENABLE | IO_PERIPHERAL_CLOCK_ENABLE | IO_PERIPHERAL_MODULE_ENABLE,
        0,
        0,
        0
    },

    /* LPM_OPERATION_MODE_SLEEP */
    {
        IO_PERIPHERAL_PIN_MUX_ENABLE | IO_PERIPHERAL_CLOCK_ENABLE | IO_PERIPHERAL_MODULE_ENABLE | IO_PERIPHERAL_WAKEUP_ENABLE | IO_PERIPHERAL_WAKEUP_SLEEPONEXIT_DISABLE,
        0,
        0,
        0
    },

    /* LPM_OPERATION_MODE_STOP */
    {
        IO_PERIPHERAL_PIN_MUX_DISABLE | IO_PERIPHERAL_CLOCK_DISABLE,
        0,
        0,
        0
    }
};


#endif /* MQX_ENABLE_LOW_POWER */


const KUART_INIT_STRUCT _bsp_uart0_init = {
/* Queue Size           */  BSPCFG_UART0_QUEUE_SIZE,
/* Channel              */  0,
/* Input Clock [Hz]     */  BSP_SYSTEM_CLOCK,
/* Baud Rate            */  BSPCFG_UART0_BAUD_RATE,
/* RX/TX Int vect       */  Vsci0,
/* ERR   Int vect       */  Vsci0,
/* RX/TX priority       */  3,
/* ERR   priority       */  3
#if MQX_ENABLE_LOW_POWER
                            ,
/* Clock source         */  CM_CLOCK_SOURCE_CORE,
/* LPM operation info   */  _bsp_uart0_operation_modes
#endif
};

const KUART_INIT_STRUCT _bsp_uart1_init = {
/* Queue Size           */  BSPCFG_UART1_QUEUE_SIZE,
/* Channel              */  1,
/* Input Clock [Hz]     */  BSP_SYSTEM_CLOCK,
/* Baud Rate            */  BSPCFG_UART1_BAUD_RATE,
/* RX/TX Int vect       */  Vsci1,
/* ERR   Int vect       */  Vsci1,
/* RX/TX priority       */  3,
/* ERR   priority       */  3
#if MQX_ENABLE_LOW_POWER
                            ,
/* Clock source         */  CM_CLOCK_SOURCE_CORE,
/* LPM operation info   */  _bsp_uart1_operation_modes
#endif
};

/* EOF */
