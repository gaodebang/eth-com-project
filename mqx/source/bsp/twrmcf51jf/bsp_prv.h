/**HEADER*********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
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
* $FileName: bsp_prv.h$
* $Version : 3.8.5.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains the definitions of constants and structures
*   required for initialization of the card.
*
*END*************************************************************************/

#ifndef __bsp_prv_h__
    #define __bsp_prv_h__

#include "PE_LDD.h"
#ifdef PE_LDD_VERSION
    #include "PDD_Types.h"
#endif


/* Include BSP private header files */
#include "flash_mcf51jf.h"


/*
** I/O initialization controlled by initialization structures for each channel
*/

extern const KADC_INIT_STRUCT           _bsp_adc0_init;
extern const KPDB_INIT_STRUCT           _bsp_pdb0_init;

extern const KUART_INIT_STRUCT          _bsp_uart0_init;
extern const KUART_INIT_STRUCT          _bsp_uart1_init;

extern const SPI16_INIT_STRUCT          _bsp_spi0_init;
extern const SPI16_INIT_STRUCT          _bsp_spi1_init;

extern const KI2C_INIT_STRUCT           _bsp_i2c0_init;
extern const KI2C_INIT_STRUCT           _bsp_i2c1_init;
extern const KI2C_INIT_STRUCT           _bsp_i2c2_init;
extern const KI2C_INIT_STRUCT           _bsp_i2c3_init;

extern const FLASHX_FILE_BLOCK          _bsp_flashx_file_blocks[];
extern const FLASHX_INIT_STRUCT         _bsp_flashx_init;
extern const PCCARDFLEXBUS_INIT_STRUCT  _bsp_cfcard_init;

extern const KUSB_DCD_INIT_STRUCT       _bsp_usb_dcd_init;

#ifdef __cplusplus
extern "C" {
#endif

/*
**  FUNCTION PROTOTYPES
*/

extern void __init_hardware(void);
extern void __cpp_init(void);

extern void _bsp_exit_handler(void);
extern void _bsp_timer_isr(pointer);
extern void _bsp_flexbus_pccard_setup (const uint_32 base_address);

#ifdef __cplusplus
}
#endif

#endif /* __bsp_prv_h__ */
/* EOF */

