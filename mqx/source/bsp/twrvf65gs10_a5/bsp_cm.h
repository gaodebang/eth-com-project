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
* $FileName: bsp_cm.h$
* $Version : 3.8.4.0$
* $Date    : Sep-25-2012$
*
* Comments:
*   Clock manager Vybrid specific definitions and prototypes.
*
*       _bsp_initialize_hardware();
*       _bsp_set_clock_configuration();
*       _bsp_get_clock_configuration();
*       _bsp_get_clock();
*       _bsp_osc_autotrim();
*
*END************************************************************************/

#ifndef __bsp_cm_h__
#define __bsp_cm_h__
#include <cm_vybrid.h>

#define CPU_CLOCK_CONFIG_NUMBER         0x01U /* Specifies number of defined sclock configurations. */

#define CPU_XTAL_CLK_HZ                 24000000UL /* Value of the external crystal or oscillator clock frequency in Hz */
#define CPU_XTAL32K_CLK_HZ              32768U /* Value of the external 32k crystal or oscillator clock frequency in Hz */

#define CPU_FAMILY_Vybrid              /* Specification of the core type of the selected cpu */
#define CPU_LITTLE_ENDIAN              /* The selected cpu uses little endian */

/* CPU frequencies in clock configuration 0 */
#define CPU_CLOCK_CONFIG_0              0x00U /* Clock configuration 0 identifier */
#define CPU_PLL_AUDIO_CLK_HZ_0          846720000UL   /* PLL4 clock frequency 0 - for 48000 with oversampling of 384 and 768  */
#define CPU_PLL_AUDIO_CLK_HZ_1          1128960000UL  /* PLL4 clock frequency 1 - for 44100 with oversampling from 256 to 768 */
#define CPU_PLL_AUDIO_CLK_HZ_2          1179648000UL  /* PLL4 clock frequency 2 - for 48000 with oversampling of 256 and 512  */
#define CPU_PLL_AUDIO_DENOM             0x1FFFFFDB    /* Audio PLL divider denominator */
#define CPU_PLL_AUDIO_NUM_0             0x08F5C285    /* Audio PLL divider numerator for frequency 0 */
#define CPU_PLL_AUDIO_NUM_1             0x0147AE13    /* Audio PLL divider numerator for frequency 1 */
#define CPU_PLL_AUDIO_NUM_2             0x04DD2F15    /* Audio PLL divider numerator for frequency 2 */

typedef enum {
    BSP_CLOCK_CONFIGURATION_0 = 0,      /* Default configuration */
    BSP_CLOCK_CONFIGURATIONS,           /* Number of available clock configurations */
    BSP_CLOCK_CONFIGURATION_DEFAULT     = BSP_CLOCK_CONFIGURATION_0
} BSP_CLOCK_CONFIGURATION;

#ifdef __cplusplus
extern "C" {
#endif

void _bsp_clock_manager_init(void);

BSP_CLOCK_CONFIGURATION _bsp_get_clock_configuration
(
    void
);

_mqx_int _bsp_set_clock_configuration
(
    BSP_CLOCK_CONFIGURATION clock_configuration
);

uint32_t _bsp_get_clock
(
    /* [IN] clock configuration */
    const BSP_CLOCK_CONFIGURATION   clock_configuration,
    /* [IN] clock source index */
    const CM_CLOCK_SOURCE           clock_source
);

uint32_t _bsp_set_clock
(
    /* [IN] desired frequency */
    const uint32_t        frequency,
    /* [IN] clock source index */
    const CM_CLOCK_SOURCE clock_source
);

#ifdef __cplusplus
}
#endif


#endif /* __bsp_cm_h__ */

