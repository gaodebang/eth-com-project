/**HEADER********************************************************************
* 
* Copyright (c) 2011 Freescale Semiconductor;
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
* $FileName: timer_mtim16.h$
* $Version : 3.8.1.0$
* $Date    : Sep-21-2011$
*
* Comments:
*
*   This file contains definitions for the 16-bit MTIM functions.
*
*END************************************************************************/

#ifndef __timer_mtim16_h__
#define __timer_mtim16_h__

#include <mqx.h>
#include <bsp.h>

#ifdef __cplusplus
extern "C" {
#endif

/*-----------------------------------------------------------------------*/
/*                      FUNCTION PROTOTYPES
*/

pointer _bsp_get_mtim16_base_address (uint_8);
_mqx_uint _bsp_get_mtim16_vector(uint_8);
void _bsp_mtim16_clk_en (uint_8);

_mqx_int _mtim16_timer_install(uint_8, uint_32, uint_32, uint_32, INT_ISR_FPTR, boolean);
_mqx_int _mtim16_timer_install_kernel(uint_8, uint_32, uint_32, uint_32, boolean);
uint_32 _mtim16_timer_init(uint_8, uint_32, uint_32, boolean);

uint_32 _mtim16_get_hwticks(pointer);

void _mtim16_mask_int(uint_8);
void _mtim16_unmask_int(uint_8);
void _mtim16_clear_int(uint_8);


#ifdef __cplusplus
}
#endif

#endif
