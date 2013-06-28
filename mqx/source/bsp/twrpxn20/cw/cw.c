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
* $Version : 3.8.2.0$
* $Date    : Oct-2-2012$
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
__declspec(section ".init") extern initializer_fcn_t _ctors[];
__declspec(section ".init") extern initializer_fcn_t _dtors[];
#endif /* BSPCFG_ENABLE_CPP */

/* CodeWarrior overrides prototypes */
#if BSPCFG_ENABLE_CPP
void __cpp_init(void);
void __cpp_fini(void);
#endif /* BSPCFG_ENABLE_CPP */
int  exit(int);
pointer malloc(_mem_size);
pointer calloc(_mem_size, _mem_size);
void    free(pointer);

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

   /* call constructor of static instances */
   for (constructor = _ctors; *constructor; constructor++) {
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
   initializer_fcn_t *destructor;

   /* call destructor of static instances */
   for (destructor = _dtors; *destructor; destructor++) {
      (*destructor)();
   } 
} 
#endif /* BSPCFG_ENABLE_CPP */

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : exit
* Returned Value   : none
* Comments         :
*   Final exit function
*
*END*----------------------------------------------------------------------*/
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
