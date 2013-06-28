/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2008 Embedded Access Inc.;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
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
* $FileName: init_lwadc.c$
* $Version : 3.8.1.0$
* $Date    : Sep-21-2012$
*
* Comments:
*
*   This file contains the definition for the lwadc devices
*
*
*END*********************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "bsp_prv.h"

const LWADC_INIT_STRUCT lwadc0_init = {
	    /* The number of ADC peripheral, use adc_t enum from PSP */
	    0,
	    /* The clock source, selects the best from BUSCLK and BUSCLK/2 */
	    LWADC_CLK_BUSCLK_ANY,
	    /* The clock divisor for ADC. use the fastest one */
	    LWADC_DIV_ANY,
	    /* ADC high speed control, see ADC_HSC enum */
	    LWADC_HSC_NORMAL,
	    /* ADC low power control, see ADC_LPC enum */
	    LWADC_LPC_NORMAL,
	    /* The calibration data pointer */
	    NULL,
	    /* ADC interrupt vector */
	    INT_ADC0,
	    /* ADC interrupt vector */
	    BSP_ADC0_VECTOR_PRIORITY,
	    
	    BSP_ADC_VREF_DEFAULT
	};
/* EOF */
