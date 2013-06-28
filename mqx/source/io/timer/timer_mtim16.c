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
* $FileName: timer_mtim16.c$
* $Version : 3.8.3.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains timer functions for use with a MTIM.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include "timer_mtim16.h"


#define MTIM16_SC_TSTP_MASK  (1<<4)
#define MTIM16_SC_TRST_MASK  (1<<5)
#define MTIM16_SC_TOIE_MASK  (1<<6)
#define MTIM16_SC_TOF_MASK   (1<<7)

static void _mtim16_kernel_isr(pointer p);

typedef struct mtim16_struct
{
    uint_8 MTIMSC;   /* Status/control Register */
    uint_8 MTIMCLK;  /* Clock Configuration Register */
    uint_16 MTIMCNT;  /* Counter Register */
    uint_16 MTIMMOD;  /* Modulo Register */      
} MTIM16_STRUCT, _PTR_ MTIM16_STRUCT_PTR;


_mqx_int _mtim16_timer_install
(
  /* [IN] the timer to initialize */
  uint_8    timer,

  /* [IN] ticks per second */
  uint_32   tickfreq,

  /* [IN] input clock speed in Hz */
  uint_32   clk,

  /* [IN] interrupt priority */
  uint_32 priority,

  INT_ISR_FPTR isr_ptr,
    
  /* [IN] unmask the timer after installation */
  boolean   unmask_timer
)
{
    uint_32 result;
    _mqx_uint vector = _bsp_get_mtim16_vector(timer);

    if (vector == 0)
    {
        return MQX_INVALID_DEVICE;
    }

    _bsp_int_disable(vector);

    /* Set up tick timer */
    _mtim16_timer_init(timer, tickfreq, clk, FALSE);

    /* Install the timer interrupt handler */
    if (_int_install_isr(vector, isr_ptr, NULL) == NULL)
	{
		return MQX_TIMER_ISR_INSTALL_FAIL;
	}

    _bsp_int_init(vector, priority, 0, TRUE);
    
    _bsp_int_enable(vector);

    if (unmask_timer) {
    	_mtim16_unmask_int(timer);
    }
    
    return MQX_OK;
}

_mqx_int _mtim16_timer_install_kernel
(
		/* [IN] the timer to initialize */
		uint_8    timer,

		/* [IN] ticks per second */
		uint_32   tickfreq,

		/* [IN] input clock speed in Hz */
		uint_32   clk,

	    /* [IN] interrupt priority */
	    uint_32 priority,

		/* [IN] unmask the timer after installation */
		boolean   unmask_timer
)
{
    uint_32 result;
    uint_32 period;
    _mqx_uint vector = _bsp_get_mtim16_vector(timer);

    if (vector == 0)
    {
        return MQX_INVALID_DEVICE;
    }

    _bsp_int_disable(vector);

    /* Set up tick timer */
    period = _mtim16_timer_init(timer, tickfreq, clk, FALSE);

    /* Install the timer interrupt handler */
    if (_int_install_isr(vector, _mtim16_kernel_isr, NULL) == NULL)
	{
		return MQX_TIMER_ISR_INSTALL_FAIL;
	}

    /* Initialize the timer interrupt */
    _time_set_timer_vector(_bsp_get_mtim16_vector(timer));
    _time_set_hwtick_function(_mtim16_get_hwticks, (pointer) timer);
    _time_set_hwticks_per_tick(period);
    _time_set_ticks_per_sec(tickfreq);

    _bsp_int_init(vector, priority, 0, TRUE);
    
    _bsp_int_enable(vector);

    if (unmask_timer) {
    	_mtim16_unmask_int(timer);
    }

    return MQX_OK;

}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mtim16_timer_init
* Returned Value  : the clock rate for the timer (ns per hw tick)
* Comments        :
*   this function will set up a timer to interrupt
*
*END*---------------------------------------------------------------------*/

