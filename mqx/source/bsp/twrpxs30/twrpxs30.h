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
* $FileName: twrpxs30.h$
* $Version : 3.8.4.0$
* $Date    : Sep-27-2012$
*
* Comments:
*
*   This include file is used to provide information needed by
*   an application program using the kernel running on the
*   Freescale TWR-PSX30 Tower board.
*
*END*********************************************************************/

#ifndef __twrpxs30_h__
#define __twrpxs30_h__
#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------
**                  HARDWARE INITIALIZATION DEFINITIONS
*/

/*
** Define the board type
*/
#define BSP_TWRPXS30                  TRUE
#define BSP_NAME                      "TWRPXS30"

#define tBOARD                        "Freescale " BSP_NAME
#define tCPU                          "PXS30"
#define tMEMORY                       "256KB Internal RAM"

// TODO: Should be defined in project generation script. Remove this once script is updated
#define _TARGET "Flash"

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
#define BSP_REMOTE_PRIVATE_RAM_START    (pointer)((uint_32)BSP_PRIVATE_RAM_START+MPXS30_SRAM_CORE_1_BASE-MPXS30_SRAM_CORE_0_BASE)
#define BSP_SHARED_RAM_START            (pointer)__SHARED_RAM_START
#define BSP_SHARED_RAM_SIZE             (uint_32)__SHARED_RAM_SIZE
#define BSP_REMOTE_SHARED_RAM_START     (pointer)((uint_32)BSP_SHARED_RAM_START+MPXS30_SRAM_CORE_1_BASE-MPXS30_SRAM_CORE_0_BASE)
#define BSP_UNCACHED_DATA_START         (pointer)__UNCACHED_DATA_START
#define BSP_UNCACHED_DATA_SIZE          (uint_32)__UNCACHED_DATA_SIZE

#define BSP_PRIVATE_RAM_ATTR            (PSP_MMU_WRITE_THROUGH|PSP_MMU_EXEC_ALLOWED|PSP_MMU_PAGE_LOCKED)
#define BSP_REMOTE_PRIVATE_RAM_ATTR     (PSP_MMU_CACHE_INHIBITED|PSP_MMU_WRITE_THROUGH|PSP_MMU_PAGE_LOCKED)
#define BSP_SHARED_RAM_ATTR             (PSP_MMU_CACHE_INHIBITED|PSP_MMU_WRITE_THROUGH|PSP_MMU_EXEC_ALLOWED|PSP_MMU_PAGE_LOCKED)
#define BSP_UNCACHED_DATA_ATTR          (PSP_MMU_CACHE_INHIBITED|PSP_MMU_WRITE_THROUGH|PSP_MMU_EXEC_ALLOWED|PSP_MMU_PAGE_LOCKED)

#define BSP_VIRTIAL_MEMORY_BIT          (0x08000000)
#define RAM_VIRTUAL_ADDRESS             (0x40000000|BSP_VIRTIAL_MEMORY_BIT)


// The Boot code needs to set up some TLBs. The RAM TLB is designated as Process ID 1, so that
// we can add new RAM TLBs for MQX as Process ID 2, and then switch process IDs to enable MQX's TLBs
#define BSP_PID_BOOT        1
#define BSP_PID_MQX         2

// These are the TLBs that are set up prior to MQX starting
#define BSP_FLASH_TLB       0
#define BSP_RAM_TLB         1
#define BSP_PERIPHERAL_TLB  2


/*----------------------------------------------------------------------
**           CLOCK CONFIGURATION
*/

/*
** The processor clock speed
*/

#define BSP_XOSC_CLOCK                 (40000000)
#define BSP_FMPLL0_CLOCK               (180000000)
#define BSP_FMPLL1_CLOCK               (90000000)

#define BSP_CORE_CLOCK                 (BSP_FMPLL0_CLOCK)
#define BSP_TIMEBASE_CLOCK             (BSP_CORE_CLOCK)

#define BSP_SYS_CLK                    (BSP_FMPLL0_CLOCK/2)
#define BSP_PERI0_CLOCK                (BSP_SYS_CLK)
#define BSP_PERI1_CLOCK                (BSP_SYS_CLK/2)
#define BSP_FLASH_CLK                  (BSP_SYS_CLK/2)

