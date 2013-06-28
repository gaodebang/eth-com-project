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
* $FileName: mpxs30.h$
* $Version : 3.8.3.0$
* $Date    : Jul-9-2012$
*
* Comments:
*
*   This file contains the type definitions for the Freescale PowerPC 
*   MPXS30 processor.
*
*END***********************************************************************/

#ifndef __mpxs30_h__
#define __mpxs30_h__

/* Indicate processor type */
#define PSP_BOOKE
#define PSP_E200_CORE_Z7

// Specify # MMU TLB entries prior to including e200core.h 
#define E200CORE_MMU_NUM_TLBS       (64)

// TODO: Are these still needed?- Apparently not
#define PSP_MPXS30
#define PSP_MPC5675K

#include <e200core.h>
#include <mpxsxx.h>
#include <core_cnfg_mpxs30.h>

/*--------------------------------------------------------------------------*/
/*
**                    CONSTANT DEFINITIONS
*/

#define PSP_NUM_CORES                                2
#define PSP_SUPPORT_STRUCT_DEFINED                   1
#define PSP_HAS_DSP                                  0
#define PSP_HAS_DSP_TASKS                            0
#define PSP_HAS_FPU                                  0
#define PSP_ALWAYS_SAVE_AND_RESTORE_VOLATILE_FP_REGS 0
#define PSP_HAS_DEVICE_PROTECTION                    1

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

// TODO: Verify this
/* CTXCR register is not supported by MPC5xxx. CS field is read as zero */
#define PSP_IVORx_MASK                 (0xFF8)

#define PSP_MSR_CE 	   (1<<(63-46)) /* Critical interrupt enable */
#define PSP_MSR_WE 	   (1<<(63-45)) /* Wait state enable */
#define PSP_MSR_SPE        (1<<(63-38)) /* SPE APU execuition enable */

/* overwrite PSP_MSR_EE in powerpc.h */
#ifdef PSP_MSR_EE
#undef PSP_MSR_EE  
#define PSP_MSR_EE         (1<<(63-48)) /* Exernal interrupt enable */
#endif

/* Some extra cache defines */
#define PSP_DCACHE_NUM_LINES       (128)
#define PSP_DCACHE_NUM_WAYS        (4)
#ifdef PSP_DCACHE_SIZE
#undef PSP_DCACHE_SIZE
#define PSP_DCACHE_SIZE            (PSP_DCACHE_NUM_LINES*PSP_CACHE_LINE_SIZE*PSP_DCACHE_NUM_WAYS) /* 16Kbyte */
#endif

#define PSP_ICACHE_NUM_LINES       (128)
#define PSP_ICACHE_NUM_WAYS        (4)
#ifdef PSP_ICACHE_SIZE
#undef PSP_ICACHE_SIZE
#define PSP_ICACHE_SIZE            (PSP_ICACHE_NUM_LINES*PSP_CACHE_LINE_SIZE*PSP_DCACHE_NUM_WAYS) /* 16Kbyte */
#endif

#undef  PSP_MEMORY_ACCESSING_CAPABILITY
#define PSP_MEMORY_ACCESSING_CAPABILITY (32)

/* Do you want to verify kernel data can be read and written correctly */
#define PSP_KERNEL_DATA_VERIFY_ENABLE   ((uint_32)__KERNEL_DATA_VERIFY_ENABLE)


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

#define MPXS30_INTC_VECTOR_BASE  (PSP_EXCPT_SPE_FP_ROUND + 1)
#define QINTC_BASE_VECTOR          MPXS30_INTC_VECTOR_BASE

#define _PSP_VECTOR_TO_IRQ(v) ((v)-MPXS30_INTC_VECTOR_BASE)
#define _PSP_IRQ_TO_VECTOR(i) ((i)+MPXS30_INTC_VECTOR_BASE)

#ifndef __ASM__

