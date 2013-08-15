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
* $FileName: iar_comp.h$
* $Version : 3.8.4.0$
* $Date    : Oct-1-2012$
*
* Comments:
*
*   This file defines the IAR compiler specific macros for MQX
*
*END************************************************************************/
#ifndef __comp_h__
#define __comp_h__ 1

#include <intrinsics.h>

#ifdef __cplusplus
extern "C" {
#endif


#if ((__VER__) < 6050000)
#error "MQX requires IAR version 6.5 or higher"
#endif


#define _ASM_NOP()    asm("nop")
#define _ASM_STOP(x)  asm("stop #(" #x ")")
#define _ASM_WFI()    asm("wfi")

#define MRC(coproc, opcode1, Rt, CRn, CRm, opcode2)		{ Rt = __MRC(coproc, opcode1, CRn, CRm, opcode2); }
#define MCR(coproc, opcode1, Rt, CRn, CRm, opcode2)		{ __MCR(coproc, opcode1, Rt, CRn, CRm, opcode2); }
#define DSB()	{ __DSB(); }
#define ISB()	{ __ISB(); }

#define _PSP_SYNC()     _ASM_NOP()

#define _PSP_SET_CPSR(x) __set_CPSR(x)
#define _PSP_GET_CPSR(x) (x = __get_CPSR())

// TODO move to GIC implementation
#define _PSP_SET_ENABLE_SR(x)   { ICCPMR = GIC_PMR_PRIORITY(x); }
#define _PSP_SET_DISABLE_SR(x)  _PSP_SET_ENABLE_SR(x)

#define _WEAK_SYMBOL(x)     __weak x
#define _WEAK_FUNCTION(x)   __weak x

#if MQX_ENABLE_USER_MODE
#define KERNEL_ACCESS  _Pragma("location=\".kernel_data\"")
#define USER_RW_ACCESS _Pragma("location=\".rwuser\"")
#define USER_RO_ACCESS _Pragma("location=\".rouser\"")
#define USER_NO_ACCESS _Pragma("location=\".nouser\"")

#else /* MQX_ENABLE_USER_MODE */

#define KERNEL_ACCESS
#define USER_RW_ACCESS
#define USER_RO_ACCESS
#define USER_NO_ACCESS

#endif /* MQX_ENABLE_USER_MODE */

#ifdef __cplusplus
}
#endif

#endif
