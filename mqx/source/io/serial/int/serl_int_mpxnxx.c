/**HEADER********************************************************************
*
* Copyright (c) 2011 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2011 Embedded Access Inc.;
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
* $FileName: serl_int_mpxnxx.c$
* $Version : 3.8.1.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains the driver functions for the LINFLEXD
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "io_prv.h"
#include "charq.h"
#include "fio_prv.h"
#include "serinprv.h"


extern _mqx_uint _lin_serial_polled_ioctl(LIN_SERIAL_INFO_STRUCT_PTR, _mqx_uint, pointer);
extern _mqx_uint _lin_serial_init(LIN_SERIAL_INIT_STRUCT_PTR, pointer _PTR_, char_ptr, uint_32);
extern _mqx_uint _lin_serial_polled_deinit(LIN_SERIAL_INIT_STRUCT_PTR, LIN_SERIAL_INFO_STRUCT_PTR );

static uint_32 _lin_serial_int_init( IO_SERIAL_INT_DEVICE_STRUCT_PTR, char_ptr);
static uint_32 _lin_serial_int_deinit( LIN_SERIAL_INIT_STRUCT_PTR,LIN_SERIAL_INFO_STRUCT_PTR);
static uint_32 _lin_serial_int_enable( LIN_SERIAL_INFO_STRUCT_PTR);
static void    _lin_serial_int_rx_tx_isr( pointer );
static void    _lin_serial_int_err_isr(pointer);
static void    _lin_serial_int_putc( IO_SERIAL_INT_DEVICE_STRUCT_PTR,char);


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _lin_serial_int_install
* Returned Value   : uint_32 a task error code or MQX_OK
* Comments         :
*    Install an interrupt driven uart serial device.
*
*END*----------------------------------------------------------------------*/

uint_32 _lin_serial_int_install
    (
        /* [IN] A string that identifies the device for fopen */
        char_ptr identifier,

        /* [IN] The I/O init data pointer */
        const LIN_SERIAL_INIT_STRUCT _PTR_ init_data_ptr
    )
{
    return _io_serial_int_install(identifier,
        (uint_32 (_CODE_PTR_)(pointer, char _PTR_))_lin_serial_int_init,
        (uint_32 (_CODE_PTR_)(pointer))_lin_serial_int_enable,
        (uint_32 (_CODE_PTR_)(pointer,pointer))_lin_serial_int_deinit,
        (void    (_CODE_PTR_)(pointer, char))_lin_serial_int_putc,
        (uint_32 (_CODE_PTR_)(pointer, uint_32, pointer))_lin_serial_polled_ioctl,
        (pointer)init_data_ptr,
        init_data_ptr->QUEUE_SIZE);
}


/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_int_init
* Returned Value   : uint_32 a task error code or MQX_OK
* Comments         :
*    This function initializes the UART in interrupt mode.
*
*END*********************************************************************/

static uint_32 _lin_serial_int_init
    (
        /* [IN] the interrupt I/O initialization information */
        IO_SERIAL_INT_DEVICE_STRUCT_PTR int_io_dev_ptr,

        /* [IN] the rest of the name of the device opened */
        char_ptr                        open_name_ptr
    )
{
    LIN_SERIAL_INFO_STRUCT_PTR uart_info_ptr;
    LIN_SERIAL_INIT_STRUCT_PTR uart_init_ptr;
    uint_32                         i,result;

    uart_init_ptr = int_io_dev_ptr->DEV_INIT_DATA_PTR;

    result = _lin_serial_init((pointer)uart_init_ptr,
        &int_io_dev_ptr->DEV_INFO_PTR, open_name_ptr, LIN_BUFFER_MODE);

    if (result != MQX_OK)
    {
        return result;
    }

    uart_info_ptr = int_io_dev_ptr->DEV_INFO_PTR;

    uart_info_ptr->NUM_VECTORS = _bsp_get_lin_vectors(uart_init_ptr->DEVICE, &uart_info_ptr->VECTORS);

    if (uart_info_ptr->NUM_VECTORS == ESCI_NUM_VECTORS)
    {
        for (i=0; i < uart_info_ptr->NUM_VECTORS; i++)
        {
            uart_info_ptr->OLD_ISR_DATA[i] = _int_get_isr_data(uart_info_ptr->VECTORS[i]);
        }

        uart_info_ptr->OLD_ISR[ESCI_COMBINED_VECTOR_INDEX] =
             _int_install_isr(uart_info_ptr->VECTORS[ESCI_COMBINED_VECTOR_INDEX], _lin_serial_int_rx_tx_isr, int_io_dev_ptr);

        for (i=0;i<uart_info_ptr->NUM_VECTORS;i++)
        {
            _bsp_int_init(uart_info_ptr->VECTORS[i], uart_init_ptr->PRIORITY,0,TRUE);
        }
    }
    else
    {
         return MQX_INVALID_VECTORED_INTERRUPT;
    }
    
    return MQX_OK;
}


/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_int_deinit
* Returned Value   : uint_32 a task error code or MQX_OK
* Comments         :
*    This function de-initializes the UART in interrupt mode.
*
*END*********************************************************************/

