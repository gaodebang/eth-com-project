/**HEADER********************************************************************
*
* Copyright (c) 2012 Freescale Semiconductor;
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
* $FileName: twrvf65gs10_a5.h$
* $Version : 3.8.9.1$
* $Date    : Sep-27-2012$
*
* Comments:
*
*   This include file is used to provide information needed by
*   an application program using the kernel running on the
*   Freescale TWR-VF65GS10 Evaluation board.
*
*END************************************************************************/

#ifndef _twrvf65gs10_a5_h_
#define _twrvf65gs10_a5_h_  1

/*----------------------------------------------------------------------
**                  HARDWARE INITIALIZATION DEFINITIONS
*/

/*
** Define the board type
*/
#define BSP_TWR_VF65GS10                    1
#define BSP_NAME                            "TWRVF65GS10"


#define __DEFAULT_PROCESSOR_NUMBER          1

/*----------------------------------------------------------------------
**                  CLOCK
*/

/* Init startup clock configuration is CPU_CLOCK_CONFIG_0 */
#define BSP_CLOCK_SRC                   (24000000u)
#define BSP_CORE_CLOCK                  (396000000u)
#define BSP_BUS_CLOCK                   (132000000u)
#define BSP_IPG_CLOCK                   (66000000u)

#define BSP_SYSTEM_CLOCK                (BSP_CORE_CLOCK)

/*
** The clock tick rate
*/
#ifndef BSP_ALARM_FREQUENCY
    #define BSP_ALARM_FREQUENCY              (200)
#endif

/*
** Old clock rate definition in MS per tick, kept for compatibility
*/
#define BSP_ALARM_RESOLUTION                 (1000 / BSP_ALARM_FREQUENCY)

/*
** Define the location of the hardware interrupt vector table
*/

//#define BSP_INTERRUPT_VECTOR_TABLE ...

#ifndef BSP_FIRST_INTERRUPT_VECTOR_USED
   #define BSP_FIRST_INTERRUPT_VECTOR_USED  16
#endif

#ifndef BSP_LAST_INTERRUPT_VECTOR_USED
   #define BSP_LAST_INTERRUPT_VECTOR_USED    159
#endif

#define BSP_TIMER_INTERRUPT_VECTOR           INT_GlobalTimer


#define BSP_TIMER                            (0)
#define BSP_TIMER_PRIORITY                   (2)
#define BSP_TIMER_CLOCK_SOURCE               (EPIT_CLK_SRC_PER)
#define BSP_TIMER_FREQUENCY                  (BSP_BUS_CLOCK)
#define BSP_TIMER_PRESCALE                   (1)

/*----------------------------------------------------------------------
**            Core Mutex
*/
#ifndef BSPCFG_CORE_MUTEX
    #define BSPCFG_CORE_MUTEX               1
#endif

#ifndef BSPCFG_CORE_MUTEX_STATS
    #define BSPCFG_CORE_MUTEX_STATS         0
#endif

#define BSPCFG_CORE_MUTEX_PRIORITY          3


/*-----------------------------------------------------------------------------
**                      Ethernet Info
*/
#define BSP_ENET_DEVICE_COUNT                  MACNET_DEVICE_COUNT

/*
** MACNET interrupt levels and vectors
*/
#define BSP_MACNET0_INT_TX_LEVEL           (4)
#define BSP_MACNET0_INT_RX_LEVEL           (4)
#define BSP_MACNET1_INT_TX_LEVEL           (4)
#define BSP_MACNET1_INT_RX_LEVEL           (4)

#define BSP_DEFAULT_ENET_DEVICE             0
#define BSP_DEFAULT_ENET_OUI                { 0x00, 0x00, 0x5E, 0, 0, 0 }

/*
** The Ethernet PHY device number 0..31
*/
#ifndef BSP_ENET0_PHY_ADDR
    #define BSP_ENET0_PHY_ADDR                 0
#endif

#ifndef BSP_ENET1_PHY_ADDR
    #define BSP_ENET1_PHY_ADDR                 1
#endif
/*
** PHY MII Speed (MDC - Management Data Clock)
*/
#define BSP_ENET0_PHY_MII_SPEED             (2500000L)
#define BSP_ENET1_PHY_MII_SPEED             (2500000L)

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_HAS_SRAM_POOL
    #define BSPCFG_HAS_SRAM_POOL            1
#endif


#ifndef BSPCFG_RX_RING_LEN
    #define BSPCFG_RX_RING_LEN              3 /* Number of receive BD's */
#endif

#ifndef BSPCFG_TX_RING_LEN
    #define BSPCFG_TX_RING_LEN              3 /* Number of transmit BD's */
