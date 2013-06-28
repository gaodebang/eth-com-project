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
* $Version : 3.8.2.0$
* $Date    : Aug-6-2012$
*
* Comments:
*
*   This file contains parameters for PCB over shared memory initialization
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
    /* TX_BD_ADDR       */ (uchar_ptr)(BSP_SHARED_RAM_START)+1024,
    /* TX_LIMIT_ADDR    */ (uchar_ptr)(BSP_SHARED_RAM_START)+2048,
    /* RX_BD_ADDR       */ (pointer)(BSP_SHARED_RAM_START),
    /* RX_LIMIT_ADDR    */ (uchar_ptr)(BSP_SHARED_RAM_START)+1024,
    /* INPUT_MAX_LENGTH */ 128,
    /* RX_VECTOR        */ NVIC_CPU_to_CPU_int0,
    /* TX_VECTOR        */ NVIC_CPU_to_CPU_int1,
    /* REMOTE_RX_VECTOR */ INT_CPU_to_CPU_int0,
    /* REMOTE_TX_VECTOR */ INT_CPU_to_CPU_int1,
    /* INT_TRIGGER      */ _bsp_io_pcb_shm_int_trigger
};
