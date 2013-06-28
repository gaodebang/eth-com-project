/*
   File: ivor_branch_table_p1.c - for use with MPC560x only
   Description:  Branch table for 16 e200z0h core interrupts
   Copyright Freescale 2008.  All Rights Reserved
   Rev 1.0 Jul  6 2007 S.M. - Initial version 
   Rev 1.1 May 13 2008 D.F. - Adapted 551x version for e200z0h processors
   Rev 1.2 Feb 10 2012 FPT.H - Modified for MQX with exception entries in Flash 
*/

#ifdef __cplusplus
extern "C" {
#endif

#pragma push

#define SIXTEEN_BYTES 16

/* IVOR4 will call this handler */
extern void INTC_INTCInterruptHandler(void);

/* PSP_INT_VECTOR_ENTRY is assigned by Linker. 
 * It must point to the entry of PSP Interrupt Handler */
extern void PSP_INT_VECTOR_ENTRY (void); 

#pragma section code_type ".ivor_branch_table"
#pragma force_active on

#pragma function_align 16

/* Set interrupt handlers */
asm void ivor_branch_table(void);

asm void ivor_branch_table(void) {
  nofralloc
 
   .align SIXTEEN_BYTES
IVOR0trap: // IVOR 0 interrupt handler
   
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 0 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop

   .align SIXTEEN_BYTES
IVOR1trap: // IVOR 1 interrupt handler
    /* Does not install IVOR1 - Machine Check */
    b IVOR1trap 
    se_nop

   .align SIXTEEN_BYTES
IVOR2trap: // IVOR 2 interrupt handler	
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 2 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop

   .align SIXTEEN_BYTES
IVOR3trap: // IVOR 3 interrupt handler	
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 3 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop

   .align SIXTEEN_BYTES
IVOR4trap: // IVOR 4 interrupt handler
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 4 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop

   .align SIXTEEN_BYTES
IVOR5trap: // IVOR 5 interrupt handler	
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 5 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop
   
   .align SIXTEEN_BYTES
IVOR6trap: // IVOR 5 interrupt handler	
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 6 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop
   
   .align SIXTEEN_BYTES
IVOR7trap: // IVOR 5 interrupt handler	
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 7 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop
   
   .align SIXTEEN_BYTES
IVOR8trap: // IVOR 5 interrupt handler	
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 8 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop
   
   .align SIXTEEN_BYTES
IVOR9trap: // IVOR 5 interrupt handler	
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 9 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop
   
   .align SIXTEEN_BYTES
IVOR10trap: // IVOR 5 interrupt handler
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 10 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop

   .align SIXTEEN_BYTES
IVOR11trap: // IVOR 5 interrupt handler
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 11 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop
   
   .align SIXTEEN_BYTES
IVOR12trap: // IVOR 5 interrupt handler
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 12 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop

   .align SIXTEEN_BYTES
IVOR13trap: // IVOR 5 interrupt handler
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 13 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop
   
   .align SIXTEEN_BYTES
IVOR14trap: // IVOR 5 interrupt handler
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 14 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop
   
   .align SIXTEEN_BYTES
IVOR15trap: // IVOR 5 interrupt handler
   mtsprg0 r0 // Save r0 to SPRG0
   se_li r0, 15 // r0 = IVORx
   b PSP_INT_VECTOR_ENTRY
   se_nop



nop  // fill to 0x100 bytes
nop
nop
nop  
nop
nop
        
}

#pragma pop

#ifdef __cplusplus
}
#endif
