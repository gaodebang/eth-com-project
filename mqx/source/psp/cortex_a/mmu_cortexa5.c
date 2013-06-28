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
* $FileName: mmu_cortexa5.c$
* $Version : 3.8.7.0$
* $Date    : Sep-4-2012$
*
* Comments:
*
*   This file contains MMU utiltity functions for use with the PPC603
*   CPU.
*
*END************************************************************************/

#include "mqx_inc.h"
#include "mmu_cortexa5.h"

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : super_section_line_fill
* Returned Value  : one line from L1 table
* Comments        :
*   Fill line for table entry 16M
*
*END*---------------------------------------------------------------------*/
static uint_32 super_section_line_fill(uint_32 addr, uint_32 flags)
{
        uint_32 pageline  = 0;

        pageline = addr  & MMU_SUPER_SECTION_SUPER_SECTION_BASE_ADDR_MASK;
        /* set page type for section base addres 1 mega */
        pageline |= (( addr << MMU_SUPER_SECTION_SUPER_SECTION_BASE_ADDR_SHIFT  ) & MMU_SUPER_SECTION_SUPER_SECTION_BASE_ADDR_MASK  ) |
                    (( 2    << MMU_SECTION_ENTRY_TYPE_SHIFT                     ) & MMU_SECTION_ENTRY_TYPE_MASK                     ) |
                    (( 1    << MMU_SUPER_SECTION_TABLE_ENTRY_TYPE_A_SHIFT       ) & MMU_SUPER_SECTION_TABLE_ENTRY_TYPE_A_MASK       ) |
                    /* Page description is Global */
                    (( 0    << MMU_SUPER_SECTION_NG_SHIFT                       ) & MMU_SUPER_SECTION_NG_MASK                       ) |
                    /*Page is Not-shared */
                    (( 0    << MMU_SUPER_SECTION_S_SHIFT                        ) &  MMU_SUPER_SECTION_S_MASK                       ) |
                    /* Page Domain is deprecated */
                    (( 0    << MMU_SUPER_SECTION_DOMAIN_SHIFT                   ) & MMU_SUPER_SECTION_DOMAIN_MASK                   ) |
                    /* Execute Never disabled - this would prevent erroneous execution of data if set */
                    (( 0    << MMU_SUPER_SECTION_XN_SHIFT                       ) & MMU_SUPER_SECTION_XN_MASK                       );

        /** Cache type **/
        /* write-throuth, no write-allocate */
        if ((flags & PSP_PAGE_TYPE_MASK) == PSP_PAGE_TYPE(PSP_PAGE_TYPE_CACHE_WTNWA))
        {
            pageline |= (( 0  <<  MMU_SUPER_SECTION_TEX_SHIFT               ) & MMU_SUPER_SECTION_TEX_MASK  ) |
                        (( 1  <<  MMU_SUPER_SECTION_C_SHIFT                 ) & MMU_SUPER_SECTION_C_MASK    ) |
                        (( 0  <<  MMU_SUPER_SECTION_B_SHIFT                 ) & MMU_SUPER_SECTION_B_MASK    );
        }
        /* write-back, no write-allocate */
        else if ((flags & PSP_PAGE_TYPE_MASK) == PSP_PAGE_TYPE(PSP_PAGE_TYPE_CACHE_WBNWA))
        {
            pageline |= (( 0  <<  MMU_SUPER_SECTION_TEX_SHIFT               ) & MMU_SUPER_SECTION_TEX_MASK  ) |
                        (( 1  <<  MMU_SUPER_SECTION_C_SHIFT                 ) & MMU_SUPER_SECTION_C_MASK    ) |
                        (( 1  <<  MMU_SUPER_SECTION_B_SHIFT                 ) & MMU_SUPER_SECTION_B_MASK    );
        }
        /* non cacheable */
        else if ((flags & PSP_PAGE_TYPE_MASK) == PSP_PAGE_TYPE(PSP_PAGE_TYPE_CACHE_NON))
        {
            pageline |= (( 1  <<  MMU_SUPER_SECTION_TEX_SHIFT               ) & MMU_SUPER_SECTION_TEX_MASK  ) |
                        (( 0  <<  MMU_SUPER_SECTION_C_SHIFT                 ) & MMU_SUPER_SECTION_C_MASK    ) |
                        (( 0  <<  MMU_SUPER_SECTION_B_SHIFT                 ) & MMU_SUPER_SECTION_B_MASK    );
        }
        else if ((flags & PSP_PAGE_TYPE_MASK) == PSP_PAGE_TYPE(PSP_PAGE_TYPE_STRONG_ORDER))
        {
            /* we decided to use strongly ordered memory rule, because we experience that this the only working rule */
            pageline |= (( 0  <<  MMU_SUPER_SECTION_TEX_SHIFT               ) & MMU_SUPER_SECTION_TEX_MASK  ) |
                        (( 0  <<  MMU_SUPER_SECTION_C_SHIFT                 ) & MMU_SUPER_SECTION_C_MASK    ) |
                        (( 0  <<  MMU_SUPER_SECTION_B_SHIFT                 ) & MMU_SUPER_SECTION_B_MASK    );
        }
        /** Shareable bit **/
        if      ((flags & PSP_PAGE_SHARE_MASK) == PSP_PAGE_SHARE(PSP_PAGE_SHARE_SHAREABLE))
        {
            pageline |= ((1 << MMU_SECTION_S_SHIFT) & MMU_SECTION_S_MASK);
        }
        else if ((flags & PSP_PAGE_SHARE_MASK) == PSP_PAGE_SHARE(PSP_PAGE_SHARE_NON_SHAREABLE))
        {
            pageline |= ((0 << MMU_SECTION_S_SHIFT) & MMU_SECTION_S_MASK);
        }
        /** Access controll **/
        if ((flags & PSP_PAGE_DESCR_MASK) == PSP_PAGE_DESCR(PSP_PAGE_DESCR_ACCESS_RW_ALL))
        {
            pageline |= (( 0  <<  MMU_SUPER_SECTION_APX_SHIFT               ) &  MMU_SUPER_SECTION_APX_MASK ) |
                        (( 3  <<  MMU_SUPER_SECTION_AP_SHIFT                ) &  MMU_SUPER_SECTION_AP_MASK  );
        }
        else if ((flags & PSP_PAGE_DESCR_MASK) == PSP_PAGE_DESCR(PSP_PAGE_DESCR_NOACCESS_ALL))
        {
            pageline |= (( 0  <<  MMU_SUPER_SECTION_APX_SHIFT               ) &  MMU_SUPER_SECTION_APX_MASK ) |
                        (( 0  <<  MMU_SUPER_SECTION_AP_SHIFT                ) &  MMU_SUPER_SECTION_AP_MASK  );
        }
        return pageline;
}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : section_line_fill
* Returned Value  : one line from L1 table
* Comments        :
*   Fill line for table entry 1M
*
*END*---------------------------------------------------------------------*/
static uint_32 section_line_fill(uint_32 addr, uint_32 flags)
{
        uint_32 pageline  = 0;

        pageline = addr  & MMU_SECTION_SECTION_BASE_ADDR_MASK;
        /* set page type for section base addres 1 mega */
        pageline |= (( addr << MMU_SECTION_SECTION_BASE_ADDR_SHIFT  ) & MMU_SECTION_SECTION_BASE_ADDR_MASK  ) |
                    (( 2    << MMU_SECTION_ENTRY_TYPE_SHIFT         ) & MMU_SECTION_ENTRY_TYPE_MASK      ) |
                    (( 0    << MMU_SECTION_TABLE_ENTRY_TYPE_A_SHIFT ) & MMU_SECTION_TABLE_ENTRY_TYPE_A_MASK ) |
                    /* Page description is Global */
                    (( 0    << MMU_SECTION_NG_SHIFT                 ) & MMU_SECTION_NG_MASK                 ) |
                    /*Page is Not-shared */
                    (( 0    << MMU_SECTION_S_SHIFT                  ) &  MMU_SECTION_S_MASK                 ) |
                    /* Page Domain is deprecated */
                    (( 0    << MMU_SECTION_DOMAIN_SHIFT             ) & MMU_SECTION_DOMAIN_MASK             ) |
                    /* Execute Never disabled - this would prevent erroneous execution of data if set */
                    (( 0    << MMU_SECTION_XN_SHIFT                 ) & MMU_SECTION_XN_MASK                 );

        /** Cache type **/
        /* write-throuth, no write-allocate */
        if      ((flags & PSP_PAGE_TYPE_MASK) == PSP_PAGE_TYPE(PSP_PAGE_TYPE_CACHE_WTNWA))
        {
            pageline |= (( 0  <<  MMU_SECTION_TEX_SHIFT               ) & MMU_SECTION_TEX_MASK  ) |
                        (( 1  <<  MMU_SECTION_C_SHIFT                 ) & MMU_SECTION_C_MASK    ) |
                        (( 0  <<  MMU_SECTION_B_SHIFT                 ) & MMU_SECTION_B_MASK    );
        }
        /* write-back, no write-allocate */
        else if ((flags & PSP_PAGE_TYPE_MASK) == PSP_PAGE_TYPE(PSP_PAGE_TYPE_CACHE_WBNWA))
        {
            pageline |= (( 0  <<  MMU_SECTION_TEX_SHIFT               ) & MMU_SECTION_TEX_MASK  ) |
                        (( 1  <<  MMU_SECTION_C_SHIFT                 ) & MMU_SECTION_C_MASK    ) |
                        (( 1  <<  MMU_SECTION_B_SHIFT                 ) & MMU_SECTION_B_MASK    );
        }
        /* non cacheable */
        /* we decided to use strongly ordered memory rule, because we experience that this the only working rule */
        else if ((flags & PSP_PAGE_TYPE_MASK) == PSP_PAGE_TYPE(PSP_PAGE_TYPE_CACHE_NON))
        {
            pageline |= (( 1  <<  MMU_SECTION_TEX_SHIFT               ) & MMU_SECTION_TEX_MASK  ) |
                        (( 0  <<  MMU_SECTION_C_SHIFT                 ) & MMU_SECTION_C_MASK    ) |
                        (( 0  <<  MMU_SECTION_B_SHIFT                 ) & MMU_SECTION_B_MASK    );
        }
        /* strong order */
        else if ((flags & PSP_PAGE_TYPE_MASK) == PSP_PAGE_TYPE(PSP_PAGE_TYPE_STRONG_ORDER))
        {
            pageline |= (( 0  <<  MMU_SECTION_TEX_SHIFT               ) & MMU_SECTION_TEX_MASK  ) |
                        (( 0  <<  MMU_SECTION_C_SHIFT                 ) & MMU_SECTION_C_MASK    ) |
                        (( 0  <<  MMU_SECTION_B_SHIFT                 ) & MMU_SECTION_B_MASK    );
        }
        /** Shareable bit **/
        if      ((flags & PSP_PAGE_SHARE_MASK) == PSP_PAGE_SHARE(PSP_PAGE_SHARE_SHAREABLE))
        {
            pageline |= (( 1  <<  MMU_SECTION_S_SHIFT                 ) & MMU_SECTION_S_MASK    );
        }
        else if ((flags & PSP_PAGE_SHARE_MASK) == PSP_PAGE_SHARE(PSP_PAGE_SHARE_NON_SHAREABLE))
        {
            pageline |= (( 0  <<  MMU_SECTION_S_SHIFT                 ) & MMU_SECTION_S_MASK    );
        }
        /** Access controll **/
        if ((flags & PSP_PAGE_DESCR_MASK) == PSP_PAGE_DESCR(PSP_PAGE_DESCR_ACCESS_RW_ALL))
        {
            pageline |= (( 0  <<  MMU_SECTION_APX_SHIFT               ) &  MMU_SECTION_APX_MASK ) |
                        (( 3  <<  MMU_SECTION_AP_SHIFT                ) &  MMU_SECTION_AP_MASK  );
        }
        else if ((flags & PSP_PAGE_DESCR_MASK) == PSP_PAGE_DESCR(PSP_PAGE_DESCR_NOACCESS_ALL))
        {
            pageline |= (( 0  <<  MMU_SECTION_APX_SHIFT               ) &  MMU_SECTION_APX_MASK ) |
                        (( 0  <<  MMU_SECTION_AP_SHIFT                ) &  MMU_SECTION_AP_MASK  );
        }
        return pageline;
}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_vinit
* Returned Value  : MQX_OK or an error code
* Comments        :
*   Initialize the mmu
*
*END*---------------------------------------------------------------------*/
_mqx_uint _mmu_vinit
   (
      /* [IN] initialization flags */
      _mqx_uint default_attribute,

      /* [IN] initialization info */
      pointer   base_ptr
   )
{
    uint_32                 addr = (uint_32)base_ptr;
    uint_32                 DACR  ;/*System Control Register */
    PSP_SUPPORT_STRUCT_PTR  psp_support_ptr = _psp_get_support_ptr();
    uint_32                 k;

    #if MQX_CHECK_ERRORS
    if (psp_support_ptr == NULL)
    {
        return(MQX_COMPONENT_DOES_NOT_EXIST);
    }
    #endif
    /*
    ** We need to set the translation table base register. This register
    ** must be aligned on a 16 Kbyte boundary.
    */
    if (addr & ~MMU_TRANSLATION_TABLE_ALIGN_MASK)
    {
        return MQX_INVALID_PARAMETER;
    }
    psp_support_ptr->PAGE_TABLE_BASE = addr;
    psp_support_ptr->PAGE_TABLE_USED = MMU_TRANSLATION_TABLE_SIZE;
    psp_support_ptr->MMU_DEFAULT_ATTRIBUTE = default_attribute;

    /* A 16MB supersection. This is a special kind of 1MB section entry, which requires 16 entries in the page table. */
    if ((default_attribute & PSP_PAGE_TABLE_SECTION_SIZE_MASK) == PSP_PAGE_TABLE_SECTION_SIZE(PSP_PAGE_TABLE_SECTION_SIZE_16MB))
    {
        for (k = 0; k < MMU_TRANSLATION_TABLE_ENTRIES; k++) /* make  16MB sections*/
        {
            ((uint_32*)addr)[k] = super_section_line_fill((k  << MMU_SECTION_SECTION_BASE_ADDR_SHIFT) & MMU_SUPER_SECTION_SUPER_SECTION_BASE_ADDR_MASK, default_attribute);
        }
    }
    /* A 1MB section translation entry */
    else if ((default_attribute & PSP_PAGE_TABLE_SECTION_SIZE_MASK) == PSP_PAGE_TABLE_SECTION_SIZE(PSP_PAGE_TABLE_SECTION_SIZE_1MB))
    {
        for (k = 0; k < MMU_TRANSLATION_TABLE_ENTRIES; k++) /* make  1MB sections*/
        {
            ((uint_32*)addr)[k] = section_line_fill(k  << MMU_SECTION_SECTION_BASE_ADDR_SHIFT, default_attribute);
        }
    }
    else
    {
        /* unsupported init section size */
        return MQX_INVALID_PARAMETER;
    }
    return MQX_OK;
}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_venable
* Returned Value  : void
* Comments        :
*   Enable the operation of the mmu
*
*END*---------------------------------------------------------------------*/
void _mmu_venable(void)
{
    uint_32 SCTLR  ;/*System Control Register */
    uint_32 DACR   ;
    PSP_SUPPORT_STRUCT_PTR   psp_support_ptr = _psp_get_support_ptr();

    /* write table address to TTBR0*/
    MCR(15, 0, (uint_32)psp_support_ptr->PAGE_TABLE_BASE, 2, 0, 0);

    //DACR = 0xFFFFFFFF; //All inclusive acces
    DACR = 0x55555555; /* set Client mode for all Domains */

    /* write modified DACR*/
    MCR(15, 0, DACR, 3, 0, 0);
    // MCR p15, 0, <Rd>, c3, c0, 0 ; Write DACR

    /* invalidate all tlb */
    MCR(15, 0, 0, 8, 7, 0);
    /*   MCR p15, 0, <Rd>, c8, c7, 0 -- Invalidate entire Unified TLB : TLBIALL*/

    /* read SCTLR */
    MRC(15, 0, SCTLR, 1, 0, 0);
    /* set MMU enable bit */
    SCTLR = SCTLR | 0x1u;

    /* write modified SCTLR*/
    MCR(15, 0, SCTLR, 1, 0, 0);
}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_vdisable
* Returned Value  : void
* Comments        :
*   Disable the operation of the mmu
*
*END*---------------------------------------------------------------------*/
void _mmu_vdisable(void)
{
    uint_32 SCTLR  ;/*System Control Register */

    /* read SCTLR */
    MRC(15, 0, SCTLR, 1, 0, 0);
    /* clear MMU enable bit */
    SCTLR &=~ 0x01u;

    /* write modified SCTLR*/
    MCR(15, 0, SCTLR, 1, 0, 0);
}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_add_vregion
* Returned Value  : MQX_OK or an error code
* Comments        :
*   Initialize the mmu
*
*END*---------------------------------------------------------------------*/
_mqx_uint _mmu_add_vregion
   (
        /* [IN] physical address of region */
        pointer addr,
        /* [IN] virtual address of region */
        pointer vaddr,
        /* [IN] size of region */
        _mem_size size,
        /* [IN] flags for region */
        _mqx_uint flags
   )
{
    uint_32 vindex     = 0;
    uint_32 pindex     = 0;
    _mqx_int i = 0;
    PSP_SUPPORT_STRUCT_PTR   psp_support_ptr = _psp_get_support_ptr();
 #if MQX_CHECK_ERRORS
    if ( psp_support_ptr == NULL )
    {
        return MQX_INVALID_POINTER;
    }
#endif
    /* A 16MB supersection. This is a special kind of 1MB section entry, which requires 16 entries in the page table. */
    if ((flags & PSP_PAGE_TABLE_SECTION_SIZE_MASK) == PSP_PAGE_TABLE_SECTION_SIZE(PSP_PAGE_TABLE_SECTION_SIZE_16MB))
    {
        /* index in L1PageTable */
        vindex = ((uint_32)vaddr >> MMU_SECTION_SECTION_BASE_ADDR_SHIFT);
        pindex = ((uint_32)addr  >> MMU_SECTION_SECTION_BASE_ADDR_SHIFT);

        for (i = (size >> MMU_SECTION_SECTION_BASE_ADDR_SHIFT); i > 0; pindex++, vindex++, i-- )
        {
            ((uint_32 *)psp_support_ptr->PAGE_TABLE_BASE)[vindex] = super_section_line_fill((pindex << MMU_SECTION_SECTION_BASE_ADDR_SHIFT) & MMU_SUPER_SECTION_SUPER_SECTION_BASE_ADDR_MASK, flags);
        }
    }
    /* A 1MB section translation entry */
    else if ((flags & PSP_PAGE_TABLE_SECTION_SIZE_MASK) == PSP_PAGE_TABLE_SECTION_SIZE(PSP_PAGE_TABLE_SECTION_SIZE_1MB))
    {
        /* index in L1PageTable */
        vindex = ((uint_32)vaddr >> MMU_SECTION_SECTION_BASE_ADDR_SHIFT);
        pindex = ((uint_32)addr  >> MMU_SECTION_SECTION_BASE_ADDR_SHIFT);

        for (i = (size >> MMU_SECTION_SECTION_BASE_ADDR_SHIFT); i > 0; pindex++, vindex++, i-- )
        {
            ((uint_32 *)psp_support_ptr->PAGE_TABLE_BASE)[vindex] = section_line_fill(pindex << MMU_SECTION_SECTION_BASE_ADDR_SHIFT, flags);
        }
    }
    else if ((flags & PSP_PAGE_TABLE_SECTION_SIZE_MASK) == PSP_PAGE_TABLE_SECTION_SIZE(PSP_PAGE_TABLE_SECTION_SIZE_64KB))
    {
        /* unsupported init section size */
    }
    else if ((flags & PSP_PAGE_TABLE_SECTION_SIZE_MASK) == PSP_PAGE_TABLE_SECTION_SIZE(PSP_PAGE_TABLE_SECTION_SIZE_4KB))
    {
        /* unsupported init section size */
    }
    else
    {
        /* unsupported init section size */
    }

    /* invalidate all tlb */
    MCR(15, 0, 0, 8, 7, 0);
    /*   MCR p15, 0, <Rd>, c8, c7, 0 -- Invalidate entire Unified TLB : TLBIALL*/
    return(MQX_OK);
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _mmu_vtop
* Returned Value   : MQX_OK or an error code
* Comments         :
*   translate  virtual address to physical address
*
*END*------------------------------------------------------------------------*/
 _mqx_int _mmu_vtop(pointer va, pointer _PTR_ pa)
{
    /* VA to PA translation with privileged read permission check  */
    MCR(15, 0, (uint_32)va & 0xfffffc00, 7, 8, 0);
    /* Read PA register */
    MRC(15, 0, *(uint_32*)pa, 7, 4, 0);
    /* First bit of returned value is Result of conversion(0 is successful translation) */
    if ((uint_32)*pa & 0x01)
    {
        /* We can try write permission also */
        /* VA to PA translation with privileged write permission check  */
        MCR(15, 0, (uint_32)va & 0xfffffc00, 7, 8, 1);
        /* Read PA register */
        MRC(15, 0, *(uint_32*)pa, 7, 4, 0);
        /* First bit of returned value is Result of conversion(0 is successful translation) */
        if ((uint_32)*pa & 0x01)
        {
            return MQX_INVALID_POINTER;
        }
    }
    /* complete address returning base + offset*/
    *pa = (pointer) (((uint_32)*pa & 0xfffff000) | ((uint_32)va & 0x00000fff));
    return MQX_OK;
}
