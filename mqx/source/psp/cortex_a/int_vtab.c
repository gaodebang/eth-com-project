/*HEADER*********************************************************************
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
* $FileName: int_vtab.c$
* $Version : 3.8.1.0$
* $Date    : Jul-3-2012$
*
* Comments:
*
*   This file contains the functions used to access the vector
*   table locations.
*
*END************************************************************************/

#include "mqx_inc.h"

#if MQX_USE_INTERRUPTS
/*!
 * \brief Changes the location of the interrupt vector table.
 *
 * \param[in] new Address of the new interrupt vector table.
 *
 * \return Address of the previous vector table.
 *
 * \warning Behavior depends on the BSP and the PSP.
 *
 * \see _int_get_vector_table
 * \see _int_get_previous_vector_table
 */
_psp_code_addr _int_set_vector_table
    (
        _psp_code_addr new
    )
{
    KERNEL_DATA_STRUCT_PTR kernel_data;
    PSP_SUPPORT_STRUCT_PTR psp_support_ptr;
    _psp_code_addr old;

    _GET_KERNEL_DATA(kernel_data);

    psp_support_ptr = (PSP_SUPPORT_STRUCT_PTR)kernel_data->PSP_SUPPORT_PTR;
    old = psp_support_ptr->VBR;
    psp_support_ptr->VBR = new;

    return old;
}

/*!
 * \brief Gets the address of the current interrupt vector table. The function
 * depends on the PSP.
 *
 * \return Address of the current interrupt vector table.
 *
 * \see _int_set_vector_table
 * \see _int_get_previous_vector_table
 */
_psp_code_addr _int_get_vector_table
    (
        void
    )
{
    KERNEL_DATA_STRUCT_PTR kernel_data;
    PSP_SUPPORT_STRUCT_PTR   psp_support_ptr;

    _GET_KERNEL_DATA(kernel_data);
    psp_support_ptr = (PSP_SUPPORT_STRUCT_PTR)kernel_data->PSP_SUPPORT_PTR;

    return (psp_support_ptr->VBR);
}

#endif
