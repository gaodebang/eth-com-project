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
* $FileName: int_pc.c$
* $Version : 3.8.1.0$
* $Date    : Jul-3-2012$
*
* Comments:
*
*   This file contains the function for resetting the pc of interrupted task.
*END************************************************************************/

#include "mqx_inc.h"

/* Saved the stack pointers for the various interrupt modes */
extern uint_32 _psp_irq_sp;
extern uint_32 _psp_fiq_sp;
extern uint_32 _psp_undef_sp;
extern uint_32 _psp_abort_sp;

/*
 * \brief This function sets the pc of an interrupted task.
 *
 * \param[in] td_stack_ptr Stack pointer of selected task.
 * \param[in] function     The function to set the pc to.
 */
void _psp_set_pc_of_interrupted_task
    (
        PSP_BASIC_INT_FRAME_STRUCT_PTR td_stack_ptr,
        void (_CODE_PTR_ function)(uint_32)
    )
{
    PSP_BASIC_INT_FRAME_STRUCT_PTR  stack_ptr;
    KERNEL_DATA_STRUCT_PTR kernel_data;

    _GET_KERNEL_DATA(kernel_data);

    stack_ptr = kernel_data->INTERRUPT_STACK_PTR;
    /*
    * Stack pointer is actually on the top. We need to add the stack
    * frame to it
    */
    stack_ptr--;

    stack_ptr->STACK.PC = (uint_32)function + 4;         // +4 because return from exception (IRQ)... (subs pc, lr, #4)

#if 0
    if ((uint_32)function & 1) {
        /* Fix SPSR to return to thumb mode */
        tmp = _psp_get_spsr();
        tmp |= 0x20;
        _psp_set_spsr(tmp);
    }
#endif
}
