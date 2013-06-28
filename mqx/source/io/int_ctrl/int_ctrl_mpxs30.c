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
* $FileName: int_ctrl_mpxs30.c$
* $Version : 3.8.1.0$
* $Date    : Oct-5-2011$
*
* Comments:
*
*   This file contains the source functions for the INTC driver.
*
*END************************************************************************/

#include "mqx_inc.h"
#include "bsp.h"
#include "psp.h"

   
/*FUNCTION*-------------------------------------------------------------
* 
* Function Name    : _bsp_qintc_enable_access
* Returned Value   : True if enabled
* Comments         :
*    This function enables the specified device.
*
*END*-----------------------------------------------------------------*/

boolean _bsp_qintc_enable_access(void)
{
    return _qpbridge_enable_access(MPXS30_PBRIDGE_INTC);
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_qintc_base_address
* Returned Value   : none
* Comments         :
*    Get base address of interrupt controller
*
*END*------------------------------------------------------------------------*/

VQINTC_REG_STRUCT_PTR _bsp_get_qintc_base_address(void)
{
    switch (_psp_core_num()) {
        case 0:  return (VQINTC_REG_STRUCT_PTR) MPXS30_INTC_BASE;
        case 1:  return (VQINTC_REG_STRUCT_PTR) MPXS30_INTC_1_BASE;
        default: return NULL;
    }
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_core_qintc_base_address
* Returned Value   : none
* Comments         :
*    Get base address of the other core's interrupt controller
*
*END*------------------------------------------------------------------------*/

VQINTC_REG_STRUCT_PTR _bsp_get_core_qintc_base_address(uint_32 core_num)
{
    switch (core_num) {
        case 0:  return (VQINTC_REG_STRUCT_PTR) MPXS30_INTC_BASE;
        case 1:  return (VQINTC_REG_STRUCT_PTR) MPXS30_INTC_1_BASE;
        default: return NULL;
    }
}
