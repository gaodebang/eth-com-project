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
* Comments:
*
*   This include file is used to provide information needed by
*   an application program using the kernel running on the
*   Freescale TWR-K60N512 Evaluation board.
*
*END************************************************************************/

#ifndef _twrvf65gs10_m4_h_
#define _twrvf65gs10_m4_h_  1


/*----------------------------------------------------------------------
**                  HARDWARE INITIALIZATION DEFINITIONS
*/

/*
** Define the board type
*/
//#define BSP_TWR_VF65GS10                    1 //TODO: uncomment me
#define BSP_NAME                            "TWRVF65GS10"


/*
** PROCESSOR MEMORY BOUNDS
*/
#define BSP_PERIPH_BASE                     (CORTEX_PERIPH_BASE)

#ifdef __CC_ARM

#define __DEFAULT_PROCESSOR_NUMBER 1

extern const vector_entry __vector_table[256] __attribute__((used));
#define __VECTOR_TABLE_ROM_START    ((_mqx_max_type)__vector_table)
#define __VECTOR_TABLE_RAM_START    0x3f800000 /* where .vectors_ram is placed. Check linker command file. */

#else /* __CC_ARM */

extern uchar __EXTERNAL_MRAM_ROM_BASE[],    __EXTERNAL_MRAM_ROM_SIZE[];
extern uchar __EXTERNAL_MRAM_RAM_BASE[],    __EXTERNAL_MRAM_RAM_SIZE[];
extern uchar __EXTERNAL_LCD_BASE[],         __EXTERNAL_LCD_SIZE[];
extern uchar __EXTERNAL_LCD_DC_BASE[];
extern const uchar __FLASHX_START_ADDR[];
extern const uchar __FLASHX_END_ADDR[];
extern const uchar __FLASHX_SECT_SIZE[];
extern uchar __INTERNAL_FLEXNVM_BASE[];
extern uchar __INTERNAL_FLEXNVM_SIZE[];

extern vector_entry __VECTOR_TABLE_RAM_START[]; // defined in linker command file
extern vector_entry __VECTOR_TABLE_ROM_START[]; // defined in linker command file

extern uchar __DEFAULT_PROCESSOR_NUMBER[];
extern uchar __DEFAULT_INTERRUPT_STACK_SIZE[];

#endif /* __CC_ARM */


/* Enable modification of flash configuration bytes during loading for flash targets */
#ifndef BSPCFG_ENABLE_CFMPROTECT
    #define BSPCFG_ENABLE_CFMPROTECT        1
#endif
#if !BSPCFG_ENABLE_CFMPROTECT && defined(__ICCARM__)
    #error Cannot disable CFMPROTECT field on IAR compiler. Please define BSPCFG_ENABLE_CFMPROTECT to 1.
#endif

/*
 * The clock configuration settings
 * Remove old definitions of "BSP_CLOCKS" in drivers and replace
 * by runtime clock checking. Its assumed that BSP_CLOCK_CONFIGURATION_1
 * sets PLL to full speed 96MHz to be compatible with old drivers.
 */
#ifndef BSP_CLOCK_CONFIGURATION_STARTUP
    #define BSP_CLOCK_CONFIGURATION_STARTUP (BSP_CLOCK_CONFIGURATION_96MHZ)
#endif /* BSP_CLOCK_CONFIGURATION_STARTUP */

/* Init startup clock configuration is CPU_CLOCK_CONFIG_0 */
#define BSP_CLOCK_SRC                   (50000000)
#define BSP_CORE_CLOCK                  (132000000)
#define BSP_SYSTEM_CLOCK                (66000000)
#define BSP_BUS_CLOCK                   (25000000)

/*
** The clock tick rate
*/
#ifndef BSP_ALARM_FREQUENCY
    #define BSP_ALARM_FREQUENCY             (200)
#endif

/*
** Old clock rate definition in MS per tick, kept for compatibility
*/
#define BSP_ALARM_RESOLUTION                (1000 / BSP_ALARM_FREQUENCY)