#define BSP_MOTC_CLOCK                 (BSP_FMPLL1_CLOCK)

// Used by kernel tests
#define BSP_SYSTEM_CLOCK               (BSP_FMPLL0_CLOCK)

// Used by timing test to display core frequency. Should not be confused with BSP_SYS_CLOCK or BSP_SYSTEM_CLOCK
#define SYSTEM_CLOCK                   (BSP_CORE_CLOCK/ 1000000)

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

#define BSP_GPIO47          MPXS30_473_A8
#define BSP_GPIO48          MPXS30_473_B8
#define BSP_GPIO49          MPXS30_473_E3
#define BSP_GPIO50          MPXS30_473_C5
#define BSP_GPIO51          MPXS30_473_A7
#define BSP_GPIO52          MPXS30_473_B7
#define BSP_GPIO57          MPXS30_473_M1
#define BSP_GPIO60          MPXS30_473_N3
#define BSP_GPIO78          MPXS30_473_Y15
#define BSP_GPIO93          MPXS30_473_Y16
#define BSP_GPIO98          MPXS30_473_R1

#define BSP_GPIO128         MPXS30_473_A17
#define BSP_GPIO132         MPXS30_473_A16
#define BSP_GPIO133         MPXS30_473_C17
#define BSP_GPIO134         MPXS30_473_A15
#define BSP_GPIO135         MPXS30_473_B16
#define BSP_GPIO136         MPXS30_473_C16
#define BSP_GPIO137         MPXS30_473_B15
#define BSP_GPIO138         MPXS30_473_A18
#define BSP_GPIO139         MPXS30_473_C18
#define BSP_GPIO140         MPXS30_473_B19
#define BSP_GPIO141         MPXS30_473_A19
#define BSP_GPIO142         MPXS30_473_D18
#define BSP_GPIO144         MPXS30_473_A20
#define BSP_EIRQ31          BSP_GPIO93
#define BSP_EIRQ26          BSP_GPIO78

#define FEC_TXD0            MPXS30_473_B11
#define FEC_TXD1            MPXS30_473_C11
#define FEC_TXD2            MPXS30_473_C10
#define FEC_TXD3            MPXS30_473_A13
#define FEC_TX_EN           MPXS30_473_A12
#define FEC_TX_ER           MPXS30_473_B13
#define FEC_TX_CLK          MPXS30_473_A11

#define FEC_RXD0            MPXS30_473_B12
#define FEC_RXD1            MPXS30_473_C14
#define FEC_RXD2            MPXS30_473_D14
#define FEC_RXD3            MPXS30_473_B9
#define FEC_RX_DV           MPXS30_473_A9
#define FEC_RX_ER           MPXS30_473_B10
#define FEC_RX_CLK          MPXS30_473_C13

#define FEC_CRS             MPXS30_473_C12
#define FEC_COL             MPXS30_473_C15

#define FEC_MDC             MPXS30_473_D15
#define FEC_MDIO            MPXS30_473_A10

#define DSPI0_CS0           MPXS30_473_L1
#define DSPI0_CS1           MPXS30_473_Y5

// The following are not brough out on TWRPXS30. Re-enable for customer specific hardware
//#define DSPI0_CS2         MPXS30_473_Y3
//#define DSPI0_CS3         MPXS30_473_W3

#define DSPI0_SCK           MPXS30_473_K1
#define DSPI0_SIN           MPXS30_473_M3
#define DSPI0_SOUT          MPXS30_473_D4

#define DSPI1_CS0           MPXS30_473_K2
#define DSPI1_CS2           MPXS30_473_V4
#define DSPI1_CS3           MPXS30_473_AA4
#define DSPI1_SCK           MPXS30_473_K3
#define DSPI1_SIN           MPXS30_473_J4
#define DSPI1_SOUT          MPXS30_473_K4

