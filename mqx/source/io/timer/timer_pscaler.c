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
* $FileName: timer_pscaler.c$
* $Version : 3.8.3.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains timer functions for software timer postscaler.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include "timer_pscaler.h"


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _postscaler_init
* Returned Value  : TRUE if functions was called postscaler->period times
* Comments        :
*     SW postscaler function
*
*END*---------------------------------------------------------------------*/

void _postscaler_init(POSTSCALER_STRUCT _PTR_ postscaler, uint_16 period)
{
    postscaler->period = period;
    postscaler->counter = 0;
}


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _postscaler_check
* Returned Value  : TRUE if functions was called postscaler->period times
* Comments        :
*     SW postscaler function
*
*END*---------------------------------------------------------------------*/

boolean _postscaler_check(POSTSCALER_STRUCT _PTR_ postscaler)
{
    postscaler->counter++;
    if (postscaler->counter >= postscaler->period) {
        postscaler->counter = 0;
        return TRUE;
    }
    else {
        return FALSE;
    }
}
