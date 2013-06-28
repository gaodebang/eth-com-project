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
* $FileName: bsp_cm.c$
* $Version : 3.8.5.0$
* $Date    : Oct-2-2012$
*
* Comments:
*   Clock manager Vybrid BSP specific definitions and function prototypes.
*
*       _bsp_initialize_hardware();
*       _bsp_set_clock_configuration();
*       _bsp_get_clock_configuration();
*       _bsp_get_clock();
*       _bsp_osc_autotrim();
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include <bsp_prv.h>
#include <bsp_cm.h>
#include <lwsem.h>

/* Clock Manager Errors  */
#define ERR_OK          CM_ERR_OK               /* OK */
#define ERR_SPEED       CM_ERR_SPEED            /* This device does not work in the active speed mode. */
#define ERR_RANGE       CM_ERR_RANGE            /* Parameter out of range. */
#define ERR_VALUE       CM_ERR_VALUE            /* Parameter of incorrect value. */
#define ERR_FAILED      CM_ERR_FAILED           /* Requested functionality or process failed. */
#define ERR_PARAM_MODE  CM_ERR_PARAM_MODE       /* Invalid mode. */

/* Global variables */
static uint8_t ClockConfigurationID = CPU_CLOCK_CONFIG_0; /* Active clock configuration */
static uint32_t Pll4ClockInHz = 0; /* PLL4 clock frequency in Hz */
static LWSEM_STRUCT pll4sem; /* Semaphore for protection of PLL4 setup critical sections */                          
/*
** ===================================================================
**     Method      :  Cpu_GetClockConfiguration
**
**     Description :
**         Returns the active clock configuration identifier.
**     Parameters  : None
**     Returns     :
**         ---             - Active clock configuration identifier
** ===================================================================
*/
uint8_t Cpu_GetClockConfiguration(void)
{
  return ClockConfigurationID;         /* Return the actual clock configuration identifier */
}
/*
** ===================================================================
**     Method      :  _bsp_get_clock_configuration
**
**     Description :
**         Returs the active clock configuration identifier.
**     Parameters  : None
**     Returns     :
**         ---             - Active clock configuration identifier
** ===================================================================
*/
BSP_CLOCK_CONFIGURATION _bsp_get_clock_configuration
(
    void
)
{
    return (BSP_CLOCK_CONFIGURATION)Cpu_GetClockConfiguration();
}
/*
** ===================================================================
**     Method      :  _bsp_set_clock_configuration
**
**     Description :
**         Placeholder for clock configuration setting
**     Parameters  : clock configuration
**     Returns     :
**         ---            zero
** ===================================================================
*/
_mqx_int _bsp_set_clock_configuration(BSP_CLOCK_CONFIGURATION clock_configuration)
{
    return(0);
}

/*
** ===================================================================
**     Method      :  _bsp_clock_manager_init
**
**     Description :
**         Placeholder for clock configuration setting
**     Parameters  : clock configuration
**     Returns     :
**         ---            zero
** ===================================================================
*/
void _bsp_clock_manager_init(void)
{
    /* initialize semaphore */
    _lwsem_create(&pll4sem, 1);
}

/*
** ===================================================================
**     Method      :  _bsp_get_clock
**
**     Description :
**         This function returns clock freqency in Hertz for clock source
**         and configuration selected by parameters.     
**     Parameters  : clock configuration, clock source
**     Returns     :
**         ---      Clock freqenecy in Hertz
** ===================================================================
*/
uint32_t _bsp_get_clock
(
    const BSP_CLOCK_CONFIGURATION   clock_configuration,
    const CM_CLOCK_SOURCE           clock_source
)
{
    if (clock_source == CM_CLOCK_SOURCE_PLL_AUDIO)
    {
        Anadig_MemMapPtr anadig = Anadig_BASE_PTR;
        /* integer part of divider */
        uint32_t mfi = (anadig->PLL4_CTRL & Anadig_PLL4_CTRL_DIV_SELECT_MASK) >> Anadig_PLL4_CTRL_DIV_SELECT_SHIFT;
        /* divider numerator */
        uint32_t mfn = anadig->PLL4_NUM;
        /* divider denominator */
        uint32_t mfd = anadig->PLL4_DENOM;
        
        /* If function is called after PLL4 clock change, recalculate global Pll4clockInHz */
        _lwsem_wait(&pll4sem);
        if (!Pll4ClockInHz)
        {
            /* If PLL4 is active and locked */
            if ((anadig->PLL4_CTRL & (Anadig_PLL4_CTRL_LOCK_MASK | Anadig_PLL4_CTRL_ENABLE_MASK)) &&
               !(anadig->PLL4_CTRL & (Anadig_PLL4_CTRL_BYPASS_CLK_SRC_MASK | Anadig_PLL4_CTRL_POWERDOWN_MASK)))
            {
                Pll4ClockInHz = (uint_32) ((CPU_XTAL_CLK_HZ * mfi) + ((long long) CPU_XTAL_CLK_HZ * mfn) / mfd);
            }
            else
            {
                _lwsem_post(&pll4sem);
                return(0);
            }
        }
        _lwsem_post(&pll4sem);
        return (Pll4ClockInHz);
    }

    switch (clock_source)
    {
        case CM_CLOCK_SOURCE_CORE:
            return BSP_CORE_CLOCK;

        case CM_CLOCK_SOURCE_BUS:
            return BSP_BUS_CLOCK;

        case CM_CLOCK_SOURCE_IPG:
            return BSP_IPG_CLOCK;
    }

    return(0);    
}