#define DSPI2_CS0           MPXS30_473_L3
#define DSPI2_CS1           MPXS30_473_B6
#define DSPI2_CS2           MPXS30_473_L2
#define DSPI2_SCK           MPXS30_473_U4
#define DSPI2_SIN           MPXS30_473_AC3
#define DSPI2_SOUT          MPXS30_473_AB3

#define LIN0_TXD            MPXS30_473_V20
#define LIN0_RXD            MPXS30_473_W20

#define LIN1_TXD            MPXS30_473_AA22
#define LIN1_RXD            MPXS30_473_AB21

#define LIN2_TXD            MPXS30_473_B18
#define LIN2_RXD            MPXS30_473_D19

#define LIN3_TXD            MPXS30_473_B17
#define LIN3_RXD            MPXS30_473_C19

#define CAN0_TXD            MPXS30_473_B21
#define CAN0_RXD            MPXS30_473_C20

#define CAN1_TXD            MPXS30_473_B4
#define CAN1_RXD            MPXS30_473_D3

#define CAN2_TXD            MPXS30_473_L2    // Shared with DSPI2
#define CAN2_RXD            MPXS30_473_B6    // Shared with DSPI2

#define CAN3_TXD            MPXS30_473_L3    // Shared with DSPI2
#define CAN3_RXD            MPXS30_473_U4    // Shared with DSPI2

#define I2C0_CLOCK          MPXS30_473_V20   // Shared with Lin0_Tx
#define I2C0_DATA           MPXS30_473_W20   // Shared with Lin0_Rx

#define I2C1_CLOCK          MPXS30_473_AA22  // Shared with Lin1_Tx
#define I2C1_DATA           MPXS30_473_AB21  // Shared with Lin1_Rx

#define I2C2_CLOCK          MPXS30_473_B20
#define I2C2_DATA           MPXS30_473_A21

#define FLEXPWM0_A0         MPXS30_473_N1
#define FLEXPWM0_A1         MPXS30_473_R3
#define FLEXPWM0_A2         MPXS30_473_P3
#define FLEXPWM0_A3         MPXS30_473_P4
#define FLEXPWM0_B0         MPXS30_473_P1
#define FLEXPWM0_B1         MPXS30_473_P2
#define FLEXPWM0_B2         MPXS30_473_N4
#define FLEXPWM0_B3         MPXS30_473_T1
// The following are not brough out on TWRPXS30. Re-enable for customer specific hardware
//#define FLEXPWM0_X0         MPXS30_473_M1
//#define FLEXPWM0_X1         MPXS30_473_N3
//#define FLEXPWM0_X2         MPXS30_473_R1
//#define FLEXPWM0_X3         MPXS30_473_R2

#define FLEXPWM1_A0         MPXS30_473_T2
#define FLEXPWM1_A1         MPXS30_473_T3
#define FLEXPWM1_A2         MPXS30_473_U3
#define FLEXPWM1_A3         MPXS30_473_AC4
#define FLEXPWM1_B0         MPXS30_473_U1
#define FLEXPWM1_B1         MPXS30_473_U2
#define FLEXPWM1_B2         MPXS30_473_V3
#define FLEXPWM1_B3         MPXS30_473_AC5
// The following are not brough out on TWRPXS30. Re-enable for customer specific hardware
//#define FLEXPWM1_X0         MPXS30_473_Y5
//#define FLEXPWM1_X1         MPXS30_473_AA5
//#define FLEXPWM1_X2         MPXS30_473_AB4

#define ADC2_AN0            MPXS30_473_AA8
#define ADC2_AN1            MPXS30_473_AB8
#define ADC2_AN2            MPXS30_473_AB9
#define ADC2_AN3            MPXS30_473_AC9

#define ADC2_ADC3_AN11      MPXS30_473_Y7
#define ADC2_ADC3_AN12      MPXS30_473_AA7
#define ADC2_ADC3_AN13      MPXS30_473_AB7
#define ADC2_ADC3_AN14      MPXS30_473_Y8

#define ADC3_AN0            MPXS30_473_Y6
#define ADC3_AN1            MPXS30_473_AA6
#define ADC3_AN2            MPXS30_473_AB6
#define ADC3_AN3            MPXS30_473_AC6

