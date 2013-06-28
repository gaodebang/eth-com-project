/**HEADER********************************************************************
*
* Copyright (c) 2012 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2011 Embedded Access Inc
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
* $FileName: lwadc_mpxs30.h$
* $Version : 3.8.1.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   CPU specific ADC driver header file
*
*END************************************************************************/

#ifndef __lwadc_mpxs30_h__
#define __lwadc_mpxs30_h__

/*----------------------------------------------------------------------*/
/*
**                          CONSTANT DEFINITIONS
*/

#define ADC_HW_CHANNELS         16

#define ADC_INPUT_ADC0_AN0          ADC_INPUT(0,0)
#define ADC_INPUT_ADC0_AN1          ADC_INPUT(0,1)
#define ADC_INPUT_ADC0_AN2          ADC_INPUT(0,2)
#define ADC_INPUT_ADC0_AN3          ADC_INPUT(0,3)
#define ADC_INPUT_ADC0_AN4          ADC_INPUT(0,4)
#define ADC_INPUT_ADC0_AN5          ADC_INPUT(0,5)
#define ADC_INPUT_ADC0_AN6          ADC_INPUT(0,6)
#define ADC_INPUT_ADC0_AN7          ADC_INPUT(0,7)
#define ADC_INPUT_ADC0_AN8          ADC_INPUT(0,8)
#define ADC_INPUT_ADC0_AN9          ADC_INPUT(0,9)
#define ADC_INPUT_ADC0_AN10         ADC_INPUT(0,10)
#define ADC_INPUT_ADC0_AN11         ADC_INPUT(0,11)
#define ADC_INPUT_ADC0_AN12         ADC_INPUT(0,12)
#define ADC_INPUT_ADC0_AN13         ADC_INPUT(0,13)
#define ADC_INPUT_ADC0_AN14         ADC_INPUT(0,14)
#define ADC_INPUT_ADC0_AN15         ADC_INPUT(0,15)
#define ADC_INPUT_ADC0_PMU          ADC_INPUT_ADC0_AN9
#define ADC_INPUT_ADC0_VDD_LV_COR   ADC_INPUT_ADC0_AN10
#define ADC_INPUT_ADC0_TSENS        ADC_INPUT_ADC0_AN15

#define ADC_INPUT_ADC1_AN0          ADC_INPUT(1,0)
#define ADC_INPUT_ADC1_AN1          ADC_INPUT(1,1)
#define ADC_INPUT_ADC1_AN2          ADC_INPUT(1,2)
#define ADC_INPUT_ADC1_AN3          ADC_INPUT(1,3)
#define ADC_INPUT_ADC1_AN4          ADC_INPUT(1,4)
#define ADC_INPUT_ADC1_AN5          ADC_INPUT(1,5)
#define ADC_INPUT_ADC1_AN6          ADC_INPUT(1,6)
#define ADC_INPUT_ADC1_AN7          ADC_INPUT(1,7)
#define ADC_INPUT_ADC1_AN8          ADC_INPUT(1,8)
#define ADC_INPUT_ADC1_AN9          ADC_INPUT(1,9)
#define ADC_INPUT_ADC1_AN10         ADC_INPUT(1,10)
#define ADC_INPUT_ADC1_AN11         ADC_INPUT(1,11)
#define ADC_INPUT_ADC1_AN12         ADC_INPUT(1,12)
#define ADC_INPUT_ADC1_AN13         ADC_INPUT(1,13)
#define ADC_INPUT_ADC1_AN14         ADC_INPUT(1,14)
#define ADC_INPUT_ADC1_AN15         ADC_INPUT(1,15)
#define ADC_INPUT_ADC1_PMU          ADC_INPUT_ADC1_AN9
#define ADC_INPUT_ADC1_VDD_HV_PDI   ADC_INPUT_ADC1_AN10
#define ADC_INPUT_ADC1_VDD_HV_DRAM  ADC_INPUT_ADC1_AN15

#define ADC_INPUT_ADC2_AN0          ADC_INPUT(2,0)
#define ADC_INPUT_ADC2_AN1          ADC_INPUT(2,1)
#define ADC_INPUT_ADC2_AN2          ADC_INPUT(2,2)
#define ADC_INPUT_ADC2_AN3          ADC_INPUT(2,3)
#define ADC_INPUT_ADC2_AN9          ADC_INPUT(2,9)
#define ADC_INPUT_ADC2_AN10         ADC_INPUT(2,10)
#define ADC_INPUT_ADC2_AN11         ADC_INPUT(2,11)
#define ADC_INPUT_ADC2_AN12         ADC_INPUT(2,12)
#define ADC_INPUT_ADC2_AN13         ADC_INPUT(2,13)
#define ADC_INPUT_ADC2_AN14         ADC_INPUT(2,14)
#define ADC_INPUT_ADC2_AN15         ADC_INPUT(2,15)
#define ADC_INPUT_ADC2_PMU          ADC_INPUT_ADC2_AN9

#define ADC_INPUT_ADC3_AN0          ADC_INPUT(3,0)
#define ADC_INPUT_ADC3_AN1          ADC_INPUT(3,1)
#define ADC_INPUT_ADC3_AN2          ADC_INPUT(3,2)
#define ADC_INPUT_ADC3_AN3          ADC_INPUT(3,3)
#define ADC_INPUT_ADC3_AN9          ADC_INPUT(3,9)
#define ADC_INPUT_ADC3_AN10         ADC_INPUT(3,10)
#define ADC_INPUT_ADC3_AN11         ADC_INPUT(3,11)
#define ADC_INPUT_ADC3_AN12         ADC_INPUT(3,12)
#define ADC_INPUT_ADC3_AN13         ADC_INPUT(3,13)
#define ADC_INPUT_ADC3_AN14         ADC_INPUT(3,14)
#define ADC_INPUT_ADC3_AN15         ADC_INPUT(3,15)
#define ADC_INPUT_ADC3_PMU          ADC_INPUT_ADC3_AN9


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif