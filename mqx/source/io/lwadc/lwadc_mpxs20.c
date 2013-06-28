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
* $FileName: lwadc_mpxs20.c$
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

static const pointer adc_address[] = { (pointer) MPXS20_ADC_0_BASE, (pointer) MPXS20_ADC_1_BASE };

static const uint_32 adc_channel_mask[MPXSXX_ADC_NUM_DEVICES] = {
    ADC_ALL_CHANNEL_MASK,
    ADC_ALL_CHANNEL_MASK,
};


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
      return (VPXADC_REG_STRUCT_PTR)adc_address[device];
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
