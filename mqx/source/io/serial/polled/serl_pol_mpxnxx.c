/**HEADER********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2010 Embedded Access Inc.;
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
* $FileName: serl_pol_mpxnxx.c$
* $Version : 3.8.1.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains the driver functions for the LIN_SERIAL
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "io_prv.h"
#include "charq.h"
#include "fio_prv.h"
#include "serplprv.h"
#include "serl_lin_esci.h"


/* Polled driver functions */
extern _mqx_uint _lin_serial_polled_init(LIN_SERIAL_INIT_STRUCT_CPTR, pointer _PTR_, char_ptr);
extern _mqx_uint _lin_serial_polled_deinit(LIN_SERIAL_INIT_STRUCT_PTR, LIN_SERIAL_INFO_STRUCT_PTR );
static char      _lin_serial_polled_getc(LIN_SERIAL_INFO_STRUCT_PTR);
static void      _lin_serial_polled_putc(LIN_SERIAL_INFO_STRUCT_PTR, char);
static boolean   _lin_serial_polled_status(LIN_SERIAL_INFO_STRUCT_PTR);
extern _mqx_uint _lin_serial_polled_ioctl(LIN_SERIAL_INFO_STRUCT_PTR, _mqx_uint, pointer);
extern uint_32   _lin_uart_serial_int_enable(LIN_SERIAL_INFO_STRUCT_PTR io_info_ptr);


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _lin_serial_polled_install
* Returned Value   : _mqx_uint a task error code or MQX_OK
* Comments         :
*    Install a polled lin_ptr serial device.
*
*END*----------------------------------------------------------------------*/