typedef enum
{
/* Software settable interrupts */
   MPXS30_INTC_SSCIR0_VECTOR             = _PSP_IRQ_TO_VECTOR(0),
   MPXS30_INTC_SSCIR1_VECTOR             = _PSP_IRQ_TO_VECTOR(1),
   MPXS30_INTC_SSCIR2_VECTOR             = _PSP_IRQ_TO_VECTOR(2),
   MPXS30_INTC_SSCIR3_VECTOR             = _PSP_IRQ_TO_VECTOR(3),
   MPXS30_INTC_SSCIR4_VECTOR             = _PSP_IRQ_TO_VECTOR(4),
   MPXS30_INTC_SSCIR5_VECTOR             = _PSP_IRQ_TO_VECTOR(5),
   MPXS30_INTC_SSCIR6_VECTOR             = _PSP_IRQ_TO_VECTOR(6),
   MPXS30_INTC_SSCIR7_VECTOR             = _PSP_IRQ_TO_VECTOR(7),
   
   MPXS30_INTC_PIT_0_VECTOR              = _PSP_IRQ_TO_VECTOR(59),
   MPXS30_INTC_PIT_1_VECTOR              = _PSP_IRQ_TO_VECTOR(60),
   MPXS30_INTC_PIT_2_VECTOR              = _PSP_IRQ_TO_VECTOR(61),
   MPXS30_INTC_PIT_3_VECTOR              = _PSP_IRQ_TO_VECTOR(127),

   MPXS30_INTC_SIU_IRQ_0_VECTOR          = _PSP_IRQ_TO_VECTOR(41),
   MPXS30_INTC_SIU_IRQ_1_VECTOR          = _PSP_IRQ_TO_VECTOR(42),
   MPXS30_INTC_SIU_IRQ_2_VECTOR          = _PSP_IRQ_TO_VECTOR(43),
   MPXS30_INTC_SIU_IRQ_3_VECTOR          = _PSP_IRQ_TO_VECTOR(44),
   
   MPXS30_INTC_ADC0_EOC_VECTOR           = _PSP_IRQ_TO_VECTOR(62),
   MPXS30_INTC_ADC0_ER_VECTOR            = _PSP_IRQ_TO_VECTOR(63),
   MPXS30_INTC_ADC0_WD_VECTOR            = _PSP_IRQ_TO_VECTOR(64),

   MPXS30_INTC_ADC1_EOC_VECTOR           = _PSP_IRQ_TO_VECTOR(82),
   MPXS30_INTC_ADC1_ER_VECTOR            = _PSP_IRQ_TO_VECTOR(83),
   MPXS30_INTC_ADC1_WD_VECTOR            = _PSP_IRQ_TO_VECTOR(84),

   MPXS30_INTC_ADC2_EOC_VECTOR           = _PSP_IRQ_TO_VECTOR(102),
   MPXS30_INTC_ADC2_ER_VECTOR            = _PSP_IRQ_TO_VECTOR(103),
   MPXS30_INTC_ADC2_WD_VECTOR            = _PSP_IRQ_TO_VECTOR(104),

   MPXS30_INTC_ADC3_EOC_VECTOR           = _PSP_IRQ_TO_VECTOR(302),
   MPXS30_INTC_ADC3_ER_VECTOR            = _PSP_IRQ_TO_VECTOR(303),
   MPXS30_INTC_ADC3_WD_VECTOR            = _PSP_IRQ_TO_VECTOR(304),

   MPXS30_INTC_FLEXCAN0_ESR_VECTOR       = _PSP_IRQ_TO_VECTOR(65),
   MPXS30_INTC_FLEXCAN0_BOFF_VECTOR      = _PSP_IRQ_TO_VECTOR(66),
   MPXS30_INTC_FLEXCAN0_BUF_00_03_VECTOR = _PSP_IRQ_TO_VECTOR(68),
   MPXS30_INTC_FLEXCAN0_BUF_04_07_VECTOR = _PSP_IRQ_TO_VECTOR(69),
   MPXS30_INTC_FLEXCAN0_BUF_08_11_VECTOR = _PSP_IRQ_TO_VECTOR(70),
   MPXS30_INTC_FLEXCAN0_BUF_12_15_VECTOR = _PSP_IRQ_TO_VECTOR(71),
   MPXS30_INTC_FLEXCAN0_BUF_16_31_VECTOR = _PSP_IRQ_TO_VECTOR(72),

   MPXS30_INTC_FLEXCAN1_ESR_VECTOR       = _PSP_IRQ_TO_VECTOR(85),
   MPXS30_INTC_FLEXCAN1_BOFF_VECTOR      = _PSP_IRQ_TO_VECTOR(86),
   MPXS30_INTC_FLEXCAN1_BUF_00_03_VECTOR = _PSP_IRQ_TO_VECTOR(88),
   MPXS30_INTC_FLEXCAN1_BUF_04_07_VECTOR = _PSP_IRQ_TO_VECTOR(89),
   MPXS30_INTC_FLEXCAN1_BUF_08_11_VECTOR = _PSP_IRQ_TO_VECTOR(90),
   MPXS30_INTC_FLEXCAN1_BUF_12_15_VECTOR = _PSP_IRQ_TO_VECTOR(91),
   MPXS30_INTC_FLEXCAN1_BUF_16_31_VECTOR = _PSP_IRQ_TO_VECTOR(92),

   MPXS30_INTC_FLEXCAN2_ESR_VECTOR       = _PSP_IRQ_TO_VECTOR(105),
   MPXS30_INTC_FLEXCAN2_BOFF_VECTOR      = _PSP_IRQ_TO_VECTOR(106),
   MPXS30_INTC_FLEXCAN2_BUF_00_03_VECTOR = _PSP_IRQ_TO_VECTOR(108),
   MPXS30_INTC_FLEXCAN2_BUF_04_07_VECTOR = _PSP_IRQ_TO_VECTOR(109),
   MPXS30_INTC_FLEXCAN2_BUF_08_11_VECTOR = _PSP_IRQ_TO_VECTOR(110),
   MPXS30_INTC_FLEXCAN2_BUF_12_15_VECTOR = _PSP_IRQ_TO_VECTOR(111),
   MPXS30_INTC_FLEXCAN2_BUF_16_31_VECTOR = _PSP_IRQ_TO_VECTOR(112),

   MPXS30_INTC_FLEXCAN3_ESR_VECTOR       = _PSP_IRQ_TO_VECTOR(282),
   MPXS30_INTC_FLEXCAN3_BOFF_VECTOR      = _PSP_IRQ_TO_VECTOR(283),
   MPXS30_INTC_FLEXCAN3_BUF_00_03_VECTOR = _PSP_IRQ_TO_VECTOR(285),
   MPXS30_INTC_FLEXCAN3_BUF_04_07_VECTOR = _PSP_IRQ_TO_VECTOR(286),
   MPXS30_INTC_FLEXCAN3_BUF_08_11_VECTOR = _PSP_IRQ_TO_VECTOR(287),
   MPXS30_INTC_FLEXCAN3_BUF_12_15_VECTOR = _PSP_IRQ_TO_VECTOR(288),
   MPXS30_INTC_FLEXCAN3_BUF_16_31_VECTOR = _PSP_IRQ_TO_VECTOR(289),


   MPXS30_INTC_DSPI0_TFUF_RFOF_VECTOR    = _PSP_IRQ_TO_VECTOR(74),
   MPXS30_INTC_DSPI0_EOQF_VECTOR         = _PSP_IRQ_TO_VECTOR(75),
   MPXS30_INTC_DSPI0_TFFF_VECTOR         = _PSP_IRQ_TO_VECTOR(76),
   MPXS30_INTC_DSPI0_TCF_VECTOR          = _PSP_IRQ_TO_VECTOR(77),
   MPXS30_INTC_DSPI0_RFDF_VECTOR         = _PSP_IRQ_TO_VECTOR(78),


   MPXS30_INTC_DSPI1_TFUF_RFOF_VECTOR    = _PSP_IRQ_TO_VECTOR(94),
   MPXS30_INTC_DSPI1_EOQF_VECTOR         = _PSP_IRQ_TO_VECTOR(95),
   MPXS30_INTC_DSPI1_TFFF_VECTOR         = _PSP_IRQ_TO_VECTOR(96),
   MPXS30_INTC_DSPI1_TCF_VECTOR          = _PSP_IRQ_TO_VECTOR(97),
   MPXS30_INTC_DSPI1_RFDF_VECTOR         = _PSP_IRQ_TO_VECTOR(98),

   MPXS30_INTC_DSPI2_TFUF_RFOF_VECTOR    = _PSP_IRQ_TO_VECTOR(114),
   MPXS30_INTC_DSPI2_EOQF_VECTOR         = _PSP_IRQ_TO_VECTOR(115),
   MPXS30_INTC_DSPI2_TFFF_VECTOR         = _PSP_IRQ_TO_VECTOR(116),
   MPXS30_INTC_DSPI2_TCF_VECTOR          = _PSP_IRQ_TO_VECTOR(117),
   MPXS30_INTC_DSPI2_RFDF_VECTOR         = _PSP_IRQ_TO_VECTOR(118),


   MPXS30_INTC_LINFLEX0_RXI_VECTOR       = _PSP_IRQ_TO_VECTOR(79),
   MPXS30_INTC_LINFLEX0_TXI_VECTOR       = _PSP_IRQ_TO_VECTOR(80),
   MPXS30_INTC_LINFLEX0_ERR_VECTOR       = _PSP_IRQ_TO_VECTOR(81),

   MPXS30_INTC_LINFLEX1_RXI_VECTOR       = _PSP_IRQ_TO_VECTOR(99),
   MPXS30_INTC_LINFLEX1_TXI_VECTOR       = _PSP_IRQ_TO_VECTOR(100),
   MPXS30_INTC_LINFLEX1_ERR_VECTOR       = _PSP_IRQ_TO_VECTOR(101),

   MPXS30_INTC_LINFLEX2_RXI_VECTOR       = _PSP_IRQ_TO_VECTOR(119),
   MPXS30_INTC_LINFLEX2_TXI_VECTOR       = _PSP_IRQ_TO_VECTOR(120),
   MPXS30_INTC_LINFLEX2_ERR_VECTOR       = _PSP_IRQ_TO_VECTOR(121),

   MPXS30_INTC_LINFLEX3_RXI_VECTOR       = _PSP_IRQ_TO_VECTOR(122),
   MPXS30_INTC_LINFLEX3_TXI_VECTOR       = _PSP_IRQ_TO_VECTOR(123),
   MPXS30_INTC_LINFLEX3_ERR_VECTOR       = _PSP_IRQ_TO_VECTOR(124),

   MPXS30_INTC_I2C0_VECTOR               = _PSP_IRQ_TO_VECTOR(125),
   MPXS30_INTC_I2C1_VECTOR               = _PSP_IRQ_TO_VECTOR(126),
   MPXS30_INTC_I2C2_VECTOR               = _PSP_IRQ_TO_VECTOR(292),

   MPXS30_INTC_SEMA40_VECTOR             = _PSP_IRQ_TO_VECTOR(247),
   MPXS30_INTC_SEMA41_VECTOR             = _PSP_IRQ_TO_VECTOR(248),

   MPXS30_INTC_FEC_TX_VECTOR             = _PSP_IRQ_TO_VECTOR(334),
   MPXS30_INTC_FEC_RX_VECTOR             = _PSP_IRQ_TO_VECTOR(335),
   MPXS30_INTC_FEC_ERR_VECTOR            = _PSP_IRQ_TO_VECTOR(336)

} PSP_INTERRUPT_VECTOR_TABLE;

