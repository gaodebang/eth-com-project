/**HEADER*********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
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
* $FileName: boot.c$
* $Version : 3.8.4.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*    This file contains the boot and boot exception code.
*
*END**************************************************************************/

#include "mqx_inc.h"
#include "bsp.h"
#include "bsp_prv.h"

/* imported data */
extern unsigned long far _SDA_BASE[];
extern unsigned long far __BOOT_STACK_ADDRESS[];

/* imported routines */
extern void _start(void);

/* exported routines */
asm __declspec(register_abi) void __boot(void);
asm __declspec(register_abi) void __boot_exception(void);


/*  Assume we could start here via the debugger or jump here at any time */
asm __declspec(register_abi) void __boot(void)
{
    /* disable interrupts */
    move.w      #0x2700,sr

    /* setup the stack pointer */
    lea        __BOOT_STACK_ADDRESS, a7

    /* setup A6 dummy stackframe */
    movea.l     #0,a6
    link        a6,#0

    /* setup interrupt vector table */
    move.l #__VECTOR_TABLE_ROM_START, d0
    movec d0, VBR

    /* initialize any hardware specific issues */
    jsr    __init_hardware

    /* jump to the compiler _start function */
    jmp     _start
}


asm __declspec(register_abi) void __boot_exception(void)
{
    halt
    rte
}
