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
* $FileName: twrpxd10.h$
* $Version : 3.8.3.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This include file is used to provide information needed by
*   an application program using the kernel running on the 
*   Freescale 5675K Evaluation board.
*
*END*********************************************************************/

#ifndef __twrpxd10_h__
#define __twrpxd10_h__

#ifdef __cplusplus
extern "C" {
#endif




/**                  HARDWARE INITIALIZATION DEFINITIONS
*/

/*
** Define the board type
*/
#define BSP_TWRPXD10                    1
#define BSP_NAME                        "TWRPXD10"

#define tBOARD                        "Freescale " BSP_NAME
#define tCPU                          "MPXD10"



/*----------------------------------------------------------------------
**            Signal Assignments
*/
#define ADC0_AN0            (30)
#define ADC0_AN1            (31)
#define ADC0_AN2            (32)
#define ADC0_AN3            (33)
#define ADC0_AN4            (34)
#define ADC0_AN5            (35)
#define ADC0_AN6            (36)
#define ADC0_AN7            (37)
#define ADC0_AN8            (38)
#define ADC0_AN9            (39)
#define ADC0_AN10           (40)
#define ADC0_AN11           (41)
#define ADC0_AN12           (42)
#define ADC0_AN13           (43)
#define ADC0_AN14           (44)
#define ADC0_AN15           (45)

#define BSP_BUTTON1         (131)
#define BSP_BUTTON2         (72)

#define BSP_LED1            (111)
#define BSP_LED2            (112)

#define LIN0_TXD            (18)
#define LIN0_RXD            (19)
#define LIN1_TXD            (29)
#define LIN1_RXD            (28)


#define I2C0_SCL            (77)
#define I2C0_SDA            (76)
#define I2C1_SCL            (79)
#define I2C1_SDA            (78)
#define I2C2_SCL            (8)
#define I2C2_SDA            (9)
#define I2C3_SCL            (86)
#define I2C3_SDA            (87)


#define DSPI0_SCK           (25)
#define DSPI0_SOUT          (24)
#define DSPI0_SIN           (23)
#define DSPI0_CS0           (103)
#define DSPI1_SCK           (20)
#define DSPI1_SOUT          (21)
#define DSPI1_SIN           (22)
#define DSPI1_CS0           (43)

#define FlexCAN0_TX         (16)
#define FlexCAN0_RX         (17)
#define FlexCAN1_TX         (27)
#define FlexCAN1_RX         (26)
     

#define BSP_BUTTON1_MUX_GPIO 0
#define BSP_BUTTON2_MUX_GPIO 0
#define BSP_LED1_MUX_GPIO  (SIUL_PCR_SMC_MASK)
#define BSP_LED2_MUX_GPIO  (SIUL_PCR_SMC_MASK)


/*----------------------------------------------------------------------
**           MMU CONFIGURATION
*/
//extern uchar __PRIVATE_RAM_START[];
//extern uchar __PRIVATE_RAM_SIZE[];
//extern uchar __SHARED_RAM_START[];
//extern uchar __SHARED_RAM_SIZE[]; 
//extern uchar __UNCACHED_DATA_START[];
//extern uchar __UNCACHED_DATA_SIZE[]; 
//extern uchar __UNCACHED_DATA_END[];
//
//#define BSP_PRIVATE_RAM_START           (pointer)__PRIVATE_RAM_START
//#define BSP_PRIVATE_RAM_SIZE            (uint_32)__PRIVATE_RAM_SIZE
//
//
//#define BSP_UNCACHED_DATA_START         (pointer)__UNCACHED_DATA_START
//#define BSP_UNCACHED_DATA_SIZE          (uint_32)__UNCACHED_DATA_SIZE
//
//#define BSP_PRIVATE_RAM_ATTR            (PSP_MMU_WRITE_THROUGH|PSP_MMU_EXEC_ALLOWED|PSP_MMU_PAGE_LOCKED)   
//#define BSP_UNCACHED_DATA_ATTR          (PSP_MMU_CACHE_INHIBITED|PSP_MMU_WRITE_THROUGH|PSP_MMU_EXEC_ALLOWED|PSP_MMU_PAGE_LOCKED)



/*----------------------------------------------------------------------
**            TIMER DRIVER CONFIGURATION
*/
/** MGCT: <category name="BSP Hardware Options"> */
/*
** The clock tick rate in miliseconds - be cautious to keep this value such
** that it divides 1000 well.
** MGCT: <option type="number" min="1" max="1000"/>
*/
#ifndef  BSP_ALARM_FREQUENCY
    #define BSP_ALARM_FREQUENCY         (200)
#endif
/** MGCT: </category> */ 
/*
** Old clock rate definition in milliseconds per tick for compatibility
*/
#define BSP_ALARM_RESOLUTION            (1000 / BSP_ALARM_FREQUENCY)

/* Set to 1 if Core Time Base uses External clock as input clock */
#define BSP_TIMEBASE_USES_EXTERNAL_CLK  0

#ifdef BSPCFG_TIMER_PIT_DEVICE
#define BSP_TIMER_INTERRUPT_VECTOR        _bsp_get_qpit_vector(BSPCFG_TIMER_PIT_DEVICE, BSPCFG_TIMER_PIT_CHANNEL)
#define BSP_TIMER_INTERRUPT_PRIORITY      BSPCFG_TIMER_INT_LEVEL
#else
#define BSP_TIMER_INTERRUPT_VECTOR        PSP_EXCPT_DECREMENTER
#endif


/*----------------------------------------------------------------------
**           CLOCK CONFIGURATION
*/

/*
** The processor clock speed
*/
#define BSP_XOSC_CLOCK                  (8000000) 
#define BSP_FMPLL0_CLOCK                (64000000) 

#define BSP_SYSTEM_CLOCK                (BSP_FMPLL0_CLOCK)

#define BSP_CORE_CLOCK                  (BSP_SYSTEM_CLOCK)
#define BSP_TIMEBASE_CLOCK              (BSP_CORE_CLOCK)

#define BSP_PERI1_CLOCK                 (BSP_SYSTEM_CLOCK/2)
#define BSP_PERI2_CLOCK                 (BSP_SYSTEM_CLOCK/2)
#define BSP_PERI3_CLOCK                 (BSP_SYSTEM_CLOCK/2)

#define BSP_I2C_CLOCK                   (BSP_PERI1_CLOCK)
#define BSP_MOTC_CLOCK                  (BSP_PERI3_CLOCK)

#define BSP_CLKOUT_DIV                  (4) 

#define SYSTEM_CLOCK                    (BSP_SYSTEM_CLOCK/1000000)       /* system bus frequency in MHz */


/*----------------------------------------------------------------------
**           INTERRUPT CONTROLLER CONFIGURATION
*/

/* Define the range of interrupts for which the application can install
** isrs.
*/

#define BSP_FIRST_INTERRUPT_VECTOR_USED   PSP_EXCPT_CRITICAL
#define BSP_LAST_INTERRUPT_VECTOR_USED    QINTC_LAST_VECTOR

/*
** The following macros are needed by the i/o drivers to prevent
** pipeline side effects
*/
#undef  _BSP_IO_EIEIO
#define _BSP_IO_EIEIO   _PSP_EIEIO()
#undef  _BSP_IO_SYNC
#define _BSP_IO_SYNC    _PSP_SYNC()
#undef  _BSP_IO_ISYNC
#define _BSP_IO_ISYNC   _PSP_ISYNC()

/*-----------------------------------------------------------------------------
**            DSPI DRIVER CONFIGURATION
*/
#define BSP_DSPI_RX_BUFFER_SIZE          (32)
#define BSP_DSPI_TX_BUFFER_SIZE          (32)
#define BSP_DSPI_BAUDRATE                (1000000)
#define BSP_DSPI_INT_LEVEL               (4)

#define BSP_SPI_MEMORY_CHANNEL           1

/*----------------------------------------------------------------------
**            SDCard DRIVER CONFIGURATION
*/
#define BSP_SDCARD_SPI_CHANNEL           "spi1:"
#define BSP_SDCARD_SPI_CS                1

#define BSP_SDCARD_GPIO_DETECT           131 //23
#define BSP_SDCARD_DETECT_MUX_GPIO       0

/*----------------------------------------------------------------------
**            SERIAL IO DEVICE DRIVER CONFIGURATION
*/
/** MGCT: <category name="I/O Subsystem"> */

/*
** Enable I/O subsystem features in MQX. No I/O drivers and file I/O will be 
** possible without this feature.
** 
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_IO_SUBSYSTEM
    #define BSPCFG_ENABLE_IO_SUBSYSTEM      1
#endif
/** MGCT: </category> */ 

/** MGCT: <category name="Default Driver Installation in BSP startup"> */

/** MGCT: <category name="LINFLEXD0 Settings"> */

/*
** Polled TTY device (LINFLEXD0) 
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_TTYA
    #define BSPCFG_ENABLE_TTYA              1
#endif

/*
** Interrupt-driven TTY device (LINFLEXD0)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ITTYA
    #define BSPCFG_ENABLE_ITTYA             1
#endif

/** MGCT: </category> */ 

/** MGCT: <category name="LINFLEXD1 Settings"> */

/*
** Polled TTY device (LINFLEXD1) 
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_TTYB
    #define BSPCFG_ENABLE_TTYB              1
#endif

/*
** Interrupt-driven TTY device (LINFLEXD1)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ITTYB
    #define BSPCFG_ENABLE_ITTYB             1
#endif
/** MGCT: </category> */ 


#ifndef BSPCFG_DEFAULT_LINFLEXD_BAUD_RATE
    #define BSPCFG_DEFAULT_LINFLEXD_BAUD_RATE    115200
#endif

/* TTYA and ITTYA baud rate */
#ifndef BSPCFG_LINFLEXD0_BAUD_RATE
    #define BSPCFG_LINFLEXD0_BAUD_RATE           BSPCFG_DEFAULT_LINFLEXD_BAUD_RATE
#endif

/* TTYB and ITTYB baud rate */
#ifndef BSPCFG_LINFLEXD1_BAUD_RATE
    #define BSPCFG_LINFLEXD1_BAUD_RATE           BSPCFG_DEFAULT_LINFLEXD_BAUD_RATE
#endif


#ifndef BSPCFG_DEFAULT_LINFLEXD_QUEUE_SIZE
    #define BSPCFG_DEFAULT_LINFLEXD_QUEUE_SIZE   64
#endif

/* TTYA and ITTYA buffer size */
#ifndef BSPCFG_LINFLEXD0_QUEUE_SIZE
    #define BSPCFG_LINFLEXD0_QUEUE_SIZE          BSPCFG_DEFAULT_LINFLEXD_QUEUE_SIZE
#endif

/* TTYB and ITTYB buffer size */
#ifndef BSPCFG_LINFLEXD1_QUEUE_SIZE
    #define BSPCFG_LINFLEXD1_QUEUE_SIZE          BSPCFG_DEFAULT_LINFLEXD_QUEUE_SIZE
#endif


/* ITTYA interrupt priority */
#ifndef BSPCFG_LINFLEXD0_PRIORITY
    #define BSPCFG_LINFLEXD0_PRIORITY            8
#endif

/* ITTYB interrupt priority */
#ifndef BSPCFG_LINFLEXD1_PRIORITY
    #define BSPCFG_LINFLEXD1_PRIORITY            8
#endif

/*----------------------------------------------------------------------
**            I2C DRIVER CONFIGURATION
*/
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_I2C0
    #define BSPCFG_ENABLE_I2C0             0
#endif
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_II2C0
    #define BSPCFG_ENABLE_II2C0            0
#endif
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_I2C1
    #define BSPCFG_ENABLE_I2C1             0
#endif
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_II2C1
    #define BSPCFG_ENABLE_II2C1            0
#endif
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_I2C2
    #define BSPCFG_ENABLE_I2C2             0
#endif

#ifndef BSPCFG_ENABLE_II2C2
    #define BSPCFG_ENABLE_II2C2            0
#endif
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_I2C3
    #define BSPCFG_ENABLE_I2C3             0
#endif
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_II2C3
    #define BSPCFG_ENABLE_II2C3            0
#endif

#if BSPCFG_ENABLE_I2C2
     #define BSPCFG_DEFAULT_I2C_DEVICE     "i2c2:"
#endif

#if BSPCFG_ENABLE_II2C2
     #define BSPCFG_DEFAULT_II2C_DEVICE    "ii2c2:"
#endif

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_SPI0
    #define BSPCFG_ENABLE_SPI0             0
#endif
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ISPI0
    #define BSPCFG_ENABLE_ISPI0            0
#endif
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_SPI1
    #define BSPCFG_ENABLE_SPI1             0
#endif
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ISPI1
    #define BSPCFG_ENABLE_ISPI1            0
#endif
/** MGCT: </category> */ 

#define BSP_I2C0_ADDRESS                              (0x6E)
#define BSP_I2C1_ADDRESS                              (0x6F)
#define BSP_I2C2_ADDRESS                              (0x6C)
#define BSP_I2C3_ADDRESS                              (0x6D)
#define BSP_I2C0_BAUD_RATE                            (400000)
#define BSP_I2C1_BAUD_RATE                            (100000)
#define BSP_I2C2_BAUD_RATE                            (100000)
#define BSP_I2C3_BAUD_RATE                            (100000)
#define BSP_I2C0_MODE                                 (I2C_MODE_MASTER)
#define BSP_I2C1_MODE                                 (I2C_MODE_MASTER)
#define BSP_I2C2_MODE                                 (I2C_MODE_MASTER)
#define BSP_I2C3_MODE                                 (I2C_MODE_MASTER)
#define BSP_I2C0_INT_LEVEL                            (1)
#define BSP_I2C1_INT_LEVEL                            (1)
#define BSP_I2C2_INT_LEVEL                            (1)
#define BSP_I2C3_INT_LEVEL                            (1)
#define BSP_I2C0_RX_BUFFER_SIZE                       (64)
#define BSP_I2C0_TX_BUFFER_SIZE                       (64)
#define BSP_I2C1_RX_BUFFER_SIZE                       (64)
#define BSP_I2C1_TX_BUFFER_SIZE                       (64)
#define BSP_I2C2_RX_BUFFER_SIZE                       (64)
#define BSP_I2C2_TX_BUFFER_SIZE                       (64)
#define BSP_I2C3_RX_BUFFER_SIZE                       (64)
#define BSP_I2C3_TX_BUFFER_SIZE                       (64)

/** MGCT: <category name="Default Driver Configuration"> */
/*----------------------------------------------------------------------
**            FLEXCAN DRIVER CONFIGURATION
*/
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_FLEXCAN_CALCULATE_BIT_TIMING
    #define BSPCFG_FLEXCAN_CALCULATE_BIT_TIMING         1
#endif

#define FLEXCAN_IPBUS_CLK                             (BSP_PERI2_CLOCK) 
#define FLEXCAN_OSC_CLK                               (BSP_XOSC_CLOCK)


/*----------------------------------------------------------------------
**            LWADC DRIVER CONFIGURATION
*/
/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_LWADC
#define BSPCFG_ENABLE_LWADC 1
#endif
/*
** MGCT: <option type="bool"/>
*/
#if BSPCFG_ENABLE_LWADC
#ifndef BSPCFG_ENABLE_LWADC0
    #define BSPCFG_ENABLE_LWADC0 1
#endif
#endif

#define BSP_ADC_VREF_DEFAULT        3300 /* in millivolts */
#define BSP_ADC_POTENTIOMETER_MAX   3300 /* in millivolts */
#define MPXD10_ADC_NUM_CHANNELS     16
#define MPXD10_ADC_NUM_DEVICE       1

#define BSP_ADC_POTENTIOMETER       ADC_INPUT_ADC0_AN38
#define BSP_ADC_TWR_AN0             ADC_INPUT_ADC0_AN38
#define BSP_ADC_TWR_AN1             ADC_INPUT_ADC0_AN39
#define BSP_ADC_TWR_AN2             ADC_INPUT_ADC0_AN40
#define BSP_ADC_TWR_AN3             ADC_INPUT_ADC0_AN41
#define BSP_ADC_TWR_AN4             ADC_INPUT_ADC0_AN42
#define BSP_ADC_TWR_AN5             ADC_INPUT_ADC0_AN43

/*----------------------------------------------------------------------
**                  DEFAULT MQX INITIALIZATION DEFINITIONS
*/

extern uchar __KERNEL_DATA_START[];
extern uchar __KERNEL_DATA_END[];
#define BSP_DEFAULT_START_OF_KERNEL_MEMORY           (pointer)__KERNEL_DATA_START
#define BSP_DEFAULT_END_OF_KERNEL_MEMORY             (pointer)__KERNEL_DATA_END
#define BSP_DEFAULT_PROCESSOR_NUMBER                 (1L)
#define BSP_DEFAULT_INTERRUPT_STACK_SIZE             (2048L)
#define BSP_DEFAULT_MQX_HARDWARE_INTERRUPT_LEVEL_MAX (6L)
#define BSP_DEFAULT_MAX_MSGPOOLS                     (16L)
#define BSP_DEFAULT_MAX_MSGQS                        (128L)

#ifndef BSP_DEFAULT_IO_CHANNEL
/*
 * Serial console options:(do not forget to enable BSPCFG_ENABLE_TTY define if changed)
 *      "ttyb:"      TWR-SER      polled mode; J10 on position 2-3, J11 on position 2-3
 *      "ittyb:"     TWR-SER      interrupt mode; J10 on position 2-3, J11 on position 2-3
 *      "ttyb:"      OSBDM       polled mode; J10 on position 1-2, J11 on position 1-2
 *      "ittyb:"     OSBDM       interrupt mode; J10 on position 1-2, J11 on position 1-2
 ** MGCT: <option type="string" maxsize="256" quoted="false" allowempty="false"/> 
 */
    #if BSPCFG_ENABLE_TTYB
        #define BSP_DEFAULT_IO_CHANNEL               "ttyb:"
        #define BSP_DEFAULT_IO_CHANNEL_DEFINED       1
    #elif BSPCFG_ENABLE_ITTYB
        #define BSP_DEFAULT_IO_CHANNEL               "ittyb:"
        #define BSP_DEFAULT_IO_CHANNEL_DEFINED       1
    #else
        #define BSP_DEFAULT_IO_CHANNEL               NULL
    #endif
#endif

#define BSP_DEFAULT_IO_OPEN_MODE                     (pointer) \
   (IO_SERIAL_XON_XOFF | IO_SERIAL_TRANSLATION | IO_SERIAL_ECHO)

#ifdef __cplusplus
}
#endif
/** MGCT: </category> */ 
#endif

/* EOF */
