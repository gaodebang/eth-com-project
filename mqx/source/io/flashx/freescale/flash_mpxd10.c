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
* $FileName: flash_mpxd10.c$
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

#include "mqx.h"
#include "bsp.h"
#include "flashx.h"
#include "flash_c90.h"
#include "flash_c90_prv.h"
#include "flash_c90i_prv.h"

#define K1      (1024)
#define K16     (16*K1)
#define K32     (32*K1)
#define K64     (64*K1)
#define K128    (128*K1)
#define K256    (256*K1)
#define K512    (512*K1)

const FLASHX_BLOCK_INFO_STRUCT _mpxd10_data_flash_block_map[] =
{
    /* count, address, size */

    /* LAS */
    { 4, 0,  K16,  C90_ASPACE_LAS|C90_CONTROLLER_0|C90_WIDTH_64|C90_ALIGN_32 }, /* D0 L0..L3 4*16 KB */
    /* MAS */
    /* HAS - not available on TWRPXD10's Data Flash */

    /* Shadow row - - not available on TWRPXD10 */

    { 0, 0, 0 }
};

const FLASHX_BLOCK_INFO_STRUCT _mpxd10_code_flash_block_map[] =
{
    /* count, address, size */

    /* LAS */
    { 1,  0,                                                K32,  C90_ASPACE_LAS|C90_CONTROLLER_0|C90_WIDTH_64 }, /* C0 L0     1*32 KB */
    { 2,  K32,                                              K16,  C90_ASPACE_LAS|C90_CONTROLLER_0|C90_WIDTH_64 }, /* C0 L1..L2 2*16 KB */
    { 2,  K32+2*K16,                                        K32,  C90_ASPACE_LAS|C90_CONTROLLER_0|C90_WIDTH_64 }, /* C0 L3..L4 2*32 KB */
    { 1,  K64+2*K32,                                        K128,  C90_ASPACE_LAS|C90_CONTROLLER_0|C90_WIDTH_64 }, /* C0 L5    1*128 KB */
    /* MAS Module 0*/  
    { 2,  K128+K128,                                        K128,  C90_ASPACE_MAS|C90_CONTROLLER_0|C90_WIDTH_64 }, /* C0 L6..L7 2*128 KB */
    /* LAS Module 1*/    
    { 2,  K256+2*K128,                                      K128,  C90_ASPACE_LAS|C90_CONTROLLER_1|C90_WIDTH_64 }, /* C1 L0..L1 2*128 KB */
    /* MAS Module 1*/        
    { 2,  K512+2*K128,                                      K128, C90_ASPACE_MAS|C90_CONTROLLER_1|C90_WIDTH_64 }, /* C1 L2..L3 2*128 KB */
    /* Shadow row - - not available on TWRPXD10 CFlash Module 1*/
    { 4,   0x200000,                                        K16, C90_ASPACE_SHADOW|C90_CONTROLLER_0|C90_WIDTH_64 }, 

    { 0, 0, 0 }
};



/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_c90_address
* Returned Value   : Address upon success
* Comments         :
*    This function returns the base register address of the C90 flash controller.
*
*END*----------------------------------------------------------------------*/

pointer _bsp_get_c90_address (uint_32 base_addr)
{
    return (pointer)MPXD10_DFLASH0_BASE;
}
/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_c90i_address
* Returned Value   : Address upon success
* Comments         :
*    This function returns the base register address of the specified C90 flash
*    controller. It is for use with the multiple controller version of the c90
*    driver.
*
*END*----------------------------------------------------------------------*/
pointer _bsp_get_c90i_address (uint_32 base_addr, uint_32 controller)
{
    if (controller == 0) {
        /* Asking for base address of the main controller associated with the specified
           address */ 
        switch (base_addr) {
            case  MPXD10_CFLASH0_MEM_BASE: return (pointer)MPXD10_CFLASH0_BASE;
            case  MPXD10_CFLASH1_MEM_BASE: return (pointer)MPXD10_CFLASH1_BASE;
            case  MPXD10_DFLASH_MEM_BASE:  return (pointer)MPXD10_DFLASH0_BASE;
        }
    } else if ((controller == 1) && (base_addr == MPXD10_CFLASH0_MEM_BASE) ){
        /* Asking for base address of the alternate controller associated with the specified
           address. Only CFLASH0 has an alternate controller. */
        return (pointer)MPXD10_CFLASH1_BASE;
    }
    return NULL;
}
