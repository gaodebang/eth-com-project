  
/** 
 * FILE: Exceptions.c
 *
 *  DESCRIPTION: Setup of IVPR to point to the EXCEPTION_HANDLERS memory area 
 *               defined in the linker command file.
 *               Default setup of the IVORxx registers. 
*/


/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/

#include "Exceptions.h" /* Implement functions from this file */

/*----------------------------------------------------------------------------*/
/* Function Implementations                                                   */
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif

#pragma push /* Save the current state */
/* Symbol EXCEPTION_HANDLERS is defined in the application linker command file (.lcf) 
   It is defined to the start of the code memory area used for the .__exception_handlers section. 
*/
/*lint -esym(752, EXCEPTION_HANDLERS) */
__declspec (section ".__exception_handlers_p0") extern long EXCEPTION_HANDLERS;  
#pragma force_active on
#pragma function_align 16 /* We use 16 bytes alignment for Exception handlers */
__declspec(interrupt)
__declspec (section ".__exception_handlers_p0")
void EXCEP_DefaultExceptionHandler(void)
{

}
#pragma force_active off
#pragma pop

#define IVOR_HANDLER_ADDR(x) (EXCEPTION_HANDLERS + (x)*32)

__asm void EXCEP_InitExceptionHandlers(void)
{
nofralloc

    /* Set the IVPR to the Exception Handlers address defined in the lcf file
     * IVPR 0-15 bits Vector Base
     * IVPR 16-31 bits ignored
     * */
    lis     r0, EXCEPTION_HANDLERS@h
    mtivpr  r0

    li		r0, (IVOR_HANDLER_ADDR(0))@l
    mtivor0 r0
    
    li		r0, (IVOR_HANDLER_ADDR(1))@l
    mtivor1 r0
    
    li		r0, (IVOR_HANDLER_ADDR(2))@l
    mtivor2 r0
       	
    li		r0, (IVOR_HANDLER_ADDR(3))@l
    mtivor3 r0
       	
    li		r0, (IVOR_HANDLER_ADDR(4))@l
    mtivor4 r0
     	
    li		r0, (IVOR_HANDLER_ADDR(5))@l
    mtivor5 r0
    
    li		r0, (IVOR_HANDLER_ADDR(6))@l
    mtivor6 r0
    
    li		r0, (IVOR_HANDLER_ADDR(7))@l
    mtivor7 r0
    
    li		r0, (IVOR_HANDLER_ADDR(8))@l
    mtivor8 r0
    
    li		r0, (IVOR_HANDLER_ADDR(9))@l
    mtivor9 r0
    
    li		r0, (IVOR_HANDLER_ADDR(10))@l
    mtivor10 r0
    
    li		r0, (IVOR_HANDLER_ADDR(11))@l
    mtivor11 r0
    
    li		r0, (IVOR_HANDLER_ADDR(12))@l
    mtivor12 r0
    
    li		r0, (IVOR_HANDLER_ADDR(13))@l
    mtivor13 r0
    
    li		r0, (IVOR_HANDLER_ADDR(14))@l
    mtivor14 r0
    
    li		r0, (IVOR_HANDLER_ADDR(15))@l
    mtivor15 r0

    blr
}

#ifdef __cplusplus
}
#endif

