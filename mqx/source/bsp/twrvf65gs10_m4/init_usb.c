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
* $FileName: init_usb.c$
* $Version : 3.8.1.0$
* $Date    : Sep-25-2012$
*
* Comments:
*
*   This file contains board-specific USB initialization functions.
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "bsp_prv.h"

const struct usb_ehci_dev_init_struct _ehci0_dev_init_param = {
    (pointer)USB0_BASE_PTR,
    (uchar_ptr)USB0_BASE_PTR + 0x100,
    (uchar_ptr)USB0_BASE_PTR + 0x80,
    NULL,
    INT_USB0 - 32, //vector for M4 core is not setup in the processor header file
    3           //priority
};

const struct usb_ehci_host_init_struct _ehci0_host_init_param = {
    (pointer)USB0_BASE_PTR,
    (uchar_ptr)USB0_BASE_PTR + 0x100,
    (uchar_ptr)USB0_BASE_PTR + 0x80,
    /* The speed of the EHCI host controller is set to HS */
    BSP_EHCI_HS, //speed: HS
    INT_USB0 - 32, //vector for M4 core is not setup in the processor header file
    3,           //priority
    1024           //size of periodic list [items]
};

const struct usb_ehci_dev_init_struct _ehci1_dev_init_param = {
    (pointer)USB1_BASE_PTR,
    (uchar_ptr)USB1_BASE_PTR + 0x100,
    (uchar_ptr)USB1_BASE_PTR + 0x80,
    NULL,
    INT_USB1 - 32, //vector for M4 core is not setup in the processor header file
    3           //priority
};

const struct usb_ehci_host_init_struct _ehci1_host_init_param = {
    (pointer)USB1_BASE_PTR,
    (uchar_ptr)USB1_BASE_PTR + 0x100,
    (uchar_ptr)USB1_BASE_PTR + 0x80,
    /* The speed of the EHCI host controller is set to HS */
    BSP_EHCI_HS, //speed: HS
    INT_USB1 - 32, //vector for M4 core is not setup in the processor header file
    3,           //priority
    1024           //size of periodic list [items]
};

const pointer _bsp_usb_table[] = 
{
    (pointer) &_ehci0_dev_init_param,
    (pointer) &_ehci0_dev_init_param,
    (pointer) &_ehci0_host_init_param,
    (pointer) &_ehci0_host_init_param
};