// Each PSP defines its own interrupt type. makes it hard to share drivers...
typedef PSP_INTERRUPT_VECTOR_TABLE PSP_INTERRUPT_TABLE_INDEX;
typedef PSP_INTERRUPT_VECTOR_TABLE IRQInterruptIndex;


#endif /* __ASM__ */

#define QINTC_FIRST_VECTOR      MPXS30_INTC_VECTOR_BASE
#define QINTC_LAST_VECTOR       MPXS30_INTC_FEC_ERR_VECTOR

/* The maximum number of hardware interrupt vectors */
#ifdef PSP_MAXIMUM_INTERRUPT_VECTORS
#undef PSP_MAXIMUM_INTERRUPT_VECTORS
#endif
#define PSP_MAXIMUM_INTERRUPT_VECTORS  (16)
#define PSP_SKIP_INT_INSTALL_FOR_VECTORS	case PSP_EXCPT_MACHINE_CHECK:


/*==========================================================================*/
// Memory mapped peripherals
#define MPXS30_FLASH_BASE                    (0x00000000)
#define MPXS30_CFLASH0_MEM_BASE              (0x00000000)
#define MPXS30_CFLASH1_MEM_BASE              (0x00040000)
#define MPXS30_DFLASH_MEM_BASE               (0x00800000)