/*
** Define the location of the hardware interrupt vector table
*/
#if MQX_ROM_VECTORS
    #define BSP_INTERRUPT_VECTOR_TABLE              ((uint_32)__VECTOR_TABLE_ROM_START)
#else
    #define BSP_INTERRUPT_VECTOR_TABLE              ((uint_32)__VECTOR_TABLE_RAM_START)
#endif

#ifndef BSP_FIRST_INTERRUPT_VECTOR_USED
    #define BSP_FIRST_INTERRUPT_VECTOR_USED     (0)
#endif

#ifndef BSP_LAST_INTERRUPT_VECTOR_USED
    #define BSP_LAST_INTERRUPT_VECTOR_USED      (250)
#endif

#define BSP_TIMER_INTERRUPT_VECTOR              NVIC_SysTick
#define BSP_TIMER_INTERRUPT_PRIORITY            2

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


/*
** RTC interrupt level
*/
#define BSP_RTC_INT_LEVEL                      (4)

/*
** LPM related
*/
#define BSP_LPM_DEPENDENCY_LEVEL_SERIAL_POLLED (30)
#define BSP_LPM_DEPENDENCY_LEVEL_SERIAL_INT    (31)

/*
** GPIO board specifications
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


/*
** HWTIMER specifications
*/
#define BSP_HWTIMER1_DEV        pit_devif
#define BSP_HWTIMER1_SOURCE_CLK (CM_CLOCK_SOURCE_SYSTEM)
#define BSP_HWTIMER1_ID         (0)

#define BSP_HWTIMER2_DEV        pit_devif
#define BSP_HWTIMER2_SOURCE_CLK (CM_CLOCK_SOURCE_SYSTEM)
#define BSP_HWTIMER2_ID         (1)

/* Port IRQ levels */
#define BSP_PORTA_INT_LEVEL         (3)
#define BSP_PORTB_INT_LEVEL         (3)
#define BSP_PORTC_INT_LEVEL         (3)
#define BSP_PORTD_INT_LEVEL         (3)
#define BSP_PORTE_INT_LEVEL         (3)

/* LCD board settings */
/* GPIO settings for navigation buttons on LCD board */
#define BSP_LCD_NAVSW_N             (GPIO_PORT_C | GPIO_PIN18)
#define BSP_LCD_NAVSW_W             (GPIO_PORT_E | GPIO_PIN28)
#define BSP_LCD_NAVSW_E             (GPIO_PORT_E | GPIO_PIN5)
#define BSP_LCD_NAVSW_S             (GPIO_PORT_C | GPIO_PIN19)
//#define BSP_LCD_NAVSW_CTR           (GPIO_PORT_E | GPIO_PIN27) /* Conflict with LCD RESET signal */

#define BSP_LCD_DC                  (GPIO_PORT_B | GPIO_PIN17) /* open J3 13-14 */
#define BSP_LCD_DC_FN               1                          /* Functionality for LCD DC pin */

/* GPIO settings for resistive touch screen on LCD board */
#define BSP_LCD_TCHRES_X_PLUS       (GPIO_PORT_B | GPIO_PIN4)
#define BSP_LCD_TCHRES_X_MINUS      (GPIO_PORT_B | GPIO_PIN6)
#define BSP_LCD_TCHRES_Y_PLUS       (GPIO_PORT_B | GPIO_PIN7)
#define BSP_LCD_TCHRES_Y_MINUS      (GPIO_PORT_B | GPIO_PIN5)

#define BSP_LCD_SPI_CHANNEL         "spi2:"

#define BSP_LCD_X_PLUS_ADC_CHANNEL  (ADC1_SOURCE_AD10)
#define BSP_LCD_Y_PLUS_ADC_CHANNEL  (ADC1_SOURCE_AD13)

