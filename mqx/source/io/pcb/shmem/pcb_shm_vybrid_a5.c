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
* $FileName: pcb_shm_vybrid_a5.c$
* $Version : 3.8.3.0$
* $Date    : Jul-24-2012$
*
* Comments:
*
*   This file contains the Vybrid_a5 core specific code for the
*   shared memory driver.
*
*END************************************************************************/

#include "mqx_inc.h"
#include "fio.h"
#include "io.h"
#include "io_prv.h"
#include "io_pcb.h"
#include "iopcbprv.h"
#include "pcb_shm.h"
#include "pcbshmv.h"
#include "bsp.h"


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _bsp_io_pcb_shm_int_trigger
* Returned Value  : _mqx_uint result   MQX_OK or an error code.
* Comments        :
*     This function triggers an interrupt to the destination processor.
*
*END*---------------------------------------------------------------------*/

void _bsp_io_pcb_shm_int_trigger(uint_32 vector)
{
    MSCM_IRCPGIR = MSCM_IRCPGIR_TLF(1) | MSCM_IRCPGIR_INTID(vector - NVIC_CPU_to_CPU_int0);
}


/*NOTIFIER*-------------------------------------------------------------
*
*  Function Name  : _bsp_io_pcb_shm_rx_isr
*  Returned Value : void
*  Comments       :
*        Packet reception ISR.
*
*END*-----------------------------------------------------------------*/

static void _bsp_io_pcb_shm_rx_isr
    (
        /* [IN] the info structure */
        pointer handle
    )
{
    IO_PCB_SHM_INFO_STRUCT_PTR    info_ptr = (IO_PCB_SHM_INFO_STRUCT_PTR)handle;

    /* clear the inter-core interrupt */
#if PSP_MQX_CPU_IS_VYBRID_A5
    MSCM_IRCP0IR = (1 << (info_ptr->INIT.RX_VECTOR - INT_CPU_to_CPU_int0));
#else
    MSCM_IRCP1IR = (1 << (info_ptr->INIT.RX_VECTOR - NVIC_CPU_to_CPU_int0));
#endif
    _io_pcb_shm_rx_isr(handle);
}

/*NOTIFIER*-------------------------------------------------------------
*
*  Function Name  : _bsp_io_pcb_shm_tx_isr
*  Returned Value : void
*  Comments       :
*        Packet transmission ISR.
*
*END*-----------------------------------------------------------------*/

static void _bsp_io_pcb_shm_tx_isr
    (
        /* [IN] the info structure */
        pointer handle
    )
{
    IO_PCB_SHM_INFO_STRUCT_PTR    info_ptr = (IO_PCB_SHM_INFO_STRUCT_PTR)handle;

    /* clear the inter-core interrupt */
#if PSP_MQX_CPU_IS_VYBRID_A5
    MSCM_IRCP0IR = (1 << (info_ptr->INIT.TX_VECTOR - INT_CPU_to_CPU_int0));
#else
    MSCM_IRCP1IR = (1 << (info_ptr->INIT.TX_VECTOR - NVIC_CPU_to_CPU_int0));
#endif
    _io_pcb_shm_tx_isr(handle);
}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _bsp_io_pcb_shm_int_install
* Returned Value  : _mqx_uint result   MQX_OK or an error code.
* Comments        :
*     This function is use to install the shared memory device ISRs.
*
*END*---------------------------------------------------------------------*/
#if PSP_MQX_CPU_IS_VYBRID_A5
_mqx_uint _bsp_io_pcb_shm_int_install
    (
        /* [IN] the initialization record for this device */
        IO_PCB_SHM_INIT_STRUCT_PTR init_ptr,

        /* [IN] the context record for this device */
        IO_PCB_SHM_INFO_STRUCT_PTR info_ptr
    )
{
    if (!_int_install_isr(init_ptr->RX_VECTOR, _bsp_io_pcb_shm_rx_isr, info_ptr))
    {
        return MQX_IO_PCB_SHM_INSTALL_ISR_FAILLED;
    }

    /* Install the tx finished ISR */
    if (!_int_install_isr(init_ptr->TX_VECTOR, _bsp_io_pcb_shm_tx_isr, info_ptr))
    {
        return MQX_IO_PCB_SHM_INSTALL_ISR_FAILLED;
    }

    /* clear all inter-core interrupts */
    MSCM_IRCP0IR = (1 << (info_ptr->INIT.RX_VECTOR - INT_CPU_to_CPU_int0));
    MSCM_IRCP0IR = (1 << (info_ptr->INIT.TX_VECTOR - INT_CPU_to_CPU_int0));
    MSCM_IRCP1IR = (1 << (info_ptr->INIT.REMOTE_RX_VECTOR - NVIC_CPU_to_CPU_int0));
    MSCM_IRCP1IR = (1 << (info_ptr->INIT.REMOTE_TX_VECTOR - NVIC_CPU_to_CPU_int0));

    _bsp_int_init(init_ptr->RX_VECTOR, BSPCFG_IO_PCB_SHM_RX_PRIO, 0, TRUE);
    _bsp_int_init(init_ptr->TX_VECTOR, BSPCFG_IO_PCB_SHM_TX_PRIO, 0 , TRUE);

    return MQX_OK;
}
#else
_mqx_uint _bsp_io_pcb_shm_int_install
    (
        /* [IN] the initialization record for this device */
        IO_PCB_SHM_INIT_STRUCT_PTR init_ptr,

        /* [IN] the context record for this device */
        IO_PCB_SHM_INFO_STRUCT_PTR info_ptr
    )
{
    if (!_int_install_isr(init_ptr->RX_VECTOR, _bsp_io_pcb_shm_rx_isr, info_ptr))
    {
        return MQX_IO_PCB_SHM_INSTALL_ISR_FAILLED;
    }

    /* Install the tx finished ISR */
    if (!_int_install_isr(init_ptr->TX_VECTOR, _bsp_io_pcb_shm_tx_isr, info_ptr))
    {
        return MQX_IO_PCB_SHM_INSTALL_ISR_FAILLED;
    }

    _bsp_int_init(init_ptr->RX_VECTOR, BSPCFG_IO_PCB_SHM_RX_PRIO, 0, TRUE);
    _bsp_int_init(init_ptr->TX_VECTOR, BSPCFG_IO_PCB_SHM_TX_PRIO, 0 , TRUE);

    return MQX_OK;
}
#endif
