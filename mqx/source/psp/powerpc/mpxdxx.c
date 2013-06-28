/**HEADER********************************************************************
*
* Copyright (c) 2011 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2011 Embedded Access Inc.;
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
* $FileName: mpxdxx.c$
* $Version : 3.8.2.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This file contains utiltity functions for use with the mpxdxx CPUs.
*
*END*********************************************************************/

#include "mqx_inc.h"


#ifndef PSP_E200_CORE_Z0
/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _mpxdxx_enable_timer
* Returned Value   : int
* Comments         :
*    This function enables Timebase unit
*
*END*----------------------------------------------------------------------*/
int_32 _mpxdxx_enable_timer(boolean external)
{
    register uint_32 tmp;

    _PSP_SPR_GET(tmp,E200CORE_HID0);

    /* Set the time base clock */
    if (external) {
        tmp |= E200CORE_HID0_SEL_TBCLK;
    } else {
        tmp &= ~E200CORE_HID0_SEL_TBCLK;
    }

    /* Time base enable */
    tmp |= E200CORE_HID0_TBEN;
    _PSP_SPR_SET(E200CORE_HID0, tmp);

    return MQX_OK;
}
#endif /* !PSP_E200_CORE_Z0 */

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _mpxdxx_initialize_support
* Returned Value   : none
* Comments         :
*  Initilize the support functions for the mpxdxx
*
*END*------------------------------------------------------------------------*/
void _mpxdxx_initialize_support(void)
{
     _psp_set_support_ptr( _mem_alloc_system_zero((uint_32)sizeof(PSP_SUPPORT_STRUCT)));
}