/* ADC tchres device init struct */
#define BSP_TCHRES_ADC_DEVICE "adc1:"
#define BSP_TCHRES_X_TRIGGER ADC_PDB_TRIGGER
#define BSP_TCHRES_Y_TRIGGER ADC_PDB_TRIGGER

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
**                      DSPI
*/

#define BSP_DSPI_INT_LEVEL               (3)
#define BSP_SPI_MEMORY_CHANNEL           0

/*-----------------------------------------------------------------------------
**                      ESDHC
*/

#define BSP_SDCARD_ESDHC_CHANNEL            "esdhc1:"
#define BSP_SDCARD_GPIO_DETECT              (LWGPIO_PORT_E | LWGPIO_PIN6)
#define BSP_SDCARD_DETECT_MUX_GPIO          (LWGPIO_MUX_E6_GPIO)

/*-----------------------------------------------------------------------------
**                      I2C
*/
#define BSP_I2C_CLOCK                       (BSP_BUS_CLOCK)
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

#define BSP_I2C0_INT_LEVEL                  (5)
#define BSP_I2C1_INT_LEVEL                  (5)
#define BSP_I2C2_INT_LEVEL                  (5)
#define BSP_I2C3_INT_LEVEL                  (5)

#define BSP_I2C0_RX_BUFFER_SIZE             (64)
#define BSP_I2C0_TX_BUFFER_SIZE             (64)
#define BSP_I2C1_RX_BUFFER_SIZE             (64)
#define BSP_I2C1_TX_BUFFER_SIZE             (64)
#define BSP_I2C2_RX_BUFFER_SIZE             (64)
#define BSP_I2C2_TX_BUFFER_SIZE             (64)
#define BSP_I2C3_RX_BUFFER_SIZE             (64)
#define BSP_I2C3_TX_BUFFER_SIZE             (64)



/*-----------------------------------------------------------------------------
**                      I2S
*/

#define BSP_I2S0_MODE                   (I2S_MODE_MASTER)
#define BSP_I2S0_DATA_BITS              (16)
#define BSP_I2S0_CLOCK_SOURCE           (I2S_CLK_INT)
#define BSP_I2S0_INT_LEVEL              (5)
#define BSP_I2S0_BUFFER_SIZE            (128)

/*-----------------------------------------------------------------------------
**                      ADC
*/
#define ADC_MAX_MODULES                 (2)
#define BSP_ADC_POTENTIOMETER           (ADC_INPUT_ADC0_AN5)
#define BSP_ADC_CH_POT                  (ADC1_SOURCE_ADPM1)

#define BSP_ADC0_VECTOR_PRIORITY        (3)
#define BSP_ADC1_VECTOR_PRIORITY        (3)
#define BSP_PDB_VECTOR_PRIORITY         (3)

#define BSP_ADC_VREF_DEFAULT            (3300)
#define BSP_ADC_POTENTIOMETER_MAX       (3300)

#ifndef BSPCFG_ENABLE_LWADC
#define BSPCFG_ENABLE_LWADC 1
#endif

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

/*-----------------------------------------------------------------------------
**                  IO DEVICE DRIVERS CONFIGURATION
*/

#ifndef BSPCFG_ENABLE_IO_SUBSYSTEM
    #define BSPCFG_ENABLE_IO_SUBSYSTEM      1
#endif

/* polled TTY device (UART0) */
#ifndef BSPCFG_ENABLE_TTYA
    #define BSPCFG_ENABLE_TTYA              0
#endif

/* polled TTY device (UART1) */
#ifndef BSPCFG_ENABLE_TTYB
    #define BSPCFG_ENABLE_TTYB              0
#endif

/* polled TTY device (UART2) */
#ifndef BSPCFG_ENABLE_TTYC
    #define BSPCFG_ENABLE_TTYC              0
#endif

/* polled TTY device (UART3) */
#ifndef BSPCFG_ENABLE_TTYD
    #define BSPCFG_ENABLE_TTYD              1
#endif

