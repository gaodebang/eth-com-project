/**HEADER*********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
* All Rights Reserved
*
******************************************************************************
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
******************************************************************************
*
* $FileName: mcf51jf.h$
* $Version : 3.8.3.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains the type definitions for the mcf51jf microcontroller.
*
*END*************************************************************************/

#ifndef __mcf51jf_h__
#define __mcf51jf_h__



/*
** PSP common definitions
*/
#define PSP_HAS_DSP                         0
#define PSP_HAS_EMAC                        0
#define PSP_HAS_MMU                         0
#define PSP_HAS_CODE_CACHE                  0
#define PSP_HAS_DATA_CACHE                  0
#define PSP_CACHE_LINE_SIZE                 (0x10)

#define PSP_STOP_ON_IDLE                    0

/*
/** Test for disable cpu wait mode macro.
*/
#if PSP_STOP_ON_IDLE
    #warning "With PSP_STOP_ON_IDLE and no idle_task USB doesn't recover from wait mode"
#endif

#ifndef __ASM__

/* Include mcu specific header file */
#if     MQX_CPU == PSP_CPU_MCF51JF128
    #include "mcf51jf128.h"
#endif

/* Do you want to verify kernel data can be read and written correctly */
#define PSP_KERNEL_DATA_VERIFY_ENABLE       ((uint_32)__KERNEL_DATA_VERIFY_ENABLE)

/*
** Standard cache macros
*/
#define _DCACHE_FLUSH()
#define _DCACHE_FLUSH_LINE(p)
#define _DCACHE_FLUSH_MBYTES(p, m)
#define _DCACHE_INVALIDATE()
#define _DCACHE_INVALIDATE_LINE(p)
#define _DCACHE_INVALIDATE_MBYTES(p, m)

#define _CACHE_ENABLE(n)
#define _CACHE_DISABLE()

#define _ICACHE_INVALIDATE()
#define _ICACHE_INVALIDATE_LINE(p)
#define _ICACHE_INVALIDATE_MBYTES(p, m)

/*
** The PSP_SUPPORT_STRUCT structure is used to maintain the PSP support information
*/
typedef struct psp_support_struct
{
    uint_32 RESERVED;

} PSP_SUPPORT_STRUCT, _PTR_ PSP_SUPPORT_STRUCT_PTR;

/*
**  FUNCTION PROTOTYPES AND GLOBAL EXTERNS
*/

#ifdef __cplusplus
extern "C" {
#endif

extern  uchar   __KERNEL_DATA_VERIFY_ENABLE[];

void _mcf51xx_initialize_support
    (
        /* [IN] dummy parameter */
        uint_32 param
    );

#ifdef __cplusplus
}
#endif

#endif /*__ASM__ */

#endif /* __mcf51jf_h__ */
/* EOF */