uint_32 _mtim16_timer_init
    (
        /* [IN] the timer to initialize */
        uint_8    timer,

        /* [IN] ticks per second */
        uint_32   tickfreq,

        /* [IN] input clock speed in Hz */
        uint_32   clk,

        /* [IN] unmask the timer after initializing */
        boolean   unmask_timer
    )
{
    uint_32 period, prescale = 0;

    volatile MTIM16_STRUCT _PTR_  mtim16_ptr;
   
    mtim16_ptr = _bsp_get_mtim16_base_address(timer);
    if (mtim16_ptr == NULL) return 0;

    period = (clk / tickfreq);
    while (period > (0xFFFF+1)) {
        prescale += 1;  /* divides clock in half */
        clk >>= 1;
        period = (clk / tickfreq);
    }

    _bsp_mtim16_clk_en(timer); /* enable clock to the MTIM */

    /* reset and stop counter */
    mtim16_ptr->MTIMSC = MTIM16_SC_TRST_MASK | MTIM16_SC_TSTP_MASK;

    /* set registers */
    mtim16_ptr->MTIMCLK = (uint_8) prescale;  
    mtim16_ptr->MTIMMOD = (uint_16) period - 1;

    /* start counter and enable interrupt (if desired) */
    mtim16_ptr->MTIMSC =  (unmask_timer ? MTIM16_SC_TOIE_MASK : 0);

    return period;
}


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mtim16_get_hwticks
* Returned Value  : Number of ticks
* Comments        :
*   This function will return the number of ticks elapsed since the last
* timer tick.
*
*END*---------------------------------------------------------------------*/
uint_32 _mtim16_get_hwticks
   (
      /* [IN] the timer to clear */
      pointer parameter
   )
{
    uint_8  timer = (uint_8)parameter;
    uint_32 ticks;
    uint_32 modulo;

    volatile MTIM16_STRUCT _PTR_  mtim16_ptr;
   
    mtim16_ptr = _bsp_get_mtim16_base_address(timer);
    if (mtim16_ptr == NULL) return 0;

    modulo = mtim16_ptr->MTIMMOD + 1;
    ticks = mtim16_ptr->MTIMCNT;

    if ((mtim16_ptr->MTIMSC & MTIM16_SC_TOF_MASK) != 0) {
        /* Another full TICK period has expired since we handled the last timer interrupt.
        We need to read the counter again, since the wrap may have
        occurred between the previous read and the checking of the overflow bit. */
        ticks = mtim16_ptr->MTIMCNT + modulo;
    }

    /* actual ticks in MTIMCNT + what we have missed because of sw prescaller */ 
    return ticks;
}


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mtim16_mask_int
* Returned Value  :
* Comments        :
*   This function will mask interrupt of given timer
*
*END*---------------------------------------------------------------------*/

void _mtim16_mask_int
    (
        /* [IN] the timer to use */
        uint_8    timer
    )
{
    volatile MTIM16_STRUCT _PTR_  mtim16_ptr;
   
    mtim16_ptr = _bsp_get_mtim16_base_address(timer);
    if (mtim16_ptr == NULL) return;

    mtim16_ptr->MTIMSC &= ~((uint_8)MTIM16_SC_TOIE_MASK);
}


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mtim16_unmask_int
* Returned Value  :
* Comments        :
*   This function will unmask interrupt of given timer
*
*END*---------------------------------------------------------------------*/

void _mtim16_unmask_int
    (
        /* [IN] the timer to use */
        uint_8    timer
    )
{
    volatile MTIM16_STRUCT _PTR_  mtim16_ptr;
   
    mtim16_ptr = _bsp_get_mtim16_base_address(timer);
    if (mtim16_ptr == NULL) return;

    /* clear interrupt flag first, then enable interrupt */
    mtim16_ptr->MTIMSC = (mtim16_ptr->MTIMSC & ~((uint_8)MTIM16_SC_TOF_MASK)) | MTIM16_SC_TOIE_MASK;
}


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mtim16_clear_int
* Returned Value  :
* Comments        :
*   This function will clear interrupt flag of given timer
*
*END*---------------------------------------------------------------------*/

void _mtim16_clear_int
    (
        /* [IN] the timer to use */
        uint_8    timer
    )
{
    volatile MTIM16_STRUCT _PTR_  mtim16_ptr;
   
    mtim16_ptr = _bsp_get_mtim16_base_address(timer);
    if (mtim16_ptr == NULL) return;

    mtim16_ptr->MTIMSC &= ~((uint_8)MTIM16_SC_TOF_MASK);
}

static void _mtim16_kernel_isr(pointer p) {
	/* Clear timer interrupt flag */
	_mtim16_clear_int(BSP_TIMER);
	_time_notify_kernel();
}
