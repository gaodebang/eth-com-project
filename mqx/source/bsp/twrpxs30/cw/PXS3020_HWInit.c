
/*
 *
 * FILE : PXS3020_HWInit.c
 *
 * DESCRIPTION:
 *  This file contains all PXS3020 derivative needed initializations,
 *  and all initializations for the PXS3020 boards which are supported.
 *  This includes setting up the External Bus Interface to allow access
 *  to memory on the external bus, and ensuring there is a valid entry in
 *  the MMU for the external memory access.
 */

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/

#include "PXS3020_cw.h"     /* PXS30xx platform development header            */
#include "PXS3020_HWInit.h"
#include <mqx.h>
#include <bsp.h>

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************/
/* PXS3020 derivative specific hardware initialization */
/*******************************************************/

/*----------------------------------------------------------------------------*/
/* Function declarations                                                      */
/*----------------------------------------------------------------------------*/

/* All these functions must be located in the initial 4KB memory window (.init)
    and implemented "nofralloc" so as to not use the stack */

/* Memory initialization */
__declspec(section ".init") __asm void INIT_Derivative(void);

/* Write one MMU Table Entry */
__declspec(section ".init") __asm void WriteMMUTableEntry( void );

/* Initialize the needed MMU Table entries */
__declspec(section ".init") __asm void __initMMU(void);


/* This macro allows to use C defined address with the inline assembler */
#define MAKE_HLI_COMPATIBLE(hli_name, c_expr) enum { hli_name=/*lint -e30*/((int)(c_expr)) };


/*----------------------------------------------------------------------------*/
/* Function implementations                                                   */
/*----------------------------------------------------------------------------*/

/* Symbol L2SRAM_LOCATION is defined in the application linker command file (.lcf)
   It is defined to the start of the L2SRAM of the PXS3020.
*/
/*lint -esym(752, L2SRAM_LOCATION) */
extern long L2SRAM_LOCATION;
extern long L2SRAM_INIT_LEN;

__asm void INIT_Derivative(void)
{
    nofralloc

    /* Don't have a stack yet, save the return address in a register */
    mflr r26;
    bl __initMMU

    mtlr r26;

    /* PXS3020 L2SRAM initialization code */
    lis r11,L2SRAM_LOCATION@h /* Base address of the L2SRAM, 64-bit word aligned */
    ori r11,r11,L2SRAM_LOCATION@l

    lis r12,L2SRAM_INIT_LEN@h /* Length of memory area to initialize */
    ori r12,r12,L2SRAM_INIT_LEN@l

    srwi. r12,r12,7 /* Loop counter; actual length/4 bytes/32 GPRs */
    bt eq,init_l2sram_end
    mtctr r12

    init_l2sram_loop:
        stmw r0,0(r11)        /* Write all 32 GPRs to L2SRAM */
        addi r11,r11,128      /* Inc the ram ptr; 32 GPRs * 4 bytes = 128 */
        bdnz init_l2sram_loop /* Loop for all L2SRAM */
    init_l2sram_end:

    //*(volatile unsigned int*)0xfff38010 = 0x0000C520;
    lis r4,1
    subi r4,r4,15072
    lis r3,-12
    stw r4,-32752(r3)
    //*(volatile unsigned int*) 0xfff38010 = 0x0000D928;
    lis r4,1
    subi r4,r4,9944
    lis r3,-12
    stw r4,-32752(r3)
    //*(volatile unsigned int*) 0xfff38000 = 0x8000010A;
    lis r4,-32768
    addi r4,r4,266
    lis r3,-12
    stw r4,-32768(r3)

    blr
}


/*----------------------------------------------------------------------------*/
/* Writing to MMU Table Entries                                               */
/*----------------------------------------------------------------------------*/

/* Initialize the needed MMU Table entries */

/* Set up MMU for internal memory just like the debugger: a single window, 4GB wide
   Base address = 0x0000_0000
   4 GByte Memory Space, Not Guarded, Cachable, All Access
*/

