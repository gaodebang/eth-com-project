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
* $FileName: cm_vybrid.h$
* $Version : 3.8.2.0$
* $Date    : Oct-1-2012$
*
* Comments:
*   Clock manager Vybrid specific definitions.
*
*END************************************************************************/

#ifndef __cm_vybrid_h__
#define __cm_vybrid_h__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PE_LDD_VERSION
    
typedef struct  {
    uint32_t cpu_pll4_clk_hz;
} TCpuClockConfiguration;
    
#endif  /* PE_LDD_VERSION */

typedef enum  {
    CM_CLOCK_SOURCE_CORE = 0,
    CM_CLOCK_SOURCE_BUS,
    CM_CLOCK_SOURCE_IPG,
    CM_CLOCK_SOURCE_PLL_AUDIO,
    CM_CLOCK_SOURCES,            /* Number of clock sources available */
    CM_CLOCK_SOURCE_SYSTEM = CM_CLOCK_SOURCE_CORE
} CM_CLOCK_SOURCE;

#ifdef __cplusplus
}
#endif


#endif /* __cm_vybrid_h__ */
