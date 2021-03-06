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
* $FileName: mpxn20_fec_init.c$
* $Version : 3.8.2.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This file contains the FEC Ethernet initialization functions
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "enet.h"
#include "enetprv.h"
#include "bsp_prv.h"
#include "mpxn20_fec_prv.h"


#if PSP_HAS_DATA_CACHE  && !MQX_USE_UNCACHED_MEM
   #warning FEC driver requires uncached memory
#endif

const ENET_MAC_IF_STRUCT MPXN20_FEC_IF = {
    MPXN20_FEC_initialize,
    MPXN20_FEC_shutdown,
    MPXN20_FEC_send,
    MPXN20_FEC_read_mii,
    MPXN20_FEC_write_mii
    #if BSPCFG_ENABLE_ENET_MULTICAST
    ,
    MPXN20_FEC_join,
    MPXN20_FEC_rejoin
    #endif
};


/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : MPXN20_FEC_initialize
*  Returned Value : ENET_OK or error code
*  Comments       :
*        Initializes the chip (extended version).
*
*END*-----------------------------------------------------------------*/

#define IF_ERROR_EXIT(c,x) {if (c) { error = x; goto EXIT; }}

uint_32 MPXN20_FEC_initialize
   (
      ENET_CONTEXT_STRUCT_PTR enet_ptr
   )
{
   MPXN20_FEC_CONTEXT_STRUCT_PTR   fec_context_ptr=NULL;
   MPXN20_VFEC_STRUCT_PTR          fec_ptr;
   MPXN20_VFEC_BD_STRUCT_PTR       bd_ptr;
   uchar_ptr                buf_ptr;
   MPXN20_FEC_RX_PCB_PTR           pcb_ptr;
   uint_32                  i, rxsize, txsize, ssize, lsize, pcbsize,rx_pcb_size, large_packet_size, rcr;
   uint_32                  clock, timeout, error = ENET_OK;
   boolean                  bOK;

   #if PSP_HAS_DEVICE_PROTECTION
   if (!FEC_enable_access(enet_ptr->PARAM_PTR->ENET_IF->MAC_NUMBER)) {
       return ENETERR_INVALID_DEVICE;
   }
   #endif

   fec_ptr = MPXN20_FEC_get_base_address(enet_ptr->PARAM_PTR->ENET_IF->MAC_NUMBER);
   if (fec_ptr == NULL) {
      return ENETERR_INVALID_DEVICE;
   }

   /* currently limit number of TX BDs to 32, as a bitmask is used in the free function.*/
   if (enet_ptr->PARAM_PTR->NUM_TX_ENTRIES > 32) {
      return ENETERR_INVALID_INIT_PARAM;
   }

   /*
   ** This function can be called from any context, and it needs mutual
   ** exclusion with itself.
   */
   MPXN20_FEC_int_disable();

   fec_context_ptr = _mem_alloc_system_zero(sizeof(MPXN20_FEC_CONTEXT_STRUCT));
   IF_ERROR_EXIT((NULL==fec_context_ptr), ENETERR_ALLOC_MAC_CONTEXT);
   _mem_set_type((pointer)fec_context_ptr, MEM_TYPE_IO_ENET_MAC_CONTEXT_STRUCT);

   enet_ptr->MAC_CONTEXT_PTR = (pointer) fec_context_ptr;

   fec_context_ptr->FEC_ADDRESS = fec_ptr;
   fec_context_ptr->PHY_PTR = MPXN20_FEC_get_base_address(enet_ptr->PARAM_PTR->ENET_IF->PHY_NUMBER);

   /* Turn the clock on to the FEC.*/
   MPXN20_FEC_enable_clock(enet_ptr->PARAM_PTR->ENET_IF->MAC_NUMBER);

   /* Stop the chip */
   fec_ptr->ECR = MPXN20_FEC_ECR_RESET;

   /* wait until the initialization cycle completes */
   timeout = 0;
   while ((fec_ptr->ECR & MPXN20_FEC_ECR_RESET) && (timeout<MPXN20_FEC_RESET_TIMEOUT)){
      _time_delay(1);
      timeout++;
   }
   IF_ERROR_EXIT((fec_ptr->ECR & MPXN20_FEC_ECR_RESET), ENETERR_INIT_FAILED);

   /* Disable all FEC interrupts */
   fec_ptr->EIMR = 0;

   /* clear any pending interrpts */
   fec_ptr->EIR = MPXN20_FEC_EIR_ALL_PENDING;

   fec_context_ptr->NumRxBDs = enet_ptr->PARAM_PTR->NUM_RX_ENTRIES;
   fec_context_ptr->NumTxBDs = enet_ptr->PARAM_PTR->NUM_TX_ENTRIES;

   /* Compute aligned buffer sizes*/
   if (enet_ptr->PARAM_PTR->TX_BUFFER_SIZE) {
      fec_context_ptr->AlignedTxBufferSize = MPXN20_FEC_TX_ALIGN(enet_ptr->PARAM_PTR->TX_BUFFER_SIZE);
   } else {
      fec_context_ptr->AlignedTxBufferSize = MPXN20_FEC_TX_ALIGN(enet_ptr->MaxTxFrameSize);
   }

   if (enet_ptr->PARAM_PTR->RX_BUFFER_SIZE) {
      fec_context_ptr->AlignedRxBufferSize = MPXN20_FEC_RX_ALIGN(enet_ptr->PARAM_PTR->RX_BUFFER_SIZE);
   } else {
      fec_context_ptr->AlignedRxBufferSize = MPXN20_FEC_RX_ALIGN(enet_ptr->MaxRxFrameSize);
   }

   /* Allocate the Transmit and Receive buffer descriptors*/
   bd_ptr = (MPXN20_VFEC_BD_STRUCT_PTR)_mem_alloc_system_zero_uncached((sizeof(MPXN20_FEC_BD_STRUCT)*(fec_context_ptr->NumRxBDs+fec_context_ptr->NumTxBDs))+MPXN20_FEC_BD_ALIGNMENT);

   IF_ERROR_EXIT((NULL == bd_ptr), ENETERR_ALLOC_BD);
   _mem_set_type((pointer)bd_ptr, MEM_TYPE_IO_BD_STRUCT);

   fec_context_ptr->UNALIGNED_RING_PTR = (pointer) bd_ptr;
   fec_context_ptr->FEC_RX_RING_PTR = (MPXN20_VFEC_BD_STRUCT_PTR) MPXN20_FEC_BD_ALIGN((uint_32)bd_ptr);
   fec_context_ptr->FEC_TX_RING_PTR = &fec_context_ptr->FEC_RX_RING_PTR[fec_context_ptr->NumRxBDs];

   /* Set wrap bit in last BD */
   fec_context_ptr->FEC_RX_RING_PTR[fec_context_ptr->NumRxBDs - 1].CONTROL = MPXN20_FEC_BD_ETHER_RX_WRAP;
   fec_context_ptr->FEC_TX_RING_PTR[fec_context_ptr->NumTxBDs - 1].CONTROL = MPXN20_FEC_BD_ETHER_TX_WRAP;

   fec_context_ptr->AvailableTxBDs = fec_context_ptr->NumTxBDs;

   /* Allocate array to hold Transmit PCB pointers while they are queued for transmission*/
   fec_context_ptr->TxPCBS_PTR = (PCB_PTR *) _mem_alloc_system_zero(sizeof(PCB_PTR)*fec_context_ptr->NumTxBDs);
   IF_ERROR_EXIT((NULL==fec_context_ptr->TxPCBS_PTR), ENETERR_ALLOC_PCB);
   _mem_set_type((pointer)fec_context_ptr->TxPCBS_PTR, MEM_TYPE_IO_PCB_PTR);

   /* Allocate the Receive PCBs*/
   rx_pcb_size = sizeof(MPXN20_FEC_RX_PCB);
   pcbsize = enet_ptr->PARAM_PTR->NUM_RX_PCBS * rx_pcb_size;
   fec_context_ptr->RX_PCB_BASE = (MPXN20_FEC_RX_PCB_PTR) _mem_alloc_system_zero(pcbsize);
   IF_ERROR_EXIT((NULL==fec_context_ptr->RX_PCB_BASE), ENETERR_ALLOC_PCB);
   _mem_set_type((pointer)fec_context_ptr->RX_PCB_BASE, MEM_TYPE_IO_PCB_STRUCT);

   /* Allocate the Transmit and Receive buffers*/
   txsize = (enet_ptr->PARAM_PTR->NUM_TX_BUFFERS * fec_context_ptr->AlignedTxBufferSize) + MPXN20_FEC_TX_BUFFER_ALIGNMENT;
   rxsize = (enet_ptr->PARAM_PTR->NUM_RX_BUFFERS  * fec_context_ptr->AlignedRxBufferSize) + MPXN20_FEC_RX_BUFFER_ALIGNMENT;
   ssize  = (enet_ptr->PARAM_PTR->NUM_SMALL_BUFFERS * MPXN20_FEC_SMALL_PACKET_SIZE);
   large_packet_size = enet_ptr->PARAM_PTR->OPTIONS&ENET_OPTION_VLAN ? ENET_FRAMESIZE_VLAN : ENET_FRAMESIZE;
   lsize  = (enet_ptr->PARAM_PTR->NUM_LARGE_BUFFERS * large_packet_size);

   /* temporary fix for cache problems... was befor _mem_alloc_system*/
   buf_ptr = _mem_alloc_system_uncached( rxsize + txsize + ssize + lsize);  
   IF_ERROR_EXIT((NULL==buf_ptr), ENETERR_ALLOC_BUFFERS);
   _mem_set_type(buf_ptr, MEM_TYPE_IO_ENET_BUFFERS);

   fec_context_ptr->UNALIGNED_BUFFERS = buf_ptr;

   /* Align to TX buffer boundary*/
   buf_ptr = (uchar_ptr)MPXN20_FEC_TX_ALIGN((uint_32)buf_ptr);

   /* Queue packets on TX Buffer Q.*/
   fec_context_ptr->TX_BUFFERS = NULL;
   for (i=0;i<enet_ptr->PARAM_PTR->NUM_TX_BUFFERS;i++) {
      ENET_Enqueue_Buffer((pointer *)&fec_context_ptr->TX_BUFFERS, buf_ptr);
      buf_ptr += fec_context_ptr->AlignedTxBufferSize;
   }

   /* Align to RX buffer boundary*/
   buf_ptr = (uchar_ptr)MPXN20_FEC_RX_ALIGN((uint_32)buf_ptr);

   /* Queue packets on RX Buffer Q.*/
   fec_context_ptr->RX_BUFFERS = NULL;
   for (i=0;i<enet_ptr->PARAM_PTR->NUM_RX_BUFFERS;i++) {
      ENET_Enqueue_Buffer((pointer *)&fec_context_ptr->RX_BUFFERS, buf_ptr);
      buf_ptr += fec_context_ptr->AlignedRxBufferSize;
   }

   /* Queue small packets on small buffer Q.*/
   for (i=0;i<enet_ptr->PARAM_PTR->NUM_SMALL_BUFFERS;i++) {
      ENET_Enqueue_Buffer((pointer *)&fec_context_ptr->SMALL_BUFFERS, buf_ptr);
      buf_ptr += MPXN20_FEC_SMALL_PACKET_SIZE;
   }

   /* Queue large packets on large buffer Q.*/
   for (i=0;i<enet_ptr->PARAM_PTR->NUM_LARGE_BUFFERS;i++) {
      ENET_Enqueue_Buffer((pointer *)&fec_context_ptr->LARGE_BUFFERS, buf_ptr);
      buf_ptr += large_packet_size;
   }

   /*Enqueue the RX PCBs onto the receive PCB queue*/
   pcb_ptr = fec_context_ptr->RX_PCB_BASE;
   for (i = 0; i < enet_ptr->PARAM_PTR->NUM_RX_PCBS; i++) {
      QADD(fec_context_ptr->RxPCBHead, fec_context_ptr->RxPCBTail, (PCB_PTR) pcb_ptr);
      pcb_ptr++;
   }

   /* Fill up the receive ring*/
   MPXN20_FEC_add_buffers_to_rx_ring(fec_context_ptr);

   /* Initialize the FEC I/O Pins*/
   MPXN20_FEC_io_init(enet_ptr->PARAM_PTR->ENET_IF->MAC_NUMBER, enet_ptr->PARAM_PTR->OPTIONS);


   /* Set the DMA Byte Order */   
   fec_ptr->ETH_DMA_CONTROL = ETH_DMA_CONTROL_DATA_BO_BIG | ETH_DMA_CONTROL_DESC_BO_BIG;

   /* Program this station's Ethernet physical address */
   fec_ptr->PALR = *(uint_32_ptr) &enet_ptr->ADDRESS[0];
   fec_ptr->PAUR = (*(uint_16_ptr)(&enet_ptr->ADDRESS[4])) << 16;

   /* Clear the individual hash table registers*/
   fec_ptr->IAUR = 0;
   fec_ptr->IALR = 0;

   /* Clear the group hash table registers*/
   fec_ptr->GAUR = 0;
   fec_ptr->GALR = 0;

   /* Program receive buffer size */
   fec_ptr->EMRBR = fec_context_ptr->AlignedRxBufferSize;

   /* Configure start of Rx and Tx BD rings*/   
   
   fec_ptr->ERDSR = (uint_32)fec_context_ptr->FEC_RX_RING_PTR;
   fec_ptr->ETDSR = (uint_32) fec_context_ptr->FEC_TX_RING_PTR;

   /* Set Receive Frame size
   ** NOTE: Oddly, the Receive Control Register (RCR) affects the transmit side too.  The RCR is used to determine if the
   **     transmitter is babbling, which means, if the RX buffer size < Tx Buffer size, we can get babbling transmitter
   **     errors if we set RCR to the maximum Receive frame length.  We really have no choice but to set RCR to one
   **     of ENET_FRAMESIZE or ENET_FRAMESIZE_VLAN.
   */
   rcr = MPXN20_FEC_RCR_MII_MODE | MPXN20_FEC_RCR_FRAME_LENGTH(large_packet_size);
   if (enet_ptr->PARAM_PTR->OPTIONS & ENET_OPTION_RMII) {
      rcr |= MPXN20_FEC_RCR_RMMI_MODE;
   } else if (enet_ptr->PARAM_PTR->OPTIONS & ENET_OPTION_7WIRE) {
      rcr &= ~MPXN20_FEC_RCR_MII_MODE;
   }
   /*rcr |= MPXN20_FEC_RCR_PROM;*/
   fec_ptr->RCR =  rcr;


   if (enet_ptr->PARAM_PTR->OPTIONS & ENET_OPTION_MAC_LOOPBACK) {
      fec_ptr->RCR |= MPXN20_FEC_RCR_LOOP;
   }
   else{
      fec_ptr->RCR &= ~MPXN20_FEC_RCR_LOOP;       
   }
       

   /*  Set Full/Half duplex based on mode.*/
   if (enet_ptr->PARAM_PTR->MODE & ENET_HALF_DUPLEX) {
       /* half duplex*/
      fec_ptr->TCR = 0; 
   } else {
       /* full duplex*/
      fec_ptr->TCR = 4; 
   }

   /*
    ** Enable MII_SPEED register
    **   MII_SPEED = Bus Clock/(MII Clock *2)
    ** Note: we are not multiplying MII Clock by 2 below since the MII Clock field starts at bit 1, not bit 0
    */
   clock = MPXN20_FEC_clock_frequency(enet_ptr->PARAM_PTR->ENET_IF->MAC_NUMBER);
   i = (clock/ enet_ptr->PARAM_PTR->ENET_IF->PHY_MII_SPEED + 1) & ~1;

   if (enet_ptr->PARAM_PTR->OPTIONS & ENET_OPTION_NO_PREAMBLE) {
      i |= MPXN20_FEC_MII_MSCR_PREAMBLE;
   }
   fec_ptr->MSCR = i;

   /*Zero counters*/
   fec_ptr->MIBC = 0x80000000;
   _mem_zero((pointer)fec_ptr->MIB_RAM, sizeof(fec_ptr->MIB_RAM));
   fec_ptr->MIBC = 0;

   /*Install the ISRs*/
   bOK = MPXN20_FEC_install_isrs( enet_ptr);
   IF_ERROR_EXIT(!bOK, ENETERR_INSTALL_ISR);



   /*
    ** Unmask transmit/receive interrupts
    ** NOTE: need to enable both RXF and RXB, but only TXB, as RXB does not get generated with RXF,
    **      but TXB does get generated with TXF
    ** However, on 52259, enabling RXB is resulting in an HBERR interrupt. RXB is not required, so leave it disabled.
    */
   fec_ptr->EIMR =MPXN20_FEC_EIMR_TXB | MPXN20_FEC_EIMR_RXF;

    /*Enable FEC*/
   fec_ptr->ECR = MPXN20_FEC_ECR_ETHER_EN;

    /*Discover PHY address if PHY_DISCOVER option is set*/
   if (enet_ptr->PARAM_PTR->OPTIONS & ENET_OPTION_PHY_DISCOVER) {
      bOK = (*enet_ptr->PARAM_PTR->ENET_IF->PHY_IF->DISCOVER)(enet_ptr);
      IF_ERROR_EXIT(!bOK, ENETERR_INIT_FAILED);
   } else {
    /*   Set Phy address from initialization parameter*/
      enet_ptr->PHY_ADDRESS = enet_ptr->PARAM_PTR->ENET_IF->PHY_ADDRESS;
   }

    /*Perform Phy initialization*/
   bOK = (*enet_ptr->PARAM_PTR->ENET_IF->PHY_IF->INIT)(enet_ptr);
   IF_ERROR_EXIT(!bOK, ENETERR_INIT_FAILED);


   /*
    ** Signals the FEC that empty buffers are available.
    ** It is NECESSARY to do this AFTER enabling the FEC.
    */
   fec_ptr->RDAR = MPXN20_FEC_RDAR_ACTIVE;

    /*control transfers to this point on any error, with error set to error code.*/
EXIT:
   if (ENET_OK!=error) {
      #if BSPCFG_ENET_RESTORE
         MPXN20_FEC_uninstall_all_isrs(enet_ptr);
      #endif
      MPXN20_FEC_free_context(fec_context_ptr);
   }
   MPXN20_FEC_int_enable();
   return error;
}

/* EOF */
