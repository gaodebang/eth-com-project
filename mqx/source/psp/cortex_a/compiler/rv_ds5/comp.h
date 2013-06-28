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
* $FileName: comp.h$
* $Version : 3.8.6.0$
* $Date    : Oct-1-2012$
*
* Comments:
*
*   This file defines the DS5 compiler specific macros for MQX
*
*END************************************************************************/
#ifndef __comp_h__
#define __comp_h__ 1

#ifdef __cplusplus
extern "C" {
#endif

static inline void _PSP_SET_CPSR(uint_32 x) {
	register unsigned int regCPSR __asm("cpsr");
	regCPSR = x;
}

static inline uint_32 __PSP_GET_CPSR(void) {
	register unsigned int regCPSR __asm("cpsr");
	return regCPSR;
}

static inline uint_32 __get_SP(void) {
	register unsigned int regSP __asm("sp");
	return regSP;
}

static inline  uint_32 __get_PC(void) {
	register unsigned int regPC __asm("pc");
	return regPC;
}

static inline  uint_32 __get_LR(void) {
	register unsigned int regLR __asm("lr");
	return regLR;
}

#define _PSP_GET_CPSR(x)	x = __PSP_GET_CPSR()


#define _PSP_SET_ENABLE_SR(x)   { ICCPMR = GIC_PMR_PRIORITY(x); }
#define _PSP_SET_DISABLE_SR(x)  _PSP_SET_ENABLE_SR(x)

#define _ASM_NOP()   __nop()
#define _ASM_WFI()   __wfi()
#define _ASM_SLEEP   _ASM_WFI

/* eclipse CDT parser/indexer have problem with parsing __asm{} macros bellow, this is workaround */
#ifdef __CDT_PARSER__
#define MRC(coproc, opcode1, Rt, CRn, CRm, opcode2)
#define MCR(coproc, opcode1, Rt, CRn, CRm, opcode2)
#define DSB()
#define ISB()
#else
#define MRC(coproc, opcode1, Rt, CRn, CRm, opcode2)      __asm{mrc p##coproc, opcode1, Rt, c##CRn, c##CRm, opcode2}
#define MCR(coproc, opcode1, Rt, CRn, CRm, opcode2)      __asm{mcr p##coproc, opcode1, Rt, c##CRn, c##CRm, opcode2}
#define DSB()   __asm{dsb}
#define ISB()   __asm{isb}
#endif

#define _PSP_SYNC()

#define _WEAK_SYMBOL(x)     __weak x
#define _WEAK_FUNCTION(x)   __weak x

#if MQX_ENABLE_USER_MODE
#define KERNEL_ACCESS  __attribute__((section(".kernel_data")))
#define USER_RW_ACCESS __attribute__((section(".rwuser")))
#define USER_RO_ACCESS __attribute__((section(".rouser")))
#define USER_NO_ACCESS __attribute__((section(".nouser")))

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
