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
* $Version : 3.8.1.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains board-specific pin initialization functions.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>

#include <pxn2020_cw.h>



static const uint_16 adc_pin_map[1][14] = {
   {
      ADC0_AN0,
      ADC0_AN1,
      ADC0_AN2,
      ADC0_AN3,
      ADC0_AN4,
      ADC0_AN5,
      ADC0_AN6,
      ADC0_AN7,
      ADC0_AN8,
      ADC0_AN9,
      ADC0_AN10,
      ADC0_AN11,
      ADC0_AN12,
      ADC0_AN13
   }
};


static _siu_configure_input(uint_32 pin, uint_32 padfn)
{
    SIU.PCR[pin].B.IBE=1;
    SIU.PCR[pin].B.WPE=1;
    SIU.PCR[pin].B.WPS=1;
    SIU.PCR[pin].B.PA =padfn;
}

static _siu_configure_output(uint_32 pin, uint_32 padfn)
{
    SIU.PCR[pin].B.OBE=1;
    SIU.PCR[pin].B.SRC=1;
    SIU.PCR[pin].B.PA=padfn;
}

static _siu_configure_output_pull_up(uint_32 pin )
{
    SIU.PCR[pin].B.WPE=1;
    SIU.PCR[pin].B.WPS=1;
}

static _siu_configure_inout(uint_32 pin, uint_32 padfn)
{
    SIU.PCR[pin].B.ODE=1;
    SIU.PCR[pin].B.IBE=1;
    SIU.PCR[pin].B.OBE=1;
    SIU.PCR[pin].B.WPE=1;
    SIU.PCR[pin].B.WPS=1;
    SIU.PCR[pin].B.SRC=1;
    SIU.PCR[pin].B.PA=padfn;
}

