/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2008 Embedded Access Inc.;
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
* $FileName: timer_mcf51jf.c$
* $Version : 3.8.4.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains timer functions for use with a MCF51JF.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include "timer_mtim16.h"

#define MTIM16_TIMERS 1

static _mqx_uint _mtim16_vectors[] =
{
	BSP_TIMER_INTERRUPT_VECTOR
};

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_mtim16_vector
* Returned Value   : Vector number upon success, 0 upon failure
* Comments         :
* 	 This function returns interrupt vector number of the corresponding MTIM
*
*END*----------------------------------------------------------------------*/
_mqx_uint _bsp_get_mtim16_vector(uint_8 timer) {
	if (timer > (MTIM16_TIMERS - 1)) {
		return 0;
	} else {
		return _mtim16_vectors[timer];
	}
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_mtim16_base_address
* Returned Value   : Address upon success, NULL upon failure
* Comments         :
*    This function returns the base register address of the corresponding MTIM
*
*END*----------------------------------------------------------------------*/
pointer _bsp_get_mtim16_base_address (uint_8 timer)
{
    switch (timer) {
        case 0: return (pointer)MTIM0_BASE_PTR;
    }
    return NULL;
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_mtim16_clk_en
* Returned Value   : Address upon success, NULL upon failure
* Comments         :
*    This function enables clock to corresponding MTIM
*
*END*----------------------------------------------------------------------*/
void _bsp_mtim16_clk_en (uint_8 timer)
{
    switch (timer) {
        case 0:
        	SIM_SCGC3_REG(SIM_BASE_PTR) |= SIM_SCGC3_MTIM_MASK;
          break;
    }
}
