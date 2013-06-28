/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
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
* $FileName: lwadc_mpxd10.h$
* $Version : 3.8.1.0$
* $Date    : Sep-26-2012$
*
* Comments:
*
*   CPU specific ADC driver header file
*
*END************************************************************************/

#ifndef __lwadc_mpxd10_h__
#define __lwadc_mpxd10_h__

/*----------------------------------------------------------------------*/
/*
**                          CONSTANT DEFINITIONS
*/
#define ADC_HW_CHANNELS          72
#define ADC_NUM_DEVICES          1
#define ADC_RESOLUTION_DEFAULT   ADC_RESOLUTION_10BIT
#define ADC_ALL_CHANNEL_MASK     (0xffffffff)

#define ADC_INPUT_ADC0_AN32         ADC_INPUT(0,32)
#define ADC_INPUT_ADC0_AN33         ADC_INPUT(0,33)
#define ADC_INPUT_ADC0_AN34         ADC_INPUT(0,34)
#define ADC_INPUT_ADC0_AN35         ADC_INPUT(0,35)
#define ADC_INPUT_ADC0_AN36         ADC_INPUT(0,36)
#define ADC_INPUT_ADC0_AN37         ADC_INPUT(0,37)
#define ADC_INPUT_ADC0_AN38         ADC_INPUT(0,38)
#define ADC_INPUT_ADC0_AN39         ADC_INPUT(0,39)
#define ADC_INPUT_ADC0_AN40         ADC_INPUT(0,40)
#define ADC_INPUT_ADC0_AN41         ADC_INPUT(0,41)
#define ADC_INPUT_ADC0_AN42         ADC_INPUT(0,42)
#define ADC_INPUT_ADC0_AN43         ADC_INPUT(0,43)
#define ADC_INPUT_ADC0_AN44         ADC_INPUT(0,44)
#define ADC_INPUT_ADC0_AN45         ADC_INPUT(0,45)
#define ADC_INPUT_ADC0_AN46         ADC_INPUT(0,46)
#define ADC_INPUT_ADC0_AN47         ADC_INPUT(0,47)
#define ADC_INPUT_ADC0_AN48         ADC_INPUT(0,48)
#define ADC_INPUT_ADC0_AN49         ADC_INPUT(0,49)
#define ADC_INPUT_ADC0_AN50         ADC_INPUT(0,50)
#define ADC_INPUT_ADC0_AN51         ADC_INPUT(0,51)
#define ADC_INPUT_ADC0_AN52         ADC_INPUT(0,52)
#define ADC_INPUT_ADC0_AN53         ADC_INPUT(0,53)
#define ADC_INPUT_ADC0_AN54         ADC_INPUT(0,54)
#define ADC_INPUT_ADC0_AN55         ADC_INPUT(0,55)
#define ADC_INPUT_ADC0_AN56         ADC_INPUT(0,56)
#define ADC_INPUT_ADC0_AN57         ADC_INPUT(0,57)
#define ADC_INPUT_ADC0_AN58         ADC_INPUT(0,58)
#define ADC_INPUT_ADC0_AN59         ADC_INPUT(0,59)
#define ADC_INPUT_ADC0_AN60         ADC_INPUT(0,60)
#define ADC_INPUT_ADC0_AN61         ADC_INPUT(0,61)
#define ADC_INPUT_ADC0_AN62         ADC_INPUT(0,62)
#define ADC_INPUT_ADC0_AN63         ADC_INPUT(0,63)
#define ADC_INPUT_ADC0_AN64         ADC_INPUT(0,64)
#define ADC_INPUT_ADC0_AN65         ADC_INPUT(0,65)
#define ADC_INPUT_ADC0_AN66         ADC_INPUT(0,66)
#define ADC_INPUT_ADC0_AN67         ADC_INPUT(0,67)
#define ADC_INPUT_ADC0_AN68         ADC_INPUT(0,68)
#define ADC_INPUT_ADC0_AN69         ADC_INPUT(0,69)
#define ADC_INPUT_ADC0_AN70         ADC_INPUT(0,70)
#define ADC_INPUT_ADC0_AN71         ADC_INPUT(0,71)

#define ADC_INPUT_ADC0_PMU          ADC_INPUT_ADC0_AN41
#define ADC_INPUT_ADC0_VDD_LV_COR   ADC_INPUT_ADC0_AN42

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif

/* EOF */
