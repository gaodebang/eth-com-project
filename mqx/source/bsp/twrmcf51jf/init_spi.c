/**HEADER*********************************************************************
*
* Copyright (c) 2009 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 1989-2009 ARC International;
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
* $FileName: init_spi.c$
* $Version : 3.8.3.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains the definition for the baud rate for the SPI
*   channel
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>

/*
** parameters of spi0 initialization
*/

const SPI16_INIT_STRUCT _bsp_spi0_init = {
/* Channel                          */  0,
/* Chip select                      */  SPI16_CS0,
/* Input Clock [Hz]                 */  BSP_SPI_CLOCK,
/* Baud Rate                        */  BSP_SPI0_BAUDRATE,
/* RX Buffer Size (interrupt only)  */  BSP_SPI0_RX_BUFFER_SIZE,
/* TX Buffer Size (interrupt only)  */  BSP_SPI0_TX_BUFFER_SIZE,
/* Int Vector                       */  Vspi0,
/* Transfer mode                    */  SPI_DEVICE_MASTER_MODE,
/* Clock phase                      */  SPI_CLK_POL_PHA_MODE0
};

/*
** parameters of spi1 initialization
*/

const SPI16_INIT_STRUCT _bsp_spi1_init = {
/* Channel                          */  1,
/* Chip select                      */  SPI16_CS0,
/* Input Clock [Hz]                 */  BSP_SPI_CLOCK,
/* Baud Rate                        */  BSP_SPI1_BAUDRATE,
/* RX Buffer Size (interrupt only)  */  BSP_SPI1_RX_BUFFER_SIZE,
/* TX Buffer Size (interrupt only)  */  BSP_SPI1_TX_BUFFER_SIZE,
/* Int Vector                       */  Vspi1,
/* Transfer mode                    */  SPI_DEVICE_MASTER_MODE,
/* Clock phase                      */  SPI_CLK_POL_PHA_MODE0
};


/* EOF */
