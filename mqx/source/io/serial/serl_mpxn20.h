/**HEADER********************************************************************
*
* Copyright (c) 2011 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2011 Embedded Access Inc.;
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
* $FileName: serl_mpxn20.h$
* $Version :  3.8.2.0$
* $Date    :  Oct-2-2012$
*
* Comments:
*   This include file provides the register defintons for the lin Uart.
*
*
*END************************************************************************/

#ifndef __esci_h__
#define __esci_h__ 1


/*--------------------------------------------------------------------------*/
/*
**                    CONSTANT DEFINITIONS
*/

#define lin_LINCR1_INIT        (1<<0)

#define ESCI_SCICR1_LOOPS       (1<<15)
#define ESCI_SCICR1_R           (1<<14)
#define ESCI_SCICR1_RSRC        (1<<13)
#define ESCI_SCICR1_M           (1<<12)
#define ESCI_SCICR1_WAKE        (1<<11)
#define ESCI_SCICR1_ILT         (1<<10)
#define ESCI_SCICR1_PE          (1<<9)
#define ESCI_SCICR1_PT          (1<<8)
#define ESCI_SCICR1_TIE         (1<<7)
#define ESCI_SCICR1_TCIE        (1<<6)
#define ESCI_SCICR1_RIE         (1<<5)
#define ESCI_SCICR1_ILIE        (1<<4)
#define ESCI_SCICR1_TE          (1<<3)
#define ESCI_SCICR1_RE          (1<<2)
#define ESCI_SCICR1_RWU         (1<<1)
#define ESCI_SCICR1_SBK         (1<<0)

#define ESCI_SCICR2_MDIS        (1<<15)
#define ESCI_SCICR2_FBR         (1<<14)
#define ESCI_SCICR2_BSTP        (1<<13)
#define ESCI_SCICR2_BERRIE      (1<<12)
#define ESCI_SCICR2_RXDMA       (1<<11)
#define ESCI_SCICR2_TXDMA       (1<<10)
#define ESCI_SCICR2_BRCL        (1<<9)
#define ESCI_SCICR2_TXDIR       (1<<8)
#define ESCI_SCICR2_BESM        (1<<7)
#define ESCI_SCICR2_BESTP       (1<<6)
#define ESCI_SCICR2_RXPOL       (1<<5)
#define ESCI_SCICR2_PMSK        (1<<4)
#define ESCI_SCICR2_ORIE        (1<<3)
#define ESCI_SCICR2_NFIE        (1<<2)
#define ESCI_SCICR2_FEIE        (1<<1)
#define ESCI_SCICR2_PFIE        (1<<0)

#define ESCI_SCICR3_SYNM        (1<<12)
#define ESCI_SCICR3_EROE        (1<<11)
#define ESCI_SCICR3_ERFE        (1<<10)
#define ESCI_SCICR3_ERPE        (1<<9)
#define ESCI_SCICR3_M2          (1<<8)

#define ESCI_SCIIFSR1_TDRE      (1<<15)
#define ESCI_SCIIFSR1_TC        (1<<14)
#define ESCI_SCIIFSR1_RDRF      (1<<13)
#define ESCI_SCIIFSR1_IDLE      (1<<12)
#define ESCI_SCIIFSR1_OR        (1<<11)
#define ESCI_SCIIFSR1_NF        (1<<10)
#define ESCI_SCIIFSR1_FE        (1<<9)
#define ESCI_SCIIFSR1_PF        (1<<8)
#define ESCI_SCIIFSR1_BERR      (1<<4)
#define ESCI_SCIIFSR1_TACT      (1<<1)
#define ESCI_SCIIFSR1_RACT      (1<<0)

#define ESCI_SCIIFSR2_RXRDY     (1<<15)
#define ESCI_SCIIFSR2_TXRDY     (1<<14)
#define ESCI_SCIIFSR2_LWAKE     (1<<13)
#define ESCI_SCIIFSR2_STO       (1<<12)
#define ESCI_SCIIFSR2_PBERR     (1<<11)
#define ESCI_SCIIFSR2_CERR      (1<<10)
#define ESCI_SCIIFSR2_CKERR     (1<<9)
#define ESCI_SCIIFSR2_FRC       (1<<8)
#define ESCI_SCIIFSR2_UREQ      (1<<1)
#define ESCI_SCIIFSR2_OVFL      (1<<0)

#define ESCI_SCIILCR1_LRES      (1<<15)
#define ESCI_SCIILCR1_WU        (1<<14)
#define ESCI_SCIILCR1_PRTY      (1<<9)
#define ESCI_SCIILCR1_LIN       (1<<8)
#define ESCI_SCIILCR1_RXIE      (1<<7)
#define ESCI_SCIILCR1_TXIE      (1<<6)
#define ESCI_SCIILCR1_WUIE      (1<<5)
#define ESCI_SCIILCR1_STIE      (1<<4)
#define ESCI_SCIILCR1_PBIE      (1<<3)
#define ESCI_SCIILCR1_CIE       (1<<2)
#define ESCI_SCIILCR1_CKIE      (1<<1)
#define ESCI_SCIILCR1_FCIE      (1<<0)

#define ESCI_SCIILCR2_UQIE      (1<<9)
#define ESCI_SCIILCR2_OFIE      (1<<8)

/*--------------------------------------------------------------------------*/
/*
**                    DATATYPE DECLARATIONS
*/

typedef volatile struct esci_reg_struct
{
    /*Baud Rate Register*/
    uint_16   eSCI_BRR;  
    /*Control Register 1*/
    uint_16   eSCI_CR1;  
    /*Control Register 2*/
    uint_16   eSCI_CR2;  
    /*SCI Data Register*/
    uint_16   ESCI_DR;  
    /*Interrupt Flag and Status Register 1*/
    uint_16   eSCI_IFSR1;
    /*Interrupt Flag and Status Register 2*/
    uint_16   eSCI_IFSR2;
    /*LIN Control Register 1*/
    uint_16   eSCI_LCR1; 
    /*LIN Control Register 2*/
    uint_16   eSCI_LCR2; 
    /*LIN Transmit Register */
    uchar     eSCI_LTR; 
    
    uchar     reserver0[3]
    /*LIN Receive Register*/;
    uchar     eSCI_LRR; 
    
    uchar     reserver1[3]
    /*LIN CRC Polynomial Register*/;
    uint_16   eSCI_LPR; 
    /*Control Register 3*/
    uint_16   eSCI_CR3; 

} ESCI_REG_STRUCT;

typedef volatile struct esci_reg_struct *VLIN_REG_STRUCT_PTR;


/*--------------------------------------------------------------------------*/
/*
**                        FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

VLIN_REG_STRUCT_PTR _bsp_get_lin_base_address(uint_32 channel);

#ifdef __cplusplus
}
#endif

#endif

/* EOF */