#define MPXS30_SRAM_BASE                     (0x40000000)
#define MPXS30_SRAM_CORE_0_BASE              (0x40000000)
#define MPXS30_SRAM_CORE_0_SIZE              (256*1024)
#define MPXS30_SRAM_CORE_0_END               (MPXS30_SRAM_CORE_0_BASE+MPXS30_SRAM_CORE_0_SIZE)

#define MPXS30_SRAM_CORE_1_BASE              (0x50000000)
#define MPXS30_SRAM_CORE_1_SIZE              (256*1024)
#define MPXS30_SRAM_CORE_1_END               (MPXS30_SRAM_CORE_1_BASE+MPXS30_SRAM_CORE_1_SIZE)

#define MPXS30_DRAM_BASE                     (0x60000000)

// On-platform 1 peripherals
#define MPXS30_PERIPHERAL_BASE               (0x80000000)
#define MPXS30_PBRIDGE_1_BASE                (0x8ff00000)
#define MPXS30_XBAR_1_BASE                   (0x8ff04000)
#define MPXS30_MPU_1_BASE                    (0x8ff10000)
#define MPXS30_SEMA4_1_BASE                  (0x8ff24000)
#define MPXS30_SWT_1_BASE                    (0x8ff38000)
#define MPXS30_STM_1_BASE                    (0x8ff3c000)
#define MPXS30_ECSM_1_BASE                   (0x8ff40000)
#define MPXS30_DMA_1_BASE                    (0x8ff44000)
#define MPXS30_INTC_1_BASE                   (0x8ff48000)

// Off-platform peripherals
#define MPXS30_PDI_BASE                      (0xc3e40000)
#define MPXS30_ADC_2_BASE                    (0xc3e50000)
#define MPXS30_ADC_3_BASE                    (0xc3e54000)
#define MPXS30_CTU_1_BASE                    (0xc3e5c000)
#define MPXS30_CRCU_1_BASE                   (0xc3e60000)
#define MPXS30_FLEXPWM_2_BASE                (0xc3e74000)
#define MPXS30_EBI_BASE                      (0xc3f84000)
#define MPXS30_CFLASH0_BASE                  (0xc3f88000)
#define MPXS30_DFLASH0_BASE                  (0xc3f8c000)
#define MPXS30_SIUL_BASE                     (0xc3f90000)
#define MPXS30_WKPU_BASE                     (0xc3f94000)
#define MPXS30_MDDRC_BASE                    (0xc3f98000)
#define MPXS30_DMACHMUX_1_BASE               (0xc3fac000)
#define MPXS30_CFLASH1_BASE                  (0xc3fb0000)
#define MPXS30_SSCM_BASE                     (0xc3fd8000)
#define MPXS30_MC_ME_BASE                    (0xc3fdc000)
#define MPXS30_MC_CGM_BASE                   (0xc3fe0000)
#define MPXS30_MC_RGM_BASE                   (0xc3fe4000)
#define MPXS30_MC_PCU_BASE                   (0xc3fe8000)
#define MPXS30_PIT_BASE                      (0xc3ff0000)
#define MPXS30_STCU_BASE                     (0xc3ff4000)
#define MPXS30_ADC_0_BASE                    (0xffe00000)
#define MPXS30_ADC_1_BASE                    (0xffe04000)
#define MPXS30_CTU_0_BASE                    (0xffe0c000)
#define MPXS30_ETIMER_0_BASE                 (0xffe18000)
#define MPXS30_ETIMER_1_BASE                 (0xffe1c000)
#define MPXS30_ETIMER_2_BASE                 (0xffe20000)
#define MPXS30_FLEXPWM_0_BASE                (0xffe24000)
#define MPXS30_FLEXPWM_1_BASE                (0xffe28000)
#define MPXS30_I2C0_BASE                     (0xffe30000)
#define MPXS30_I2C1_BASE                     (0xffe34000)
#define MPXS30_I2C2_BASE                     (0xffe38000)
#define MPXS30_LINFLEXD_0_BASE               (0xffe40000)
#define MPXS30_LINFLEXD_1_BASE               (0xffe44000)
#define MPXS30_LINFLEXD_2_BASE               (0xffe48000)
#define MPXS30_LINFLEXD_3_BASE               (0xffe4c000)
#define MPXS30_CRCU_0_BASE                   (0xffe68000)
#define MPXS30_FCCU_BASE                     (0xffe6c000)
// On-platform 0 peripherals
#define MPXS30_PBRIDGE_BASE                  (0xfff00000)
#define MPXS30_XBAR_BASE                     (0xfff04000)
#define MPXS30_MPU_BASE                      (0xfff10000)
#define MPXS30_SEMA4_0_BASE                  (0xfff24000)
#define MPXS30_SWT_BASE                      (0xfff38000)
#define MPXS30_STM_BASE                      (0xfff3c000)
#define MPXS30_ECSM_BASE                     (0xfff40000)
#define MPXS30_DMA_BASE                      (0xfff44000)
#define MPXS30_INTC_BASE                     (0xfff48000)

