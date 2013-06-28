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
* $FileName: dispatch_gic.s$
* $Version : 3.8.10.0$
* $Date    : Sep-24-2012$
*
* Comments:
*
*
*END************************************************************************/

#include <asm_mac.h>

#include "mqx_cnfg.h"
#include "types.inc"
#include "psp_prv.inc"

#define __ASM__
#include "psp_cpu.h"
#include "mqx_prv.h"
#undef __ASM__

                ASM_CODE_SECTION(KERNEL)

                ASM_EXTERN(_mqx_kernel_data)
                ASM_EXTERN(_sched_execute_scheduler_internal_isr)
                ASM_EXTERN(reset)

                ASM_PUBLIC(_psp_exception_return)
                ASM_PUBLIC(_int_kernel_isr_return_internal)
                ASM_PUBLIC(_int_kernel_isr)
                ASM_PUBLIC(_gic_init)

                ASM_PUBLIC_BEGIN(_gic_init)
                ASM_PUBLIC_FUNC(_gic_init)
ASM_LABEL(_gic_init)
                push {r0}
                ldr r0, =_vector_tbl
                mcr p15, 0, r0, c12, c0, 0      /* write VBAR register */

                /* SCTLR bit V - location of exception vectors -> 0x00000000-0x0000001C */
                mrc p15, 0, r0, c1, c0, 0       /* read SCTLR */
                bic r0, r0, #0x2000
                mcr p15, 0, r0, c1, c0, 0       /* write SCTLR */
                pop {r0}

                bx lr
                ASM_PUBLIC_END(_gic_init)


/*
 * This is the entry point for IRQ exception.  On entry, mode is changed to
 * IRQ and interrupts are disabled.  The lr and sp are banked and spsr
 * contains the previous cpsr from svc mode.
 */

/* interrupt prologue */
                ASM_PUBLIC_BEGIN(_int_kernel_isr)
                ASM_PUBLIC_FUNC(_int_kernel_isr)
