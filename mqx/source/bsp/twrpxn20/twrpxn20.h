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
* $FileName: twrpxn20.h$
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

#ifndef __twrpxn20_h__
#define __twrpxn20_h__

#ifdef __cplusplus
extern "C" {
#endif




/**                  HARDWARE INITIALIZATION DEFINITIONS
*/

/*
** Define the board type
*/
#define BSP_TWRPXN20                    1
#define BSP_NAME                        "TWRPXN20"

#define tBOARD                        "Freescale " BSP_NAME
#define tCPU                          "PXN20"



/*----------------------------------------------------------------------
**            Signal Assignments
*/
#define ADC0_AN0            (0)
#define ADC0_AN1            (1)
#define ADC0_AN2            (2)
#define ADC0_AN3            (3)
#define ADC0_AN4            (4)
#define ADC0_AN5            (5)
#define ADC0_AN6            (6)
#define ADC0_AN7            (7)
#define ADC0_AN8            (8)
#define ADC0_AN9            (9)
#define ADC0_AN10           (10)
#define ADC0_AN11           (11)
#define ADC0_AN12           (12)
#define ADC0_AN13           (13)

#define BSP_BUTTON1         (24)
#define BSP_BUTTON2         (25)

#define BSP_ACCEL_IRQ       (29)
#define BSP_LED1            (128)
#define BSP_LED2            (129)

#define LIN0_TXD            (60)
#define LIN0_RXD            (61)
#define LIN1_TXD            (62)
#define LIN1_RXD            (63)
#define LIN2_TXD            (64)
#define LIN2_RXD            (65)
#define LIN3_TXD            (66)
#define LIN3_RXD            (67)
#define LIN4_TXD            (68)
#define LIN4_RXD            (69)
#define LIN5_TXD            (70)
#define LIN5_RXD            (71)

#define I2C0_SCL            (78)
#define I2C0_SDA            (79)
#define I2C1_SCL            (100)
#define I2C1_SDA            (101)
#define I2C2_SCL            (98)
#define I2C2_SDA            (99)
#define I2C3_SCL            (58)
#define I2C3_SDA            (59)


#define DSPI0_SCK           (80)
#define DSPI0_SOUT          (81)
#define DSPI0_SIN           (82)
#define DSPI0_CS0           (83)
#define DSPI1_SCK           (84)
#define DSPI1_SOUT          (85)
#define DSPI1_SIN           (86)
#define DSPI1_CS0           (87)
#define DSPI2_SCK           (88)
#define DSPI2_SOUT          (89)
#define DSPI2_SIN           (90)
#define DSPI2_CS0           (91)
#define DSPI3_SCK           (92)
#define DSPI3_SOUT          (93)
#define DSPI3_SIN           (94)
#define DSPI3_CS0           (95)

#define FlexCAN0_TX         (48)
#define FlexCAN0_RX         (49)
#define FlexCAN1_TX         (50)
#define FlexCAN1_RX         (51)
#define FlexCAN2_TX         (52)
#define FlexCAN2_RX         (53)
#define FlexCAN3_TX         (54)
#define FlexCAN3_RX         (55)
#define FlexCAN4_TX         (56)
#define FlexCAN4_RX         (57)
#define FlexCAN5_TX         (58)
#define FlexCAN5_RX         (59)
     
#define FEC_TXD0            (108)
#define FEC_TXD1            (109)
#define FEC_TXD2            (110)
#define FEC_TXD3            (111)
#define FEC_TX_EN           (114)
#define FEC_TX_ER           (106)
#define FEC_TX_CLK          (104)
#define FEC_RXD0            (116)
#define FEC_RXD1            (117)
#define FEC_RXD2            (118)
#define FEC_RXD3            (119)
#define FEC_RX_DV           (113)
#define FEC_RX_ER           (115)
#define FEC_RX_CLK          (107)
#define FEC_CRS             (105)
#define FEC_COL             (112)
#define FEC_MDC             (102)
#define FEC_MDIO            (103)

#define BSP_BUTTON1_MUX_GPIO 0
#define BSP_BUTTON2_MUX_GPIO 0
#define BSP_LED1_MUX_GPIO  (SIUL_PCR_SMC_MASK)
#define BSP_LED2_MUX_GPIO  (SIUL_PCR_SMC_MASK)


/*----------------------------------------------------------------------
**           MMU CONFIGURATION
*/
extern uchar __PRIVATE_RAM_START[];
extern uchar __PRIVATE_RAM_SIZE[];
extern uchar __SHARED_RAM_START[];
extern uchar __SHARED_RAM_SIZE[]; 
extern uchar __UNCACHED_DATA_START[];
extern uchar __UNCACHED_DATA_SIZE[]; 
extern uchar __UNCACHED_DATA_END[];

#define BSP_PRIVATE_RAM_START           (pointer)__PRIVATE_RAM_START
#define BSP_PRIVATE_RAM_SIZE            (uint_32)__PRIVATE_RAM_SIZE


#define BSP_UNCACHED_DATA_START         (pointer)__UNCACHED_DATA_START
#define BSP_UNCACHED_DATA_SIZE          (uint_32)__UNCACHED_DATA_SIZE

#define BSP_PRIVATE_RAM_ATTR            (PSP_MMU_WRITE_THROUGH|PSP_MMU_EXEC_ALLOWED|PSP_MMU_PAGE_LOCKED)   
#define BSP_UNCACHED_DATA_ATTR          (PSP_MMU_CACHE_INHIBITED|PSP_MMU_WRITE_THROUGH|PSP_MMU_EXEC_ALLOWED|PSP_MMU_PAGE_LOCKED)


// The Boot code needs to set up some TLBs. The RAM TLB is designated as Process ID 1, so that
// we can add new RAM TLBs for MQX as Process ID 2, and then switch process IDs to enable MQX's TLBs
//#define BSP_PID_BOOT 1
#define BSP_PID_MQX  0

// These are the TLBs that are set up prior to MQX starting
/* Note: same order with HWINIT */
#define BSP_PERIPHERAL_TLB      0 /* MMU for for Periph B Modules */
#define BSP_FLASH_TLB           1 /* Set up MMU to put internal Flash  */
#define BSP_EXT_RAM_TLB         2 /* External Memory */
#define BSP_INT_SRAM_TLB        3 /* Internal SRAM */
#define BSP_PERIPHERAL_A_TLB    4 /* Peripherial A */


/* Set to 1 if you want to use MMU page tables */
/* +++ NOTE: Page table is not supported +++ */
#define BSP_USE_PAGE_TABLES     0

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

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_PIT_TIMER
    #define BSPCFG_ENABLE_PIT_TIMER         0
#endif

/*
** MGCT: <option type="number"/>
*/
#ifndef BSPCFG_TIMER_PIT_DEVICE
    #define BSPCFG_TIMER_PIT_DEVICE        (0)
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSPCFG_TIMER_PIT_CHANNEL
    #define BSPCFG_TIMER_PIT_CHANNEL     _psp_core_num()
#endif

/*
** MGCT: <option type="number"/>
*/
#ifndef BSPCFG_TIMER_INT_LEVEL
    #define BSPCFG_TIMER_INT_LEVEL       (12)
#endif

/** MGCT: </category> */ 

/*
** Old clock rate definition in milliseconds per tick for compatibility
*/
#define BSP_ALARM_RESOLUTION            (1000 / BSP_ALARM_FREQUENCY)

/* Set to 1 if Core Time Base uses External clock as input clock */
#define BSP_TIMEBASE_USES_EXTERNAL_CLK  0

#if BSPCFG_ENABLE_PIT_TIMER
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
#define BSP_XOSC_CLOCK                  (40000000)
#define BSP_FMPLL0_CLOCK                (80000000)

#define BSP_SYSTEM_CLOCK                (BSP_FMPLL0_CLOCK)

#define BSP_CORE_CLOCK                  (BSP_SYSTEM_CLOCK)
#define BSP_TIMEBASE_CLOCK              (BSP_CORE_CLOCK)

#define BSP_PERIPHERAL_CLOCK            (BSP_SYSTEM_CLOCK)

#define BSP_PERI1_CLOCK                 (BSP_SYSTEM_CLOCK/2)
#define BSP_PERI2_CLOCK                 (BSP_SYSTEM_CLOCK)
#define BSP_PERI3_CLOCK                 (BSP_SYSTEM_CLOCK/2)
#define BSP_PERI4_CLOCK                 (BSP_SYSTEM_CLOCK/2)

#define BSP_I2C_CLOCK                   (BSP_PERI1_CLOCK)

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
#define BSP_DSPI_INT_LEVEL               (4)

#define BSP_SPI_MEMORY_CHANNEL           0

/*----------------------------------------------------------------------
**            SDCard DRIVER CONFIGURATION
*/
#define BSP_SDCARD_SPI_CHANNEL           "spi1:"
#define BSP_SDCARD_SPI_CS                1

#define BSP_SDCARD_GPIO_DETECT           23
#define BSP_SDCARD_DETECT_MUX_GPIO       0

/*----------------------------------------------------------------------
**            FEC ETHERNET DRIVER CONFIGURATION
*/

#define BSP_ENET_DEVICE_COUNT      (MPXN20_FEC_DEVICE_COUNT)

#define MPXN20_FEC0                       0
#define BSP_DEFAULT_ENET_DEVICE MPXN20_FEC0

#define BSP_DEFAULT_ENET_OUI              { 0x00, 0x00, 0x5E, 0, 0, 0 }

/** MGCT: <category name="BSP Ethernet Options"> */

/*
** FEC interrupt priority.
** MGCT: <option type="number"/>
*/
#ifndef BSPCFG_FEC_PRIORITY
   #define BSPCFG_FEC_PRIORITY            8
#endif

/*
** Number of receive BD's.
** MGCT: <option type="number"/>
*/
#ifndef BSPCFG_RX_RING_LEN
  #define BSPCFG_RX_RING_LEN              5
#endif

/*
** Number of transmit BD's.
** MGCT: <option type="number"/>
*/
#ifndef BSPCFG_TX_RING_LEN
  #define BSPCFG_TX_RING_LEN              5
#endif

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ENET_MULTICAST
    #define BSPCFG_ENABLE_ENET_MULTICAST  1
#endif

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ENET_STATS
    #define BSPCFG_ENABLE_ENET_STATS      1
#endif

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENET_RESTORE
    #define BSPCFG_ENET_RESTORE           1
#endif

/*
** The ethernet PHY device number 0..31.
*/
#ifndef BSP_ENET0_PHY_ADDR
    #define BSP_ENET0_PHY_ADDR                                  0
#endif

#define BSP_ENET0_PHY_MII_SPEED                            (2500000L)

/** MGCT: </category> */


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

/** MGCT: <category name="UART0 Settings"> */

/*
** Polled TTY device (UART0) 
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_TTYA
    #define BSPCFG_ENABLE_TTYA              0
#endif

/*
** Interrupt-driven TTY device (UART0)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ITTYA
    #define BSPCFG_ENABLE_ITTYA             0
#endif

/** MGCT: </category> */ 

/** MGCT: <category name="UART1 Settings"> */

/*
** Polled TTY device (UART1) 
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_TTYB
    #define BSPCFG_ENABLE_TTYB              0
#endif

/*
** Interrupt-driven TTY device (UART1)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ITTYB
    #define BSPCFG_ENABLE_ITTYB             0
#endif

/** MGCT: </category> */

/** MGCT: <category name="UART2 Settings"> */

/*
** Polled TTY device (UART2) 
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_TTYC
    #define BSPCFG_ENABLE_TTYC              0
#endif

/*
** Interrupt-driven TTY device (UART2)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ITTYC
    #define BSPCFG_ENABLE_ITTYC             0
#endif

/** MGCT: </category> */ 

/** MGCT: <category name="UART3 Settings"> */

/*
** Polled TTY device (UART3) 
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_TTYD
    #define BSPCFG_ENABLE_TTYD              0
#endif

/*
** Interrupt-driven TTY device (UART3)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ITTYD
    #define BSPCFG_ENABLE_ITTYD             0
#endif

/** MGCT: </category> */ 

/** MGCT: <category name="UART4 Settings"> */

/*
** Polled TTY device (UART4) 
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_TTYE
    #define BSPCFG_ENABLE_TTYE              0
#endif

/*
** Interrupt-driven TTY device (UART4)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ITTYE
    #define BSPCFG_ENABLE_ITTYE             0
#endif

/** MGCT: </category> */ 

/** MGCT: <category name="UART5 Settings"> */

/*
** Polled TTY device (UART5) 
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_TTYF
    #define BSPCFG_ENABLE_TTYF              0
#endif

/*
** Interrupt-driven TTY device (UART5)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ITTYF
    #define BSPCFG_ENABLE_ITTYF             0
#endif

/** MGCT: </category> */ 

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

/*
** MGCT: <option type="bool"/>
*/
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
** Polled SPI0
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_SPI0
    #define BSPCFG_ENABLE_SPI0                  0
#endif

/*
** Interrupt-driven SPI0
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ISPI0
    #define BSPCFG_ENABLE_ISPI0                 0
#endif

/*
** Polled SPI1
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_SPI1
    #define BSPCFG_ENABLE_SPI1                  0
#endif

/*
** Interrupt-driven SPI1
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ISPI1
    #define BSPCFG_ENABLE_ISPI1                 0
#endif

/*
** Polled SPI2
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_SPI2
    #define BSPCFG_ENABLE_SPI2                  0
#endif

/*
** Interrupt-driven SPI2
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ISPI2
    #define BSPCFG_ENABLE_ISPI2                 0
#endif

/*
** Polled SPI3
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_SPI3
    #define BSPCFG_ENABLE_SPI3                  0
#endif

/*
** Interrupt-driven SPI3
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ISPI3
    #define BSPCFG_ENABLE_ISPI3                 0
#endif

/*
** RTC device
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_RTCDEV
    #define BSPCFG_ENABLE_RTCDEV                0
#endif

/*
** PCFLASH device
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_PCFLASH
    #define BSPCFG_ENABLE_PCFLASH               0
#endif

/*
** FTFL
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_FLASHX
    #define BSPCFG_ENABLE_FLASHX                0
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
#define FLEXCAN_IPBUS_CLK                             (BSP_PERIPHERAL_CLOCK) 
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
#ifndef BSPCFG_ENABLE_LWADC0
    #if BSPCFG_ENABLE_LWADC
        #define BSPCFG_ENABLE_LWADC0 1
    #else
        #define BSPCFG_ENABLE_LWADC0 0
    #endif
#endif

#define BSP_ADC_VREF_DEFAULT        3300 /* in millivolts */
#define BSP_ADC_POTENTIOMETER_MAX   3300 /* in millivolts */
#define MPXN20_ADC_NUM_CHANNELS     14

#define BSP_ADC_POTENTIOMETER       ADC_INPUT_ADC0_AN0
#define TWRPI_ID0                   ADC_INPUT_ADC0_AN8
#define TWRPI_ID1                   ADC_INPUT_ADC0_AN9
#define TWRPI_ANALOG0               ADC_INPUT_ADC0_AN10
#define TWRPI_ANALOG1               ADC_INPUT_ADC0_AN11
#define TWRPI_ANALOG2               ADC_INPUT_ADC0_AN12
#define BSP_ADC_TWR_AN13            ADC_INPUT_ADC0_AN13
#define BSP_ADC_TWR_AN0             ADC_INPUT_ADC0_AN0
#define BSP_ADC_TWR_AN1             ADC_INPUT_ADC0_AN1
#define BSP_ADC_TWR_AN2             ADC_INPUT_ADC0_AN2
#define BSP_ADC_TWR_AN3             ADC_INPUT_ADC0_AN3
#define BSP_ADC_TWR_AN4             ADC_INPUT_ADC0_AN4
#define BSP_ADC_TWR_AN5             ADC_INPUT_ADC0_AN5
#define BSP_ADC_TWR_AN6             ADC_INPUT_ADC0_AN6
#define BSP_ADC_TWR_AN7             ADC_INPUT_ADC0_AN7

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

/*
** Serial console options:(do not forget to enable BSPCFG_ENABLE_TTY define if changed)
**      "ttya:"      On J24      polled mode; J18 on position 3-5 and 4-6, J21 on position 3-5 and 4-6
**      "ittya:"     On J24      interrupt mode; J18 on position 3-5 and 4-6, J21 on position 3-5 and 4-6
**      "ttyb:"      OSBDM       polled mode; J23 on position 3-5, 4-6
**      "ittyb:"     OSBDM       interrupt mode; J23 on position 3-5, 4-6
**      "ttyc:"      TWR-SER     polled mode
**      "ittyc:"     TWR-SER     interrupt mode
** MGCT: <option type="string" maxsize="256" quoted="false" allowempty="false"/> 
*/
#ifndef BSP_DEFAULT_IO_CHANNEL
    #if BSPCFG_ENABLE_TTYB
        #define BSP_DEFAULT_IO_CHANNEL               "ttyb:"
        #define BSP_DEFAULT_IO_CHANNEL_DEFINED       1
    #elif BSPCFG_ENABLE_ITTYB
        #define BSP_DEFAULT_IO_CHANNEL               "ittyb:"
        #define BSP_DEFAULT_IO_CHANNEL_DEFINED       1
    #else
        #define BSP_DEFAULT_IO_CHANNEL               NULL
    #endif
#else
    /* undef is for backward compatibility with user_configh.h files which have already had it defined */
    #undef  BSP_DEFAULT_IO_CHANNEL_DEFINED
    #define BSP_DEFAULT_IO_CHANNEL_DEFINED
#endif

#define BSP_DEFAULT_IO_OPEN_MODE                     (pointer) \
   (IO_SERIAL_XON_XOFF | IO_SERIAL_TRANSLATION | IO_SERIAL_ECHO)

#ifdef __cplusplus
}
#endif

/** MGCT: </category> */ 

/** MGCT: <category name="Other Options"> */

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_CPP
    #define BSPCFG_ENABLE_CPP               0
#endif

/** MGCT: </category> */ 

#endif

