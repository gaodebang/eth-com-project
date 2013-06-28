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
* $FileName: spi_mpxd10.c$
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


static const pointer dspi_address[] =
{
    (pointer)MPXD10_DSPI_0_BASE,
    (pointer)MPXD10_DSPI_1_BASE
};


static const uint_32 /*PSP_INTERRUPT_TABLE_INDEX*/ dspi_vectors[][5] =
{
    {
        MPXD10_INTC_DSPI0_SR_TFUF_RFOF_VECTOR,
        MPXD10_INTC_DSPI0_SR_EOQF_VECTOR,
        MPXD10_INTC_DSPI0_SR_TFFF_VECTOR,
        MPXD10_INTC_DSPI0_SR_TCF_VECTOR,
        MPXD10_INTC_DSPI0_SR_RFDF_VECTOR
    },
    {
        MPXD10_INTC_DSPI1_SR_TFUF_RFOF_VECTOR,
        MPXD10_INTC_DSPI1_SR_EOQF_VECTOR,
        MPXD10_INTC_DSPI1_SR_TFFF_VECTOR,
        MPXD10_INTC_DSPI1_SR_TCF_VECTOR,
        MPXD10_INTC_DSPI1_SR_RFDF_VECTOR
    }

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

pointer _bsp_get_dspi_base_address
(
    uint_8 dev_num
)
{
   if (dev_num < ELEMENTS_OF(dspi_address)) {
        return dspi_address[dev_num];
   }
    return NULL;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_dspi_vectors
* Returned Value   : Number of vectors upon success, 0 upon failure
* Comments         :
*    This function returns desired interrupt vector table indices for specified
*    SPI module and vector identifier.
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
