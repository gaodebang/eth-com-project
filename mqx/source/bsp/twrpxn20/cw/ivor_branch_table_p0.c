/*
   File: ivor_branch_table_p0.c - for use with MPC5568x only
   Description:  Branch table for 16 MPC5568x core interrupts
   Copyright Freescale 2007.  All Rights Reserved
   Rev 1.0 Jul 6 2007 S.M. - Initial version
   Rev 2.0 Dec 1 2011 FPT Team - Modified alignment to 32 for MPC5568x 
    Translated to inline assembly to allow easy transition to VLE
*/

#ifdef __cplusplus
extern "C" {
#endif

#pragma push

#define IVOR_TABLE_ALIGN 32

#pragma section code_type ".ivor_branch_table_p0"
#pragma force_active on
#pragma function_align 32  

asm void ivor_branch_table_p0(void) {
  nofralloc
  
				.align IVOR_TABLE_ALIGN       
IVOR0trap:  b	IVOR0trap	 // IVOR 0 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR1trap:  b	IVOR1trap	 // IVOR 1 interrupt handler
						
				.align IVOR_TABLE_ALIGN       
IVOR2trap:  b	IVOR2trap	 // IVOR 2 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR3trap:  b	IVOR3trap	 // IVOR 3 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR4trap:  b   IVOR4trap // IVOR 4 handler (External Interrupt)

				.align IVOR_TABLE_ALIGN       
IVOR5trap:  b	IVOR5trap       // IVOR 5 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR6trap:  b	IVOR6trap	 // IVOR 6 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR7trap:  b	IVOR7trap	 // IVOR 7 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR8trap:  b	IVOR8trap	 // IVOR 8 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR9trap:  b	IVOR9trap	 // IVOR 9 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR10trap: b   IVOR10trap   // IVOR 10 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR11trap:  b	IVOR11trap	 // IVOR 11 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR12trap:  b	IVOR12trap	 // IVOR 12 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR13trap:  b	IVOR13trap	 // IVOR 13 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR14trap:  b	IVOR14trap	 // IVOR 14 interrupt handler

				.align IVOR_TABLE_ALIGN       
IVOR15trap:  b	IVOR15trap	 // IVOR15 interrupt handler

        nop  // fill to 0x100 bytes
        nop
        nop
        
}

#pragma pop

#ifdef __cplusplus
}
#endif

/* EOF */
