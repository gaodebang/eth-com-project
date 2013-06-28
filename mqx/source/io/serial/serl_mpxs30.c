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
* $FileName: serl_mpxs30.c$
* $Version : 3.8.3.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains the driver functions for the LINFLEXD
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"

static const pointer linflexd_address[] = {
   (pointer)MPXS30_LINFLEXD_0_BASE, (pointer)MPXS30_LINFLEXD_1_BASE,
   (pointer)MPXS30_LINFLEXD_2_BASE, (pointer)MPXS30_LINFLEXD_3_BASE };

static const uint_32 linflexd_config[] = {
   CORECFG_LINFLEX_0, CORECFG_LINFLEX_1,
   CORECFG_LINFLEX_2, CORECFG_LINFLEX_3 };

static const uint_32 linflexd_pbridge_id[] = {
   MPXS30_PBRIDGE_LINFLEXD_0, MPXS30_PBRIDGE_LINFLEXD_1,
   MPXS30_PBRIDGE_LINFLEXD_2, MPXS30_PBRIDGE_LINFLEXD_3 };


static const uint_32 /*PSP_INTERRUPT_TABLE_INDEX*/ linflexd_vectors[][3] =
{
    {
        MPXS30_INTC_LINFLEX0_RXI_VECTOR,
        MPXS30_INTC_LINFLEX0_TXI_VECTOR,
        MPXS30_INTC_LINFLEX0_ERR_VECTOR,
    },
    {
        MPXS30_INTC_LINFLEX1_RXI_VECTOR,
        MPXS30_INTC_LINFLEX1_TXI_VECTOR,
        MPXS30_INTC_LINFLEX1_ERR_VECTOR,
    },
    {
        MPXS30_INTC_LINFLEX2_RXI_VECTOR,
        MPXS30_INTC_LINFLEX2_TXI_VECTOR,
        MPXS30_INTC_LINFLEX2_ERR_VECTOR,
    },
    {
        MPXS30_INTC_LINFLEX3_RXI_VECTOR,
        MPXS30_INTC_LINFLEX3_TXI_VECTOR,
        MPXS30_INTC_LINFLEX3_ERR_VECTOR,
    },
};


/*FUNCTION*-------------------------------------------------------------
*
* Function Name    : _bsp_linflexd_enable_access
* Returned Value   : True if enabled
* Comments         :
*    This function enables the specified device.
*
*END*-----------------------------------------------------------------*/

boolean _bsp_linflexd_enable_access(uint_32 device)
{
    if (_psp_core_peripheral_enabled(linflexd_config[device])) {
        return _qpbridge_enable_access(linflexd_pbridge_id[device]);
    }
    return FALSE;
}


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
      //return (VLINFLEXD_REG_STRUCT_PTR) linflexd_address[channel];
      return (VLINFLEXD_REG_STRUCT_PTR) _psp_core_peripheral_address(linflexd_config[channel], linflexd_address[channel]);
   }
   return NULL;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_linflexd_vector
* Returned Value   : OK or error
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
