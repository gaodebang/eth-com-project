/**HEADER********************************************************************
* 
* Copyright (c) 2011 Freescale Semiconductor;
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
* $FileName: init_gpio.c$
* $Version : 3.8.4.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains board-specific pin initialization functions.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>

#include <pxs2010_cw.h>


static _siul_configure_analog_input(uint_32 pin)
{
    SIU.PCR[pin].B.APC=1;
}

static _siul_configure_pad(uint_32 pad, uint_32 padfn)
{
    SIU.PSMI[pad].B.PADSEL=padfn;
}

static _siul_configure_pull(uint_32 pin, int pull)
{
    SIU.PCR[pin].B.WPE=(pull!=0);
    SIU.PCR[pin].B.WPS=(pull>0);
}

static _siul_configure_slew_rate(uint_32 pin, int src)
{
    SIU.PCR[pin].B.SRC=src;
}

static _siul_configure_input(uint_32 pin, int pull)
{
    SIU.PCR[pin].B.IBE=1;
    _siul_configure_pull(pin, pull);
}

static _siul_configure_output(uint_32 pin, uint_32 padfn)
{
    SIU.PCR[pin].B.OBE=1;
    SIU.PCR[pin].B.SMC=1;
    SIU.PCR[pin].B.PA=padfn;
}
static _siul_configure_inout(uint_32 pin, uint_32 opadfn)
{
    _siul_configure_input(pin, 1);
    _siul_configure_output(pin, opadfn);
    SIU.PCR[pin].B.ODE=1;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_serial_io_init
* Returned Value   : MQX_OK for success, -1 for failure
* Comments         :
*    This function performs BSP-specific initialization related to serial
*
*END*----------------------------------------------------------------------*/

_mqx_int _bsp_serial_io_init(uint_8 dev_num)
{
    switch (dev_num) {
        case 0:
            _siul_configure_output(LIN0_TXD, 1);
            _siul_configure_input(LIN0_RXD, 1);
            _siul_configure_pad(MPXS20_PADSEL_LINFLEX0_RXD, 0);
            break;
        case 1:
            _siul_configure_output(LIN1_TXD, 1);
            _siul_configure_input(LIN1_RXD, 1);
            _siul_configure_pad(MPXS20_PADSEL_LINFLEX1_RXD, 2);
            break;
        default:
            return -1;
    }
    
    return MQX_OK;
}



/*FUNCTION*-------------------------------------------------------------------
 *
 * Function Name    : _bsp_flexcan_io_init
 * Returned Value   : MQX_OK for success, -1 for failure
 * Comments         :
 *    This function performs BSP-specific initialization related to can
 *
 *END*----------------------------------------------------------------------*/

_mqx_int _bsp_flexcan_io_init(uint_32 dev_num)
{
    switch (dev_num) {
        case 0:
            _siul_configure_output(CAN0_TXD, 1);
            _siul_configure_input(CAN0_RXD, 0);
            _siul_configure_pad(MPXS20_PADSEL_FLEXCAN0_RXD, 1);
            break;
        case 1:
            _siul_configure_output(CAN1_TXD, 1);
            _siul_configure_input(CAN1_RXD, 0);
            _siul_configure_pad(MPXS20_PADSEL_FLEXCAN1_RXD, 0);
            break;
        default:
            return IO_ERROR;
    }
    
    return MQX_OK;
}


/*FUNCTION*-------------------------------------------------------------------
 *
 * Function Name    : _bsp_dspi_io_init
 * Returned Value   : MQX_OK for success, -1 for failure
 * Comments         :
 *    This function performs BSP-specific initialization related to DSPI
 *
 *END*----------------------------------------------------------------------*/

_mqx_int _bsp_dspi_io_init
(
    uint_32 dev_num
)
{
    switch (dev_num)
    {
        case 0: /* DSPI0 */
            _siul_configure_output(DSPI0_CS0, 1);
            _siul_configure_slew_rate(DSPI0_CS0, 1);

            _siul_configure_output(DSPI0_CS1, 2);
            _siul_configure_slew_rate(DSPI0_CS1, 1);
            /* CS1 pull-up to disable connected accelerometer */
            _siul_configure_pull(DSPI0_CS1, 1);

            _siul_configure_output(DSPI0_SCK, 1);
            _siul_configure_slew_rate(DSPI0_SCK, 1);

            _siul_configure_output(DSPI0_SOUT, 1);
            _siul_configure_slew_rate(DSPI0_SOUT, 1);

            _siul_configure_input(DSPI0_SIN, 0);
            break;
        case 1: /* DSPI1 */
            _siul_configure_output(DSPI1_CS0, 1);
            _siul_configure_slew_rate(DSPI1_CS0, 1);

            _siul_configure_output(DSPI1_SCK, 1);
            _siul_configure_slew_rate(DSPI1_SCK, 1);

            _siul_configure_output(DSPI1_SOUT, 1);
            _siul_configure_slew_rate(DSPI1_SOUT, 1);

            _siul_configure_input(DSPI1_SIN, 0);
            break;
        case 2: /* DSPI2 */
            return -1;
            break;
        default:
            /* do nothing if bad dev_num was selected */
            return -1;
    }

    return MQX_OK;
}


/*FUNCTION*-------------------------------------------------------------------
 *
 * Function Name    : _bsp_adc_io_init
 * Returned Value   : MQX_OK for success, -1 for failure
 * Comments         :
 *    This function performs BSP-specific initialization related to ADC
 *
 *END*----------------------------------------------------------------------*/

static const uint_16 adc_pin_map[4][16] = {
   { ADC0_AN0, ADC0_AN1, ADC0_AN2, ADC0_AN3, ADC0_AN4, ADC0_AN5, ADC0_AN6, ADC0_AN7, ADC0_AN8, 0, 0, ADC0_ADC1_AN11, ADC0_ADC1_AN12, ADC0_ADC1_AN13, ADC0_ADC1_AN14, 0 },
   { ADC1_AN0, ADC1_AN1, ADC1_AN2, ADC1_AN3, ADC1_AN4, ADC1_AN5, ADC1_AN6, ADC1_AN7, ADC1_AN8, 0, 0, ADC0_ADC1_AN11, ADC0_ADC1_AN12, ADC0_ADC1_AN13, ADC0_ADC1_AN14, 0 },
};

_mqx_int _bsp_adc_io_init(uint_32 input)
{
    uint_32 pin,device, channel;

    device  = ADC_DEVICE(input);
    channel = ADC_CHANNEL(input);

    if ((device > 3) || (channel > 15)) {
        return -1;
    }

    pin = adc_pin_map[device][channel];
    if (pin) {
        _siul_configure_analog_input(pin);
    }

    return MQX_OK;
}
