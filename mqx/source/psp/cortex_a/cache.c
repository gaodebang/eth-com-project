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
* $FileName: cache.c$
* $Version : 3.8.4.0$
* $Date    : Sep-27-2012$
*
* Comments:
*
*   This file contains functions for use with the cortex  vybrid caches.
*   Funcionality of L1 cache is accessible on by special instructions mcr - for write and mrc for read.
*
*
*END************************************************************************/
#include "mqx_inc.h"

/* vybrid platforms can be consist of L1 core cache and L2 cache (l2c310 cache controller) */
#if     PSP_HAS_L1_CACHE
/* PSP A5 Cache prototypes */
void _a5_dcache_enable(void);
void _a5_dcache_disable(void);
void _a5_dcache_flush(void);
void _a5_dcache_flush_line(pointer);
void _a5_dcache_flush_mlines(pointer, uint_32);
void _a5_dcache_invalidate(void);
void _a5_dcache_invalidate_line(pointer);
void _a5_dcache_invalidate_mlines(pointer, uint_32);

void _a5_icache_enable(void);
void _a5_icache_disable(void);
void _a5_icache_invalidate(void);
void _a5_icache_invalidate_line(pointer);
void _a5_icache_invalidate_mlines(pointer, uint_32);
#endif
#if     PSP_HAS_L2_CACHE
/* PSP L2C-310 Cache prototypes */
void _l2c310_cache_enable(void);
void _l2c310_cache_disable(void);
void _l2c310_cache_flush(void);
void _l2c310_cache_flush_line(pointer);
void _l2c310_cache_flush_mlines(pointer, uint_32);
void _l2c310_cache_invalidate(void);
void _l2c310_cache_invalidate_line(pointer);
void _l2c310_cache_invalidate_mlines(pointer, uint_32);

void _l2c310_cache_enable(void);
void _l2c310_cache_disable(void);
void _l2c310_cache_invalidate(void);
void _l2c310_cache_invalidate_line(pointer);
void _l2c310_cache_invalidate_mlines(pointer, uint_32);
#endif

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _dcache_enable
* Returned Value   : none
* Comments         :
*   This function enables data cache at any available cache level.
*   Works only if MMU is enabled!
*
*END*----------------------------------------------------------------------*/
void _dcache_enable(void)
{
#if PSP_HAS_L1_CACHE
	_a5_dcache_enable();
#endif

#if PSP_HAS_L2_CACHE
	_l2c310_cache_enable();
#endif
}