#define ADC0_AN0            MPXS30_473_AB10
#define ADC0_AN1            MPXS30_473_AC10
#define ADC0_AN2            MPXS30_473_AA11
#define ADC0_AN3            MPXS30_473_AC11
#define ADC0_AN4            MPXS30_473_AB11
#define ADC0_AN5            MPXS30_473_AA12
#define ADC0_AN6            MPXS30_473_AB12
#define ADC0_AN7            MPXS30_473_AB13
#define ADC0_AN8            MPXS30_473_AA13

#define ADC0_ADC1_AN11      MPXS30_473_Y14
#define ADC0_ADC1_AN12      MPXS30_473_AA14
#define ADC0_ADC1_AN13      MPXS30_473_AB14
#define ADC0_ADC1_AN14      MPXS30_473_AC14

#define ADC1_AN0            MPXS30_473_AA15
#define ADC1_AN1            MPXS30_473_AB15
#define ADC1_AN2            MPXS30_473_AA16
#define ADC1_AN3            MPXS30_473_AB16
#define ADC1_AN4            MPXS30_473_AB17
#define ADC1_AN5            MPXS30_473_AA17
#define ADC1_AN6            MPXS30_473_Y18
#define ADC1_AN7            MPXS30_473_AA18
#define ADC1_AN8            MPXS30_473_Y17

// Board specific GPIOs
#define BSP_LIN0_TXD_ENABLE BSP_GPIO142
#define BSP_LIN0_RXD_ENABLE BSP_GPIO144

#define BSP_BUTTON1         BSP_GPIO78
#define BSP_BUTTON2         BSP_GPIO93
// TWPXS30 only supports two buttons. Add the following for customer specific hardware
//#define BSP_BUTTON3       TBD
//#define BSP_BUTTON4       TBD

#define BSP_BUTTON1_MUX_GPIO 0
#define BSP_BUTTON2_MUX_GPIO 0
#define BSP_BUTTON3_MUX_GPIO 0
#define BSP_BUTTON4_MUX_GPIO 0

#define BSP_LED1            BSP_GPIO60
#define BSP_LED2            BSP_GPIO98
#define BSP_LED3            BSP_GPIO48
#define BSP_LED4            BSP_GPIO49

#define BSP_LED1_MUX_GPIO   (SIUL_PCR_SMC_MASK)
#define BSP_LED2_MUX_GPIO   (SIUL_PCR_SMC_MASK)
#define BSP_LED3_MUX_GPIO   (SIUL_PCR_SMC_MASK)
#define BSP_LED4_MUX_GPIO   (SIUL_PCR_SMC_MASK)


/*----------------------------------------------------------------------
**            LWADC
*/

#define BSP_ADC_CLOCK               (BSP_MOTC_CLOCK/2)
#define BSP_ADC_VREF_DEFAULT        5000 // in millivolts
#define BSP_ADC_POTENTIOMETER_MAX   5000 // in millivolts

#define BSP_ADC_POTENTIOMETER       ADC_INPUT_ADC0_AN8
#define BSP_ADC_TB1_PIN2            ADC_INPUT_ADC1_AN5
#define BSP_ADC_TB1_PIN3            ADC_INPUT_ADC0_AN7

#define BSP_ADC_INPUT_0             BSP_ADC_TB1_PIN2
#define BSP_ADC_INPUT_1             BSP_ADC_TB1_PIN3


#define BSP_ADC_TWRPI_PIN8          ADC_INPUT_ADC0_AN3
#define BSP_ADC_TWRPI_PIN9          ADC_INPUT_ADC0_AN4
#define BSP_ADC_TWRPI_PIN12         ADC_INPUT_ADC0_AN5
#define BSP_ADC_TWRPI_PIN17         ADC_INPUT_ADC0_AN1
#define BSP_ADC_TWRPI_PIN18         ADC_INPUT_ADC0_AN2

