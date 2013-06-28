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
* $FileName: mpxn20_fec_util.c$
* $Version : 3.8.2.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This file contains the FEC Driver utility functions
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "enetprv.h"
#include "mpxn20_fec_prv.h"

/*NOTIFIER*-------------------------------------------------------------
*
*  Function Name  : MPXN20_FEC_Error_ISR
*  Returned Value : void
*  Comments       :
*        Interrupt service routine for Tx.
*
*END*-----------------------------------------------------------------*/

void MPXN20_FEC_Error_ISR
   (
         /* [IN] the Ethernet state structure */
      pointer  enet
   )
{
   ENET_CONTEXT_STRUCT_PTR  enet_ptr = (ENET_CONTEXT_STRUCT_PTR)enet;
   MPXN20_FEC_CONTEXT_STRUCT_PTR   fec_context_ptr = (MPXN20_FEC_CONTEXT_STRUCT_PTR) enet_ptr->MAC_CONTEXT_PTR;
   MPXN20_VFEC_STRUCT_PTR          fec_ptr= fec_context_ptr->FEC_ADDRESS;
   uint_32                  events;

   if (fec_ptr == NULL) return;

   events = fec_ptr->EIR;
   while (events & MPXN20_FEC_EIR_HBERR) {

      /* clear the interrupt */
      fec_ptr->EIR = MPXN20_FEC_EIR_HBERR;

      events = fec_ptr->EIR;
   }
}


/*NOTIFIER*-------------------------------------------------------------
*
*  Function Name  : MPXN20_FEC_ISR
*  Returned Value : void
*  Comments       :
*        Interrupt service routine for FEC. Used for devices with one
*  FEC Vector
*
*END*-----------------------------------------------------------------*/

void MPXN20_FEC_ISR
   (
         /* [IN] the Ethernet state structure */
      pointer  enet
   )
{
   ENET_CONTEXT_STRUCT_PTR          enet_ptr = (ENET_CONTEXT_STRUCT_PTR)enet;
   MPXN20_FEC_CONTEXT_STRUCT_PTR   fec_context_ptr = (MPXN20_FEC_CONTEXT_STRUCT_PTR) enet_ptr->MAC_CONTEXT_PTR;
   MPXN20_VFEC_STRUCT_PTR          fec_ptr= fec_context_ptr->FEC_ADDRESS;
   uint_32                          events;

   if (fec_ptr == NULL) return;

   events = fec_ptr->EIR;
   while (events & (MPXN20_FEC_EIR_TXF | MPXN20_FEC_EIR_TXB | MPXN20_FEC_EIR_RXF | MPXN20_FEC_EIR_RXB| MPXN20_FEC_EIR_HBERR)) {

      if (events & (MPXN20_FEC_EIR_TXB | MPXN20_FEC_EIR_TXF)) {
         /* clear the TX interrupt */
         fec_ptr->EIR = MPXN20_FEC_EIR_TXB | MPXN20_FEC_EIR_TXF;
         MPXN20_FEC_process_tx_bds(enet_ptr);
      }

      if (events & (MPXN20_FEC_EIR_RXF | MPXN20_FEC_EIR_RXB)) {

         /* clear the RX interrupt */
         fec_ptr->EIR = (MPXN20_FEC_EIR_RXF | MPXN20_FEC_EIR_RXB);
         MPXN20_FEC_process_rx_bds(enet_ptr);
      }

      if (events & MPXN20_FEC_EIR_HBERR) {

         /* clear the interrupt */
         fec_ptr->EIR = MPXN20_FEC_EIR_HBERR;

         events = fec_ptr->EIR;
      }

      events = fec_ptr->EIR;
   }
}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : MPXN20_FEC_free_context
*  Returned Value :
*  Comments       :
*
*
*END*-----------------------------------------------------------------*/

void MPXN20_FEC_free_context( MPXN20_FEC_CONTEXT_STRUCT_PTR fec_context_ptr )
{
   if (fec_context_ptr) {
      if (fec_context_ptr->UNALIGNED_BUFFERS) {
         _mem_free((pointer)fec_context_ptr->UNALIGNED_BUFFERS);
      }
      if (fec_context_ptr->RX_PCB_BASE) {
         _mem_free((pointer)fec_context_ptr->RX_PCB_BASE);
      }
      if (fec_context_ptr->TxPCBS_PTR) {
         _mem_free((pointer)fec_context_ptr->TxPCBS_PTR);
      }
      if (fec_context_ptr->UNALIGNED_RING_PTR) {
         _mem_free((pointer)fec_context_ptr->UNALIGNED_RING_PTR);
      }

      _mem_free((pointer)fec_context_ptr);
   }
}

/* EOF */