// Off-platform peripherals
#define MPXS30_ETHERNET_BASE                 (0xfff4c000)
#define MPXS30_COHERENCY_MODULE_BASE         (0xfff50000)
#define MPXS30_DSPI_0_BASE                   (0xfff90000)
#define MPXS30_DSPI_1_BASE                   (0xfff94000)
#define MPXS30_DSPI_2_BASE                   (0xfff98000)
#define MPXS30_CAN0_BASE                     (0xfffc0000)
#define MPXS30_CAN1_BASE                     (0xfffc4000)
#define MPXS30_CAN2_BASE                     (0xfffc8000)
#define MPXS30_CAN3_BASE                     (0xfffcc000)
#define MPXS30_DMACHMUX_BASE                 (0xfffdc000)
#define MPXS30_FLEXRAY_BASE                  (0xfffe0000)
#define MPXS30_BAM_BASE                      (0xffffc000)


#define SEMA4_NUM_DEVICES                    2
#define MPXSXX_ADC_NUM_DEVICES               4

/*----------------------------------------------------------------------------*/

/* MMU and Cache */

// MPXS30 MMU page sizes.
// Note MPXS30 allows 1K and 2K page sizes, but these sizes have restrictions on placement
// Also, MPXS30 allows 4G pages size, but we can't use it, so we don't allow it
#define E200CORE_MMU_MIN_PAGE_SIZE  (4*1024)
#define E200CORE_MMU_MAX_PAGE_SIZE  (2*1024*1024)

#define _mpxs30_mmu_init       _mmu_init
#define _mpxs30_mmu_disable    _mmu_disable
#define _mpxs30_mmu_enable     _mmu_enable
#define _mpxs30_mmu_add_region _mmu_add_region
#define _mpxs30_mmu_add_regions(x) _mmu_add_region(x,0,0)


