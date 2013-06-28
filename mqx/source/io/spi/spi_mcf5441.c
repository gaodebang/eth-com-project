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
* $FileName: spi_mcf5441.c$
* $Version : 3.8.2.0$
* $Date    : Oct-3-2012$
*
* Comments:
*
*   This file contains board-specific SPI initialization functions.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include "spi_dspi.h"


static const uint_32 /*PSP_INTERRUPT_TABLE_INDEX*/ dspi_vectors[][1] =
{
    { MCF5441_INT_DSPI0 },
    { MCF5441_INT_DSPI1 },
    { MCF5441_INT_DSPI2 },
    { MCF5441_INT_DSPI3 }
};


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_dspi_base_address
* Returned Value   : Address upon success, NULL upon failure
* Comments         :
*    This function returns the base register address of the corresponding SPI
*    module.
*
*END*----------------------------------------------------------------------*/

pointer _bsp_get_dspi_base_address(uint_8 dev_num)
{
    pointer addr = NULL;
    
    switch (dev_num) 
    {
        case 0:
            addr = (pointer)&(((VMCF5441_STRUCT_PTR)_PSP_GET_IPSBAR())->DSPI0);
            break;
        case 1:
            addr = (pointer)&(((VMCF5441_STRUCT_PTR)_PSP_GET_IPSBAR())->DSPI1);
            break;
        case 2:
            addr = (pointer)&(((VMCF5441_STRUCT_PTR)_PSP_GET_IPSBAR())->DSPI2);
            break;
        case 3:
            addr = (pointer)&(((VMCF5441_STRUCT_PTR)_PSP_GET_IPSBAR())->DSPI3);
            break;
        default:
            break;
    }
    
    return addr;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_dspi_vectors
* Returned Value   : Number of vectors associated with the peripheral
* Comments         :
*    This function returns desired interrupt vector table indices for specified
*    SPI module.
*
*END*----------------------------------------------------------------------*/

uint_32 _bsp_get_dspi_vectors(uint_32 dev_num, const uint_32 _PTR_ _PTR_ vectors_ptr)
{
    if (dev_num < ELEMENTS_OF(dspi_vectors)) {
        *vectors_ptr = dspi_vectors[dev_num];
        return ELEMENTS_OF(dspi_vectors[0]);
    }
    return 0;
}
