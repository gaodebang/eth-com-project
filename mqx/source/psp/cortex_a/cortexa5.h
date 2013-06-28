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
* $FileName: cortexa5.h$
* $Version : 3.8.7.0
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This file contains the type definitions for the ARM Cortex processors.
*
*END************************************************************************/
#ifndef __cortexa5_h__
#define __cortexa5_h__

/* MMU constant definition of L1 table */
#define MMU_TRANSLATION_TABLE_ALIGN         (0x00004000)
#define MMU_TRANSLATION_TABLE_ALIGN_MASK    (~(MMU_TRANSLATION_TABLE_ALIGN - 1))
#define MMU_TRANSLATION_TABLE_ENTRIES       (0x00001000)
#define MMU_TRANSLATION_LINE_SIZE           (sizeof(uint_32))
#define MMU_TRANSLATION_TABLE_SIZE          (MMU_TRANSLATION_TABLE_ENTRIES * MMU_TRANSLATION_LINE_SIZE)


/*-----------------------Memory Configuration-------------------------*/

#define PSP_IRAMBLK1_START  0xf8000000
#define PSP_IRAMBLK1_SIZE   0x20000
#define PSP_IRAMBLK1_END    (PSP_IRAMBLK1_START + PSP_IRAMBLK1_SIZE)

#define PSP_IRAMBLK2_START  0xf8020000
#define PSP_IRAMBLK2_SIZE   0x40000
#define PSP_IRAMBLK2_END    (PSP_IRAMBLK2_START + PSP_IRAMBLK2_SIZE)

#define PSP_FLTT_SIZE       (16*1024)



#ifndef GIC_PRIOR_IMPL
#define GIC_PRIOR_IMPL          (3)   // minimal implemented priority required by cortex core
#endif

#define GIC_PRIOR_SHIFT         (8 - GIC_PRIOR_IMPL)
#define GIC_PRIOR_MASK          ((0xff << GIC_PRIOR_SHIFT) & 0xff)
#define GIC_PRIOR(x)            (((x) << GIC_PRIOR_SHIFT) & GIC_PRIOR_MASK)

#define PSP_INT_FIRST_INTERNAL      0
#define PSP_INT_LAST_INTERNAL       0x3ff

#define PSP_INT_FIRST_INT_ROUTER    48        // A5 core vector 48 == GIC vector 32 -> first vector in interrupt router

#ifndef __ASM__

/*
** Standard cache macros
*/
#define PSP_PAGE_TYPE_MASK                  0x000000ff
#define PSP_PAGE_TYPE_SHIFT                 0
#define PSP_PAGE_TYPE(x)                    ((uint_32)((x << PSP_PAGE_TYPE_SHIFT) & PSP_PAGE_TYPE_MASK))
#define PSP_PAGE_DESCR_MASK                 0x00000f00
#define PSP_PAGE_DESCR_SHIFT                8
#define PSP_PAGE_DESCR(x)                   ((uint_32)((x << PSP_PAGE_DESCR_SHIFT) & PSP_PAGE_DESCR_MASK))
#define PSP_PAGE_SHARE_MASK                 0x0000f000
#define PSP_PAGE_SHARE_SHIFT                12
#define PSP_PAGE_SHARE(x)                   ((uint_32)((x << PSP_PAGE_SHARE_SHIFT) & PSP_PAGE_SHARE_MASK))
#define PSP_PAGE_TABLE_SECTION_SIZE_MASK    0x000f0000
#define PSP_PAGE_TABLE_SECTION_SIZE_SHIFT   16
#define PSP_PAGE_TABLE_SECTION_SIZE(x)      ((uint_32)((x << PSP_PAGE_TABLE_SECTION_SIZE_SHIFT) & PSP_PAGE_TABLE_SECTION_SIZE_MASK))

enum PSP_PAGE_TYPE
{
    PSP_PAGE_TYPE_CACHE_WTNWA,
    PSP_PAGE_TYPE_CACHE_WBNWA,
    PSP_PAGE_TYPE_CACHE_NON,
    PSP_PAGE_TYPE_STRONG_ORDER,
    PSP_PAGE_TYPE_SHAREABLE
};

enum PSP_PAGE_DESCR
{
    PSP_PAGE_DESCR_ACCESS_RW_ALL,
    PSP_PAGE_DESCR_NOACCESS_ALL
};

enum PSP_PAGE_SHARE
{
    PSP_PAGE_SHARE_NON_SHAREABLE,
    PSP_PAGE_SHARE_SHAREABLE
};

enum PSP_PAGE_TABLE_SECTION_SIZE
{
    PSP_PAGE_TABLE_SECTION_SIZE_4KB,
    PSP_PAGE_TABLE_SECTION_SIZE_64KB,
    PSP_PAGE_TABLE_SECTION_SIZE_1MB,
    PSP_PAGE_TABLE_SECTION_SIZE_16MB
};




typedef struct psp_mmu_region_table
   /* This structure is used to hold the MMU page table setup information */
{
   /* Start of the memory region */
   uint_32 START_OF_REGION;

   /* End of the memory region */
   uint_32 REGION_SIZE;

   /* Region page size */
   uint_32 PAGE_SIZE;

   /* Properties of the region */
   uint_32 FLAGS;

} PSP_MMU_REGION_TABLE, _PTR_ PSP_MMU_REGION_TABLE_PTR;


#ifdef __cplusplus
extern "C" {
#endif

/* Generic PSP prototypes */
_mqx_uint _psp_int_init(_mqx_uint, _mqx_uint);
void _psp_int_install(void);

void _a5_initialize_support(void);
/* MMU functions */
void _mmu_vdisable(void);
void _mmu_venable(void);
_mqx_uint _mmu_add_vregion(pointer, pointer, _mem_size, _mqx_uint);
_mqx_uint _mmu_vinit(_mqx_uint, pointer);

uint_32 _psp_core_num(void);


#ifdef __cplusplus
}
#endif

#endif // __ASM__

#endif // __cortexa5_h__
