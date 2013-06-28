/**HEADER*********************************************************************
*
* Copyright (c) 2009 Freescale Semiconductor;
* All Rights Reserved
*
******************************************************************************
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
******************************************************************************
*
* $FileName: int_ctrl_mcfplus.c$
* $Version : 3.8.4.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains ColdFire+ interrupt controller functions
*
*END**************************************************************************/

#include "mqx_inc.h"
#include "int_ctrl_mcfplus.h"

/* local variables */
static uint_16  status_reg;

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name   : _mcfplus_int_mask_all
* Returned Value  : void
* Comments        : Mask all interrupts (setting actual int level to 7)
*
*END*-----------------------------------------------------------------------*/

void  _mcfplus_int_mask_all
    (
        void
    )
{ /* Body */
    status_reg = _psp_get_sr();
    _psp_set_sr(0x2700);
} /* Endbody */

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name   : _mcfplus_int_mask_all
* Returned Value  : void
* Comments        : Unmask all interrupts (restoring actual int level from 7)
*
*END*-----------------------------------------------------------------------*/

void  _mcfplus_int_unmask_all
    (
        void
    )
{ /* Body */
    _psp_set_sr(status_reg);
} /* Endbody */

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name   : _mcfplus_int_mask
* Returned Value  : MQX error code
* Comments        : Disable interrupt from given vector.
*
*END*-----------------------------------------------------------------------*/

uint_32 _mcfplus_int_mask
    (
        uint_32 vector
    )
{ /* Body */
    if ((vector >= 64) && (vector <= 102))    {
        vector -= 64;
    }
    else if ((vector >= 110) && (vector <= 114))    {
        vector -= 71;
    }
    else    {
        return MQX_INVALID_PARAMETER;
    }

    if (vector < 32)    {
        INTC_IMRL |= (1 << vector);
    }
    else    {
        INTC_IMRH |= (1 << (vector - 32));
    }

    return MQX_OK;
} /* Endbody */

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name   : _mcfplus_int_unmask
* Returned Value  : MQX error code
* Comments        : Enable interrupt from given vector.
*
*END*-----------------------------------------------------------------------*/

uint_32 _mcfplus_int_unmask
    (
        uint_32 vector
    )
{ /* Body */
    if ((vector >= 64) && (vector <= 102))    {
        vector -= 64;
    }
    else if ((vector >= 110) && (vector <= 114))    {
        vector -= 71;
    }
    else    {
        return MQX_INVALID_PARAMETER;
    }

    if (vector < 32)    {
        INTC_IMRL &= (~ (1 << vector));
    }
    else    {
        INTC_IMRH &= (~ (1 << (vector - 32)));
    }

    return MQX_OK;
} /* Endbody */

/* EOF */