#if __option(vle)
    #define PAGE_MODE _VLE_MODE
#else
    #define PAGE_MODE BOOK_E_MODE
#endif

#define LOAD_REG(r,v) \
    lis r,v @h; \
    ori r,r,v @l;

#define LOAD_MMU_ENTRY(mas0,mas1,mas2,mas3) \
    LOAD_REG(r3, mas0) \
    LOAD_REG(r4, mas1) \
    LOAD_REG(r5, mas2) \
    LOAD_REG(r6, mas3) \
    bl WriteMMUTableEntry;


__asm void __initMMU(void)
{
    MAKE_HLI_COMPATIBLE(FLASH_MAS0_VALUE,MAS0_VALUE(BSP_FLASH_TLB))
    MAKE_HLI_COMPATIBLE(FLASH_MAS1_VALUE,MAS1_VALUE(V_VALID, IPROT_PROTECTED, TID_GLOBAL, 0, TSIZE_1GB))
//MAKE_HLI_COMPATIBLE(FLASH_MAS2_VALUE,MPXS30_FLASH_BASE|MAS2_FLAGS(SHARED_CACHE_STATE_NOT_USED, PAGE_MODE, WRITE_BACK, CACHE_INHIBIT, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN ))
    MAKE_HLI_COMPATIBLE(FLASH_MAS2_VALUE,MPXS30_FLASH_BASE|MAS2_FLAGS(SHARED_CACHE_STATE_NOT_USED, PAGE_MODE, WRITE_THROUGH, CACHEABLE,  MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN ))
    MAKE_HLI_COMPATIBLE(FLASH_MAS3_VALUE,MPXS30_FLASH_BASE|MAS3_FLAGS(READ_WRITE_EXECUTE))

    MAKE_HLI_COMPATIBLE(RAM_MAS0_VALUE,MAS0_VALUE(BSP_RAM_TLB))
    MAKE_HLI_COMPATIBLE(RAM_MAS1_VALUE,MAS1_VALUE(V_VALID, IPROT_PROTECTED, 1, 0, TSIZE_256KB ))
    MAKE_HLI_COMPATIBLE(RAM_MAS2_VALUE,RAM_VIRTUAL_ADDRESS|MAS2_FLAGS(SHARED_CACHE_STATE_NOT_USED, PAGE_MODE, WRITE_BACK, CACHE_INHIBIT, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN ))
    MAKE_HLI_COMPATIBLE(P0_RAM_MAS3_VALUE,MPXS30_SRAM_CORE_0_BASE|MAS3_FLAGS(READ_WRITE_EXECUTE))
    MAKE_HLI_COMPATIBLE(P1_RAM_MAS3_VALUE,MPXS30_SRAM_CORE_1_BASE|MAS3_FLAGS(READ_WRITE_EXECUTE))

    MAKE_HLI_COMPATIBLE(PERIPHERAL_MAS0_VALUE,MAS0_VALUE(BSP_PERIPHERAL_TLB))
    MAKE_HLI_COMPATIBLE(PERIPHERAL_MAS1_VALUE,MAS1_VALUE(V_VALID, IPROT_PROTECTED, TID_GLOBAL, 0, TSIZE_2GB))
    MAKE_HLI_COMPATIBLE(PERIPHERAL_MAS2_VALUE,MPXS30_PERIPHERAL_BASE|MAS2_FLAGS(SHARED_CACHE_STATE_NOT_USED, PAGE_MODE, WRITE_BACK, CACHE_INHIBIT, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN ))
    MAKE_HLI_COMPATIBLE(PERIPHERAL_MAS3_VALUE,MPXS30_PERIPHERAL_BASE|MAS3_FLAGS(READ_WRITE_EXECUTE))



nofralloc

    mflr    r27
    LOAD_MMU_ENTRY(FLASH_MAS0_VALUE,FLASH_MAS1_VALUE,FLASH_MAS2_VALUE,FLASH_MAS3_VALUE)

    // Set PID=1
    li      r3,BSP_PID_BOOT
    mtspr   spr48,r3

    // check which core we are running on
    mfspr   r3,spr286
    cmpi    r3,0
    bne     do_p1_ram
    // We are core 0, init RAM to point to core 0's ram
    LOAD_MMU_ENTRY(RAM_MAS0_VALUE,RAM_MAS1_VALUE,RAM_MAS2_VALUE,P0_RAM_MAS3_VALUE)
    b       do_periph
do_p1_ram:
    // We are core 1, init RAM to point to core 1's ram
    LOAD_MMU_ENTRY(RAM_MAS0_VALUE,RAM_MAS1_VALUE,RAM_MAS2_VALUE,P1_RAM_MAS3_VALUE)
do_periph:
    LOAD_MMU_ENTRY(PERIPHERAL_MAS0_VALUE,PERIPHERAL_MAS1_VALUE,PERIPHERAL_MAS2_VALUE,PERIPHERAL_MAS3_VALUE)
    mtlr   r27

    blr
}

