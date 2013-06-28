#ifndef _i2s_mcf54xx_h
#define _i2s_mcf54xx_h 1
/**HEADER********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
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
* $FileName: i2s_mcf54xx.h$
* $Version : 3.8.2.0$
* $Date    : Oct-7-2011$
*
* Comments:
*
*   This include file is used to provide information needed by
*   applications using the I2S I/O functions.
*
*END************************************************************************/

#include "i2s_audio.h"

#define BIT16_MAX 32767
/*--------------------------------------------------------------------------*/
/*
**                    DATATYPE DECLARATIONS
*/

/*
** MCF54XX_I2S_INIT_STRUCT
**
** This structure defines the initialization parameters to be used
** when a serial port is initialized.
*/
typedef struct mcf54xx_i2s_init_struct
{
    /* The I2S channel to initialize */
    uint_8              CHANNEL;

    /* Default operating mode */
    uint_8              MODE;

    /* Number of valid data bits*/
    uint_8              DATA_BITS;

    /* SSI_CLOCK source*/
    uint_8              CLOCK_SOURCE;

    /* Data are stereo */
    boolean             STEREO;

    /* Transmit dummy data */
    boolean             TX_DUMMY;

    /* Interrupt level to use */
    _int_level          LEVEL;

    /* Tx buffer size */
    uint_32             BUFFER_SIZE;

    /* I/O data format */
    AUDIO_DATA_FORMAT   const * IO_FORMAT;

} MCF54XX_I2S_INIT_STRUCT, _PTR_ MCF54XX_I2S_INIT_STRUCT_PTR;
typedef const MCF54XX_I2S_INIT_STRUCT _PTR_ MCF54XX_I2S_INIT_STRUCT_CPTR;

/*--------------------------------------------------------------------------*/
/*
**                        FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

    extern uint_32 _mcf54xx_i2s_int_install (char_ptr, MCF54XX_I2S_INIT_STRUCT_CPTR);
    extern pointer _bsp_get_i2s_base_address (uint_8);
    extern uint_32 _bsp_get_i2s_vector (uint_8);
    extern _mqx_int _bsp_i2s_io_init(uint_8, uint_8, uint_8);
    extern _mqx_int _bsp_i2s_hw_init(MCF54XX_I2S_INIT_STRUCT_PTR, VMCF5441_SSI_STRUCT_PTR);
#ifdef __cplusplus
}
#endif

#endif
/* EOF */
