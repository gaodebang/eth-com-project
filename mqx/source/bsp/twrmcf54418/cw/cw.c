/**HEADER********************************************************************
* 
* Copyright (c) 2008- Freescale Semiconductor;
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
* $FileName: cw.c$
* $Version : 3.8.10.0$
* $Date    : Oct-3-2011$
*
* Comments:
*
*   This file contains runtime support for the CodeWarrior.
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"

#if BSPCFG_ENABLE_CPP
typedef void (*initializer_fcn_t)(void);
extern initializer_fcn_t __sinit__[];
#endif /* BSPCFG_ENABLE_CPP */

void    __destroy_global_chain(void);

/* CodeWarrior overrides prototypes */
void    __initialize_hardware(void);
#if BSPCFG_ENABLE_CPP
void __cpp_init(void);
static void __cpp_fini(void);
#endif /* BSPCFG_ENABLE_CPP */
int  exit(int);
pointer malloc(_mem_size);
pointer calloc(_mem_size, _mem_size);
void    free(pointer);

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : __initialize_hardware
* Returned Value   : void
* Comments         :
*   Initialize special CPU registers
*
*END*----------------------------------------------------------------------*/
#if   __REGABI__
    __declspec(register_abi)
#elif __STDABI__
    __declspec(standard_abi)
#endif
asm void __initialize_hardware(void)
{
    move.w #0x2700,sr

    clr.l   d0
    movec   d0,cacr
    movec   d0,acr0
    movec   d0,acr1

    move.l  d0,_psp_saved_cacr
    move.l  d0,_psp_saved_acr0
    move.l  d0,_psp_saved_acr1
    rts
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : __cpp_init
* Returned Value   : void
* Comments         :
*   Override C++ initializer of static instances
*
*END*----------------------------------------------------------------------*/
#if BSPCFG_ENABLE_CPP
void __cpp_init(void)
{ 
   initializer_fcn_t *constructor;

   /* call constructor of static instances, ctors in codewarrior 10 is not used anymore */
   for (constructor = __sinit__; *constructor; constructor++) {
      (*constructor)();
   } 
}
#endif /* BSPCFG_ENABLE_CPP */

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : __cpp_fini
* Returned Value   : void
* Comments         :
*   Override C++ deinitializer of static instances
*
*END*----------------------------------------------------------------------*/
#if BSPCFG_ENABLE_CPP
static void __cpp_fini(void)
{
   /* 
   initializer_fcn_t *destructor;
   */
   /* call destructor of static instances */
   /*
   for (destructor = _dtors; *destructor; destructor++) {
      (*destructor)();
   }
   */ 
} 
#endif /* BSPCFG_ENABLE_CPP */

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : exit
* Returned Value   : should not return
* Comments         :
*   Replacement for Codewarrior's exit function
*
*END*----------------------------------------------------------------------*/
#if MQX_EXIT_ENABLED
int exit(int status)
{ 
   // Semi-normal Codewarrior shutdown sequence
#if BSPCFG_ENABLE_CPP
   __destroy_global_chain();
   __cpp_fini();
#endif

   /*
   ** Change for whatever is appropriate for your board
   ** and application.  Perhaps a software reset or
   ** some kind of trap/call to the kernel soft re-boot.
   */
   for(;;) {
      volatile uint_8 a = 0;
   }

   return(0);
}

#else  /* MQX_EXIT_ENABLED */

int exit(int status) 
{
    return 0;
}

#endif /* MQX_EXIT_ENABLED */ 

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : malloc
* Returned Value   : pointer
* Comments         :
*   Override C/C++ runtime heap allocation function
*
*END*----------------------------------------------------------------------*/
pointer malloc(_mem_size bytes) 
{
    return _mem_alloc_system(bytes);
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : calloc
* Returned Value   : pointer
* Comments         :
*   Override C/C++ runtime heap deallocation
*
*END*----------------------------------------------------------------------*/
pointer calloc(_mem_size n, _mem_size z)
{
    return _mem_alloc_system_zero(n*z);
} 

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : free
* Returned Value   : void
* Comments         :
*   Override C/C++ runtime free 
*
*END*----------------------------------------------------------------------*/
void free(pointer p) 
{
    _mem_free(p);
}

/* EOF */