/*
** ===================================================================
**     Method      :  _bsp_set_clock
**
**     Description :
**         This function set clock freqency for clock source
**         selected by parameter.     
**     Parameters  : frequency in Hertz, clock source
**     Returns     :
**         ---       Freqency of clock selected source in Hertz - 
**                   value matches actual frequency of source.
** ===================================================================
*/
uint32_t _bsp_set_clock
(
    const uint32_t        frequency,
    const CM_CLOCK_SOURCE clock_source
)
{
    if (clock_source == CM_CLOCK_SOURCE_PLL_AUDIO)
    {
        Anadig_MemMapPtr anadig = Anadig_BASE_PTR;

        /* If PLL4 is disabled, bypassed or powered down return */
        if (anadig->PLL4_CTRL & (Anadig_PLL4_CTRL_BYPASS_CLK_SRC_MASK | Anadig_PLL4_CTRL_POWERDOWN_MASK) ||
           !(anadig->PLL4_CTRL & Anadig_PLL4_CTRL_ENABLE_MASK))    
        {
            return(0);
        }
        /* Lock PLL4 */
        _lwsem_wait(&pll4sem);

        /* Disable PLL4 */
        anadig->PLL4_CTRL &= (~Anadig_PLL4_CTRL_ENABLE_MASK);
        
        anadig->PLL4_DENOM = CPU_PLL_AUDIO_DENOM;
        /* Frequency lower or same as minimum */
        if (frequency <= CPU_PLL_AUDIO_CLK_HZ_0)
        {
            anadig->PLL4_NUM = CPU_PLL_AUDIO_NUM_0;
            anadig->PLL4_CTRL = (anadig->PLL4_CTRL & ~Anadig_PLL4_CTRL_DIV_SELECT_MASK) | Anadig_PLL4_CTRL_DIV_SELECT(0x23);
        }
        /* Frequency between PLL freq. 0 and 1 */
        else if (frequency <= CPU_PLL_AUDIO_CLK_HZ_1)
        {
            /* lower half*/
            if (frequency <= (CPU_PLL_AUDIO_CLK_HZ_0 + (CPU_PLL_AUDIO_CLK_HZ_1 - CPU_PLL_AUDIO_CLK_HZ_0) / 2))
            {
                anadig->PLL4_NUM = CPU_PLL_AUDIO_NUM_0;
                anadig->PLL4_CTRL = (anadig->PLL4_CTRL & ~Anadig_PLL4_CTRL_DIV_SELECT_MASK) | Anadig_PLL4_CTRL_DIV_SELECT(0x23);
            }
            /* upper half */
            else
            {
                anadig->PLL4_NUM = CPU_PLL_AUDIO_NUM_1;
                anadig->PLL4_CTRL = (anadig->PLL4_CTRL & ~Anadig_PLL4_CTRL_DIV_SELECT_MASK) | Anadig_PLL4_CTRL_DIV_SELECT(0x2F);
            }
        }
        /* Frequency between PLL freq. 1 and 2 */
        else if (frequency <= CPU_PLL_AUDIO_CLK_HZ_2)
        {
            /* lower half*/
            if (frequency <= (CPU_PLL_AUDIO_CLK_HZ_1 + (CPU_PLL_AUDIO_CLK_HZ_2 - CPU_PLL_AUDIO_CLK_HZ_1) / 2))
            {
                anadig->PLL4_NUM = CPU_PLL_AUDIO_NUM_1;
                anadig->PLL4_CTRL = (anadig->PLL4_CTRL & ~Anadig_PLL4_CTRL_DIV_SELECT_MASK) | Anadig_PLL4_CTRL_DIV_SELECT(0x2F);
            }
            /* upper half */
            else
            {
                anadig->PLL4_NUM = CPU_PLL_AUDIO_NUM_2;
                anadig->PLL4_CTRL = (anadig->PLL4_CTRL & ~Anadig_PLL4_CTRL_DIV_SELECT_MASK) | Anadig_PLL4_CTRL_DIV_SELECT(0x31);
            }
        }
        /* Frequency higher or same as maximum */
        else
        {
            anadig->PLL4_NUM = CPU_PLL_AUDIO_NUM_2;
            anadig->PLL4_CTRL = (anadig->PLL4_CTRL & ~Anadig_PLL4_CTRL_DIV_SELECT_MASK) | Anadig_PLL4_CTRL_DIV_SELECT(0x31);
        }
        anadig->PLL4_CTRL |= (Anadig_PLL4_CTRL_ENABLE_MASK);

        /* Change in PLL4 dividers, so set global Pll4ClockInHz to zero -> in will be recalculated */
        Pll4ClockInHz = 0;
        _lwsem_post(&pll4sem);
        return(_bsp_get_clock(_bsp_get_clock_configuration(), clock_source));
    }
    return(0);
}
