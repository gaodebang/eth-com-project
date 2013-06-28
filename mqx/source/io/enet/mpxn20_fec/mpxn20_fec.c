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
* $FileName: mpxn20_fec.c$
* $Version : 3.8.2.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   Processor family specific file needed for enet module.
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "enetprv.h"
#include "mpxn20_fec_prv.h"

/*FUNCTION*-------------------------------------------------------------
* 
* Function Name    : MPXN20_FEC_enable_access
* Returned Value   : True if enabled
* Comments         :
*    This function enables the specified device.
*
*END*-----------------------------------------------------------------*/

boolean MPXN20_FEC_enable_access(uint_32 device)
{    
    
    return TRUE;
}

/*FUNCTION*-------------------------------------------------------------
* 
* Function Name    : MPXN20_FEC_get_vector
* Returned Value   : MQX vector number for specified interrupt
* Comments         :
*    This function returns index into MQX interrupt vector table for
*    specified enet interrupt. If not known, returns 0.
*
*END*-----------------------------------------------------------------*/


PSP_INTERRUPT_TABLE_INDEX MPXN20_FEC_get_vector
(
    uint_32     device,
    MPXN20_FEC_VECTORS vector_index
)
{

   if (device == 0) {
      switch (vector_index) {
         case MPXN20_FEC_RX_VECTOR:  return MPXN20_INTC_FEC_RX_VECTOR;
         case MPXN20_FEC_TX_VECTOR:  return MPXN20_INTC_FEC_TX_VECTOR;         
         /*case MPXN20_FEC_ERR_VECTOR: return MPXN20_INTC_FEC_ERR_VECTOR;*/
      }
    }

    return 0;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : MPXN20_FEC_get_base_address
* Returned Value   : Pointer to desired enem device or NULL if not present
* Comments         :
*    This function returns pointer to base address of address space of the
*    desired enet device. Returns NULL otherwise.
*
*END*----------------------------------------------------------------------*/

MPXN20_VFEC_STRUCT_PTR MPXN20_FEC_get_base_address(uint_32 device)
{
   if (device ==0) {
      return (MPXN20_VFEC_STRUCT_PTR) MPXN20_FEC_BASE;
   }
   return NULL;
}



/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : MPXN20_FEC_io_init
* Returned Value   : none
* Comments         :
*    This function performs BSP-specific initialization related to ENET
*
*END*----------------------------------------------------------------------*/

void MPXN20_FEC_io_init( uint_32   device, uint_32 mode )
{

   if (device >= MPXN20_FEC_DEVICE_COUNT) 
      return;

   _bsp_enet_io_init(device, mode);
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : MPXN20_FEC_enable_clock
* Returned Value   : none
* Comments         :
*    Turn on FEC clock
*
*END*----------------------------------------------------------------------*/

void MPXN20_FEC_enable_clock( uint_32   device )
{
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : MPXN20_FEC_clock_frequency
* Returned Value   : none
* Comments         :
*    Turn on FEC clock
*
*END*----------------------------------------------------------------------*/

uint_32 MPXN20_FEC_clock_frequency(uint_32   device)
{
    
    return BSP_TIMEBASE_CLOCK;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : MPXN20_FEC_clock_frequency
* Returned Value   : none
* Comments         :
*    Turn on FEC clock
*
*END*----------------------------------------------------------------------*/

uint_32 MPXN20_FEC_int_level(uint_32   device)
{
    return BSPCFG_FEC_PRIORITY;
}

/* EOF */
