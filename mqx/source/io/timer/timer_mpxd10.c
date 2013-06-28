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
* $FileName: timer_mpxd10.c$
* $Version : 3.8.1.0$
* $Date    : Sep-26-2012$
*
* Comments:
*
*   This file contains timer functions for use with a MCF5208.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include "timer_qpit.h"


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_qpit_vector
* Returned Value   : Vector number upon success, 0 upon failure
* Comments         :
*    This function returns desired interrupt vector number for specified PIT
*
*END*----------------------------------------------------------------------*/

static PSP_INTERRUPT_TABLE_INDEX _qpit_vectors[] =
{
      MPXD10_INTC_PIT_CHANNEL_0_VECTOR, 
      MPXD10_INTC_PIT_CHANNEL_1_VECTOR,
      MPXD10_INTC_PIT_CHANNEL_2_VECTOR,
      MPXD10_INTC_PIT_CHANNEL_3_VECTOR
};

PSP_INTERRUPT_TABLE_INDEX _bsp_get_qpit_vector
    (
        uint_32 device,
        uint_32 channel
    )
{
    return (PSP_INTERRUPT_TABLE_INDEX) (device==0) ? _qpit_vectors[channel] : 0;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_qpit_base_address
* Returned Value   : Address upon success, NULL upon failure
* Comments         :
*    This function returns the base register address of the corresponding PIT
*
*END*----------------------------------------------------------------------*/

VQPIT_REG_STRUCT_PTR _bsp_get_qpit_base_address(uint_32 device)
{
    if (device == 0) {
        return (VQPIT_REG_STRUCT_PTR)MPXD10_PIT_BASE;
    }
    return NULL;
}