/**HEADER********************************************************************
* 
* Copyright (c) 2010 Freescale Semiconductor;
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
* $FileName: bsp_prv.h$
* $Version : 3.8.4.0$
* $Date    : Oct-3-2012$
*
* Comments:
*
*   This file contains the definitions of constants and structures
*   required for initialization of the card.
*
*END************************************************************************/
#ifndef _bsp_prv_h
#define _bsp_prv_h 1

#ifdef __cplusplus
extern "C" {
#endif


/*
**  FUNCTION PROTOTYPES
*/
  
void    __init(void);

uint_32 _bsp_get_hwticks(pointer);
void    _bsp_exit_handler(void);
void    _bsp_timer_isr(pointer);

void init_gic(void);


/*
**  STRUCTURE DEFINITIONS
*/

/* I/O initialization controlled by initialization structures for each channel */
extern const KUART_INIT_STRUCT _bsp_sci0_init;
extern const KUART_INIT_STRUCT _bsp_sci1_init;
extern const KUART_INIT_STRUCT _bsp_sci2_init;
extern const KUART_INIT_STRUCT _bsp_sci3_init;
extern const KUART_INIT_STRUCT _bsp_sci4_init;
extern const KUART_INIT_STRUCT _bsp_sci5_init;

extern const ESDHC_INIT_STRUCT _bsp_esdhc0_init;
extern const ESDHC_INIT_STRUCT _bsp_esdhc1_init;
extern const LWADC_INIT_STRUCT lwadc0_init;
extern const LWADC_INIT_STRUCT lwadc1_init;
extern const SPI_INIT_STRUCT _bsp_spi0_init;
extern const SPI_INIT_STRUCT _bsp_spi1_init;
extern const SPI_INIT_STRUCT _bsp_spi2_init;

extern const QI2C_INIT_STRUCT _bsp_i2c0_init;
extern const QI2C_INIT_STRUCT _bsp_i2c1_init;
extern const QI2C_INIT_STRUCT _bsp_i2c2_init;
extern const QI2C_INIT_STRUCT _bsp_i2c3_init;

extern const USB_EHCI_HOST_INIT_STRUCT _ehci0_host_init_param;
extern const USB_EHCI_HOST_INIT_STRUCT _ehci1_host_init_param;

#ifdef __cplusplus
}
#endif

#endif
/* EOF */

