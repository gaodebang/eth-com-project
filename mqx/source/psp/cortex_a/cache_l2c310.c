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
* $FileName: cache_l2c310.c$
* $Version : 3.8.5.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This file contains functions for use with the l2c-310 cache controller.
*   This controller can work only with physical adresses.
*
*
*END************************************************************************/
#include "mqx_inc.h"
/* Function _mmu_vtop is used for translation from virtual to physical address */
 _mqx_int _mmu_vtop(pointer va, pointer _PTR_ pa);

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _l2c310_cache_enable
* Returned Value   : none
* Comments         :
*   This function enables data cache at any available cache level.
*   Works only if MMU is enabled!
*
*END*----------------------------------------------------------------------*/
void _l2c310_cache_enable(void)
{
    /* this cache is common for Data and Instruction we should avoid invalidating if cache is already turned on*/
    if (!(CA5L2C_reg1_control & L2C_reg1_control_L2_Cache_enable_MASK))
    {
      /* we should invalidate entire cache before enabling :Initializaion sequence in L2C-310 r3p2 Technical Reference Manual*/
        CA5L2C_reg7_inv_way |= L2C_reg7_inv_way_Way_MASK;
        while (CA5L2C_reg7_cache_sync & L2C_reg7_cache_sync_C_MASK);

        CA5L2C_reg1_control |= L2C_reg1_control_L2_Cache_enable_MASK;
        /* Drain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are emptyDrain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are empty */
        while (CA5L2C_reg7_cache_sync & L2C_reg7_cache_sync_C_MASK);
    }
}
    /*FUNCTION*-------------------------------------------------------------------
* Function Name    : _l2c310_cache_disable
* Returned Value   : none
* Comments         :
*   This function disables the data cache at any available cache level.
*
*END*----------------------------------------------------------------------*/
void _l2c310_cache_disable(void)
{
    CA5L2C_reg1_control &= ~L2C_reg1_control_L2_Cache_enable_MASK;
    /* Drain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are emptyDrain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are empty */
    while (CA5L2C_reg7_cache_sync & L2C_reg7_cache_sync_C_MASK);
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _l2c310_cache_invalidate
* Returned Value   : none
* Comments         :
*   This function invalidates the entire data cache
*
*END*----------------------------------------------------------------------*/
void _l2c310_cache_invalidate(void)
{
    CA5L2C_reg7_inv_way |= L2C_reg7_inv_way_Way_MASK;
    while (CA5L2C_reg7_cache_sync & L2C_reg7_cache_sync_C_MASK);
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _l2c310_cache_invalidate_line
* Comments         :
*    This function is called to invalidate a line of data cache.
*
*END*------------------------------------------------------------------------*/
void _l2c310_cache_invalidate_line(pointer addr)
{
    /* addr parameter can be virtual address and this cache work only with physical address */
    pointer pa = NULL; /* physical address pointer */
    if (_mmu_vtop(addr, &pa) == MQX_OK)
    {
        CA5L2C_reg7_inv_pa = (uint_32)pa & (L2C_reg7_clean_pa_Index_MASK | L2C_reg7_clean_pa_Tag_MASK);
        /* Drain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are emptyDrain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are empty */
        while (CA5L2C_reg7_cache_sync & L2C_reg7_cache_sync_C_MASK);
    }
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _l2c310_cache_invalidate_mlines
* Returned Value   : none
* Comments         :
*
*   This function is called to invalidate number of lines of data cache.
*   Number of lines depends on length parameter and size of line.
*   Size of line for A5 L2 cache is 32B.
*
*END*-----------------------------------------------------------------------*/
void _l2c310_cache_invalidate_mlines(pointer addr, _mem_size length)
{
    /* addr parameter can be virtual address and this cache work only with physical address */
    pointer pa = NULL; /* physical address pointer */
    pointer end_addr = (pointer)((uint_32)addr + length);
    addr = (pointer) ((uint_32)addr & ~(PSP_CACHE_LINE_SIZE - 1));    
    do
    {
        if (_mmu_vtop(addr, &pa) == MQX_OK)
        {
            CA5L2C_reg7_inv_pa = (uint_32)pa & (L2C_reg7_clean_pa_Index_MASK | L2C_reg7_clean_pa_Tag_MASK);
            addr = (pointer) ((uint_32)addr + PSP_CACHE_LINE_SIZE);
            /* Drain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are emptyDrain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are empty */
            while (CA5L2C_reg7_cache_sync & L2C_reg7_cache_sync_C_MASK);
        }
        else
        {
            addr = (pointer) ((uint_32)addr + PSP_CACHE_LINE_SIZE);
        }
    } while (addr < end_addr);
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _l2c310_cache_flush
* Returned Value   : none
* Comments         :
*   This function FLUSH (CLEAN) all lines of cachce (all sets in all ways)
*   Size of line for A5 L2 cache is 32B.
*
*END*----------------------------------------------------------------------*/
void _l2c310_cache_flush(void)
{
    //read count of ways and clean only them
    CA5L2C_reg7_clean_way |= L2C_reg7_clean_way_Way_MASK;
    /* Drain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are emptyDrain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are empty */
    while (CA5L2C_reg7_cache_sync & L2C_reg7_cache_sync_C_MASK);
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _l2c310_cache_flush_line
* Comments         :
*   This function FLUSH (CLEAN)  line of cachce.
*   Size of line for A5 L2 cache is 32B.
*
*END*------------------------------------------------------------------------*/
void _l2c310_cache_flush_line(pointer addr)
{
    /* addr parameter can be virtual address and this cache work only with physical address */
    pointer pa = NULL; /* physical address pointer */
    if (_mmu_vtop(addr, &pa) == MQX_OK)
    {
        CA5L2C_reg7_clean_pa = (uint_32)pa & (L2C_reg7_clean_pa_Index_MASK | L2C_reg7_clean_pa_Tag_MASK);
        /* Drain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are emptyDrain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are empty */
        while (CA5L2C_reg7_cache_sync & L2C_reg7_cache_sync_C_MASK);
    }
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _l2c310_cache_flush_mlines
* Returned Value   : none
* Comments         :
*
*   This function is called to flush number of lines of data cache.
*   Number of lines depends on length parameter and size of line.
*   Size of line for A5 L2 cache is 32B.
*
*END*-----------------------------------------------------------------------*/
void _l2c310_cache_flush_mlines(pointer addr, _mem_size length)
{
    /* addr parameter can be virtual address and this cache work only with physical address */
    pointer pa = NULL; /* physical address pointer */
    pointer end_addr = (pointer)((uint_32)addr + length);
    addr = (pointer) ((uint_32)addr & ~(PSP_CACHE_LINE_SIZE - 1));    
    do
    {
        if (_mmu_vtop(addr, &pa) == MQX_OK)
        {
            CA5L2C_reg7_clean_pa = (uint_32)pa & (L2C_reg7_clean_pa_Index_MASK | L2C_reg7_clean_pa_Tag_MASK);
            addr = (pointer) ((uint_32)addr + PSP_CACHE_LINE_SIZE);
            /* Drain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are emptyDrain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are empty */
            while (CA5L2C_reg7_cache_sync & L2C_reg7_cache_sync_C_MASK);
        }
        else
        {
            addr = (pointer) ((uint_32)addr + PSP_CACHE_LINE_SIZE);
        }
    } while (addr < end_addr);
}
