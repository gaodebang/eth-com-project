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
* $Version : 3.8.2.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains board-specific pin initialization functions.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>

#include <pxs3020_cw.h>


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

_mqx_int _bsp_serial_io_init(uint_32 dev_num)
{
    switch (dev_num) {
        case 0:
            _siul_configure_output(LIN0_TXD, 1);
            _siul_configure_input(LIN0_RXD, 1);
            _siul_configure_pad(MPXS30_PADSEL_LINFLEX0_RXD,0);
            break;
        case 1:
            _siul_configure_output(LIN1_TXD, 1);
            _siul_configure_input(LIN1_RXD, 1);
            _siul_configure_pad(MPXS30_PADSEL_LINFLEX1_RXD,1);
            break;
        case 2:
            _siul_configure_output(LIN2_TXD, 2);
            _siul_configure_input(LIN2_RXD, 1);
            _siul_configure_pad(MPXS30_PADSEL_LINFLEX2_RXD,2);
            break;
        case 3:
            _siul_configure_output(LIN3_TXD, 2);
            _siul_configure_input(LIN3_RXD, 1);
            _siul_configure_pad(MPXS30_PADSEL_LINFLEX3_RXD,2);
            break;
        default:
            return -1;
    }

    return MQX_OK;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_enet_io_init
* Returned Value   : MQX_OK for success, -1 for failure
* Comments         :
*    This function performs BSP-specific initialization related to enet
*
*END*----------------------------------------------------------------------*/

_mqx_int _bsp_enet_io_init(uint_32 dev_num)
{
    if (dev_num) {
        return -1;
    }
    _siul_configure_output(FEC_TXD0, 1);
    _siul_configure_output(FEC_TXD1, 1);
    _siul_configure_output(FEC_TXD2, 1);
    _siul_configure_output(FEC_TXD3, 1);
    _siul_configure_output(FEC_TX_EN, 1);
    _siul_configure_output(FEC_TX_ER, 1);
    _siul_configure_input(FEC_TX_CLK, 1);

    _siul_configure_input(FEC_RXD0, 1);
    _siul_configure_input(FEC_RXD1, 1);
    _siul_configure_input(FEC_RXD2, 1);
    _siul_configure_input(FEC_RXD3, 1);
    _siul_configure_input(FEC_RX_DV, 1);
    _siul_configure_input(FEC_RX_ER, 1);
    _siul_configure_input(FEC_RX_CLK, 1);

    _siul_configure_input(FEC_CRS, 1);
    _siul_configure_input(FEC_COL, 1);

    _siul_configure_output(FEC_MDC, 1);
    // MDIO is bidirectional
    _siul_configure_inout(FEC_MDIO, 1);

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
            _siul_configure_input(CAN0_RXD, 1);
            _siul_configure_pad(MPXS30_PADSEL_FLEXCAN0_RXD,1);
            break;
        case 1:
            _siul_configure_output(CAN1_TXD, 1);
            _siul_configure_input(CAN1_RXD, 1);
            _siul_configure_pad(MPXS30_PADSEL_FLEXCAN1_RXD,0);
            break;
        case 2:
            _siul_configure_output(CAN2_TXD, 1);
            _siul_configure_input(CAN2_RXD, 1);
            _siul_configure_pad(MPXS30_PADSEL_FLEXCAN2_RXD,0);
            break;
        case 3:
            _siul_configure_output(CAN3_TXD, 1);
            _siul_configure_input(CAN3_RXD, 1);
            _siul_configure_pad(MPXS30_PADSEL_FLEXCAN3_RXD,0);
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

_mqx_int _bsp_dspi_io_init(uint_32 dev_num)
{
    switch (dev_num)
    {
        case 0: /* DSPI0 */
            _siul_configure_output(DSPI0_CS0, 1);
            //_siul_configure_output(DSPI0_CS2, 1);
            //_siul_configure_output(DSPI0_CS3, 1);
            _siul_configure_output(DSPI0_SCK, 1);
            _siul_configure_output(DSPI0_SOUT, 1);
            _siul_configure_input(DSPI0_SIN, 0);
            break;
        case 1: /* DSPI1 */
            _siul_configure_output(DSPI1_CS0, 1);
            _siul_configure_output(DSPI1_CS2, 1);
            _siul_configure_output(DSPI1_CS3, 1);
            _siul_configure_output(DSPI1_SCK, 1);
            _siul_configure_output(DSPI1_SOUT, 1);
            _siul_configure_input(DSPI1_SIN, 0);
            break;
        case 2:
            _siul_configure_output(DSPI2_CS0, 1);
            _siul_configure_output(DSPI2_CS1, 1);
            _siul_configure_output(DSPI2_CS2, 1);
            _siul_configure_output(DSPI2_SCK, 1);
            _siul_configure_output(DSPI2_SOUT, 1);
            _siul_configure_input(DSPI2_SIN, 0);
            _siul_configure_pad(MPXS30_PADSEL_DSPI2_SCK,0);
            _siul_configure_pad(MPXS30_PADSEL_DSPI2_SIN,1);
            _siul_configure_pad(MPXS30_PADSEL_DSPI2_CS0,0);
            break;

        default:
            return -1;
    }

    return MQX_OK;
}

/*FUNCTION*-------------------------------------------------------------------
 *
 * Function Name    : _bsp_i2c_io_init
 * Returned Value   : MQX_OK for success, -1 for failure
 * Comments         :
 *    This function performs BSP-specific initialization related to I2C
 *
 *END*----------------------------------------------------------------------*/
_mqx_int _bsp_i2c_io_init(uint_32 dev_num)
{
    switch (dev_num) {
        case 0:
            _siul_configure_inout(I2C0_CLOCK, 2);
            _siul_configure_inout(I2C0_DATA, 2);
            break;
        case 1:
            _siul_configure_inout(I2C1_CLOCK, 2);
            _siul_configure_inout(I2C1_DATA, 2);
            _siul_configure_pad(MPXS30_PADSEL_I2C1_SDA,0);
            _siul_configure_pad(MPXS30_PADSEL_I2C1_SCL,0);
            break;
        case 2:
            _siul_configure_inout(I2C2_CLOCK, 2);
            _siul_configure_inout(I2C2_DATA, 2);
            _siul_configure_pad(MPXS30_PADSEL_I2C2_SDA,1);
            _siul_configure_pad(MPXS30_PADSEL_I2C2_SCL,1);
            break;
        default:
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
   { ADC2_AN0, ADC2_AN1, ADC2_AN2, ADC2_AN3, 0,        0,        0,        0,        0,        0, 0, ADC2_ADC3_AN11, ADC2_ADC3_AN12, ADC2_ADC3_AN13, ADC2_ADC3_AN14, 0 },
   { ADC3_AN0, ADC3_AN1, ADC3_AN2, ADC3_AN3, 0,        0,        0,        0,        0,        0, 0, ADC2_ADC3_AN11, ADC2_ADC3_AN12, ADC2_ADC3_AN13, ADC2_ADC3_AN14, 0 }
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
