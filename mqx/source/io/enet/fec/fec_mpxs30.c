/**HEADER********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2008 Embedded Access Inc.;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
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
* $FileName: fec_mpxs30.c$
* $Version : 3.8.1.0$
* $Date    : Oct-5-2011$
*
* Comments:
*
*   Processor family specific file needed for enet module.
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "enetprv.h"
#include "fec_prv.h"

/*FUNCTION*-------------------------------------------------------------
* 
* Function Name    : FEC_enable_access
* Returned Value   : True if enabled
* Comments         :
*    This function enables the specified device.
*
*END*-----------------------------------------------------------------*/

boolean FEC_enable_access(uint_32 device)
{
    if (_psp_core_peripheral_enabled(CORECFG_ENET_0)) {
        return _qpbridge_enable_access(MPXS30_PBRIDGE_FEC);
    }
    return FALSE;
}

/*FUNCTION*-------------------------------------------------------------
* 
* Function Name    : FEC_get_vector
* Returned Value   : MQX vector number for specified interrupt
* Comments         :
*    This function returns index into MQX interrupt vector table for
*    specified enet interrupt. If not known, returns 0.
*
*END*-----------------------------------------------------------------*/


PSP_INTERRUPT_VECTOR_TABLE FEC_get_vector
(
    uint_32     device,
    FEC_VECTORS vector_index
)
{

   if (device == 0) {
      switch (vector_index) {
         case FEC_RX_VECTOR:  return MPXS30_INTC_FEC_RX_VECTOR;
         case FEC_TX_VECTOR:  return MPXS30_INTC_FEC_TX_VECTOR;
         case FEC_ERR_VECTOR: return MPXS30_INTC_FEC_ERR_VECTOR;
      }
    }

    return (PSP_INTERRUPT_VECTOR_TABLE) 0;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : FEC_get_base_address
* Returned Value   : Pointer to desired enem device or NULL if not present
* Comments         :
*    This function returns pointer to base address of address space of the
*    desired enet device. Returns NULL otherwise.
*
*END*----------------------------------------------------------------------*/

VFEC_STRUCT_PTR FEC_get_base_address(uint_32 device)
{
   if (device ==0) {
      return (VFEC_STRUCT_PTR) MPXS30_ETHERNET_BASE;
   }
   return NULL;
}



/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : FEC_io_init
* Returned Value   : none
* Comments         :
*    This function performs BSP-specific initialization related to ENET
*
*END*----------------------------------------------------------------------*/

void FEC_io_init( uint_32   device, uint_32 mode )
{

   if (device >= MPXS30_FEC_DEVICE_COUNT) 
      return;

   _bsp_enet_io_init(device, mode);
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : FEC_enable_clock
* Returned Value   : none
* Comments         :
*    Turn on FEC clock
*
*END*----------------------------------------------------------------------*/

void FEC_enable_clock( uint_32   device )
{
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : FEC_clock_frequency
* Returned Value   : none
* Comments         :
*    Turn on FEC clock
*
*END*----------------------------------------------------------------------*/

uint_32 FEC_clock_frequency(uint_32   device)
{
    return BSP_CORE_CLOCK;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : FEC_clock_frequency
* Returned Value   : none
* Comments         :
*    Turn on FEC clock
*
*END*----------------------------------------------------------------------*/

uint_32 FEC_int_level(uint_32   device)
{
    return BSPCFG_FEC_PRIORITY;
}