#define BSP_ADC_TWR_AN7             ADC_INPUT_ADC0_AN7
#define BSP_ADC_TWR_AN6             ADC_INPUT_ADC0_AN6
#define BSP_ADC_TWR_AN5             ADC_INPUT_ADC0_AN5
#define BSP_ADC_TWR_AN4             ADC_INPUT_ADC0_AN4
#define BSP_ADC_TWR_AN3             ADC_INPUT_ADC0_AN3
#define BSP_ADC_TWR_AN2             ADC_INPUT_ADC1_AN0
#define BSP_ADC_TWR_AN1             ADC_INPUT_ADC0_AN13
#define BSP_ADC_TWR_AN0             ADC_INPUT_ADC0_AN12

#define BSP_ADC_TWR_AN13            ADC_INPUT_ADC1_AN5
#define BSP_ADC_TWR_AN12            ADC_INPUT_ADC1_AN4
#define BSP_ADC_TWR_AN11            ADC_INPUT_ADC1_AN3
#define BSP_ADC_TWR_AN10            ADC_INPUT_ADC0_AN0
#define BSP_ADC_TWR_AN9             ADC_INPUT_ADC2_AN13
#define BSP_ADC_TWR_AN8             ADC_INPUT_ADC2_AN12

#define BSP_ADC_VDD_CORE            ADC_INPUT_ADC0_VDD_LV_COR
#define BSP_ADC_TEMPERATURE         ADC_INPUT_ADC0_TSENS

/*----------------------------------------------------------------------
**            FEC ETHERNET DRIVER CONFIGURATION
*/

#define BSP_ENET0 0
#define BSP_DEFAULT_ENET_DEVICE BSP_ENET0

#define BSP_ENET_DEVICE_COUNT MPXS30_FEC_DEVICE_COUNT

#define BSP_ENET0_PHY_ADDR                1
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
  #define BSPCFG_RX_RING_LEN              8
#endif

/*
** Number of transmit BD's.
** MGCT: <option type="number"/>
*/
#ifndef BSPCFG_TX_RING_LEN
  #define BSPCFG_TX_RING_LEN              8
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

/** MGCT: </category> */

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

/*
** MGCT: <option type="number" min="0"/>
*/
#ifndef BSPCFG_DEFAULT_LINFLEXD_BAUD_RATE
    #define BSPCFG_DEFAULT_LINFLEXD_BAUD_RATE    115200
#endif

/*
** MGCT: <option type="number" min="0"/>
*/
#ifndef BSPCFG_DEFAULT_LINFLEXD_QUEUE_SIZE
    #define BSPCFG_DEFAULT_LINFLEXD_QUEUE_SIZE   64
#endif

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

/*
** TTYA and ITTYA baud rate
** MGCT: <option type="string"/>
*/
#ifndef BSPCFG_LINFLEXD0_BAUD_RATE
    #define BSPCFG_LINFLEXD0_BAUD_RATE           BSPCFG_DEFAULT_LINFLEXD_BAUD_RATE
#endif

/*
** TTYA and ITTYA buffer size
** MGCT: <option type="string"/>
*/
#ifndef BSPCFG_LINFLEXD0_QUEUE_SIZE
    #define BSPCFG_LINFLEXD0_QUEUE_SIZE          BSPCFG_DEFAULT_LINFLEXD_QUEUE_SIZE
#endif

/*
** ITTYA interrupt priority
** MGCT: <option type="number" min="0"/>
*/
#ifndef BSPCFG_LINFLEXD0_PRIORITY
    #define BSPCFG_LINFLEXD0_PRIORITY            8
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

/* 
** TTYB and ITTYB baud rate
** MGCT: <option type="string"/>
*/
#ifndef BSPCFG_LINFLEXD1_BAUD_RATE
    #define BSPCFG_LINFLEXD1_BAUD_RATE           BSPCFG_DEFAULT_LINFLEXD_BAUD_RATE
#endif

/* 
** TTYB and ITTYB buffer size 
** MGCT: <option type="string"/>
*/
#ifndef BSPCFG_LINFLEXD1_QUEUE_SIZE
    #define BSPCFG_LINFLEXD1_QUEUE_SIZE          BSPCFG_DEFAULT_LINFLEXD_QUEUE_SIZE
#endif

/* 
** ITTYB interrupt priority
** MGCT: <option type="number" min="0"/>
*/
#ifndef BSPCFG_LINFLEXD1_PRIORITY
    #define BSPCFG_LINFLEXD1_PRIORITY            8