/* Write one MMU Table Entry:               */
/* r3, r4, r5 and r6 must hold              */
/* the values of MAS0, MAS1, MAS2 and MAS3  */
__asm void WriteMMUTableEntry( void )
{
nofralloc

    /* Write MMU Assist Register 0 (MAS0); SPR 624 */
    mtspr   624, r3
    /* Write MMU Assist Register 1 (MAS1); SPR 625 */
    mtspr   625, r4
    /* Write MMU Assist Register 2 (MAS2); SPR 626 */
    mtspr   626, r5
    /* Write MMU Assist Register 3 (MAS3); SPR 627 */
    mtspr   627, r6
    /* Write the table entry */
    tlbwe

    blr
}

/*******************************************************/
/* PXS3020 boards specific hardware initializations    */
/*******************************************************/


/*----------------------------------------------------------------------------*/
/* Function declarations                                                      */
/*----------------------------------------------------------------------------*/

/* Initialize a set of contiguous PCRs */
__asm void InitPCRs(void);

/* Initialize the SIU External Bus Interface */
__asm void __initSIUExtBusInterface(void);

/* Initialize the used EBI Chip Selects */
__asm void __initEBIChipSelects(void);


/*----------------------------------------------------------------------------*/
/* Function implementations                                                   */
/*----------------------------------------------------------------------------*/

