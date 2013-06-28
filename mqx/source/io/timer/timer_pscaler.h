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
* $FileName: timer_pscaler.h$
* $Version : 3.8.1.0$
* $Date    : May-11-2011$
*
* Comments:
*
*   This file contains definitions for the MTIM functions.
*
*END************************************************************************/

#ifndef __timer_pscaler_h__
#define __timer_pscaler_h__

#include <mqx.h>
#include <bsp.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct postscaler_struct
{
    uint_16 counter;
    uint_16 period;
} POSTSCALER_STRUCT, _PTR_ POSTSCALER_STRUCT_PTR;


/*-----------------------------------------------------------------------*/
/*                      FUNCTION PROTOTYPES
*/

void _postscaler_init(POSTSCALER_STRUCT _PTR_, uint_16);
boolean _postscaler_check(POSTSCALER_STRUCT _PTR_);


#ifdef __cplusplus
}
#endif

#endif