/* Pin definitions - 257 pin package */
#define MPXS30_257_A4  114
#define MPXS30_257_A5  112
#define MPXS30_257_A6  110
#define MPXS30_257_A7  51
#define MPXS30_257_A8  47
#define MPXS30_257_A10 213
#define MPXS30_257_A11 209
#define MPXS30_257_A12 211
#define MPXS30_257_A13 198
#define MPXS30_257_A14 200
#define MPXS30_257_A15 204
#define MPXS30_257_B3  22
#define MPXS30_257_B4  14
#define MPXS30_257_B5  219
#define MPXS30_257_B6  9
#define MPXS30_257_B7  52
#define MPXS30_257_B8  48
#define MPXS30_257_B10 214
#define MPXS30_257_B11 215
#define MPXS30_257_B12 212
#define MPXS30_257_B13 205
#define MPXS30_257_B14 207
#define MPXS30_257_B15 16
#define MPXS30_257_C2  220
#define MPXS30_257_C5  50
#define MPXS30_257_C6  0
#define MPXS30_257_C7  1
#define MPXS30_257_C8  2
#define MPXS30_257_C9  3
#define MPXS30_257_C11 208
#define MPXS30_257_C12 201
#define MPXS30_257_C13 206
#define MPXS30_257_C14 17
#define MPXS30_257_C16 136
#define MPXS30_257_C17 128
#define MPXS30_257_D1  85
#define MPXS30_257_D2  84
#define MPXS30_257_D3  15
#define MPXS30_257_D4  38
#define MPXS30_257_D6  44
#define MPXS30_257_D7  43
#define MPXS30_257_D10 203
#define MPXS30_257_D11 202
#define MPXS30_257_D12 210
#define MPXS30_257_D13 199
#define MPXS30_257_D16 131
#define MPXS30_257_D17 132
#define MPXS30_257_E2  86
#define MPXS30_257_E3  49
#define MPXS30_257_E14 129
#define MPXS30_257_E15 133
#define MPXS30_257_E16 134
#define MPXS30_257_E17 135
#define MPXS30_257_F1  113
#define MPXS30_257_F2  108
#define MPXS30_257_F3  7
#define MPXS30_257_F4  8
#define MPXS30_257_F14 233
#define MPXS30_257_F15 137
#define MPXS30_257_F16 138
#define MPXS30_257_F17 139
#define MPXS30_257_G1  115
#define MPXS30_257_G3  37
#define MPXS30_257_G4  6
#define MPXS30_257_G14 140
#define MPXS30_257_G15 141
#define MPXS30_257_G16 142
#define MPXS30_257_G17 130
#define MPXS30_257_H1  109
#define MPXS30_257_H3  36
#define MPXS30_257_H4  5
#define MPXS30_257_H14 143
#define MPXS30_257_H15 144
#define MPXS30_257_H17 194
#define MPXS30_257_J1  87
#define MPXS30_257_J2  111
#define MPXS30_257_J3  10
#define MPXS30_257_J4  42
#define MPXS30_257_J14 145
#define MPXS30_257_J15 146
#define MPXS30_257_J17 195
#define MPXS30_257_K1  89
#define MPXS30_257_K2  88
#define MPXS30_257_K3  216
#define MPXS30_257_K4  39
#define MPXS30_257_K14 196
#define MPXS30_257_K15 197
#define MPXS30_257_K16 149
#define MPXS30_257_K17 148
#define MPXS30_257_L1  90
#define MPXS30_257_L2  91
#define MPXS30_257_L3  11
#define MPXS30_257_L4  218
#define MPXS30_257_L16 150
#define MPXS30_257_L17 20
#define MPXS30_257_M3  56
#define MPXS30_257_M4  217
#define MPXS30_257_M14 152
#define MPXS30_257_M15 21
#define MPXS30_257_M17 157
#define MPXS30_257_N3  53
#define MPXS30_257_N14 154
#define MPXS30_257_N15 151
#define MPXS30_257_N16 155
#define MPXS30_257_N17 156
#define MPXS30_257_P3  54
#define MPXS30_257_P5  45
#define MPXS30_257_P6  46
#define MPXS30_257_P8  92
#define MPXS30_257_P12 93
#define MPXS30_257_P13 78
#define MPXS30_257_P15 153
#define MPXS30_257_P16 147
#define MPXS30_257_P17 163
#define MPXS30_257_R4  55
#define MPXS30_257_R14 18
#define MPXS30_257_R16 164
#define MPXS30_257_R17 165
#define MPXS30_257_T3  12
#define MPXS30_257_T14 19
#define MPXS30_257_T15 4
#define MPXS30_257_U3  13