void ClockInit(void) {
    if (_psp_core_num()==0) {
        /* Clear all reset flags to avoid staying in SAFE mode */
        RGM.FES.R = 0xFFFF;         /* Clear all flags */

        CGM.CMU_0_CSR.R = 0x00000006;   /* Avoid CMU reset when fXOSC<fIRC */

        CGM.AC3_SC.R = 0x01000000;      /* Select Xosc as PLL0 source clock */
        CGM.AC4_SC.R = 0x01000000;      /* Select Xosc as PLL1 source clock */
        CGM.AC0_SC.R = 0x05000000;      /* PLL_1 output as Motor control clock */
        CGM.AC0_DC0.R = 0x80000000;     /* Divided by 1, prescaler enabled */
        CGM.SC_DC0.R = 0x80810000;      /* Peripheral set 0 clock div. by 1 */
                                        /* Peripheral set 1 clock div. by 2 */

        CGM.AC2_SC.R = 0x05000000;      /* PLL_1 secondary output (80) for FlexCan clock */
        CGM.AC2_DC0.R = 0x81000000;     /* Divided by 2, prescaler enabled */

        /* Setup OSC */
        ME.RUN[0].R = 0x001F00F4;       /* Main vol. reg. ON */
                                        /* PLL0/1 ON, XOSC ON, 16MHz_IRC ON */
                                        /* DFLASH/CFLASH ON */
                                        /* system clock is sourced from PLL0 */

        /* Setup PLL0 - 180MHz @ 40MHz XOSC */
        CGM.FMPLL[0].CR.B.IDF=0x3;      /* Divide by 4 for 40MHz XTAL */
        CGM.FMPLL[0].CR.B.ODF=0x0;      /* Divide by 2 */
        CGM.FMPLL[0].CR.B.NDIV=36;      /* Loop divide by 36 for 40 MHz crystal */

        /* Setup PLL1 - 90MHz @ 40MHz XOSC */
        CGM.FMPLL[1].CR.B.IDF=0x3;      /* Divide by 4 for 40MHz XTAL */
        CGM.FMPLL[1].CR.B.ODF=0x1;      /* Divide by 4 */
        CGM.FMPLL[1].CR.B.NDIV=36;      /* Loop divide by 36 for 40 MHz crystal */

        /* Setting RUN Configuration Register ME_RUN_PC[0] */
        ME.RUNPC[0].R=0x000000FE;       /* Peripheral ON in every mode */

        /* Enter the RUN mode */
        ME.MCTL.R = 0x40005AF0;         /* Mode & Key */
        ME.MCTL.R = 0x4000A50F;         /* Mode & Key inverted */

        /* Wait for mode entry to complete */
        while(ME.GS.B.S_MTRANS == 1) {}

        /* Wait for PLL0 to lock */
        while(CGM.FMPLL[0].CR.B.S_LOCK != 1) {}

        /* Wait for PLL1 to lock */
        while(CGM.FMPLL[1].CR.B.S_LOCK != 1) {}
    }
}

void P1_Start(void * fn)
{
    SSCM.DPMBOOT.R = (unsigned int) fn;
    SSCM.DPMKEY.R = 0x5af0;
    SSCM.DPMKEY.R = 0xa50f;
}


// NOTE: The remaining functions are currently not used on TWRPXS30, will need to be added if DDR is populated

__asm void INIT_ExternalBusAndMemory(void)
{
nofralloc

    mflr     r28

    /* Initialize the SIU External Bus Interface */
    bl __initSIUExtBusInterface
    /* Initialize the used EBI Chip Selects */
    bl __initEBIChipSelects
    /* TODO: Initialize the needed MMU Table entries for external memory */
    /* bl __initMMUExternalMemory */

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

    /*  This initializes the PXS3020 external bus
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

/*----------------------------------------------------------------------------*/
/* EBI Chip Selects                                                           */
/*----------------------------------------------------------------------------*/

/* Initialize the used EBI Chip Selects */
__asm void __initEBIChipSelects(void)
{
#if INIT_USED_BOARD==PXS3020DEMO_AXM_0321
MAKE_HLI_COMPATIBLE(EBBI_CS0_BR,&EBI.CS[0].BR.R)
MAKE_HLI_COMPATIBLE(EBBI_CS0_OR,&EBI.CS[0].OR.R)
#endif
nofralloc

#if INIT_USED_BOARD==PXS3020DEMO_AXM_0321
    /*  CY7C1338 512K External SRAM - 4 beat burst, 0 wait
        Set up Memory Controller CS0 @ AXM_0321_EXTERNAL_RAM
    */
    /*  EBI.CS[0].BR.R = (unsigned long)AXM_0321_EXTERNAL_RAM | 0x41UL;
    */
    lis      r3,AXM_0321_EXTERNAL_RAM@h
    addi     r0,r3,AXM_0321_EXTERNAL_RAM@l
    ori      r0,r0,0x0041
    lis      r3,EBBI_CS0_BR@ha
    ori      r3,r3,EBBI_CS0_BR@l
    stw      r0,0(r3)
    /*  EBI.CS[0].OR.R = 0xfff80000;
    */
    lis      r0,0xfff8
    lis      r3,EBBI_CS0_OR@h
    ori      r3,r3,EBBI_CS0_OR@l
    stw      r0,0(r3)
#endif

    blr
}


#ifdef __cplusplus
}
#endif
