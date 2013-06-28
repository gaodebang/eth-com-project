/**HEADER********************************************************************
*
* Copyright (c) 2012 Freescale Semiconductor;
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
* $FileName: cortexa5.h$
* $Version : 3.8.7.0$
* $Date    : Oct-2-2012$
*
* Comments:
* ARM Generic Interrupt Controller version 2.0
*
*END************************************************************************/

#include "gic.h"

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _gic_int_init
* Returned Value  : _mqx_uint
*       MQX_OK or error code
* Comments        :
*  	Initialize a specific interrupt in the GIC
*
*END*---------------------------------------------------------------------*/
_mqx_uint _gic_int_init
   (
      // [IN} Interrupt number
      _mqx_uint irq,

      // [IN} Interrupt priority
      _mqx_uint prior,

      // [IN] enable the interrupt now?
      boolean enable
   )
{
    _mqx_uint gic_irq_no = irq - 16;

    // check priority value, must be below maximal enabled/set value
    if (prior >= (1 << GIC_PRIOR_IMPL)) {
        return MQX_INVALID_PARAMETER;
    }

    if (irq >= PSP_INT_FIRST_INTERNAL && irq <= PSP_INT_LAST_INTERNAL) {
        // set priority
        GIC_ICDIPR(gic_irq_no >> 2) = (GIC_ICDIPR(gic_irq_no >> 2) & ~(0xff << ((gic_irq_no & 3) * 8))) | (((prior << GIC_PRIOR_SHIFT) & GIC_PRIOR_MASK) << ((gic_irq_no & 3) * 8));

        if (enable)
            _gic_int_enable(irq);
        else
            _gic_int_disable(irq);
    }
    else
        return MQX_INVALID_PARAMETER;

    return MQX_OK;
}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _gic_int_enable
* Returned Value  : _mqx_uint
*       MQX_OK or error code
* Comments        :
* 	Enable interrupt on GIC
*
*END*---------------------------------------------------------------------*/
_mqx_uint _gic_int_enable(_mqx_uint irq) {
    _mqx_uint gic_irq_no = irq - 16;

    if (irq >= PSP_INT_FIRST_INTERNAL && irq <= PSP_INT_LAST_INTERNAL) {
        GICD_ISENABLER(gic_irq_no / 32) = (1 << (gic_irq_no % 32));
    }
    else
        return MQX_INVALID_PARAMETER;

    return MQX_OK;
}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _gic_int_disable
* Returned Value  : _mqx_uint
*       MQX_OK or error code
* Comments        :
* 	Disable interrupt on GIC
*
*END*---------------------------------------------------------------------*/
_mqx_uint _gic_int_disable(_mqx_uint irq) {
    _mqx_uint gic_irq_no = irq - 16;

    if (irq >= PSP_INT_FIRST_INTERNAL && irq <= PSP_INT_LAST_INTERNAL) {
        GICD_ICENABLER(gic_irq_no / 32) = (1 << (gic_irq_no % 32));
    }
    else
        return MQX_INVALID_PARAMETER;

    return MQX_OK;
}