_mqx_uint _lin_serial_polled_install
    (
        /* [IN] A string that identifies the device for fopen */
        char_ptr           identifier,

        /* [IN] The I/O init data pointer */
        LIN_SERIAL_INIT_STRUCT_CPTR  init_data_ptr
    )
{
    return _io_serial_polled_install(identifier,
        (_mqx_uint (_CODE_PTR_)(pointer, pointer _PTR_, char _PTR_)) _lin_serial_polled_init,
        (_mqx_uint (_CODE_PTR_)(pointer, pointer))  _lin_serial_polled_deinit,
        (char (_CODE_PTR_)(pointer)) _lin_serial_polled_getc,
        (void (_CODE_PTR_)(pointer, char)) _lin_serial_polled_putc,
        (boolean (_CODE_PTR_)(pointer)) _lin_serial_polled_status,
        (_mqx_uint (_CODE_PTR_)(pointer, _mqx_uint, pointer)) _lin_serial_polled_ioctl,
        (pointer)init_data_ptr, init_data_ptr->QUEUE_SIZE);
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _lin_serial_reconfigure
* Returned Value   : _mqx_uint a task error code or MQX_OK
* Comments         :
*
*
*END*----------------------------------------------------------------------*/

static uint_32 _lin_serial_reconfigure
    (
        LIN_SERIAL_INFO_STRUCT_PTR io_info_ptr
    )
{
    VLIN_REG_STRUCT_PTR lin_ptr ;
    uint_32 uartcr = 0;
    uint_32 lfdiv;
    uint_32 lincr1,lincr2;


    if (io_info_ptr->INIT.STOP_BITS != IO_SERIAL_STOP_BITS_1) {
        return MQX_INVALID_PARAMETER;
    }
    switch (io_info_ptr->INIT.PARITY) {
        case IO_SERIAL_PARITY_EVEN:
            uartcr |= ESCI_SCICR1_PE;
            break;
        case IO_SERIAL_PARITY_ODD:
            uartcr |= ESCI_SCICR1_PE | ESCI_SCICR1_PT;
            break;
        case IO_SERIAL_PARITY_NONE:
            if (io_info_ptr->INIT.BITS_PER_CHARACTER==7) {
                return MQX_INVALID_PARAMETER;
            }
            break;

        default:
            return MQX_INVALID_PARAMETER;
            break;
    }

    switch (io_info_ptr->INIT.BITS_PER_CHARACTER) {
        case 7:
            break;
        case 8:
            break;
        default:
            return MQX_INVALID_PARAMETER;
            break;
    }

    lin_ptr = (VLIN_REG_STRUCT_PTR)io_info_ptr->LIN_PTR;
  
    /* Save interrupt enable state - reconfigure may be done from polled or interrupt mode driver */
    lincr1 = lin_ptr->eSCI_CR1;
    lincr2 = lin_ptr->eSCI_CR2;

    /* Select UART mode and set parameters */
    lin_ptr->eSCI_LCR1 &= ~ESCI_SCIILCR1_LIN;
    lin_ptr->eSCI_LCR1 = uartcr;

    /* Enable Tx and Rx */
    uartcr |= ESCI_SCICR1_TE | ESCI_SCICR1_RE;
    lin_ptr->eSCI_CR1 = uartcr;

    /* Calculate baud rate */
    lfdiv =  (io_info_ptr->INIT.CLOCK_SPEED/(16*io_info_ptr->INIT.BAUD_RATE));
    lin_ptr->eSCI_BRR = (uint_16)(lfdiv & 0x1FFF);

    /* Disable interrupts */
    lin_ptr->eSCI_CR1 &= ~(ESCI_SCICR1_TIE|ESCI_SCICR1_RIE);
    
    /* Restore interrupt enable state */
    lin_ptr->eSCI_CR1 |= lincr1;
    lin_ptr->eSCI_CR2 |= lincr2;

    return MQX_OK;
}


/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_init
* Returned Value   : MQX_OK or a MQX error code.
* Comments         :
*    This function initializes LIN in UART mode
*
*END*********************************************************************/

uint_32 _lin_serial_init
    (
        /* [IN] the initialization information for the device being opened */
        LIN_SERIAL_INIT_STRUCT_CPTR    io_init_ptr,

        /* [OUT] the address to store device specific information */
        pointer _PTR_                       io_info_ptr_ptr,

        /* [IN] the rest of the name of the device opened */
        char _PTR_                          open_name_ptr,

        /* [IN] the uart mode to use */
        uint_32                             mode
    )
{
    VLIN_REG_STRUCT_PTR         lin_ptr;
    LIN_SERIAL_INFO_STRUCT_PTR  io_info_ptr;
    uint_32                          channel;
    uint_32                          result;

    /* Get peripheral address */
    channel = io_init_ptr->DEVICE;

    lin_ptr = _bsp_get_lin_base_address(channel);
    if (lin_ptr == NULL) {
        return MQX_INVALID_IO_CHANNEL;
    }

    io_info_ptr = (LIN_SERIAL_INFO_STRUCT_PTR)_mem_alloc_system_zero(
        (_mem_size)sizeof(LIN_SERIAL_INFO_STRUCT));

    #if MQX_CHECK_MEMORY_ALLOCATION_ERRORS
    if (io_info_ptr == NULL) {
        return MQX_OUT_OF_MEMORY;
    }
    #endif

    /* Save initialization values and base address */
    io_info_ptr->INIT = *io_init_ptr;

    /* Polled driver uses fifo mode, int driver uses buffered mode */
    io_info_ptr->CONTROL_BITS = mode;

    /* Store pointer to lin registers */
    io_info_ptr->LIN_PTR = lin_ptr;
    
    /* */
    lin_ptr->eSCI_CR2 &= ~(ESCI_SCICR2_MDIS);
    
    /* Disable interrupts*/
    lin_ptr->eSCI_CR1 &= ~(ESCI_SCICR1_TIE|ESCI_SCICR1_RIE);
    
    /* init GPIO and clock GATING */
    _bsp_serial_io_init(channel);

    result = _lin_serial_reconfigure(io_info_ptr);
    if (result!=MQX_OK) {
        _mem_free(io_info_ptr);
        io_info_ptr = NULL;
    }
    *io_info_ptr_ptr = io_info_ptr;

    return result;
} 

/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_polled_init
* Returned Value   : MQX_OK or a MQX error code.
* Comments         :
*    This function initializes LIN in UART mode
*
*END*********************************************************************/

uint_32 _lin_serial_polled_init
    (
        /* [IN] the initialization information for the device being opened */
        LIN_SERIAL_INIT_STRUCT_CPTR    io_init_ptr,

        /* [OUT] the address to store device specific information */
        pointer _PTR_                       io_info_ptr_ptr,

        /* [IN] the rest of the name of the device opened */
        char _PTR_                          open_name_ptr
    )
{
    return _lin_serial_init(io_init_ptr, io_info_ptr_ptr, open_name_ptr, LIN_FIFO_MODE);
}


/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_polled_deinit
* Returned Value   : MQX_OK or a mqx error code.
* Comments         :
*    This function de-initializes the UART
*
*END*********************************************************************/

_mqx_uint _lin_serial_polled_deinit
    (
        /* [IN] the initialization information for the device being opened */
        LIN_SERIAL_INIT_STRUCT_PTR io_init_ptr,

        /* [IN] the address of the device specific information */
        LIN_SERIAL_INFO_STRUCT_PTR io_info_ptr
    )
{
    _mem_free((pointer)io_info_ptr);

    return MQX_OK;
}


/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_polled_getc
* Returned Value   : char
* Comments         :
*   Return a character when it is available.
*   This function polls the device for input.
*
*************************************************************************/

static char _lin_serial_polled_getc
    (
        /* [IN] the address of the device specific information */
        LIN_SERIAL_INFO_STRUCT_PTR io_info_ptr
    )
{
    VLIN_REG_STRUCT_PTR lin_ptr = io_info_ptr->LIN_PTR;
    uchar data;

    while ((lin_ptr->eSCI_IFSR1&ESCI_SCIIFSR1_RDRF) == 0){
    /* Wait until there is a character available */
    }
    
    data = lin_ptr->ESCI_DR;
    lin_ptr->eSCI_IFSR1 |=ESCI_SCIIFSR1_RDRF;
    io_info_ptr->STATS.RX_CHARS++;

    return (char)data;
}


/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_polled_putc
* Returned Value   : void
* Comments         :
*   Writes the provided character.
*
*END*********************************************************************/

static void _lin_serial_polled_putc
    (
        /* [IN] the address of the device specific information */
        LIN_SERIAL_INFO_STRUCT_PTR io_info_ptr,

        /* [IN] the character to write */
        char                           c
    )
{
    VLIN_REG_STRUCT_PTR lin_ptr = io_info_ptr->LIN_PTR;
    lin_ptr->eSCI_IFSR1 |=ESCI_SCIIFSR1_TDRE; 
    lin_ptr->ESCI_DR = c;
    
    while (!(lin_ptr->eSCI_IFSR1&ESCI_SCIIFSR1_TDRE)){
    }
    
    io_info_ptr->STATS.TX_CHARS++;
}


/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_polled_status
* Returned Value   : boolean
* Comments         :
*            This function returns TRUE if a character is available
*            on the on I/O device, otherwise it returns FALSE.
*
*END*********************************************************************/

static boolean _lin_serial_polled_status
    (
        /* [IN] the address of the device specific information */
        LIN_SERIAL_INFO_STRUCT_PTR io_info_ptr
    )
{
    VLIN_REG_STRUCT_PTR lin_ptr = io_info_ptr->LIN_PTR;

    if ((lin_ptr->eSCI_IFSR1&ESCI_SCIIFSR1_RDRF)!=0)
         return TRUE;
    else
         return FALSE;
}


/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_polled_ioctl
* Returned Value   : uint_32 MQX_OK or a mqx error code.
* Comments         :
*    This function performs miscellaneous services for
*    the I/O device.
*
*END*********************************************************************/

uint_32 _lin_serial_polled_ioctl
    (
        /* [IN] the address of the device specific information */
        LIN_SERIAL_INFO_STRUCT_PTR io_info_ptr,

        /* [IN] The command to perform */
        _mqx_uint                      cmd,

        /* [IN] Parameters for the command */
        pointer                        param_ptr
    )
{
    uint_32_ptr u32_ptr = (uint_32_ptr)param_ptr;
    VLIN_REG_STRUCT_PTR lin_ptr = io_info_ptr->LIN_PTR;

    switch (cmd) {

    case IO_IOCTL_SERIAL_GET_STOP_BITS:
        *u32_ptr = io_info_ptr->INIT.STOP_BITS;
        return MQX_OK;

    case IO_IOCTL_SERIAL_SET_STOP_BITS:
        if (*u32_ptr != IO_SERIAL_STOP_BITS_1)
            return MQX_INVALID_PARAMETER;

    case IO_IOCTL_SERIAL_GET_DATA_BITS:
        *u32_ptr = io_info_ptr->INIT.BITS_PER_CHARACTER;
        break;

    case IO_IOCTL_SERIAL_SET_DATA_BITS:
        io_info_ptr->INIT.BITS_PER_CHARACTER = *u32_ptr;
        return _lin_serial_reconfigure(io_info_ptr);

    case IO_IOCTL_SERIAL_GET_BAUD:
        *u32_ptr = io_info_ptr->INIT.BAUD_RATE;
        break;

    case IO_IOCTL_SERIAL_SET_BAUD:
        io_info_ptr->INIT.BAUD_RATE = *u32_ptr;
        return _lin_serial_reconfigure(io_info_ptr);

    case IO_IOCTL_SERIAL_GET_STATS:
        {
            LIN_STATS_STRUCT_PTR stats_ptr = (LIN_STATS_STRUCT_PTR)param_ptr;
            *stats_ptr = io_info_ptr->STATS;
        }
        break;

    case IO_IOCTL_SERIAL_CLEAR_STATS:
        _mem_zero((pointer) &io_info_ptr->STATS, sizeof(io_info_ptr->STATS));
        break;

    case IO_IOCTL_SERIAL_GET_CONFIG:
        {
            LIN_SERIAL_INIT_STRUCT_PTR io_init_ptr = (LIN_SERIAL_INIT_STRUCT_PTR)param_ptr;
            *io_init_ptr = io_info_ptr->INIT;
        }
        break;

    case IO_IOCTL_SERIAL_GET_PARITY:
        *(uint_32_ptr)param_ptr = io_info_ptr->INIT.PARITY;
        break;
        
    case IO_IOCTL_SERIAL_SET_PARITY:
        switch (*(uint_32_ptr)param_ptr) {
            case IO_SERIAL_PARITY_NONE:
            case IO_SERIAL_PARITY_ODD:
            case IO_SERIAL_PARITY_EVEN:
            case IO_SERIAL_PARITY_MARK:
            case IO_SERIAL_PARITY_SPACE:
                break;
            default:
                return MQX_INVALID_PARAMETER;
        }
        io_info_ptr->INIT.PARITY = *(uint_32_ptr)param_ptr;
        return _lin_serial_reconfigure(io_info_ptr);
        
    case IO_IOCTL_SERIAL_DISABLE_RX:
        if( *(boolean _PTR_)param_ptr == TRUE ) 
        {
            /* disable receiver */
            lin_ptr->eSCI_CR1 &=~ESCI_SCICR1_RE;
        }
        else 
        {      
            /* enable receiver */  
            lin_ptr->eSCI_CR1 |= ESCI_SCICR1_RE;
        }   
        break;

    case IO_IOCTL_SERIAL_WAIT_FOR_TC:
         /* wait for transmission end signal */
         while( ! lin_ptr->eSCI_IFSR1 & ESCI_SCIIFSR1_TC )   
         { };
         break;
                   
    default:
        return IO_ERROR_INVALID_IOCTL_CMD;
    }

    return MQX_OK;
}

/* EOF */
