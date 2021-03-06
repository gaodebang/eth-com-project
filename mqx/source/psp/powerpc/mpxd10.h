/**HEADER********************************************************************
 * 
 * Copyright (c) 2008 Freescale Semiconductor;
 * All Rights Reserved
 *
 * Copyright (c) 2004-2008 Embedded Access Inc.;
 * All Rights Reserved
 *
 * Copyright (c) 1989-2008 ARC International;
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
 * $FileName: mpxd10.h$
 * $Version : 3.8.1.0$
 * $Date    : Sep-26-2012$
 *
 * Comments:
 *
 *   This file contains the type definitions for the Freescale PowerPC 
 *   MPC5668 processor.
 *
 *END***********************************************************************/

#ifndef __MPXD10_h__
#define __MPXD10_h__

/* Indicate processor type */
#define PSP_MPXD10    

#define PSP_NO_MMU_YET
#define PSP_BOOKE_VLE
#define PSP_E200_CORE_Z0


#include <e200core.h>
#include <mpxdxx.h>

/*--------------------------------------------------------------------------*/
/*
 **                    CONSTANT DEFINITIONS
 */

#define PSP_SUPPORT_STRUCT_DEFINED                   1
#define PSP_HAS_DSP                                  0
#define PSP_HAS_DSP_TASKS                            0
#define PSP_HAS_FPU                                  0
#define PSP_ALWAYS_SAVE_AND_RESTORE_VOLATILE_FP_REGS 0

/*==========================================================================*/
/*
 **                   MQX REQUIRED DEFINITIONS
 **
 ** Other MQX kernel and component functions require these definitions to exist.
 */

/*
 ** Define padding needed to make the STOREBLOCK_STRUCT align properly
 ** to cache line size (see mem_prv.h)
 */
#define PSP_MEM_STOREBLOCK_ALIGNMENT   (2) /* padding in _mqx_uints */


#define PSP_MSR_CE     (1<<(63-46)) /* Critical interrupt enable */
#define PSP_MSR_WE     (1<<(63-45)) /* Wait state enable */
#define PSP_MSR_SPE    (1<<(63-38)) /* SPE APU execuition enable */

/* overwrite PSP_MSR_EE in powerpc.h */
#ifdef PSP_MSR_EE
#undef PSP_MSR_EE  
#define PSP_MSR_EE     (1<<(63-48)) /* Exernal interrupt enable */
#endif

#undef  PSP_MEMORY_ACCESSING_CAPABILITY
#define PSP_MEMORY_ACCESSING_CAPABILITY (32)

/* Do you want to verify kernel data can be read and written correctly */
#ifndef PSP_KERNEL_DATA_VERIFY_ENABLE
#define PSP_KERNEL_DATA_VERIFY_ENABLE   \
        ((uint_32)__KERNEL_DATA_VERIFY_ENABLE)
#endif

/*==========================================================================*/
/*
 **                    ISR VECTOR TABLE
 */

/*
 ** Interrupt controller sources
 **
 ** The Interrupt controller has two types of interrupt requests: peripheral and 
 ** software settable. Both interrupts are external input interrupt to 
 ** e200z6 core (IVOR4). 
 **
 ** Software settable interrupts 0-7 are assigned vectors 0-7, respectively.
 ** The peripheral interrupt requests are assigned vectors 8 to 300 to cover
 ** all of the peripheral interrupt requests.
 **
 ** All external interrupts are demuxed by an external ISR to generate
 ** individual ISR for each local interrupt source.
 **
 ** Following is vector table for interrupt controller in software vector mode.
 */

#define MPXD10_INTC_VECTOR_BASE  (PSP_EXCPT_SPE_FP_ROUND + 1)
#define QINTC_BASE_VECTOR          MPXD10_INTC_VECTOR_BASE

#define _PSP_VECTOR_TO_IRQ(v) ((v)-QINTC_BASE_VECTOR)
#define _PSP_IRQ_TO_VECTOR(i) ((i)+QINTC_BASE_VECTOR)

#ifndef __ASM__