static _siu_configure_analog_input(uint_32 pin, uint_32 padfn)
{
   SIU.PCR[pin].B.PA=padfn;
   SIU.PCR[pin].B.WPE=1;
   SIU.PCR[pin].B.WPS=0;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_serial_io_init
* Returned Value   : 0 for success, -1 for failure
* Comments         :
*    This function performs BSP-specific initialization related to serial
*
*END*----------------------------------------------------------------------*/

_mqx_int _bsp_serial_io_init(uint_8 dev_num)
{
    switch (dev_num) {
        case 0:  /* eSCI_A */
            /* TX */
            _siu_configure_output(LIN0_TXD, 1);
            /* RX */         
            _siu_configure_input(LIN0_RXD, 1);    
            break;
        case 1:  /* eSCI_B */
            /* TX */
            _siu_configure_output(LIN1_TXD, 1);
            /* RX */
            _siu_configure_input(LIN1_RXD, 1);
            break;
        case 2:  /* eSCI_C */
            /* TX */
            _siu_configure_output(LIN2_TXD, 1);
            /* RX */
            _siu_configure_input(LIN2_RXD, 1);
            break;
        case 3:  /* eSCI_D */
            /* TX */
               _siu_configure_output(LIN3_TXD, 1);
            /* RX */
            _siu_configure_input(LIN3_RXD, 1);
            break;
        case 4:  /* eSCI_E */
            /* TX */
            _siu_configure_output(LIN4_TXD, 1);
            /* RX */
            _siu_configure_input(LIN4_RXD, 1);    
            break;
        case 5:  /* eSCI_F */
            /* TX */
            _siu_configure_output(LIN5_TXD, 1);
            /* RX */
            _siu_configure_input(LIN5_RXD, 1);
            break;
        default:
            return -1;
    }
    
    return 0;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_dspi_io_init
* Returned Value   : MQX_OK or -1
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
        case 0: /* DSPI0 - DSPI_A*/
            /* SCK (PF0) */
            _siu_configure_output(DSPI0_SCK, 1);
            /* SOUT (PF1) */
            _siu_configure_output(DSPI0_SOUT, 1);
            /* SIN (PF2) */
            _siu_configure_input(DSPI0_SIN, 1);
            /* CS0 (PF3) */
            _siu_configure_output(DSPI0_CS0, 1);
            
            break;

        case 1: /* DSPI1 - DSPI_B */
            /* SCK (PF4) */
            _siu_configure_output(DSPI1_SCK, 1);       
            /* SOUT (PF5) */
            _siu_configure_output(DSPI1_SOUT, 1); 
            /* SIN (PF6) */
            _siu_configure_input(DSPI1_SIN, 1);
            /* CS0 (PF7) */
            _siu_configure_output(DSPI1_CS0, 1);
                        
            break;
            
        case 2: /* DSPI2 - DSPI_C */
            /* SCK (PF8) */
            _siu_configure_output(DSPI2_SCK, 1);
            /* SOUT (PF9) */
            _siu_configure_output(DSPI2_SOUT, 1);
            /* SIN (PF10) */
            _siu_configure_input(DSPI2_SIN, 1);
            /* CS0 (PF11) */
            _siu_configure_output(DSPI2_CS0, 1);

            break;

        case 3: /* DSPI3 - DSPI_D - TWRPI_SPI */
            /* SCK (PF12) */
            _siu_configure_output(DSPI3_SCK, 1);
            /* SOUT (PF13) */
            _siu_configure_output(DSPI3_SOUT, 1);
            /* SIN (PF14) */
            _siu_configure_input(DSPI3_SIN, 1);
            /* CS0 (PF15) */
            _siu_configure_output(DSPI3_CS0, 1);

            break;

        default:
            /* do nothing if bad dev_num was selected */
            return -1;
    }

    return MQX_OK;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_i2c_io_init
* Returned Value   : 0 for success, -1 for failure
* Comments         :
*    This function performs BSP-specific initialization related to I2C
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_i2c_io_init(uint_32 dev_num)
{
   switch (dev_num) {
      case 0: /* I2C_A*/
         /* SCL PE14*/
         _siu_configure_inout(I2C0_SCL, 1);
         /* SDA PE15*/
         _siu_configure_inout(I2C0_SDA, 1);
         break;
      case 1: /* I2C_B */
         /* SCL PG4*/
         _siu_configure_inout(I2C1_SCL, 2);
         /* SDA PG5*/
         _siu_configure_inout(I2C1_SDA, 2);
         break;
      case 2: /* I2C_C */
         /* SCL PG2*/
         _siu_configure_inout(I2C2_SCL, 2);
         /* SDA PG3*/
         _siu_configure_inout(I2C2_SDA, 2);
         break;
      case 3: /* I2C_D */
         /* SCL PD10*/
         _siu_configure_inout(I2C3_SCL, 3);
         /* SDA  PD11*/
         _siu_configure_inout(I2C3_SDA, 3);
         break;
      default:
         return -1;
   }

   return 0;
}

/*FUNCTION*-------------------------------------------------------------------
 *
 * Function Name    : _bsp_flexcan_io_init
 * Returned Value   : 0 for success, -1 for failure
 * Comments         :
 *    This function performs BSP-specific initialization related to can
 *
 *END*----------------------------------------------------------------------*/

_mqx_int _bsp_flexcan_io_init(uint_32 dev_num)
{
    switch (dev_num) {
        case 0: /* FlexCAN_A */
            /* TX */
            _siu_configure_output(FlexCAN0_TX, 1); 
            /* RX */
            _siu_configure_input(FlexCAN0_RX, 1);
            break;
        case 1: /* FlexCAN_B */
            /* TX */
            _siu_configure_output(FlexCAN1_TX, 1); 
            /* RX */
            _siu_configure_input(FlexCAN1_RX, 1);
            break;
        case 2: /* FlexCAN_C */
            /* TX */
            _siu_configure_output(FlexCAN2_TX, 1); 
            /* RX */
            _siu_configure_input(FlexCAN2_RX, 1);
            break;
        case 3: /* FlexCAN_D */
            /* TX */
            _siu_configure_output(FlexCAN3_TX, 1); 
            /* RX */
            _siu_configure_input(FlexCAN3_RX, 1);
            break;
        case 4: /* FlexCAN_E */
            /* TX */
            _siu_configure_output(FlexCAN4_TX, 1); 
            /* RX */
            _siu_configure_input(FlexCAN4_RX, 1);
            break;
        case 5: /* FlexCAN_F */
            /* TX */
            _siu_configure_output(FlexCAN5_TX, 1); 
            /* RX */
            _siu_configure_input(FlexCAN5_RX, 1);
            break;
        default:
            return IO_ERROR;
    }
    
    return MQX_OK;
}  

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_adc_io_init
* Returned Value   : 0 for success, -1 for failure
* Comments         :
*    This function performs BSP-specific initialization related to ADC
*
*END*----------------------------------------------------------------------*/

_mqx_int _bsp_adc_io_init(uint_32 input)
{
   uint_32 pin,device, channel;
   uint_8  i = 0;
   
   device  = ADC_DEVICE(input);
   channel = ADC_CHANNEL(input);
   if ((device > MPXNXX_ADC_NUM_DEVICES) || (channel > MPXN20_ADC_NUM_CHANNELS)) {
      return -1;
   }

   pin = adc_pin_map[device][channel];
   if (pin) {
      _siu_configure_analog_input(pin, 0);
   }
   return MQX_OK;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_enet_io_init
* Returned Value   : 0 for success, -1 for failure
* Comments         :
*    This function performs BSP-specific initialization related to enet
*
*END*----------------------------------------------------------------------*/

_mqx_int _bsp_enet_io_init(uint_32 dev_num)
{
    if (dev_num) {
        return -1;
    }    
    
    _siu_configure_output(FEC_TXD0, 2);    
    _siu_configure_output(FEC_TXD1, 2);    
    _siu_configure_output(FEC_TXD2, 2);
    _siu_configure_output(FEC_TXD3, 2);
    
    _siu_configure_output(FEC_TX_EN, 2);
    _siu_configure_output(FEC_TX_ER, 2);
    
    _siu_configure_input(FEC_TX_CLK, 2); 
    
    
    _siu_configure_input(FEC_RXD0, 2);
    _siu_configure_input(FEC_RXD1, 2);
    _siu_configure_input(FEC_RXD2, 2);
    _siu_configure_input(FEC_RXD3, 2);
    _siu_configure_input(FEC_RX_DV, 2);
    _siu_configure_input(FEC_RX_ER, 2);
        
    _siu_configure_input(FEC_RX_CLK, 2);
  
    
    _siu_configure_input(FEC_CRS, 2);
    _siu_configure_input(FEC_COL, 2);
    
    _siu_configure_output(FEC_MDC, 2);
    // MDIO is bidirectional
    _siu_configure_inout(FEC_MDIO, 2); 

    return 0;
}
