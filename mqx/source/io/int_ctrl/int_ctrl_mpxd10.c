/**HEADER********************************************************************
*
* Copyright (c) 2011 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2011 Embedded Access Inc.;
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
* $FileName: int_ctrl_mpxd10.c$
* $Version : 3.8.1.0$
* $Date    : Sep-26-2012$
*
* Comments:
*
*   This file contains the source functions for the INTC driver.
*
*END************************************************************************/

#include "mqx_inc.h"
#include "bsp.h"
#include "psp.h"


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_get_qintc_base_address
* Returned Value   : none
* Comments         :
*    Get base address of interrupt controller
*
*END*------------------------------------------------------------------------*/

VQINTC_REG_STRUCT_PTR _bsp_get_qintc_base_address(void)
{
	return (VQINTC_REG_STRUCT_PTR) MPXD10_INTC_BASE;
}