/**HEADER********************************************************************
*
* Copyright (c) 2011 Freescale Semiconductor;
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
* $FileName: serl_mpxs20.c$
* $Version : 3.8.4.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains the driver functions for the LINFLEXD
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "serl_linflexd.h"


static const pointer linflexd_address[] = 
{
    (pointer)MPXS20_LINFLEXD_0_BASE,
    (pointer)MPXS20_LINFLEXD_1_BASE
};


static const uint_32 /*PSP_INTERRUPT_TABLE_INDEX*/ linflexd_vectors[][3] =
{
    {
        MPXS20_INTC_LINFLEX0_RXI_VECTOR,
        MPXS20_INTC_LINFLEX0_TXI_VECTOR,
        MPXS20_INTC_LINFLEX0_ERR_VECTOR,
    },
    {
        MPXS20_INTC_LINFLEX1_RXI_VECTOR,
        MPXS20_INTC_LINFLEX1_TXI_VECTOR,
        MPXS20_INTC_LINFLEX1_ERR_VECTOR,
    },
};


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_linflexd_base_address
* Returned Value   : none
* Comments         :
*    Get base address of linflexd controller
*
*END*------------------------------------------------------------------------*/

VLINFLEXD_REG_STRUCT_PTR _bsp_get_linflexd_base_address(uint_32 channel)
{
    if (channel < ELEMENTS_OF(linflexd_address)) {
        return (VLINFLEXD_REG_STRUCT_PTR)linflexd_address[channel];
    }
    return NULL;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_linflexd_vectors
* Returned Value   : Number of vectors associated with the peripheral
* Comments         :
*
*
*END*----------------------------------------------------------------------*/

uint_32 _bsp_get_linflexd_vectors(uint_32 device, const uint_32 _PTR_ _PTR_ vectors_ptr)
{
    if (device < ELEMENTS_OF(linflexd_vectors)) {
        *vectors_ptr = linflexd_vectors[device];
        return ELEMENTS_OF(linflexd_vectors[0]);
    } else {
        return 0;
    }
}
