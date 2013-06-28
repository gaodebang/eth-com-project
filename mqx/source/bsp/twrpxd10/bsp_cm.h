/**HEADER***********************************************************************
*
* Copyright (c) 2012 Freescale Semiconductor;
* All Rights Reserved
*
********************************************************************************
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
********************************************************************************
*
* $FileName: bsp_cm.h$
* $Version : 3.8.1.0$
* $Date    : Oct-2-2012$
*
* Comments:
*   Implementation of subset of clock manager API to provide clock frequencies
*   on platforms without full-featured clock manager
*
*       _bsp_get_clock_configuration();
*       _bsp_get_clock();
*
*END***************************************************************************/

#ifndef __bsp_cm_h__
#define __bsp_cm_h__ 1


typedef enum {
    BSP_CLOCK_CONFIGURATION_0 = 0,
    BSP_CLOCK_CONFIGURATIONS,    /* Number of available clock configurations */
    BSP_CLOCK_CONFIGURATION_DEFAULT = BSP_CLOCK_CONFIGURATION_0
} BSP_CLOCK_CONFIGURATION;


typedef enum {
    CM_CLOCK_SOURCE_XOSC = 0,
    CM_CLOCK_SOURCE_FMPLL0,
    CM_CLOCK_SOURCE_PERI1,
    CM_CLOCK_SOURCE_PERI2,
    CM_CLOCK_SOURCE_PERI3,

    /* Number of clock sources available */
    CM_CLOCK_SOURCES,

    /* Aliases */
    CM_CLOCK_SOURCE_SYSTEM = CM_CLOCK_SOURCE_FMPLL0,
    CM_CLOCK_SOURCE_CORE = CM_CLOCK_SOURCE_SYSTEM,
    CM_CLOCK_SOURCE_TIMEBASE = CM_CLOCK_SOURCE_CORE
} CM_CLOCK_SOURCE;


#ifdef __cplusplus
extern "C" {
#endif


BSP_CLOCK_CONFIGURATION _bsp_get_clock_configuration(void);


uint_32 _bsp_get_clock(
    /* [IN] clock configuration */
    const BSP_CLOCK_CONFIGURATION   clock_configuration,
    /* [IN] clock source index */
    const CM_CLOCK_SOURCE           clock_source
);


#ifdef __cplusplus
}
#endif


#endif /* __bsp_cm_h__ */