/* Pin definitions - 473 pin package */
#define MPXS30_473_A4  114
#define MPXS30_473_A5  112
#define MPXS30_473_A6  110
#define MPXS30_473_A7  51
#define MPXS30_473_A8  47
#define MPXS30_473_A9  210
#define MPXS30_473_A10 198
#define MPXS30_473_A11 207
#define MPXS30_473_A12 200
#define MPXS30_473_A13 204
#define MPXS30_473_A15 134
#define MPXS30_473_A16 132
#define MPXS30_473_A17 128
#define MPXS30_473_A18 138
#define MPXS30_473_A19 141
#define MPXS30_473_A20 144
#define MPXS30_473_A21 146
#define MPXS30_473_B3  22
#define MPXS30_473_B4  14
#define MPXS30_473_B5  219
#define MPXS30_473_B6  9
#define MPXS30_473_B7  52
#define MPXS30_473_B8  48
#define MPXS30_473_B9  214
#define MPXS30_473_B10 215
#define MPXS30_473_B11 201
#define MPXS30_473_B12 211
#define MPXS30_473_B13 205
#define MPXS30_473_B15 137
#define MPXS30_473_B16 135
#define MPXS30_473_B17 131
#define MPXS30_473_B18 129
#define MPXS30_473_B19 140
#define MPXS30_473_B20 145
#define MPXS30_473_B21 16
#define MPXS30_473_C2  220
#define MPXS30_473_C5  50
#define MPXS30_473_C6  43
#define MPXS30_473_C7  1
#define MPXS30_473_C8  2
#define MPXS30_473_C9  3
#define MPXS30_473_C10 203
#define MPXS30_473_C11 202
#define MPXS30_473_C12 208
#define MPXS30_473_C13 209
#define MPXS30_473_C14 212
#define MPXS30_473_C15 206
#define MPXS30_473_C16 136
#define MPXS30_473_C17 133
#define MPXS30_473_C18 139
#define MPXS30_473_C19 143
#define MPXS30_473_C20 17
#define MPXS30_473_C22 197
#define MPXS30_473_C23 152
#define MPXS30_473_D1  86
#define MPXS30_473_D2  84
#define MPXS30_473_D3  15
#define MPXS30_473_D4  38
#define MPXS30_473_D6  44
#define MPXS30_473_D7  0
#define MPXS30_473_D14 213
#define MPXS30_473_D15 199
#define MPXS30_473_D18 142
#define MPXS30_473_D19 130
#define MPXS30_473_D21 155
#define MPXS30_473_D22 195
#define MPXS30_473_D23 154
#define MPXS30_473_E2  85
#define MPXS30_473_E3  49
#define MPXS30_473_E20 233
#define MPXS30_473_E21 149
#define MPXS30_473_E22 150
#define MPXS30_473_E23 156
#define MPXS30_473_F1  109
#define MPXS30_473_F2  108
#define MPXS30_473_F3  113
#define MPXS30_473_F4  115
#define MPXS30_473_F20 151
#define MPXS30_473_F21 194
#define MPXS30_473_F22 148
#define MPXS30_473_F23 179
#define MPXS30_473_G1  87
#define MPXS30_473_G3  111
#define MPXS30_473_G4  88
#define MPXS30_473_G20 196
#define MPXS30_473_G21 190
#define MPXS30_473_G22 192
#define MPXS30_473_G23 181
#define MPXS30_473_H1  90
#define MPXS30_473_H3  89
#define MPXS30_473_H4  91
#define MPXS30_473_H20 176
#define MPXS30_473_J1  216
#define MPXS30_473_J2  218
#define MPXS30_473_J3  217
#define MPXS30_473_J4  8
#define MPXS30_473_J20 174
#define MPXS30_473_J21 175
#define MPXS30_473_J22 177
#define MPXS30_473_J23 180
#define MPXS30_473_K1  37
#define MPXS30_473_K2  5
#define MPXS30_473_K3  6
#define MPXS30_473_K4  7
#define MPXS30_473_K21 178
#define MPXS30_473_K22 182
#define MPXS30_473_K23 183
#define MPXS30_473_L1  36
#define MPXS30_473_L2  42
#define MPXS30_473_L3  10
#define MPXS30_473_M1  57
#define MPXS30_473_M3  39
#define MPXS30_473_M20 157
#define MPXS30_473_M21 153
#define MPXS30_473_M22 185
#define MPXS30_473_M23 184
#define MPXS30_473_N1  58
#define MPXS30_473_N3  60
#define MPXS30_473_N4  100
#define MPXS30_473_N20 191
#define MPXS30_473_N21 193
#define MPXS30_473_N22 187
#define MPXS30_473_N23 186
#define MPXS30_473_P1  59
#define MPXS30_473_P2  62
#define MPXS30_473_P3  99
#define MPXS30_473_P4  102
#define MPXS30_473_P20 188
#define MPXS30_473_P21 189
#define MPXS30_473_R1  98
#define MPXS30_473_R2  101
#define MPXS30_473_R3  80
#define MPXS30_473_R21 161
#define MPXS30_473_R22 147
#define MPXS30_473_T1  103
#define MPXS30_473_T2  117
#define MPXS30_473_T3  120
#define MPXS30_473_T20 166
#define MPXS30_473_T21 167
#define MPXS30_473_T22 159
#define MPXS30_473_U1  118
#define MPXS30_473_U2  121
#define MPXS30_473_U3  123
#define MPXS30_473_U4  11
#define MPXS30_473_U20 164
#define MPXS30_473_U21 170
#define MPXS30_473_U23 158
#define MPXS30_473_V3  124
#define MPXS30_473_V4  56
#define MPXS30_473_V20 18
#define MPXS30_473_V21 171
#define MPXS30_473_V23 160
#define MPXS30_473_W3  53
#define MPXS30_473_W20 19
#define MPXS30_473_W21 172
#define MPXS30_473_W22 165
#define MPXS30_473_W23 162
#define MPXS30_473_Y3  54
#define MPXS30_473_Y5  116
#define MPXS30_473_Y6  229
#define MPXS30_473_Y7  225
#define MPXS30_473_Y8  228
#define MPXS30_473_Y9  45
#define MPXS30_473_Y10 46
#define MPXS30_473_Y11 92

#define MPXS30_473_Y14 24
#define MPXS30_473_Y15 78
#define MPXS30_473_Y16 93
#define MPXS30_473_Y17 74
#define MPXS30_473_Y18 76
#define MPXS30_473_Y21 173
#define MPXS30_473_Y22 169
#define MPXS30_473_Y23 163
#define MPXS30_473_AA4 55
#define MPXS30_473_AA5  119
#define MPXS30_473_AA6  230
#define MPXS30_473_AA7  226
#define MPXS30_473_AA8  221
#define MPXS30_473_AA11 33
#define MPXS30_473_AA12 66
#define MPXS30_473_AA13 69
#define MPXS30_473_AA14 26
#define MPXS30_473_AA15 29
#define MPXS30_473_AA16 31
#define MPXS30_473_AA17 64
#define MPXS30_473_AA18 73
#define MPXS30_473_AA19 21
#define MPXS30_473_AA20 4
#define MPXS30_473_AA22 94
#define MPXS30_473_AA23 168
#define MPXS30_473_AB3  12
#define MPXS30_473_AB4  122
#define MPXS30_473_AB5  125
#define MPXS30_473_AB6  231
#define MPXS30_473_AB7  227
#define MPXS30_473_AB8  222
#define MPXS30_473_AB9  223
#define MPXS30_473_AB10 23
#define MPXS30_473_AB11 70
#define MPXS30_473_AB12 71
#define MPXS30_473_AB13 68
#define MPXS30_473_AB14 27
#define MPXS30_473_AB15 30
#define MPXS30_473_AB16 32
#define MPXS30_473_AB17 75
#define MPXS30_473_AB18 20
#define MPXS30_473_AB21 95
#define MPXS30_473_AC3  13
#define MPXS30_473_AC4  126
#define MPXS30_473_AC5  127
#define MPXS30_473_AC6  232
#define MPXS30_473_AC9  224
#define MPXS30_473_AC10 24
#define MPXS30_473_AC11 34
#define MPXS30_473_AC14 28