typedef enum {
   /* Software settable interrupts */
   MPXD10_INTC_SOFTWARE_INTR_0_VECTOR = MPXD10_INTC_VECTOR_BASE,
   MPXD10_INTC_SOFTWARE_INTR_1_VECTOR,
   MPXD10_INTC_SOFTWARE_INTR_2_VECTOR,
   MPXD10_INTC_SOFTWARE_INTR_3_VECTOR,
   MPXD10_INTC_SOFTWARE_INTR_4_VECTOR,
   MPXD10_INTC_SOFTWARE_INTR_5_VECTOR,
   MPXD10_INTC_SOFTWARE_INTR_6_VECTOR,
   MPXD10_INTC_SOFTWARE_INTR_7_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_8_VECTOR,

   /* ECSM */
   MPXD10_INTC_PLATFORM_FLASH_BANK_ERR_VECTOR,

   /* DMA2x */
   MPXD10_INTC_DMA2X_COMBINED_ERR_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_0_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_1_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_2_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_3_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_4_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_5_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_6_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_7_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_8_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_9_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_10_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_11_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_12_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_13_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_14_VECTOR,
   MPXD10_INTC_DMA2X_CHANNEL_15_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_27_VECTOR,

   /* Software Watchdog - SWT */
   MPXD10_INTC_SWT_TIMEOUT_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_29_VECTOR,

   /* System Timer Module - STM */
   MPXD10_INTC_STM_MATCH_CHANNEL_0_VECTOR,
   MPXD10_INTC_STM_MATCH_CHANNEL_1_VECTOR,
   MPXD10_INTC_STM_MATCH_CHANNEL_2_VECTOR,
   MPXD10_INTC_STM_MATCH_CHANNEL_3_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_34_VECTOR,

   /* ECSM */
   MPXD10_INTC_ECSM_ECC_DBD_VECTOR,
   MPXD10_INTC_ECSM_ECC_SBC_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_37_VECTOR,

   /* RTC */
   MPXD10_INTC_RTC_VECTOR,
   MPXD10_INTC_API_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_40_VECTOR,

   /* RTC */
   MPXD10_INTC_SIU_EXT_IRQ_0_VECTOR,
   MPXD10_INTC_SIU_EXT_IRQ_1_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_43_VECTOR,
   MPXD10_INTC_NOTUSED_44_VECTOR,
   MPXD10_INTC_NOTUSED_45_VECTOR,

   /* WakeUP Unit - WKPU */
   MPXD10_INTC_WAKEUP_IRQ_0_VECTOR,
   MPXD10_INTC_WAKEUP_IRQ_1_VECTOR,
   MPXD10_INTC_WAKEUP_IRQ_2_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_50_VECTOR,
   MPXD10_INTC_NOTUSED_51_VECTOR,

   /* Mode Entry Module - MC_ME */
   MPXD10_INTC_MC_ME_SAFE_MODE_VECTOR,
   MPXD10_INTC_MC_ME_MODE_TRANSIT_VECTOR,
   MPXD10_INTC_MC_ME_INVALID_MODE_VECTOR,
   MPXD10_INTC_MC_ME_INVALID_MODE_CONFIG_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_56_VECTOR,

   /* Reset Generation Module - MC_RGM */
   MPXD10_INTC_MC_RGM_VECTOR,

   /* FXOSC */
   MPXD10_INTC_FXOSC_COUTNER_EXPIRED_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_59_VECTOR,

   /* PIT */
   MPXD10_INTC_PIT_CHANNEL_0_VECTOR,
   MPXD10_INTC_PIT_CHANNEL_1_VECTOR,
   MPXD10_INTC_PIT_CHANNEL_2_VECTOR,

   /* ADC0 */
   MPXD10_INTC_ADC0_EOC_VECTOR,
   MPXD10_INTC_ADC0_ER_VECTOR,
   MPXD10_INTC_ADC0_WD_VECTOR,

   /* FlexCan0 */
   MPXD10_INTC_FLEXCAN0_ESR_ERR_VECTOR,
   MPXD10_INTC_FLEXCAN0_ESR_BOFF_RX_TX_WARN_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_68_VECTOR,

   /* FlexCan0 */
   MPXD10_INTC_FLEXCAN0_BUF_00_03_VECTOR,
   MPXD10_INTC_FLEXCAN0_BUF_04_07_VECTOR,
   MPXD10_INTC_FLEXCAN0_BUF_08_11_VECTOR,
   MPXD10_INTC_FLEXCAN0_BUF_12_15_VECTOR,
   MPXD10_INTC_FLEXCAN0_BUF_16_31_VECTOR,
   MPXD10_INTC_FLEXCAN0_BUF_32_63_VECTOR,

   /* DSPI0 */
   MPXD10_INTC_DSPI0_SR_TFUF_RFOF_VECTOR,
   MPXD10_INTC_DSPI0_SR_EOQF_VECTOR,
   MPXD10_INTC_DSPI0_SR_TFFF_VECTOR,
   MPXD10_INTC_DSPI0_SR_TCF_VECTOR,
   MPXD10_INTC_DSPI0_SR_RFDF_VECTOR,

   /* LINFlex0 */
   MPXD10_INTC_LINFLEX0_RXI_VECTOR,
   MPXD10_INTC_LINFLEX0_TXI_VECTOR,
   MPXD10_INTC_LINFLEX0_ERR_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_83_VECTOR,
   MPXD10_INTC_NOTUSED_84_VECTOR,
   MPXD10_INTC_NOTUSED_85_VECTOR,

   /* FlexCan1 */
   MPXD10_INTC_FLEXCAN1_ESR_ERR_VECTOR,
   MPXD10_INTC_FLEXCAN1_ESR_BOFF_RX_TX_WARN_VECTOR,

   /* NOT USED */
   MPXD10_INTC_NOTUSED_88_VECTOR,

   /* FlexCan1 */
   MPXD10_INTC_FLEXCAN1_BUF_00_03_VECTOR,
   MPXD10_INTC_FLEXCAN1_BUF_04_07_VECTOR,
   MPXD10_INTC_FLEXCAN1_BUF_08_11_VECTOR,
   MPXD10_INTC_FLEXCAN1_BUF_12_15_VECTOR,
   MPXD10_INTC_FLEXCAN1_BUF_16_31_VECTOR,
   MPXD10_INTC_FLEXCAN1_BUF_32_63_VECTOR,

   /* DSPI1 */
   MPXD10_INTC_DSPI1_SR_TFUF_RFOF_VECTOR,
   MPXD10_INTC_DSPI1_SR_EOQF_VECTOR,
   MPXD10_INTC_DSPI1_SR_TFFF_VECTOR,
   MPXD10_INTC_DSPI1_SR_TCF_VECTOR,
   MPXD10_INTC_DSPI1_SR_RFDF_VECTOR,

   /* LINFlex1 */
   MPXD10_INTC_LINFLEX1_RXI_VECTOR,
   MPXD10_INTC_LINFLEX1_TXI_VECTOR,
   MPXD10_INTC_LINFLEX1_ERR_VECTOR,

   MPXD10_INTC_NOTUSED_103_VECTOR,
   /* NOT USED */
   MPXD10_INTC_NOTUSED_104_VECTOR,
   MPXD10_INTC_NOTUSED_105_VECTOR,
   MPXD10_INTC_NOTUSED_106_VECTOR,
   MPXD10_INTC_NOTUSED_107_VECTOR,
   MPXD10_INTC_NOTUSED_108_VECTOR,
   MPXD10_INTC_NOTUSED_109_VECTOR,
   MPXD10_INTC_NOTUSED_110_VECTOR,
   MPXD10_INTC_NOTUSED_111_VECTOR,
   MPXD10_INTC_NOTUSED_112_VECTOR,
   MPXD10_INTC_NOTUSED_113_VECTOR,
   MPXD10_INTC_NOTUSED_114_VECTOR,
   MPXD10_INTC_NOTUSED_115_VECTOR,
   MPXD10_INTC_NOTUSED_116_VECTOR,
   MPXD10_INTC_NOTUSED_117_VECTOR,
   MPXD10_INTC_NOTUSED_118_VECTOR,
   MPXD10_INTC_NOTUSED_119_VECTOR,
   MPXD10_INTC_NOTUSED_120_VECTOR,
   MPXD10_INTC_NOTUSED_121_VECTOR,
   MPXD10_INTC_NOTUSED_122_VECTOR,
   MPXD10_INTC_NOTUSED_123_VECTOR,
   MPXD10_INTC_NOTUSED_124_VECTOR,
   MPXD10_INTC_NOTUSED_125_VECTOR,
   
   /* I2C0, I2C1 */
   MPXD10_INTC_I2C0_IBIF_VECTOR,
   MPXD10_INTC_I2C1_IBIF_VECTOR,
   
   /* PIT */
   MPXD10_INTC_PIT_CHANNEL_3_VECTOR,
   
   /* NOT USED */
   MPXD10_INTC_NOTUSED_129_VECTOR,
   MPXD10_INTC_NOTUSED_130_VECTOR,
   MPXD10_INTC_NOTUSED_131_VECTOR,
   MPXD10_INTC_NOTUSED_132_VECTOR,
   MPXD10_INTC_NOTUSED_133_VECTOR,
   MPXD10_INTC_NOTUSED_134_VECTOR,
   MPXD10_INTC_NOTUSED_135_VECTOR,
   MPXD10_INTC_NOTUSED_136_VECTOR,
   MPXD10_INTC_NOTUSED_137_VECTOR,
   MPXD10_INTC_NOTUSED_138_VECTOR,
   MPXD10_INTC_NOTUSED_139_VECTOR,
   MPXD10_INTC_NOTUSED_140_VECTOR,
   MPXD10_INTC_NOTUSED_141_VECTOR,
   
   /* eMIOS0 */
   MPXD10_INTC_EMIOS0_GFR_F8_F9_VECTOR,
   MPXD10_INTC_EMIOS0_GFR_F10_F11_VECTOR,
   MPXD10_INTC_EMIOS0_GFR_F12_F13_VECTOR,
   MPXD10_INTC_EMIOS0_GFR_F14_F15_VECTOR,
   MPXD10_INTC_EMIOS0_GFR_F16_F17_VECTOR,
   MPXD10_INTC_EMIOS0_GFR_F18_F19_VECTOR,
   MPXD10_INTC_EMIOS0_GFR_F20_F21_VECTOR,
   MPXD10_INTC_EMIOS0_GFR_F22_F23_VECTOR,
   
   /* NOT USED */
   MPXD10_INTC_NOTUSED_150_VECTOR,
   MPXD10_INTC_NOTUSED_151_VECTOR,
   MPXD10_INTC_NOTUSED_152_VECTOR,
   MPXD10_INTC_NOTUSED_153_VECTOR,
   MPXD10_INTC_NOTUSED_154_VECTOR,
   MPXD10_INTC_NOTUSED_155_VECTOR,
   MPXD10_INTC_NOTUSED_156_VECTOR,
   MPXD10_INTC_NOTUSED_157_VECTOR,
   
   /* eMIOS1 */
   MPXD10_INTC_EMIOS1_GFR_F16_F17_VECTOR,
   MPXD10_INTC_EMIOS1_GFR_F18_F19_VECTOR,
   MPXD10_INTC_EMIOS1_GFR_F20_F21_VECTOR,
   MPXD10_INTC_EMIOS1_GFR_F22_F23_VECTOR,
   
   /* NOT USED */
   MPXD10_INTC_NOTUSED_162_VECTOR,
   MPXD10_INTC_NOTUSED_163_VECTOR,
   MPXD10_INTC_NOTUSED_164_VECTOR,
   MPXD10_INTC_NOTUSED_165_VECTOR,
   MPXD10_INTC_NOTUSED_166_VECTOR,
   MPXD10_INTC_NOTUSED_167_VECTOR,
   MPXD10_INTC_NOTUSED_168_VECTOR,
   MPXD10_INTC_NOTUSED_169_VECTOR,
   MPXD10_INTC_NOTUSED_170_VECTOR,
   MPXD10_INTC_NOTUSED_171_VECTOR,
   MPXD10_INTC_NOTUSED_172_VECTOR,
   MPXD10_INTC_NOTUSED_173_VECTOR,
   
   /* I2C2, I2C3 */
   MPXD10_INTC_I2C2_IBIF_VECTOR,
   MPXD10_INTC_I2C3_IBIF_VECTOR,
   
   /* NOT USED */
   MPXD10_INTC_NOTUSED_176_VECTOR,
   MPXD10_INTC_NOTUSED_178_VECTOR,
   MPXD10_INTC_NOTUSED_179_VECTOR,
   MPXD10_INTC_NOTUSED_180_VECTOR,
   MPXD10_INTC_NOTUSED_181_VECTOR,
   MPXD10_INTC_NOTUSED_183_VECTOR,
   MPXD10_INTC_NOTUSED_184_VECTOR,
   MPXD10_INTC_NOTUSED_185_VECTOR,
   
   /* Sound Generation Logic - SGL */
   MPXD10_INTC_SGL_SDCI_VECTOR,
   
   /* Display Control Unit - DCU0 */
   MPXD10_INTC_DCU0_VS_BLANK_LS_BF_VS_VSYNC_VECTOR,
   MPXD10_INTC_DCU0_UNDRUN_VECTOR,
   MPXD10_INTC_DCU0_PARERR_VECTOR,
   MPXD10_INTC_DCU0_PDI_VECTOR,
   
   /* NOT USED */
   MPXD10_INTC_NOTUSED_191_VECTOR,
   MPXD10_INTC_NOTUSED_192_VECTOR,
   MPXD10_INTC_NOTUSED_193_VECTOR,
   MPXD10_INTC_NOTUSED_194_VECTOR,
   
   /* Stepper Motor Driver - SMD0 */
   MPXD10_INTC_SMD0_MCTOI_SCDETECT_VECTOR,
   MPXD10_INTC_SMD0_SSD0_VECTOR,
   MPXD10_INTC_SMD0_SSD1_VECTOR,
   MPXD10_INTC_SMD0_SSD2_VECTOR,
   MPXD10_INTC_SMD0_SSD3_VECTOR,
   MPXD10_INTC_SMD0_SSD4_VECTOR,
   MPXD10_INTC_SMD0_SSD5_VECTOR,
   
   /* Liquid Crystal Display 0 - LCD0*/
   MPXD10_INTC_LCD0_EOF_VECTOR,
   
   /* NOT USED */
   MPXD10_INTC_NOTUSED_203_VECTOR,
   
   /* QuadSPI0 */
   MPXD10_INTC_QSPI0_TFUF_RFOF_TBUF_RBOF_ABOF_VECTOR,
   MPXD10_INTC_QSPI0_EOQF_VECTOR,
   MPXD10_INTC_QSPI0_TFF_TBFF_VECTOR,
   MPXD10_INTC_QSPI0_TCF_TFF_VECTOR,
   MPXD10_INTC_QSPI0_RFDF_RBDF_VECTOR,
   MPXD10_INTC_QSPI0_IPAEF_IPIEF_ICEF_VECTOR
   
} MPXD10_INTERRUPT_VECTOR_TABLE;

