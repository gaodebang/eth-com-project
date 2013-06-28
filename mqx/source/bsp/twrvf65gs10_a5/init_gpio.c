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
* $FileName: init_gpio.c$
* $Version : 3.8.5.0$
* $Date    : Aug-31-2012$
*
* Comments:
*
*   This file contains board-specific pin initialization functions.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include <vybrid.h>

static const uint_16 adc_pin_map[ADC_NUM_DEVICES][ADC_HW_CHANNELS] = {
   {
      LWADC0_AN0,
      LWADC0_AN1,
      LWADC0_AN2,
      LWADC0_AN3,
      LWADC0_AN4,
      LWADC0_AN5,
      LWADC0_AN6,
      LWADC0_AN7,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
   },
      {
      LWADC1_AN0,
      LWADC1_AN1,
      LWADC1_AN2,
      LWADC1_AN3,
      LWADC1_AN4,
      LWADC1_AN5,
      LWADC1_AN6,
      LWADC1_AN7,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
      LWADC_SIG_NC,
   }
};

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
    _mqx_uint dev_num
)
{
    switch (dev_num)
    {
        case 0:
            IOMUXC_RGPIO(41) = 
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(2) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1); // PTB19.CS
            
            IOMUXC_RGPIO(42) = 
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1); // PTB20.SIN
              
            IOMUXC_RGPIO(43) = 
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(2) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1); // PTB21.SOUT
              
            IOMUXC_RGPIO(44) = 
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(2) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1); // PTB22.SCK
                
            SPI0_MCR &= ~((0x3 << 28) | (0x1 << 14)); // DSPI to 0x00 & enables module clock
              
            break;
        default:
            /* do nothing if bad dev_num was selected */
            return -1;
    }
    return MQX_OK;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_esdhc_io_init
* Returned Value   : MQX_OK or -1
* Comments         :
*    This function performs BSP-specific initialization related to ESDHC
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_esdhc_io_init 
(
    _mqx_uint dev_num,
    _mqx_uint value
) 
{
    switch (dev_num)
    {
        case 1:
            /* Set clock */
            CCM_CSCMR1 |= CCM_CSCMR1_ESDHC1_CLK_SEL(3);
            CCM_CSCDR2  = (CCM_CSCDR2 & ~((uint_32)CCM_CSCDR2_ESDHC1_DIV_MASK)) | CCM_CSCDR2_ESDHC1_DIV(2); /* div 3 */
            CCM_CSCDR2 |= CCM_CSCDR2_ESDHC1_EN_MASK;
            
            /* SDHC1 CLK  */
            IOMUXC_RGPIO(14) = 
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(2) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5);
            /* SDHC1 CMD  */
            IOMUXC_RGPIO(15) = 
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(2) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5);
            /* SDHC1 DAT0 */
            IOMUXC_RGPIO(16) = 
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(2) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5);
            /* SDHC1 DAT1 */
            IOMUXC_RGPIO(17) = 
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(2) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5);
            /* SDHC1 DAT2 */
            IOMUXC_RGPIO(18) = 
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(2) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5);
            /* SDHC1 DAT3 */
            IOMUXC_RGPIO(19) = 
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(2) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5);
            
            break;
        default:
            /* Do nothing if bad dev_num was selected */
            return -1;
    }

    return MQX_OK;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_i2c_io_init