#endif


#ifndef BSPCFG_ENABLE_ENET_MULTICAST
    #define BSPCFG_ENABLE_ENET_MULTICAST    1
#endif

#ifndef BSPCFG_ENABLE_ENET_STATS
    #define BSPCFG_ENABLE_ENET_STATS        1
#endif

#ifndef BSPCFG_ENET_RESTORE
    #define BSPCFG_ENET_RESTORE             1
#endif

#ifndef BSPCFG_ENABLE_CPP
    #define BSPCFG_ENABLE_CPP               0
#endif

/*-----------------------------------------------------------------------------
**                      SPI
*/
#define BSP_DSPI_INT_LEVEL                  (3)
#define BSP_SPI_MEMORY_CHANNEL              (0)

/*-----------------------------------------------------------------------------
**                      I2C
*/
#define BSP_I2C_CLOCK                       (BSP_BUS_CLOCK) // NEED TO DIG DEEPER INTO CLOCKS. THIS IS BASED ON UBOOT AND WORKS FOR NOW
#define BSP_I2C0_ADDRESS                    (0x6E)
#define BSP_I2C1_ADDRESS                    (0x6F)
#define BSP_I2C2_ADDRESS                    (0x70)
#define BSP_I2C3_ADDRESS                    (0x71)

#define BSP_I2C0_BAUD_RATE                  (100000)
#define BSP_I2C1_BAUD_RATE                  (100000)
#define BSP_I2C2_BAUD_RATE                  (100000)
#define BSP_I2C3_BAUD_RATE                  (100000)

#define BSP_I2C0_MODE                       (I2C_MODE_MASTER)
#define BSP_I2C1_MODE                       (I2C_MODE_MASTER)
#define BSP_I2C2_MODE                       (I2C_MODE_MASTER)
#define BSP_I2C3_MODE                       (I2C_MODE_MASTER)

#define BSP_I2C0_INT_LEVEL                  (4)
#define BSP_I2C0_INT_SUBLEVEL               (4)
#define BSP_I2C1_INT_LEVEL                  (4)
#define BSP_I2C1_INT_SUBLEVEL               (4)
#define BSP_I2C2_INT_LEVEL                  (4)
#define BSP_I2C2_INT_SUBLEVEL               (4)
#define BSP_I2C3_INT_LEVEL                  (4)
#define BSP_I2C3_INT_SUBLEVEL               (4)

#define BSP_I2C0_RX_BUFFER_SIZE             (64)
#define BSP_I2C0_TX_BUFFER_SIZE             (64)
#define BSP_I2C1_RX_BUFFER_SIZE             (64)
#define BSP_I2C1_TX_BUFFER_SIZE             (64)
#define BSP_I2C2_RX_BUFFER_SIZE             (64)
#define BSP_I2C2_TX_BUFFER_SIZE             (64)
#define BSP_I2C3_RX_BUFFER_SIZE             (64)
#define BSP_I2C3_TX_BUFFER_SIZE             (64)
/*-----------------------------------------------------------------------------
**                      ADC
*/
#define ADC_MAX_MODULES                 (2)
#define BSP_ADC_POTENTIOMETER           (ADC_INPUT_ADC0_AN5)
#define BSP_ADC0_VECTOR_PRIORITY        (3)
#define BSP_ADC1_VECTOR_PRIORITY        (3)
#define BSP_PDB_VECTOR_PRIORITY         (3)
#define BSP_ADC_VREF_DEFAULT            (3300)
#define BSP_ADC_POTENTIOMETER_MAX       (3300)

#ifndef BSPCFG_ENABLE_LWADC
#define BSPCFG_ENABLE_LWADC 1
#endif

/*-----------------------------------------------------------------------------
**                      SSI
*/
#define BSP_SSI1_AUDMUX_OUT_PORT             (6)
#define BSP_SSI2_AUDMUX_OUT_PORT             (5)
#define BSP_SSI3_AUDMUX_OUT_PORT             (7)

#define BSP_SSI1_MODE                        (SSI_MODE_SLAVE)
#define BSP_SSI2_MODE                        (SSI_MODE_SLAVE)
#define BSP_SSI3_MODE                        (SSI_MODE_SLAVE)

#define BSP_SSI1_DIR                         (SSI_DIR_TX)
#define BSP_SSI2_DIR                         (SSI_DIR_TX)
#define BSP_SSI3_DIR                         (SSI_DIR_TX)