#define MPXS30_PADSEL_CTU0_EXT_IN                     0  
#define MPXS30_PADSEL_DSPI2_SCK                       1  
#define MPXS30_PADSEL_DSPI2_SIN                       2  
#define MPXS30_PADSEL_DSPI2_CS0                       3  
#define MPXS30_PADSEL_TIMER0_ETC_4                    7  
#define MPXS30_PADSEL_TIMER0_ETC_5                    8  
#define MPXS30_PADSEL_TIMER1_ETC_0                    9  
#define MPXS30_PADSEL_TIMER1_ETC_1                    10 
#define MPXS30_PADSEL_TIMER1_ETC_2                    11 
#define MPXS30_PADSEL_ETIMER1_ETC_3                   12 
#define MPXS30_PADSEL_ETIMER1_ETC_4                   13 
#define MPXS30_PADSEL_ETIMER1_ETC_5                   14 
#define MPXS30_PADSEL_FLEXPWM0_EXT_SYNC               15 
#define MPXS30_PADSEL_FLEXPWM0_FAULT_0                16 
#define MPXS30_PADSEL_FLEXPWM0_FAULT_1                17 
#define MPXS30_PADSEL_FLEXPWM0_FAULT_3                19 
#define MPXS30_PADSEL_FLEXPWM0_A_0                    20 
#define MPXS30_PADSEL_FLEXPWM0_A_1                    21 
#define MPXS30_PADSEL_FLEXPWM0_A_2                    22 
#define MPXS30_PADSEL_FLEXPWM0_A_3                    23 
#define MPXS30_PADSEL_FLEXPWM0_B_0                    24 
#define MPXS30_PADSEL_FLEXPWM0_B_1                    25 
#define MPXS30_PADSEL_FLEXPWM0_B_2                    26 
#define MPXS30_PADSEL_FLEXPWM0_B_3                    27 
#define MPXS30_PADSEL_FLEXPWM0_X_1                    28 
#define MPXS30_PADSEL_FLEXPWM0_X_2                    29 
#define MPXS30_PADSEL_FLEXPWM0_X_3                    30 
#define MPXS30_PADSEL_LINFLEX0_RXD                    31 
#define MPXS30_PADSEL_LINFLEX1_RXD                    32 
#define MPXS30_PADSEL_FLEXCAN0_RXD                    33 
#define MPXS30_PADSEL_FLEXCAN1_RXD                    34 
#define MPXS30_PADSEL_ETIMER0_ETC_0                   35 
#define MPXS30_PADSEL_ETIMER0_ETC_1                   36 
#define MPXS30_PADSEL_ETIMER0_ETC_2                   37 
#define MPXS30_PADSEL_ETIMER0_ETC_3                   38 
#define MPXS30_PADSEL_ETIMER2_ETC_0                   39 
#define MPXS30_PADSEL_ETIMER2_ETC_1                   40 
#define MPXS30_PADSEL_ETIMER2_ETC_2                   41 
#define MPXS30_PADSEL_ETIMER2_ETC_3                   42 
#define MPXS30_PADSEL_FLEXCAN2_RXD                    43 
#define MPXS30_PADSEL_FLEXCAN3_RXD                    44 
#define MPXS30_PADSEL_I2C1_SCL                        45 
#define MPXS30_PADSEL_I2C1_SDA                        46 
#define MPXS30_PADSEL_I2C2_SCL                        47 
#define MPXS30_PADSEL_I2C2_SDA                        48 
#define MPXS30_PADSEL_LINFLEX2_RXD                    49 
#define MPXS30_PADSEL_LINFLEX3_RXD                    50 
#define MPXS30_PADSEL_ETIMER2_ETC_4                   51 
#define MPXS30_PADSEL_ETIMER2_ETC_5                   52 
#define MPXS30_PADSEL_FLEXPWM1_A_0                    53 
#define MPXS30_PADSEL_FLEXPWM1_A_1                    54 
#define MPXS30_PADSEL_FLEXPWM1_A_2                    55 
#define MPXS30_PADSEL_FLEXPWM1_B_0                    56 
#define MPXS30_PADSEL_FLEXPWM1_B_1                    57 
#define MPXS30_PADSEL_FLEXPWM1_B_2                    58 
#define MPXS30_PADSEL_CTU1_EXT_IN                     59 
#define MPXS30_PADSEL_FLEXPWM0_X_0                    60 


#endif
