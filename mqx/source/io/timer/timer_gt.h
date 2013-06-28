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
* $FileName: timer_gt.h$
* $Version : 3.8.1.0$
* $Date    : Jul-3-2012$
*
* Comments:
*
*    This file contains definitions for the Global Timer (Faraday)
*
*END***********************************************************************/

#ifndef __timer_gt_h__
#define __timer_gt_h__


#ifdef __cplusplus
extern "C" {
#endif

//VQPIT_REG_STRUCT_PTR _bsp_get_qpit_base_address(uint_32 device);
//PSP_INTERRUPT_TABLE_INDEX _bsp_get_qpit_vector(uint_32  device, uint_32 channel);
//boolean _bsp_qpit_enable_access(uint_32 device);

//uint_32 _qpit_timer_install(uint_32 device, uint_32 channel, uint_32 tickfreq, uint_32 clk, uint_32 priority, void (_CODE_PTR_ isr_ptr)(void *));
uint_32 _gt_install_kernel(uint_32 device, uint_32 channel, uint_32 tickfreq, uint_32 clk, uint_32 priority);


#ifdef __cplusplus
}
#endif


#endif