#define BSP_SSI1_FIFO                        (SSI_FIFO_FIFO0)
#define BSP_SSI2_FIFO                        (SSI_FIFO_FIFO0)
#define BSP_SSI3_FIFO                        (SSI_FIFO_FIFO0)

#define BSP_SSI1_WORD_LENGTH                 (SSI_WORD_LENGTH_16BIT)
#define BSP_SSI2_WORD_LENGTH                 (SSI_WORD_LENGTH_16BIT)
#define BSP_SSI3_WORD_LENGTH                 (SSI_WORD_LENGTH_16BIT)

#define BSP_SSI1_ALIGN                       (SSI_ALIGN_LSB)
#define BSP_SSI2_ALIGN                       (SSI_ALIGN_LSB)
#define BSP_SSI3_ALIGN                       (SSI_ALIGN_LSB)

#define BSP_SSI1_RX_BUFFER_SIZE              (4096)
#define BSP_SSI2_RX_BUFFER_SIZE              (4096)
#define BSP_SSI3_RX_BUFFER_SIZE              (4096)

#define BSP_SSI1_TX_BUFFER_SIZE              (16384)
#define BSP_SSI2_TX_BUFFER_SIZE              (8192)
#define BSP_SSI3_TX_BUFFER_SIZE              (16384)

/*-----------------------------------------------------------------------------
**                      GPIO
*/
#define BSP_LED1                            (LWGPIO_PORT_A | LWGPIO_PIN22)
#define BSP_LED2                            (LWGPIO_PORT_A | LWGPIO_PIN23)
#define BSP_LED3                            (LWGPIO_PORT_A | LWGPIO_PIN24)
#define BSP_LED4                            (LWGPIO_PORT_A | LWGPIO_PIN25)
#define BSP_SW1                             (LWGPIO_PORT_B | LWGPIO_PIN6)
#define BSP_SW2                             (LWGPIO_PORT_B | LWGPIO_PIN7)
#define BSP_BUTTON1                         BSP_SW1
#define BSP_BUTTON2                         BSP_SW2

#define BSP_LED1_MUX_GPIO                   (LWGPIO_MUX_A22_GPIO)
#define BSP_LED2_MUX_GPIO                   (LWGPIO_MUX_A23_GPIO)
#define BSP_LED3_MUX_GPIO                   (LWGPIO_MUX_A24_GPIO)
#define BSP_LED4_MUX_GPIO                   (LWGPIO_MUX_A25_GPIO)
#define BSP_LED4_MUX_GPIO                   (LWGPIO_MUX_A25_GPIO)
#define BSP_SW1_MUX_GPIO                    (LWGPIO_MUX_B6_GPIO)
#define BSP_SW2_MUX_GPIO                    (LWGPIO_MUX_B7_GPIO)
#define BSP_BUTTON1_MUX_GPIO                BSP_SW2_MUX_GPIO
#define BSP_BUTTON1_MUX_IRQ                 BSP_SW1_MUX_GPIO
#define BSP_BUTTON2_MUX_GPIO                BSP_SW2_MUX_GPIO

/*-----------------------------------------------------------------------------
**                      HWTIMER
*/
#define BSP_HWTIMER1_DEV        pit_devif
#define BSP_HWTIMER1_SOURCE_CLK (CM_CLOCK_SOURCE_IPG)
#define BSP_HWTIMER1_ID         (0)

#define BSP_HWTIMER2_DEV        pit_devif
#define BSP_HWTIMER2_SOURCE_CLK (CM_CLOCK_SOURCE_IPG)
#define BSP_HWTIMER2_ID         (1)

/*----------------------------------------------------------------------
**                  IO DEVICE DRIVERS CONFIGURATION
*/

#ifndef BSPCFG_ENABLE_IO_SUBSYSTEM
    #define BSPCFG_ENABLE_IO_SUBSYSTEM  1
#endif

/* polled TTY device (UART 1) */
//#ifndef BSPCFG_ENABLE_TTYB
//    #define BSPCFG_ENABLE_TTYB  1
//#endif

/* polled TTY device (UART 2) */
#ifndef BSPCFG_ENABLE_TTYC
    #define BSPCFG_ENABLE_TTYC  1
#endif


/* TTYA and ITTYA baud rate */
#ifndef BSPCFG_SCI0_BAUD_RATE
    #define BSPCFG_SCI0_BAUD_RATE             115200
#endif

/* TTYB and ITTYB baud rate */
#ifndef BSPCFG_SCI1_BAUD_RATE
    #define BSPCFG_SCI1_BAUD_RATE             115200
#endif

/* TTYC and ITTYC baud rate */
#ifndef BSPCFG_SCI2_BAUD_RATE
    #define BSPCFG_SCI2_BAUD_RATE             115200
