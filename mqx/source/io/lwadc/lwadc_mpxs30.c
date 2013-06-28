/**HEADER********************************************************************
*
* Copyright (c) 2011 Freescale Semiconductor;
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
* $FileName: lwadc_mpxs30.c$
* $Version : 3.8.1.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains board-specific ADC initialization functions.
*
*END************************************************************************/


#include <mqx.h>
#include <bsp.h>

#include "pxadc.h"
#include "lwadc_mpxsxx.h"
#include "lwadc_mpxsxx_prv.h"

static const uint_32 adc_pbridge_id[] = {  MPXS30_PBRIDGE_ADC_0, MPXS30_PBRIDGE_ADC_1, MPXS30_PBRIDGE_ADC_2, MPXS30_PBRIDGE_ADC_3 };
static const pointer adc_address[] = { (pointer) MPXS30_ADC_0_BASE, (pointer) MPXS30_ADC_1_BASE, (pointer) MPXS30_ADC_2_BASE, (pointer) MPXS30_ADC_3_BASE };
static const uint_32 adc_config[] = {  CORECFG_ADC_0, CORECFG_ADC_1, CORECFG_ADC_2, CORECFG_ADC_3 };

static const uint_32 adc_channel_mask[MPXSXX_ADC_NUM_DEVICES] = {
    ADC_ALL_CHANNEL_MASK,
    ADC_ALL_CHANNEL_MASK,
    ADC_AN0_MASK|ADC_AN1_MASK|ADC_AN2_MASK|ADC_AN3_MASK|ADC_AN9_MASK|ADC_AN11_MASK|ADC_AN12_MASK|ADC_AN13_MASK|ADC_AN14_MASK,
    ADC_AN0_MASK|ADC_AN1_MASK|ADC_AN2_MASK|ADC_AN3_MASK|ADC_AN9_MASK|ADC_AN11_MASK|ADC_AN12_MASK|ADC_AN13_MASK|ADC_AN14_MASK,
};


/*FUNCTION*-------------------------------------------------------------
*
* Function Name    : _bsp_adc_enable_access
* Returned Value   : True if enabled
* Comments         :
*    This function enables the specified device.
*
*END*-----------------------------------------------------------------*/

boolean _bsp_adc_enable_access(uint_32 device)
{
    if (device < ELEMENTS_OF(adc_address)) {
        if (_psp_core_peripheral_enabled(adc_config[device])) {
            return _qpbridge_enable_access(adc_pbridge_id[device]);
        }
    }
    return FALSE;
}


/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_adc_base_address
* Returned Value   : address if successful, NULL otherwise
* Comments         :
*    This function returns the base register address of the corresponding ADC device.
*
*END*********************************************************************/

VPXADC_REG_STRUCT_PTR _bsp_get_adc_base_address(uint_32 device)
{
   if (device < ELEMENTS_OF(adc_address)) {
      return (VPXADC_REG_STRUCT_PTR) _psp_core_peripheral_address(adc_config[device], adc_address[device]);
   }
   return NULL;
}


/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_adc_channel_mask
* Returned Value   : address if successful, NULL otherwise
* Comments         :
*    This function returns a bit mask indicating which channels are valid
*    for the specified device.
*
*END*********************************************************************/

uint_32 _bsp_get_adc_channel_mask(uint_32 device)
{
   if (device < ELEMENTS_OF(adc_channel_mask)) {
      return adc_channel_mask[device];
   }
   return 0;
}


/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_adc_vector
* Returned Value   : vector number if successful, 0 otherwise
* Comments         :
*    This function returns desired interrupt vector number for specified ADC device.
*
*END*********************************************************************/

#if 0
static const uint_32 adc_eoc_vector[] = {MPXS30_INTC_ADC0_EOC_VECTOR,MPXS30_INTC_ADC1_EOC_VECTOR,MPXS30_INTC_ADC2_EOC_VECTOR,MPXS30_INTC_ADC3_EOC_VECTOR};
static const uint_32 adc_er_vector[] = {MPXS30_INTC_ADC0_ER_VECTOR,MPXS30_INTC_ADC1_ER_VECTOR,MPXS30_INTC_ADC2_ER_VECTOR,MPXS30_INTC_ADC3_ER_VECTOR};
static const uint_32 adc_wd_vector[] = {MPXS30_INTC_ADC0_WD_VECTOR,MPXS30_INTC_ADC1_WD_VECTOR,MPXS30_INTC_ADC2_WD_VECTOR,MPXS30_INTC_ADC3_WD_VECTOR};
uint_32 _bsp_get_adc_vector(uint_32 channel, uint_32 vector_type)
{
    if (channel < ELEMENTS_OF(adc_eoc_vector)) {
        switch (vector_type) {
        case ADC_VECTOR_EOC:
            return adc_eoc_vector[channel];
        case ADC_VECTOR_ER:
            return adc_eoc_vector[channel];
        case ADC_VECTOR_WD:
            return adc_eoc_vector[channel];

        }
    }
    return 0;
}
#endif
