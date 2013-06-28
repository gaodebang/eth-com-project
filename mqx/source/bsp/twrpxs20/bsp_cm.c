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
* $FileName: bsp_cm.c$
* $Version : 3.8.1.0$
* $Date    : Sep-25-2012$
*
* Comments:
*   Implementation of subset of clock manager API to provide clock frequencies
*   on platforms without full-featured clock manager
*
*       _bsp_get_clock_configuration();
*       _bsp_get_clock();
*
*END***************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include <bsp_prv.h>



static const uint_32 cm_clock_freq[BSP_CLOCK_CONFIGURATIONS][CM_CLOCK_SOURCES] = {
  /* Clock configuration 0 */
  {
      BSP_XOSC_CLOCK,
      BSP_FMPLL0_CLOCK,
      BSP_FMPLL1_CLOCK
  }
};



BSP_CLOCK_CONFIGURATION _bsp_get_clock_configuration
(
    void
)
{
    return BSP_CLOCK_CONFIGURATION_0;
}


uint_32 _bsp_get_clock
(
    const BSP_CLOCK_CONFIGURATION   clock_configuration,
    const CM_CLOCK_SOURCE           clock_source
)
{
    if ((clock_source < CM_CLOCK_SOURCES) && (clock_configuration < BSP_CLOCK_CONFIGURATIONS))
    {
        return cm_clock_freq[clock_configuration][clock_source];
    }
    else
    {
        return 0;
    }
}