/* polled TTY device (UART4) */
#ifndef BSPCFG_ENABLE_TTYE
    #define BSPCFG_ENABLE_TTYE              0
#endif

/* polled TTY device (UART5) */
#ifndef BSPCFG_ENABLE_TTYF
    #define BSPCFG_ENABLE_TTYF              1
#endif

/* interrupt-driven TTY device (UART0) */
#ifndef BSPCFG_ENABLE_ITTYA
    #define BSPCFG_ENABLE_ITTYA             0
#endif

/* interrupt-driven TTY device (UART1) */
#ifndef BSPCFG_ENABLE_ITTYB
    #define BSPCFG_ENABLE_ITTYB             0
#endif

/* interrupt-driven TTY device (UART2) */
#ifndef BSPCFG_ENABLE_ITTYC
    #define BSPCFG_ENABLE_ITTYC             0
#endif

/* interrupt-driven TTY device (UART3) */
#ifndef BSPCFG_ENABLE_ITTYD
    #define BSPCFG_ENABLE_ITTYD             0
#endif

/* interrupt-driven TTY device (UART4) */
#ifndef BSPCFG_ENABLE_ITTYE
    #define BSPCFG_ENABLE_ITTYE             0
#endif

/* interrupt-driven TTY device (UART5) */
#ifndef BSPCFG_ENABLE_ITTYF
    #define BSPCFG_ENABLE_ITTYF             0
#endif

/* TTY device HW signals (UART3) */
#ifndef BSPCFG_ENABLE_TTYD_HW_SIGNALS
    #define BSPCFG_ENABLE_TTYD_HW_SIGNALS   0
#endif

/* TTYA and ITTYA baud rate */
#ifndef BSPCFG_SCI0_BAUD_RATE
    #define BSPCFG_SCI0_BAUD_RATE             230400
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

/* polled I2C0 device */
#ifndef BSPCFG_ENABLE_I2C0
    #define BSPCFG_ENABLE_I2C0                  1
#endif

/* polled I2C1 device */
#ifndef BSPCFG_ENABLE_I2C1
    #define BSPCFG_ENABLE_I2C1                  0
#endif

/* int I2C0 device */
#ifndef BSPCFG_ENABLE_II2C0
    #define BSPCFG_ENABLE_II2C0                 0
#endif

/* int I2C1 device */
#ifndef BSPCFG_ENABLE_II2C1
    #define BSPCFG_ENABLE_II2C1                 0
#endif

/* GPIO device */
#ifndef BSPCFG_ENABLE_GPIODEV
    #define BSPCFG_ENABLE_GPIODEV               0
#endif

/* RTC device */
#ifndef BSPCFG_ENABLE_RTCDEV
    #define BSPCFG_ENABLE_RTCDEV                0
#endif

/* PCFLASH device */
#ifndef BSPCFG_ENABLE_PCFLASH
    #define BSPCFG_ENABLE_PCFLASH               0
#endif

/* polled SPI0 */
#ifndef BSPCFG_ENABLE_SPI0
    #define BSPCFG_ENABLE_SPI0                  0
#endif

/* int SPI0 */
#ifndef BSPCFG_ENABLE_ISPI0
    #define BSPCFG_ENABLE_ISPI0                 0
#endif

/* polled SPI1 */
#ifndef BSPCFG_ENABLE_SPI1
    #define BSPCFG_ENABLE_SPI1                  0
#endif

/* int SPI1 */
#ifndef BSPCFG_ENABLE_ISPI1
    #define BSPCFG_ENABLE_ISPI1                 0
#endif

/* polled SPI2 */
#ifndef BSPCFG_ENABLE_SPI2
    #define BSPCFG_ENABLE_SPI2                  0
#endif

/* int SPI2 */
#ifndef BSPCFG_ENABLE_ISPI2
    #define BSPCFG_ENABLE_ISPI2                 0
#endif

/* ADC */
#ifndef BSPCFG_ENABLE_ADC
    #define BSPCFG_ENABLE_ADC                   0
