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
* $FileName: fec_mpxs30.h$
* $Version : 3.8.1.0$
* $Date    : Oct-5-2011$
*
* Comments:
*
*   This file contains the definitions of constants and structures
*   required for the ethernet drivers for the mpxs30 processor
*
*END************************************************************************/
#ifndef _mpxs30_fec_h
#define _mpxs30_fec_h 1


#define MPXS30_FEC_DEVICE_COUNT            1

// Three interrupt vectors
typedef enum {
   FEC_RX_VECTOR,
   FEC_TX_VECTOR,
   FEC_ERR_VECTOR,
   FEC_NUM_ISRS
} FEC_VECTORS;

#define FEC_RX_BUFFER_ALIGNMENT     64     // TODO: check
#define FEC_TX_BUFFER_ALIGNMENT     64     // TODO: check
#define FEC_BD_ALIGNMENT            64     // TODO: check

/*
** PHY MII Speed (MDC - Management Data Clock)
*/
#define FEC_PHY_MII_SPEED                             (2500000L)

// Needs to be here, because a SMALL packet must be a multiple of the RX_BUFFER_ALIGNMENT
#define FEC_SMALL_PACKET_SIZE           ENET_ALIGN(64,FEC_RX_BUFFER_ALIGNMENT)

// temporary - these should be generic PSP functions.
#define _psp_set_int_prio_and_level(vector, level, sublev, unmask)    _bsp_int_init(vector, level, sublev, unmask)
#define _psp_int_mask(x)                    _bsp_int_disable(x)

/* The Ethernet initialization structure */
typedef struct {
   uint_32 RX_PRIO;
   uint_32 TX_PRIO;
   uint_32 ERR_PRIO;
} FEC_INT_INIT_STRUCT, _PTR_ FEC_INIT_INIT_STRUCT_PTR;



#endif