#endif

/* TTYD and ITTYD baud rate */
#ifndef BSPCFG_SCI3_BAUD_RATE
    #define BSPCFG_SCI3_BAUD_RATE             115200
#endif

/* TTYE and ITTYE baud rate */
#ifndef BSPCFG_SCI4_BAUD_RATE
    #define BSPCFG_SCI4_BAUD_RATE             115200
#endif

/* TTYF and ITTYF baud rate */
#ifndef BSPCFG_SCI5_BAUD_RATE
    #define BSPCFG_SCI5_BAUD_RATE             115200
#endif

/* TTYA and ITTYA buffer size */
#ifndef BSPCFG_SCI0_QUEUE_SIZE
    #define BSPCFG_SCI0_QUEUE_SIZE             64
#endif

/* TTYB and ITTYB buffer size */
#ifndef BSPCFG_SCI1_QUEUE_SIZE
    #define BSPCFG_SCI1_QUEUE_SIZE             64
#endif

/* TTYC and ITTYC buffer size */
#ifndef BSPCFG_SCI2_QUEUE_SIZE
    #define BSPCFG_SCI2_QUEUE_SIZE             64
#endif

/* TTYD and ITTYD buffer size */
#ifndef BSPCFG_SCI3_QUEUE_SIZE
    #define BSPCFG_SCI3_QUEUE_SIZE             64
#endif

/* TTYE and ITTYE buffer size */
#ifndef BSPCFG_SCI4_QUEUE_SIZE
    #define BSPCFG_SCI4_QUEUE_SIZE             64
#endif

/* TTYF and ITTYF buffer size */
#ifndef BSPCFG_SCI5_QUEUE_SIZE
    #define BSPCFG_SCI5_QUEUE_SIZE             64
#endif

/* ESDHC device */
#ifndef BSPCFG_ENABLE_ESDHC
    #define BSPCFG_ENABLE_ESDHC                1
#endif

/* USB device */
#ifndef BSPCFG_ENABLE_USB
    #define BSPCFG_ENABLE_USB                  1
#endif


/*
** The SDCARD settings.
*/
#define BSP_SDCARD_ESDHC_CHANNEL            "esdhc1:"
#define BSP_SDCARD_GPIO_DETECT              (LWGPIO_PORT_E | LWGPIO_PIN6)
#define BSP_SDCARD_DETECT_MUX_GPIO          (LWGPIO_MUX_E6_GPIO)

/*----------------------------------------------------------------------
**                  USB Configuration
*/
#define USBCFG_CONNECTOR_UTMI               (0)
#define USBCFG_USBOTG_CONNECTOR             USBCFG_CONNECTOR_UTMI

#define USBCFG_DEFAULT_HOST_CONTROLLER      (&_bsp_usb_host_ehci0_if)
#define USBCFG_DEFAULT_DEVICE_CONTROLLER    (&_bsp_usb_dev_ehci0_if)

#define BSP_USB_INT_LEVEL                   (3)

#define USBCFG_EHCI             1
#define USBCFG_MAX_DRIVERS      4

/* This will be removed in the future and runtime option in the initialization struct will be used */
#define USBCFG_REGISTER_ENDIANNESS        MQX_LITTLE_ENDIAN
#define USBCFG_MEMORY_ENDIANNESS          MQX_LITTLE_ENDIAN

/*----------------------------------------------------------------------
**            MULTICORE SUPPORT
*/

/* IPC for Shared Memory */
// Set to let Shared memory driver that there is core specific support required
#define BSPCFG_IO_PCB_SHM_SUPPORT           1
#define BSPCFG_IO_PCB_SHM_RX_PRIO           2
#define BSPCFG_IO_PCB_SHM_TX_PRIO           2


/*----------------------------------------------------------------------
**                  DEFAULT MQX INITIALIZATION DEFINITIONS
*/

#define __INTERNAL_SRAM_BASE (0x3f000000)
#define __INTERNAL_SRAM_SIZE (0x00080000)

#define __EXTERNAL_DDRAM_BASE (0x80000000)
#define __EXTERNAL_DDRAM_SIZE (0x08000000)

extern uchar __KERNEL_DATA_START[];
extern uchar __KERNEL_DATA_END[];

extern uchar __SHARED_RAM_START[];
extern uchar __SHARED_RAM_END[];

extern uchar __UNCACHED_DATA_START[];
extern uchar __UNCACHED_DATA_END[];

extern uchar __SRAM_POOL_START[];
extern uchar __SRAM_POOL_END[];