#endif

/* FTFL */
#ifndef BSPCFG_ENABLE_FLASHX
    #define BSPCFG_ENABLE_FLASHX                0
#endif

/* ESDHC device */
#ifndef BSPCFG_ENABLE_ESDHC
    #define BSPCFG_ENABLE_ESDHC                 0
#endif

/* IODEBUG device */
#ifndef BSPCFG_ENABLE_IODEBUG
    #define BSPCFG_ENABLE_IODEBUG               1
#endif

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

/* Defined in link.xxx */
extern uchar __KERNEL_DATA_START[];
extern uchar __KERNEL_DATA_END[];

extern uchar __KERNEL_AREA_START[];
extern uchar __KERNEL_AREA_END[];

extern uchar __USER_HEAP_START[];
extern uchar __USER_HEAP_END[];

extern uchar __SHARED_RAM_START[];
extern uchar __SHARED_RAM_END[];

extern uchar __UNCACHED_DATA_START[];
extern uchar __UNCACHED_DATA_END[];

extern uchar __SRAM_POOL_START[];
extern uchar __SRAM_POOL_END[];

/* Tightly coupled memory - lower */
#define BSP_CORE_M4_TCML_START                                ((pointer) 0x1F800000)
#define BSP_CORE_M4_TCML_SIZE                                 (0x8000)

#if MQX_ENABLE_USER_MODE

#if __IAR_SYSTEMS_ICC__
#pragma section = "USER_RW_MEMORY"
#pragma section = "USER_RO_MEMORY"
#pragma section = "USER_NO_MEMORY"
#pragma section = "USER_HEAP"
#pragma section = "USER_DEFAULT_MEMORY"

#define BSP_DEFAULT_START_OF_USER_DEFAULT_MEMORY            ((pointer)__sfb("USER_DEFAULT_MEMORY"))
#define BSP_DEFAULT_END_OF_USER_DEFAULT_MEMORY              ((pointer)__sfe("USER_DEFAULT_MEMORY"))

//#define BSP_DEFAULT_START_OF_USER_HEAP                      ((pointer)__sfb("USER_HEAP"))
//#define BSP_DEFAULT_END_OF_USER_HEAP                        ((pointer)__sfe("USER_HEAP"))

#define BSP_DEFAULT_START_OF_USER_RW_MEMORY                 ((pointer)__sfb("USER_RW_MEMORY"))
#define BSP_DEFAULT_END_OF_USER_RW_MEMORY                   ((pointer)__sfe("USER_RW_MEMORY"))

#define BSP_DEFAULT_START_OF_USER_RO_MEMORY                 ((pointer)__sfb("USER_RO_MEMORY"))
#define BSP_DEFAULT_END_OF_USER_RO_MEMORY                   ((pointer)__sfe("USER_RO_MEMORY"))

#define BSP_DEFAULT_START_OF_USER_NO_MEMORY                 ((pointer)__sfb("USER_NO_MEMORY"))
#define BSP_DEFAULT_END_OF_USER_NO_MEMORY                   ((pointer)__sfe("USER_NO_MEMORY"))

#elif defined(__CC_ARM)

extern unsigned int Image$$RWUSER$$Base;
extern unsigned int Image$$RWUSER$$Limit;
extern unsigned int Image$$ROUSER$$Base;
extern unsigned int Image$$ROUSER$$Limit;
extern unsigned int Image$$NOUSER$$Base;
extern unsigned int Image$$NOUSER$$Limit;
extern unsigned int Image$$DATA$$Base;
extern unsigned int Image$$DATA$$Limit;

