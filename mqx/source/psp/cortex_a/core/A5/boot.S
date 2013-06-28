/**HEADER********************************************************************
*
* Copyright (c) 2012 Freescale Semiconductor;
* All Rights Reserved
*
*****************************************************************************
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
*****************************************************************************
*
* $FileName: cortexa5_boot.S$
* $Version : 3.8.7.0$
* $Date    : Oct-3-2012$
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

                ASM_PUBLIC(__boot)
                ASM_PUBLIC(reset)

                ASM_EXTERN(init_hardware)
                ASM_EXTERN(__BOOT_STACK_ADDRESS)
                ASM_EXTERN(__cmain)
                ASM_EXTERN(_int_kernel_isr)

                // Forward declaration of sections.
                ASM_DATA_SECTION(FIQ_STACK)
                ASM_DATA_SECTION(ABT_STACK)
                ASM_DATA_SECTION(UND_STACK)
                ASM_DATA_SECTION(SUP_STACK)

#if defined(__IAR_SYSTEMS_ICC__)  || defined (__IASMARM__)
                #define FIQ_STACK_ADDR      SFE(FIQ_STACK)
                #define ABT_STACK_ADDR      SFE(ABT_STACK)
                #define UND_STACK_ADDR      SFE(UND_STACK)
                #define SUP_STACK_ADDR      SFE(SUP_STACK)
#elif defined(__CC_ARM)
                IMPORT ||Image$$FIQ_STACKS$$ZI$$Limit||
                IMPORT ||Image$$ABT_STACKS$$ZI$$Limit||
                IMPORT ||Image$$UND_STACKS$$ZI$$Limit||
                IMPORT ||Image$$SUP_STACKS$$ZI$$Limit||

                #define FIQ_STACK_ADDR      ||Image$$FIQ_STACKS$$ZI$$Limit||
                #define ABT_STACK_ADDR      ||Image$$ABT_STACKS$$ZI$$Limit||
                #define UND_STACK_ADDR      ||Image$$UND_STACKS$$ZI$$Limit||
                #define SUP_STACK_ADDR      ||Image$$SUP_STACKS$$ZI$$Limit||
#elif defined(__GNUC__)
                #define FIQ_STACK_ADDR      _FIQ_STACK_END
                #define ABT_STACK_ADDR      _ABT_STACK_END
                #define UND_STACK_ADDR      _UND_STACK_END
                #define SUP_STACK_ADDR      _SUP_STACK_END
#else
#error unsuported compiler
#endif
                ASM_CODE_SECTION(STARTUP)
                //ARM

ASM_LABEL(__boot)
                b reset
                b undefined_handler
                b svc_handler
                b prefetch_handler
                b abort_handler
                b .                     /* reserved vector */
                b _int_kernel_isr       /* irq */
                b fiq_handle            /* fiq */

ASM_LABEL(undefined_handler)
ASM_LABEL(svc_handler)
ASM_LABEL(prefetch_handler)
ASM_LABEL(abort_handler)
ASM_LABEL(fiq_handle)
                b .

ASM_LABEL(reset)
                /* disable caches, MMU - this is not required from a cold reset */
                mrc p15, 0, r0, c1, c0, 0       /* Read CP15 System Control register */
                bic r0, r0, #(0x1 << 12)        /* Clear I bit 12 to disable I Cache */
                bic r0, r0, #(0x1 <<  2)        /* Clear C bit  2 to disable D Cache */
                bic r0, r0, #0x1                /* Clear M bit  0 to disable MMU */
                bic r0, r0, #(0x1 << 11)        /* Clear Z bit 11 to disable branch prediction */
                mcr p15, 0, r0, c1, c0, 0       /* Write value back to CP15 System Control register */

                /* enable NEON MPE in secure state and nonsecure state */
                mrc p15, 0, r0, c1, c1, 2
                orr r0, r0, #3<<10           /* enable neon */
                bic r0, r0, #3<<14           /* clear nsasedis/nsd32dis */
                mcr p15, 0, r0, c1, c1, 2

                ldr r0, =(0xf << 20)
                mcr p15, 0, r0, c1, c0, 2

                mov r3, #0x40000000
                /*vmsr FPEXC, r3*/
                fmxr FPEXC, r3

                /* Go into svc mode.  Currently MQX will always operate out of this mode for kernel and user-land code.*/
                mrs r0, cpsr
                bic r0, r0, #0x1f
                orr r0, r0, #0xd3
                msr cpsr_c,r0

                /* We need to setup the user mode stuff.  Don't do this now because
                 * once we switch to user mode, we can't switch back out this way. */
                /*
                msr cpsr_c, #PSP_PSR_MODE_USER | PSP_PSR_CTRL_DIS_FIQ
                sub r1, r0, #PSP_STACK_USER_OFFSET
                mov sp, r1
                */

                /* set FIQ mode stack */
                msr cpsr_c, #PSP_PSR_MODE_FIQ | PSP_PSR_CTRL_DIS_FIQ | PSP_PSR_CTRL_DIS_IRQ
                ldr sp, =FIQ_STACK_ADDR

                /* set IRQ mode stack */
                msr cpsr_c, #PSP_PSR_MODE_IRQ | PSP_PSR_CTRL_DIS_FIQ | PSP_PSR_CTRL_DIS_IRQ
                ldr r0, =__BOOT_STACK_ADDRESS       // __stack_start
                mov sp, r1

                /* set ABORT mode stack */
                msr cpsr_c, #PSP_PSR_MODE_ABORT | PSP_PSR_CTRL_DIS_FIQ | PSP_PSR_CTRL_DIS_IRQ
                ldr sp, =ABT_STACK_ADDR

                /* set UNDEF mode stack */
                msr cpsr_c, #PSP_PSR_MODE_UNDEF | PSP_PSR_CTRL_DIS_FIQ | PSP_PSR_CTRL_DIS_IRQ
                ldr sp, =UND_STACK_ADDR

                /* set SYS mode stack */
                msr cpsr_c, #PSP_PSR_MODE_SYS | PSP_PSR_CTRL_DIS_FIQ | PSP_PSR_CTRL_DIS_IRQ
                ldr sp, =SUP_STACK_ADDR

                /* set SVC mode stack */
                msr cpsr_c, #PSP_PSR_MODE_SVC | PSP_PSR_CTRL_DIS_FIQ | PSP_PSR_CTRL_DIS_IRQ
                sub r1, r0, #0x40
                mov sp, r1

#if defined(__IAR_SYSTEMS_ICC__)  || defined (__IASMARM__)
                ASM_EXTERN(init_hardware)
                ASM_EXTERN(__cmain)
                blx ASM_PREFIX(init_hardware)
                ldr r0, =ASM_PREFIX(__cmain)
                bx r0
#elif defined(__CC_ARM)
                ASM_EXTERN(init_hardware)
                ASM_EXTERN(__main)
                blx ASM_PREFIX(init_hardware)
                b ASM_PREFIX(__main)
#elif defined(__GNUC__)
                ASM_EXTERN(init_hardware)
                ASM_EXTERN(__cs3_start_c)
                blx ASM_PREFIX(init_hardware)
                blx ASM_PREFIX(__cs3_start_c)
#endif

                ASM_END
