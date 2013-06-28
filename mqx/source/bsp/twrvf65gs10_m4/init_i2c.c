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
* $FileName: init_i2c.c$
* $Version : 3.8.0.2$
* $Date    : Sep-27-2012$
*
* Comments:
*
*   This file contains the definition for the baud rate for the I2C
*   channel
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>

const QI2C_INIT_STRUCT _bsp_i2c0_init = {
    0,                      /* I2C channel    */
    BSP_I2C0_MODE,          /* I2C mode       */
    BSP_I2C0_ADDRESS,       /* I2C address    */
    BSP_I2C0_BAUD_RATE,     /* I2C baud rate  */
    BSP_I2C0_INT_LEVEL,     /* I2C int level  */
    BSP_I2C0_TX_BUFFER_SIZE,/* I2C int tx buf */
    BSP_I2C0_RX_BUFFER_SIZE /* I2C int rx buf */
};

const QI2C_INIT_STRUCT _bsp_i2c1_init = {
    1,                      /* I2C channel    */
    BSP_I2C1_MODE,          /* I2C mode       */
    BSP_I2C1_ADDRESS,       /* I2C address    */
    BSP_I2C1_BAUD_RATE,     /* I2C baud rate  */
    BSP_I2C1_INT_LEVEL,     /* I2C int level  */
    BSP_I2C1_TX_BUFFER_SIZE,/* I2C int tx buf */
    BSP_I2C1_RX_BUFFER_SIZE /* I2C int rx buf */
};

const QI2C_INIT_STRUCT _bsp_i2c2_init = {
    2,                      /* I2C channel    */
    BSP_I2C2_MODE,          /* I2C mode       */
    BSP_I2C2_ADDRESS,       /* I2C address    */
    BSP_I2C2_BAUD_RATE,     /* I2C baud rate  */
    BSP_I2C2_INT_LEVEL,     /* I2C int level  */
    BSP_I2C2_TX_BUFFER_SIZE,/* I2C int tx buf */
    BSP_I2C2_RX_BUFFER_SIZE /* I2C int rx buf */
};

const QI2C_INIT_STRUCT _bsp_i2c3_init = {
    3,                      /* I2C channel    */
    BSP_I2C3_MODE,          /* I2C mode       */
    BSP_I2C3_ADDRESS,       /* I2C address    */
    BSP_I2C3_BAUD_RATE,     /* I2C baud rate  */
    BSP_I2C3_INT_LEVEL,     /* I2C int level  */
    BSP_I2C3_TX_BUFFER_SIZE,/* I2C int tx buf */
    BSP_I2C3_RX_BUFFER_SIZE /* I2C int rx buf */
};
