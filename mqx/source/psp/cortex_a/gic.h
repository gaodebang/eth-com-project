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
* $FileName: gic.h$
* $Version : 3.8.7.0$
* $Date    : Oct-2-2012$
*
* Comments:
* ARM Generic Interrupt Controller version 2.0
*
*END************************************************************************/

#ifndef __gic_h__
#define __gic_h__

#include <mqx.h>

/* Initialization of interrupt vector in GIC (vector, priority, enable/disable) */
_mqx_uint _gic_int_init(_mqx_uint irq, _mqx_uint prior, boolean enable);

/* Enable interrupt for given vector */
_mqx_uint _gic_int_enable(_mqx_uint irq);

/* Disable interrupt for given vector */
_mqx_uint _gic_int_disable(_mqx_uint irq);

#endif // __gic_h__
