/*
 *
 * FILE : MPC5606S_HWInit.c
 *
 * DESCRIPTION:
 *  This file contains the initialization for MPC5606S derivative
*  - External Bus Interface to allow access to memory on the external bus
* - init SRAM
 */

#include "MPXD10_cw.h"   /* MPC55xx platform development header */
#include "MPXD10_HWInit.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Initialize the SIU External Bus Interface */
__asm void __initSIUExtBusInterface(void);

/* Initialize a set of contiguous PCRs */
__asm void InitPCRs(void); 

/* Symbol L2SRAM_LOCATION is defined in the application linker command file (.lcf)
   It is defined to the start of the L2SRAM of the PXD1010
*/
/*lint -esym(752, L2SRAM_LOCATION) */
extern long L2SRAM_LOCATION;  


__asm void INIT_Derivative(void) 
{
nofralloc
    /* Disable WatchDog*/
    // *(volatile unsigned int*)0xfff38010 = 0x0000c520; 
    e_lis r9,0x0001
    e_add16i r9,r9,-15072
    e_lis r8,0xfff4
    e_stw r9,-32752(r8)
    //  *(volatile unsigned int*) 0xfff38010 = 0x0000d928; 
    e_lis r9,0x0001
    e_add16i r9,r9,-9944
    e_lis r8,0xfff4
    e_stw r9,-32752(r8)
    // *(volatile unsigned int*) 0xfff38000 = 0xff00000A; 
    e_lis r3,0xff00
    se_addi r3,0x000a
    e_lis r8,0xfff4
    e_stw r3,-32768(r8)
    
    /* PXD1010 SRAM initialization code*/
    lis r11,L2SRAM_LOCATION@h
    ori r11,r11,L2SRAM_LOCATION@l
    li r12,384 /* Loops to cover 48K SRAM; 48k/4 bytes/32 GPRs = 384 */
    mtctr r12

    init_l2sram_loop:
        stmw r0, 0(r11)        /* Write 32 GPRs to SRAM*/
        addi r11,r11,128      /* Inc the ram ptr; 32 GPRs * 4 bytes = 128B */
        bdnz init_l2sram_loop /* Loop for 48k of SRAM */
    blr
}

/*******************************************************/
/* PXD1010 specific hardware initializations                            */
/*******************************************************/

/** This macro allows to use C defined address with the inline assembler */
#define MAKE_HLI_COMPATIBLE(hli_name, c_expr) enum { hli_name=/*lint -e30*/((int)(c_expr)) };

__asm void INIT_ExternalBusAndMemory(void) 
{
nofralloc

    mflr     r28
    
    /* Initialize the SIU External Bus Interface */
    bl __initSIUExtBusInterface
    
    mtlr     r28
    
    blr
}

/*----------------------------------------------------------------------------*/
/* SIU External Bus Interface                                                 */
/*----------------------------------------------------------------------------*/

/* Initialize a set of contiguous PCRs:               */
/* r3: the firts PCR to initialize                    */
/* r4: the value to write in the PCRs                 */ 
/* r5: the number of PCRs to initialize               */
__asm void InitPCRs(void) 
{
nofralloc

    mtctr r5                   /* intialize ctr with the number of PCRs to initialize */
    pcr_init_loop:
        sth r4,0(r3)           /* Write r4 to current PCR address */
        addi r3,r3, 2          /* Inc the memory ptr by 2 to point to the next PCR */
        bdnz pcr_init_loop     /* Loop for ctr PCRs */

    blr
}

/* Initialize the SIU External Bus Interface */
__asm void __initSIUExtBusInterface(void)
{ 
MAKE_HLI_COMPATIBLE(SIU_PCR0,&SIU.PCR[0].R)
MAKE_HLI_COMPATIBLE(SIU_PCR4,&SIU.PCR[4].R)
MAKE_HLI_COMPATIBLE(SIU_PCR28,&SIU.PCR[28].R)
MAKE_HLI_COMPATIBLE(SIU_PCR62,&SIU.PCR[62].R)
MAKE_HLI_COMPATIBLE(SIU_PCR64,&SIU.PCR[64].R)
MAKE_HLI_COMPATIBLE(SIU_PCR68,&SIU.PCR[68].R)
nofralloc

    mflr r27

    /*  This initializes the PXD1010 external bus
        Set up the pins
        Address bus PCR 4 - 27
        Configure address bus pins
    */
    lis r3,SIU_PCR4@h          /* First PCR Address bus is PCR 4 */
    ori r3,r3,SIU_PCR4@l
    li r5,24                   /* Loop counter to get all address bus PCR (4 to 27) -> 24 PCRs  */
    li r4, 0x0440              /* PCRs initialization value */
    bl InitPCRs

    /*  Data bus PCR 28-59
        Configure data bus pins
    */
    lis r3,SIU_PCR28@h         /* First PCR for data bus is PCR 28 */
    ori r3,r3,SIU_PCR28@l
    li r5,32                   /* Loop counter to get all data bus PCR (28-59) -> 32 PCRs  */
    li r4, 0x0440              /* PCRs initialization value */
    bl InitPCRs

    /*  Configure minimum bus control pins
        RD/WR  & BDIP PCR 62/63
    */
    lis r3,SIU_PCR62@h         /* First PCR for is PCR 62 */
    ori r3,r3,SIU_PCR62@l
    li r5,2                    /* Loop counter to get all PCR (62-63) -> 2 PCRs  */
    li r4, 0x0440              /* PCRs initialization value */
    bl InitPCRs

    /*  WE[0-4] PCR 64-67
    */
    lis r3,SIU_PCR64@h         /* First PCR for is PCR 64 */
    ori r3,r3,SIU_PCR64@l
    li r5,4                    /* Loop counter to get all PCR (64-67) -> 4 PCRs  */
    li r4, 0x0443              /* PCRs initialization value */
    bl InitPCRs

    /*  OE & TS
    */
    lis r3,SIU_PCR68@h         /* First PCR for is PCR 68 */
    ori r3,r3,SIU_PCR68@l
    li r5,2                    /* Loop counter to get all PCR (68-69) -> 2 PCRs  */
    li r4, 0x0443              /* PCRs initialization value */
    bl InitPCRs
    
    /*  Configure the chip selects
        CS[0-3]
    */
    lis r3,SIU_PCR0@h          /* First PCR for is PCR 0 */
    ori r3,r3,SIU_PCR0@l
    li r5,4                    /* Loop counter to get all PCR (0-3) -> 4 PCRs  */
    li r4, 0x0443              /* PCRs initialization value */
    bl InitPCRs
    
    mtlr r27
    
    blr
}

#ifdef __cplusplus
}
#endif
