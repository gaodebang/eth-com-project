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
* $FileName: int_ctrl_mcfplus.h$
* $Version : 3.8.4.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains definitions for the ColdFire+ interrupt controller
*
*END*************************************************************************/
#ifndef __int_ctrl_mcfplus_h__
    #define __int_ctrl_mcfplus_h__

/* type definitions */
typedef uchar _int_level;

#ifdef __cplusplus
extern "C" {
#endif

/* function prototypes */
extern void    _mcfplus_int_unmask_all(void);
extern void    _mcfplus_int_mask_all(void);
extern uint_32 _mcfplus_int_mask(uint_32);
extern uint_32 _mcfplus_int_unmask(uint_32);

#ifdef __cplusplus
}
#endif

#endif /* __int_ctrl_mcfplus_h__ */
/* EOF */
