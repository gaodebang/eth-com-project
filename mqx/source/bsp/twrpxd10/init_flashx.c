/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
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
* $FileName: init_flashx.c$
* $Version : 3.8.1.0$
* $Date    : Sep-26-2012$
*
* Comments:
*
*   This file contains the global generic settings for FLASHX driver.
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "flash_c90i.h"


const FLASHX_FILE_BLOCK _bsp_data_flashx_file_blocks[] = {
    { "bank0",  MPXD10_DFLASH_MEM_BASE,   MPXD10_DFLASH_MEM_BASE+MPXD10_DFLASH_LAS_SIZE-1 }, /* low address space, 64 KB */
    { NULL , 0, 0 }
};

const FLASHX_FILE_BLOCK _bsp_code_flashx_file_blocks[] = {
    { "bank0",  MPXD10_CFLASH0_LAS_ADDR,                        MPXD10_CFLASH0_LAS_ADDR + MPXD10_CFLASH_LAS_SIZE-1 },   /* low address space */
    { "bank1",  MPXD10_CFLASH0_MAS_ADDR,                        MPXD10_CFLASH0_MAS_ADDR + MPXD10_CFLASH_MAS_SIZE-1 },   /* mis address space */    
    { "bank2",  MPXD10_CFLASH1_LAS_ADDR,                        MPXD10_CFLASH1_LAS_ADDR + MPXD10_CFLASH_LAS_SIZE-1 },   /* low address space */
    { "bank3",  MPXD10_CFLASH1_MAS_ADDR,                        MPXD10_CFLASH1_MAS_ADDR + MPXD10_CFLASH_MAS_SIZE-1 },   /* mis address space */
  { NULL , 0, 0 }
};


const FLASHX_INIT_STRUCT _bsp_data_flashx_init = {
    MPXD10_DFLASH_MEM_BASE,         /* BASE_ADDR                                                                            */
    _mpxd10_data_flash_block_map,   /* HW block map for PXD10 devices                                                       */
    _bsp_data_flashx_file_blocks,   /* Files on the device defined by the BSP                                               */
    &_flashx_c90_if,                /* Interface for low level driver                                                       */
    8,                              /* For external devices, data lines for the flash. Not used for internal flash devices. */
    1,                              /* Number of parallel external flash devices. Not used for internal flash devices.      */
    0,                              /* 0 if the write verify is requested, non-zero otherwise                               */
    NULL                            /* low level driver specific data                                                       */
};

const FLASHX_INIT_STRUCT _bsp_code_flashx_init = {
    MPXD10_CFLASH0_MEM_BASE,        /* BASE_ADDR                                                                            */
    _mpxd10_code_flash_block_map,   /* HW block map for PXD10 devices                                                       */
    _bsp_code_flashx_file_blocks,   /* Files on the device defined by the BSP                                               */
    &_flashx_c90i_if,               /* Interface for low level driver                                                       */
    8,                              /* For external devices, data lines for the flash. Not used for internal flash devices. */
    1,                              /* Number of parallel external flash devices. Not used for internal flash devices.      */
    0,                              /* 0 if the write verify is requested, non-zero otherwise                               */
    NULL                            /* low level driver specific data                                                       */
};