extern uchar __DEFAULT_INTERRUPT_STACK_SIZE[];

#if __IAR_SYSTEMS_ICC__

#pragma section = "KERNEL_DATA"
#define BSP_DEFAULT_START_OF_KERNEL_MEMORY      ((pointer)__sfb("KERNEL_DATA"))

#elif defined(__CC_ARM)

#define BSP_DEFAULT_START_OF_KERNEL_MEMORY      ((pointer)__KERNEL_DATA_START)

#elif defined(__GNUC__)

#define BSP_DEFAULT_START_OF_KERNEL_MEMORY      ((pointer)__KERNEL_DATA_START)

#else
#error UNKNOWN COMPILER - IMPLEMENT ME!!!
#endif

#define BSP_DEFAULT_END_OF_KERNEL_MEMORY                      ((pointer)__KERNEL_DATA_END)

#define VF65GS10_SRAM_BASE                     	(0x3f000000)
#define VF65GS10_SRAM_CORE_0_BASE              	(0x3f07f000)
#define VF65GS10_SRAM_CORE_0_SIZE              	(2 * 1024)
#define VF65GS10_SRAM_CORE_0_END               	(VF65GS10_SRAM_CORE_0_BASE + VF65GS10_SRAM_CORE_0_SIZE)

#define VF65GS10_SRAM_CORE_1_BASE              	(0x3f07f800)
#define VF65GS10_SRAM_CORE_1_SIZE              	(2 * 1024)
#define VF65GS10_SRAM_CORE_1_END               	(VF65GS10_SRAM_CORE_1_BASE + VF65GS10_SRAM_CORE_1_SIZE)

#if defined(__ARMCC_VERSION)
extern uchar Image$$SHARED_RAM_START$$Base[];
extern uchar Image$$SHARED_RAM_END$$Base[];
#define BSP_SHARED_RAM_START                ((pointer)Image$$SHARED_RAM_START$$Base)
#define BSP_SHARED_RAM_SIZE                 (Image$$SHARED_RAM_END$$Base - Image$$SHARED_RAM_START$$Base)
#else
#define BSP_SHARED_RAM_START                ((pointer)__SHARED_RAM_START)
#define BSP_SHARED_RAM_SIZE                 (__SHARED_RAM_SIZE)
#endif
#define BSP_REMOTE_SHARED_RAM_START         (VF65GS10_SRAM_CORE_1_BASE)

#ifndef BSP_DEFAULT_INTERRUPT_STACK_SIZE
    #define BSP_DEFAULT_INTERRUPT_STACK_SIZE              (3000) //TODO: use ((uint_32)__DEFAULT_INTERRUPT_STACK_SIZE)
#endif

#ifndef BSP_DEFAULT_MQX_HARDWARE_INTERRUPT_LEVEL_MAX
    #define BSP_DEFAULT_MQX_HARDWARE_INTERRUPT_LEVEL_MAX  (2L)
#endif

#ifndef BSP_DEFAULT_MAX_MSGPOOLS
    #define BSP_DEFAULT_MAX_MSGPOOLS                      (2L)
#endif

#ifndef BSP_DEFAULT_MAX_MSGQS
    #define BSP_DEFAULT_MAX_MSGQS                         (16L)
#endif

/*
 * Other Serial console options:(do not forget to enable BSPCFG_ENABLE_TTY define if changed)
 *      "ttyb:"      OpenSDA     polled mode
 */
#ifndef BSP_DEFAULT_IO_CHANNEL
    #if BSPCFG_ENABLE_TTYB
        #define BSP_DEFAULT_IO_CHANNEL                        "ttyb:"
        #define BSP_DEFAULT_IO_CHANNEL_DEFINED
    #else
        #define BSP_DEFAULT_IO_CHANNEL                        NULL
   #endif
#endif

#ifndef BSP_DEFAULT_IO_OPEN_MODE
    #define BSP_DEFAULT_IO_OPEN_MODE                      (pointer) (/*IO_SERIAL_XON_XOFF |*/ IO_SERIAL_TRANSLATION | IO_SERIAL_ECHO)
#endif


#ifndef BSP_CORE_0_PROCESSOR_NUMBER
    #define BSP_CORE_0_PROCESSOR_NUMBER                 (1)
#endif

#ifndef BSP_CORE_1_PROCESSOR_NUMBER
    #define BSP_CORE_1_PROCESSOR_NUMBER                 (2)
#endif

#define BSP_DEFAULT_PROCESSOR_NUMBER                    ((uint_32)BSP_CORE_0_PROCESSOR_NUMBER)

#endif // _twrvf65gs10_a5_h_
