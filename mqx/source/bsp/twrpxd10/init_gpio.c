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
* $Date    : Sep-26-2012$
*
* Comments:
*
*   This file contains board-specific pin initialization functions.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>

#include <MPXD10_cw.h>

/* PCTL# Registers for Enable/Disable ClockGate */
#define CLOCK_GATE_PCTLREG_DSPI_0         (4)
#define CLOCK_GATE_PCTLREG_DSPI_1         (5)
#define CLOCK_GATE_PCTLREG_QUADDSPI_0     (10)
#define CLOCK_GATE_PCTLREG_FLEXCAN_0      (16)
#define CLOCK_GATE_PCTLREG_FLEXCAN_1      (17)
#define CLOCK_GATE_PCTLREG_ADC_0          (32)
#define CLOCK_GATE_PCTLREG_I2C_0          (44)
#define CLOCK_GATE_PCTLREG_I2C_1          (45)
#define CLOCK_GATE_PCTLREG_I2C_2          (46)
#define CLOCK_GATE_PCTLREG_I2C_3          (47)
#define CLOCK_GATE_PCTLREG_LINFLEX_0      (48)
#define CLOCK_GATE_PCTLREG_LINFLEX_1      (49)
#define CLOCK_GATE_PCTLREG_SIUL           (68)
#define CLOCK_GATE_PCTLREG_EMIOS_0        (72)
#define CLOCK_GATE_PCTLREG_EMIOS_1        (73)
#define CLOCK_GATE_PCTLREG_RTCAPI         (91)
#define CLOCK_GATE_PCTLREG_PITRTI         (92)


static const uint_16 adc_pin_map[ADC_NUM_DEVICES][ADC_HW_CHANNELS] = {
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
      ADC0_AN13,
      ADC0_AN14,
      ADC0_AN15,
   }
};



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
    SIU.PCR[pin].B.SME=1;
    SIU.PCR[pin].B.PA=padfn;
}

static _siul_configure_inout(uint_32 pin, uint_32 opadfn)
{
    _siul_configure_input(pin, 1);
    _siul_configure_output(pin, opadfn);
    SIU.PCR[pin].B.ODE=1;
}

static _me_set_clock_gate(uint_32 clkgate_reg, uint_32 is_set)
{
  /* Note that:  only set clock get for DRUN mode */
  ME.RUNPC[0].B.DRUN = 1; /* RUNPC0 ACTIVE  */
  ME.RUNPC[1].B.DRUN = 0; /* RUNPC1 frozen clock with clock gate */
  //ME.PCTL[48+LINFlex_Index].B.LP_CFG = 1; /* Select gate clock for LINFlex0 */
  ME.PCTL[clkgate_reg].B.RUN_CFG = (is_set == 1) ? 0 : 1;
  //RE enter the DRUN mode, to update the configuration
  ME.MCTL.R = 0x30005AF0; // Mode & Key
  ME.MCTL.R = 0x3000A50F; // Mode & Key inverted
  while (ME.IS.B.I_MTC != 1) {
  } // Wait until transition completed
  ME.IS.B.I_MTC = 1;
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
  case 0:
    _siul_configure_output(LIN0_TXD, 1);
    _siul_configure_pull(LIN0_TXD, 1);
    
    _siul_configure_input(LIN0_RXD, 1);
    _siul_configure_pull(LIN0_RXD, 1);
    _me_set_clock_gate(CLOCK_GATE_PCTLREG_LINFLEX_0, 1);
    break;
  case 1:
    _siul_configure_output(LIN1_TXD, 1);
    _siul_configure_pull(LIN1_TXD, 1);
    
    _siul_configure_input(LIN1_RXD, 1);
    _siul_configure_pull(LIN1_RXD, 1);
    _me_set_clock_gate(CLOCK_GATE_PCTLREG_LINFLEX_1, 1);
    break;
  
  default:
    return -1;
  }

  return MQX_OK;
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
            /* SCK (PB9) */
            _siul_configure_output(DSPI0_SCK, 1);
            /* SOUT (PB8) */
            _siul_configure_output(DSPI0_SOUT, 1);
            /* SIN (PB7) */
            _siul_configure_input(DSPI0_SIN, 1);
            /* CS0 (PH4) */
            _siul_configure_output(DSPI0_CS0, 1);
            _me_set_clock_gate(CLOCK_GATE_PCTLREG_DSPI_0, 1);
            break;

        case 1: /* DSPI1 - DSPI_B */
            /* SCK (PB4) */
            _siul_configure_output(DSPI1_SCK, 1);       
            /* SOUT (PB5) */
            _siul_configure_output(DSPI1_SOUT, 1); 
            /* SIN (PB6) */
            _siul_configure_input(DSPI1_SIN, 1);
            /* CS0 (PC13) */
            _siul_configure_output(DSPI1_CS0, 3);
            _me_set_clock_gate(CLOCK_GATE_PCTLREG_DSPI_1, 1);                        
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
         /* SCL PF7*/
         _siul_configure_inout(I2C0_SCL, 1);
         /* SDA PF6*/
         _siul_configure_inout(I2C0_SDA, 1);
         _me_set_clock_gate(CLOCK_GATE_PCTLREG_I2C_0, 1);
         break;
      case 1: /* I2C_B */
         /* SCL PF9*/
         _siul_configure_inout(I2C1_SCL, 2);
         /* SDA PF8*/
         _siul_configure_inout(I2C1_SDA, 2);
         _me_set_clock_gate(CLOCK_GATE_PCTLREG_I2C_1, 1);
         break;
      case 2: /* I2C_C */
         /* SCL PA8*/
         _siul_configure_inout(I2C2_SCL, 2);
         /* SDA PA9*/
         _siul_configure_inout(I2C2_SDA, 2);
         _me_set_clock_gate(CLOCK_GATE_PCTLREG_I2C_2, 1);
         break;
      case 3: /* I2C_D */
         /* SCL PG0*/
         _siul_configure_inout(I2C3_SCL, 3);
         /* SDA  PG1*/
         _siul_configure_inout(I2C3_SDA, 3);
         _me_set_clock_gate(CLOCK_GATE_PCTLREG_I2C_3, 1);
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
            _siul_configure_output(FlexCAN0_TX, 1); 
            /* RX */
            _siul_configure_input(FlexCAN0_RX, 1);
            _me_set_clock_gate(CLOCK_GATE_PCTLREG_FLEXCAN_0, 1);
            break;
        case 1: /* FlexCAN_B */
            /* TX */
            _siul_configure_output(FlexCAN1_TX, 1); 
            /* RX */
            _siul_configure_input(FlexCAN1_RX, 1);
            _me_set_clock_gate(CLOCK_GATE_PCTLREG_FLEXCAN_1, 1);
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
   if ( (device > ADC_NUM_DEVICES) || (channel > ADC_HW_CHANNELS) )
       return -1; 
   pin = adc_pin_map[device][channel-32];
   if (pin) {
      _siul_configure_analog_input(pin);
   }
   _me_set_clock_gate(CLOCK_GATE_PCTLREG_ADC_0, 1);
   return MQX_OK;
}
/* EOF */

