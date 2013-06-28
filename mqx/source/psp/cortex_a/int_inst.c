/*HEADER*********************************************************************
*
* Copyright (c) 2010 Freescale Semiconductor;
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
* $FileName: int_inst.c$
* $Version : 3.8.1.0$
* $Date    : Jul-3-2012$
*
* Comments:
*
*   This file contains the function for initializing the handling of
*   interrupts.
*
*END************************************************************************/

#include "mqx_inc.h"

/* We need to save the stack pointer for the various interrupt modes */
uint_32 _psp_irq_sp;
uint_32 _psp_fiq_sp;
uint_32 _psp_undef_sp;
uint_32 _psp_abort_sp;

/*!
 * \brief This function initializes kernel interrupt tables.
 */
void _psp_int_install(void) {
   KERNEL_DATA_STRUCT_PTR kernel_data;
   uint_32_ptr vectors;
   uint_32 offset;
   uint_32 i;
   uint_32 cpsr;

   _GET_KERNEL_DATA(kernel_data);

   _PSP_GET_CPSR(cpsr);
   _PSP_SET_CPSR(PSP_PSR_MODE_IRQ | PSP_PSR_CTRL_DIS_FIQ | PSP_PSR_CTRL_DIS_IRQ);
   __set_SP((uint_32)kernel_data->INTERRUPT_STACK_PTR);
   _PSP_SET_CPSR(cpsr);

   vectors = (uint_32_ptr) _int_get_vector_table();
   offset = (uint_32) vectors;
}
