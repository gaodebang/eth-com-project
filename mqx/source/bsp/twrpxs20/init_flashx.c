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
* $Version : 3.8.2.0$
* $Date    : Oct-7-2011$
*
* Comments:
*
*   This file contains the global generic settings for FLASHX driver.
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"


const FLASHX_FILE_BLOCK _bsp_flashx_file_blocks[] = {
    { "bank0",  0x00000,   0x3FFFF }, /* low address space, 256 KB */
    { "bank1",  0x40000,   0x7FFFF }, /* mid address space, 256 KB */
    { "bank2",  0x80000,   0xFFFFF }, /* high address space, 512 KB */
    { "shadow", 0xF00000, 0xF03FFF }, /* shadow row, 16 KB */
    { NULL , 0, 0 }
};


const FLASHX_INIT_STRUCT _bsp_flashx_init = {
    0x00000000, /* BASE_ADDR should be 0 for internal flashes */
    _mpxs20_block_map, /* HW block map for PXS20 devices */
    _bsp_flashx_file_blocks, /* Files on the device defined by the BSP */
    &_flashx_c90_if, /* Interface for low level driver */
    8,  /* For external devices, data lines for the flash. Not used for internal flash devices. */
    1,  /* Number of parallel external flash devices. Not used for internal flash devices. */
    0,  /* 0 if the write verify is requested, non-zero otherwise */
    NULL /* low level driver specific data */
};