#endif

/** MGCT: </category> */

/** MGCT: <category name="LINFLEXD2 Settings"> */

/*
** Polled TTY device (LINFLEXD2)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_TTYC
    #define BSPCFG_ENABLE_TTYC              1
#endif

/*
** Interrupt-driven TTY device (LINFLEXD2)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ITTYC
    #define BSPCFG_ENABLE_ITTYC             1
#endif

/*
** TTYC and ITTYC baud rate
** MGCT: <option type="string"/>
*/
#ifndef BSPCFG_LINFLEXD2_BAUD_RATE
    #define BSPCFG_LINFLEXD2_BAUD_RATE           BSPCFG_DEFAULT_LINFLEXD_BAUD_RATE
#endif

/*
** TTYC and ITTYC buffer size
** MGCT: <option type="string"/>
*/
#ifndef BSPCFG_LINFLEXD2_QUEUE_SIZE
    #define BSPCFG_LINFLEXD2_QUEUE_SIZE          BSPCFG_DEFAULT_LINFLEXD_QUEUE_SIZE
#endif

/*
** ITTYC interrupt priority
** MGCT: <option type="number" min="0"/>
*/
#ifndef BSPCFG_LINFLEXD2_PRIORITY
    #define BSPCFG_LINFLEXD2_PRIORITY            8
#endif

/** MGCT: </category> */

/** MGCT: <category name="LINFLEXD3 Settings"> */

/*
** Polled TTY device (LINFLEXD3)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_TTYD
    #define BSPCFG_ENABLE_TTYD              1
#endif

/*
** Interrupt-driven TTY device (LINFLEXD3)
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ITTYD
    #define BSPCFG_ENABLE_ITTYD             1
#endif

/*
** TTYD and ITTYD baud rate
** MGCT: <option type="string"/>
*/
#ifndef BSPCFG_LINFLEXD3_BAUD_RATE
    #define BSPCFG_LINFLEXD3_BAUD_RATE           BSPCFG_DEFAULT_LINFLEXD_BAUD_RATE
#endif

/*
** TTYD and ITTYD buffer size
** MGCT: <option type="string"/>
*/
#ifndef BSPCFG_LINFLEXD3_QUEUE_SIZE
    #define BSPCFG_LINFLEXD3_QUEUE_SIZE          BSPCFG_DEFAULT_LINFLEXD_QUEUE_SIZE
#endif

/*
** ITTYD interrupt priority
** MGCT: <option type="number" min="0"/>
*/
#ifndef BSPCFG_LINFLEXD3_PRIORITY
    #define BSPCFG_LINFLEXD3_PRIORITY            8
#endif

/** MGCT: </category> */

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
    #define BSPCFG_ENABLE_I2C2             1
#endif

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_II2C2
    #define BSPCFG_ENABLE_II2C2            1
#endif

#if BSPCFG_ENABLE_I2C2
     #define BSPCFG_DEFAULT_I2C_DEVICE     "i2c2:"
#endif

#if BSPCFG_ENABLE_II2C2
     #define BSPCFG_DEFAULT_II2C_DEVICE    "ii2c2:"
#endif

#define BSP_I2C_CLOCK                      (BSP_PERI1_CLOCK)
#define BSP_I2C0_ADDRESS                   (0x6E)
#define BSP_I2C1_ADDRESS                   (0x6F)
#define BSP_I2C2_ADDRESS                   (0x6D)
#define BSP_I2C0_BAUD_RATE                 (400000)
#define BSP_I2C1_BAUD_RATE                 (100000)
#define BSP_I2C2_BAUD_RATE                 (100000)
#define BSP_I2C0_MODE                      (I2C_MODE_MASTER)
#define BSP_I2C1_MODE                      (I2C_MODE_MASTER)
#define BSP_I2C2_MODE                      (I2C_MODE_MASTER)
#define BSP_I2C0_INT_LEVEL                 (1)
#define BSP_I2C1_INT_LEVEL                 (1)
#define BSP_I2C2_INT_LEVEL                 (1)
#define BSP_I2C0_RX_BUFFER_SIZE            (64)
#define BSP_I2C0_TX_BUFFER_SIZE            (64)
#define BSP_I2C1_RX_BUFFER_SIZE            (64)
#define BSP_I2C1_TX_BUFFER_SIZE            (64)
#define BSP_I2C2_RX_BUFFER_SIZE            (64)
#define BSP_I2C2_TX_BUFFER_SIZE            (64)