ASM_LABEL(_int_kernel_isr)
                stmfd sp!, {r0-r12, lr}

                /* Load r1 with the address of our 8-byte workspace. */
                ldr r1, =_irq_work_space
                /* Store lr, r0, and r2 into the workspace.  We will trash these
                 * and need to recover them later. */
                str lr, [r1, #0]
                str r0, [r1, #4]
                str r2, [r1, #8]

                GET_KERNEL_DATA r3              /* get the kernel data address */

                /* increment in interrupt counter */
                ldrh r1, [r3, #KD_IN_ISR]
                add r1, r1, #1
                strh r1, [r3, #KD_IN_ISR]


                /* create interrupt content */
                ldr r0, [r3, #KD_INTERRUPT_CONTEXT_PTR] /* previous interrupt content */
                push {r0}                               /* store in stack */
                push {lr}

                ldr r5, =0x40002100             /* GICC */
                ldr r4, [r5, #4]                /* GICC_PMR 0x40002104 */
                ldr r2, =0                      /* error code (set 0) */
                ldr r1, [r5, #0x0c]             /* GICC_IAR */
                mrs r0, cpsr                    /* cpsr */
                push {r0-r2, r4}

                str sp, [r3, #KD_INTERRUPT_CONTEXT_PTR] /* previous interrupt content */

                /* check for spurious interrupt */

                /* store IAR */
                stmfd sp!, {r1}


#if MQX_KERNEL_LOGGING
                ldr r0, [r3, #KD_LOG_CONTROL]
                tst r0, #0x00000001
                beq _isr_no_logging

                /* prepare parameters for klog function, r0 = vector idx */
                mov r0, r1
                push {r0-r3}
                blx ASM_PREFIX(_klog_isr_start_internal)
                pop {r0-r3}
ASM_LABEL(_isr_no_logging)
#endif // MQX_KERNEL_LOGGING

                // check vector range
                // check if isr vector is greater then last user vector
                ldr r0, [r3, #KD_LAST_USER_ISR_VECTOR]
                cmp r1, r0
                bls _int_kernel_isr_vect_ok

                // reserved ?
                cmp r1, #1020
                blo _int_kernel_isr_vect_default

                // spurious ?
                cmp r1, #1024
                blo _int_kernel_isr_return_internal     // yes, spurious interrupt

ASM_LABEL(_int_kernel_isr_vect_default)
                mov r0, r1      // ISR number as function parameter
                // reserved vector - we will call default ISR
                ldr r1, [r3, #KD_DEFAULT_ISR]           // load address of default ISR
                b _isr_execute
ASM_LABEL(_int_kernel_isr_vect_ok)
                /* calculate offset in table */
                /* each table entry is 12 bytes in size */
                mov r0, #12
                mul r1, r1, r0

                ldr r0, [r3, #KD_INTERRUPT_TABLE_PTR]       /* pointer to interrupt table begin */
                add r1, r1, r0                              /* get address of entry in table */
                ldr r0, [r1, #IT_APP_ISR_DATA]              /* move notifier data into r0 = first parameter in C func */
                ldr r1, [r1, #0]

ASM_LABEL(_isr_execute)
                /* r0 = first parameter in C func */
                /* r1 contain interrupt function address */

                stmfd sp!, {r3}

                /* Execute the ISR */
                blx r1

ASM_LABEL(_int_kernel_isr_epilog)
                ldmfd sp!, {r3}

ASM_LABEL(_int_kernel_isr_return_internal)

                // load IAR
                ldmfd sp!, {r0}

#if MQX_KERNEL_LOGGING
                ldr r1, [r3, #KD_LOG_CONTROL]
                tst r1, #0x00000001
                beq _isr_return_no_logging

                /* prepare parameters for klog function, r0 = exception number */
                push {r0-r3}
                blx ASM_PREFIX(_klog_isr_end_internal)
                pop {r0-r3}
ASM_LABEL(_isr_return_no_logging)
#endif /* MQX_KERNEL_LOGGING */

                /* remove interrupt content */
                pop {r0-r2, r4-r6}
                str r6, [r3, #KD_INTERRUPT_CONTEXT_PTR] /* update pointer to interrupt content */

                // R1 = IAR

                /* decrement interrupt counter */
                ldrh r2, [r3, #KD_IN_ISR]
                subs r2, r2, #1
                strh r2, [r3, #KD_IN_ISR]

                // end of interrupt
                ldr r0, =0x40002100     /* GICC base address */
                str r1, [r0, #0x10]     /* GICC_EOIR */

                /* Check the result of IN_ISR.  If it's > 0 at this point, we were
                   more than one level deep.  Don't reschedule in that case. */
                tst r2, #0
                bne _isr_no_preempt

                // Check to see if we need to reschedule.
                ldr r1, [r3, #KD_ACTIVE_PTR]

                // If the task has preemption disabled, don't reschedule no matter what.
                ldr r2, [r1, #TD_FLAGS]
                ands r2, r2, #TASK_PREEMPTION_DISABLED
                bne _isr_no_preempt

                ldr r2, [r3, #KD_CURRENT_READY_Q]
                ldr r2, [r2, #0]
                cmp r1, r2
                bne _isr_sched_start_internal

ASM_LABEL(_isr_no_preempt)
                // return from interrupt
                ldmfd sp!, {r0-r12, lr}
                subs pc, lr, #4

ASM_LABEL(_isr_sched_start_internal)
                /* At this point, we are in IRQ exception mode and we need to
                 * reschedule.  We need to save the sp_irq, lr_irq, and spsr_irq
                 * before changing modes from IRQ to SVC. */

                /* pop all pushed registers back into place onto the IRQ stack. */
                ldmfd sp!, {r0-r12, lr}

                /* Change modes back to supervisor with interrupts disabled.
                 * This is done by loading the spsr into the cpsr (spsr should hold
                 * the pre-exception cpsr from svc mode).
                 * Save a copy of this spsr into r2 for later, and then disable
                 * interrupts and stay with ARM instructions when switching over. */
                mrs r2, spsr
                mov r0, r2
                orr r0, r0, #0xc0	/* Disable interrupts */
                bic r0, r0, #0x20	/* Clean thumb bit (stay in ARM mode) */
                msr cpsr_cxsf, r0

                /* Load the lr from work space into r0. */
                ldr r0, =_irq_work_space
                ldr r0, [r0, #0]

                /* Subtract 4 from lr because arm loads pc+4 into the lr when entering
                 * IRQ exception. */
                sub r0, r0, #4
                /* Write the lr to the pc-load location in the stack space
                 * (highest/first address pushed). */
                str r0, [sp, #-4]!

                /* Restore r0 and r2 from our workspace since they've been trashed.
                 * Stash away r2 (saved spsr). */
                ldr r0, =_irq_work_space
                str r2, [r0, #12]
                ldr r2, [r0, #8]
                ldr r0, [r0, #4]

                /* Push the registers on the stack frame for the task, now that we've
                 * switched over from IRQ mode back to SVC. */
                stmdb sp!, {r0-r12,lr}

                /* Load up the saved r2/spsr into r1.  Don't need to worry about
                 * trashing registers anymore. */
                ldr r0, =_irq_work_space
                ldr r1, [r0, #12]

                /* Save the spsr we saved earlier which was really the pre-ISR cpsr
                 * back into the stack for the current task before switching. */
                str r1, [sp, #-4]!

                /* save PMR to stack */
                ldr r0, =0x40002100             /* GICC_PMR */
                ldr r0, [r0, #4]                /* 0x40002104 */
                str r0, [sp, #-4]!

                /* Branch to internal scheduler.  This skips the saving of the stack
                 * frame (since we already did our context store) and launches right
                 * into reschedule. */
                b _sched_execute_scheduler_internal_isr
                ASM_PUBLIC_END(_int_kernel_isr)


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _psp_exception_return
* Returned Value   : none
* Comments         : This functions returns us from an isr exception
*
*END*----------------------------------------------------------------------*/
                ASM_PUBLIC_BEGIN(_psp_exception_return)
                ASM_PUBLIC_FUNC(_psp_exception_return)
ASM_LABEL(_psp_exception_return)
                /*
                 * This function is NOT IMPLEMENTED, because we DO NOT NEED it.
                 * Actual version of MQX, does not support nested interrupts.
                 * Situation can't occure when interrupt IRQ (which is handled
                 * by MQX) is interrupted by another interrupt wired to IRQ.
                 */
                bx lr
                ASM_PUBLIC_END(_psp_exception_return)

/* Scratch space registers. */
                ASM_ALIGN(4)
ASM_LABEL(_irq_work_space)
                ASM_CONST32(0)
                ASM_CONST32(0)
                ASM_CONST32(0)
                ASM_CONST32(0)

/* IAR (6.50 and older) has problem with ASM_CODE_SECTION(.vector_tbl) */
#if defined(__IAR_SYSTEMS_ICC__)  || defined (__IASMARM__)
                SECTION .vector_tbl : CODE
#else
                ASM_ALIGN(32)
#endif

/* this section must be aligned to 32B (VBAR) */
ASM_LABEL(_vector_tbl)
                b reset
                b undefined_handler
                b svc_handler
                b prefetch_handler
                b abort_handler
                b .                 /* reserved vector */
                b _int_kernel_isr   /* irq */
                b fiq_handle        /* fiq */

ASM_LABEL(undefined_handler)
ASM_LABEL(svc_handler)
ASM_LABEL(prefetch_handler)
ASM_LABEL(abort_handler)
ASM_LABEL(fiq_handle)
                b .

                ASM_END