#define BSP_DEFAULT_START_OF_USER_RW_MEMORY                 ((pointer)&Image$$RWUSER$$Base)
#define BSP_DEFAULT_END_OF_USER_RW_MEMORY                   ((pointer)&Image$$RWUSER$$Limit)
#define BSP_DEFAULT_START_OF_USER_RO_MEMORY                 ((pointer)&Image$$ROUSER$$Base)
#define BSP_DEFAULT_END_OF_USER_RO_MEMORY                   ((pointer)&Image$$ROUSER$$Limit)
#define BSP_DEFAULT_START_OF_USER_NO_MEMORY                 ((pointer)&Image$$NOUSER$$Base)
#define BSP_DEFAULT_END_OF_USER_NO_MEMORY                   ((pointer)&Image$$NOUSER$$Limit)

#define BSP_DEFAULT_START_OF_USER_DEFAULT_MEMORY            ((pointer)&Image$$DATA$$Base)
#define BSP_DEFAULT_END_OF_USER_DEFAULT_MEMORY              ((pointer)&Image$$DATA$$Limit)

#else // CW
extern uchar __USER_DEFAULT_MEMORY_START[];
extern uchar __USER_DEFAULT_MEMORY_END[];
extern uchar __USER_RW_MEMORY_START[];
extern uchar __USER_RW_MEMORY_END[];
extern uchar __USER_RO_MEMORY_START[];
extern uchar __USER_RO_MEMORY_END[];
extern uchar __USER_NO_MEMORY_START[];
extern uchar __USER_NO_MEMORY_END[];

#define BSP_DEFAULT_START_OF_USER_DEFAULT_MEMORY            ((pointer)__USER_DEFAULT_MEMORY_START)
#define BSP_DEFAULT_END_OF_USER_DEFAULT_MEMORY              ((pointer)__USER_DEFAULT_MEMORY_END)

//#define BSP_DEFAULT_START_OF_USER_HEAP                      ((pointer)__USER_HEAP_START)
//#define BSP_DEFAULT_END_OF_USER_HEAP                        ((pointer)__USER_AREA_END)

#define BSP_DEFAULT_START_OF_USER_RW_MEMORY                 ((pointer)__USER_RW_MEMORY_START)
#define BSP_DEFAULT_END_OF_USER_RW_MEMORY                   ((pointer)__USER_RW_MEMORY_END)

#define BSP_DEFAULT_START_OF_USER_RO_MEMORY                 ((pointer)__USER_RO_MEMORY_START)
#define BSP_DEFAULT_END_OF_USER_RO_MEMORY                   ((pointer)__USER_RO_MEMORY_END)

#define BSP_DEFAULT_START_OF_USER_NO_MEMORY                 ((pointer)__USER_NO_MEMORY_START)
#define BSP_DEFAULT_END_OF_USER_NO_MEMORY                   ((pointer)__USER_NO_MEMORY_END)

#endif

#define BSP_DEFAULT_START_OF_USER_HEAP                      ((pointer)(16 * 1024))
#define BSP_DEFAULT_END_OF_USER_HEAP                        ((pointer)0)

#define BSP_DEFAULT_START_OF_KERNEL_AREA                    ((pointer)__KERNEL_DATA_START)  //((pointer)__KERNEL_AREA_START)
#define BSP_DEFAULT_END_OF_KERNEL_AREA                      ((pointer)__KERNEL_DATA_END)    //((pointer)__KERNEL_AREA_END)

#define BSP_DEFAULT_MAX_USER_TASK_PRIORITY                  (0)
#define BSP_DEFAULT_MAX_USER_TASK_COUNT                     (0)

#endif // MQX_ENABLE_USER_MODE

#define BSP_DEFAULT_START_OF_KERNEL_MEMORY                    ((pointer)__KERNEL_DATA_START)
#define BSP_DEFAULT_END_OF_KERNEL_MEMORY                      ((pointer)__KERNEL_DATA_END)

#ifndef BSP_CORE_0_PROCESSOR_NUMBER
    #define BSP_CORE_0_PROCESSOR_NUMBER                 (1)
#endif

#ifndef BSP_CORE_1_PROCESSOR_NUMBER
    #define BSP_CORE_1_PROCESSOR_NUMBER                 (2)
#endif