/* I2C Address for MMA8451 */
#define I2C_ACCELEROMETER_ADDRESS           0x1C


/*----------------------------------------------------------------------
**            SPI DRIVER CONFIGURATION
*/

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_SPI0
    #define BSPCFG_ENABLE_SPI0             1
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
    #define BSPCFG_ENABLE_SPI1             1
#endif

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ISPI1
    #define BSPCFG_ENABLE_ISPI1            0
#endif

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_SPI2
    #define BSPCFG_ENABLE_SPI2             1
#endif

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_ISPI2
    #define BSPCFG_ENABLE_ISPI2            0
#endif

#define BSP_DSPI_RX_BUFFER_SIZE            (32)
#define BSP_DSPI_TX_BUFFER_SIZE            (32)
#define BSP_DSPI_BAUDRATE                  (1000000)
#define BSP_DSPI_INT_LEVEL                 (4)
#define BSP_DSPI_INT_SUBLEVEL              (0)

/*----------------------------------------------------------------------
**            ADC ENABLEMENT
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

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_LWADC2
    #if BSPCFG_ENABLE_LWADC
        #define BSPCFG_ENABLE_LWADC2 1
    #else
        #define BSPCFG_ENABLE_LWADC2 0
    #endif
#endif

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_LWADC3
    #if BSPCFG_ENABLE_LWADC
        #define BSPCFG_ENABLE_LWADC3 1
    #else
        #define BSPCFG_ENABLE_LWADC3 0
    #endif
#endif

/*
** FTFL
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_FLASHX
    #define BSPCFG_ENABLE_FLASHX                0
#endif

/** MGCT: </category> */ 

/*----------------------------------------------------------------------
**            SPI Serial FLASH CONFIGURATION
*/

#define BSP_SPI_MEMORY_CHANNEL             (0)

/*----------------------------------------------------------------------
**            SDCard DRIVER CONFIGURATION
*/

#define BSP_SDCARD_SPI_CHANNEL             "spi2:"
#define BSP_SDCARD_SPI_CS                  (1)
/* SDCARD WP cannot be used, pin is shared with SDI (MISO) */
//#define BSP_SDCARD_GPIO_DETECT

/* SDCARD protect not available */
//#define BSP_SDCARD_GPIO_PROTECT


/*----------------------------------------------------------------------
**            FLEXCAN DRIVER CONFIGURATION
*/
#define FLEXCAN_IPBUS_CLK                  (BSP_FMPLL1_CLOCK/2)
#define FLEXCAN_OSC_CLK                    (BSP_XOSC_CLOCK)


/*----------------------------------------------------------------------
**            IPC for Shared Memory
*/
// Set to let Shared memory driver that there is core specific support required
#define BSPCFG_IO_PCB_SHM_SUPPORT           1
#define BSPCFG_IO_PCB_SHM_RX_PRIO           2
#define BSPCFG_IO_PCB_SHM_TX_PRIO           2


/*----------------------------------------------------------------------
**            IPC for Serial
*/
#define CORE_0_SERIAL_IPC_PORT_NAME         "ittya:"
#define CORE_1_SERIAL_IPC_PORT_NAME         "ittyc:"

#define DEFAULT_SERIAL_IPC_PORT_NAME        CORE_0_SERIAL_IPC_PORT_NAME

/** MGCT: <category name="Other Options" order="2000"> */

/*----------------------------------------------------------------------
**            Core Mutex
*/

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_CORE_MUTEX
    #define BSPCFG_CORE_MUTEX               1
#endif

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_CORE_MUTEX_STATS
    #define BSPCFG_CORE_MUTEX_STATS         0
#endif

#define BSPCFG_CORE_MUTEX_PRIORITY          3

