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
*************************************************************************
*
* $FileName: twrpxs20.h$
* $Version : 3.8.13.0$
* $Date    : Sep-27-2012$
*
* Comments:
*
*   This include file is used to provide information needed by
*   an application program using the kernel running on the 
*   Freescale TWRPXS20 Evaluation board.
*
*END*********************************************************************/

#ifndef __twrpxs20_h__
#define __twrpxs20_h__

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------
**                  HARDWARE INITIALIZATION DEFINITIONS
*/

/*
** Define the board type
*/
#define BSP_TWRPXS20                    1
#define BSP_NAME                        "TWRPXS20"

#define tBOARD                          "Freescale " BSP_NAME
#define tCPU                            "PXS2010"
#define tMEMORY                         "128KB Internal RAM"


/* Set to 1 if you want to use MMU page tables */
/* +++ NOTE: Page table is not supported +++ */
#define BSP_USE_PAGE_TABLES		0


/*----------------------------------------------------------------------
**           CLOCK CONFIGURATION
*/

/*
** The processor clock speed
*/
#define BSP_XOSC_CLOCK                  (40000000) 
#define BSP_FMPLL0_CLOCK                (80000000) 
#define BSP_FMPLL1_CLOCK                (120000000) 

#define BSP_TIMEBASE_CLOCK              (BSP_FMPLL0_CLOCK)
#define BSP_PERIPHERAL_CLOCK            (BSP_FMPLL0_CLOCK)

#define BSP_MOTC_CLOCK                  (BSP_FMPLL1_CLOCK)

// Used by kernel tests
#define BSP_SYSTEM_CLOCK                (BSP_FMPLL0_CLOCK)

// Used by timing test to display core frequency. Should not be confused with BSP_SYS_CLOCK or BSP_SYSTEM_CLOCK
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


#define _bsp_int_disable(v)     _qintc_set_prio(v,0)
#define _bsp_int_enable(v)      /* Interrupt controller driver does not support this functionality, use _bsp_int_init instead */
#define _bsp_int_init(v,l,s,e)  _qintc_set_prio(v,l)


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
** The clock tick rate in milliseconds
*/
#define BSP_ALARM_RESOLUTION             (1000/BSP_ALARM_FREQUENCY)

/* Set to 1 if Core Time Base uses External clock as input clock */
#define BSP_TIMEBASE_USES_EXTERNAL_CLK   0


#if BSPCFG_ENABLE_PIT_TIMER
    #define BSP_TIMER_INTERRUPT_VECTOR        _bsp_get_qpit_vector(BSPCFG_TIMER_PIT_DEVICE, BSPCFG_TIMER_PIT_CHANNEL)
    #define BSP_TIMER_INTERRUPT_PRIORITY      BSPCFG_TIMER_INT_LEVEL
#else
    #define BSP_TIMER_INTERRUPT_VECTOR        PSP_EXCPT_DECREMENTER
#endif


/*----------------------------------------------------------------------
**            Signal Assignments
*/

#define LIN0_TXD            MPXS20_144_114
#define LIN0_RXD            MPXS20_144_116

#define LIN1_TXD            MPXS20_144_115
#define LIN1_RXD            MPXS20_144_113

#define CAN0_TXD            MPXS20_144_109
#define CAN0_RXD            MPXS20_144_110

#define CAN1_TXD            MPXS20_144_143
#define CAN1_RXD            MPXS20_144_144

#define DSPI0_CS0           MPXS20_144_11
#define DSPI0_CS1           MPXS20_144_81
#define DSPI0_SCK           MPXS20_144_13
#define DSPI0_SOUT          MPXS20_144_142
#define DSPI0_SIN           MPXS20_144_15

#define DSPI1_CS0           MPXS20_144_14
#define DSPI1_SCK           MPXS20_144_2
#define DSPI1_SOUT          MPXS20_144_10
#define DSPI1_SIN           MPXS20_144_12


#define ADC0_AN0            MPXS20_144_43
#define ADC0_AN1            MPXS20_144_47
#define ADC0_AN2            MPXS20_144_41
#define ADC0_AN3            MPXS20_144_45
#define ADC0_AN4            MPXS20_144_46
#define ADC0_AN5            MPXS20_144_49
#define ADC0_AN6            MPXS20_144_48
#define ADC0_AN7            MPXS20_144_42
#define ADC0_AN8            MPXS20_144_44

#define ADC0_ADC1_AN11      MPXS20_144_52
#define ADC0_ADC1_AN12      MPXS20_144_53
#define ADC0_ADC1_AN13      MPXS20_144_54
#define ADC0_ADC1_AN14      MPXS20_144_55

#define ADC1_AN0            MPXS20_144_60
#define ADC1_AN1            MPXS20_144_64
#define ADC1_AN2            MPXS20_144_62
#define ADC1_AN3            MPXS20_144_66
#define ADC1_AN4            MPXS20_144_65
#define ADC1_AN5            MPXS20_144_68
#define ADC1_AN6            MPXS20_144_67
#define ADC1_AN7            MPXS20_144_61
#define ADC1_AN8            MPXS20_144_63


#define BSP_BUTTON1 12
#define BSP_BUTTON2 13


#define BSP_BUTTON1_MUX_GPIO 0
#define BSP_BUTTON2_MUX_GPIO 0


#define BSP_LED1  106
#define BSP_LED2  83
#define BSP_LED3  54
#define BSP_LED4  107

#define BSP_LED1_MUX_GPIO  (SIUL_PCR_SMC_MASK)
#define BSP_LED2_MUX_GPIO  (SIUL_PCR_SMC_MASK)
#define BSP_LED3_MUX_GPIO  (SIUL_PCR_SMC_MASK)
#define BSP_LED4_MUX_GPIO  (SIUL_PCR_SMC_MASK)


