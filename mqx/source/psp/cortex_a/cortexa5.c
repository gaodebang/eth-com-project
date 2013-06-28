/**HEADER********************************************************************
*
* Copyright (c) 2012 Freescale Semiconductor;
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
* $FileName: cortexa5.c$
* $Version : 3.8.6.0$
* $Date    : Sep-24-2012$
*
* Comments:
*
*   This file contains utiltity functions for use with an A5.
*
*END************************************************************************/

#include "mqx_inc.h"


#if !PSP_HAS_SUPPORT_STRUCT
#error ARM PSP requires PSP_HAS_SUPPORT_STRUCT to be set
#endif

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _psp_set_support_ptr
* Returned Value   : none
* Comments         :
*   Set PSP_SUPPORT_STRUCT to kernel data
*
*END*------------------------------------------------------------------------*/
void _psp_set_support_ptr(PSP_SUPPORT_STRUCT_PTR psp_sup_ptr)
{
   KERNEL_DATA_STRUCT_PTR kernel_data;

   if (psp_sup_ptr != NULL)
   {
      _GET_KERNEL_DATA(kernel_data);

      _mem_set_type(psp_sup_ptr, MEM_TYPE_PSP_SUPPORT_STRUCT);

      kernel_data->PSP_SUPPORT_PTR = psp_sup_ptr;
   }
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _psp_get_support_ptr
* Returned Value   : pointer to PSP_SUPPORT_STRUCT
* Comments         :
*   Return PSP_SUPPORT_STRUCT from kernel data
*
*END*------------------------------------------------------------------------*/
PSP_SUPPORT_STRUCT_PTR _psp_get_support_ptr(void)
{
   KERNEL_DATA_STRUCT_PTR kernel_data;

   _GET_KERNEL_DATA(kernel_data);

   return kernel_data->PSP_SUPPORT_PTR;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_initialize_support
* Returned Value   : none
* Comments         :
*   Initilize the support functions for the A5 platforms
*
*END*------------------------------------------------------------------------*/
void _a5_initialize_support(void)
{
    KERNEL_DATA_STRUCT_PTR kernel_data;
    PSP_SUPPORT_STRUCT_PTR psp_sup_ptr;

    _GET_KERNEL_DATA(kernel_data);

    psp_sup_ptr = _mem_alloc_system_zero((uint_32)sizeof(PSP_SUPPORT_STRUCT));

    if (psp_sup_ptr)
    {
       _mem_set_type(psp_sup_ptr, MEM_TYPE_PSP_SUPPORT_STRUCT);
       kernel_data->PSP_SUPPORT_PTR = psp_sup_ptr;
    }
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _psp_core_num
* Returned Value   : int
* Comments         :
*    This function returns the core number
*
*END*----------------------------------------------------------------------*/
uint_32 _psp_core_num(void)
{
    return MSCM_CPxNUM & MSCM_CPxNUM_CPN_MASK;
}