static uint_32 _lin_serial_int_deinit
    (
        /* [IN] the interrupt I/O initialization information */
        LIN_SERIAL_INIT_STRUCT_PTR io_init_ptr,

        /* [IN] the address of the device specific information */
        LIN_SERIAL_INFO_STRUCT_PTR io_info_ptr
    )
{
    VLIN_REG_STRUCT_PTR            lin_ptr = io_info_ptr->LIN_PTR;
    uint_32 i;

    /* Disable interrupts */
    lin_ptr->eSCI_CR1 &= ~(ESCI_SCICR1_TIE|ESCI_SCICR1_RIE);
        
    _lin_serial_polled_deinit(io_init_ptr, io_info_ptr);

    for (i=0;i<io_info_ptr->NUM_VECTORS;i++)
    {
        _int_install_isr(io_info_ptr->VECTORS[i], io_info_ptr->OLD_ISR[i], io_info_ptr->OLD_ISR_DATA[i]);
    }

    return(MQX_OK);
}


/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_int_enable
* Returned Value   : uint_32 a task error code or MQX_OK
* Comments         :
*    This function enables the UART interrupts mode.
*
*END*********************************************************************/

uint_32 _lin_serial_int_enable
    (
        /* [IN] the address of the device specific information */
        LIN_SERIAL_INFO_STRUCT_PTR io_info_ptr
    )
{
    VLIN_REG_STRUCT_PTR            lin_ptr = io_info_ptr->LIN_PTR;
    lin_ptr->eSCI_IFSR1 = ESCI_SCIIFSR1_TDRE;
    lin_ptr->eSCI_CR1 |= (ESCI_SCICR1_TIE|ESCI_SCICR1_RIE);

    return MQX_OK;
}



/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_int_rx_tx_isr
* Returned Value   : none
* Comments         :
*   interrupt handler for the serial I/O interrupts.
*
*************************************************************************/

static void _lin_serial_int_rx_tx_isr
    (
        /* [IN] the address of the device specific information */
        pointer parameter
    )
{
    IO_SERIAL_INT_DEVICE_STRUCT_PTR     int_io_dev_ptr = parameter;
    LIN_SERIAL_INFO_STRUCT_PTR     io_info_ptr = int_io_dev_ptr->DEV_INFO_PTR;
    VLIN_REG_STRUCT_PTR            lin_ptr = io_info_ptr->LIN_PTR;
    int_32                              c;
    uint_16                             stat;

    /* Handle receive */
    if (lin_ptr->eSCI_IFSR1 & ESCI_SCIIFSR1_RDRF) {

        lin_ptr->eSCI_IFSR1 =  ESCI_SCIIFSR1_RDRF;
        c = lin_ptr->ESCI_DR;

        stat = lin_ptr->eSCI_IFSR1;
        if (stat & (ESCI_SCIIFSR1_OR|ESCI_SCIIFSR1_FE|ESCI_SCIIFSR1_PF)) {
            if (stat & ESCI_SCIIFSR1_OR) {
                ++io_info_ptr->STATS.RX_OVERRUNS;
                lin_ptr->eSCI_IFSR1 = ESCI_SCIIFSR1_OR;
            }
            if (stat & ESCI_SCIIFSR1_FE) {
                ++io_info_ptr->STATS.RX_FRAMING_ERRORS;
                lin_ptr->eSCI_IFSR1 = ESCI_SCIIFSR1_FE;
            }
            if (stat & ESCI_SCIIFSR1_PF) {
                ++io_info_ptr->STATS.RX_PARITY_ERRORS;
                lin_ptr->eSCI_IFSR1 = ESCI_SCIIFSR1_PF;
            }
        }

        io_info_ptr->STATS.RX_CHARS++;

        if (!_io_serial_int_addc(int_io_dev_ptr, c)) {
            io_info_ptr->STATS.RX_DROPPED_INPUT++;
        }
    }
    if (lin_ptr->eSCI_IFSR1 & ESCI_SCIIFSR1_TDRE) {
        lin_ptr->eSCI_IFSR1 = ESCI_SCIIFSR1_TDRE;

        c = _io_serial_int_nextc(int_io_dev_ptr);
        if (c >= 0)
        {
            lin_ptr->ESCI_DR = c;
            io_info_ptr->STATS.TX_CHARS++;
        }
    }
    io_info_ptr->STATS.INTERRUPTS++;
}


/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_int_err_isr
* Returned Value   : none
* Comments         :
*   interrupt handler for the serial I/O error interrupts.
*
*************************************************************************/

static void _lin_serial_int_err_isr 
(
        /* [IN] the address of the device specific information */
        pointer parameter
    )
{
    IO_SERIAL_INT_DEVICE_STRUCT_PTR     int_io_dev_ptr = parameter;
    LIN_SERIAL_INFO_STRUCT_PTR     io_info_ptr = int_io_dev_ptr->DEV_INFO_PTR;
    VLIN_REG_STRUCT_PTR            lin_ptr = io_info_ptr->LIN_PTR;

    io_info_ptr->STATS.INTERRUPTS++;
}


/*FUNCTION****************************************************************
*
* Function Name    : _lin_serial_int_putc
* Returned Value   : none
* Comments         :
*   This function is called to write out the first character, when
* the output serial device and output ring buffers are empty.
*
*END*********************************************************************/

static void _lin_serial_int_putc
    (
        /* [IN] the address of the device specific information */
        IO_SERIAL_INT_DEVICE_STRUCT_PTR int_io_dev_ptr,

        /* [IN] the character to write out now */
        char c
    )
{
    LIN_SERIAL_INFO_STRUCT_PTR     io_info_ptr =  int_io_dev_ptr->DEV_INFO_PTR;
    VLIN_REG_STRUCT_PTR            lin_ptr = io_info_ptr->LIN_PTR;

    lin_ptr->ESCI_DR = c;
    io_info_ptr->STATS.TX_CHARS++;
}

/* EOF */
