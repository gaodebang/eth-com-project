/**HEADER********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2010 Embedded Access Inc.;
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
* $FileName: serl_mpxn20.c$
* $Version : 3.8.1.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains the driver functions for the lin
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"

static const pointer esci_address[] = {
   (pointer)MPXN20_ESCI_A_BASE,
   (pointer)MPXN20_ESCI_B_BASE,
   (pointer)MPXN20_ESCI_C_BASE,
   (pointer)MPXN20_ESCI_D_BASE,
   (pointer)MPXN20_ESCI_E_BASE,
   (pointer)MPXN20_ESCI_F_BASE};

static const uint_32 /*PSP_INTERRUPT_TABLE_INDEX*/ _esci_vectors[][1] =
{
    {
    	MPXN20_INTC_SCI_A_VECTOR,
    },
    {
       	MPXN20_INTC_SCI_B_VECTOR,
    },
    {
       	MPXN20_INTC_SCI_C_VECTOR,
    },
    {
    	MPXN20_INTC_SCI_D_VECTOR,
    },
    {
       	MPXN20_INTC_SCI_E_VECTOR,
    },
    {
       	MPXN20_INTC_SCI_F_VECTOR,
    }
   
};

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_esci_base_address
* Returned Value   : none
* Comments         :
*    Get base address of lin controller
*
*END*------------------------------------------------------------------------*/


VLIN_REG_STRUCT_PTR _bsp_get_lin_base_address(uint_32 channel)
{
    if (channel < ELEMENTS_OF(esci_address)) {
        return (VLIN_REG_STRUCT_PTR)esci_address[channel];
    }
    return NULL;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_lin_vector
* Returned Value   : OK or error
* Comments         :
*
*
*END*----------------------------------------------------------------------*/

uint_32 _bsp_get_lin_vectors(uint_32 device, const uint_32 _PTR_ _PTR_ vectors_ptr)
{
    if (device < ELEMENTS_OF(_esci_vectors)) {
        *vectors_ptr = _esci_vectors[device];
        return ELEMENTS_OF(_esci_vectors[0]);
    } else {
        return 0;
    }
}

/* EOF */
