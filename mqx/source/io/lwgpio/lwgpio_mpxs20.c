/**HEADER********************************************************************
*
* Copyright (c) 2011 Freescale Semiconductor;
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
* $FileName: lwgpio_mpxs20.c$
* $Version : 3.8.3.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains chip dependent functions for SIUL
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "lwgpio.h"

#include "lwgpio_siul.h"


#define SIUL_EIRQS 32


/* pin id for each eirq, reverse lookup is used because eirq to id table would be sparse and too large */
static const uint_8 _bsp_siul_eirq_pins[SIUL_EIRQS] = {
     0,  1,  2,  3,  4,   5,  6,  7,
     8, 10, 11, 12, 13,  14, 15, 16,
    17, 18, 22, 30, 31, 104, 36, 37,
    38, 77, 78, 79, 80, 105, 92, 93
};


/*FUNCTION*****************************************************************
*
* Function Name    : _bsp_get_gpio_base_address
* Returned Value   : void
* Comments         :
*    Returns base address of SIUL peripheral
*
*END*********************************************************************/
pointer _bsp_get_gpio_base_address(void)
{
    return (pointer)MPXS20_SIUL_BASE;
}


/*FUNCTION*****************************************************************
*
* Function Name    : _bsp_siul_pin_to_eirq
* Returned Value   : pin id
* Comments         :
*    Returns eirq for given pin or -1 if unsupported
*
*END*********************************************************************/
int _bsp_siul_pin_to_eirq(uint_32 id)
{
    int i;

    for (i=0; i<SIUL_EIRQS; i++) {
        if (_bsp_siul_eirq_pins[i] == id) return i;
    }

    return -1; /* pin does not support irq */
}


/*FUNCTION*****************************************************************
*
* Function Name    : _bsp_siul_int_get_vector
* Returned Value   : eirq number
* Comments         :
*    returns interrupt vector for given eirq
*
*END*********************************************************************/
/* Returns interrupt vector for given eirq */
int _bsp_siul_int_get_vector(uint_32 eirq)
{
    if (eirq < 8) return MPXS20_INTC_SIU_IRQ_0_VECTOR;
    else if (eirq < 16) return MPXS20_INTC_SIU_IRQ_1_VECTOR;
    else if (eirq < 24) return MPXS20_INTC_SIU_IRQ_2_VECTOR;
    else if (eirq < 32) return MPXS20_INTC_SIU_IRQ_3_VECTOR;
    else return 0;
}
