/*
   File: ivor_branch_table_p0.c - for use with MPC551x only
   Description:  Branch table for 16 MPC551x core interrupts
   Copyright Freescale 2007.  All Rights Reserved
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
__interrupt_vector_table:
__ivor0:    b   __ivor0

                .align IVOR_TABLE_ALIGN
__machine_check:                // No recovery or notification attempted yet!
__ivor1:
            b   __ivor1

                .align IVOR_TABLE_ALIGN
__ivor2:    b   __ivor2

                .align IVOR_TABLE_ALIGN
__ivor3:    b   __ivor3

                .align IVOR_TABLE_ALIGN
__ivor4:    b   __ivor4

                .align IVOR_TABLE_ALIGN
__ivor5:    b   __ivor5

                .align IVOR_TABLE_ALIGN
__ivor6:    b   __ivor6

                .align IVOR_TABLE_ALIGN
__ivor7:    b   __ivor7

                .align IVOR_TABLE_ALIGN
__ivor8:    b   __ivor8

                .align IVOR_TABLE_ALIGN
__ivor9:    b   __ivor9

                .align IVOR_TABLE_ALIGN
__ivor10:   b   __ivor10

                .align IVOR_TABLE_ALIGN
__ivor11:   b   __ivor11

                .align IVOR_TABLE_ALIGN
__ivor12:   b   __ivor12

                .align IVOR_TABLE_ALIGN
__ivor13:   b   __ivor13

                .align IVOR_TABLE_ALIGN
__ivor14:   b   __ivor14

                .align IVOR_TABLE_ALIGN
__ivor15:   b   __ivor15

            nop                 // padding
            nop
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
