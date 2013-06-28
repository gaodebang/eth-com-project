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
* $FileName: cache_a5.c$
* $Version : 3.8.4.0$
* $Date    : Aug-29-2012$
*
* Comments:
*
*   This file contains functions for use with the cortex  a5 caches.
*   Funcionality of L1 cache is accessible on by special instructions mcr - for write and mrc for read.
*
*
*END************************************************************************/
#include "mqx_inc.h"

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_dcache_enable
* Returned Value   : none
* Comments         :
*   This function enables data cache at any available cache level.
*   Works only if MMU is enabled!
*
*END*----------------------------------------------------------------------*/
void _a5_dcache_enable(void)
{
    uint_32 sctlr;/* System Control Register */
    /* read sctlr */
    MRC(15, 0, sctlr, 1, 0, 0);

    /* set  C bit (data caching enable) */
    sctlr |= 0x1 << 2;

    /* write modified sctlr*/
    MCR(15, 0, sctlr, 1, 0, 0);
    /* All Cache, Branch predictor and TLB maintenance operations before followed instruction complete*/
    DSB();
}

/*FUNCTION*-------------------------------------------------------------------
* Function Name    : _a5_dcache_disable
* Returned Value   : none
* Comments         :
*   This function disables the data cache at any available cache level.
*
*END*----------------------------------------------------------------------*/
void _a5_dcache_disable(void)
{
    uint_32 sctlr;/* System Control Register */
    /* read sctlr */
    MRC(15, 0, sctlr, 1, 0, 0);
    /* set  C bit (data caching enable) */
    sctlr &= ~(0x1 << 2);

    /* write modified sctlr*/
    MCR(15, 0, sctlr, 1, 0, 0);
    /* All Cache, Branch predictor and TLB maintenance operations before followed instruction complete*/
    DSB();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_dcache_invalidate
* Returned Value   : none
* Comments         :
*   This function invalidates the entire data cache
*
*END*----------------------------------------------------------------------*/
void _a5_dcache_invalidate(void)
{
    uint_32 csid, wayset;  /* Cache Size ID , wayset parameter */
    int_32 num_sets, num_ways; /* number of sets  */

    MRC(15, 1, csid, 0, 0, 0);    /* Read Cache Size ID */
    /* Fill number of sets  and number of ways from csid register  This walues are decremented by 1*/
    num_ways = (csid >> 0x03) & 0x3FFu; //((csid& csid_ASSOCIATIVITY_MASK) >> csid_ASSOCIATIVITY_SHIFT`)
    /* Invalidation all lines (all Sets in all ways) */
    while (num_ways >= 0)
    {
        num_sets = (csid >> 0x13) & 0x7FFFu; //((csid & csid_NUMSETS_MASK)      >> csid_NUMSETS_SHIFT       )
        while (num_sets >= 0 )
        {
            wayset = (num_sets << 5u) | (num_ways << 30u); //(num_sets << SETWAY_SET_SHIFT) | (num_sets << 3SETWAY_WAY_SHIFT)
            /* invalidate line if we know set and way */
            MCR(15, 0, wayset, 7, 6, 2);
            num_sets--;
        }
        num_ways--;
    }
    /* All Cache, Branch predictor and TLB maintenance operations before followed instruction complete*/
    DSB();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_dcache_invalidate_line
* Comments         :
*    This function is called to invalidate a line of data cache.
*
*END*------------------------------------------------------------------------*/
void _a5_dcache_invalidate_line(pointer addr)
{
    uint_32 va;
    va = (uint_32) addr & 0xfffffff0; //addr & va_VIRTUAL_ADDRESS_MASK
    /* Invalidate data cache line by va to PoC (Point of Coherency). */
    MCR(15, 0, va, 7, 6, 1);
    /* All Cache, Branch predictor and TLB maintenance operations before followed instruction complete*/
    DSB();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_dcache_invalidate_mlines
* Returned Value   : none
* Comments         :
*
*   This function is called to invalidate number of lines of data cache.
*   Number of lines depends on length parameter and size of line.
*   Size of line for A5 L1 cache is 32B.
*
*END*-----------------------------------------------------------------------*/
void _a5_dcache_invalidate_mlines(pointer addr, _mem_size length)
{
    uint_32 va;
    pointer end_addr = (pointer)((uint_32)addr + length);
    addr = (pointer) ((uint_32)addr & ~(PSP_CACHE_LINE_SIZE - 1));    
    do
    {
        /* Clean data cache line to PoC (Point of Coherence) by va. */
        va = (uint_32) ((uint_32)addr & 0xfffffff0); //addr & va_VIRTUAL_ADDRESS_MASK
        MCR(15, 0, va, 7, 6, 1);
        /* increment addres to next line and decrement lenght */
        addr = (pointer) ((uint_32)addr + PSP_CACHE_LINE_SIZE);
    } while (addr < end_addr);
    /* All Cache, Branch predictor and TLB maintenance operations before followed instruction complete*/
    DSB();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_dcache_flush
* Returned Value   : none
* Comments         :
*   This function FLUSH (CLEAN) all lines of cachce (all sets in all ways)
*   Size of line for A5 L1 cache is 32B.
*
*END*----------------------------------------------------------------------*/
void _a5_dcache_flush(void)
{
    uint_32 csid, wayset;  /* Cache Size ID */
    int_32 num_sets, num_ways; /* number of sets  */

    MRC(15, 1, csid, 0, 0, 0);    /* Read Cache Size ID */
    /* Fill number of sets  and number of ways from csid register  This walues are decremented by 1*/
    num_ways = (csid >> 0x03) & 0x3FFu;
    while (num_ways >= 0)
    {
        num_sets = (csid >> 0x13) & 0x7FFFu;
        while (num_sets >= 0 )
        {
            wayset = (num_sets << 5u) | (num_ways << 30u);
            /* FLUSH (clean) line if we know set and way */
            MCR(15, 0, wayset, 7, 10, 2);
            num_sets--;
        }
        num_ways--;
    }
    /* All Cache, Branch predictor and TLB maintenance operations before followed instruction complete*/
    DSB();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_dcache_flush_line
* Comments         :
*   This function FLUSH (CLEAN)  line of cachce.
*   Size of line for A5 L1 cache is 32B.
*
*END*------------------------------------------------------------------------*/
void _a5_dcache_flush_line(pointer addr)
{
    uint_32 va;
    va = (uint_32) addr & 0xfffffff0; //addr & va_VIRTUAL_ADDRESS_MASK
    /* Clean data cache line to PoC (Point of Coherence) by va. */
    MCR(15, 0, va, 7, 10, 1);
    /* All Cache, Branch predictor and TLB maintenance operations before followed instruction complete*/
    DSB();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_dcache_flush_mlines
* Returned Value   : none
* Comments         :
*
*   This function is called to flush number of lines of data cache.
*   Number of lines depends on length parameter and size of line.
*   Size of line for A5 L1 cache is 32B.
*
*END*-----------------------------------------------------------------------*/
void _a5_dcache_flush_mlines(pointer addr, _mem_size length)
{
    uint_32 va;
    pointer end_addr = (pointer)((uint_32)addr + length);
    addr = (pointer) ((uint_32)addr & ~(PSP_CACHE_LINE_SIZE - 1));    
    do
    {
        /* Clean data cache line to PoC (Point of Coherence) by va. */
        va = (uint_32) ((uint_32)addr & 0xfffffff0); //addr & va_VIRTUAL_ADDRESS_MASK
        MCR(15, 0, va, 7, 10, 1);
        /* increment addres to next line and decrement lenght */
        addr = (pointer) ((uint_32)addr + PSP_CACHE_LINE_SIZE);
    } while (addr < end_addr);
    /* All Cache, Branch predictor and TLB maintenance operations before followed instruction complete*/
    DSB();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_icache_enable
* Returned Value   : none
* Comments         :
*   This function enables instruction cache at any available cache level.
*   Works without enabled MMU too!
*
*END*----------------------------------------------------------------------*/
void _a5_icache_enable(void)
{
    uint_32 sctlr  ;/*System Control Register */
    /* read sctlr */
    MRC(15, 0, sctlr, 1, 0, 0);
    /* set  I bit (instruction caching enable) */
    sctlr |= 0x1 << 12;

    /* write modified sctlr*/
    MCR(15, 0, sctlr, 1, 0, 0);
    /* synchronize context on this processor */
    ISB();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_icache_disable
* Returned Value   : none
* Comments         :
*   This function disables the Invalidate cache at any available cache level.
*
*END*----------------------------------------------------------------------*/
void _a5_icache_disable(void)
{
    uint_32 sctlr  ;/*System Control Register */
    /* read sctlr */
    MRC(15, 0, sctlr, 1, 0, 0);
    /* Clear  I bit (instruction caching enable) */
    sctlr &= ~(0x1 << 12);

    /* write modified sctlr*/
    MCR(15, 0, sctlr, 1, 0, 0);
    /* synchronize context on this processor */
    ISB();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_icache_invalidate
* Returned Value   : none
* Comments         :
*   This function invalidate entyre of the data cache
*
*END*----------------------------------------------------------------------*/
void _a5_icache_invalidate(void)
{
    uint_32 SBZ;
    SBZ = 0x0u;
    MCR(15, 0, SBZ, 7, 5, 0);
    /* synchronize context on this processor */
    ISB();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_icache_invalidate_line
* Comments         :
*   This function is called to invalidate a line.
*
*END*------------------------------------------------------------------------*/
void _a5_icache_invalidate_line(pointer addr)
{
    uint_32 va;
    va = (uint_32) addr & 0xfffffff0;
    /* Invalidate instruction cache by va to PoU (Point of unification). */
    MCR(15, 0, va, 7, 5, 1);
    /* synchronize context on this processor */
    ISB();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _a5_icache_invalidate_mlines
* Comments         :
*
*   This function is called to invalidate number of lines of data cache.
*   Number of lines depends on length parameter and size of line.
*   Size of line for A5 L1 cache is 32B.
*
*END*----------------------------------------------------------------------*/
void _a5_icache_invalidate_mlines(pointer addr, _mem_size length)
{
    uint_32 va;
    pointer end_addr = (pointer)((uint_32)addr + length);
    addr = (pointer) ((uint_32)addr & ~(PSP_CACHE_LINE_SIZE - 1));    
    do
    {
        /* Clean data cache line to PoC (Point of Coherence) by va. */
        va = (uint_32) ((uint_32)addr & 0xfffffff0);
        MCR(15, 0, va, 7, 5, 1);
        /* increment addres to next line and decrement lenght */
        addr = (pointer) ((uint_32)addr + PSP_CACHE_LINE_SIZE);
    } while (addr < end_addr);
    /* synchronize context on this processor */
    ISB();
}

