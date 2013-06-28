/**HEADER********************************************************************
*
* Copyright (c) 2008-2011 Freescale Semiconductor;
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
* $FileName: flexcan_mpxs30.c$
* $Version : 3.8.1.0$
* $Date    : Oct-5-2011$
*
* Comments:
*
*   Processor family specific file needed for flexcan module.
*   Revision History:
*   Date             Version  Changes
*   ---------        -------  -------
*   Sep 26/08        2.50     Initial version
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include <flexcan.h>

static const pointer  flexcan_address[] = {
    (pointer) MPXS30_CAN0_BASE, (pointer) MPXS30_CAN1_BASE,
    (pointer) MPXS30_CAN2_BASE, (pointer) MPXS30_CAN3_BASE
};

static const uint_32 flexcan_config[] = {
    CORECFG_CAN_0, CORECFG_CAN_1,
    CORECFG_CAN_2, CORECFG_CAN_3
};

static const uint_32 flexcan_pbridge_id[] = {
    MPXS30_PBRIDGE_FLEXCAN_0, MPXS30_PBRIDGE_FLEXCAN_1,
    MPXS30_PBRIDGE_FLEXCAN_2, MPXS30_PBRIDGE_FLEXCAN_3
};

/*FUNCTION*-------------------------------------------------------------
*
* Function Name    : _bsp_flexcan_enable_access
* Returned Value   : True if enabled
* Comments         :
*    This function enables the specified device.
*
*END*-----------------------------------------------------------------*/

boolean _bsp_flexcan_enable_access(uint_32 device)
{
    if (device < ELEMENTS_OF(flexcan_address)) {
        if (_psp_core_peripheral_enabled(flexcan_config[device])) {
            return _qpbridge_enable_access(flexcan_pbridge_id[device]);
        }
    }
    return FALSE;
}


/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_flexcan_base_address
* Returned Value   : Pointer to desired CAN device or NULL if not present
* Comments         :
*    This function returns pointer to base address of address space of the
*    desired CAN device. Returns NULL otherwise.
*
*END*********************************************************************/

pointer _bsp_get_flexcan_base_address(uint_8 channel)
{
    if (channel < ELEMENTS_OF(flexcan_address)) {
        return flexcan_address[channel];
    }
    return NULL;
}


/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_flexcan_vector
* Returned Value   : MQX vector number for specified interrupt
* Comments         :
*    This function returns index into MQX interrupt vector table for
*    specified flexcan interrupt. If not known, returns 0.
*
*END*********************************************************************/
PSP_INTERRUPT_TABLE_INDEX _bsp_get_flexcan_vector
(
    /* [IN] FlexCAN device number */
     uint_8  dev_num,
    /* [IN] FlexCAN interrupt vector type */
     uint_8  vector_type,
    /* [IN] FlexCAN interrupt vector index */
     uint_32 vector_index
)
{
    PSP_INTERRUPT_TABLE_INDEX index = (PSP_INTERRUPT_TABLE_INDEX) 0;

    if ((FLEXCAN_INT_BUF==vector_type) && (31>=vector_index)) {
         vector_index = vector_index>>2;
    } else if (0 != vector_index) {
         return 0;
    }

    switch (dev_num)
    {
        case 0:
             switch (vector_type)
             {
                  case FLEXCAN_INT_BUF:
                      index = MPXS30_INTC_FLEXCAN0_BUF_00_03_VECTOR+vector_index;
                      break;
                  case FLEXCAN_INT_ERR:
                      index = MPXS30_INTC_FLEXCAN0_ESR_VECTOR;
                      break;
                  case FLEXCAN_INT_BOFF:
                      index = MPXS30_INTC_FLEXCAN0_BOFF_VECTOR;
                      break;
                  default:
                      break;
             }
             break;
        case 1:
             switch (vector_type)
             {
                  case FLEXCAN_INT_BUF:
                      index = MPXS30_INTC_FLEXCAN1_BUF_00_03_VECTOR+vector_index;
                      break;
                  case FLEXCAN_INT_ERR:
                      index = MPXS30_INTC_FLEXCAN1_ESR_VECTOR;
                      break;
                  case FLEXCAN_INT_BOFF:
                      index = MPXS30_INTC_FLEXCAN1_BOFF_VECTOR;
                      break;
                  default:
                      break;
             }
             break;
        case 2:
             switch (vector_type)
             {
                  case FLEXCAN_INT_BUF:
                      index = MPXS30_INTC_FLEXCAN2_BUF_00_03_VECTOR+vector_index;
                      break;
                  case FLEXCAN_INT_ERR:
                      index = MPXS30_INTC_FLEXCAN2_ESR_VECTOR;
                      break;
                  case FLEXCAN_INT_BOFF:
                      index = MPXS30_INTC_FLEXCAN2_BOFF_VECTOR;
                      break;
                  default:
                      break;
             }
             break;

        case 3:
             switch (vector_type)
             {
                  case FLEXCAN_INT_BUF:
                      index = MPXS30_INTC_FLEXCAN3_BUF_00_03_VECTOR+vector_index;
                      break;
                  case FLEXCAN_INT_ERR:
                      index = MPXS30_INTC_FLEXCAN3_ESR_VECTOR;
                      break;
                  case FLEXCAN_INT_BOFF:
                      index = MPXS30_INTC_FLEXCAN3_BOFF_VECTOR;
                      break;
                  default:
                      break;
             }
             break;

             default: break;
    }

    return index;
}
