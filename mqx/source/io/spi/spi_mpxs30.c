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
* $FileName: spi_mpxs30.c$
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


static const uint_32 dspi_config[]  =
{
    CORECFG_SPI_0,
    CORECFG_SPI_1,
    CORECFG_SPI_2
};

static const uint_32 dspi_pbridge_id[] =
{
    MPXS30_PBRIDGE_DSPI_0,
    MPXS30_PBRIDGE_DSPI_1,
    MPXS30_PBRIDGE_DSPI_2
};


static const pointer dspi_address[] =
{
    (pointer)MPXS30_DSPI_0_BASE,
    (pointer)MPXS30_DSPI_1_BASE,
    (pointer)MPXS30_DSPI_2_BASE
};


static const uint_32 /*PSP_INTERRUPT_TABLE_INDEX*/ dspi_vectors[][5] =
{
    {
        MPXS30_INTC_DSPI0_TFUF_RFOF_VECTOR,
        MPXS30_INTC_DSPI0_EOQF_VECTOR,
        MPXS30_INTC_DSPI0_TFFF_VECTOR,
        MPXS30_INTC_DSPI0_TCF_VECTOR,
        MPXS30_INTC_DSPI0_RFDF_VECTOR,
    },
    {
        MPXS30_INTC_DSPI1_TFUF_RFOF_VECTOR,
        MPXS30_INTC_DSPI1_EOQF_VECTOR,
        MPXS30_INTC_DSPI1_TFFF_VECTOR,
        MPXS30_INTC_DSPI1_TCF_VECTOR,
        MPXS30_INTC_DSPI1_RFDF_VECTOR,
    },
    {
        MPXS30_INTC_DSPI2_TFUF_RFOF_VECTOR,
        MPXS30_INTC_DSPI2_EOQF_VECTOR,
        MPXS30_INTC_DSPI2_TFFF_VECTOR,
        MPXS30_INTC_DSPI2_TCF_VECTOR,
        MPXS30_INTC_DSPI2_RFDF_VECTOR,
    },
};


/*FUNCTION*-------------------------------------------------------------
*
* Function Name    : _bsp_dspi_enable_access
* Returned Value   : True if enabled
* Comments         :
*    This function enables the specified device.
*
*END*-----------------------------------------------------------------*/

boolean _bsp_dspi_enable_access(uint_32 device)
{
    if (device < ELEMENTS_OF(dspi_address)) {
        if (_psp_core_peripheral_enabled(dspi_config[device])) {
            return _qpbridge_enable_access(dspi_pbridge_id[device]);
        }
    }
    return FALSE;
}


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
    if (dev_num < ELEMENTS_OF(dspi_address)) {
        return dspi_address[dev_num];
    }
    return NULL;
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