* Returned Value   : MQX_OK or -1
* Comments         :
*    This function performs BSP-specific initialization related to I2C
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_i2c_io_init
(
    _mqx_uint dev_num
 )
{
    switch (dev_num) {
    case 0: // I2C0
            IOMUXC_RGPIO(36) = 	
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7)  |
                IOMUXC_SW_MUX_CTL_PAD_ODE(1)      |
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3)|
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(2);
            
            IOMUXC_RGPIO(37) = 	
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7)  |
                IOMUXC_SW_MUX_CTL_PAD_ODE(1)      |
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3)|
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(2);
        
        IOMUXC_I2C0_IPP_SCL_IND_SELECT_INPUT = IOMUXC_I2C0_IPP_SCL_IND_SELECT_INPUT_DAISY(1);   // ALT2 - PAD_36
        IOMUXC_I2C0_IPP_SDA_IND_SELECT_INPUT = IOMUXC_I2C0_IPP_SDA_IND_SELECT_INPUT_DAISY(1);   // ALT2 - PAD_37
        break;
    case 1: // I2C1
            IOMUXC_RGPIO(38) = 	
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7)  |
                IOMUXC_SW_MUX_CTL_PAD_ODE(1)      |
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3)|
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(2);
            
            IOMUXC_RGPIO(39) = 	
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7)  |
                IOMUXC_SW_MUX_CTL_PAD_ODE(1)      |
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3)|
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(2);

        IOMUXC_I2C1_IPP_SCL_IND_SELECT_INPUT = IOMUXC_I2C1_IPP_SCL_IND_SELECT_INPUT_DAISY(1);   // ALT2 - PAD_38
        IOMUXC_I2C1_IPP_SDA_IND_SELECT_INPUT = IOMUXC_I2C1_IPP_SDA_IND_SELECT_INPUT_DAISY(1);   // ALT2 - PAD_39
        break;
    case 2: // I2C2
            IOMUXC_RGPIO(12) = 	
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7)  |
                IOMUXC_SW_MUX_CTL_PAD_ODE(1)      |
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3)|
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(6);
            
            IOMUXC_RGPIO(13) = 	
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7)  |
                IOMUXC_SW_MUX_CTL_PAD_ODE(1)      |
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3)|
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(6);
            
        IOMUXC_I2C2_IPP_SCL_IND_SELECT_INPUT = IOMUXC_I2C2_IPP_SCL_IND_SELECT_INPUT_DAISY(0);   // ALT6 - PAD_12
        IOMUXC_I2C2_IPP_SDA_IND_SELECT_INPUT = IOMUXC_I2C2_IPP_SDA_IND_SELECT_INPUT_DAISY(0);   // ALT6 - PAD_13
        break;
    case 3: // I2C3
            IOMUXC_RGPIO(20) = 	
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7)  |
                IOMUXC_SW_MUX_CTL_PAD_ODE(1)      |
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3)|
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5); // ALT5 - PAD_20
            
            IOMUXC_RGPIO(21) = 	
                IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1)  |
                IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7)  |
                IOMUXC_SW_MUX_CTL_PAD_ODE(1)      |
                IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3)|
                IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5);  // ALT5 - PAD_21
        break;
    default:
        break;
    }
    return MQX_OK;    
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_ssi_io_init
* Returned Value   : MQX_OK or -1
* Comments         :
*    This function performs BSP-specific initialization related to SSI
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_ssi_io_init
(
    uint_8 dev_num
)
{
    return MQX_OK;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_enet_io_init
* Returned Value   : MQX_OK or -1
* Comments         :
*    This function performs BSP-specific initialization related to ENET
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_enet_io_init
(
    _mqx_uint device
)
{
    // ENET RMII clk - get RMII external clk from pad
    IOMUXC_RGPIO(0) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;  //RMII_CLKIN  

    // clock
    CCM_CSCMR2 &= ~CCM_CSCMR2_RMII_CLK_SEL_MASK;
    CCM_CSCMR2 |= 0 << CCM_CSCMR2_RMII_CLK_SEL_SHIFT;  // RMII_CLK
    CCM_CSCDR1 |= CCM_CSCDR1_RMII_CLK_EN_MASK;      // enable RMII_CLK_EN

    // IOMUX

    /*  
    ** NOTE: 
    **  TWR-VF65GS10 is using TWR-SER2 for PHY, which is connected by one MDIO channel (ch.0) thus pins for MDIO on ENET1 are not used. 
    */
    
    //IOMUXC_SW_MUX_CTL_PAD_PAD_45 = 0x00102400;      // RMII0_MDC
    IOMUXC_RGPIO(45) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6);
    //IOMUXC_SW_MUX_CTL_PAD_PAD_46 = 0x00102400;      // RMII0_MDIO
    IOMUXC_RGPIO(46) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
    
    switch (device)
    {
        case 0:
            
            //IOMUXC_SW_MUX_CTL_PAD_PAD_47 = 0x00103400;      // RMII0_CRS_DV
            IOMUXC_RGPIO(47) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            //IOMUXC_SW_MUX_CTL_PAD_PAD_48 = 0x00103400;      // RMII0_RXD1
            IOMUXC_RGPIO(48) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            //IOMUXC_SW_MUX_CTL_PAD_PAD_49 = 0x00103400;      // RMII0_RXD0
            IOMUXC_RGPIO(49) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            //IOMUXC_SW_MUX_CTL_PAD_PAD_50 = 0x00103400;      // RMII0_RXER
            IOMUXC_RGPIO(50) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            
            //IOMUXC_SW_MUX_CTL_PAD_PAD_51 = 0x00103400;      // RMII0_TXD1
            IOMUXC_RGPIO(51) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;
            //IOMUXC_SW_MUX_CTL_PAD_PAD_52 = 0x00103400;      // RMII0_TXD0
            IOMUXC_RGPIO(52) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;
            //IOMUXC_SW_MUX_CTL_PAD_PAD_53 = 0x00103400;      // RMII0_TXEN
            IOMUXC_RGPIO(53) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;
            break;
        
        case 1:

            //IOMUXC_SW_MUX_CTL_PAD_PAD_56 = 0x00103400;      // RMII1_CRS_DV
            IOMUXC_RGPIO(56) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            //IOMUXC_SW_MUX_CTL_PAD_PAD_57 = 0x00103400;      // RMII1_RXD1
            IOMUXC_RGPIO(57) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            //IOMUXC_SW_MUX_CTL_PAD_PAD_58 = 0x00103400;      // RMII1_RXD0
            IOMUXC_RGPIO(58) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            //IOMUXC_SW_MUX_CTL_PAD_PAD_59 = 0x00103400;      // RMII1_RXER
            IOMUXC_RGPIO(59) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            
            //IOMUXC_SW_MUX_CTL_PAD_PAD_60 = 0x00103400;      // RMII1_TXD1
            IOMUXC_RGPIO(60) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;
            //IOMUXC_SW_MUX_CTL_PAD_PAD_61 = 0x00103400;      // RMII1_TXD0
            IOMUXC_RGPIO(61) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;
            //IOMUXC_SW_MUX_CTL_PAD_PAD_62 = 0x00103400;      // RMII1_TXEN
            IOMUXC_RGPIO(62) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(6) | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;
            break;
        
        default:
            return (-1);
    }
    
    return MQX_OK;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_usb_iomux_init
* Returned Value   : MQX_OK or -1
* Comments         :
*    This function performs BSP-specific initialization related to SSI
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_usb_iomux_init
(
    uint_8 dev_num
 )
{

  return MQX_OK;
}


_mqx_int  _bsp_uart_io_init
(
    uint_8 dev_num
)
{

  return MQX_OK;
}

_mqx_int _bsp_gpio_io_init 
(
    void
) 
{
    return MQX_OK;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_serial_io_init
* Returned Value   : MQX_OK for success, -1 for failure
* Comments         :
*    This function performs BSP-specific initialization related to serial
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_serial_io_init
(
    /* [IN] Serial device number */
    _mqx_uint dev_num,
    
    /* [IN] Required functionality */
    _mqx_uint flags
)
{
    switch (dev_num) {
    case 0:
        IOMUXC_RGPIO(32) = 0x001011A2;
        IOMUXC_RGPIO(33) = 0x001011A1;
        break;
    case 1:
        IOMUXC_SCI_FLX1_IPP_IND_SCI_RX_SELECT_INPUT = 0x00000000;
        IOMUXC_SCI_FLX1_IPP_IND_SCI_TX_SELECT_INPUT = 0x00000000;
        IOMUXC_RGPIO(26) = 0x002011A2;
        IOMUXC_RGPIO(27) = 0x002011A1;
        break;
    case 2: // SCI2
        IOMUXC_SCI_FLX2_IPP_IND_SCI_RX_SELECT_INPUT = 0x00000000;
        IOMUXC_SCI_FLX2_IPP_IND_SCI_TX_SELECT_INPUT = 0x00000000;
        IOMUXC_RGPIO(28) = 0x007021A2;
        IOMUXC_RGPIO(29) = 0x007021A1;
    }
    return MQX_OK;
}

_mqx_int _bsp_serial_rts_init
(
    _mqx_uint device_index
)
{
    return MQX_OK;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_sai_io_init
* Returned Value   : 0 for success, -1 for failure
* Comments         :
*    This function performs BSP-specific initialization related to SAI
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_sai_io_init
(
    _mqx_uint dev_num
)
{
    switch(dev_num)
    {
        case 0: // SAI0
            CCM_CSCMR1 = (CCM_CSCMR1 & ~CCM_CSCMR1_SAI0_CLK_SEL_MASK) | CCM_CSCMR1_SAI0_CLK_SEL(3);
            CCM_CSCDR1 = (CCM_CSCMR1 & ~CCM_CSCDR1_SAI0_DIV_MASK) | CCM_CSCDR1_SAI0_DIV(0x0f);
            CCM_CSCDR1 |= CCM_CSCDR1_SAI0_EN_MASK;
            
            // RX_BCLK
            //IOMUXC_SW_MUX_CTL_PAD_PAD_11 = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;

            // RX_DATA
            //IOMUXC_SW_MUX_CTL_PAD_PAD_12 = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            
            // RX_SYNC 
            //IOMUXC_SW_MUX_CTL_PAD_PAD_13 = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            
            // TX_SYNC
            IOMUXC_RGPIO(98) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_PKE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_PUE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;
            
            // TX_DATA
            IOMUXC_RGPIO(96) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_PKE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_PUE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;

            // TX_BCLK
            IOMUXC_RGPIO(93) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) | \
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_PKE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_PUE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;
                          
            break;
        case 2:
            // RX_BCLK
            IOMUXC_RGPIO(11) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;

            // RX_DATA
            IOMUXC_RGPIO(12) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            
            // RX_SYNC 
            IOMUXC_RGPIO(13) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5) | IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK;
            
            // TX_SYNC
            IOMUXC_RGPIO(9) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5) | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_PKE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_PUE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;
            
            // TX_DATA
            IOMUXC_RGPIO(8) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5) | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) |
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_PKE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_PUE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;

            // TX_BCLK
            IOMUXC_RGPIO(6) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(5) | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(7) | 
                IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(1) | IOMUXC_SW_MUX_CTL_PAD_PAD_PKE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_PUE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;

