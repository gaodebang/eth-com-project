/**HEADER********************************************************************
*
* Copyright (c) 2008-2012 Freescale Semiconductor;
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
* $FileName: comp.c$
* $Version : 3.8.2.0$
* $Date    : Oct-3-2012$
*
* Comments:
*
*   This file contains runtime support for the Codesourcery GCC.
*
*END************************************************************************/

#include <stdio.h>
#include "mqx.h"

pointer malloc(_mem_size);
pointer calloc(_mem_size, _mem_size);
void    free(pointer);

void *__dso_handle = NULL;


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : __cxa_atexit
* Returned Value   : int
* Comments         : 
*   Dummy function which avoid GCC to register destructors of global objects. 
*   By default GCC use '__cxa_atexit' function which register destructors
*   to LIFO. When LIFO is full, it performs malloc, but at this point
*   there is no heap, so malloc fails. 
*
*END*----------------------------------------------------------------------*/

int __cxa_atexit (void (*fn) (void *), void *arg, void *d)
{
    return 0;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _init
* Returned Value   : void
* Comments         :
*   Perform custom action before main
*
*END*----------------------------------------------------------------------*/

void _init(void)
{
    ;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _fini
* Returned Value   : void
* Comments         :
*   Perform custom action before exit
*
*END*----------------------------------------------------------------------*/

void _fini(void)
{
    ;
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
* Function Name    : _malloc_r
* Returned Value   : pointer
* Comments         :
*   Override C/C++ reentrant runtime heap allocation function
*
*END*----------------------------------------------------------------------*/

pointer _malloc_r(pointer reent, size_t nbytes)
{
    return _mem_alloc_system(nbytes);
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
*   Override C/C++ runtime heap deallocation function
*
*END*----------------------------------------------------------------------*/

void free(pointer p)
{
    _mem_free(p);
}