/*----------------------------------------------------------------------
**            LWADC
*/

#define BSP_ADC_CLOCK               (BSP_MOTC_CLOCK/2)
#define BSP_ADC_VREF_DEFAULT        5000 // in millivolts
#define BSP_ADC_POTENTIOMETER_MAX   3300 // in millivolts

#define BSP_ADC_POTENTIOMETER       ADC_INPUT_ADC0_AN8
#define BSP_ADC_TB1_PIN2            ADC_INPUT_ADC1_AN5
#define BSP_ADC_TB1_PIN3            ADC_INPUT_ADC0_AN7

#define BSP_ADC_INPUT_0             BSP_ADC_TB1_PIN2
#define BSP_ADC_INPUT_1             BSP_ADC_TB1_PIN3


#define BSP_ADC_TWRPI_PIN8          ADC_INPUT_ADC1_AN0
#define BSP_ADC_TWRPI_PIN9          ADC_INPUT_ADC1_AN1
#define BSP_ADC_TWRPI_PIN12         ADC_INPUT_ADC1_AN2
#define BSP_ADC_TWRPI_PIN17         ADC_INPUT_ADC1_AN3
#define BSP_ADC_TWRPI_PIN18         ADC_INPUT_ADC1_AN4

#define BSP_ADC_TWR_AN7             ADC_INPUT_ADC0_AN7
#define BSP_ADC_TWR_AN6             ADC_INPUT_ADC0_AN6
#define BSP_ADC_TWR_AN5             ADC_INPUT_ADC0_AN5
#define BSP_ADC_TWR_AN4             ADC_INPUT_ADC0_AN4
#define BSP_ADC_TWR_AN3             ADC_INPUT_ADC0_AN3
#define BSP_ADC_TWR_AN2             ADC_INPUT_ADC0_AN2
#define BSP_ADC_TWR_AN1             ADC_INPUT_ADC0_AN1
#define BSP_ADC_TWR_AN0             ADC_INPUT_ADC0_AN0

#define BSP_ADC_TWR_AN13            ADC_INPUT_ADC1_AN5
#define BSP_ADC_TWR_AN12            ADC_INPUT_ADC1_AN4
#define BSP_ADC_TWR_AN11            ADC_INPUT_ADC1_AN3
#define BSP_ADC_TWR_AN10            ADC_INPUT_ADC1_AN2
#define BSP_ADC_TWR_AN9             ADC_INPUT_ADC1_AN1
#define BSP_ADC_TWR_AN8             ADC_INPUT_ADC1_AN0

#define BSP_ADC_VDD_CORE            ADC_INPUT_ADC0_VREG_1V2
#define BSP_ADC_TEMPERATURE         ADC_INPUT_ADC0_TSENS


/*-----------------------------------------------------------------------------
**            SPI DRIVER CONFIGURATION
*/

#define BSP_DSPI_RX_BUFFER_SIZE          (32)
#define BSP_DSPI_TX_BUFFER_SIZE          (32)
#define BSP_DSPI_BAUDRATE                (1000000)
#define BSP_DSPI_INT_LEVEL               (4)

#define BSP_SPI_MEMORY_CHANNEL           0


/*----------------------------------------------------------------------
**            SDCard DRIVER CONFIGURATION
*/

#define BSP_SDCARD_SPI_CHANNEL           "spi1:"
#define BSP_SDCARD_SPI_CS                1

#define BSP_SDCARD_GPIO_DETECT           9         
#define BSP_SDCARD_DETECT_MUX_GPIO       0

/* SDCARD WP cannot be used, pin is shared with INT2 of MMA7455L accelerometer */
/*
#define BSP_SDCARD_GPIO_PROTECT          93             
#define BSP_SDCARD_PROTECT_MUX_GPIO      0
*/


/*----------------------------------------------------------------------
**            FLEXCAN DRIVER CONFIGURATION
*/
#define FLEXCAN_IPBUS_CLK                               (BSP_FMPLL0_CLOCK/2)
#define FLEXCAN_OSC_CLK                                 (BSP_XOSC_CLOCK)

/*----------------------------------------------------------------------
**            IO DEVICE DRIVERS CONFIGURATION
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
** RTC device
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_RTCDEV
    #define BSPCFG_ENABLE_RTCDEV                0
#endif

/*
** RTC device
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_GPIODEV
    #define BSPCFG_ENABLE_GPIODEV               0
#endif

/*
** PCFLASH device
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_PCFLASH
    #define BSPCFG_ENABLE_PCFLASH               0
#endif

/*
** PCFLASH device
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_SDHC
    #define BSPCFG_ENABLE_SDHC                  0
#endif

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_NANDFLASH
    #define BSPCFG_ENABLE_NANDFLASH             0
#endif

/*
** FTFL
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_FLASHX
    #define BSPCFG_ENABLE_FLASHX                0
#endif

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

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_LWADC1
    #if BSPCFG_ENABLE_LWADC
        #define BSPCFG_ENABLE_LWADC1 1
    #else
        #define BSPCFG_ENABLE_LWADC1 0
    #endif
#endif

/** MGCT: </category> */

/*----------------------------------------------------------------------
**                  DEFAULT MQX INITIALIZATION DEFINITIONS
** MGCT: <category name="Default Driver Configuration">
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
**      "ttya:"      TWR-SER     polled mode
**      "ittya:"     TWR-SER     interrupt mode
**      "ttyb:"      OSBDM       polled mode
**      "ittyb:"     OSBDM       interrupt mode
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
