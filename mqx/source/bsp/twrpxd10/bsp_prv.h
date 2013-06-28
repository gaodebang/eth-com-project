#ifndef _bsp_prv_h_
#define _bsp_prv_h_ 1
/**HEADER********************************************************************
*
* Copyright (c) 2008-2011 Freescale Semiconductor;
* All Rights Reserved                       
*
* Copyright (c) 2004-2011 Embedded Access Inc.;
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
* $Version : 3.8.2.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This file contains the definitions of constants and structures
*   required for initialization of the card.
*
*END************************************************************************/

/*
**  FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif


/* I/O initialization controlled by initialization structures for each
** channel
*/
extern const LINFLEXD_SERIAL_INIT_STRUCT _bsp_linflexd0_init;
extern const LINFLEXD_SERIAL_INIT_STRUCT _bsp_linflexd1_init;
extern const LWADC_INIT_STRUCT _lwadc0_init;

extern const SPI_INIT_STRUCT _bsp_spi0_init;
extern const SPI_INIT_STRUCT _bsp_spi1_init;

extern const QI2C_INIT_STRUCT _bsp_i2c0_init;
extern const QI2C_INIT_STRUCT _bsp_i2c1_init;
extern const QI2C_INIT_STRUCT _bsp_i2c2_init;
extern const QI2C_INIT_STRUCT _bsp_i2c3_init;

extern const FLASHX_INIT_STRUCT _bsp_data_flashx_init;
extern const FLASHX_INIT_STRUCT _bsp_code_flashx_init;
extern const FLASHX_FILE_BLOCK _bsp_flashx_file_blocks[];


extern void    __init(void);       /* Diab Data */
extern void    __init_cpp(void);   /* Codewarrior */
extern void    _ExitProcess(void); /* Codewarrior */

extern void    _bsp_exit_handler(void);
extern void    _bsp_timer_isr(pointer);
extern void    _bsp_program_isr(pointer);
extern void    _bsp_init_pll(void);
extern uint_32 _bsp_get_hwticks(pointer);

extern void _bsp_uart_init(void);
extern void _bsp_uart_dcr_config(uint_32, uint_32);

extern void    __interrupt_vector_table(void);
extern void    __ivor0(void);
extern void    __machine_check(void); // not normal 8 instrs
extern void    __ivor2(void);
extern void    __ivor3(void);
extern void    __ivor4(void);
extern void    __ivor5(void);
extern void    __ivor6(void);
extern void    __ivor7(void);
extern void    __ivor8(void);
extern void    __ivor9(void);
extern void    __ivor10(void);
extern void    __ivor11(void);
extern void    __ivor12(void);
extern void    __ivor13(void);
extern void    __ivor14(void);
extern void    __ivor15(void);
extern void    __ivor32(void);
extern void    __ivor33(void);
extern void    __ivor34(void);


#ifdef __cplusplus
}
#endif

#endif
/* EOF */
