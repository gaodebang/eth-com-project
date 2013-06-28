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
* $Version : 3.8.2.0$
* $Date    : Jul-2-2012$
*
* Comments:
*
*   This file contains board-specific USB initialization functions.
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "bsp_prv.h"

/* This value is taken from linker file. We cannot use linker value, so we have to define it here.
** This approach is not clean, however it works if the IPSBAR is not changed during runtime.
*/
#undef  BSP_IPSBAR
#define BSP_IPSBAR (0xEC000000)
const struct usb_ehci_dev_init_struct _ehci0_dev_init_param = {
    (pointer)(&((VMCF5441_STRUCT_PTR)BSP_IPSBAR)->USBOTG),
    (pointer)((uint_32)&(((VMCF5441_STRUCT_PTR)BSP_IPSBAR)->USBOTG) + 0x100),
    (pointer)((uint_32)&(((VMCF5441_STRUCT_PTR)BSP_IPSBAR)->USBOTG) + 0x080),
    (pointer) &(((VMCF5441_STRUCT_PTR)BSP_IPSBAR)->CCM).UOCSR,
    MCF5441_INT_USB_OTG, //vector
    3  //priority
};

const struct usb_ehci_host_init_struct _ehci0_host_init_param = {
    (pointer)(&((VMCF5441_STRUCT_PTR)BSP_IPSBAR)->USBOTG),
    (pointer)((uint_32)&(((VMCF5441_STRUCT_PTR)BSP_IPSBAR)->USBOTG) + 0x100),
    (pointer)((uint_32)&(((VMCF5441_STRUCT_PTR)BSP_IPSBAR)->USBOTG) + 0x080),
    BSP_EHCI_FS,
    MCF5441_INT_USB_OTG, //vector
    3,  //priority
    1024 //size of periodic list [items]
};

const struct usb_ehci_host_init_struct _ehci1_host_init_param = {
    (pointer)(&((VMCF5441_STRUCT_PTR)BSP_IPSBAR)->USBHOST),
    (pointer)((uint_32)&(((VMCF5441_STRUCT_PTR)BSP_IPSBAR)->USBHOST) + 0x100),
    (pointer)((uint_32)&(((VMCF5441_STRUCT_PTR)BSP_IPSBAR)->USBHOST) + 0x080),
    BSP_EHCI_FS,
    MCF5441_INT_USB_HOST, //vector
    3,  //priority
    1024 //size of periodic list [items]
};

const pointer _bsp_usb_table[] = 
{
    (pointer) &_ehci0_dev_init_param,
    (pointer) &_ehci0_host_init_param,
    (pointer) &_ehci1_host_init_param
};
