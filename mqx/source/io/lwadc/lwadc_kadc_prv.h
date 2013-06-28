/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2011 Embedded Access Inc
* All Rights Reserved
*
**************************************************************************** 
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
* $FileName: lwadc_kadc_prv.h$
* $Version : 3.8.1.0$
* $Date    : Sep-21-2012$
*
* Comments:
*
*   CPU specific LWADC driver header file
*
*END************************************************************************/

#ifndef __lwadc_kadc_prv_h__
#define __lwadc_kadc_prv_h__

#ifdef __cplusplus
extern "C" {
#endif
#define ADC_MAX_FREQUENCY 5000000 /* 5 MHz for ADC clock source is maximum */

#ifndef ADC_CHANNELS_PER_ADC
    #define ADC_CHANNELS_PER_ADC (2)  /* one ADC can handle 2 channels */
#endif
#define ADC_MAX_HW_CHANNELS  ADC_CHANNELS_PER_ADC /* there is no sense to have more channels allocated */

#ifndef ADC_MAX_MODULES
    #error Define number of ADC peripheral modules on chip in BSP (<MQX>/source/bsp/<board_name>/<board_name>.h)
#endif

#ifndef ADC_MAX_SW_CHANNELS
    #define ADC_MAX_CHANNELS ADC_MAX_HW_CHANNELS
#else
    #if (ADC_MAX_HW_CHANNELS > ADC_MAX_SW_CHANNELS)
        #define ADC_MAX_CHANNELS ADC_MAX_SW_CHANNELS
    #else
        #define ADC_MAX_CHANNELS ADC_MAX_HW_CHANNELS
    #endif
#endif

#define LWADC_CFG2_ADLSTS_20             ADC_CFG2_ADLSTS(0)
#define LWADC_CFG2_ADLSTS_12             ADC_CFG2_ADLSTS(1)
#define LWADC_CFG2_ADLSTS_6              ADC_CFG2_ADLSTS(2)
#define LWADC_CFG2_ADLSTS_2              ADC_CFG2_ADLSTS(3)
#define LWADC_CFG2_ADLSTS_DEFAULT       (ADC_CFG2_ADLSTS_20)

#define LWADC_SC3_AVGS_4                 ADC_SC3_AVGS(0x00)
#define LWADC_SC3_AVGS_8                 ADC_SC3_AVGS(0x01)
#define LWADC_SC3_AVGS_16                ADC_SC3_AVGS(0x02)
#define LWADC_SC3_AVGS_32                ADC_SC3_AVGS(0x03)
#define LWADC_SC3_AVGE                   ADC_SC3_AVGS(0x04)
#define LWADC_SC3_ADCO                   ADC_SC3_AVGS(0x08)
#define LWADC_SC3_CALF                   ADC_SC3_AVGS(0x40)
#define LWADC_SC3_CAL                    ADC_SC3_AVGS(0x80)

#define LWADC_SC2_REFSEL_VREF            ADC_SC2_REFSEL(0x00)
#define LWADC_SC2_REFSEL_VALT            ADC_SC2_REFSEL(0x01)
#define LWADC_SC2_REFSEL_VBG             ADC_SC2_REFSEL(0x02)

#define LWADC_SC1_ADCH_DISABLED          ADC_SC1_ADCH(0x1F)

#define LWADC_CFG1_ADIV_1                ADC_CFG1_ADIV(0x00)
#define LWADC_CFG1_ADIV_2                ADC_CFG1_ADIV(0x01)
#define LWADC_CFG1_ADIV_4                ADC_CFG1_ADIV(0x02)
#define LWADC_CFG1_ADIV_8                ADC_CFG1_ADIV(0x03)

#define LWADC_CFG1_ADICLK_BUSCLK         ADC_CFG1_ADICLK(0x00)
#define LWADC_CFG1_ADICLK_BUSCLK2        ADC_CFG1_ADICLK(0x01)
#define LWADC_CFG1_ADICLK_ALTCLK         ADC_CFG1_ADICLK(0x02)
#define LWADC_CFG1_ADICLK_ADACK          ADC_CFG1_ADICLK(0x03)

extern pointer  _bsp_get_adc_base_address(_mqx_uint);

#ifdef __cplusplus
}
#endif

#endif

/* EOF */