// Each PSP defines its own interrupt type. makes it hard to share drivers...
typedef MPXD10_INTERRUPT_VECTOR_TABLE PSP_INTERRUPT_TABLE_INDEX;
typedef MPXD10_INTERRUPT_VECTOR_TABLE IRQInterruptIndex;

#endif /* __ASM__ */

#define QINTC_FIRST_VECTOR      MPXD10_INTC_VECTOR_BASE
#define QINTC_LAST_VECTOR       MPXD10_INTC_QSPI0_IPAEF_IPIEF_ICEF_VECTOR

/* The maximum number of hardware interrupt vectors */
#ifdef PSP_MAXIMUM_INTERRUPT_VECTORS
#undef PSP_MAXIMUM_INTERRUPT_VECTORS
#endif
#define PSP_MAXIMUM_INTERRUPT_VECTORS  (16)
#define PSP_SKIP_INT_INSTALL_FOR_VECTORS case PSP_EXCPT_MACHINE_CHECK:

/*==========================================================================*/
// Memory mapped peripherals
#define MPXD10_SRAM_BASE                     (0x40000000)
#define MPXD10_DFLASH_MEM_BASE               (0x00800000)
#define MPXD10_CFLASH0_MEM_BASE              (0x00000000) 
#define MPXD10_CFLASH1_MEM_BASE              (0x00080000)

