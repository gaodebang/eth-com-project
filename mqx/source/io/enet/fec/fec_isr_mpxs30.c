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
* $FileName: fec_isr_mpxs30.c$
* $Version : 3.8.1.0$
* $Date    : Oct-5-2011$
*
* Comments:
*
*   This file contains the FEC Driver utility functions
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "enetprv.h"
#include "fec_prv.h"

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : FEC_install_isrs
*  Returned Value :
*  Comments       :
*
*
*END*-----------------------------------------------------------------*/

boolean FEC_install_isrs( ENET_CONTEXT_STRUCT_PTR enet_ptr  )
{
#if BSPCFG_ENET_RESTORE
   FEC_CONTEXT_STRUCT_PTR     fec_context_ptr = (FEC_CONTEXT_STRUCT_PTR) enet_ptr->MAC_CONTEXT_PTR;
#endif

   fec_context_ptr->OLDISR_PTR[0]  = _int_get_isr(MPXS30_INTC_FEC_RX_VECTOR);
   fec_context_ptr->OLDISR_DATA[0] = _int_get_isr_data(MPXS30_INTC_FEC_RX_VECTOR);
   fec_context_ptr->OLDISR_PTR[1]  = _int_get_isr(MPXS30_INTC_FEC_TX_VECTOR);
   fec_context_ptr->OLDISR_DATA[1] = _int_get_isr_data(MPXS30_INTC_FEC_TX_VECTOR);
   fec_context_ptr->OLDISR_PTR[2]  = _int_get_isr(MPXS30_INTC_FEC_ERR_VECTOR);
   fec_context_ptr->OLDISR_DATA[3] = _int_get_isr_data(MPXS30_INTC_FEC_ERR_VECTOR);

   if (_int_install_isr(MPXS30_INTC_FEC_RX_VECTOR, FEC_RX_ISR, (pointer)enet_ptr)==NULL) {
      return FALSE;
   }
   if (_int_install_isr(MPXS30_INTC_FEC_TX_VECTOR, FEC_TX_ISR, (pointer)enet_ptr)==NULL) {
      return FALSE;
   }
   if (_int_install_isr(MPXS30_INTC_FEC_ERR_VECTOR, FEC_TX_ISR, (pointer)enet_ptr)==NULL) { // TODO: FEC_ISR
      return FALSE;
   }

   /* Enable Ethernet Interrupt at INTC level  */
   _bsp_int_init(MPXS30_INTC_FEC_RX_VECTOR, BSPCFG_FEC_PRIORITY,0,TRUE);
   _bsp_int_init(MPXS30_INTC_FEC_TX_VECTOR, BSPCFG_FEC_PRIORITY,0,TRUE);
   _bsp_int_init(MPXS30_INTC_FEC_ERR_VECTOR,BSPCFG_FEC_PRIORITY,0,TRUE);

   return TRUE;
}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : FEC_mask_interrupts
*  Returned Value :
*  Comments       :
*
*
*END*-----------------------------------------------------------------*/

void FEC_mask_interrupts( ENET_CONTEXT_STRUCT_PTR enet_ptr )
{
	  _bsp_int_disable(MPXS30_INTC_FEC_RX_VECTOR);
	  _bsp_int_disable(MPXS30_INTC_FEC_TX_VECTOR);
	  _bsp_int_disable(MPXS30_INTC_FEC_ERR_VECTOR);
}


#if BSPCFG_ENET_RESTORE


/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : FEC_uninstall_all_isrs
*  Returned Value :
*  Comments       :
*
*
*END*-----------------------------------------------------------------*/

void FEC_uninstall_all_isrs( ENET_CONTEXT_STRUCT_PTR enet_ptr )
{
   FEC_CONTEXT_STRUCT_PTR    fec_context_ptr = (FEC_CONTEXT_STRUCT_PTR) enet_ptr->MAC_CONTEXT_PTR;

   FEC_mask_interrupts(enet_ptr);

   if (fec_context_ptr->OLDISR_PTR[0]) {
 	 _int_install_isr(MPXS30_INTC_FEC_RX_VECTOR, fec_context_ptr->OLDISR_PTR[0], fec_context_ptr->OLDISR_DATA[0]);
     fec_context_ptr->OLDISR_PTR[0] = NULL;
    }
   if (fec_context_ptr->OLDISR_PTR[1]) {
 	 _int_install_isr(MPXS30_INTC_FEC_TX_VECTOR, fec_context_ptr->OLDISR_PTR[1], fec_context_ptr->OLDISR_DATA[1]);
     fec_context_ptr->OLDISR_PTR[1] = NULL;
    }
   if (fec_context_ptr->OLDISR_PTR[2]) {
 	 _int_install_isr(MPXS30_INTC_FEC_ERR_VECTOR, fec_context_ptr->OLDISR_PTR[2], fec_context_ptr->OLDISR_DATA[2]);
     fec_context_ptr->OLDISR_PTR[2] = NULL;
    }
}
#endif