//            IOMUXC_SW_MUX_CTL_PAD_PAD_3 |= IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(2);     // alt2 EXT_AUDIO_MCLK
//            IOMUXC_SW_MUX_CTL_PAD_PAD_5 |= IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(2);     // alt6 EXT_AUDIO_MCLK
            
            // EXT_AUDIO_MCLK
            IOMUXC_RGPIO(40) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(2) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(3);

            break;
        default:
            break;
    }
    
    return MQX_OK;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_usb_host_io_init
* Returned Value   : MQX_OK or -1
* Comments         :
*    This function performs BSP-specific initialization related to USB in host mode
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_usb_host_io_init
(
    struct usb_host_if_struct *usb_if
)
{
  /* Setup clocking and PLL */
  CCM_CLPCR &= ~CCM_CLPCR_SBYOS_MASK; //on-chip oscillator on (by default after reset)
  //Setup 3V0 regulator
  Anadig_REG_3P0 |= Anadig_REG_3P0_ENABLE_BO_MASK;
  Anadig_REG_3P0 |= Anadig_REG_3P0_ENABLE_LINREG_MASK;
  while(!( Anadig_REG_3P0 & Anadig_REG_3P0_OK_VDD3P0_MASK))
  { /* wait till regulator output is in steady state */ }


  if (usb_if->HOST_INIT_PARAM == &_ehci0_host_init_param) {
    /* For USB0 */
    // enable USB0 clock gate
    CCM_CCGR1 |= CCM_CCGR1_CG4(0x3);

    Anadig_PLL3_CTRL &= ~Anadig_PLL3_CTRL_BYPASS_CLK_SRC_MASK; //the source of clock is 24MHz XTAL CLK
    Anadig_PLL3_CTRL &= ~Anadig_PLL3_CTRL_BYPASS_MASK; //do not bypass the PLL
    Anadig_PLL3_CTRL |= Anadig_PLL3_CTRL_POWER_MASK; //power the USB0 PLL
    Anadig_PLL3_CTRL |= Anadig_PLL3_CTRL_EN_USB_CLKS_MASK; //start clocking PHY UTMI peripeheral

    /* Setup PHY0 peripheral with UTMI interface */
    USBPHY0_CTRL_CLR = USBPHY_CTRL_SFTRST_MASK | USBPHY_CTRL_CLKGATE_MASK; //leave the reset state on PHY and run clocks
    USBPHY0_DEBUG_CLR = USBPHY_DEBUG_CLKGATE_MASK;
    USBPHY0_CTRL_SET = USBPHY_CTRL_ENUTMILEVEL3_MASK | USBPHY_CTRL_ENUTMILEVEL2_MASK;

    USBPHY0_PWD = 0; //switch PHY from standby to normal operation

    /* Setup PTA16 (control of USB0 VBUS) to power the bus */
    //GPIO0_PSOR = 1 << 6; //set output level of PTA16 to "1" 
    //IOMUXC_RGPIO(6) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(0) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(0) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(3) | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;

    /* Setup PTD6 (control of USB0 VBUS) to power the bus */
    GPIO2_PSOR = 1 << 21; //set output level of PTD6 to "1" 
    IOMUXC_RGPIO(85) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(0) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(0) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(3) | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;

    USBC0_CTRL |= USBC_CTRL_PM_MASK;
  }
  else if (usb_if->HOST_INIT_PARAM == &_ehci1_host_init_param) {
    /* For USB1 */
    // enable USB1 clock gate
    CCM_CCGR7 |= CCM_CCGR7_CG4(0x3);

    Anadig_PLL7_CTRL &= ~Anadig_PLL7_CTRL_BYPASS_CLK_SRC_MASK; //the source of clock is 24MHz XTAL CLK
    Anadig_PLL7_CTRL &= ~Anadig_PLL7_CTRL_BYPASS_MASK; //do not bypass the PLL
    Anadig_PLL7_CTRL |= Anadig_PLL7_CTRL_POWER_MASK; //power the USB1 PLL
    Anadig_PLL7_CTRL |= Anadig_PLL7_CTRL_EN_USB_CLKS_MASK; //power the USB1 PHY
  
    /* Setup PHY1 peripheral with UTMI interface */
    USBPHY1_CTRL_CLR = USBPHY_CTRL_SFTRST_MASK | USBPHY_CTRL_CLKGATE_MASK; //leave the reset state on PHY and run clocks
    USBPHY1_DEBUG_CLR = USBPHY_DEBUG_CLKGATE_MASK;
    USBPHY1_CTRL_SET = USBPHY_CTRL_ENUTMILEVEL3_MASK | USBPHY_CTRL_ENUTMILEVEL2_MASK;

    USBPHY1_PWD = 0; //switch PHY from standby to normal operation

    /* Setup PTA24 (control of USB1 VBUS) to power the bus */
    //GPIO0_PSOR = 1 << 24; //set output level of PTA24 to "1"
    //IOMUXC_RGPIO(14) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(0) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(0) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(3) | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;

    /* Setup PTD13 (control of USB1 VBUS) to power the bus */
    GPIO2_PSOR = 1 << 28; //set output level of PTD13 to "1"
    IOMUXC_RGPIO(92) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(0) | IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(0) | IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK | IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(3) | IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK;

    USBC1_CTRL |= USBC_CTRL_PM_MASK;
  }
  else {
    /* Return unknown interface */
    return IO_ERROR;
  }

  return MQX_OK;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_usb_dev_io_init
* Returned Value   : MQX_OK or -1
* Comments         :
*    This function performs BSP-specific initialization related to USB in device mode
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_usb_dev_io_init
(
    struct usb_dev_if_struct *usb_if
)
{
  /* Setup clocking and PLL */
  CCM_CLPCR &= ~CCM_CLPCR_SBYOS_MASK; //on-chip oscillator on (by default after reset)
  //Setup 3V0 regulator
  Anadig_REG_3P0 |= Anadig_REG_3P0_ENABLE_BO_MASK;
  Anadig_REG_3P0 |= Anadig_REG_3P0_ENABLE_LINREG_MASK;
  while(!( Anadig_REG_3P0 & Anadig_REG_3P0_OK_VDD3P0_MASK))
  { /* wait till regulator output is in steady state */ }


  if (usb_if->DEV_INIT_PARAM == &_ehci0_dev_init_param) {
    /* For USB0 */
    // enable USB0 clock gate
    CCM_CCGR1 |= CCM_CCGR1_CG4(0x3);

    Anadig_PLL3_CTRL &= ~Anadig_PLL3_CTRL_BYPASS_CLK_SRC_MASK; //the source of clock is 24MHz XTAL CLK
    Anadig_PLL3_CTRL &= ~Anadig_PLL3_CTRL_BYPASS_MASK; //do not bypass the PLL
    Anadig_PLL3_CTRL |= Anadig_PLL3_CTRL_POWER_MASK; //power the USB0 PLL
    Anadig_PLL3_CTRL |= Anadig_PLL3_CTRL_EN_USB_CLKS_MASK; //start clocking PHY UTMI peripeheral

    /* Setup PHY0 peripheral with UTMI interface */
    USBPHY0_CTRL_CLR = USBPHY_CTRL_SFTRST_MASK | USBPHY_CTRL_CLKGATE_MASK; //leave the reset state on PHY and run clocks
    USBPHY0_DEBUG_CLR = USBPHY_DEBUG_CLKGATE_MASK;
    USBPHY0_CTRL_SET = USBPHY_CTRL_ENUTMILEVEL3_MASK | USBPHY_CTRL_ENUTMILEVEL2_MASK;

    USBPHY0_PWD = 0; //switch PHY from standby to normal operation

    USBC0_CTRL |= USBC_CTRL_PM_MASK;
  }
  else if (usb_if->DEV_INIT_PARAM == &_ehci1_dev_init_param) {
    /* For USB1 */
    // enable USB1 clock gate
    CCM_CCGR7 |= CCM_CCGR7_CG4(0x3);

    Anadig_PLL7_CTRL &= ~Anadig_PLL7_CTRL_BYPASS_CLK_SRC_MASK; //the source of clock is 24MHz XTAL CLK
    Anadig_PLL7_CTRL &= ~Anadig_PLL7_CTRL_BYPASS_MASK; //do not bypass the PLL
    Anadig_PLL7_CTRL |= Anadig_PLL7_CTRL_POWER_MASK; //power the USB1 PLL
    Anadig_PLL7_CTRL |= Anadig_PLL7_CTRL_EN_USB_CLKS_MASK; //power the USB1 PHY
  
    /* Setup PHY1 peripheral with UTMI interface */
    USBPHY1_CTRL_CLR = USBPHY_CTRL_SFTRST_MASK | USBPHY_CTRL_CLKGATE_MASK; //leave the reset state on PHY and run clocks
    USBPHY1_DEBUG_CLR = USBPHY_DEBUG_CLKGATE_MASK;
    USBPHY1_CTRL_SET = USBPHY_CTRL_ENUTMILEVEL3_MASK | USBPHY_CTRL_ENUTMILEVEL2_MASK;

    USBPHY1_PWD = 0; //switch PHY from standby to normal operation

    USBC1_CTRL |= USBC_CTRL_PM_MASK;
  }
  else {
    /* Return unknown interface */
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

   
   device  = ADC_DEVICE(input);
   channel = ADC_CHANNEL(input);

   if ( (device > ADC_NUM_DEVICES) || (channel > ADC_HW_CHANNELS) )
       return -1; 
   pin = adc_pin_map[device][channel];
   if(pin)
   {
       if(((device==0)&&((channel <=3 )&&(channel >= 0))) || ((device==1)&&((channel <=3 )&&(channel >= 2))))
       {
            IOMUXC_RGPIO(pin) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(2);
       }
       if(((device==0)&&((channel ==4 ))) || ((device==1)&&((channel ==0 )||(channel == 1)||(channel == 4)||(channel == 7))))
       {
            IOMUXC_RGPIO(pin) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(3);
       }
       if(((device==0)&&((channel <=7 )||(channel >= 5))) || ((device==1)&&((channel <=6 )||(channel >= 5))))
       {
            IOMUXC_RGPIO(pin) = IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(6);
       }
   }

   return MQX_OK;
}