#define MPXD10_I2C_0_BASE                    (0xFFE30000)
#define MPXD10_I2C_1_BASE                    (0xFFE34000)
#define MPXD10_I2C_2_BASE                    (0xFFE38000)
#define MPXD10_I2C_3_BASE                    (0xFFE3C000)

#define MPXD10_DSPI_0_BASE                   (0xFFF90000)
#define MPXD10_DSPI_1_BASE                   (0xFFF94000)

#define MPXD10_MPU_BASE                      (0xFFF10000)

#define MPXD10_SWT_BASE                      (0xFFF38000)
#define MPXD10_STM_BASE                      (0xFFF3C000)
#define MPXD10_ECSM_BASE                     (0xFFF40000)
#define MPXD10_EDMA_BASE                     (0xFFF44000)
#define MPXD10_INTC_BASE                     (0xFFF48000)

#define MPXD10_ADC_0_BASE                    (0xFFE00000)

#define MPXD10_LINFLEXD_0_BASE               (0xFFE40000)
#define MPXD10_LINFLEXD_1_BASE               (0xFFE44000)

#define MPXD10_FLEXCAN_0_BASE                (0xFFFC0000)
#define MPXD10_FLEXCAN_1_BASE                (0xFFFC4000)

#define MPXD10_DMA_MUX_BASE                  (0xFFFDC000)
#define MPXD10_PIT_BASE                      (0xC3FF0000)
#define MPXD10_EMIOS_0_BASE                  (0xC3FA0000)
#define MPXD10_EMIOS_1_BASE                  (0xC3FA4000)

#define MPXD10_SIU_BASE                      (0xC3F90000)

#define MPXD10_RTC_BASE                      (0xC3FEC000)
#define MPXD10_SGL_BASE                      (0xFFE78000)
#define MPXD10_QUADSPI_0_BASE                (0xFFFA8000)

#define MPXD10_CFLASH1_BASE                  (0xC3FB0000)
#define MPXD10_CFLASH0_BASE                  (0xC3F88000)
#define MPXD10_DFLASH0_BASE                  (0xC3F8C000)
/*  Current version does not support multi core, 
 ** therefore this definition for Semaphore device is just simply ingored
 */

#define MPXDXX_ADC_NUM_DEVICES               1


#endif
