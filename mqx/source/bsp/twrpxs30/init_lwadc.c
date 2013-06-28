/**HEADER********************************************************************
* 
* Copyright (c) 2012 Freescale Semiconductor;
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
* $Date    : Jun-6-2012$
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

const LWADC_INIT_STRUCT lwadc0_init = { 0, LWADC_FORMAT_RIGHT_JUSTIFIED, BSP_ADC_CLOCK, BSP_ADC_VREF_DEFAULT };
const LWADC_INIT_STRUCT lwadc1_init = { 1, LWADC_FORMAT_RIGHT_JUSTIFIED, BSP_ADC_CLOCK, BSP_ADC_VREF_DEFAULT };
const LWADC_INIT_STRUCT lwadc2_init = { 2, LWADC_FORMAT_RIGHT_JUSTIFIED, BSP_ADC_CLOCK, BSP_ADC_VREF_DEFAULT };
const LWADC_INIT_STRUCT lwadc3_init = { 3, LWADC_FORMAT_RIGHT_JUSTIFIED, BSP_ADC_CLOCK, BSP_ADC_VREF_DEFAULT };
