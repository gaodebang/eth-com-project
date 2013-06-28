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
* $FileName: init_pcb_shm.c$
* $Version : 3.8.1.0$
* $Date    : Jul-11-2012$
*
* Comments:
*
*   This file contains the initialization definition for DSPI driver
*
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include <pcb_shm.h>

/*
** parameters for PCB over shared memory initialization
*/

const IO_PCB_SHM_INIT_STRUCT pcb_shm_init = 
{
    /* TX_BD_ADDR       */ BSP_SHARED_RAM_START,
    /* TX_LIMIT_ADDR    */ (uchar_ptr)(BSP_SHARED_RAM_START)+1024,
    /* RX_BD_ADDR       */ BSP_REMOTE_SHARED_RAM_START,
    /* RX_LIMIT_ADDR    */ (uchar_ptr)(BSP_REMOTE_SHARED_RAM_START)+1024,
    /* INPUT_MAX_LENGTH */ 128,
    /* RX_VECTOR        */ MPXS30_INTC_SSCIR0_VECTOR,
    /* TX_VECTOR        */ MPXS30_INTC_SSCIR1_VECTOR,
    /* REMOTE_RX_VECTOR */ MPXS30_INTC_SSCIR0_VECTOR,
    /* REMOTE_TX_VECTOR */ MPXS30_INTC_SSCIR1_VECTOR,
    /* INT_TRIGGER      */ _bsp_io_pcb_shm_int_trigger
};
