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
* $FileName: flash_mpxd10.h$
* $Version : 3.8.1.0$
* $Date    : Sep-26-2012$
*
* Comments:
*
*   This file contains the default initialization record for the
*   flash device. The 8313e-rdb uses a Spansion 29lv640 The
*   8323e-rdb uses a Intel Strata 28f128j3.
*
*END************************************************************************/
#ifndef __flash_mpxd10_h__
#define __flash_mpxd10_h__


#include "flashx.h"

#define MPXD10_CFLASH_LAS_SIZE      (256*1024)
#define MPXD10_CFLASH_MAS_SIZE      (256*1024)

#define MPXD10_CFLASH0_SHADOW_SIZE  (16*1024)
#define MPXD10_DFLASH_LAS_SIZE      (64*1024)

#define MPXD10_CFLASH0_LAS_ADDR     (0x000000)
#define MPXD10_CFLASH0_MAS_ADDR     (0x040000)

#define MPXD10_CFLASH1_LAS_ADDR     (0x080000)
#define MPXD10_CFLASH1_MAS_ADDR     (0x0C0000)  
#define MPXD10_CFLASH0_SHADOW_ADDR  (0x200000)

/*----------------------------------------------------------------------*/
/* 
**              DEFINED VARIABLES
*/

extern const FLASHX_BLOCK_INFO_STRUCT _mpxd10_data_flash_block_map[];
extern const FLASHX_BLOCK_INFO_STRUCT _mpxd10_code_flash_block_map[];

extern const FLASHX_DEVICE_IF_STRUCT _flashx_c90i_code_if;

#endif
