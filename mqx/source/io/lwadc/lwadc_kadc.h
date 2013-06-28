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
* $FileName: lwadc_kadc.h$
* $Version : 3.8.1.0$
* $Date    : Sep-21-2012$
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


#define LWADC_RESOLUTION_16BIT    0x10000
#define LWADC_RESOLUTION_12BIT    0x1000
#define LWADC_RESOLUTION_10BIT    0x400
#define LWADC_RESOLUTION_8BIT     0x100
#define LWADC_RESOLUTION_DEFAULT  (LWADC_RESOLUTION_16BIT)
#define ADC_CDR_CDATA_MASK      0x0000FFFF
#define ADC_SOURCE_CHANNEL(x)   (x)
#define ADC_SOURCE_MUXSEL_SHIFT (9)
#define ADC_SOURCE_MUXSEL_X     (0x0000) /* none of A / B is forced to use */
#define ADC_SOURCE_MUXSEL_A     (0x0200) /* the A pair is forced to use */
#define ADC_SOURCE_MUXSEL_B     (0x0400) /* the B pair is forced to use */
#define ADC_SOURCE_DIFF         (0x0800)
#define ADC_SOURCE_MODULE_SHIFT (12)
#define ADC_SOURCE_MODULE(x)    (x << ADC_SOURCE_MODULE_SHIFT)
#define ADC_SOURCE_MODULE_ANY   ADC_SOURCE_MODULE(0x00)

#define ADC_GET_CHANNEL(x)  ((x) & 0x001F)
#define ADC_GET_MUXSEL(x)   ((x) & 0x0600)
#define ADC_GET_DIFF(x)     ((x) & 0x0800)
#define ADC_GET_MODULE(x)   ((x) & 0xF000)
#define ADC_RESOLUTION_16BIT    ADC_CFG1_MODE(0x03)
#define ADC_RESOLUTION_12BIT    ADC_CFG1_MODE(0x01)
#define ADC_RESOLUTION_10BIT    ADC_CFG1_MODE(0x02)
#define ADC_RESOLUTION_8BIT     ADC_CFG1_MODE(0x00)


typedef enum {
    LWADC_CLK_BUSCLK,     /* selects BUSCLK */
    LWADC_CLK_BUSCLK2,    /* selects BUSCLK/2 */
    LWADC_CLK_BUSCLK_ANY, /* selects BUSCLK or BUSCLK/2 */
    LWADC_CLK_ALTERNATE,
    LWADC_CLK_ASYNC
} LWADC_CLOCK_SOURCE;

typedef enum {
    LWADC_DIV_1 = 0,
    LWADC_DIV_2 = 1,
    LWADC_DIV_4 = 2,
    LWADC_DIV_8 = 3,
    LWADC_DIV_ANY = -1 /* selects automatically the fastest one */
} LWADC_CLOCK_DIV;

typedef enum {
    LWADC_LPC_LOW =    ADC_CFG1_ADLPC_MASK, /* use low power of ADC (reduces max. ADCCLK frequency) */
    LWADC_LPC_NORMAL = 0                    /* use normal power of ADC */
} LWADC_LPC;

typedef enum {
    LWADC_HSC_NORMAL = ADC_CFG2_ADHSC_MASK, /* use normal speed */
    LWADC_HSC_HIGH = 0                      /* use high speed */
} LWADC_HSC;

typedef enum {
    LWADC_PDB_COMP1OUT = 0,   /* Comparator 1 output trigger */
    LWADC_PDB_COMP2OUT = 4,   /* Comparator 2 output trigger */
    LWADC_PDB_EXTRIG   = 16,  /* External event trigger */
    LWADC_PDB_SWTRIG   = 28   /* Software trigger */
} LWADC_PDB_TRIGSEL;


typedef struct lwadc_init_struct {
    /* The number of ADC peripheral, use adc_t enum from PSP */
    uint_8 ADC_NUMBER;

    /* The clock source */
    LWADC_CLOCK_SOURCE CLOCK_SOURCE;

    /* The clock divisor for ADC */
    LWADC_CLOCK_DIV CLOCK_DIV;

    /* ADC high speed control, see ADC_HSC enum */
    LWADC_HSC SPEED;

    /* ADC low power control, see ADC_LPC enum */
    LWADC_LPC POWER;

    /* The calibration data pointer */
    uint_8_ptr CALIBRATION_DATA_PTR;

    /* ADC interrupt vector */
    uint_32 ADC_VECTOR;

    /* ADC interrupt vector */
    uint_32 ADC_PRIORITY;
    
    uint_32 reference;
}LWADC_INIT_STRUCT, * LWADC_INIT_STRUCT_PTR;


typedef struct adc_context {
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

extern uint_32 _lwadc_init( const LWADC_INIT_STRUCT * init_ptr);
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
