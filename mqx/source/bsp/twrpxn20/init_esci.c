/**HEADER********************************************************************
*
* Copyright (c) 2011 Freescale Semiconductor;
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
* $FileName: init_esci.c$
* $Version : 3.8.3.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This file contains the definition for the baud rate for the serial
*   channel
*
*END************************************************************************/

#include "mqx.h"
#include "bsp.h"

const LIN_SERIAL_INIT_STRUCT _bsp_lin0_init = {
    /* Com port number     */ 0,
    /* Queue size          */ 256,
    /* Clock speed         */ BSP_PERI1_CLOCK,
    /* Baud rate           */ 115200,
    /* Bits per character  */ 8,                       /* 7 or 8*/
    /* Parity              */ IO_SERIAL_PARITY_NONE,   /* No parity only valid if bpc=8*/
    /* Stop bits           */ IO_SERIAL_STOP_BITS_1,   /* Must be 1*/
    /* Int. Prio           */ 8
};

const LIN_SERIAL_INIT_STRUCT _bsp_lin1_init = {
    /* Com port number     */ 1,
    /* Queue size          */ 256,
    /* Clock speed         */ BSP_PERI1_CLOCK,
    /* Baud rate           */ 115200,
    /* Bits per character  */ 8,                       /* 7 or 8*/
    /* Parity              */ IO_SERIAL_PARITY_NONE,   /* No parity only valid if bpc=8*/
    /* Stop bits           */ IO_SERIAL_STOP_BITS_1,   /* Must be 1*/
    /* Int. Prio           */ 8
};

const LIN_SERIAL_INIT_STRUCT _bsp_lin2_init = {
    /* Com port number     */ 2,
    /* Queue size          */ 256,
    /* Clock speed         */ BSP_PERI1_CLOCK,
    /* Baud rate           */ 115200,
    /* Bits per character  */ 8,                       /* 7 or 8*/
    /* Parity              */ IO_SERIAL_PARITY_NONE,   /* No parity only valid if bpc=8*/
    /* Stop bits           */ IO_SERIAL_STOP_BITS_1,   /* Must be 1*/
    /* Int. Prio           */ 8
};

const LIN_SERIAL_INIT_STRUCT _bsp_lin3_init = {
    /* Com port number     */ 3,
    /* Queue size          */ 256,
    /* Clock speed         */ BSP_PERI1_CLOCK,
    /* Baud rate           */ 115200,
    /* Bits per character  */ 8,                       /* 7 or 8*/
    /* Parity              */ IO_SERIAL_PARITY_NONE,   /* No parity only valid if bpc=8*/
    /* Stop bits           */ IO_SERIAL_STOP_BITS_1,   /* Must be 1*/
    /* Int. Prio           */ 8
};

const LIN_SERIAL_INIT_STRUCT _bsp_lin4_init = {
    /* Com port number     */ 4,
    /* Queue size          */ 256,
    /* Clock speed         */ BSP_PERI1_CLOCK,
    /* Baud rate           */ 115200,
    /* Bits per character  */ 8,                       /* 7 or 8*/
    /* Parity              */ IO_SERIAL_PARITY_NONE,   /* No parity only valid if bpc=8*/
    /* Stop bits           */ IO_SERIAL_STOP_BITS_1,   /* Must be 1*/
    /* Int. Prio           */ 8
};

const LIN_SERIAL_INIT_STRUCT _bsp_lin5_init = {
    /* Com port number     */ 5,
    /* Queue size          */ 256,
    /* Clock speed         */ BSP_PERI1_CLOCK,
    /* Baud rate           */ 115200,
    /* Bits per character  */ 8,                       /* 7 or 8*/
    /* Parity              */ IO_SERIAL_PARITY_NONE,   /* No parity only valid if bpc=8*/
    /* Stop bits           */ IO_SERIAL_STOP_BITS_1,   /* Must be 1*/
    /* Int. Prio           */ 8
};