/*
** MGCT: <option type="bool"/>
*/
#ifndef BSPCFG_ENABLE_CPP
    #define BSPCFG_ENABLE_CPP               0
#endif

/** MGCT: </category> */ 

/*----------------------------------------------------------------------
**                  DEFAULT MQX INITIALIZATION DEFINITIONS
** MGCT: <category name="Default MQX initialization parameters"> 
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


#ifndef BSP_DEFAULT_IO_OPEN_MODE
    #define BSP_DEFAULT_IO_OPEN_MODE                     (pointer) \
        (IO_SERIAL_XON_XOFF | IO_SERIAL_TRANSLATION | IO_SERIAL_ECHO)
#endif

/** MGCT: <category name="Core 0 Settings"> */

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_0_PROCESSOR_NUMBER
    #define BSP_CORE_0_PROCESSOR_NUMBER                 BSP_DEFAULT_PROCESSOR_NUMBER
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_0_INTERRUPT_STACK_SIZE
    #define BSP_CORE_0_INTERRUPT_STACK_SIZE             BSP_DEFAULT_INTERRUPT_STACK_SIZE
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_0_MQX_HARDWARE_INTERRUPT_LEVEL_MAX
    #define BSP_CORE_0_MQX_HARDWARE_INTERRUPT_LEVEL_MAX BSP_DEFAULT_MQX_HARDWARE_INTERRUPT_LEVEL_MAX
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_0_MAX_MSGPOOLS
    #define BSP_CORE_0_MAX_MSGPOOLS                     BSP_DEFAULT_MAX_MSGPOOLS
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_0_MAX_MSGQS
    #define BSP_CORE_0_MAX_MSGQS                        BSP_DEFAULT_MAX_MSGQS
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_0_IO_CHANNEL
    #define BSP_CORE_0_IO_CHANNEL                       "ittyb:"
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_0_IO_OPEN_MODE
    #define BSP_CORE_0_IO_OPEN_MODE                     BSP_DEFAULT_IO_OPEN_MODE
#endif

/** MGCT: </category> */ 

/** MGCT: <category name="Core 1 Settings"> */

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_1_PROCESSOR_NUMBER
    #define BSP_CORE_1_PROCESSOR_NUMBER                 BSP_DEFAULT_PROCESSOR_NUMBER+1
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_1_INTERRUPT_STACK_SIZE
    #define BSP_CORE_1_INTERRUPT_STACK_SIZE             BSP_DEFAULT_INTERRUPT_STACK_SIZE
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_1_MQX_HARDWARE_INTERRUPT_LEVEL_MAX
    #define BSP_CORE_1_MQX_HARDWARE_INTERRUPT_LEVEL_MAX BSP_DEFAULT_MQX_HARDWARE_INTERRUPT_LEVEL_MAX
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_1_MAX_MSGPOOLS
    #define BSP_CORE_1_MAX_MSGPOOLS                     BSP_DEFAULT_MAX_MSGPOOLS
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_1_MAX_MSGQS
    #define BSP_CORE_1_MAX_MSGQS                        BSP_DEFAULT_MAX_MSGQS
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_1_IO_CHANNEL
    #define BSP_CORE_1_IO_CHANNEL                       "ittyd:"
#endif

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_CORE_1_IO_OPEN_MODE
    #define BSP_CORE_1_IO_OPEN_MODE                     BSP_DEFAULT_IO_OPEN_MODE
#endif

/** MGCT: </category> */ 

/*
** MGCT: <option type="string"/>
*/
#ifndef BSP_DEFAULT_IO_CHANNEL
    #define BSP_DEFAULT_IO_CHANNEL                      BSP_CORE_0_IO_CHANNEL
    #define BSP_DEFAULT_IO_CHANNEL_DEFINED              1
#else
    /* undef is for backward compatibility with user_configh.h files which have already had it defined */
    #undef  BSP_DEFAULT_IO_CHANNEL_DEFINED
    #define BSP_DEFAULT_IO_CHANNEL_DEFINED              1
#endif

/** MGCT: </category> */ 

#ifdef __cplusplus
}
#endif

#endif
