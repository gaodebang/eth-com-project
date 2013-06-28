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
* $FileName: timer_gt.c$
* $Version : 3.8.4.0$
* $Date    : Sep-24-2012$
*
* Comments:
*
*    This file contains definitions for the Qoriwa PIT timer driver.
*
*END***********************************************************************/

#include "mqx_inc.h"
#include <bsp.h>
#include "bsp_prv.h"

#include "timer_gt.h"

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _gt_get_hwticks
* Returned Value   : Number of hwticks elapsed since last interrupt
* Comments         :
*
*
*END*----------------------------------------------------------------------*/

static uint_32 _gt_get_hwticks(pointer dummy)
{
	uint_64 cmp_prev;
    uint_64 cnt;
    GICD_MemMapPtr GICD = GICD_BASE_PTR;
    uint_32 ticks, cnt_l, cnt_h, cmp_l, cmp_h;

    cmp_h = GT_CVRH;
    cmp_l = GT_CVRL;

    /* Read counter and comparator value */
    do
    {
    	cnt_h = GT_CNTRH;
    	cnt_l = GT_CNTRL;
    }
    while(cnt_h != GT_CNTRH);

    /* Check if global timer interrupt is pending */
    if ((GICD->ISPENDR[0] & 0x08000000) || (GT_IS & 0x00000001))
    {
    	 /* Read counter and comparator value */
    	 cmp_h = GT_CVRH;
    	 cmp_l = GT_CVRL;

         /* Read counter and comparator value */
    	 do
    	 {
    	 	cnt_h = GT_CNTRH;
    	  	cnt_l = GT_CNTRL;
    	 }
    	 while(cnt_h != GT_CNTRH);

    	 cmp_prev = (uint_64) cmp_h << 32 | cmp_l;
    	 cmp_prev -= 2*GT_AIR;
    }
    else
    {
    	cmp_prev = (uint_64) cmp_h << 32 | cmp_l;
    	cmp_prev -= GT_AIR;
    }
    cnt = (uint_64) cnt_h << 32 | cnt_l;
    /* Calculate HW ticks count since last interrupt */
    ticks = (cnt - cmp_prev) & 0xFFFFFFFF;
    return ticks;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _gt_get_period
* Returned Value   : Number of hwticks per tick
* Comments         :
*
*
*END*----------------------------------------------------------------------*/

static uint_32 _gt_get_period(void)
{
//    return GT_AIR + 1;
    return GTIMINCR + 1;
}

#if 0


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _qpit_timer_init
* Returned Value   : Number of hwticks per tick
* Comments         : Initilizes QPIT
*
*
*END*----------------------------------------------------------------------*/

static uint_32 _qpit_timer_init
    (
        /* [IN] the device to initialize */
        VQPIT_REG_STRUCT_PTR  qpit_ptr,

        /* [IN] the channel to initialize */
        uint_32   channel,

        /* [IN] ticks per second */
        uint_32   tickfreq,

        /* [IN] input clock speed in Hz */
        uint_32   clk
    )
{
   uint_32 period;

   period = (uint_32)(((clk << 1)/tickfreq + 1) >> 1);

   /* Enable PIT module, disable count on breakpoint */
   qpit_ptr->MCR = QPIT_MCR_FRZ;

   /* Disable timer and interrupt */
   qpit_ptr->TIMERS[channel].TCTRL = 0;

   qpit_ptr->TIMERS[channel].LDVAL = period-1;

   /* Clear any pending interrupt */
   qpit_ptr->TIMERS[channel].TFLG = QPIT_TFLG_TIF;

   /* Enable timer and interrupt */
   qpit_ptr->TIMERS[channel].TCTRL = (QPIT_TCTRL_TIE|QPIT_TCTRL_TEN);

   return period;
}

#endif

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _gt_timer_install
* Returned Value   : MQX_OK if successful or else MQX Error
* Comments         :
*    Initilizes the Timer and installs isr to provide kernel ticks
*
*END*----------------------------------------------------------------------*/

uint_32 _gt_timer_install
    (
        /* [IN] the GT device to initialize */
        uint_32   device,

        /* [IN] the channel to initialize */
        uint_32   channel,

        /* [IN] ticks per second */
        uint_32   tickfreq,

        /* [IN] input clock speed in Hz */
        uint_32   clk,

        /* [IN] interrupt priority */
        uint_32 priority,

        void (_CODE_PTR_ isr_ptr)(void *)

    )
{
    //    VQPIT_REG_STRUCT_PTR         qpit_ptr;
    PSP_INTERRUPT_TABLE_INDEX    vector = BSP_TIMER_INTERRUPT_VECTOR;
    uint_32 period;

    /*    #if PSP_HAS_DEVICE_PROTECTION
    if (!_bsp_qpit_enable_access(device)) {
    return MQX_INVALID_DEVICE;
}
#endif*/

    /*    qpit_ptr = _bsp_get_qpit_base_address(device);
    vector   = _bsp_get_qpit_vector(device, channel);
    if (qpit_ptr == NULL ||  vector == 0) {
    return MQX_INVALID_DEVICE;
}*/

    _bsp_int_disable(vector);

    /* Set up tick timer */
    //    period = _gt_timer_init(qpit_ptr, channel, tickfreq, clk);
    period = (uint_32)(((clk << 1) / tickfreq + 1) >> 1);

    if (period == 0) {
        return MQX_TIMER_ISR_INSTALL_FAIL;
    }

    /* Install the timer interrupt handler */
    if (NULL == _int_install_isr(vector, isr_ptr, NULL)) {
        return _task_get_error();
    }

    _bsp_int_init(vector, priority, 0, TRUE);

    // disable GT
    //GT_CONTR = 0;
    GTIMCTRL = 0;

    GT_CVRL = period;
    
    GT_AIR = period;

    //GT_CONTR = 0x0f;     // timer en, comp en, irq en, auto inc
    GTIMCTRL = (GTIM_CTRL_ENA_MASK | GTIM_CTRL_COMP_MASK | GTIM_CTRL_INT_MASK | GTIM_CTRL_INCR_MASK);     // timer en, comp en, irq en, auto inc

    return MQX_OK;
}

/*ISR*********************************************************************
*
* Function Name    : _qpit_kernel_isr
* Returned Value   : void
* Comments         :
*
*
*END**********************************************************************/
static void _gt_kernel_isr( pointer p )
{
/*    VQPIT_TIMER_REG_STRUCT_PTR qpit_timer_ptr = (VQPIT_TIMER_REG_STRUCT_PTR) p;

    qpit_timer_ptr->TFLG = QPIT_TFLG_TIF;
*/
    //GT_IS = 1;
    GTIMISTAT = 1;
    _time_notify_kernel();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _gt_timer_install_kernel
* Returned Value   : MQX_OK if successful or else MQX Error
* Comments         :
*    Initilizes the Timer and installs isr to provide kernel ticks
*
*END*----------------------------------------------------------------------*/
uint_32 _gt_install_kernel
    (
        /* [IN] the PIT device to initialize */
        uint_32   device,

        /* [IN] the channel to initialize */
        uint_32   channel,

        /* [IN] ticks per second */
        uint_32   tickfreq,

        /* [IN] input clock speed in Hz */
        uint_32   clk,

        /* [IN] interrupt priority */
        uint_32   priority
    )
{
//    VQPIT_REG_STRUCT_PTR         qpit_ptr = _bsp_get_qpit_base_address(device);
    PSP_INTERRUPT_TABLE_INDEX    vector = BSP_TIMER_INTERRUPT_VECTOR;   //_bsp_get_qpit_vector(device, channel);
    uint_32 result;

//    if (vector == 0)
//    {
//        return MQX_INVALID_DEVICE;
//    }

    result = _gt_timer_install(device, channel, tickfreq, clk, priority, _gt_kernel_isr);
    if (result != MQX_OK)
    {
        return result;
    }

    /* Initialize the timer interrupt */
    _time_set_timer_vector(vector);
    _time_set_hwtick_function(_gt_get_hwticks, NULL);
    _time_set_hwticks_per_tick(_gt_get_period());
    _time_set_ticks_per_sec(tickfreq);

    return MQX_OK;
}
