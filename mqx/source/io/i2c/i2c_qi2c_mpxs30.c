/**HEADER********************************************************************
*
* Copyright (c) 2011 Freescale Semiconductor;
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
* $FileName: i2c_qi2c_mpxs30.c$
* $Version : 3.8.1.0$
* $Date    : Oct-5-2011$
*
* Comments:
*
*   This file contains board-specific I2C initialization functions.
*
*END************************************************************************/


#include <mqx.h>
#include <bsp.h>

static const pointer i2c_address[] = { (pointer) MPXS30_I2C0_BASE, (pointer) MPXS30_I2C1_BASE, (pointer) MPXS30_I2C2_BASE };
static const uint_32 i2c_config[]  = {  CORECFG_I2C_0, CORECFG_I2C_1, CORECFG_I2C_2 };
static const uint_32 i2c_pbridge_id[] = {  MPXS30_PBRIDGE_I2C_0, MPXS30_PBRIDGE_I2C_1, MPXS30_PBRIDGE_I2C_2 };


   
/*FUNCTION*-------------------------------------------------------------
* 
* Function Name    : _bsp_i2c_enable_access
* Returned Value   : True if enabled
* Comments         :
*    This function enables the specified device.
*
*END*-----------------------------------------------------------------*/

boolean _bsp_i2c_enable_access(uint_32 device)
{
    if (device < ELEMENTS_OF(i2c_config)) {
        if (_psp_core_peripheral_enabled(i2c_config[device])) {
            return _qpbridge_enable_access(i2c_pbridge_id[device]);
        }
    }
    return FALSE;
}


/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_i2c_base_address
* Returned Value   : address if successful, NULL otherwise
* Comments         :
*    This function returns the base register address of the corresponding I2C device.
*
*END*********************************************************************/


VQI2C_REG_STRUCT_PTR _bsp_get_i2c_base_address(uint_32 channel)
{
    if (channel < ELEMENTS_OF(i2c_address)) {
        return (VQI2C_REG_STRUCT_PTR) i2c_address[channel];
    }
    return NULL;
}



/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_i2c_vector
* Returned Value   : vector number if successful, 0 otherwise
* Comments         :
*    This function returns desired interrupt vector number for specified I2C device.
*
*END*********************************************************************/

uint_32 _bsp_get_i2c_vector(uint_8 dev_num)
{
    switch (dev_num)
    {
        case 0: return MPXS30_INTC_I2C0_VECTOR;
        case 1: return MPXS30_INTC_I2C1_VECTOR;
        case 2: return MPXS30_INTC_I2C2_VECTOR;
    }
    return 0;
}