/*FUNCTION*-------------------------------------------------------------------
* Function Name    : _dcache_disable
* Returned Value   : none
* Comments         :
*   This function disables the data cache at any available cache level.
*
*END*----------------------------------------------------------------------*/
void _dcache_disable(void)
{
#if PSP_HAS_L1_CACHE
    _a5_dcache_flush();
    _a5_dcache_disable();
#endif

#if PSP_HAS_L2_CACHE
    _l2c310_cache_flush();
    _l2c310_cache_disable();
#endif
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _dcache_invalidate
* Returned Value   : none
* Comments         :
*   This function invalidates the entire data cache
*
*END*----------------------------------------------------------------------*/
void _dcache_invalidate(void)
{
#if PSP_HAS_L2_CACHE
    _l2c310_cache_invalidate();
#endif

#if PSP_HAS_L1_CACHE
    _a5_dcache_invalidate();
#endif
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _dcache_invalidate_line
* Comments         :
*    This function is called to invalidate a line of data cache.
*
*END*------------------------------------------------------------------------*/
void _dcache_invalidate_line(pointer addr)
{
#if PSP_HAS_L2_CACHE
    _l2c310_cache_invalidate_line(addr);
#endif

#if PSP_HAS_L1_CACHE
    _a5_dcache_invalidate_line(addr);
#endif
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _dcache_invalidate_mlines
* Returned Value   : none
* Comments         :
*
*   This function is called to invalidate number of lines of data cache.
*   Number of lines depends on length parameter and size of line.
*   Size of line for vybrid L1 cache is 32B.
*
*END*-----------------------------------------------------------------------*/
void _dcache_invalidate_mlines(pointer addr, _mem_size length)
{
#if PSP_HAS_L2_CACHE
    _l2c310_cache_invalidate_mlines(addr, length);
#endif

#if PSP_HAS_L1_CACHE
    _a5_dcache_invalidate_mlines(addr, length);
#endif
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _dcache_flush
* Returned Value   : none
* Comments         :
*   This function FLUSH (CLEAN) all lines of cachce (all sets in all ways)
*   Size of line for vybrid L1 cache is 32B.
*
*END*----------------------------------------------------------------------*/
void _dcache_flush(void)
{
#if PSP_HAS_L1_CACHE
    _a5_dcache_flush();
#endif

#if PSP_HAS_L2_CACHE
    _l2c310_cache_flush();
#endif
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _dcache_flush_line
* Comments         :
*   This function FLUSH (CLEAN)  line of cachce.
*   Size of line for vybrid L1 cache is 32B.
*
*END*------------------------------------------------------------------------*/
void _dcache_flush_line(pointer addr)
{
#if PSP_HAS_L1_CACHE
    _a5_dcache_flush_line(addr);
#endif

#if PSP_HAS_L2_CACHE
    _l2c310_cache_flush_line(addr);
#endif
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _dcache_flush_mlines
* Returned Value   : none
* Comments         :
*
*   This function is called to flush number of lines of data cache.
*   Number of lines depends on length parameter and size of line.
*   Size of line for vybrid L1 cache is 32B.
*
*END*-----------------------------------------------------------------------*/
void _dcache_flush_mlines(pointer addr, _mem_size length)
{
#if PSP_HAS_L1_CACHE
    _a5_dcache_flush_mlines(addr, length);
#endif

#if PSP_HAS_L2_CACHE
    _l2c310_cache_flush_mlines(addr, length);
#endif
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _icache_enable
* Returned Value   : none
* Comments         :
*   This function enables instruction cache at any available cache level.
*   Works without enabled MMU too!
*
*END*----------------------------------------------------------------------*/
void _icache_enable(void)
{
#if PSP_HAS_L1_CACHE
    _a5_icache_enable();
#endif

#if PSP_HAS_L2_CACHE
    _l2c310_cache_enable();
#endif
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _icache_disable
* Returned Value   : none
* Comments         :
*   This function disables the Invalidate cache at any available cache level.
*
*END*----------------------------------------------------------------------*/
void _icache_disable(void)
{
#if PSP_HAS_L1_CACHE
    _a5_icache_disable();
#endif
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _icache_invalidate
* Returned Value   : none
* Comments         :
*   This function invalidate entyre of the data cache
*
*END*----------------------------------------------------------------------*/
void _icache_invalidate(void)
{
#if PSP_HAS_L2_CACHE
    _l2c310_cache_invalidate();
#endif

#if PSP_HAS_L1_CACHE
    _a5_icache_invalidate();
#endif
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _icache_invalidate_line
* Comments         :
*   This function is called to invalidate a line.
*
*END*------------------------------------------------------------------------*/
void _icache_invalidate_line(pointer addr)
{
#if PSP_HAS_L2_CACHE
    _l2c310_cache_invalidate_line(addr);
#endif

#if PSP_HAS_L1_CACHE
    _a5_icache_invalidate_line(addr);
#endif
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _icache_invalidate_mlines
* Comments         :
*
*   This function is called to invalidate number of lines of data cache.
*   Number of lines depends on length parameter and size of line.
*   Size of line for vybrid L1 cache is 32B.
*
*END*----------------------------------------------------------------------*/
void _icache_invalidate_mlines(pointer addr, _mem_size length)
{
#if PSP_HAS_L2_CACHE
    _l2c310_cache_invalidate_mlines(addr, length);
#endif

#if PSP_HAS_L1_CACHE
    _a5_icache_invalidate_mlines(addr, length);
#endif
}
