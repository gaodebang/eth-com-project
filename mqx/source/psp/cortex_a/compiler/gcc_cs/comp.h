
#ifndef __comp_h__
#define __comp_h__ 1

#ifdef __cplusplus
extern "C" {
#endif


#define _STRINGIFY(x) #x

#define _ASM_NOP()    asm("nop")
#define _ASM_STOP(x)  asm("stop #(" _STRINGIFY(x) ")")
#define _ASM_WFI()    asm("wfi")

#define MRC(coproc, opcode1, Rt, CRn, CRm, opcode2) \
asm volatile ("mrc " _STRINGIFY(p##coproc) " , " _STRINGIFY(opcode1) \
" , %[output] , " _STRINGIFY(c##CRn) " , " _STRINGIFY(c##CRm) " , " \
_STRINGIFY(opcode2) : [output] "=r" (Rt) : )

#define MCR(coproc, opcode1, Rt, CRn, CRm, opcode2) \
asm volatile ("mcr " _STRINGIFY(p##coproc) " , " _STRINGIFY(opcode1) \
" , %[input] , " _STRINGIFY(c##CRn) " , " _STRINGIFY(c##CRm) " , " \
_STRINGIFY(opcode2) : : [input] "r" (Rt))

#define DSB()   asm("dsb")
#define ISB()   asm("isb")

#define _PSP_SYNC()     _ASM_NOP()

#define _PSP_SET_CPSR(x) asm volatile (".arm\n msr cpsr, %0" : : "r" (x))
#define _PSP_GET_CPSR(x) asm volatile (".arm\n mrs %0, cpsr" : "=r" (x) : : )

#define _PSP_SET_ENABLE_SR(x)   { ICCPMR = GIC_PMR_PRIORITY(x); }
#define _PSP_SET_DISABLE_SR(x)  _PSP_SET_ENABLE_SR(x)

#define _WEAK_SYMBOL(x)     x __attribute__((weak))
#define _WEAK_FUNCTION(x)   x __attribute__((weak))


#ifdef __cplusplus
}
#endif

#endif