#define BSP_DEFAULT_PROCESSOR_NUMBER                    ((uint_32)BSP_CORE_1_PROCESSOR_NUMBER)

#ifndef MQX_AUX_CORE
#define MQX_AUX_CORE                            1
#endif

#define VF65GS10_SRAM_BASE                     (0x3f000000)
#define VF65GS10_SRAM_CORE_0_BASE              (0x3f07f000)
#define VF65GS10_SRAM_CORE_0_SIZE              (2 * 1024)
#define VF65GS10_SRAM_CORE_0_END               (VF65GS10_SRAM_CORE_0_BASE + VF65GS10_SRAM_CORE_0_SIZE)

#define VF65GS10_SRAM_CORE_1_BASE              (0x3f07f800)
#define VF65GS10_SRAM_CORE_1_SIZE              (2 * 1024)
#define VF65GS10_SRAM_CORE_1_END               (VF65GS10_SRAM_CORE_1_BASE + VF65GS10_SRAM_CORE_1_SIZE)

#if defined(__ARMCC_VERSION)
extern uchar Image$$SHARED_RAM_START$$Base[];
extern uchar Image$$SHARED_RAM_END$$Base[];
#define BSP_SHARED_RAM_START                ((pointer)Image$$SHARED_RAM_START$$Base)
#define BSP_SHARED_RAM_SIZE                 (Image$$SHARED_RAM_END$$Base - Image$$SHARED_RAM_START$$Base)
#else
#define BSP_SHARED_RAM_START                ((pointer)__SHARED_RAM_START)
#define BSP_SHARED_RAM_SIZE                 (__SHARED_RAM_SIZE)
#endif
#define BSP_REMOTE_SHARED_RAM_START         (VF65GS10_SRAM_CORE_0_BASE)

#ifndef BSP_DEFAULT_INTERRUPT_STACK_SIZE
    #define BSP_DEFAULT_INTERRUPT_STACK_SIZE              (3000) //TODO: use ((uint_32)__DEFAULT_INTERRUPT_STACK_SIZE)
#endif

#ifndef BSP_DEFAULT_MQX_HARDWARE_INTERRUPT_LEVEL_MAX
    #define BSP_DEFAULT_MQX_HARDWARE_INTERRUPT_LEVEL_MAX      (2L)
#endif

#ifndef BSP_DEFAULT_MAX_MSGPOOLS
    #define BSP_DEFAULT_MAX_MSGPOOLS                          (2L)
#endif

#ifndef BSP_DEFAULT_MAX_MSGQS
    #define BSP_DEFAULT_MAX_MSGQS                             (16L)
#endif

/*
 * Other Serial console options:(do not forget to enable BSPCFG_ENABLE_TTY define if changed)
 *      "ttyc:"      TWR-SER     polled mode
 */
#ifndef BSP_DEFAULT_IO_CHANNEL
    #if BSPCFG_ENABLE_TTYC
        #define BSP_DEFAULT_IO_CHANNEL                    "ttyc:"
        #define BSP_DEFAULT_IO_CHANNEL_DEFINED
    #else
        #define BSP_DEFAULT_IO_CHANNEL                      NULL
    #endif
#endif

#ifndef BSP_DEFAULT_IO_OPEN_MODE
    #define BSP_DEFAULT_IO_OPEN_MODE                      (pointer) (IO_SERIAL_XON_XOFF | IO_SERIAL_TRANSLATION | IO_SERIAL_ECHO)
#endif

/* FLASHX flash memory pool minimum size */
#if BSPCFG_ENABLE_FLASHX
    #ifndef BSPCFG_FLASHX_SIZE
        #define BSPCFG_FLASHX_SIZE      (FLASHX_END_ADDR - FLASHX_START_ADDR) /* defines maximum possible space */
    #endif
#else
    #undef  BSPCFG_FLASHX_SIZE
    #define BSPCFG_FLASHX_SIZE      0x0
#endif

#endif /* _twrvf65gs10_m4_h_  */
