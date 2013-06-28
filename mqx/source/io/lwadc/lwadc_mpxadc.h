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
* $FileName: lwadc_mpxadc.h$
* $Version : 3.8.1.0$
* $Date    : Sep-26-2012$
*
* Comments:
*
*   CPU specific ADC driver header file
*
*END************************************************************************/

#ifndef __lwadc_mpxadc_h__
#define __lwadc_mpxadc_h__

/*----------------------------------------------------------------------*/
/*
**                          CONSTANT DEFINITIONS
*/

#ifdef __cplusplus
extern "C" {
#endif

#define ADC_RESOLUTION_8BIT    0x100
#define ADC_RESOLUTION_10BIT   0x400
#define ADC_RESOLUTION_12BIT   0x1000

#define ADC_DEV_SHIFT           (8)
#define ADC_DEV_MASK            (0xf00)
#define ADC_CHANNEL_MASK        (0xff)
    
#define ADC_INPUT(dev,channel)  (dev<<ADC_DEV_SHIFT | channel)
#define ADC_DEVICE(input)       (input>>ADC_DEV_SHIFT)
#define ADC_CHANNEL(input)      (input&ADC_CHANNEL_MASK)
#define ADC_DATA_CHANNEL(input) (input)
#define ADC_SOURCE_AN0          0x00
#define ADC_SOURCE_AN1          0x01
#define ADC_SOURCE_AN2          0x02
#define ADC_SOURCE_AN3          0x03
#define ADC_SOURCE_AN4          0x04
#define ADC_SOURCE_AN5          0x05
#define ADC_SOURCE_AN6          0x06
#define ADC_SOURCE_AN7          0x07
#define ADC_SOURCE_AN8          0x08
#define ADC_SOURCE_AN9          0x09
#define ADC_SOURCE_AN10         0x0a
#define ADC_SOURCE_AN11         0x0b
#define ADC_SOURCE_AN12         0x0c
#define ADC_SOURCE_AN13         0x0d
#define ADC_SOURCE_AN14         0x0e
#define ADC_SOURCE_AN15         0x0f
#define ADC_SOURCE_AN16         0x10
#define ADC_SOURCE_AN17         0x11
#define ADC_SOURCE_AN18         0x12
#define ADC_SOURCE_AN19         0x13
#define ADC_SOURCE_AN20         0x14
#define ADC_SOURCE_AN21         0x15
#define ADC_SOURCE_AN22         0x16
#define ADC_SOURCE_AN23         0x17
#define ADC_SOURCE_AN24         0x18
#define ADC_SOURCE_AN25         0x19
#define ADC_SOURCE_AN26         0x1a
#define ADC_SOURCE_AN27         0x1b
#define ADC_SOURCE_AN28         0x1c
#define ADC_SOURCE_AN29         0x1d
#define ADC_SOURCE_AN30         0x1e
#define ADC_SOURCE_AN31         0x1f


#define ADC_AN0_MASK            (1<<ADC_SOURCE_AN0)
#define ADC_AN1_MASK            (1<<ADC_SOURCE_AN1)
#define ADC_AN2_MASK            (1<<ADC_SOURCE_AN2)
#define ADC_AN3_MASK            (1<<ADC_SOURCE_AN3)
#define ADC_AN4_MASK            (1<<ADC_SOURCE_AN4)
#define ADC_AN5_MASK            (1<<ADC_SOURCE_AN5)
#define ADC_AN6_MASK            (1<<ADC_SOURCE_AN6)
#define ADC_AN7_MASK            (1<<ADC_SOURCE_AN7)
#define ADC_AN8_MASK            (1<<ADC_SOURCE_AN8)
#define ADC_AN9_MASK            (1<<ADC_SOURCE_AN9)
#define ADC_AN10_MASK           (1<<ADC_SOURCE_AN10)
#define ADC_AN11_MASK           (1<<ADC_SOURCE_AN11)
#define ADC_AN12_MASK           (1<<ADC_SOURCE_AN12)
#define ADC_AN13_MASK           (1<<ADC_SOURCE_AN13)
#define ADC_AN14_MASK           (1<<ADC_SOURCE_AN14)
#define ADC_AN15_MASK           (1<<ADC_SOURCE_AN15)
#define ADC_AN16_MASK           (1<<ADC_SOURCE_AN16)
#define ADC_AN17_MASK           (1<<ADC_SOURCE_AN17)
#define ADC_AN18_MASK           (1<<ADC_SOURCE_AN18)
#define ADC_AN19_MASK           (1<<ADC_SOURCE_AN19)
#define ADC_AN20_MASK           (1<<ADC_SOURCE_AN20)
#define ADC_AN21_MASK           (1<<ADC_SOURCE_AN21)
#define ADC_AN22_MASK           (1<<ADC_SOURCE_AN22)
#define ADC_AN23_MASK           (1<<ADC_SOURCE_AN23)
#define ADC_AN24_MASK           (1<<ADC_SOURCE_AN24)
#define ADC_AN25_MASK           (1<<ADC_SOURCE_AN25)
#define ADC_AN26_MASK           (1<<ADC_SOURCE_AN26)
#define ADC_AN27_MASK           (1<<ADC_SOURCE_AN27)
#define ADC_AN28_MASK           (1<<ADC_SOURCE_AN28)
#define ADC_AN29_MASK           (1<<ADC_SOURCE_AN29)
#define ADC_AN30_MASK           (1<<ADC_SOURCE_AN30)
#define ADC_AN31_MASK           (1<<ADC_SOURCE_AN31)


typedef struct lwadc_init_struct {
    uint_32                     device;
    uint_32                     format;
    uint_32                     clock;
    uint_32                     reference;
}LWADC_INIT_STRUCT, * LWADC_INIT_STRUCT_PTR;


typedef struct adc_context {
    VPXADC_REG_STRUCT_PTR       adc_ptr;
    const LWADC_INIT_STRUCT *   init_ptr;
    uint_32                     mcr;
    uint_32                     channels;
    uint_32                     default_numerator;
    uint_32                     default_denominator;
}ADC_CONTEXT, * ADC_CONTEXT_PTR;

typedef struct lwadc_struct {
    ADC_CONTEXT_PTR             context_ptr;
    uint_32                     input;
    uint_32                     mask;
    uint_32                     numerator;
    uint_32                     denominator;
}LWADC_STRUCT, * LWADC_STRUCT_PTR;
typedef enum {
    LWADC_RESOLUTION=1,
    LWADC_REFERENCE,
    LWADC_FREQUENCY,
    LWADC_DIVIDER,
    LWADC_DIFFERENTIAL,
    LWADC_POWER_DOWN,
    LWADC_NUMERATOR ,
    LWADC_DENOMINATOR,
    LWADC_DEFAULT_NUMERATOR ,
    LWADC_DEFAULT_DENOMINATOR,
    LWADC_FORMAT,
    LWADC_INPUT_CONVERSION_ENABLE
} LWADC_ATTRIBUTE;

#define LWADC_FORMAT_LEFT_JUSTIFIED     1
#define LWADC_FORMAT_RIGHT_JUSTIFIED    2


typedef uint_32 LWADC_VALUE, * LWADC_VALUE_PTR;

extern boolean _lwadc_init( const LWADC_INIT_STRUCT * init_ptr);
extern boolean _lwadc_init_input( LWADC_STRUCT_PTR lwadc_ptr, uint_32 input);
extern boolean _lwadc_read_raw( LWADC_STRUCT_PTR lwadc_ptr,  LWADC_VALUE_PTR outSample);
extern boolean _lwadc_read( LWADC_STRUCT_PTR lwadc_ptr, LWADC_VALUE_PTR outSample);
extern boolean _lwadc_wait_next( LWADC_STRUCT_PTR lwadc_ptr);
extern boolean _lwadc_read_average( LWADC_STRUCT_PTR lwadc_ptr, uint_32 num_samples, LWADC_VALUE_PTR outSample);
extern boolean _lwadc_set_attribute( LWADC_STRUCT_PTR lwadc_ptr, LWADC_ATTRIBUTE attribute, uint_32 value);
extern boolean _lwadc_get_attribute( LWADC_STRUCT_PTR lwadc_ptr, LWADC_ATTRIBUTE attribute, uint_32_ptr value_ptr);


#ifdef __cplusplus
}
#endif

#endif

/* EOF */
