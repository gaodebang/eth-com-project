/**HEADER********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
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
* $FileName: init_hmi.c$
* $Version : 3.8.1.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains board-specific HMI BTNLED settings.
*
*END************************************************************************/
#include <mqx.h>
#include <bsp.h>
#include "TSS_API.h"

/* sensitivity values for each electrode */
static const uint_8 sensitivity_values[] =
{
        0x40,0x40,0x40,0x40,
        0x40,0x40
};

/* System control */
static const HMI_TSS_SYSTEM_CONTROL_STRUCT hmi_system_control_kinetis=
{
        (TSS_SYSTEM_EN_MASK | TSS_DC_TRACKER_EN_MASK),
        TSS_TRIGGER_MODE_ALWAYS,    /* system trigger */
        0x08,                        /* number of samples */
        sensitivity_values          /* pointer to sensitivity values */
};

/* ON BOARD keypad */
static const HMI_TSS_INIT_STRUCT hmi_init_table_tss_twrpi_void[]=
{
        /* UID, FLAG */
        {HMI_BUTTON_1,0},    /* E1 - touch button 1 */
        {HMI_BUTTON_2,0},    /* E2 - touch button 2 */
        {HMI_BUTTON_3,0},    /* E3 - touch button 3 */
        {HMI_BUTTON_4,0},    /* E4 - touch button 4 */
        {HMI_BUTTON_5,0},    /* E5 - touch button 5 */
        {HMI_BUTTON_6,0},    /* E6 - touch button 6 */
        {0,0}
};

static HMI_CLIENT_STRUCT_PTR hmi_btnled_handle_ptr;                 /* Client pointer */
static HMI_PROVIDER_STRUCT_PTR hmi_twrpi_provider_keypad_ptr;       /* On Board KEYPAD provider pointer*/
static _mqx_int actual_provider = 0;                                /* Present provider which is set, default = 0*/

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_btnled_init
* Returned Value   : HMI_CLIENT_STRUCT_PTR for success, NULL for failure
* Comments         :
*    This function performs BSP-specific initialization related to HMI.
*    It installs interrupts for TSS and initializes btnled client with
*    default providers.
*END*----------------------------------------------------------------------*/
HMI_CLIENT_STRUCT_PTR _bsp_btnled_init(void)
{
    
     _int_install_isr(INT_TSI0, TSS_TSI0Isr, NULL);    /* Enable TSI0 Isr */
    _bsp_int_init(INT_TSI0, BSP_TSI_INT_LEVEL, 0, TRUE);
    _bsp_int_enable(INT_TSI0);

    _int_install_isr(INT_FTM1, TSS_HWTimerIsr, NULL);  /* Enable TIMER Isr */
    _bsp_int_init(INT_FTM1, BSP_TSI_INT_LEVEL, 0, TRUE);
    _bsp_int_enable(INT_FTM1);

    _bsp_tss_io_init();                                /* TSI init */
    hmi_tss_init(hmi_system_control_kinetis);          /* TSS init */
  
    hmi_btnled_handle_ptr = btnled_init();
    if(hmi_btnled_handle_ptr == NULL)   /* client not initialized */
    {
        return NULL;
    }
    
    /* providers init - only providers available on board */
    hmi_twrpi_provider_keypad_ptr = hmi_tss_keypad_provider_init(hmi_init_table_tss_twrpi_void, 0); /* TSS Keypad - C0_TYPE */  
    
    if (!hmi_add_provider(hmi_btnled_handle_ptr, hmi_twrpi_provider_keypad_ptr))
    {
        return NULL;    /* provider's addition to the client table failed */
    }
    return hmi_btnled_handle_ptr;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_btnled_set_twrpi
* Returned Value   : MQX_OK for success, -1 for a failure
* Comments         :
*    This function selects TWRPI module.
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_btnled_set_twrpi(_mqx_int twrpi_index)
{
    return MQX_INVALID_CONFIGURATION;   /* TWRPI not present on Kwikstick */
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_btnled_get_twrpi
* Returned Value   : _mqx_int
* Comments         :
*    This function returns activated TWRPI module.
*
*END*----------------------------------------------------------------------*/
_mqx_int _bsp_btnled_get_twrpi()
{    
    return actual_provider;    /* return actual provider */
}
/* EOF */
