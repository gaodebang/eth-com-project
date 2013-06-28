/**HEADER********************************************************************
*
* Copyright (c) 2011 Freescale Semiconductor;
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
* $FileName: core_cnfg_mpxs30.h$
* $Version : 3.8.2.0$
* $Date    : Jun-7-2012$
*
* Comments:
*
*   This file contains the default core configuration options for the PXS30
*
*END***********************************************************************/

#ifndef __core_cnfg_mpxs30_h__
#define __core_cnfg_mpxs30_h__


#include <core_cnfg.h>

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_ADC_0
   #define CORECFG_ADC_0            (CORE_0|CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_ADC_1
   #define CORECFG_ADC_1            (CORE_0|CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_ADC_2
   #define CORECFG_ADC_2            (CORE_0|CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_ADC_3
   #define CORECFG_ADC_3            (CORE_0|CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_CAN_0
   #define CORECFG_CAN_0            (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_CAN_1
   #define CORECFG_CAN_1            (CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_CAN_2
   #define CORECFG_CAN_2            (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_CAN_3
   #define CORECFG_CAN_3            (CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_DMA_0  
   #define CORECFG_DMA_0            (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_DMA_1  
   #define CORECFG_DMA_1            (CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_ENET_0
   #define CORECFG_ENET_0           (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_ETIMER_0
   #define CORECFG_ETIMER_0         (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_ETIMER_1
   #define CORECFG_ETIMER_1         (CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_ETIMER_2
   #define CORECFG_ETIMER_2         (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_FLEXRAY  
   #define CORECFG_FLEXRAY          (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_I2C_0
   #define CORECFG_I2C_0            (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_I2C_1
   #define CORECFG_I2C_1            (CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_I2C_2
   #define CORECFG_I2C_2            (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_LINFLEX_0
   #define CORECFG_LINFLEX_0        (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_LINFLEX_1
   #define CORECFG_LINFLEX_1        (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_LINFLEX_2
   #define CORECFG_LINFLEX_2        (CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_LINFLEX_3
   #define CORECFG_LINFLEX_3        (CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_PDI  
   #define CORECFG_PDI              (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_PIT_0
   #define CORECFG_PIT_0            (CORE_0|CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_PIT_0_TIMER_0
   #define CORECFG_PIT_0_TIMER_0    (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_PIT_0_TIMER_1
   #define CORECFG_PIT_0_TIMER_1    (CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_PIT_0_TIMER_2
   #define CORECFG_PIT_0_TIMER_2    (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_PIT_0_TIMER_3
   #define CORECFG_PIT_0_TIMER_3    (CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_SEMA4_0
   #define CORECFG_SEMA4_0          (CORE_0|CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_SEMA4_1
   #define CORECFG_SEMA4_1          (CORE_0|CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_SPI_0
   #define CORECFG_SPI_0            (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_SPI_1
   #define CORECFG_SPI_1            (CORE_1)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_SPI_2
   #define CORECFG_SPI_2            (CORE_0)
#endif

/* MGCT: <option type="list">
** <item name="Core 0" value="(CORE_0)"/>
** <item name="Core 1" value="(CORE_1)"/>
** <item name="Core 0 &amp; 1" value="(CORE_0|CORE_1)"/>
** </option>
*/
#ifndef CORECFG_SIUL_0
   #define CORECFG_SIUL_0           (CORE_0|CORE_1)
#endif

#endif
