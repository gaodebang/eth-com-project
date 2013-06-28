/**HEADER********************************************************************
*
* Copyright (c) 2008-2011 Freescale Semiconductor;
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
* $FileName: mqx_init.c$
* $Version : 3.8.1.0$
* $Date    : Oct-5-2011$
*
* Comments:
*
*   This file contains the source for the default MQX INITIALIZATION
*   STRUCTURE
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"

extern TASK_TEMPLATE_STRUCT MQX_template_list[];
const TASK_TEMPLATE_STRUCT MQX_template_list_1[] = {0};

const MQX_INITIALIZATION_STRUCT  MQX_init_struct = 
{
   /* PROCESSOR_NUMBER                */  BSP_CORE_0_PROCESSOR_NUMBER,
    /* START_OF_KERNEL_MEMORY          */  BSP_DEFAULT_START_OF_KERNEL_MEMORY,
    /* END_OF_KERNEL_MEMORY            */  BSP_DEFAULT_END_OF_KERNEL_MEMORY,
   /* INTERRUPT_STACK_SIZE            */  BSP_CORE_0_INTERRUPT_STACK_SIZE,
    /* TASK_TEMPLATE_LIST              */  (pointer)MQX_template_list,
   /* MQX_HARDWARE_INTERRUPT_LEVEL_MAX*/  BSP_CORE_0_MQX_HARDWARE_INTERRUPT_LEVEL_MAX,
   /* MAX_MSGPOOLS                    */  BSP_CORE_0_MAX_MSGPOOLS,
   /* MAX_MSGQS                       */  BSP_CORE_0_MAX_MSGQS,
   /* IO_CHANNEL                      */  BSP_CORE_0_IO_CHANNEL,
   /* IO_OPEN_MODE                    */  BSP_CORE_0_IO_OPEN_MODE
};

const MQX_INITIALIZATION_STRUCT  MQX_init_struct_1 = 
{
   /* PROCESSOR_NUMBER                */  BSP_CORE_1_PROCESSOR_NUMBER,
   /* START_OF_KERNEL_MEMORY          */  BSP_DEFAULT_START_OF_KERNEL_MEMORY,
   /* END_OF_KERNEL_MEMORY            */  BSP_DEFAULT_END_OF_KERNEL_MEMORY,
   /* INTERRUPT_STACK_SIZE            */  BSP_CORE_1_INTERRUPT_STACK_SIZE,
   /* TASK_TEMPLATE_LIST              */  (pointer)MQX_template_list_1,
   /* MQX_HARDWARE_INTERRUPT_LEVEL_MAX*/  BSP_CORE_1_MQX_HARDWARE_INTERRUPT_LEVEL_MAX,
   /* MAX_MSGPOOLS                    */  BSP_CORE_1_MAX_MSGPOOLS,
   /* MAX_MSGQS                       */  BSP_CORE_1_MAX_MSGQS,
   /* IO_CHANNEL                      */  BSP_CORE_1_IO_CHANNEL,
   /* IO_OPEN_MODE                    */  BSP_CORE_1_IO_OPEN_MODE
};

/* EOF */
