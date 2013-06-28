/**HEADER********************************************************************
* 
* Copyright (c) 2008-2011 Freescale Semiconductor;
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
* $FileName: ds5.c$
* $Version : 3.8.1.0$
* $Date    : Sep-13-2012$
*
* Comments:
*
*   This file contains runtime support for the KEIL Compiler.
*
*END************************************************************************/
#include "mqx.h"
#include "bsp.h"

int __aeabi_atexit(pointer, pointer, pointer);
pointer malloc(unsigned int);
pointer calloc(unsigned int, unsigned int);
void free(pointer);

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : __aeabi_atexit
* Returned Value   : int
* Comments         :
*   Override C/C++ runtime __aeabi_atexit function in KEIL
*   to avoid the call to malloc and free before MQX starts
*   http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.faqs/ka3951.html
*
*END*----------------------------------------------------------------------*/
int __aeabi_atexit(pointer object_ptr, pointer destructor_ptr, pointer __dso_handle_ptr)
{
   return 1;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : malloc
* Returned Value   : pointer
* Comments         :
*   Override C/C++ runtime heap allocation function in KEIL
*
*END*----------------------------------------------------------------------*/

pointer malloc(unsigned int bytes)
{
  return _mem_alloc_system(bytes);
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : calloc
* Returned Value   : pointer
* Comments         :
*   Override C/C++ runtime heap allocation function in KEIL
*
*END*----------------------------------------------------------------------*/

pointer calloc(unsigned int n, unsigned int z)
{
   return _mem_alloc_system_zero(n*z);
} 

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : free
* Returned Value   : void
* Comments         :
*   Override C/C++ runtime heap deallocation function in KEIL
*
*END*----------------------------------------------------------------------*/

void free(pointer p)
{
   _mem_free(p);
}
