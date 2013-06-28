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
* $FileName: lwgpio_mpxn20.c$
* $Version : 3.8.2.0$
* $Date    : Oct-2-2012$
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


#define SIU_EIRQS 16


/* pin id for each eirq, reverse lookup is used because eirq to id table would be sparse and too large */
static const uint_8 _bsp_siul_eirq_pins[SIU_EIRQS] = {
     16,  17,  18,  19,  20,   21,  22,  23,
     24,  25,  26,  27,  28,   29,  30,  31,
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
    return (pointer)MPXN20_SIU_BASE;
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

    for (i=0; i<SIU_EIRQS; i++) {
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
    if (eirq < 8) return MPXN20_INTC_SIU_EXT_INTR_0_VECTOR;
    else if (eirq < 16) return MPXN20_INTC_SIU_EXT_INTR_1_VECTOR;
    else if (eirq < 24) return MPXN20_INTC_SIU_EXT_INTR_2_VECTOR;
    else if (eirq < 32) return MPXN20_INTC_SIU_EXT_INTR_3_VECTOR;
    else return 0;
}
