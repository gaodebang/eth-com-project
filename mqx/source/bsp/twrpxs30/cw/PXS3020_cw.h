/**************************************************************************
 * FILE NAME: PXS30.h                      COPYRIGHT (c) Freescale 2011   * 
 * REVISION:  1.0                                     All Rights Reserved *
 *                                                                        *
 * DESCRIPTION:                                                           *
 * This file contain all of the register and bit field definitions for    *
 * PXS30xx.                                                               *
 **************************************************************************/
/*>>>>NOTE! this file is auto-generated please do not edit it!<<<<*/

/**************************************************************************
 * Example register & bit field write:                                    *
 *                                                                        *
 *  <MODULE>.<REGISTER>.B.<BIT> = 1;                                      *
 *  <MODULE>.<REGISTER>.R       = 0x10000000;                             *
 *                                                                        *
 **************************************************************************/


#ifndef _PXS3020_H_
#define _PXS3020_H_

#include "typedefs.h"

#define CALL_USR_INIT 1

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef __MWERKS__
#pragma push
#pragma ANSI_strict off
#endif
/****************************************************************************/
/*                          MODULE : ADC                                   */
/****************************************************************************/
struct ADC_tag {
    union {
	vuint32_t R;
	struct {
	    vuint32_t OWREN:1;
	    vuint32_t WLSIDE:1;
	    vuint32_t MODE:1;
	    vuint32_t EDGLEV:1;
	    vuint32_t TRGEN:1;
	    vuint32_t EDGE:1;
	    vuint32_t XSTRTEN:1;
	    vuint32_t NSTART:1;
	    vuint32_t:1;
	    vuint32_t JTRGEN:1;
	    vuint32_t JEDGE:1;
	    vuint32_t JSTART:1;
	    vuint32_t:2;
	    vuint32_t CTUEN:1;
	    vuint32_t:8;
	    vuint32_t ADCLKSEL:1;
	    vuint32_t ABORTCHAIN:1;
	    vuint32_t ABORT:1;
	    vuint32_t ACK0:1;
	    vuint32_t OFFREFRESH:1;
	    vuint32_t OFFCANC:1;
	    vuint32_t:2;
	    vuint32_t PWDN:1;
	} B;
    } MCR; /* MAIN CONFIGURATION REGISTER */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:7;
	    vuint32_t NSTART:1;
	    vuint32_t JABORT:1;
	    vuint32_t:2;
	    vuint32_t JSTART:1;
	    vuint32_t:3;
	    vuint32_t CTUSTART:1;
	    vuint32_t CHADDR:7;
	    vuint32_t:3;
	    vuint32_t ACK0:1;
	    vuint32_t OFFREFRESH:1;
	    vuint32_t OFFCANC:1;
	    vuint32_t ADCSTATUS:3;
	} B;
    } MSR; /* MAIN STATUS REGISTER */
    int32_t ADC_reserved1[2]; /* (0x008 - 0x00F)/4 = 0x02 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:25;
	    vuint32_t OFFCANCOVR:1;
	    vuint32_t EOFFSET:1;
	    vuint32_t EOCTU:1;
	    vuint32_t JEOC:1;
	    vuint32_t JECH:1;
	    vuint32_t EOC:1;
	    vuint32_t ECH:1;
	} B;
    } ISR; /* INTERRUPT STATUS REGISTER */
    union {
	vuint32_t R;
	struct {
	    vuint32_t EOC31:1;
	    vuint32_t EOC30:1;
	    vuint32_t EOC29:1;
	    vuint32_t EOC28:1;
	    vuint32_t EOC27:1;
	    vuint32_t EOC26:1;
	    vuint32_t EOC25:1;
	    vuint32_t EOC24:1;
	    vuint32_t EOC23:1;
	    vuint32_t EOC22:1;
	    vuint32_t EOC21:1;
	    vuint32_t EOC20:1;
	    vuint32_t EOC19:1;
	    vuint32_t EOC18:1;
	    vuint32_t EOC17:1;
	    vuint32_t EOC16:1;
	    vuint32_t EOC15:1;
	    vuint32_t EOC14:1;
	    vuint32_t EOC13:1;
	    vuint32_t EOC12:1;
	    vuint32_t EOC11:1;
	    vuint32_t EOC10:1;
	    vuint32_t EOC9:1;
	    vuint32_t EOC8:1;
	    vuint32_t EOC7:1;
	    vuint32_t EOC6:1;
	    vuint32_t EOC5:1;
	    vuint32_t EOC4:1;
	    vuint32_t EOC3:1;
	    vuint32_t EOC2:1;
	    vuint32_t EOC1:1;
	    vuint32_t EOC0:1;
	} B;
    } CEOCFR0; /* Channel Pending Register 0 */
    int32_t ADC_reserved2[2]; /* (0x018 - 0x01F)/4 = 0x02 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:25; //One bit added
	    vuint32_t MSKOFFCANCOVR:1; //Moved up
	    vuint32_t MSKEOFFSET:1; //Moved up
	    vuint32_t MSKEOCTU:1; //New for cut 2
	    vuint32_t MSKJEOC:1;
	    vuint32_t MSKJECH:1;
	    vuint32_t MSKEOC:1;
	    vuint32_t MSKECH:1;
	} B;
    } IMR; /* INTERRUPT MASK REGISTER */
    union {
	vuint32_t R;
	struct {
	    vuint32_t CIM31:1;
	    vuint32_t CIM30:1;
	    vuint32_t CIM29:1;
	    vuint32_t CIM28:1;
	    vuint32_t CIM27:1;
	    vuint32_t CIM26:1;
	    vuint32_t CIM25:1;
	    vuint32_t CIM24:1;
	    vuint32_t CIM23:1;
	    vuint32_t CIM22:1;
	    vuint32_t CIM21:1;
	    vuint32_t CIM20:1;
	    vuint32_t CIM19:1;
	    vuint32_t CIM18:1;
	    vuint32_t CIM17:1;
	    vuint32_t CIM16:1;
	    vuint32_t CIM15:1;
	    vuint32_t CIM14:1;
	    vuint32_t CIM13:1;
	    vuint32_t CIM12:1;
	    vuint32_t CIM11:1;
	    vuint32_t CIM10:1;
	    vuint32_t CIM9:1;
	    vuint32_t CIM8:1;
	    vuint32_t CIM7:1;
	    vuint32_t CIM6:1;
	    vuint32_t CIM5:1;
	    vuint32_t CIM4:1;
	    vuint32_t CIM3:1;
	    vuint32_t CIM2:1;
	    vuint32_t CIM1:1;
	    vuint32_t CIM0:1;
	} B;
    } CIMR0; /* Channel Interrupt Mask Register 0 */
    int32_t ADC_reserved3[2]; /* (0x028 - 0x02F)/4 = 0x02 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t WDG3H:1;
	    vuint32_t WDG2H:1;
	    vuint32_t WDG1H:1;
	    vuint32_t WDG0H:1;
	    vuint32_t WDG3L:1;
	    vuint32_t WDG2L:1;
	    vuint32_t WDG1L:1;
	    vuint32_t WDG0L:1;
	} B;
    } WTISR; /* WATCHDOG INTERRUPT THRESHOLD REGISTER was WDGTHR */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t MSKWDG3H:1;
	    vuint32_t MSKWDG2H:1;
	    vuint32_t MSKWDG1H:1;
	    vuint32_t MSKWDG0H:1;
	    vuint32_t MSKWDG3L:1;
	    vuint32_t MSKWDG2L:1;
	    vuint32_t MSKWDG1L:1;
	    vuint32_t MSKWDG0L:1;
	} B;
    } WTIMR; /* WATCHDOG INTERRUPT MASK REGISTER was IMWDGTHR */
    int32_t ADC_reserved4[2]; /* (0x038 - 0x03F)/4 = 0x02 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:30; //was 16
	    vuint32_t DCLR:1; //moved
	    vuint32_t DMAEN:1; //moved
	} B;
    } DMAE; /* DMAE REGISTER */
    union {
	vuint32_t R;
	struct {
	    vuint32_t DMA31:1; //was unused [16]
	    vuint32_t DMA30:1;
	    vuint32_t DMA29:1;
	    vuint32_t DMA28:1;
	    vuint32_t DMA27:1;
	    vuint32_t DMA26:1;
	    vuint32_t DMA25:1;
	    vuint32_t DMA24:1;
	    vuint32_t DMA23:1;
	    vuint32_t DMA22:1;
	    vuint32_t DMA21:1;
	    vuint32_t DMA20:1;
	    vuint32_t DMA19:1;
	    vuint32_t DMA18:1;
	    vuint32_t DMA17:1;
	    vuint32_t DMA16:1;
	    vuint32_t DMA15:1;
	    vuint32_t DMA14:1;
	    vuint32_t DMA13:1;
	    vuint32_t DMA12:1;
	    vuint32_t DMA11:1;
	    vuint32_t DMA10:1;
	    vuint32_t DMA9:1;
	    vuint32_t DMA8:1;
	    vuint32_t DMA7:1;
	    vuint32_t DMA6:1;
	    vuint32_t DMA5:1;
	    vuint32_t DMA4:1;
	    vuint32_t DMA3:1;
	    vuint32_t DMA2:1;
	    vuint32_t DMA1:1;
	    vuint32_t DMA0:1;
	} B;
    } DMAR0; /* DMA REGISTER  was [6] */
    int32_t ADC_reserved5[6]; /* (0x0060 - 0x0048)/4 = 0x02 */
    union {
	vuint32_t R;
	struct { //were in TRA & TRB
	    vuint32_t:4;
	    vuint32_t THRH:12;
	    vuint32_t:4;
	    vuint32_t THRL:12;
	} B;
    } THRHLR[4]; /* THRESHOLD REGISTER */
    int32_t ADC_reserved6[4]; /* (0x0080 - 0x0070)/4 = 0x02 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:25; //was 26
	    vuint32_t PREVAL2:2;
	    vuint32_t PREVAL1:2;
	    vuint32_t PREVAL0:2;
	    vuint32_t PREONCE:1;
	} B;
    } PSCR; /* PRESAMPLING CONTROL REGISTER was PREREG */
    union {
	vuint32_t R;
	struct {
	    vuint32_t PRES31:1; //was reserved 16
	    vuint32_t PRES30:1;
	    vuint32_t PRES29:1;
	    vuint32_t PRES28:1;
	    vuint32_t PRES27:1;
	    vuint32_t PRES26:1;
	    vuint32_t PRES25:1;
	    vuint32_t PRES24:1;
	    vuint32_t PRES23:1;
	    vuint32_t PRES22:1;
	    vuint32_t PRES21:1;
	    vuint32_t PRES20:1;
	    vuint32_t PRES19:1;
	    vuint32_t PRES18:1;
	    vuint32_t PRES17:1;
	    vuint32_t PRES16:1;
	    vuint32_t PRES15:1;
	    vuint32_t PRES14:1;
	    vuint32_t PRES13:1;
	    vuint32_t PRES12:1;
	    vuint32_t PRES11:1;
	    vuint32_t PRES10:1;
	    vuint32_t PRES9:1;
	    vuint32_t PRES8:1;
	    vuint32_t PRES7:1;
	    vuint32_t PRES6:1;
	    vuint32_t PRES5:1;
	    vuint32_t PRES4:1;
	    vuint32_t PRES3:1;
	    vuint32_t PRES2:1;
	    vuint32_t PRES1:1;
	    vuint32_t PRES0:1;
	} B;
    } PSR0; /* PRESAMPLING REGISTER was PRER[6]*/
    int32_t ADC_reserved7[3]; /* (0x088 - 0x093)/4 = 0x03 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t INPLATCH:1;
	    vuint32_t:1;
	    vuint32_t OFFSHIFT:2; //!!! This field only in CTR[0]
	    vuint32_t:1;
	    vuint32_t INPCMP:2;
	    vuint32_t:1;
	    vuint32_t INPSAMP:8;
	} B;
    } CTR[2]; /* CONVERSION TIMING REGISTER was CT[2] */
    int32_t ADC_reserved8[2]; /* (0x0A4 - 0x09A)/4 = 0x01 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t CH31:1; //was reserved 16
	    vuint32_t CH30:1;
	    vuint32_t CH29:1;
	    vuint32_t CH28:1;
	    vuint32_t CH27:1;
	    vuint32_t CH26:1;
	    vuint32_t CH25:1;
	    vuint32_t CH24:1;
	    vuint32_t CH23:1;
	    vuint32_t CH22:1;
	    vuint32_t CH21:1;
	    vuint32_t CH20:1;
	    vuint32_t CH19:1;
	    vuint32_t CH18:1;
	    vuint32_t CH17:1;
	    vuint32_t CH16:1;
	    vuint32_t CH15:1;
	    vuint32_t CH14:1;
	    vuint32_t CH13:1;
	    vuint32_t CH12:1;
	    vuint32_t CH11:1;
	    vuint32_t CH10:1;
	    vuint32_t CH9:1;
	    vuint32_t CH8:1;
	    vuint32_t CH7:1;
	    vuint32_t CH6:1;
	    vuint32_t CH5:1;
	    vuint32_t CH4:1;
	    vuint32_t CH3:1;
	    vuint32_t CH2:1;
	    vuint32_t CH1:1;
	    vuint32_t CH0:1;
	} B;
    } NCMR0; /* NORMAL CONVERSION MASK REGISTER was [6] */
    int32_t ADC_reserved9[3]; /* (0x0B0 - 0x0A8)/4 = 0x02 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t CH31:1; //was reserved 16
	    vuint32_t CH30:1;
	    vuint32_t CH29:1;
	    vuint32_t CH28:1;
	    vuint32_t CH27:1;
	    vuint32_t CH26:1;
	    vuint32_t CH25:1;
	    vuint32_t CH24:1;
	    vuint32_t CH23:1;
	    vuint32_t CH22:1;
	    vuint32_t CH21:1;
	    vuint32_t CH20:1;
	    vuint32_t CH19:1;
	    vuint32_t CH18:1;
	    vuint32_t CH17:1;
	    vuint32_t CH16:1;
	    vuint32_t CH15:1;
	    vuint32_t CH14:1;
	    vuint32_t CH13:1;
	    vuint32_t CH12:1;
	    vuint32_t CH11:1;
	    vuint32_t CH10:1;
	    vuint32_t CH9:1;
	    vuint32_t CH8:1;
	    vuint32_t CH7:1;
	    vuint32_t CH6:1;
	    vuint32_t CH5:1;
	    vuint32_t CH4:1;
	    vuint32_t CH3:1;
	    vuint32_t CH2:1;
	    vuint32_t CH1:1;
	    vuint32_t CH0:1;
	} B;
    } JCMR0; /* Injected CONVERSION MASK REGISTER was ICMR[6] */
    int32_t ADC_reserved10[4]; /* (0x0B8 - 0x0C8)/4 = 0x04 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t PDED:8; //was PDD
	} B;
    } PDEDR; /* POWER DOWN DELAY REGISTER was PDD */
    int32_t ADC_reserved11[13]; /* (0x100 - 0x0CC)/4 = 0x013 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t VALID:1;
	    vuint32_t OVERW:1;
	    vuint32_t RESULT:2;
	    vuint32_t:4;
	    vuint32_t CDATA:12;
	} B;
    } CDR[15]; /* Channel 0-55 Data REGISTER */
    int32_t ADC_reserved12[80]; /* (0x027F - 0x140)/4 = 0x03 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t THRH:12;
	    vuint32_t:4;
	    vuint32_t THRL:12;
	} B;
    } THRHLR_1[12]; /* THRESHOLD REGISTER 4 - 15 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t WSEL_CH0:4;
	    vuint32_t WSEL_CH1:4;
	    vuint32_t WSEL_CH2:4;
	    vuint32_t WSEL_CH3:4;
	    vuint32_t WSEL_CH4:4;
	    vuint32_t WSEL_CH5:4;
	    vuint32_t WSEL_CH6:4;
	    vuint32_t WSEL_CH7:4;
	} B;
    } CWSEL0; /* CHANNEL WATCHDOG SELECTION REGISTER 0 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t WSEL_CH8:4;
	    vuint32_t WSEL_CH9:4;
	    vuint32_t WSEL_CH10:4;
	    vuint32_t WSEL_CH11:4;
	    vuint32_t WSEL_CH12:4;
	    vuint32_t WSEL_CH13:4;
	    vuint32_t WSEL_CH14:4;
	    vuint32_t WSEL_CH15:4;
	} B;
    } CWSEL1; /* CHANNEL WATCHDOG SELECTION REGISTER 1 */
    int32_t ADC_reserved13[11]; /* (0x02E0 - 0x2B4)/4 = 0x09 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :16;
	    vuint32_t CWEN0:1;
	    vuint32_t CWEN1:1;
	    vuint32_t CWEN2:1;
	    vuint32_t CWEN3:1;
	    vuint32_t CWEN4:1;
	    vuint32_t CWEN5:1;
	    vuint32_t CWEN6:1;
	    vuint32_t CWEN7:1;
	    vuint32_t CWEN8:1;
	    vuint32_t CWEN9:1;
	    vuint32_t CWEN10:1;
	    vuint32_t CWEN11:1;
	    vuint32_t CWEN12:1;
	    vuint32_t CWEN13:1;
	    vuint32_t CWEN14:1;
	    vuint32_t CWEN15:1;
	} B;
    } CWENR0; /* CHANNEL WATCHDOG ENABLE REGISTER 0 */

    int32_t ADC_reserved14[3]; /* (0x02E4 - 0x2EF)/4 = 0x03 */

    union {
	vuint32_t R;
	struct {
	    vuint32_t AWORCH:32;
	} B;
    } AWORRA; /* ANALOG WATCHDOG OUT OF RANGE REGISTER 0	 */

    int32_t ADC_reserved15[19]; /* (0x033F - 0x2F4)/4 = 0x19 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t INPSAMP_C:8;
	    vuint32_t INPSAMP_RC:8;
	    vuint32_t INPSAMP_S:8;
	    vuint32_t :5;
	    vuint32_t ST_INPCMP:2;
	    vuint32_t ST_INPLATCH:1;
	} B;
    } STCR1; /* SELF TEST CONFIGURATION REGISTER 1	 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :4;
	    vuint32_t MSKWDSERR:1;
	    vuint32_t SERR:1;
	    vuint32_t MSKWDTERR:1;
	    vuint32_t :1;
	    vuint32_t MSKST_EOC:1;
	    vuint32_t :4;
	    vuint32_t MSKWDG_EOA_C:1;
	    vuint32_t MSKWDG_EOA_RC:1;
	    vuint32_t MSKWDG_EOA_S:1;
	    vuint32_t MSKERR_C:1;
	    vuint32_t MSKERR_RC:1;
	    vuint32_t MSKERR_S2:1;
	    vuint32_t MSKERR_S1:1;
	    vuint32_t MSKERR_S0:1;
	    vuint32_t :3;
	    vuint32_t EN:1;
	    vuint32_t :2;
	    vuint32_t FMA_WDSERR:1;
	    vuint32_t FMA_WDTERR:1;
	    vuint32_t FMA_C:1;
	    vuint32_t FMA_RC:1;
	    vuint32_t FMA_S:1;
	} B;
    } STCR2; /* SELF TEST CONFIGURATION REGISTER 2	 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :22;
	    vuint32_t ALG:2;
	    vuint32_t :3;
	    vuint32_t MSTEP:5;
	} B;
    } STCR3; /* SELF TEST CONFIGURATION REGISTER 3	 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :13;
	    vuint32_t WDT:3;
	    vuint32_t :8;
	    vuint32_t BR:8;
	} B;
    } STBRR; /* SELF TEST BAUD RATE REGISTER 	 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :4;
	    vuint32_t WDSERR:1;
	    vuint32_t :1;
	    vuint32_t WDTERR:1;
	    vuint32_t OVERWR:1;
	    vuint32_t ST_EOC:1;
	    vuint32_t :4;
	    vuint32_t WDG_EOA_C:1;
	    vuint32_t WDG_EOA_RC:1;
	    vuint32_t WDG_EOA_S:1;
	    vuint32_t ERR_C:1;
	    vuint32_t ERR_RC:1;
	    vuint32_t ERR_S2:1;
	    vuint32_t ERR_S1:1;
	    vuint32_t ERR_S0:1;
	    vuint32_t :1;
	    vuint32_t STEP_C:5;
	    vuint32_t STEP_RC:5;
	} B;
    } STSR1; /* SELF TEST STATUS RATE REGISTER 1	 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t OVFL:1;
	    vuint32_t :3;
	    vuint32_t DATA1:12;
	    vuint32_t :4;
	    vuint32_t DATA0:12;
	} B;
    } STSR2; /* SELF TEST STATUS RATE REGISTER 2	 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :4;
	    vuint32_t DATA1:12;
	    vuint32_t :4;
	    vuint32_t DATA0:12;
	} B;
    } STSR3; /* SELF TEST STATUS RATE REGISTER 3	 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :4;
	    vuint32_t DATA1:12;
	    vuint32_t :4;
	    vuint32_t DATA0:12;
	} B;
    } STSR4; /* SELF TEST STATUS RATE REGISTER 4	 */
    int32_t ADC_reserved16[4]; /* (0x036F - 0x360)/4 = 0x03 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :12;
	    vuint32_t VALID:1;
	    vuint32_t OVERWR:1;
	    vuint32_t :6;
	    vuint32_t TCDATA:12;
	} B;
    } STDR1; /* SELF TEST DATA REGISTER 1	 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t FDATA:12;
	    vuint32_t VALID:1;
	    vuint32_t OVERWR:1;
	    vuint32_t :6;
	    vuint32_t IDATA:12;
	} B;
    } STDR2; /* SELF TEST DATA REGISTER 2	 */
    int32_t ADC_reserved17[2]; /* (0x037F - 0x378)/4 = 0x02 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t AWDE:1;
	    vuint32_t WDTE:1;
	    vuint32_t:2;
	    vuint32_t THRH:12;
	    vuint32_t:4;
	    vuint32_t THRL:12;
	} B;
    } STAW0R; /* SELF TEST ANALOG WATCHDOG REGISTER 0 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t AWDE:1;
	    vuint32_t:3;
	    vuint32_t THRH:12;
	    vuint32_t:4;
	    vuint32_t THRL:12;
	} B;
    } STAW1AR; /* SELF TEST ANALOG WATCHDOG REGISTER 1A */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t THRH:12;
	    vuint32_t:4;
	    vuint32_t THRL:12;
	} B;
    } STAW1BR; /* SELF TEST ANALOG WATCHDOG REGISTER 1B */
    union {
	vuint32_t R;
	struct {
	    vuint32_t AWDE:1;
	    vuint32_t:19;
	    vuint32_t THRL:12;
	} B;
    } STAW2R; /* SELF TEST ANALOG WATCHDOG REGISTER 2 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t AWDE:1;
	    vuint32_t WDTDE:1;
	    vuint32_t:2;
	    vuint32_t THRH:12;
	    vuint32_t:4;
	    vuint32_t THRL:12;
	} B;
    } STAW3R; /* SELF TEST ANALOG WATCHDOG REGISTER 3 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t AWDE:1;
	    vuint32_t WDTDE:1;
	    vuint32_t:2;
	    vuint32_t THRH:12;
	    vuint32_t:4;
	    vuint32_t THRL:12;
	} B;
    } STAW4R; /* SELF TEST ANALOG WATCHDOG REGISTER 4 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t THRH:12;
	    vuint32_t:4;
	    vuint32_t THRL:12;
	} B;
    } STAW5R; /* SELF TEST ANALOG WATCHDOG REGISTER 5 */
}; /* end of ADC_tag */
/****************************************************************************/
/*                     MODULE : CFLASH                                       */
/****************************************************************************/
struct CFLASH_tag {
    union { /* Module Configuration (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t EDC:1;
            vuint32_t :4;
            vuint32_t SIZE:3;
            vuint32_t :1;
            vuint32_t LAS:3;
            vuint32_t :3;
            vuint32_t MAS:1;
            vuint32_t EER:1;
            vuint32_t RWE:1;
            vuint32_t :2;
            vuint32_t PEAS:1;
            vuint32_t DONE:1;
            vuint32_t PEG:1;
            vuint32_t :4;
            vuint32_t PGM:1;
            vuint32_t PSUS:1;
            vuint32_t ERS:1;
            vuint32_t ESUS:1;
            vuint32_t EHV:1;
        } B;
    } MCR;
    union { /* Low/Mid address block locking (Base+0x0004) */
        vuint32_t R;
        struct {
            vuint32_t LME:1;
            vuint32_t :10;
            vuint32_t TSLK:1;
            vuint32_t :2;
	    vuint32_t MLK:2;
	    vuint32_t :8;
            vuint32_t LLK:8;
        } B;
    } LML;
    union { /* High address space block locking (Base+0x0008)*/
        vuint32_t R;
        struct {
            vuint32_t HBE:1;
            vuint32_t :27;
            vuint32_t HLK:4;
        } B;
    } HBL;
    union { /* Secondary Low/Mid block lock (Base+0x000C)*/
        vuint32_t R;
        struct {
            vuint32_t SLE:1;
            vuint32_t :10;
            vuint32_t STSLK:1;
            vuint32_t :2;
            vuint32_t SMK:2;
	    vuint32_t :8;
            vuint32_t SLK:8;
        } B;
    } SLL;
    union { /* Low/Mid address space block sel (Base+0x0010)*/
        vuint32_t R;
        struct {
            vuint32_t:14;
            vuint32_t MSL:2;
	    vuint32_t :8;
            vuint32_t LSL:8;
        } B;
    } LMS;
    union { /* High address Space block select (Base+0x0014)*/
        vuint32_t R;
        struct {
            vuint32_t :28;
            vuint32_t HSL:4;
        } B;
    } HBS;
    union { /* Address (Base+0x0018) */
        vuint32_t R;
        struct {
	    vuint32_t SAD:1;
	    vuint32_t TAD:1;
	    vuint32_t :9;
	    vuint32_t AD2:1;
            vuint32_t AD1:10;
	    vuint32_t AD9:1;
	    vuint32_t AD8:1;
	    vuint32_t AD7:1;
	    vuint32_t AD6:1;
	    vuint32_t AD5:1;
	    vuint32_t AD4:1;
	    vuint32_t AD3:1;
            vuint32_t :3;
        } B;
    } ADR;
    /* Note the following 3 registers, BIU[0..2] are mirrored to */
    /*  the code flash configuraiton PFCR[0..2] registers        */
    /* To make it easier to code, the BIU registers have been    */
    /*  replaced with the PFCR registers in this header file!    */
    /* A commented out BIU register is shown for reference!      */
    union { /* CFLASH Configuration 0 (Base+0x001C) */
        vuint32_t R;
        struct {
            vuint32_t B02_APC:5;
            vuint32_t B02_WWSC:5;
            vuint32_t B02_RWSC:5;
            vuint32_t B02_RWWC2:1;
            vuint32_t B02_RWWC1:1;
            vuint32_t B02_P1_BCFG:2;
            vuint32_t B02_P1_DPFE:1;
            vuint32_t B02_P1_IPFE:1;
            vuint32_t B02_P1_PFLM:2;
            vuint32_t B02_P1_BFE:1;
            vuint32_t B02_RWWC0:1;
            vuint32_t B02_P0_BCFG:2;
            vuint32_t B02_P0_DPFE:1;
            vuint32_t B02_P0_IPFE:1;
            vuint32_t B02_P0_PFLM:2;
            vuint32_t B02_P0_BFE:1;
        } B;
    } PFCR0;
    /* Commented out Bus Interface Unit 0 (Base+0x001C) */
    /*union {              

      vuint32_t R;

      struct {

      vuint32_t BI0:32;

      } B;

      } BIU0;  */
    union { /* CFLASH Configuration 1 (Base+0x0020) */
        vuint32_t R;
        struct {
            vuint32_t B1_APC:5;
            vuint32_t B1_WWSC:5;
            vuint32_t B1_RWSC:5;
            vuint32_t B1_RWWC2:1;
            vuint32_t B1_RWWC1:1;
            vuint32_t :6;
            vuint32_t B1_P1_BFE:1;
            vuint32_t B1_RWWC0:1;
            vuint32_t :6;
            vuint32_t B1_P0_BFE:1;
        } B;
    } PFCR1;
    /* Commented out Bus Interface Unit 1 (Base+0x0020) */
    /*union {                 

      vuint32_t R;

      struct {

      vuint32_t BI1:32;

      } B;

      } BIU1; */
    union { /* CFLASH Access Protection (Base+0x0024) */
        vuint32_t R;
        struct {
            vuint32_t :6;
            vuint32_t ARBM:2;
            vuint32_t M7PFD:1;
            vuint32_t M6PFD:1;
            vuint32_t M5PFD:1;
            vuint32_t M4PFD:1;
            vuint32_t M3PFD:1;
            vuint32_t M2PFD:1;
            vuint32_t M1PFD:1;
            vuint32_t M0PFD:1;
            vuint32_t M7AP:2;
            vuint32_t M6AP:2;
            vuint32_t M5AP:2;
            vuint32_t M4AP:2;
            vuint32_t M3AP:2;
            vuint32_t M2AP:2;
            vuint32_t M1AP:2;
            vuint32_t M0AP:2;
        } B;
    } PFAPR;
    /* Commented out Bus Interface Unit 2 (Base+0x0024) */
    /*union {                

      vuint32_t R;

      struct {

      vuint32_t BI2:32;

      } B;

      } BIU2; */
    vuint8_t CFLASH_reserved0[20]; /* Reserved 20 Bytes (Base+0x0028-0x003B) */
    union { /* User Test 0 (Base+0x003C) */
        vuint32_t R;
        struct {
            vuint32_t UTE:1;
            vuint32_t :7;
            vuint32_t DSI:8;
            vuint32_t :10;
            vuint32_t MRE:1;
            vuint32_t MRV:1;
            vuint32_t EIE:1;
            vuint32_t AIS:1;
            vuint32_t AIE:1;
            vuint32_t AID:1;
        } B;
    } UT0;
    union { /* User Test 1 (Base+0x0040) */
        vuint32_t R;
        struct {
            vuint32_t DAI:32;
        } B;
    } UT1;
    union { /* User Test 2 (Base+0x0044) */
        vuint32_t R;
        struct {
            vuint32_t DAI:32;
        } B;
    } UT2;
    union { /* User Multiple Input Sig 0..4 (Base+0x0048-0x005B) */
        vuint32_t R;
        struct {
            vuint32_t MS:32;
        } B;
    } UMISR[5];
    vuint8_t CFLASH_reserved1[16292]; /* Reserved 16292 (Base+0x005C-0x3FFF)*/
}; /* end of CFLASH_tag */
/****************************************************************************/
/*                          MODULE : CGM                                   */
/****************************************************************************/
struct CGM_tag {
    /* The CGM provides a unified register interface, enabling access to 

       all clock sources:



       Clock Type | Starting Address Map | Associated Clock Sources

       ------------------------------------------------------------

       System     | C3FE0000             | OSC_CTL

       "          | C3FE00A0             | FMPLL_0

       "          | C3FE00C0             | FMPLL_1

       "          | -                    | Reserved

       MISC       | C3FE0100             | CMU_0

       MISC       | C3FE0120             | CMU_1

       MISC       | C3FE0140             | CMU_2

       MISC       | C3FE0160             | EBI Output Divider

       MISC       | C3FE0370             | CGM General



       */
    /************************************/
    /* OSC_CTL @ CGM base address + 0x0000 */
    /************************************/
    union {
	vuint32_t R;
	struct {
	    vuint32_t OSCBYP:1;
	    vuint32_t:7;
	    vuint32_t EOCV:8;
	    vuint32_t M_OSC:1;
	    vuint32_t:2;
	    vuint32_t OSCDIV:5;
	    vuint32_t I_OSC:1;
	    vuint32_t:5;
	    vuint32_t :1;
	    vuint32_t :1;
	} B;
    } OSC_CTL; /* Main OSC Control Register */
    int32_t CGM_reserved0[23]; /* (0x004 - 0x05F)/4 = 0x23 */
    /************************************/
    /* RC_CTL @ CGM base address + 0x0060 */
    /************************************/
    union {
	vuint32_t R;
	struct {
	    vuint32_t:10;
	    vuint32_t RCTRIM:6;
	    vuint32_t:3;
	    vuint32_t :5;
	    vuint32_t:2;
	    vuint32_t :1;
	    vuint32_t:5;
	} B;
    } RC_CTL; /* RC OSC Control Register */
    int32_t CGM_reserved1[15]; /* (0x064 - 0x00A0)/4 = 0x15 */
    /************************************/
    /* FMPLL_0 @ CGM base address + 0x00A0 */
    /* FMPLL_1 @ CGM base address + 0x00C0 */
    /************************************/
    struct {
	union {
	    vuint32_t R;
	    struct {
		vuint32_t:2;
		vuint32_t IDF:4;
		vuint32_t ODF:2;
		vuint32_t:1;
		vuint32_t NDIV:7;
		vuint32_t:7;
		vuint32_t EN_PLL_SW:1;
		vuint32_t :1;
		vuint32_t UNLOCK_ONCE:1;
		vuint32_t:1;
		vuint32_t I_LOCK:1;
		vuint32_t S_LOCK:1;
		vuint32_t PLL_FAIL_MASK:1;
		vuint32_t PLL_FAIL_FLAG:1;
		vuint32_t:1;
	    } B;
	} CR; /* FMPLL Control Register */
	union {
	    vuint32_t R;
	    struct {
		vuint32_t STRB_BYPASS:1;
		vuint32_t:1;
		vuint32_t SPRD_SEL:1;
		vuint32_t MOD_PERIOD:13;
		vuint32_t FM_EN:1;
		vuint32_t INC_STEP:15;
	    } B;
	} MR; /* FMPLL Modulation Register */
      int32_t CGM_reserved4[6];   /* (0x0C0 - 0x0A8)/4 = 0x06 */
    } FMPLL[1];
//     int32_t CGM_reserved3[4]; /* (0x0B0 - 0x0C0)/4 = 0x4 */
    /************************************/
    /* CMU @ CGM base address + 0x0100  */
    /************************************/
    int32_t CGM_reserved4[16]; /* (0x0D0 - 0x100)/4 = 0x16 */
/* CMU_0 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t SFM:1;
	    vuint32_t:13;
	    vuint32_t CLKSEL1:2;
	    vuint32_t:5;
	    vuint32_t RCDIV:2;
	    vuint32_t CME_A:1;
	} B;
    } CMU_0_CSR; /* Control Status Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t FD:20;
	} B;
    } CMU_0_FDR; /* Frequency Display Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:20;
	    vuint32_t HFREF_A:12;
	} B;
    } CMU_0_HFREFR_A; /* High Frequency Reference Register PLL_A Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:20;
	    vuint32_t LFREF_A:12;
	} B;
    } CMU_0_LFREFR_A; /* Low Frequency Reference Register PLL_A Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t FLCI_A:1;
	    vuint32_t FHHI_A:1;
	    vuint32_t FLLI_A:1;
	    vuint32_t OLRI:1;
	} B;
    } CMU_0_ISR; /* Interrupt Status Register */
    vuint8_t CGM_reserved5[4]; /* Reserved 4 bytes (Base+0x0014) */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t MD:20;
	} B;
    } CMU_0_MDR; /* Measurement Duration Register */
    vuint8_t CGM_reserved6[4]; /* Reserved 12 bytes (Base+0x001C - 0x001F) */
/* CMU_1 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t SFM:1;
	    vuint32_t:13;
	    vuint32_t CLKSEL1:2;
	    vuint32_t:5;
	    vuint32_t RCDIV:2;
	    vuint32_t CME_A:1;
	} B;
    } CMU_1_CSR; /* Control Status Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t FD:20;
	} B;
    } CMU_1_FDR; /* Frequency Display Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:20;
	    vuint32_t HFREF_A:12;
	} B;
    } CMU_1_HFREFR_A; /* High Frequency Reference Register PLL_A Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:20;
	    vuint32_t LFREF_A:12;
	} B;
    } CMU_1_LFREFR_A; /* Low Frequency Reference Register PLL_A Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t FLCI_A:1;
	    vuint32_t FHHI_A:1;
	    vuint32_t FLLI_A:1;
	    vuint32_t OLRI:1;
	} B;
    } CMU_1_ISR; /* Interrupt Status Register */
    vuint8_t CGM_reserved7[4]; /* Reserved 4 bytes (Base+0x0014) */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t MD:20;
	} B;
    } CMU_1_MDR; /* Measurement Duration Register */
    vuint8_t CGM_reserved8[4]; /* Reserved 12 bytes (Base+0x001C - 0x001F) */
/* CMU_2 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t SFM:1;
	    vuint32_t:13;
	    vuint32_t CLKSEL1:2;
	    vuint32_t:5;
	    vuint32_t RCDIV:2;
	    vuint32_t CME_A:1;
	} B;
    } CMU_2_CSR; /* Control Status Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t FD:20;
	} B;
    } CMU_2_FDR; /* Frequency Display Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:20;
	    vuint32_t HFREF_A:12;
	} B;
    } CMU_2_HFREFR_A; /* High Frequency Reference Register PLL_A Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:20;
	    vuint32_t LFREF_A:12;
	} B;
    } CMU_2_LFREFR_A; /* Low Frequency Reference Register PLL_A Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t FLCI_A:1;
	    vuint32_t FHHI_A:1;
	    vuint32_t FLLI_A:1;
	    vuint32_t OLRI:1;
	} B;
    } CMU_2_ISR; /* Interrupt Status Register */
    vuint8_t CGM_reserved9[4]; /* Reserved 4 bytes (Base+0x0014) */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t MD:20;
	} B;
    } CMU_2_MDR; /* Measurement Duration Register */
    vuint8_t CGM_reserved10[532]; /* Reserved 12 bytes (Base+0x001C - 0x001F) */
/*	  EBI Output Divider Missing C3FE_0160 to C3FE_0170 */
    /************************************/
    /* CGM General Registers @ CGM base address + 0x0370 */
    /************************************/
    union {
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t EN:1;
	} B;
    } OC_EN; /* Output Clock Enable Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:2;
	    vuint32_t SELDIV:2;
	    vuint32_t SELCTL:4;
	    vuint32_t:24;
	} B;
    } OCDS_SC; /* Output Clock Division Select Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t SELSTAT:4;
	    vuint32_t:24;
	} B;
    } SC_SS; /* System Clock Select Status */
    union {
	vuint32_t R;
	struct {
	    vuint32_t DE0:1;
	    vuint32_t:3;
	    vuint32_t DIV0:4;
	    vuint32_t DE1:1;
	    vuint32_t:3;
	    vuint32_t DIV1:4;
	    vuint32_t DE2:1;
	    vuint32_t:3;
	    vuint32_t DIV2:4;
	    vuint32_t DE3:1;
	    vuint32_t:3;
	    vuint32_t DIV3:4;
	} B;
    } SC_DC0; /* GSystem Clock Divider Configuration 0->4 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t SELCTL:4;
	    vuint32_t:24;
	} B;
    } AC0_SC; /* Aux Clock 0 Select Control */
    union {
	vuint32_t R;
	struct {
	    vuint32_t DE0:1;
	    vuint32_t:3;
	    vuint32_t DIV0:4;
	    vuint32_t DE1:1;
	    vuint32_t:3;
	    vuint32_t DIV1:4;
	    vuint32_t DE2:1;
	    vuint32_t:3;
	    vuint32_t DIV2:4;
	    vuint32_t DE3:1;
	    vuint32_t:3;
	    vuint32_t DIV3:4;
	} B;
    } AC0_DC0; /* Aux Clock 0 Divider Configuration 0->3 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t SELCTL:4;
	    vuint32_t:24;
	} B;
    } AC1_SC; /* Aux Clock 1 Select Control */
    union {
	vuint32_t R;
	struct {
	    vuint32_t DE0:1;
	    vuint32_t:3;
	    vuint32_t DIV0:4;
	    vuint32_t DE1:1;
	    vuint32_t:3;
	    vuint32_t DIV1:4;
	    vuint32_t DE2:1;
	    vuint32_t:3;
	    vuint32_t DIV2:4;
	    vuint32_t DE3:1;
	    vuint32_t:3;
	    vuint32_t DIV3:4;
	} B;
    } AC1_DC0; /* Aux Clock 1 Divider Configuration 0->3 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t SELCTL:4;
	    vuint32_t:24;
	} B;
    } AC2_SC; /* Aux Clock 2 Select Control */
    union {
	vuint32_t R;
	struct {
	    vuint32_t DE0:1;
	    vuint32_t:3;
	    vuint32_t DIV0:4;
	    vuint32_t DE1:1;
	    vuint32_t:3;
	    vuint32_t DIV1:4;
	    vuint32_t DE2:1;
	    vuint32_t:3;
	    vuint32_t DIV2:4;
	    vuint32_t DE3:1;
	    vuint32_t:3;
	    vuint32_t DIV3:4;
	} B;
    } AC2_DC0; /* Aux Clock 2 Divider Configuration 0->3 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t SELCTL:4;
	    vuint32_t:24;
	} B;
    } AC3_SC; /* Aux Clock 3 Select Control */
    vuint8_t CGM_reserved11[4]; /* Reserved 4 bytes (Base+0x039C) */
    union {
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t SELCTL:4;
	    vuint32_t:24;
	} B;
    } AC4_SC; /* Aux Clock 4 Select Control */
}; /* end of CGM_tag */
/****************************************************************************/
/*                          MODULE : CRC                                    */
/****************************************************************************/
struct CRC_SUB_tag {
    union {
	vuint8_t B[4]; /* Data buffer in Bytes (8 bits) */
	vuint16_t H[2]; /* Data buffer in Half-words (16 bits) */
	vuint32_t W; /* Data buffer in words (32 bits) */
	struct {
	    vuint32_t INV:1;
	    vuint32_t SWAP:1;
	    vuint32_t POLYG:1;
	    vuint32_t:29;
	}BIT;
    } CRC_CFG; /* CRC Configuration Register */
    union {
	vuint8_t B[4]; /* Data buffer in Bytes (8 bits) */
	vuint16_t H[2]; /* Data buffer in Half-words (16 bits) */
	vuint32_t W; /* Data buffer in words (32 bits) */
    } CRC_INP; /* CRC Input Register */
    union {
	vuint8_t B[4]; /* Data buffer in Bytes (8 bits) */
	vuint16_t H[2]; /* Data buffer in Half-words (16 bits) */
	vuint32_t W; /* Data buffer in words (32 bits) */
    } CRC_CSTAT; /*CRC Current Status Register */
    union {
	vuint8_t B[4]; /* Data buffer in Bytes (8 bits) */
	vuint16_t H[2]; /* Data buffer in Half-words (16 bits) */
	vuint32_t W; /* Data buffer in words (32 bits) */
    } CRC_OUTP; /* CRC Output Register */
}; /* end of CRC_tag */
struct CRC_tag {
    struct CRC_SUB_tag CNTX[3];
}; /* end of CRC_tag */
/****************************************************************************/
/*                          MODULE : CTU                                   */
/****************************************************************************/
struct CTU_tag{
    union {
	vuint32_t R;
	struct {
	    vuint32_t I15_FE:1;
	    vuint32_t I15_RE:1;
	    vuint32_t I14_FE:1;
	    vuint32_t I14_RE:1;
	    vuint32_t I13_FE:1;
	    vuint32_t I13_RE:1;
	    vuint32_t I12_FE:1;
	    vuint32_t I12_RE:1;
	    vuint32_t I11_FE:1;
	    vuint32_t I11_RE:1;
	    vuint32_t I10_FE:1;
	    vuint32_t I10_RE:1;
	    vuint32_t I9_FE:1;
	    vuint32_t I9_RE:1;
	    vuint32_t I8_FE:1;
	    vuint32_t I8_RE:1;
	    vuint32_t I7_FE:1;
	    vuint32_t I7_RE:1;
	    vuint32_t I6_FE:1;
	    vuint32_t I6_RE:1;
	    vuint32_t I5_FE:1;
	    vuint32_t I5_RE:1;
	    vuint32_t I4_FE:1;
	    vuint32_t I4_RE:1;
	    vuint32_t I3_FE:1;
	    vuint32_t I3_RE:1;
	    vuint32_t I2_FE:1;
	    vuint32_t I2_RE:1;
	    vuint32_t I1_FE:1;
	    vuint32_t I1_RE:1;
	    vuint32_t I0_FE:1;
	    vuint32_t I0_RE:1;
	} B;
    } TGSISR; /* -Trigger Generator Subunit Input Selection Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :7;
	    vuint16_t ETTM:1;
	    vuint16_t PRES:2;
	    vuint16_t MRSSM:5;
	    vuint16_t TGSM:1;
	} B;
    } TGSCR; /* Trigger Generator Subunit Control Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t TCR:16;
	} B;
    } TCR[8]; /* Trigger 0->7 Compare Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t TGSCCR:16;
	} B;
    } TGSCCR; /* TGS Counter Compare Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t TGSCRR:16;
	} B;
    } TGSCRR; /* TGS Counter Reload Register */
    uint16_t CTU_reserved0[1];
    union {
	vuint32_t R;
	struct {
	    vuint32_t :3;
	    vuint32_t T3INDEX:5;
	    vuint32_t :3;
	    vuint32_t T2INDEX:5;
	    vuint32_t :3;
	    vuint32_t T1INDEX:5;
	    vuint32_t :3;
	    vuint32_t T0INDEX:5;
	} B;
    } CLCR1; /* Command List Control Register 1 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :3;
	    vuint32_t T7INDEX:5;
	    vuint32_t :3;
	    vuint32_t T6INDEX:5;
	    vuint32_t :3;
	    vuint32_t T5INDEX:5;
	    vuint32_t :3;
	    vuint32_t T4INDEX:5;
	} B;
    } CLCR2; /* Command List Control Register 2 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :3;
	    vuint32_t T3E:1;
	    vuint32_t T3ETE:1;
	    vuint32_t T3T2E:1;
	    vuint32_t T3T1E:1;
	    vuint32_t T3ADCE:1;
	    vuint32_t :3;
	    vuint32_t T2E:1;
	    vuint32_t T2ETE:1;
	    vuint32_t T2T2E:1;
	    vuint32_t T2T1E:1;
	    vuint32_t T2ADCE:1;
	    vuint32_t :3;
	    vuint32_t T1E:1;
	    vuint32_t T1ETE:1;
	    vuint32_t T1T2E:1;
	    vuint32_t T1T1E:1;
	    vuint32_t T1ADCE:1;
	    vuint32_t :3;
	    vuint32_t T0E:1;
	    vuint32_t T0ETE:1;
	    vuint32_t T0T2E:1;
	    vuint32_t T0T1E:1;
	    vuint32_t T0ADCE:1;
	} B;
    } THCR1; /* Trigger Handler Control Register 1 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :3;
	    vuint32_t T7E:1;
	    vuint32_t T7ETE:1;
	    vuint32_t T7T2E:1;
	    vuint32_t T7T1E:1;
	    vuint32_t T7ADCE:1;
	    vuint32_t :3;
	    vuint32_t T6E:1;
	    vuint32_t T6ETE:1;
	    vuint32_t T6T2E:1;
	    vuint32_t T6T1E:1;
	    vuint32_t T6ADCE:1;
	    vuint32_t :3;
	    vuint32_t T5E:1;
	    vuint32_t T5ETE:1;
	    vuint32_t T5T2E:1;
	    vuint32_t T5T1E:1;
	    vuint32_t T5ADCE:1;
	    vuint32_t :3;
	    vuint32_t T4E:1;
	    vuint32_t T4ETE:1;
	    vuint32_t T4T2E:1;
	    vuint32_t T4T1E:1;
	    vuint32_t T4ADCE:1;
	} B;
    } THCR2; /* Trigger Handler Control Register 2 */
    /* Single Conversion Mode - Comment for Dual Conversion Mode */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CIR:1;
	    vuint16_t LC:1;
	    vuint16_t CMS:1;
	    vuint16_t FIFO:3;
	    vuint16_t :1;
	    vuint16_t :3;
	    vuint16_t SU:1;
	    vuint16_t :1;
	    vuint16_t CH:4;
	} B;
    } CLR[24]; /* Commands List Register x (double-buffered) (x = 1,...,32) */
    int32_t CTU_reserved1[4]; /* (0x06C - 0x05A)/4 = 0x04 */
    /* Uncomment for Dual Conversion Mode */
    /*union {                             

      vuint16_t R;                      

      struct {                          

      vuint16_t CIR:1;                

      vuint16_t LC:1;                 

      vuint16_t CMS:1;                

      vuint16_t FIFO:3;               

      vuint16_t :1;                   

      vuint16_t CHB:4;                

      vuint16_t :1;                   

      vuint16_t CHA:4;                

      } B;                              

      } CLR[32];		                      */
    /* Commands List Register x (double-buffered) (x = 1,...,32) */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :12;
	    vuint16_t DE3:1;
	    vuint16_t DE2:1;
	    vuint16_t DE1:1;
	    vuint16_t DE0:1;
	} B;
    } FDCR; /* FIFO DMA Control Register */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :16;
	    vuint32_t FIFO_OVERRUN_EN3:1;
	    vuint32_t FIFO_OVERFLOW_EN3:1;
	    vuint32_t FIFO_EMPTY_EN3:1;
	    vuint32_t FIFO_FULL_EN3:1;
	    vuint32_t FIFO_OVERRUN_EN2:1;
	    vuint32_t FIFO_OVERFLOW_EN2:1;
	    vuint32_t FIFO_EMPTY_EN2:1;
	    vuint32_t FIFO_FULL_EN2:1;
	    vuint32_t FIFO_OVERRUN_EN1:1;
	    vuint32_t FIFO_OVERFLOW_EN1:1;
	    vuint32_t FIFO_EMPTY_EN1:1;
	    vuint32_t FIFO_FULL_EN1:1;
	    vuint32_t FIFO_OVERRUN_EN0:1;
	    vuint32_t FIFO_OVERFLOW_EN0:1;
	    vuint32_t FIFO_EMPTY_EN0:1;
	    vuint32_t FIFO_FULL_EN0:1;
	} B;
    } FCR; /* CONTROL REGISTER FIFO */
    union {
	vuint32_t R;
	struct {
	    vuint32_t THRESHOLD3:8;
	    vuint32_t THRESHOLD2:8;
	    vuint32_t THRESHOLD1:8;
	    vuint32_t THRESHOLD0:8;
	} B;
    } FTH; /* FIFO Threshold Register */
    int32_t CTU_reserved2[1]; /* (0x07B - 0x078)/4 = 0x01 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :1;
	    vuint32_t FIFO_OVERRUN3:1;
	    vuint32_t FIFO_OVERFLOW3:1;
	    vuint32_t FIFO_EMPTY3:1;
	    vuint32_t FIFO_FULL3:1;
	    vuint32_t FIFO_OVERRUN2:1;
	    vuint32_t FIFO_OVERFLOW2:1;
	    vuint32_t FIFO_EMPTY2:1;
	    vuint32_t FIFO_FULL2:1;
	    vuint32_t FIFO_OVERRUN1:1;
	    vuint32_t FIFO_OVERFLOW1:1;
	    vuint32_t FIFO_EMPTY1:1;
	    vuint32_t FIFO_FULL1:1;
	    vuint32_t FIFO_OVERRUN0:1;
	    vuint32_t FIFO_OVERFLOW0:1;
	    vuint32_t FIFO_EMPTY0:1;
	    vuint32_t FIFO_FULL0:1;
	} B;
    } FST; /* FIFO STATUS REGISTER */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :11;
	    vuint32_t NCH:5;
	    vuint32_t :6;
	    vuint32_t DATA:10;
	} B;
    } FRA[4]; /* FIFO RIGHT Aligned REGISTER */
    int32_t CTU_reserved3[4]; /* (0x09F - 0x090)/4 = 0x04 */
    union {
	vuint32_t R;
	struct {
	    vuint32_t :11;
	    vuint32_t NCH:5;
	    vuint32_t DATA:10;
	    vuint32_t :6;
	} B;
    } FLA[4]; /* FIFO LEFT Aligned REGISTER */
    int32_t CTU_reserved4[4]; /* (0x09F - 0x090)/4 = 0x04 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :7;
	    vuint16_t ETOE:1;
	    vuint16_t T2OE:1;
	    vuint16_t T1OE:1;
	    vuint16_t ADCOE:1;
	    vuint16_t TGSOSM:1;
	    vuint16_t MRSO:1;
	    vuint16_t ICE:1;
	    vuint16_t SMTO:1;
	    vuint16_t MRSRE:1;
	} B;
    } CTUEFR; /* Cross Triggering Unit Error Flag Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :6;
	    vuint16_t ADC:1;
	    vuint16_t T7:1;
	    vuint16_t T6:1;
	    vuint16_t T5:1;
	    vuint16_t T4:1;
	    vuint16_t T3:1;
	    vuint16_t T2:1;
	    vuint16_t T1:1;
	    vuint16_t T0:1;
	    vuint16_t MRS:1;
	} B;
    } CTUIFR; /* Cross Triggering Unit Interrupt Flag Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t T7IE:1;
	    vuint16_t T6IE:1;
	    vuint16_t T5IE:1;
	    vuint16_t T4IE:1;
	    vuint16_t T3IE:1;
	    vuint16_t T2IE:1;
	    vuint16_t T1IE:1;
	    vuint16_t T0IE:1;
	    vuint16_t :5;
	    vuint16_t MRSDMAE:1;
	    vuint16_t MRSIE:1;
	    vuint16_t IEE:1;
	} B;
    } CTUIR; /* Cross Triggering Unit Interrupt/DMA Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :8;
	    vuint16_t COTR:8;
	} B;
    } COTR; /* Control On-Time Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t T7SG:1;
	    vuint16_t T6SG:1;
	    vuint16_t T5SG:1;
	    vuint16_t T4SG:1;
	    vuint16_t T3SG:1;
	    vuint16_t T2SG:1;
	    vuint16_t T1SG:1;
	    vuint16_t T0SG:1;
	    vuint16_t CTUADCRESET:1;
	    vuint16_t CTUODIS:1;
	    vuint16_t FILTERENABLE:1;
	    vuint16_t CGRE:1;
	    vuint16_t FGRE:1;
	    vuint16_t MRSSG:1;
	    vuint16_t GRE:1;
	    vuint16_t TGSISRRE:1;
	} B;
    } CTUCR; /* Cross Triggering Unit Control Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :8;
	    vuint16_t FILTERVALUE:8;
	} B;
    } CTUDF; /* Cross Triggering Unit Digital Filter */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :15;
	    vuint16_t MDIS:1;
	} B;
    } CTUPCR; /* Cross Triggering Unit Power Control */
    /* Missing CTU_EXPECT_A, CTU_EXPECT_B, CTU_CNT_range */
}; /* end of CTU_tag */
/****************************************************************************/
/*                     MODULE : DFLASH                                       */
/****************************************************************************/
struct DFLASH_tag {
    union { /* Module Configuration (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t EDC:1;
            vuint32_t :4;
            vuint32_t SIZE:3;
            vuint32_t :1;
            vuint32_t LAS:3;
            vuint32_t :1;
            vuint32_t MAS:3;
            vuint32_t EER:1;
            vuint32_t RWE:1;
            vuint32_t :2;
            vuint32_t PEAS:1;
            vuint32_t DONE:1;
            vuint32_t PEG:1;
            vuint32_t :4;
            vuint32_t PGM:1;
            vuint32_t PSUS:1;
            vuint32_t ERS:1;
            vuint32_t ESUS:1;
            vuint32_t EHV:1;
        } B;
    } MCR;
    union { /* Low/Mid address block locking (Base+0x0004) */
        vuint32_t R;
        struct {
            vuint32_t LME:1;
            vuint32_t :10;
            vuint32_t TSLK:1;
            vuint32_t :16;
            vuint32_t LLK:4;
        } B;
    } LML;
    int32_t DFLASH_reserved0[1]; /* (0x00C - 0x004)/4 = 0x01 */
    union { /* Secondary Low/mid block locking (Base+0x000C)*/
        vuint32_t R;
        struct {
            vuint32_t SLE:1;
            vuint32_t :10;
            vuint32_t STSLK:1;
            vuint32_t :2;
            vuint32_t SMK:2;
	    vuint32_t :12;
            vuint32_t SLK:4;
        } B;
    } SLL;
    union { /* Low/Mid address space block sel (Base+0x0010)*/
        vuint32_t R;
        struct {
            vuint32_t:28;
            vuint32_t LSL:4;
        } B;
    } LMS;
    int32_t DFLASH_reserved1[1]; /* (0x010 - 0x00C)/4 = 0x02 */
    union { /* Address (Base+0x0018) */
        vuint32_t R;
        struct {
	    vuint32_t SAD:1;
	    vuint32_t TAD:1;
	    vuint32_t :9;
	    vuint32_t AD2:1;
            vuint32_t AD1:10;
	    vuint32_t AD9:1;
	    vuint32_t AD8:1;
	    vuint32_t AD7:1;
	    vuint32_t AD6:1;
	    vuint32_t AD5:1;
	    vuint32_t AD4:1;
	    vuint32_t AD3:1;
            vuint32_t :3;
        } B;
    } ADR;
    int32_t DFLASH_reserved2[8]; /* (0x018 - 0x03C)/4 = 0x09 */
    union { /* User Test 0 (Base+0x003C) */
        vuint32_t R;
        struct {
            vuint32_t UTE:1;
            vuint32_t :8;
            vuint32_t DSI:7;
            vuint32_t :10;
            vuint32_t MRE:1;
            vuint32_t MRV:1;
            vuint32_t EIE:1;
            vuint32_t AIS:1;
            vuint32_t AIE:1;
            vuint32_t AID:1;
        } B;
    } UT0;
    union { /* User Test 1 (Base+0x003C) */
        vuint32_t R;
        struct {
            vuint32_t DAI:32;
        } B;
    } UT1;
    int32_t DFLASH_reserved3[1]; /* (0x044) = 0x01 */
    union { /* User Multiple Input sig 0..4 (+0x0048-0x0058)*/
        vuint32_t R;
        struct {
            vuint32_t MS:32;
        } B;
    } UMISR[2];
}; /* end of DFLASH_tag */
/****************************************************************************/
/*                          MODULE : DMAMUX                                 */
/****************************************************************************/
struct DMAMUX_tag {
    union { /* DMAMUX Channel Configuration (Base+0x0000-0x000F) */
        vuint8_t R;
        struct {
            vuint8_t ENBL:1;
            vuint8_t TRIG:1;
            vuint8_t SOURCE:6;
        } B;
    } CHCONFIG[32];
}; /* end of DMAMUX_tag */
/****************************************************************************/
/*                          MODULE : DSPI                                   */
/****************************************************************************/
struct DSPI_tag{
    union { /* DSPI Module Configuraiton (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t MSTR:1;
            vuint32_t CONT_SCKE:1;
            vuint32_t DCONF:2;
            vuint32_t FRZ:1;
            vuint32_t MTFE:1;
            vuint32_t PCSSE:1;
            vuint32_t ROOE:1;
            vuint32_t :2; /* Chip selects 6,7 not bonded out on B3M */
            vuint32_t PCSIS5:1;
            vuint32_t PCSIS4:1;
            vuint32_t PCSIS3:1;
            vuint32_t PCSIS2:1;
            vuint32_t PCSIS1:1;
            vuint32_t PCSIS0:1;
            vuint32_t :1;
            vuint32_t MDIS:1;
            vuint32_t DIS_TXF:1;
            vuint32_t DIS_RXF:1;
            vuint32_t CLR_TXF:1;
            vuint32_t CLR_RXF:1;
            vuint32_t SMPL_PT:2;
            vuint32_t :6;
            vuint32_t PES:1; /* Added on B3M */
            vuint32_t HALT:1;
        } B;
    } MCR;
    union { /* DSPI Hardware Configuration (Base+0x0004) */
        vuint32_t R; /*  register added on B3M */
        struct {
            vuint32_t :1;
            vuint32_t PISR:1;
            vuint32_t :3;
            vuint32_t CTAR:3;
            vuint32_t TXFR:4;
            vuint32_t RXFR:4;
            vuint32_t :16;
        } B;
    } HCR;
    union { /* DSPI Transfer Count (Base+0x0008) */
        vuint32_t R;
        struct {
            vuint32_t TCNT:16;
            vuint32_t :16;
        } B;
    } TCR;
    union { /* DSPI Clock & Tranfer Attrib 0-7 (+0x000C-0x0028) */
        vuint32_t R;
        struct {
            vuint32_t DBR:1;
            vuint32_t FMSZ:4;
            vuint32_t CPOL:1;
            vuint32_t CPHA:1;
            vuint32_t LSBFE:1;
            vuint32_t PCSSCK:2;
            vuint32_t PASC:2;
            vuint32_t PDT:2;
            vuint32_t PBR:2;
            vuint32_t CSSCK:4;
            vuint32_t ASC:4;
            vuint32_t DT:4;
            vuint32_t BR:4;
        } B;
    } CTAR[8];
    union { /* DSPI Status (Base+0x002C) */
        vuint32_t R;
        struct {
            vuint32_t TCF:1;
            vuint32_t TXRXS:1;
            vuint32_t :1;
            vuint32_t EOQF:1;
            vuint32_t TFUF:1;
            vuint32_t :1;
            vuint32_t TFFF:1;
            vuint32_t :2;
            vuint32_t DPEF:1; /* New on Bolero 3M */
            vuint32_t SPEF:1; /* New on Bolero 3M */
            vuint32_t DDIF:1; /* New on Bolero 3M */
            vuint32_t RFOF:1;
            vuint32_t :1;
            vuint32_t RFDF:1;
            vuint32_t :1;
            vuint32_t TXCTR:4;
            vuint32_t TXNXTPTR:4;
            vuint32_t RXCTR:4;
            vuint32_t POPNXTPTR:4;
        } B;
    } SR;
    union { /* DSPI DMA/Int Request Select & Enable (+0x0030) */
        vuint32_t R;
        struct {
            vuint32_t TCFRE:1;
            vuint32_t :2;
            vuint32_t EOQFRE:1;
            vuint32_t TFUFRE:1;
            vuint32_t :1;
            vuint32_t TFFFRE:1;
            vuint32_t TFFFDIRS:1;
            vuint32_t :1;
            vuint32_t DPEF_RE:1; /* New on Bolero 3M */
            vuint32_t SPEF_RE:1; /* New on Bolero 3M */
            vuint32_t DDIF_RE:1; /* New on Bolero 3M */
            vuint32_t RFOFRE:1;
            vuint32_t :1;
            vuint32_t RFDFRE:1;
            vuint32_t RFDFDIRS:1;
            vuint32_t :16;
        } B;
    } RSER;
    union { /* DSPI Push TX FIFO (Base+0x0034) */
        vuint32_t R;
        struct {
            vuint32_t CONT:1;
            vuint32_t CTAS:3;
            vuint32_t EOQ:1;
            vuint32_t CTCNT:1;
            vuint32_t PE:1; /* New on Bolero 3M */
            vuint32_t PP:1; /* New on Bolero 3M */
            vuint32_t :2; /* PCS 7..6 not implemented on B3M */
            vuint32_t PCS5:1;
            vuint32_t PCS4:1;
            vuint32_t PCS3:1;
            vuint32_t PCS2:1;
            vuint32_t PCS1:1;
            vuint32_t PCS0:1;
            vuint32_t TXDATA:16;
        } B;
    } PUSHR;
    union { /* DSPI Pop RX FIFO (Base+0x0038)             */
        vuint32_t R;
        struct {
            vuint32_t RXDATA:32; /* Changed t0 32-bit data on B3M        */
        } B;
    } POPR;
    union { /* DSPI Transmit FIFO 0-3 (Base+0x003C-0x0048)*/
        vuint32_t R;
        struct { /* This is MASTER mode config for B3M    */
            vuint32_t TXCMD:16; /* replace with TXDATA for B3M slave mode*/
            vuint32_t TXDATA:16;
        } B;
    } TXFR[5];
    int32_t DSPI_reserved1[11]; /* (0x07C - 0x04C)/4 = 0x012 */

    union { /* DSPI Receive FIFO 0-3 (Base+0x007C-0x0088) */
        vuint32_t R;
        struct {
            vuint32_t RXDATA:32; /* Changed to 32-bit data on B3M        */
        } B;
    } RXFR[15];
}; /* end of DSPI_tag */
/****************************************************************************/
/*                     MODULE : External Bus Interface (EBI)                */
/****************************************************************************/
struct EBI_CS_tag{
    union { /* Base Register Bank */
        vuint32_t R;
        struct {
            vuint32_t BA:17;
            vuint32_t :2;
	    vuint32_t LWRN:1;
            vuint32_t PS:1;
	    vuint32_t EOE:2;
	    vuint32_t SBL:1;
	    vuint32_t AD_MUX:1;
            vuint32_t BL:1;
            vuint32_t WEBS:1;
            vuint32_t TBDIP:1;
            vuint32_t GCSN:1;
	    vuint32_t SETA:1;
            vuint32_t BI:1;
            vuint32_t V:1;
        } B;
    } EBI_BR;
    union { /* Option Register Bank */
        vuint32_t R;
        struct {
            vuint32_t AM:17;
            vuint32_t :7;
            vuint32_t SCY:4;
            vuint32_t :1;
            vuint32_t BSCY:2;
            vuint32_t :1;
        } B;
    } EBI_OR;
}; /* end of EBI_CS_tag */

/****************************************************************************/

struct EBI_CAL_tag{
    union { /* Calibration Base Register Bank */
        vuint32_t R;
        struct {
            vuint32_t BA:17;
            vuint32_t :2;
	    vuint32_t LWRN:1;
            vuint32_t PS:1;
	    vuint32_t EOE:2;
	    vuint32_t SBL:1;
	    vuint32_t AD_MUX:1;
            vuint32_t BL:1;
            vuint32_t WEBS:1;
            vuint32_t TBDIP:1;
            vuint32_t GCSN:1;
	    vuint32_t SETA:1;
            vuint32_t BI:1;
            vuint32_t V:1;
        } B;
    } CAL_BR;
    union { /* Calibration Option Register Bank */
        vuint32_t R;
        struct {
            vuint32_t AM:17;
            vuint32_t :7;
            vuint32_t SCY:4;
            vuint32_t :1;
            vuint32_t BSCY:2;
            vuint32_t :1;
        } B;
    } CAL_OR;
}; /* end of EBI_CAL_tag */

/*****************************************************************************/

struct EBI_tag {
    union { /* Module Configuration Register */
        vuint32_t R;
        struct {
            vuint32_t :5;
            vuint32_t SIZEN:1;
            vuint32_t SIZE:2;
            vuint32_t :8;
            vuint32_t ACGE:1;
            vuint32_t EXTM:1;
            vuint32_t EARB:1;
            vuint32_t EARP:2;
            vuint32_t :4;
            vuint32_t MDIS:1;
            vuint32_t :3;
            vuint32_t D16_31:1;
            vuint32_t AD_MUX:1;
            vuint32_t DBM:1;
        } B;
    } MCR;
    uint32_t EBI_reserved1[1];
    union { /* Transfer Error Status Register */
        vuint32_t R;
        struct {
            vuint32_t :30;
            vuint32_t TEAF:1;
            vuint32_t BMTF:1;
        } B;
    } TESR;
    union { /* Bus Monitor Control Register */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t BMT:8;
            vuint32_t BME:1;
            vuint32_t :7;
        } B;
    } BMCR;
    
    struct EBI_CS_tag CS[4];

    vuint8_t EBI_reserved2[16]; /* Reserved 12 bytes (base + 0x0030-0x0040)*/

    struct EBI_CAL_tag CAL[4];

}; /* end of EBI_tag */

/****************************************************************************/
/*                          MODULE : ECSM                                   */
/****************************************************************************/
struct ECSM_tag{
    union { /* ECSM Processor Core Type (Base+0x0000) */
        vuint16_t R;
    } PCT;
    union { /* ECSM Revision (Base+0x0002) */
        vuint16_t R;
    } REV;
    vuint8_t ECSM_reserved0[4]; /* Reserved 4 bytes (Base+0x0004-0x0007) */
    union { /* ECSM IPS Module Configuration (Base+0x0008) */
        vuint32_t R;
    } IMC;
    vuint8_t ECSM_reserved1[4]; /* Reserved 7 bytes (Base+0x000C-0x00E) */
    union { /* ECSM Miscellaneous Reset Status Register (+0x000F) */
        vuint8_t R;
        struct {
            vuint8_t POR:1;
            vuint8_t DIR:1;
            vuint8_t :6;
        } B;
    } MRSR;
    vuint8_t ECSM_reserved2[14]; /* Reserved 14 bytes (Base+0x0010-0x01E) */
    union { /* ECSM Miscellaneous Interrupt (Base+0x001F) */
        vuint8_t R;
        struct {
            vuint8_t FB0AI:1;
            vuint8_t FB0SI:1;
            vuint8_t FB1AI:1;
            vuint8_t FB1SI:1;
	    vuint8_t FB2AI:1;
	    vuint8_t FB2SI:1;
	    vuint8_t :2;
        } B;
    } MIR;
    vuint8_t ECSM_reserved3[4]; /* Reserved 4 bytes (Base+0x0020-0x0023) */
    union { /*ECSM Miscellaneous User-Defined Control (+0x0024)*/
	vuint32_t R;
    } MUDCR;
    vuint8_t ECSM_reserved4[27]; /* Reserved 27 bytes (Base+0x0028-0x0042) */
    union { /* ECSM ECC Configuration (Base+0x0043) */
        vuint8_t R;
        struct {
            vuint8_t :2;
            vuint8_t ER1BR:1;
            vuint8_t EF1BR:1;
            vuint8_t :2;
            vuint8_t ERNCR:1;
            vuint8_t EFNCR:1;
        } B;
    } ECR;
    vuint8_t ECSM_reserved5[3]; /* Reserved 3 bytes (Base+0x0044-0x0046) */
    union { /* ECSM ECC Status (Base+0x0047) */
        vuint8_t R;
        struct {
            vuint8_t :2;
            vuint8_t R1BC:1;
            vuint8_t F1BC:1;
            vuint8_t :2;
            vuint8_t RNCE:1;
            vuint8_t FNCE:1;
        } B;
    } ESR;
    vuint8_t ECSM_reserved6[2]; /* Reserved 2 bytes (Base+0x0048-0x0049) */
    union { /* ECSM ECC Error Generation (Base+0x004A) */
        vuint16_t R;
        struct {
            vuint16_t :2;
            vuint16_t FRC1BI:1;
            vuint16_t FR11BI:1;
            vuint16_t :2;
            vuint16_t FRCNCI:1;
            vuint16_t FR1NCI:1;
            vuint16_t :1;
            vuint16_t ERRBIT:7;
        } B;
    } EEGR;
    vuint8_t ECSM_reserved7[4]; /* Reserved 4 bytes (Base+0x004C-0x004F) */
    union { /* ECSM Flash ECC Address(Base+0x0050) */
        vuint32_t R;
    } FEAR;
    vuint8_t ECSM_reserved8[2]; /* Reserved 2 bytes (Base+0x0054-0x0055) */
    union { /* ECSM Flash ECC Master Number (Base+0x0056) */
        vuint8_t R;
        struct {
            vuint8_t :4;
            vuint8_t FEMR:4;
        } B;
    } FEMR;
    union { /* ECSM Flash ECC Attributes (Base+0x0057) */
        vuint8_t R;
        struct {
            vuint8_t WRITE:1;
	    vuint8_t SIZE:3;
            vuint8_t PROTECTION:4;
        } B;
    } FEAT;
    vuint8_t ECSM_reserved9[4]; /* Reserved 4 bytes (Base+0x0058-0x005B) */
    union { /* ECSM Flash ECC Data (Base+0x005C) */
        vuint32_t R;
    } FEDR;
    union { /* ECSM RAM ECC Address (Base+0x0060) */
        vuint32_t R;
    } REAR;
    vuint8_t ECSM_reserved10[1]; /* Reserved 1 bytes (Base+0x0064) */
    union { /* ECSM RAM ECC Address (Base+0x0065) */
        vuint8_t R;
    } RESR;
    union { /* ECSM RAM ECC Master Number (Base+0x0066) */
        vuint8_t R;
        struct {
            vuint8_t :4;
            vuint8_t REMR:4;
        } B;
    } REMR;
    union { /* ECSM RAM ECC Attributes (Base+0x0067) */
        vuint8_t R;
        struct {
            vuint8_t WRITE:1;
            vuint8_t SIZE:3;
            vuint8_t PROTECTION:4;
        } B;
    } REAT;
    vuint8_t ECSM_reserved11[4]; /* Reserved 4 bytes (Base+0x0068-0x006B) */
    union { /* ECSM RAM ECC Data (Base+0x006C) */
        vuint32_t R;
    } REDR;
}; /* end of ECSM_tag */
/****************************************************************************/
/*                          MODULE : eDMA                                   */
/****************************************************************************/
/*for "standard" format TCD (when EDMA.TCD[x].CITERE_LINK==BITERE_LINK=0) */
struct EDMA_TCD_STD_tag {
    vuint32_t SADDR; /* source address */
    vuint16_t SMOD:5; /* source address modulo */
    vuint16_t SSIZE:3; /* source transfer size */
    vuint16_t DMOD:5; /* destination address modulo */
    vuint16_t DSIZE:3; /* destination transfer size */
    vint16_t SOFF; /* signed source address offset */
    vuint32_t NBYTES; /* inner (?minor?) byte count */
    vint32_t SLAST; /* last destination address adjustment, or scatter/gather address (if e_sg = 1) */
    vuint32_t DADDR; /* destination address */
    vuint16_t CITERE_LINK:1;
    vuint16_t CITER:15;
    vint16_t DOFF; /* signed destination address offset */
    vint32_t DLAST_SGA;
    vuint16_t BITERE_LINK:1; /* beginning ("major") iteration count */
    vuint16_t BITER:15;
    vuint16_t BWC:2; /* bandwidth control */
    vuint16_t MAJORLINKCH:6; /* enable channel-to-channel link */
    vuint16_t DONE:1; /* channel done */
    vuint16_t ACTIVE:1; /* channel active */
    vuint16_t MAJORE_LINK:1; /* enable channel-to-channel link */
    vuint16_t E_SG:1; /* enable scatter/gather descriptor */
    vuint16_t D_REQ:1; /* disable ipd_req when done */
    vuint16_t INT_HALF:1; /* interrupt on citer = (biter >> 1) */
    vuint16_t INT_MAJ:1; /* interrupt on major loop completion */
    vuint16_t START:1; /* explicit channel start */
}; /* end of EDMA_TCD_STD_tag */
/*for "channel link" format TCD (when EDMA.TCD[x].CITERE_LINK==BITERE_LINK=1)*/
struct EDMA_TCD_CHLINK_tag {
    vuint32_t SADDR; /* source address */
    vuint16_t SMOD:5; /* source address modulo */
    vuint16_t SSIZE:3; /* source transfer size */
    vuint16_t DMOD:5; /* destination address modulo */
    vuint16_t DSIZE:3; /* destination transfer size */
    vint16_t SOFF; /* signed source address offset */
    vuint32_t NBYTES; /* inner (?minor?) byte count */
    vint32_t SLAST; /* last destination address adjustment, or scatter/gather address (if e_sg = 1) */
    vuint32_t DADDR; /* destination address */
    vuint16_t CITERE_LINK:1;
    vuint16_t CITERLINKCH:6;
    vuint16_t CITER:9;
    vint16_t DOFF; /* signed destination address offset */
    vint32_t DLAST_SGA;
    vuint16_t BITERE_LINK:1; /* beginning (?major?) iteration count */
    vuint16_t BITERLINKCH:6;
    vuint16_t BITER:9;
    vuint16_t BWC:2; /* bandwidth control */
    vuint16_t MAJORLINKCH:6; /* enable channel-to-channel link */
    vuint16_t DONE:1; /* channel done */
    vuint16_t ACTIVE:1; /* channel active */
    vuint16_t MAJORE_LINK:1; /* enable channel-to-channel link */
    vuint16_t E_SG:1; /* enable scatter/gather descriptor */
    vuint16_t D_REQ:1; /* disable ipd_req when done */
    vuint16_t INT_HALF:1; /* interrupt on citer = (biter >> 1) */
    vuint16_t INT_MAJ:1; /* interrupt on major loop completion */
    vuint16_t START:1; /* explicit channel start */
}; /* end of EDMA_TCD_CHLINK_tag */
struct EDMA_tag {
    union { /* Control (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t:14;
            vuint32_t CX:1;
            vuint32_t ECX:1;
            vuint32_t GRP3PRI:2;
            vuint32_t GRP2PRI:2;
            vuint32_t GRP1PRI:2;
            vuint32_t GRP0PRI:2;
            vuint32_t EMLM:1;
            vuint32_t CLM:1;
            vuint32_t HALT:1;
            vuint32_t HOE:1;
            vuint32_t ERGA:1;
            vuint32_t ERCA:1;
            vuint32_t EDBG:1;
            vuint32_t EBW:1;
        } B;
    } CR;
    union { /* Error Status (Base+0x0004) */
        vuint32_t R;
        struct {
            vuint32_t VLD:1;
            vuint32_t:14;
            vuint32_t ECX:1;
            vuint32_t GPE:1;
            vuint32_t CPE:1;
	    vuint32_t :1;
            vuint32_t ERRCHN:5;
            vuint32_t SAE:1;
            vuint32_t SOE:1;
            vuint32_t DAE:1;
            vuint32_t DOE:1;
            vuint32_t NCE:1;
            vuint32_t SGE:1;
            vuint32_t SBE:1;
            vuint32_t DBE:1;
        } B;
    } ESR;
    union { /* Enable Request High Ch63..32 (Base+0x0008) */
        vuint32_t R;
        struct {
            vuint32_t ERQ63:1;
            vuint32_t ERQ62:1;
            vuint32_t ERQ61:1;
            vuint32_t ERQ60:1;
            vuint32_t ERQ59:1;
            vuint32_t ERQ58:1;
            vuint32_t ERQ57:1;
            vuint32_t ERQ56:1;
            vuint32_t ERQ55:1;
            vuint32_t ERQ54:1;
            vuint32_t ERQ53:1;
            vuint32_t ERQ52:1;
            vuint32_t ERQ51:1;
            vuint32_t ERQ50:1;
            vuint32_t ERQ49:1;
            vuint32_t ERQ48:1;
            vuint32_t ERQ47:1;
            vuint32_t ERQ46:1;
            vuint32_t ERQ45:1;
            vuint32_t ERQ44:1;
            vuint32_t ERQ43:1;
            vuint32_t ERQ42:1;
            vuint32_t ERQ41:1;
            vuint32_t ERQ40:1;
            vuint32_t ERQ39:1;
            vuint32_t ERQ38:1;
            vuint32_t ERQ37:1;
            vuint32_t ERQ36:1;
            vuint32_t ERQ35:1;
            vuint32_t ERQ34:1;
            vuint32_t ERQ33:1;
            vuint32_t ERQ32:1;
        } B;
    } ERQH;
    union { /* Enable Request Low Ch31..0 (Base+0x000C) */
        vuint32_t R;
        struct {
            vuint32_t ERQ31:1;
            vuint32_t ERQ30:1;
            vuint32_t ERQ29:1;
            vuint32_t ERQ28:1;
            vuint32_t ERQ27:1;
            vuint32_t ERQ26:1;
            vuint32_t ERQ25:1;
            vuint32_t ERQ24:1;
            vuint32_t ERQ23:1;
            vuint32_t ERQ22:1;
            vuint32_t ERQ21:1;
            vuint32_t ERQ20:1;
            vuint32_t ERQ19:1;
            vuint32_t ERQ18:1;
            vuint32_t ERQ17:1;
            vuint32_t ERQ16:1;
            vuint32_t ERQ15:1;
            vuint32_t ERQ14:1;
            vuint32_t ERQ13:1;
            vuint32_t ERQ12:1;
            vuint32_t ERQ11:1;
            vuint32_t ERQ10:1;
            vuint32_t ERQ09:1;
            vuint32_t ERQ08:1;
            vuint32_t ERQ07:1;
            vuint32_t ERQ06:1;
            vuint32_t ERQ05:1;
            vuint32_t ERQ04:1;
            vuint32_t ERQ03:1;
            vuint32_t ERQ02:1;
            vuint32_t ERQ01:1;
            vuint32_t ERQ00:1;
        } B;
    } ERQL;
    union { /* nable Error Interrupt High (Base+0x0010) */
        vuint16_t R;
        struct {
            vuint32_t EEI63:1;
            vuint32_t EEI62:1;
            vuint32_t EEI61:1;
            vuint32_t EEI60:1;
            vuint32_t EEI59:1;
            vuint32_t EEI58:1;
            vuint32_t EEI57:1;
            vuint32_t EEI56:1;
            vuint32_t EEI55:1;
            vuint32_t EEI54:1;
            vuint32_t EEI53:1;
            vuint32_t EEI52:1;
            vuint32_t EEI51:1;
            vuint32_t EEI50:1;
            vuint32_t EEI49:1;
            vuint32_t EEI48:1;
            vuint32_t EEI47:1;
            vuint32_t EEI46:1;
            vuint32_t EEI45:1;
            vuint32_t EEI44:1;
            vuint32_t EEI43:1;
            vuint32_t EEI42:1;
            vuint32_t EEI41:1;
            vuint32_t EEI40:1;
            vuint32_t EEI39:1;
            vuint32_t EEI38:1;
            vuint32_t EEI37:1;
            vuint32_t EEI36:1;
            vuint32_t EEI35:1;
            vuint32_t EEI34:1;
            vuint32_t EEI33:1;
            vuint32_t EEI32:1;
        } B;
    } EEIRH;
    union { /* nable Error Interrupt Low (Base+0x0014) */
        vuint16_t R;
        struct {
            vuint32_t EEI31:1;
            vuint32_t EEI30:1;
            vuint32_t EEI29:1;
            vuint32_t EEI28:1;
            vuint32_t EEI27:1;
            vuint32_t EEI26:1;
            vuint32_t EEI25:1;
            vuint32_t EEI24:1;
            vuint32_t EEI23:1;
            vuint32_t EEI22:1;
            vuint32_t EEI21:1;
            vuint32_t EEI20:1;
            vuint32_t EEI19:1;
            vuint32_t EEI18:1;
            vuint32_t EEI17:1;
            vuint32_t EEI16:1;
            vuint32_t EEI15:1;
            vuint32_t EEI14:1;
            vuint32_t EEI13:1;
            vuint32_t EEI12:1;
            vuint32_t EEI11:1;
            vuint32_t EEI10:1;
            vuint32_t EEI09:1;
            vuint32_t EEI08:1;
            vuint32_t EEI07:1;
            vuint32_t EEI06:1;
            vuint32_t EEI05:1;
            vuint32_t EEI04:1;
            vuint32_t EEI03:1;
            vuint32_t EEI02:1;
            vuint32_t EEI01:1;
            vuint32_t EEI00:1;
        } B;
    } EEIRL;
    union { /* DMA Set Enable Request (Base+0x0018) */
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t SERQ:7;
        } B;
    } SERQ;
    union { /* DMA Clear Enable Request (Base+0x0019) */
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t CERQ:7;
        } B;
    } CERQ;
    union { /* DMA Set Enable Error Interrupt (Base+0x001A) */
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t SEEI:7;
        } B;
    } SEEI;
    union { /* DMA Clr Enable Error Interrupt (Base+0x001B) */
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t CEEI:7;
        } B;
    } CEEI;
    union { /* DMA Clear Interrupt Request (Base+0x001C) */
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t CINT:7;
        } B;
    } CINT;
    union { /* DMA Clear error (Base+0x001D) */
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t CERR:7;
        } B;
    } CER;
    union { /* DMA Set Start Bit (Base+0x001E) */
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t SSRT:7;
        } B;
    } SSRT;
    union { /* DMA Clear Done Status Bit (Base+0x001F) */
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t CDNE:7;
        } B;
    } CDNE;
    union { /* DMA Interrupt Req High Ch63..32 (+0x0020) */
        vuint32_t R;
        struct {
            vuint32_t INT63:1;
            vuint32_t INT62:1;
            vuint32_t INT61:1;
            vuint32_t INT60:1;
            vuint32_t INT59:1;
            vuint32_t INT58:1;
            vuint32_t INT57:1;
            vuint32_t INT56:1;
            vuint32_t INT55:1;
            vuint32_t INT54:1;
            vuint32_t INT53:1;
            vuint32_t INT52:1;
            vuint32_t INT51:1;
            vuint32_t INT50:1;
            vuint32_t INT49:1;
            vuint32_t INT48:1;
            vuint32_t INT47:1;
            vuint32_t INT46:1;
            vuint32_t INT45:1;
            vuint32_t INT44:1;
            vuint32_t INT43:1;
            vuint32_t INT42:1;
            vuint32_t INT41:1;
            vuint32_t INT40:1;
            vuint32_t INT39:1;
            vuint32_t INT38:1;
            vuint32_t INT37:1;
            vuint32_t INT36:1;
            vuint32_t INT35:1;
            vuint32_t INT34:1;
            vuint32_t INT33:1;
            vuint32_t INT32:1;
        } B;
    } IRQRH;
    union { /* DMA Interrupt Req Low Ch31..0 (+0x0024) */
        vuint32_t R;
        struct {
            vuint32_t INT31:1;
            vuint32_t INT30:1;
            vuint32_t INT29:1;
            vuint32_t INT28:1;
            vuint32_t INT27:1;
            vuint32_t INT26:1;
            vuint32_t INT25:1;
            vuint32_t INT24:1;
            vuint32_t INT23:1;
            vuint32_t INT22:1;
            vuint32_t INT21:1;
            vuint32_t INT20:1;
            vuint32_t INT19:1;
            vuint32_t INT18:1;
            vuint32_t INT17:1;
            vuint32_t INT16:1;
            vuint32_t INT15:1;
            vuint32_t INT14:1;
            vuint32_t INT13:1;
            vuint32_t INT12:1;
            vuint32_t INT11:1;
            vuint32_t INT10:1;
            vuint32_t INT09:1;
            vuint32_t INT08:1;
            vuint32_t INT07:1;
            vuint32_t INT06:1;
            vuint32_t INT05:1;
            vuint32_t INT04:1;
            vuint32_t INT03:1;
            vuint32_t INT02:1;
            vuint32_t INT01:1;
            vuint32_t INT00:1;
        } B;
    } IRQRL;
    union { /* DMA Error High Ch63..32 (Base+0x0028)*/
        vuint32_t R;
        struct {
            vuint32_t ERR63:1;
            vuint32_t ERR62:1;
            vuint32_t ERR61:1;
            vuint32_t ERR60:1;
            vuint32_t ERR59:1;
            vuint32_t ERR58:1;
            vuint32_t ERR57:1;
            vuint32_t ERR56:1;
            vuint32_t ERR55:1;
            vuint32_t ERR54:1;
            vuint32_t ERR53:1;
            vuint32_t ERR52:1;
            vuint32_t ERR51:1;
            vuint32_t ERR50:1;
            vuint32_t ERR49:1;
            vuint32_t ERR48:1;
            vuint32_t ERR47:1;
            vuint32_t ERR46:1;
            vuint32_t ERR45:1;
            vuint32_t ERR44:1;
            vuint32_t ERR43:1;
            vuint32_t ERR42:1;
            vuint32_t ERR41:1;
            vuint32_t ERR40:1;
            vuint32_t ERR39:1;
            vuint32_t ERR38:1;
            vuint32_t ERR37:1;
            vuint32_t ERR36:1;
            vuint32_t ERR35:1;
            vuint32_t ERR34:1;
            vuint32_t ERR33:1;
            vuint32_t ERR32:1;
        } B;
    } ERRH;
    union { /* DMA Error Low Ch63..32 (Base+0x002C)*/
        vuint32_t R;
        struct {
            vuint32_t ERR31:1;
            vuint32_t ERR30:1;
            vuint32_t ERR29:1;
            vuint32_t ERR28:1;
            vuint32_t ERR27:1;
            vuint32_t ERR26:1;
            vuint32_t ERR25:1;
            vuint32_t ERR24:1;
            vuint32_t ERR23:1;
            vuint32_t ERR22:1;
            vuint32_t ERR21:1;
            vuint32_t ERR20:1;
            vuint32_t ERR19:1;
            vuint32_t ERR18:1;
            vuint32_t ERR17:1;
            vuint32_t ERR16:1;
            vuint32_t ERR15:1;
            vuint32_t ERR14:1;
            vuint32_t ERR13:1;
            vuint32_t ERR12:1;
            vuint32_t ERR11:1;
            vuint32_t ERR10:1;
            vuint32_t ERR09:1;
            vuint32_t ERR08:1;
            vuint32_t ERR07:1;
            vuint32_t ERR06:1;
            vuint32_t ERR05:1;
            vuint32_t ERR04:1;
            vuint32_t ERR03:1;
            vuint32_t ERR02:1;
            vuint32_t ERR01:1;
            vuint32_t ERR00:1;
        } B;
    } ERRL;
    union { /* DMA Hardware Request Stat High (Base+0x0030) */
        vuint32_t R;
        struct {
            vuint32_t HRS63:1;
            vuint32_t HRS62:1;
            vuint32_t HRS61:1;
            vuint32_t HRS60:1;
            vuint32_t HRS59:1;
            vuint32_t HRS58:1;
            vuint32_t HRS57:1;
            vuint32_t HRS56:1;
            vuint32_t HRS55:1;
            vuint32_t HRS54:1;
            vuint32_t HRS53:1;
            vuint32_t HRS52:1;
            vuint32_t HRS51:1;
            vuint32_t HRS50:1;
            vuint32_t HRS49:1;
            vuint32_t HRS48:1;
            vuint32_t HRS47:1;
            vuint32_t HRS46:1;
            vuint32_t HRS45:1;
            vuint32_t HRS44:1;
            vuint32_t HRS43:1;
            vuint32_t HRS42:1;
            vuint32_t HRS41:1;
            vuint32_t HRS40:1;
            vuint32_t HRS39:1;
            vuint32_t HRS38:1;
            vuint32_t HRS37:1;
            vuint32_t HRS36:1;
            vuint32_t HRS35:1;
            vuint32_t HRS34:1;
            vuint32_t HRS33:1;
            vuint32_t HRS32:1;
        } B;
    } HRSH;
    union { /* DMA Hardware Request Stat Low (Base+0x0034) */
        vuint32_t R;
        struct {
            vuint32_t HRS31:1;
            vuint32_t HRS30:1;
            vuint32_t HRS29:1;
            vuint32_t HRS28:1;
            vuint32_t HRS27:1;
            vuint32_t HRS26:1;
            vuint32_t HRS25:1;
            vuint32_t HRS24:1;
            vuint32_t HRS23:1;
            vuint32_t HRS22:1;
            vuint32_t HRS21:1;
            vuint32_t HRS20:1;
            vuint32_t HRS19:1;
            vuint32_t HRS18:1;
            vuint32_t HRS17:1;
            vuint32_t HRS16:1;
            vuint32_t HRS15:1;
            vuint32_t HRS14:1;
            vuint32_t HRS13:1;
            vuint32_t HRS12:1;
            vuint32_t HRS11:1;
            vuint32_t HRS10:1;
            vuint32_t HRS09:1;
            vuint32_t HRS08:1;
            vuint32_t HRS07:1;
            vuint32_t HRS06:1;
            vuint32_t HRS05:1;
            vuint32_t HRS04:1;
            vuint32_t HRS03:1;
            vuint32_t HRS02:1;
            vuint32_t HRS01:1;
            vuint32_t HRS00:1;
        } B;
    } HRSL;
    union { /* DMA General Purpose Output (Base+0x0038) */
        vuint32_t R;
        struct {
            vuint32_t GPOR:1;
        } B;
    } GPOR;
    vuint8_t eDMA_reserved0[196]; /* Reserved 196 bytes (Base+0x003C-0x00FF)*/
    union { /* Channel n Priority (Base+0x0100-0x013F)*/
        vuint8_t R;
        struct {
            vuint8_t ECP:1;
            vuint8_t DPA:1;
            vuint8_t GRPPRI:2;
            vuint8_t CHPRI:4;
        } B;
    } CPR[64];
    vuint8_t eDMA_reserved1[3776]; /* Reserved 3776 bytes (+0x0140-0x0FFF) */
    /* Transfer Control Descriptors 0..63 (Base+0x0140-0x17FC) */
    struct EDMA_TCD_STD_tag TCD[64];
    /* or change to following if using channel linking */
    /* Struct EDMA_TCD_CHLINK_tag TCD[64]; */
}; /* end of EDMA_tag */
/****************************************************************************/
/*                          MODULE : ETIMER                                   */
/****************************************************************************/
struct ETIMER_CHANNEL_tag{
    union {
	vuint16_t R;
	struct {
	    vuint16_t COMP1:16;
	} B;
    } COMP1; /* Compare Register 1 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t COMP2:16;
	} B;
    } COMP2; /* Compare Register 2 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CAPT1:16;
	} B;
    } CAPT1; /* Capture Register 1 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CAPT2:16;
	} B;
    } CAPT2; /* Capture Register 2 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t LOAD:16;
	} B;
    } LOAD; /* Load Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t HOLD:16;
	} B;
    } HOLD; /* Hold Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CNTR:16;
	} B;
    } CNTR; /* Counter Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CNTMODE:3;
	    vuint16_t PRISRC:5;
	    vuint16_t ONCE:1;
	    vuint16_t LENGTH:1;
	    vuint16_t DIR:1;
	    vuint16_t SECSRC:5;
	} B;
    } CTRL; /* Control Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t OEN:1;
	    vuint16_t RDNT:1;
	    vuint16_t INPUT:1;
	    vuint16_t VAL:1;
	    vuint16_t FORCE:1;
	    vuint16_t COFRC:1;
	    vuint16_t COINIT:2;
	    vuint16_t SIPS:1;
	    vuint16_t PIPS:1;
	    vuint16_t OPS:1;
	    vuint16_t MSTR:1;
	    vuint16_t OUTMODE:4;
	} B;
    } CTRL2; /* Control Register 2 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t STPEN:1;
	    vuint16_t ROC:2;
	    vuint16_t FMODE:1;
	    vuint16_t FDIS:4;
	    vuint16_t C2FCNT:3;
	    vuint16_t C1FCNT:3;
	    vuint16_t DBGEN:2;
	} B;
    } CTRL3; /* Control Register 3 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :6;
	    vuint16_t WDF:1;
	    vuint16_t RCF:1;
	    vuint16_t ICF2:1;
	    vuint16_t ICF1:1;
	    vuint16_t IEHF:1;
	    vuint16_t IELF:1;
	    vuint16_t TOF:1;
	    vuint16_t TCF2:1;
	    vuint16_t TCF1:1;
	    vuint16_t TCF:1;
	} B;
    } STS; /* Status Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t ICF2DE:1;
	    vuint16_t ICF1DE:1;
	    vuint16_t CMPLD2DE:1;
	    vuint16_t CMPLD1DE:1;
	    vuint16_t :2;
	    vuint16_t WDFIE:1;
	    vuint16_t RCFIE:1;
	    vuint16_t ICF2IE:1;
	    vuint16_t ICF1IE:1;
	    vuint16_t IEHFIE:1;
	    vuint16_t IELFIE:1;
	    vuint16_t TOFIE:1;
	    vuint16_t TCF2IE:1;
	    vuint16_t TCF1IE:1;
	    vuint16_t TCFIE:1;
	} B;
    } INTDMA; /* Interrupt and DMA Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CMPLD1:16;
	} B;
    } CMPLD1; /* Compare Load Register 1 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CMPLD2:16;
	} B;
    } CMPLD2; /* Compare Load Register 2 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CLC2:3;
	    vuint16_t CLC1:3;
	    vuint16_t CMPMODE:2;
	    vuint16_t CPT2MODE:2;
	    vuint16_t CPT1MODE:2;
	    vuint16_t CFWM:2;
	    vuint16_t ONESHOT:1;
	    vuint16_t ARM:1;
	} B;
    } CCCTRL; /* Compare and Capture Control Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :5;
	    vuint16_t FILTCNT:3;
	    vuint16_t FILTPER:8;
	} B;
    } FILT; /* Input Filter Register */
}; /* end of ETIMER_CHANNEL_tag */

struct ETIMER_tag{
    struct ETIMER_CHANNEL_tag CHANNEL[8];
    union {
	vuint16_t R;
	struct {
	    vuint16_t WDTOL:16;
	} B;
    } WDTOL; /* Watchdog Time-out Low Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t WDTOH:16;
	} B;
    } WDTOH; /* Watchdog Time-out High Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :3;
	    vuint16_t FTEST:1;
	    vuint16_t FIE:4;
	    vuint16_t :4;
	    vuint16_t FLVL:4;
	} B;
    } FCTRL; /* Fault Control Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :4;
	    vuint16_t FFPIN:4;
	    vuint16_t :4;
	    vuint16_t FFLAG:4;
	} B;
    } FSTS; /* Fault Status Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t :5;
	    vuint16_t FFILTCNT:3;
	    vuint16_t FFILTPER:8;
	} B;
    } FFILT; /* Fault Filter Register */
    int16_t ETIMER_reserved1[1];
    union {
	vuint16_t R;
	struct {
	    vuint16_t :8;
	    vuint16_t ENBL:8;
	} B;
    } ENBL; /* Channel Enable Register */
    int16_t ETIMER_reserved2[1];
    union {
	vuint16_t R;
	struct {
	    vuint16_t :11;
	    vuint16_t DREQ:5;
	} B;
    } DREQ0; /* DMA Request 0->3 Select Register */
     int16_t ETIMER_reserved3[1];
        union {
	vuint16_t R;
	struct {
	    vuint16_t :11;
	    vuint16_t DREQ:5;
	} B;
    } DREQ1; /* DMA Request 0->3 Select Register */

    
}; /* end of ETIMER_tag */
/****************************************************************************/
/*                          MODULE : FCCU                                   */
/****************************************************************************/
struct FCCU_tag{
    union { /* Control Register (Base + 0x0000) */
	vuint32_t R;
	struct {
	    vuint32_t :23;
	    vuint32_t NVML:1;
	    vuint32_t OPS:2;
	    vuint32_t :1;
	    vuint32_t OPR:5;
	} B;
    } CTRL;
    union { /* Control Key Register (Base + 0x0004 */
	vuint32_t R;
	struct {
	    vuint32_t CTRLK:32;
	} B;
    } CTRLK;
    union { /* Configuration Register (Base + 0x0008)*/
	vuint32_t R;
	struct {
	    vuint32_t :10;
	    vuint32_t RCCE1:1;
	    vuint32_t RCCE0:1;
	    vuint32_t SMRT:4;
	    vuint32_t :4;
	    vuint32_t CM:1;
	    vuint32_t SM:1;
	    vuint32_t PS:1;
	    vuint32_t FOM:3;
	    vuint32_t FOP:6;
	} B;
    } CFG;
    union { /* CF Configuration Register (Base + 0x000C-0x0010 ) */
	vuint32_t R;
	struct {
	    vuint32_t CFC:32;
	} B;
    } CF_CFG[2];
    int32_t FCCU_reserved0[2]; /* (0x014 - 0x01c)/4 = 0x02 */
    union { /* NCF Configuration Register (Base + 0x001C)*/
	vuint32_t R;
	struct {
	    vuint32_t NCFC:32;
	} B;
    } NCF_CFG;
    int32_t FCCU_reserved1[3]; /* (0x020 - 0x02C)/4 = 0x03 */
    union { /* CFS Configuration Register (base + 0x002C-0x0034)*/
	vuint32_t R;
	struct {
	    vuint32_t CFSC:32;
	} B;
    } CFS_CFG[3];
    int32_t FCCU_reserved2[5]; /* (0x038 - 0x04C)/4 = 0x05 */
    union { /* NCFS Configuration Register (base + 0x0054-0x0068)*/
	vuint32_t R;
	struct {
	    vuint32_t NCFSC:32;
	} B;
    } NCFS_CFG[2];
    int32_t FCCU_reserved3[6]; /* (0x054 - 0x06C)/4 = 0x06 */
    union { /* CF Status Register (base + 0x006C-0x0070)*/
	vuint32_t R;
	struct {
	    vuint32_t CFS:32;
	} B;
    } CFS[2];
    int32_t FCCU_reserved4[2]; /* (0x074 - 0x07C)/4 = 0x02 */
    union { /* CF Key Register (base + 0x007C)*/
	vuint32_t R;
	struct {
	    vuint32_t CFK:32;
	} B;
    } CFK;
    union { /* NCF Status Register (base + 0x0080)*/
	vuint32_t R;
	struct {
	    vuint32_t NCFS:32;
	} B;
    } NCFS0;
    int32_t FCCU_reserved5[3]; /* (0x084 - 0x090)/4 = 0x03 */
    union { /* NCF Key Register (base + 0x0090)*/
	vuint32_t R;
	struct {
	    vuint32_t NCFK:32;
	} B;
    } NCFK;
    union { /* NCF Enable Register (base + 0x0094)*/
	vuint32_t R;
	struct {
	    vuint32_t NCFE:32;
	} B;
    } NCFE;
    int32_t FCCU_reserved6[3]; /* (0x098 - 0x0A4)/4 = 0x03 */
    union { /* NCF Time-Out Enable Register (base + 0x00A4)*/
	vuint32_t R;
	struct {
	    vuint32_t NCFTOE:32;
	} B;
    } NCFTOE;
    int32_t FCCU_reserved7[3]; /* (0x0A8 - 0x0B4)/4 = 0x03 */
    union { /* NCF Time-Out Register (base + 0x00B4)*/
	vuint32_t R;
	struct {
	    vuint32_t TO:32;
	} B;
    } NCF_TO;
    union { /* CGF Time-Out Register (base + 0x00B8)*/
	vuint32_t R;
	struct {
	    vuint32_t :29;
	    vuint32_t TO:3;
	} B;
    } CFG_TO;
    union { /* EINOUT Register (base + 0x00BC)*/
	vuint32_t R;
	struct {
	    vuint32_t :32; /* This needs to be updated as they don't exist in RM*/
	} B;
    } EINOUT;
    union { /* Status Register (base + 0x00C0)*/
	vuint32_t R;
	struct {
	    vuint32_t :29;
	    vuint32_t STATUS:3;
	} B;
    } STAT;
    union { /* NA Freeze Status Register (base + 0x00C4)*/
	vuint32_t R;
	struct {
	    vuint32_t :32; /* This needs to be updated as they don't exist in RM*/
	} B;
    } NAFS;
    union { /* AF Freeze Status Register (base + 0x00C8)*/
	vuint32_t R;
	struct {
	    vuint32_t :32; /* This needs to be updated as they don't exist in RM*/
	} B;
    } AFFS;
    union { /* NF Freeze Status Register (base + 0x00CC)*/
	vuint32_t R;
	struct {
	    vuint32_t :32; /* This needs to be updated as they don't exist in RM*/
	} B;
    } NFFS;
    union { /* FA Freeze Status Register (base + 0x00D0)*/
	vuint32_t R;
	struct {
	    vuint32_t :32; /* This needs to be updated as they don't exist in RM*/
	} B;
    } FAFS;
    union { /* SC Freeze Status Register (base + 0x00D4)*/
	vuint32_t R;
	struct {
	    vuint32_t :32; /* This needs to be updated as they don't exist in RM*/
	} B;
    } SCFS;
    union { /* CF Fake Register (base + 0x00D8)*/
	vuint32_t R;
	struct {
	    vuint32_t :25;
	    vuint32_t FCFC:7;
	} B;
    } CFF;
    union { /* NCF Fake Register (base + 0x00DC)*/
	vuint32_t R;
	struct {
	    vuint32_t :25;
	    vuint32_t FCNFC:7;
	} B;
    } NCFF;
    union { /* IRQ STAT Register (base + 0x00E0)*/
	vuint32_t R;
	struct {
	    vuint32_t :29;
	    vuint32_t NMI_STAT:1;
	    vuint32_t ALRM_STAT:1;
	    vuint32_t CFG_TO_STAT:1;
	} B;
    } IRQ_STAT;
    union { /* IRQ Enable Register (base + 0x00E4)*/
	vuint32_t R;
	struct {
	    vuint32_t :31;
	    vuint32_t CFG_TOI_EN:1;
	} B;
    } IRQ_EN;
    union { /* XTMR Register (base + 0x00E8)*/
	vuint32_t R;
	struct {
	    vuint32_t XTMR:32;
	} B;
    } XTMR;
    union { /* MCS Register (base + 0x00EC)*/
	vuint32_t R;
	struct {
	    vuint32_t VL3:1;
	    vuint32_t FS3:1;
	    vuint32_t :1;
	    vuint32_t MCS3:4;
	    vuint32_t VL2:1;
	    vuint32_t FS2:1;
	    vuint32_t :1;
	    vuint32_t MCS2:4;
	    vuint32_t VL1:1;
	    vuint32_t FS1:1;
	    vuint32_t :1;
	    vuint32_t MCS1:4;
	    vuint32_t VL0:1;
	    vuint32_t FS0:1;
	    vuint32_t :1;
	    vuint32_t MCS0:4;
	} B;
    } MCS;
}; /* end of FCCU_tag */
/****************************************************************************/
/*          MODULE : FEC (Fast Ethernet Controller)                         */
/****************************************************************************/
struct FEC_tag {
    vuint8_t FEC_reserved0[3]; /*Reserved 3 bytes (Base+0x0000-0x0003)*/
    union { /* FEC Interrupt Event (Base+0x0004) */
        vuint32_t R;
        struct {
            vuint32_t HBERR:1;
            vuint32_t BABR:1;
            vuint32_t BABT:1;
            vuint32_t GRA:1;
            vuint32_t TXF:1;
            vuint32_t TXB:1;
            vuint32_t RXF:1;
            vuint32_t RXB:1;
            vuint32_t MII:1;
            vuint32_t EBERR:1;
            vuint32_t LC:1;
            vuint32_t RL:1;
            vuint32_t UN:1;
            vuint32_t:19;
        } B;
    } EIR;
    union { /*  Interrupt Mask (Base+0x0008)  */
        vuint32_t R;
        struct {
            vuint32_t HBERR:1;
            vuint32_t BABR:1;
            vuint32_t BABT:1;
            vuint32_t GRA:1;
            vuint32_t TXF:1;
            vuint32_t TXB:1;
            vuint32_t RXF:1;
            vuint32_t RXB:1;
            vuint32_t MII:1;
            vuint32_t EBERR:1;
            vuint32_t LC:1;
            vuint32_t RL:1;
            vuint32_t UN:1;
            vuint32_t:19;
        } B;
    } EIMR;
    vuint8_t FEC_reserved1[4]; /* Reserved 4 Bytes (Base+0x000C-0x000F) */
    union { /*  FEC Receive Descriptor Active (Base+0x0010) */
        vuint32_t R;
        struct {
            vuint32_t:7;
            vuint32_t R_DES_ACTIVE:1;
            vuint32_t:24;
        } B;
    } RDAR;
    union { /*  FEC TX Descriptor Active (Base+0x0014)  */
        vuint32_t R;
        struct {
            vuint32_t:7;
            vuint32_t X_DES_ACTIVE:1;
            vuint32_t:24;
        } B;
    } TDAR;
    vuint8_t FEC_reserved2[12]; /* Reserved 12 Bytes (Base+0x0018-0x0023) */
    union { /*  FEC Ethernet Control (Base+0x0024) */
        vuint32_t R;
        struct {
            vuint32_t:30;
            vuint32_t ETHER_EN:1;
            vuint32_t RESET:1;
        } B;
    } ECR;
    vuint8_t FEC_reserved3[24]; /* Reserved 24 Bytes (Base+0x0028-0x003F) */
    union { /* FEC Management Frame (Base+0x0040) */
        vuint32_t R;
        struct {
            vuint32_t ST:2;
            vuint32_t OP:2;
            vuint32_t PA:5;
            vuint32_t RA:5;
            vuint32_t TA:2;
            vuint32_t DATA:16;
        } B;
    } MMFR;
    union { /* FEC MII Speed Control (Base+0x0044) */
        vuint32_t R;
        struct {
            vuint32_t:24;
            vuint32_t DIS_PREAMBLE:1;
            vuint32_t MII_SPEED:6;
            vuint32_t:1;
        } B;
    } MSCR;
    vuint8_t FEC_reserved4[28]; /* Reserved 28 Bytes (Base+0x0048-0x0063) */
    union { /* FEC MIB Control (Base+0x0064) */
        vuint32_t R;
        struct {
            vuint32_t MIB_DISABLE:1;
            vuint32_t MIB_IDLE:1;
            vuint32_t:30;
        } B;
    } MIBC;
    vuint8_t FEC_reserved5[28]; /* Reserved 28 Bytes (Base+0x0068-0x0083) */
    union { /* FEC Receive Control (Base+0x0084) */
        vuint32_t R;
        struct {
            vuint32_t:5;
            vuint32_t MAX_FL:11;
            vuint32_t:10;
            vuint32_t FCE:1;
            vuint32_t BC_REJ:1;
            vuint32_t PROM:1;
            vuint32_t MII_MODE:1;
            vuint32_t DRT:1;
            vuint32_t LOOP:1;
        } B;
    } RCR;
    vuint8_t FEC_reserved6[60]; /* Reserved 60 Bytes (Base+0x0088-0x00C3) */
    union { /* FEC Transmit Control (Base+0x00C4) */
        vuint32_t R;
        struct {
            vuint32_t:27;
            vuint32_t RFC_PAUSE:1;
            vuint32_t TFC_PAUSE:1;
            vuint32_t FDEN:1;
            vuint32_t HBC:1;
            vuint32_t GTS:1;
        } B;
    } TCR;
    vuint8_t FEC_reserved7[28]; /* Reserved 28 Bytes (Base+0x00C8-0x00E3) */
    union { /* FEC Physical Address Low (Base+0x00E4) */
        vuint32_t R;
        struct {
            vuint32_t PADDR1:32;
        } B;
    } PALR;
    union { /* FEC Physical Address High (Base+0x00E8) */
        vuint32_t R;
        struct {
            vuint32_t PADDR2:16;
            vuint32_t TYPE:16;
        } B;
    } PAUR;
    union { /* Opcode/Pause Duration (Base+0x00EC) */
        vuint32_t R;
        struct {
            vuint32_t OPCODE:16;
            vuint32_t PAUSE_DUR:16;
        } B;
    } OPD;
    vuint8_t FEC_reserved8[40]; /* Reserved 40 Bytes (Base+0x00F0-0x0117) */
    union { /*FEC Descriptor Individual Upper Addr (+0x0118)*/
        vuint32_t R;
        struct {
	    vuint32_t IADDR1:32;
        } B;
    } IAUR;
    union { /*FEC Descriptor Individual Lower Addr (+0x011C)*/
        vuint32_t R;
        struct {
            vuint32_t IADDR2:32;
        } B;
    } IALR;
    union { /* FEC Descriptor Group Upper Addr (Base+0x0120)*/
        vuint32_t R;
        struct {
            vuint32_t GADDR1:32;
        } B;
    } GAUR;
    union { /* FEC Descriptor Group Lower Addr (Base+0x0124)*/
        vuint32_t R;
        struct {
            vuint32_t GADDR2:32;
        } B;
    } GALR;
    vuint8_t FEC_reserved9[28]; /* Reserved 28 Bytes (Base+0x0128-0x0143) */
    union { /* FEC FIFO Transmit FIFO Watermark (+0x0144) */
        vuint32_t R;
        struct {
            vuint32_t:30;
            vuint32_t X_WMRK:2;
        } B;
    } TFWR;
    vuint8_t FEC_reserved10[4]; /* Reserved 4 Bytes (Base+0x0148-0x014B) */
    union { /* FEC FIFO Receive Bound (Base+0x014C) */
        vuint32_t R;
        struct {
            vuint32_t:22;
            vuint32_t R_BOUND:8;
            vuint32_t:2;
        } B;
    } FRBR;
    union { /* FEC FIFO Receive FIFO Start (Base+0x0150) */
        vuint32_t R;
        struct {
            vuint32_t:22;
            vuint32_t R_FSTART:8;
            vuint32_t:2;
        } B;
    } FRSR;
    vuint8_t FEC_reserved11[44]; /* Reserved 44 Bytes (Base+0x0154-0x017F) */
    union { /* FEC Receive Descriptor Ring Start (+0x0180) */
        vuint32_t R;
        struct {
            vuint32_t R_DES_START:30;
            vuint32_t:2;
        } B;
    } ERDSR;
    union { /* FEC Transmit Descriptor Ring Start (+0x0184) */
        vuint32_t R;
        struct {
            vuint32_t X_DES_START:30;
            vuint32_t:2;
        } B;
    } ETDSR;
    union { /* FEC Max Receive Buffer Size (Base+0x0188) */
        vuint32_t R;
        struct {
            vuint32_t:21;
            vuint32_t R_BUF_SIZE:7;
            vuint32_t:4;
        } B;
    } EMRBR;
    vuint8_t FEC_reserved12[116]; /*Reserved 116 Bytes (Base+0x018C-0x01FF) */
    /* --- FEC MIB Counters Registers Below (Base+0x200) --- */
    union { /* MIB Count frames not counted correctly (Base+0x200)*/
        vuint32_t R;
    } RMON_T_DROP;
    union { /* MIB RMON Tx packet count (Base+0x204) */
        vuint32_t R;
    } RMON_T_PACKETS;
    union { /* MIB RMON Tx Broadcast Packets (Base+0x208) */
        vuint32_t R;
    } RMON_T_BC_PKT;
    union { /* MIB RMON Tx Multicast Packets (Base+0x20C) */
        vuint32_t R;
    } RMON_T_MC_PKT;
    union { /* MIB RMON Tx Packets w CRC/Align err (+0x210)*/
        vuint32_t R;
    } RMON_T_CRC_ALIGN;
    union { /* MIB RMON Tx Packets < 64 bytes, good crc (+0x214)*/
        vuint32_t R;
    } RMON_T_UNDERSIZE;
    union { /* RMON Tx Packets > MAX_FL bytes, good crc (+0x218) */
        vuint32_t R;
    } RMON_T_OVERSIZE;
    union { /* MIB RMON Tx Packets < 64 bytes, bad crc (+0x21C) */
        vuint32_t R;
    } RMON_T_FRAG;
    union { /* MIB RMON Tx Packets > MAX_FL bytes, bad crc (+0x220) */
        vuint32_t R;
    } RMON_T_JAB;
    union { /* MIB RMON Tx collision count (Base+0x224)*/
        vuint32_t R;
    } RMON_T_COL;
    union { /* MIB RMON Tx 64 byte packets (Base+0x228) */
        vuint32_t R;
    } RMON_T_P64;
    union { /* MIB RMON Tx 65 to 127 byte packets (+0x22C) */
        vuint32_t R;
    } RMON_T_P65TO127;
    union { /* MIB RMON Tx 128 to 255 byte packets (+0x230)*/
        vuint32_t R;
    } RMON_T_P128TO255;
    union { /* MIB RMON Tx 256 to 511 byte packets (+0x234)*/
        vuint32_t R;
    } RMON_T_P256TO511;
    union { /* MIB RMON Tx 512 to 1023 byte packets (+0x238)*/
        vuint32_t R;
    } RMON_T_P512TO1023;
    union { /* MIB RMON Tx 1024 to 2047 byte packets (+0x23C)*/
        vuint32_t R;
    } RMON_T_P1024TO2047;
    union { /* MIB RMON Tx packets w > 2048 bytes (+0x240) */
        vuint32_t R;
    } RMON_T_P_GTE2048;
    union { /* MIB RMON Tx Octets (Base+0x244) */
        vuint32_t R;
    } RMON_T_OCTETS;
    union { /* MIB Count of frames not counted correct (+0x248)*/
        vuint32_t R;
    } IEEE_T_DROP;
    union { /* MIB Frames Transmitted OK  (Base+24C) */
        vuint32_t R;
    } IEEE_T_FRAME_OK;
    union { /* MIB Frames Tx'd with Single Collision (+0x250)*/
        vuint32_t R;
    } IEEE_T_1COL;
    union { /* MIB Frames Tx'd with mult Collision (+0x254)*/
        vuint32_t R;
    } IEEE_T_MCOL;
    union { /* MIB Frames Tx'd after Deferral Delay (+0x258)*/
        vuint32_t R;
    } IEEE_T_DEF;
    union { /* MIB Frames Tx'd with Late Collision (+0x25C)*/
        vuint32_t R;
    } IEEE_T_LCOL;
    union { /* MIB Frames Tx'd with Excessive Collisions (+0x260)*/
        vuint32_t R;
    } IEEE_T_EXCOL;
    union { /* MIB Frames Tx'd with Tx FIFO Underrun (+0x264)*/
        vuint32_t R;
    } IEEE_T_MACERR;
    union { /* MIB Frames Tx'd with Carrier Sense Error (+0x268) */
        vuint32_t R;
    } IEEE_T_CSERR;
    union { /* MIB Frames Tx'd with SQE Error (Base+0x26C) */
        vuint32_t R;
    } IEEE_T_SQE;
    union { /* MIB Flow Control Pause frames tx'd (+0x270) */
        vuint32_t R;
    } IEEE_T_FDXFC;
    union { /* MIB Octet count for Frames Tx'd w/o Error (+0x274)*/
        vuint32_t R;
    } IEEE_T_OCTETS_OK;
    vuint8_t FEC_reserved13[8]; /*Reserved 12 Bytes (Base+0x278-0x27F) */
    union { /* MIB RMON # frames not counted correct (+0x280) */
        vuint32_t R;
    } RMON_R_DROP;
    union { /* MIB RMON Rx packet count (Base+0x284) */
        vuint32_t R;
    } RMON_R_PACKETS;
    union { /* MIB RMON Rx Broadcast Packets (Base+0x288) */
        vuint32_t R;
    } RMON_R_BC_PKT;
    union { /* MIB RMON Rx Multicast Packets (Base+0x28C) */
        vuint32_t R;
    } RMON_R_MC_PKT;
    union { /* MIB RMON Rx Packets w CRC/Align error (+0x290)*/
        vuint32_t R;
    } RMON_R_CRC_ALIGN;
    union { /* MIB RMON Rx Packets < 64 bytes, good crc (+0x294)*/
        vuint32_t R;
    } RMON_R_UNDERSIZE;
    union { /* MIB RMON Rx Packets > MAX_FL bytes, good crc (+0x298)*/
        vuint32_t R;
    } RMON_R_OVERSIZE;
    union { /* MIB RMON Rx Packets < 64 bytes, bad crc (+0x29C)*/
        vuint32_t R;
    } RMON_R_FRAG;
    union { /* MIB RMON Rx Packets > MAX_FL bytes, bad crc (0x2A0)*/
        vuint32_t R;
    } RMON_R_JAB;
    vuint8_t FEC_reserved14[4]; /*Reserved 4 Bytes (Base+0x2A4-0x2A7) */
    union { /* MIB RMON Rx 64 byte packets (Base+0x2A8) */
        vuint32_t R;
    } RMON_R_P64;
    union { /* MIB RMON Rx 65 to 127 byte packets (+0x2AC) */
        vuint32_t R;
    } RMON_R_P65TO127;
    union { /* MIB RMON Rx 128 to 255 byte packets (+0x2B0)*/
        vuint32_t R;
    } RMON_R_P128TO255;
    union { /* MIB RMON Rx 256 to 511 byte packets (+0x2B4)*/
        vuint32_t R;
    } RMON_R_P256TO511;
    union { /* MIB RMON Rx 512 to 1023 byte packets (+0x2B8)*/
        vuint32_t R;
    } RMON_R_P512TO1023;
    union { /* MIB RMON Rx 1024 to 2047 byte packets (+0x2BC)*/
        vuint32_t R;
    } RMON_R_P1024TO2047;
    union { /* MIB RMON Rx packets w > 2048 bytes (+0x2C0) */
        vuint32_t R;
    } RMON_R_P_GTE2048;
    union { /* MIB RMON Rx Octets (Base+0x2C4) */
        vuint32_t R;
    } RMON_R_OCTETS;
    union { /* MIB Count of frames not counted correctly (+0x2C8)*/
        vuint32_t R;
    } IEEE_R_DROP;
    union { /* MIB Frames Received OK (Base+0x2CC) */
        vuint32_t R;
    } IEEE_R_FRAME_OK;
    union { /* MIB Frames Received with CRC Error (+0x2D0) */
        vuint32_t R;
    } IEEE_R_CRC;
    union { /* MIB Frames Received Alignment Error (+0x2D4)*/
        vuint32_t R;
    } IEEE_R_ALIGN;
    union { /* MIB Receive Fifo Overflow count (+0x2D8) */
        vuint32_t R;
    } IEEE_R_MACERR;
    union { /* MIB Flow Control Pause frames Rx'd (+0x2DC) */
        vuint32_t R;
    } IEEE_R_FDXFC;
    union { /* MIB Octet count for Frames Rcvd w/o Error (+0x2E0)*/
        vuint32_t R;
    } IEEE_R_OCTETS_OK;
}; /* end of FEC_tag */
/****************************************************************************/
/*                          MODULE : FlexCAN                                */
/****************************************************************************/
struct FLEXCAN_BUF_t{
    union { /* FLEXCAN MBx Control & Status (Offset+0x0080) */
        vuint32_t R;
        struct {
            vuint32_t :4;
            vuint32_t CODE:4;
            vuint32_t :1;
            vuint32_t SRR:1;
            vuint32_t IDE:1;
            vuint32_t RTR:1;
            vuint32_t LENGTH:4;
            vuint32_t TIMESTAMP:16;
        } B;
    } CS;
    union { /* FLEXCAN MBx Identifier (Offset+0x0084) */
        vuint32_t R;
        struct {
            vuint32_t PRIO:3;
            vuint32_t STD_ID:11;
            vuint32_t EXT_ID:18;
        } B;
    } ID;
    union { /* FLEXCAN MBx Data 0..7 (Offset+0x0088) */
        vuint8_t B[8]; /* Data buffer in Bytes (8 bits) */
        vuint16_t H[4]; /* Data buffer in Half-words (16 bits) */
        vuint32_t W[2]; /* Data buffer in words (32 bits) */
        vuint32_t R[2]; /* Data buffer in words (32 bits) */
    } DATA;
}; /* end of FLEXCAN_BUF_t */
struct FLEXCAN_RXFIFO_t{ /* RxFIFO Configuration */
    union { /* RxFIFO Control & Status (Offset+0x0080) */
        vuint32_t R;
        struct {
            vuint32_t :9;
            vuint32_t SRR:1;
            vuint32_t IDE:1;
            vuint32_t RTR:1;
            vuint32_t LENGTH:4;
            vuint32_t TIMESTAMP:16;
        } B;
    } CS;
    union { /* RxFIFO Identifier (Offset+0x0084) */
        vuint32_t R;
        struct {
            vuint32_t :3;
            vuint32_t STD_ID:11;
            vuint32_t EXT_ID:18;
        } B;
    } ID;
    union { /* RxFIFO Data 0..7 (Offset+0x0088) */
        vuint8_t B[8]; /* Data buffer in Bytes (8 bits) */
        vuint16_t H[4]; /* Data buffer in Half-words (16 bits) */
        vuint32_t W[2]; /* Data buffer in words (32 bits) */
        vuint32_t R[2]; /* Data buffer in words (32 bits) */
    } DATA;
    vuint8_t FLEXCAN_RX_reserved0[80]; /* Reserved 80 bytes (+0x0090-0x00DF)*/
    union { /* RxFIFO ID Table 0..7 (+0x00E0-0x00FC) */
        vuint32_t R;
    } IDTABLE[8];
}; /* end of FLEXCAN_RXFIFO_t */

struct FLEXCAN_tag{
    union { /* FLEXCAN Module Configuration (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t MDIS:1;
            vuint32_t FRZ:1;
            vuint32_t FEN:1;
            vuint32_t HALT:1;
            vuint32_t NOT_RDY:1;
            vuint32_t :1;
            vuint32_t SOFT_RST:1;
            vuint32_t FRZ_ACK:1;
            vuint32_t SUPV:1;
            vuint32_t SLF_WAK:1;
            vuint32_t WRN_EN:1;
            vuint32_t LPM_ACK:1;
            vuint32_t WAK_SRC:1;
            vuint32_t :1;
            vuint32_t SRX_DIS:1;
            vuint32_t BCC:1;
            vuint32_t :2;
            vuint32_t LPRIO_EN:1;
            vuint32_t AEN:1;
            vuint32_t :2;
            vuint32_t IDAM:2;
            vuint32_t :2;
            vuint32_t MAXMB:6;
        } B;
    } MCR;
    union { /* FLEXCAN Control (Base+0x0004) */
        vuint32_t R;
        struct {
            vuint32_t PRESDIV:8;
            vuint32_t RJW:2;
            vuint32_t PSEG1:3;
            vuint32_t PSEG2:3;
            vuint32_t BOFF_MSK:1;
            vuint32_t ERR_MSK:1;
            vuint32_t CLK_SRC:1;
            vuint32_t LPB:1;
            vuint32_t TWRN_MSK:1;
            vuint32_t RWRN_MSK:1;
            vuint32_t :2;
            vuint32_t SMP:1;
            vuint32_t BOFF_REC:1;
            vuint32_t TSYN:1;
            vuint32_t LBUF:1;
            vuint32_t LOM:1;
            vuint32_t PROPSEG:3;
        } B;
    } CTRL;
    union { /* FLEXCAN Free Running Timer (Base+0x0008) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t TIMER:16;
        } B;
    } TIMER;
    vuint8_t FLEXCAN_reserved1[4]; /* reserved 4 bytes (Base+0x000C-0x000F) */
    union { /* FLEXCAN RX Global Mask (Base+0x0010) */
        vuint32_t R;
        struct {
            vuint32_t MI:32;
        } B;
    } RXGMASK;
    /*  --- Following 2 registers are included for legacy purposes only --- */
    union { /* FLEXCAN RX 14 Mask (Base+0x0014) */
        vuint32_t R;
        struct {
            vuint32_t MI:32;
        } B;
    } RX14MASK;
    union { /* FLEXCAN RX 15 Mask (Base+0x0018) */
        vuint32_t R;
        struct {
            vuint32_t MI:32;
        } B;
    } RX15MASK;
    /*  --- */
    union { /* FLEXCAN Error Counter (Base+0x001C) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t RX_ERR_COUNTER:8;
            vuint32_t TX_ERR_COUNTER:8;
        } B;
    } ECR;
    union { /* FLEXCAN Error & Status (Base+0x0020) */
        vuint32_t R;
        struct {
            vuint32_t :14;
            vuint32_t TWRN_INT:1;
            vuint32_t RWRN_INT:1;
            vuint32_t BIT1_ERR:1;
            vuint32_t BIT0_ERR:1;
            vuint32_t ACK_ERR:1;
            vuint32_t CRC_ERR:1;
            vuint32_t FRM_ERR:1;
            vuint32_t STF_ERR:1;
            vuint32_t TX_WRN:1;
            vuint32_t RX_WRN:1;
            vuint32_t IDLE:1;
            vuint32_t TXRX:1;
            vuint32_t FLT_CONF:2;
            vuint32_t :1;
            vuint32_t BOFF_INT:1;
            vuint32_t ERR_INT:1;
            vuint32_t WAK_INT:1;
        } B;
    } ESR;
    vuint8_t FLEXCAN_reserved2[4]; /* reserved 4 bytes (Base+0x0024) */
    union { /* FLEXCAN Interruput Masks H (Base+0x0024) */
        vuint32_t R;
        struct {
            vuint32_t BUF63M:1;
            vuint32_t BUF62M:1;
            vuint32_t BUF61M:1;
            vuint32_t BUF60M:1;
            vuint32_t BUF59M:1;
            vuint32_t BUF58M:1;
            vuint32_t BUF57M:1;
            vuint32_t BUF56M:1;
            vuint32_t BUF55M:1;
            vuint32_t BUF54M:1;
            vuint32_t BUF53M:1;
            vuint32_t BUF52M:1;
            vuint32_t BUF51M:1;
            vuint32_t BUF50M:1;
            vuint32_t BUF49M:1;
            vuint32_t BUF48M:1;
            vuint32_t BUF47M:1;
            vuint32_t BUF46M:1;
            vuint32_t BUF45M:1;
            vuint32_t BUF44M:1;
            vuint32_t BUF43M:1;
            vuint32_t BUF42M:1;
            vuint32_t BUF41M:1;
            vuint32_t BUF40M:1;
            vuint32_t BUF39M:1;
            vuint32_t BUF38M:1;
            vuint32_t BUF37M:1;
            vuint32_t BUF36M:1;
            vuint32_t BUF35M:1;
            vuint32_t BUF34M:1;
            vuint32_t BUF33M:1;
            vuint32_t BUF32M:1;
        } B;
    } IMASK1;
    union { /* FLEXCAN Interruput Masks L (Base+0x0028) */
        vuint32_t R;
        struct {
            vuint32_t BUF31M:1;
            vuint32_t BUF30M:1;
            vuint32_t BUF29M:1;
            vuint32_t BUF28M:1;
            vuint32_t BUF27M:1;
            vuint32_t BUF26M:1;
            vuint32_t BUF25M:1;
            vuint32_t BUF24M:1;
            vuint32_t BUF23M:1;
            vuint32_t BUF22M:1;
            vuint32_t BUF21M:1;
            vuint32_t BUF20M:1;
            vuint32_t BUF19M:1;
            vuint32_t BUF18M:1;
            vuint32_t BUF17M:1;
            vuint32_t BUF16M:1;
            vuint32_t BUF15M:1;
            vuint32_t BUF14M:1;
            vuint32_t BUF13M:1;
            vuint32_t BUF12M:1;
            vuint32_t BUF11M:1;
            vuint32_t BUF10M:1;
            vuint32_t BUF09M:1;
            vuint32_t BUF08M:1;
            vuint32_t BUF07M:1;
            vuint32_t BUF06M:1;
            vuint32_t BUF05M:1;
            vuint32_t BUF04M:1;
            vuint32_t BUF03M:1;
            vuint32_t BUF02M:1;
            vuint32_t BUF01M:1;
            vuint32_t BUF00M:1;
        } B;
    } IMASK2;
    union { /* FLEXCAN Interruput Flag H (Base+0x002C) */
        vuint32_t R;
        struct {
            vuint32_t BUF63I:1;
            vuint32_t BUF62I:1;
            vuint32_t BUF61I:1;
            vuint32_t BUF60I:1;
            vuint32_t BUF59I:1;
            vuint32_t BUF58I:1;
            vuint32_t BUF57I:1;
            vuint32_t BUF56I:1;
            vuint32_t BUF55I:1;
            vuint32_t BUF54I:1;
            vuint32_t BUF53I:1;
            vuint32_t BUF52I:1;
            vuint32_t BUF51I:1;
            vuint32_t BUF50I:1;
            vuint32_t BUF49I:1;
            vuint32_t BUF48I:1;
            vuint32_t BUF47I:1;
            vuint32_t BUF46I:1;
            vuint32_t BUF45I:1;
            vuint32_t BUF44I:1;
            vuint32_t BUF43I:1;
            vuint32_t BUF42I:1;
            vuint32_t BUF41I:1;
            vuint32_t BUF40I:1;
            vuint32_t BUF39I:1;
            vuint32_t BUF38I:1;
            vuint32_t BUF37I:1;
            vuint32_t BUF36I:1;
            vuint32_t BUF35I:1;
            vuint32_t BUF34I:1;
            vuint32_t BUF33I:1;
            vuint32_t BUF32I:1;
        } B;
    } IFLAG1;
    union { /* FLEXCAN Interruput Flag l (Base+0x0030) */
        vuint32_t R;
        struct {
            vuint32_t BUF31I:1;
            vuint32_t BUF30I:1;
            vuint32_t BUF29I:1;
            vuint32_t BUF28I:1;
            vuint32_t BUF27I:1;
            vuint32_t BUF26I:1;
            vuint32_t BUF25I:1;
            vuint32_t BUF24I:1;
            vuint32_t BUF23I:1;
            vuint32_t BUF22I:1;
            vuint32_t BUF21I:1;
            vuint32_t BUF20I:1;
            vuint32_t BUF19I:1;
            vuint32_t BUF18I:1;
            vuint32_t BUF17I:1;
            vuint32_t BUF16I:1;
            vuint32_t BUF15I:1;
            vuint32_t BUF14I:1;
            vuint32_t BUF13I:1;
            vuint32_t BUF12I:1;
            vuint32_t BUF11I:1;
            vuint32_t BUF10I:1;
            vuint32_t BUF09I:1;
            vuint32_t BUF08I:1;
            vuint32_t BUF07I:1;
            vuint32_t BUF06I:1;
            vuint32_t BUF05I:1;
            vuint32_t BUF04I:1;
            vuint32_t BUF03I:1;
            vuint32_t BUF02I:1;
            vuint32_t BUF01I:1;
            vuint32_t BUF00I:1;
        } B;
    } IFLAG2; /* Interruput Flag Register */
    vuint8_t FLEXCAN_reserved3[76]; /*Reserved 76 bytes (Base+0x0034-0x007F)*/
/****************************************************************************/
/* Use either Standard Buffer Structure OR RX FIFO and Buffer Structure     */
/****************************************************************************/
    /* Standard Buffer Structure */
    struct FLEXCAN_BUF_t BUF[64];
    /* RX FIFO and Buffer Structure */
    /*struct FLEXCAN_RXFIFO_t RXFIFO; */
    /*struct FLEXCAN_BUF_t BUF[56];   */
/****************************************************************************/
    vuint8_t FLEXCAN_reserved4[1024]; /*Reserved 1024 (Base+0x0480-0x087F)*/
    union { /* FLEXCAN RX Individual Mask (Base+0x0880-0x097F) */
        vuint32_t R;
        struct {
	    vuint32_t MI:32;
        } B;
    } RXIMR[64];
}; /* end of FLEXCAN_tag */
/****************************************************************************/
/*                          MODULE : FLEXPWM                                   */
/****************************************************************************/
struct FLEXPWM_SUB_tag {
    union {
	vuint16_t R;
    } CNT; /* Counter Register */
    union {
	vuint16_t R;
    } INIT; /* Initial Count Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t DBGEN:1;
	    vuint16_t WAITEN:1;
	    vuint16_t INDEP:1;
	    vuint16_t PWMA_INIT:1;
	    vuint16_t PWMB_INIT:1;
	    vuint16_t PWMX_INIT:1;
	    vuint16_t INIT_SEL:2;
	    vuint16_t FRCEN:1;
	    vuint16_t FORCE:1;
	    vuint16_t FORCE_SEL:3;
	    vuint16_t RELOAD_SEL:1;
	    vuint16_t CLK_SEL:2;
	} B;
    } CTRL2; /* Control 2 Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t LDFQ:4;
	    vuint16_t HALF:1;
	    vuint16_t FULL:1;
	    vuint16_t DT:2;
	    vuint16_t:1;
	    vuint16_t PRSC:3;
	    vuint16_t:3;
	    vuint16_t DBLEN:1;
	} B;
    } CTRL; /* Control Register */
    union {
	vuint16_t R;
    } VAL[6]; /* Value Register 0->5 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t FRACAEN:1;
	    vuint16_t:10;
	    vuint16_t FRACADLY:5;
	} B;
    } FRACA; /* Fractional Delay Register A */
    union {
	vuint16_t R;
	struct {
	    vuint16_t FRACBEN:1;
	    vuint16_t:10;
	    vuint16_t FRACBDLY:5;
	} B;
    } FRACB; /* Fractional Delay Register B */
    union {
	vuint16_t R;
	struct {
	    vuint16_t PWMA_IN:1;
	    vuint16_t PWMB_IN:1;
	    vuint16_t PWMX_IN:1;
	    vuint16_t:2;
	    vuint16_t POLA:1;
	    vuint16_t POLB:1;
	    vuint16_t POLX:1;
	    vuint16_t:2;
	    vuint16_t PWMAFS:2;
	    vuint16_t PWMBFS:2;
	    vuint16_t PWMXFS:2;
	} B;
    } OCTRL; /* Output Control Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:1;
	    vuint16_t RUF:1;
	    vuint16_t REF:1;
	    vuint16_t RF:1;
	    vuint16_t CFA1:1;
	    vuint16_t CFA0:1;
	    vuint16_t CFB1:1;
	    vuint16_t CFB0:1;
	    vuint16_t CFX1:1;
	    vuint16_t CFX0:1;
	    vuint16_t CMPF:6;
	} B;
    } STS; /* Status Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:2;
	    vuint16_t REIE:1;
	    vuint16_t RIE:1;
	    vuint16_t:4;
	    vuint16_t CX1IE:1;
	    vuint16_t CX0IE:1;
	    vuint16_t CMPIE:6;
	} B;
    } INTEN; /* Interrupt Enable Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:6;
	    vuint16_t VALDE:1;
	    vuint16_t FAND:1;
	    vuint16_t CAPTDE:2;
	    vuint16_t CA1DE:1;
	    vuint16_t CA0DE:1;
	    vuint16_t CB1DE:1;
	    vuint16_t CB0DE:1;
	    vuint16_t CX1DE:1;
	    vuint16_t CX0DE:1;
	} B;
    } DMAEN; /* DMA Enable Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:10;
	    vuint16_t OUT_TRIG_EN:6;
	} B;
    } TCTRL; /* Output Trigger Control Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:4;
	    vuint16_t DISX:4;
	    vuint16_t DISB:4;
	    vuint16_t DISA:4;
	} B;
    } DISMAP; /* Fault Disable Mapping Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:5;
	    vuint16_t DTCNT0:11;
	} B;
    } DTCNT0; /* Deadtime Count Register 0 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:5;
	    vuint16_t DTCNT1:11;
	} B;
    } DTCNT1; /* Deadtime Count Register 1 */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CA1CNT:3;
	    vuint16_t CA0CNT:3;
	    vuint16_t CFAWM:2;
	    vuint16_t EDGCNTAEN:1;
	    vuint16_t INPSELA:1;
	    vuint16_t EDGA1:2;
	    vuint16_t EDGA0:2;
	    vuint16_t ONESHOTA:1;
	    vuint16_t ARMA:1;
	} B;
    } CAPTCTRLA; /* Capture Control Register A */
    union {
	vuint16_t R;
	struct {
	    vuint16_t EDGCNTA:8;
	    vuint16_t EDGCMPA:8;
	} B;
    } CAPTCOMPA; /* Capture Compare Register A */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CB1CNT:3;
	    vuint16_t CB0CNT:3;
	    vuint16_t CFBWM:2;
	    vuint16_t EDGCNTBEN:1;
	    vuint16_t INPSELB:1;
	    vuint16_t EDGB1:2;
	    vuint16_t EDGB0:2;
	    vuint16_t ONESHOTB:1;
	    vuint16_t ARMB:1;
	} B;
    } CAPTCTRLB; /* Capture Control Register B */
    union {
	vuint16_t R;
	struct {
	    vuint16_t EDGCNTB:8;
	    vuint16_t EDGCMPB:8;
	} B;
    } CAPTCOMPB; /* Capture Compare Register B */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CX1CNT:3;
	    vuint16_t CX0CNT:3;
	    vuint16_t CFXWM:2;
	    vuint16_t EDGCNTX_EN:1;
	    vuint16_t INP_SELX:1;
	    vuint16_t EDGX1:2;
	    vuint16_t EDGX0:2;
	    vuint16_t ONESHOTX:1;
	    vuint16_t ARMX:1;
	} B;
    } CAPTCTRLX; /* Capture Control Register B */
    union {
	vuint16_t R;
	struct {
	    vuint16_t EDGCNTX:8;
	    vuint16_t EDGCMPX:8;
	} B;
    } CAPTCOMPX; /* Capture Compare Register X */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CAPTVAL0:16;
	} B;
    } CVAL0; /* Capture Value 0 Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:12;
	    vuint16_t CVAL0CYC:4;
	} B;
    } CVAL0C; /* Capture Value 0 Cycle Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CAPTVAL1:16;
	} B;
    } CVAL1; /* Capture Value 1 Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:12;
	    vuint16_t CVAL1CYC:4;
	} B;
    } CVAL1C; /* Capture Value 1 Cycle Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CAPTVAL2:16;
	} B;
    } CVAL2; /* Capture Value 2 Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:12;
	    vuint16_t CVAL2CYC:4;
	} B;
    } CVAL2C; /* Capture Value 2 Cycle Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CAPTVAL3:16;
	} B;
    } CVAL3; /* Capture Value 3 Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:12;
	    vuint16_t CVAL3CYC:4;
	} B;
    } CVAL3C; /* Capture Value 3 Cycle Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CAPTVAL4:16;
	} B;
    } CVAL4; /* Capture Value 4 Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:12;
	    vuint16_t CVAL4CYC:4;
	} B;
    } CVAL4C; /* Capture Value 4 Cycle Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t CAPTVAL5:16;
	} B;
    } CVAL5; /* Capture Value 5 Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:12;
	    vuint16_t CVAL5CYC:4;
	} B;
    } CVAL5C; /* Capture Value 5 Cycle Register */
    uint32_t FLEXPWM_reserved0[1]; /* (0x04A - 0x050)/4 = 0x01 */
}; /* end of FLEXPWM_SUB_tag */

struct FLEXPWM_tag {
    /* eg. FLEXPWM.SUB<[x]>.CNT.R  {x = 0->3} */
    struct FLEXPWM_SUB_tag SUB[4];
    union {
	vuint16_t R;
	struct {
	    vuint16_t:4;
	    vuint16_t PWMA_EN:4;
	    vuint16_t PWMB_EN:4;
	    vuint16_t PWMX_EN:4;
	} B;
    } OUTEN; /* Output Enable Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:4;
	    vuint16_t MASKA:4;
	    vuint16_t MASKB:4;
	    vuint16_t MASKX:4;
	} B;
    } MASK; /* Output Mask Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:8;
	    vuint16_t OUTA_3:1;
	    vuint16_t OUTB_3:1;
	    vuint16_t OUTA_2:1;
	    vuint16_t OUTB_2:1;
	    vuint16_t OUTA_1:1;
	    vuint16_t OUTB_1:1;
	    vuint16_t OUTA_0:1;
	    vuint16_t OUTB_0:1;
	} B;
    } SWCOUT; /* Software Controlled Output Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t SELA_3:2;
	    vuint16_t SELB_3:2;
	    vuint16_t SELA_2:2;
	    vuint16_t SELB_2:2;
	    vuint16_t SELA_1:2;
	    vuint16_t SELB_1:2;
	    vuint16_t SELA_0:2;
	    vuint16_t SELB_0:2;
	} B;
    } DTSRCSEL; /* Deadtime Source Select Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t IPOL:4;
	    vuint16_t RUN:4;
	    vuint16_t CLDOK:4;
	    vuint16_t LDOK:4;
	} B;
    } MCTRL; /* Master Control Register */
    int16_t FLEXPWM_reserved1[1];
    union {
	vuint16_t R;
	struct {
	    vuint16_t FLVL:4;
	    vuint16_t FAUTO:4;
	    vuint16_t FSAFE:4;
	    vuint16_t FIE:4;
	} B;
    } FCTRL; /* Fault Control Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:3;
	    vuint16_t FTEST:1;
	    vuint16_t FFPIN:4;
	    vuint16_t:4;
	    vuint16_t FFLAG:4;
	} B;
    } FSTS; /* Fault Status Register */
    union {
	vuint16_t R;
	struct {
	    vuint16_t:5;
	    vuint16_t FILT_CNT:3;
	    vuint16_t FILT_PER:8;
	} B;
    } FFILT; /* Fault FilterRegister */
}; /* end of FLEXPWM_tag */
/****************************************************************************/
/*                          MODULE : I2C                                    */
/****************************************************************************/
struct I2C_tag{
    union { /* I2C Bus Address (Base+0x0000) */
        vuint8_t R;
        struct {
            vuint8_t ADR:7;
            vuint8_t :1;
        } B;
    } IBAD;
    union { /* I2C Bus Frequency Divider (Base+0x0001) */
        vuint8_t R;
        struct {
            vuint8_t MULT:2;
	    vuint8_t ICR:6;
        } B;
    } IBFD;
    union { /* I2C Bus Control (Base+0x0002) */
        vuint8_t R;
        struct {
            vuint8_t MDIS:1;
            vuint8_t IBIE:1;
            vuint8_t MS:1;
            vuint8_t TX:1;
            vuint8_t NOACK:1;
            vuint8_t RSTA:1;
            vuint8_t DMAEN:1;
            vuint8_t IBDOZE:1;
        } B;
    } IBCR;
    union { /* I2C Bus Status (Base+0x0003) */
        vuint8_t R;
        struct {
            vuint8_t TCF:1;
            vuint8_t IAAS:1;
            vuint8_t IBB:1;
            vuint8_t IBAL:1;
            vuint8_t :1;
            vuint8_t SRW:1;
            vuint8_t IBIF:1;
            vuint8_t RXAK:1;
        } B;
    } IBSR;
    union { /* I2C Bus Data I/O (Base+0x0004) */
        vuint8_t R;
        struct {
            vuint8_t DATA:8;
        } B;
    } IBDR;
    union { /* I2C Interrupt Configuration (Base+0x0005) */
        vuint8_t R;
        struct {
            vuint8_t BIIE:1;
            vuint8_t :7;
        } B;
    } IBIC;
    vuint8_t I2C_reserved0[16378]; /* Reserved 16378 (Base+0x0006-0x3FFF) */
}; /* end of i2c_tag */
/*************************************************************************/
/*                          MODULE : INTC                                */
/*************************************************************************/
struct INTC_tag {
    union { /* INTC Module Configuration (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t:18;
            vuint32_t VTES_PRC1:1;
            vuint32_t:4;
            vuint32_t HVEN_PRC1:1;
            vuint32_t:2;
            vuint32_t VTES_PRC0:1;
            vuint32_t:4;
            vuint32_t HVEN_PRC0:1;
        } B;
    } BCR;
    vuint8_t INTC_reserved0[4]; /* reserved 4 bytes (Base+0x0004-0x0007) */
    union { /* INTC Current Priority Proc0 (Z7) (Base+0x0008) */
        vuint32_t R;
        struct {
            vuint32_t:28;
            vuint32_t PRI:4;
        } B;
    } CPR_PRC0;
    union { /* INTC Current Priority Proc1 (Z7) (Base+0x000C) */
        vuint32_t R;
        struct {
            vuint32_t:28;
            vuint32_t PRI:4;
        } B;
    } CPR_PRC1;
    union { /* INTC Interrupt Acknowledge Proc0 (Z7) (Base+0x0010) */
        vuint32_t R;
        struct {
            vuint32_t VTBA_PRC0:21;
            vuint32_t INTVEC_PRC0:9;
            vuint32_t:2;
        } B;
    } IACKR_PRC0;
    union { /* INTC Interrupt Acknowledge Proc1 (Z7) (Base+0x0014) */
        vuint32_t R;
        struct {
            vuint32_t VTBA_PRC1:21;
            vuint32_t INTVEC_PRC1:9;
            vuint32_t:2;
        } B;
    } IACKR_PRC1;
    union { /* INTC End Of Interrupt Proc0 (Z7) (Base+0x0018) */
        vuint32_t R;
        struct {
            vuint32_t:32;
        } B;
    } EOIR_PRC0;
    union { /* INTC End Of Interrupt Proc1 (Z7) (Base+0x001C) */
        vuint32_t R;
        struct {
            vuint32_t:32;
        } B;
    } EOIR_PRC1;
    union { /* INTC Software Set/Clear Interrupt0-7 (+0x0020-0x0027) */
        vuint8_t R;
        struct {
            vuint8_t:6;
            vuint8_t SET:1;
            vuint8_t CLR:1;
        } B;
    } SSCIR[8];
    vuint8_t INTC_reserved1[24]; /* Reserved 24 bytes (Base+0x0028-0x003F) */
    union { /* INTC Priority Select (Base+0x0040-0x0190) */
        vuint8_t R;
        struct {
            vuint8_t:4;
            vuint8_t PRI:4;
        } B;
    } PSR[336];
}; /* end of INTC_tag */
/****************************************************************************/
/*                          MODULE : LINFLEX                                */
/****************************************************************************/
struct LINFLEX_tag {
    union { /* LINFLEX LIN Control 1 (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CCD:1;
            vuint32_t CFD:1;
            vuint32_t LASE:1;
            vuint32_t AWUM:1;
            vuint32_t MBL:4;
            vuint32_t BF:1;
            vuint32_t SFTM:1;
            vuint32_t LBKM:1;
            vuint32_t MME:1;
            vuint32_t SBDT:1;
            vuint32_t RBLM:1;
            vuint32_t SLEEP:1;
            vuint32_t INIT:1;
        } B;
    } LINCR1;
    union { /* LINFLEX LIN Interrupt Enable (Base+0x0004) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t SZIE:1;
            vuint32_t OCIE:1;
            vuint32_t BEIE:1;
            vuint32_t CEIE:1;
            vuint32_t HEIE:1;
	    vuint32_t:2;
            vuint32_t FEIE:1;
            vuint32_t BOIE:1;
            vuint32_t LSIE:1;
            vuint32_t WUIE:1;
            vuint32_t DBFIE:1;
            vuint32_t DBEIE:1;
            vuint32_t DRIE:1;
            vuint32_t DTIE:1;
            vuint32_t HRIE:1;
        } B;
    } LINIER;
    union { /* LINFLEX LIN Status (Base+0x0008) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t LINS:4;
            vuint32_t:2;
            vuint32_t RMB:1;
            vuint32_t:1;
            vuint32_t RBSY:1;
            vuint32_t RPS:1;
            vuint32_t WUF:1;
            vuint32_t DBFF:1;
            vuint32_t DBEF:1;
            vuint32_t DRF:1;
            vuint32_t DTF:1;
            vuint32_t HRF:1;
        } B;
    } LINSR;
    union { /* LINFLEX LIN Error Status (Base+0x000C) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t SZF:1;
            vuint32_t OCF:1;
            vuint32_t BEF:1;
            vuint32_t CEF:1;
            vuint32_t SFEF:1;
            vuint32_t BDEF:1;
            vuint32_t IDPEF:1;
            vuint32_t FEF:1;
            vuint32_t BOF:1;
            vuint32_t:6;
            vuint32_t NF:1;
        } B;
    } LINESR;
    union { /* LINFLEX UART Mode Control (Base+0x0010) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t TDFLTFC:3;
            vuint32_t RDFLRFC:3;
	    vuint32_t RFBM:1;
	    vuint32_t TFBM:1;
	    vuint32_t WL1:1;
	    vuint32_t PC1:1;
            vuint32_t RXEN:1;
            vuint32_t TXEN:1;
            vuint32_t PC0:1;
            vuint32_t PCE:1;
            vuint32_t WL0:1;
            vuint32_t UART:1;
        } B;
    } UARTCR;
    union { /* LINFLEX UART Mode Status (Base+0x0014) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t SZF:1;
            vuint32_t OCF:1;
            vuint32_t PE3:1;
	    vuint32_t PE2:1;
	    vuint32_t PE1:1;
	    vuint32_t PE0:1;
            vuint32_t RMB:1;
            vuint32_t FEF:1;
            vuint32_t BOF:1;
            vuint32_t RPS:1;
            vuint32_t WUF:1;
            vuint32_t:1;
	    vuint32_t TO:1;
            vuint32_t DRFRFE:1;
            vuint32_t DTFTFF:1;
            vuint32_t NF:1;
        } B;
    } UARTSR;
    union { /* LINFLEX TimeOut Control Status ((Base+0x0018)*/
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t:5;
            vuint32_t LTOM:1;
            vuint32_t IOT:1;
            vuint32_t TOCE:1;
            vuint32_t CNT:8;
        } B;
    } LINTCSR;
    union { /* LINFLEX LIN Output Compare (Base+0x001C) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t OC2:8;
            vuint32_t OC1:8;
        } B;
    } LINOCR;
    union { /* LINFLEX LIN Timeout Control (Base+0x0020) */
        vuint32_t R;
        struct {
            vuint32_t :20;
            vuint32_t RTO:4;
            vuint32_t:1;
            vuint32_t HTO:7;
        } B;
    } LINTOCR;
    union { /* LINFLEX LIN Fractional Baud Rate (+0x0024) */
        vuint32_t R;
        struct {
            vuint32_t:28;
            vuint32_t DIV_F:4;
        } B;
    } LINFBRR;
    union { /* LINFLEX LIN Integer Baud Rate (Base+0x0028) */
        vuint32_t R;
        struct {
            vuint32_t:12;
            vuint32_t DIV_M:20;
        } B;
    } LINIBRR;
    union { /* LINFLEX LIN Checksum Field (Base+0x002C) */
        vuint32_t R;
        struct {
            vuint32_t:24;
            vuint32_t CF:8;
        } B;
    } LINCFR;
    union { /* LINFLEX LIN Control 2 (Base+0x0030) */
        vuint32_t R;
        struct {
            vuint32_t:17;
            vuint32_t IOBE:1;
            vuint32_t IOPE:1;
            vuint32_t WURQ:1;
            vuint32_t DDRQ:1;
            vuint32_t DTRQ:1;
            vuint32_t ABRQ:1;
            vuint32_t HTRQ:1;
            vuint32_t:8;
        } B;
    } LINCR2;
    union { /* LINFLEX Buffer Identifier (Base+0x0034) */
        vuint32_t R;
        struct {
            vuint32_t:16;
            vuint32_t DFL:6;
            vuint32_t DIR:1;
            vuint32_t CCS:1;
            vuint32_t:2;
            vuint32_t ID:6;
        } B;
    } BIDR;
    union { /* LINFLEX Buffer Data LSB (Base+0x0038) */
        vuint32_t R;
        struct {
            vuint32_t DATA3:8;
            vuint32_t DATA2:8;
            vuint32_t DATA1:8;
            vuint32_t DATA0:8;
        } B;
    } BDRL;
    union { /* LINFLEX Buffer Data MSB (Base+0x003C */
        vuint32_t R;
        struct {
            vuint32_t DATA7:8;
            vuint32_t DATA6:8;
            vuint32_t DATA5:8;
            vuint32_t DATA4:8;
        } B;
    } BDRM;
    union { /* LINFLEX Identifier Filter Enable (+0x0040) */
        vuint32_t R;
        struct {
            vuint32_t:24;
            vuint32_t FACT:8;
        } B;
    } IFER;
    union { /* LINFL Identifier Filter Match Index (+0x0044)*/
        vuint32_t R;
        struct {
            vuint32_t:28;
            vuint32_t IFMI:4;
        } B;
    } IFMI;
    union { /* LINFLEX Identifier Filter Mode (Base+0x0048) */
        vuint32_t R;
        struct {
            vuint32_t:28;
            vuint32_t IFM:4;
        } B;
    } IFMR;
    union { /*Identifier Filter Control 0..15 (+0x004C-0x0088)*/
        vuint32_t R;
        struct {
	    vuint32_t:16;
	    vuint32_t:3;
            vuint32_t DFL:3;
            vuint32_t DIR:1;
            vuint32_t CCS:1;
            vuint32_t:2;
            vuint32_t ID:6;
        } B;
    } IFCR[16];
    union { /* Global Control Register (+0x008C)*/
        vuint32_t R;
        struct {
	    vuint32_t:26;
	    vuint32_t TDFBM:1;
            vuint32_t RDFBM:1;
            vuint32_t TDLIS:1;
            vuint32_t RDLIS:1;
            vuint32_t STOP:1;
            vuint32_t SR:1;
        } B;
    } GCR;
    union { /*UART Preset Timeout Register (+0x0090)*/
        vuint32_t R;
        struct {
	    vuint32_t:20;
            vuint32_t PTO:12;
        } B;
    } UARTPTO;
    union { /*UART Current Timeout Register (+0x0094)*/
        vuint32_t R;
        struct {
	    vuint32_t:20;
	    vuint32_t CTO:12;
        } B;
    } UARTCT0;
    union { /*DMA Tx Enable Register (+0x0098)*/
        vuint32_t R;
        struct {
	    vuint32_t:16;
	    vuint32_t DTE15:1;
	    vuint32_t DTE14:1;
	    vuint32_t DTE13:1;
	    vuint32_t DTE12:1;
	    vuint32_t DTE11:1;
	    vuint32_t DTE10:1;
	    vuint32_t DTE9:1;
	    vuint32_t DTE8:1;
	    vuint32_t DTE7:1;
	    vuint32_t DTE6:1;
	    vuint32_t DTE5:1;
	    vuint32_t DTE4:1;
	    vuint32_t DTE3:1;
	    vuint32_t DTE2:1;
	    vuint32_t DTE1:1;
	    vuint32_t DTE0:1;
	} B;
    } DMATXE;
    union { /*DMA Rx Enable Register (+0x009C)*/
        vuint32_t R;
        struct {
	    vuint32_t:16;
	    vuint32_t DRE15:1;
	    vuint32_t DRE14:1;
	    vuint32_t DRE13:1;
	    vuint32_t DRE12:1;
	    vuint32_t DRE11:1;
	    vuint32_t DRE10:1;
	    vuint32_t DRE9:1;
	    vuint32_t DRE8:1;
	    vuint32_t DRE7:1;
	    vuint32_t DRE6:1;
	    vuint32_t DRE5:1;
	    vuint32_t DRE4:1;
	    vuint32_t DRE3:1;
	    vuint32_t DRE2:1;
	    vuint32_t DRE1:1;
	    vuint32_t DRE0:1;
	} B;
    } DMARXE;
    vuint8_t LINFLEX_reserved[16288]; /*Reserved 16244 (Base+0x009C-0x3FFF) */
}; /* end of LINFLEX_tag */
/****************************************************************************/
/*                          MODULE : MDDRC                                  */
/****************************************************************************/
struct MDDRC_tag{
    union { /* NMI Status Flag Register  (Base+0x0000) */
        vuint32_t R;
        struct {
	    vuint32_t RST_B:1;
	    vuint32_t CKE:1;
	    vuint32_t CLKON:1;
	    vuint32_t CMDMODE:1;
	    vuint32_t DRAM_ROW_SELECT:3;
	    vuint32_t DRAM_BANK_SELECT:4;
	    vuint32_t READ_TEST:2;
	    vuint32_t SELFREFEN:1;
	    vuint32_t :1;
	    vuint32_t RDLY:4;
	    vuint32_t HALFDQSDLY:1;
	    vuint32_t QUARTDQSDLY:1;
	    vuint32_t WDLY:3;
	    vuint32_t EARLYODT:1;
	    vuint32_t ONDIETERMINATE:1;
	    vuint32_t FIFOOVOEND:1;
            vuint32_t FIFOUVPEND:1;
            vuint32_t :2;
            vuint32_t FIFOOVEN:1;
            vuint32_t FIFOUVEN:1;
        } B;
    } DDR_SYS_CONFIG;
    union { /* DDR Time Configuration Register 0 (Base+0x0004) */
        vuint32_t R;
        struct {
	    vuint32_t :2;
	    vuint32_t DRAM_REFRESH_TIME:14;
	    vuint32_t DRAM_COMMAND_TIME:8;
	    vuint32_t DRAM_BANK_PRE_TIME:8;
        } B;
    } DDR_TIME_CONFIG0;
    union { /* DDR Time Configuration Register 1 (Base+0x0008) */
        vuint32_t R;
        struct {
	    vuint32_t DRAM_TIME_RFC:6;
	    vuint32_t DRAM_TIME_WR1:5;
	    vuint32_t DRAM_TIME_WTR1:4;
	    vuint32_t DRAM_TIME_RRD:6;
	    vuint32_t DRAM_TIME_RC:6;
	    vuint32_t DRAM_TIME_RAS:5;
        } B;
    } DDR_TIME_CONFIG1;
    union { /* DDR Time Configuration Register 2 (Base+0x000C) */
        vuint32_t R;
        struct {
	    vuint32_t DRAM_TIME_RCD:4;
	    vuint32_t DRAM_TIME_FAW:5;
	    vuint32_t DRAM_TIME_RTW1:4;
	    vuint32_t DRAM_TIME_CCD:4;
	    vuint32_t DRAM_TIME_RTP:5;
	    vuint32_t DRAM_TIME_RP:5;
	    vuint32_t DRAM_TIME_RPA:5;
        } B;
    } DDR_TIME_CONFIG2;
    union { /* DDR Command Register (Base+0x0010) */
        vuint32_t R;
        struct {
	    vuint32_t :8;
	    vuint32_t DRAM_COMMAND:24;
        } B;
    } DDR_COMMAND;
    union { /* Compact Command Register (Base+0x0014) */
        vuint32_t R;
        struct {
	    vuint32_t :16;
	    vuint32_t DRAM_COMPACT_COMMAND:16;
        } B;
    } DDR_COMPACT_COMMAND;
    union { /* Enter/Exit Self-Refresh Register (Base+0x0018) */
        vuint32_t R;
        struct {
	    vuint32_t :16;
	    vuint32_t SELF_REFRESH_CMD:16;
        } B;
    } SELF_REFRESH_CMD[8];
    union { /* DQS Config Offset Count Register (Base+0x0038) */
        vuint32_t R;
        struct {
	    vuint32_t DQS_SLAVE_3:8;
	    vuint32_t DQS_SLAVE_2:8;
	    vuint32_t DQS_SLAVE_1:8;
	    vuint32_t DQS_SLAVE_0:8;
        } B;
    } DQS_CONFIG_OFFSET_COUNT;
    union { /* DQS Config Offset Time Register (Base+0x003C) */
        vuint32_t R;
        struct {
	    vuint32_t :2;
	    vuint32_t DQS_SLAVE_3:6;
	    vuint32_t :2;
	    vuint32_t DQS_SLAVE_2:6;
	    vuint32_t :2;
	    vuint32_t DQS_SLAVE_1:6;
	    vuint32_t :2;
	    vuint32_t DQS_SLAVE_0:6;
        } B;
    } DQS_CONFIG_TIME_COUNT;
    union { /* DQS Delay Status Register (Base+0x0040) */
        vuint32_t R;
        struct {
	    vuint32_t :4;
	    vuint32_t DQS_MASTER_2:12;
	    vuint32_t :4;
	    vuint32_t DQS_MASTER_1:12;
        } B;
    } DQS_DELAY_STATUS;
    union { /* DDR Auxiliary Configuration Register (Base+0x0044) */
        vuint32_t R;
        struct {
	    vuint32_t WDATA_INJECT:1;
	    vuint32_t LOOPBACK:1;
	    vuint32_t RDATA_COMPARE:1;
	    vuint32_t DQS_TIMING:2;
    	    vuint32_t DRIVE_DQS:1;
    	    vuint32_t INPUTS_ALWAYS_ON:1;
    	    vuint32_t DQS_LOW:1;
    	    vuint32_t :24;
        } B;
    } DQS_AUX_CONFIG;    
    int32_t MDDRC_reserved1[6]; /* (0x0048 - 0x0060)/4 = 0x08 */
    union { /* DQS Delay Status Register (Base+0x0040) */
        vuint32_t R;
        struct {
	    vuint32_t :8;
	    vuint32_t CONFIG_SDR:1;
	    vuint32_t CONFIGCAS3:1;
	    vuint32_t :8;
        } B;
    } DDR_EXTRA;
    int32_t MDDRC_reserved2[7]; /* (0x0064 - 0x0080)/4 = 0x07 */

    /*************** Priority Manager *******************/
    union { /* DPRIOMAN_CONFIG1 Register  (Base+0x0080) */
        vuint32_t R;
        struct {
	    vuint32_t :2;
	    vuint32_t LUTSEL4:2;
	    vuint32_t LUTSEL3:2;
	    vuint32_t LUTSEL2:2;
	    vuint32_t LUTSEL1:2;
	    vuint32_t LUTSEL0:2;
	    vuint32_t ACK_COUNT4:4;
	    vuint32_t ACK_COUNT3:4;
	    vuint32_t ACK_COUNT2:4;
	    vuint32_t ACK_COUNT1:4;
	    vuint32_t ACK_COUNT0:4;
        } B;
    } DPRIOMAN_CONFIG1;
    union { /* DPRIOMAN_CONFIG2 Register  (Base+0x0084) */
        vuint32_t R;
        struct {
	    vuint32_t :25;
	    vuint32_t CONGESTED:1;
	    vuint32_t :1;
	    vuint32_t ACK_SEL4:1;
	    vuint32_t ACK_SEL3:1;
	    vuint32_t ACK_SEL2:1;
	    vuint32_t ACK_SEL1:1;
	    vuint32_t ACK_SEL0:1;
        } B;
    } DPRIOMAN_CONFIG2;
    union { /* HIPRIO_CONFIG Register  (Base+0x0088) */
        vuint32_t R;
        struct {
	    vuint32_t SET_CONGEST_LEVEL:8;
	    vuint32_t CLEAR_CONGEST_LEVEL:8;
	    vuint32_t FILTERBANDWIDTH:3;
	    vuint32_t AVERAGE_HIPRIORITY:13;
        } B;
    } HIPRIO_CONFIG;
    union { /* LUT0 - LUT4 MAIN UPPER Register  (Base+0x008C - 0X009C) */
        vuint32_t R;
        struct {
            vuint32_t PRIO15:4;
            vuint32_t PRIO14:4;
            vuint32_t PRIO13:4;
            vuint32_t PRIO12:4;
	    vuint32_t PRIO11:4;
	    vuint32_t PRIO10:4;
	    vuint32_t PRIO9:4;
	    vuint32_t PRIO8:4;
        } B;
    } LUT0_MAIN_UPPER[5];
    union { /* LUT0 - LUT4 MAIN LOWER Register  (Base+0x00A0 - 0X00B0) */
        vuint32_t R;
        struct {
            vuint32_t PRIO7:4;
            vuint32_t PRIO6:4;
            vuint32_t PRIO5:4;
            vuint32_t PRIO4:4;
	    vuint32_t PRIO3:4;
	    vuint32_t PRIO2:4;
	    vuint32_t PRIO1:4;
	    vuint32_t PRIO0:4;
        } B;
    } LUT0_MAIN_LOWER[5];
    union { /* LUT0 - LUT4 ALTERNATE UPPER Register  (Base+0x00B4 - 0X00C4) */
        vuint32_t R;
        struct {
            vuint32_t PRIO15:4;
            vuint32_t PRIO14:4;
            vuint32_t PRIO13:4;
            vuint32_t PRIO12:4;
	    vuint32_t PRIO11:4;
	    vuint32_t PRIO10:4;
	    vuint32_t PRIO9:4;
	    vuint32_t PRIO8:4;
        } B;
    } LUT0_ALTER_UPPER[5];
    union { /* LUT0 - LUT4 ALTERNATE LOWER Register  (Base+0x00C8 - 0X00D8) */
        vuint32_t R;
        struct {
            vuint32_t PRIO7:4;
            vuint32_t PRIO6:4;
            vuint32_t PRIO5:4;
            vuint32_t PRIO4:4;
	    vuint32_t PRIO3:4;
	    vuint32_t PRIO2:4;
	    vuint32_t PRIO1:4;
	    vuint32_t PRIO0:4;
        } B;
    } LUT0_ALTER_LOWER[5];
    union { /* Performane Configuration Register  (Base+0x00DC) */
        vuint32_t R;
        struct {
	    vuint32_t INT:1;
	    vuint32_t INTCLEAR:1;
	    vuint32_t INTEN:1;
	    vuint32_t DMAREQ:1;
	    vuint32_t DMAREQSTOP:1;
	    vuint32_t EVENTCOUNTFREERUN:1;
	    vuint32_t EVENTCOUNTTRIG:1;
	    vuint32_t :15;
	    vuint32_t LUTSEL4:2;
	    vuint32_t LUTSEL3:2;
	    vuint32_t LUTSEL2:2;
	    vuint32_t LUTSEL1:2;
	    vuint32_t LUTSEL0:2;
        } B;
    } PERMON_CONFIG;
    union { /* Event Time Counter Register  (Base+0x00E0) */
        vuint32_t R;
        struct {
	    vuint32_t :8;
	    vuint32_t EVENT_TIME:24;
        } B;
    } EVENT_TIME_COUNTER;
    union { /* Event Time Preset Register  (Base+0x00E4) */
        vuint32_t R;
        struct {
	    vuint32_t :8;
	    vuint32_t EVENT_TIME:24;
        } B;
    } EVENT_TIME_PRESET;

    int32_t MDDRC_reserved3[10]; /* (0x00E4 - 0x0110)/4 = 0x11 */
    
    union { /* Granted Ack Counters Register  (Base+0x0110 - 0X120) */
        vuint32_t R;
        struct {
	    vuint32_t :8;
	    vuint32_t GRANTED_ACK:24;
        } B;
    } GRANTED_ACK_COUNTER[5];
    union { /* Cumulative Wait Counters Register  (Base+0x0124 - 0X0134) */
        vuint32_t R;
        struct {
	    vuint32_t :8;
	    vuint32_t CUMULATIVE_WAIT:24;
        } B;
    } CUMULATIVE_WAIT[5];
    union { /* Summed Priority Counters Register  (Base+0x0138 - 0X0148) */
        vuint32_t R;
        struct {
	    vuint32_t :8;
	    vuint32_t SUMMED_PRIORITY:24;
        } B;
    } SUMMED_PRIORITY[5] ;
}; /* end of MDDRC_tag */
/****************************************************************************/
/*                          MODULE : ME (Mode Entry)                        */
/****************************************************************************/
struct ME_tag{
    union { /* Global Status (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t S_CURRENTMODE:4;
            vuint32_t S_MTRANS:1;
            vuint32_t :1;
            vuint32_t :2;
            vuint32_t S_PDO:1;
            vuint32_t :2;
            vuint32_t S_MVR:1;
            vuint32_t S_DFLA:2;
            vuint32_t S_CFLA:2;
            vuint32_t :8;
	    vuint32_t S_PLL1:1;
            vuint32_t S_PLL0:1;
            vuint32_t S_XOSC:1;
            vuint32_t S_IRCOSC:1;
            vuint32_t S_SYSCLK:4;
        } B;
    } GS;
    union { /* Mode Control (Base+0x004) */
        vuint32_t R;
        struct {
            vuint32_t TARGET_MODE:4;
            vuint32_t :12;
	    vuint32_t KEY:16;
        } B;
    } MCTL;
    union { /* Mode Enable Register(Base+0x0008) */
        vuint32_t R;
        struct {
            vuint32_t :18;
            vuint32_t :1;
            vuint32_t :2;
            vuint32_t STOP0:1;
            vuint32_t :1;
            vuint32_t HALT0:1;
            vuint32_t RUN3:1;
            vuint32_t RUN2:1;
            vuint32_t RUN1:1;
            vuint32_t RUN0:1;
            vuint32_t DRUN:1;
            vuint32_t SAFE:1;
            vuint32_t TEST:1;
            vuint32_t RESET:1;
        } B;
    } MER;
    union { /* Interrupt Status (Base+0x000C) */
        vuint32_t R;
        struct {
            vuint32_t :27;
            vuint32_t I_ICONF_CV:1;
            vuint32_t I_ICONF:1;
            vuint32_t I_IMODE:1;
            vuint32_t I_SAFE:1;
            vuint32_t I_MTC:1;
        } B;
    } IS;
    union { /* Interrupt Mask (Base+0x0010) */
        vuint32_t R;
        struct {
            vuint32_t :27;
            vuint32_t I_ICONF_CV:1;
            vuint32_t M_ICONF:1;
            vuint32_t M_IMODE:1;
            vuint32_t M_SAFE:1;
            vuint32_t M_MTC:1;
        } B;
    } IM;
    union { /* Invalid Mode Transition Status (Base+0x0014) */
        vuint32_t R;
        struct {
            vuint32_t :27;
            vuint32_t S_MTI:1;
            vuint32_t S_MRI:1;
            vuint32_t S_DMA:1;
            vuint32_t S_NMA:1;
            vuint32_t S_SEA:1;
        } B;
    } IMTS;
    union { /* Debug Mode Transition Status (Base+0x0018) */
        vuint32_t R;
        struct {
            vuint32_t PREVIOUS_MODE:4;
            vuint32_t :4;
            vuint32_t MPH_BUSY:1;
            vuint32_t :2;
            vuint32_t PMC_PROG:1;
            vuint32_t CORE_DBG:1;
            vuint32_t :2;
            vuint32_t SMR:1;
            vuint32_t :1;
            vuint32_t VREG_CSRC_SC:1;
            vuint32_t CSRC_CSRC_SC:1;
            vuint32_t IRCOSC_SC:1;
            vuint32_t SCSRC_SC:1;
            vuint32_t SYSCLK_SW:1;
            vuint32_t DFLASH_SC:1;
            vuint32_t CFLASH_SC:1;
            vuint32_t CDP_PRPH_0_143:1;
            vuint32_t :3;
            vuint32_t CDP_PRPH_96_127:1;
            vuint32_t CDP_PRPH_64_95:1;
            vuint32_t CDP_PRPH_32_63:1;
            vuint32_t CDP_PRPH_0_31:1;
        } B;
    } DMTS;
    vuint8_t ME_reserved0[4]; /* reserved 4 bytes (Base+0x001C-0x001F) */
    union { /* Reset Mode Configuration (Base+0x0020) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t PDO:1;
            vuint32_t :2;
            vuint32_t MVRON:1;
            vuint32_t DFLAON:2;
            vuint32_t CFLAON:2;
            vuint32_t :8;
	    vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSC0ON:1;
            vuint32_t IRCOCSON:1;
            vuint32_t SYSCLK:4;
        } B;
    } RESET;
    union { /* Test Mode Configuration (Base+0x0024) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t PDO:1;
            vuint32_t :2;
            vuint32_t MVRON:1;
            vuint32_t DFLAON:2;
            vuint32_t CFLAON:2;
            vuint32_t :8;
	    vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSC0ON:1;
            vuint32_t IRCOCSON:1;
            vuint32_t SYSCLK:4;
        } B;
    } TEST;
    union { /* Safe Mode Configuration (Base+0x0028) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t PDO:1;
            vuint32_t :2;
            vuint32_t MVRON:1;
            vuint32_t DFLAON:2;
            vuint32_t CFLAON:2;
            vuint32_t :8;
	    vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSC0ON:1;
            vuint32_t IRCOCSON:1;
            vuint32_t SYSCLK:4;
        } B;
    } SAFE;
    union { /* DRUN Mode Configuration (Base+0x002C) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t PDO:1;
            vuint32_t :2;
            vuint32_t MVRON:1;
            vuint32_t DFLAON:2;
            vuint32_t CFLAON:2;
            vuint32_t :8;
	    vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSC0ON:1;
            vuint32_t IRCOCSON:1;
            vuint32_t SYSCLK:4;
        } B;
    } DRUN;
    union { /* RUN 0->4 Mode Configuration (+0x0030-0x003C) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t PDO:1;
            vuint32_t :2;
            vuint32_t MVRON:1;
            vuint32_t DFLAON:2;
            vuint32_t CFLAON:2;
            vuint32_t :8;
	    vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSC0ON:1;
            vuint32_t IRCOCSON:1;
            vuint32_t SYSCLK:4;
        } B;
    } RUN[4];
    union { /* HALT0 Mode Configuration (Base+0x0040) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t PDO:1;
            vuint32_t :2;
            vuint32_t MVRON:1;
            vuint32_t DFLAON:2;
            vuint32_t CFLAON:2;
            vuint32_t :8;
	    vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSC0ON:1;
            vuint32_t IRCOCSON:1;
            vuint32_t SYSCLK:4;
        } B;
    } HALT0;
    vuint8_t ME_reserved1[4]; /* reserved 4 bytes (Base+0x0044-0x0047) */
    union { /* STOP0 Mode Configuration (Base+0x0048) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t PDO:1;
            vuint32_t :2;
            vuint32_t MVRON:1;
            vuint32_t DFLAON:2;
            vuint32_t CFLAON:2;
            vuint32_t :8;
	    vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSC0ON:1;
            vuint32_t IRCOCSON:1;
            vuint32_t SYSCLK:4;
        } B;
    } STOP0;
    vuint8_t ME_reserved2[20]; /* reserved 8 bytes (Base+0x004C-0x005F) */
    union {
        vuint32_t R;
        struct { /* Peripheral Status 0 (Base+0x0060) */
            vuint32_t :7;
            vuint32_t S_FLEXRAY:1;
            vuint32_t :4;
            vuint32_t S_FLEXCAN3:1;
            vuint32_t S_FLEXCAN2:1;
            vuint32_t S_FLEXCAN1:1;
            vuint32_t S_FLEXCAN0:1;
            vuint32_t :9;
            vuint32_t S_DSPI2:1;
            vuint32_t S_DSPI1:1;
            vuint32_t S_DSPI0:1;
            vuint32_t :4;
        } B;
    } PS0;
    union { /* Peripheral Status 1 (Base+0x0064)*/
        vuint32_t R;
        struct {
            vuint32_t :5;
            vuint32_t S_CRC0:1;
            vuint32_t :6;
            vuint32_t S_LINFLEX3:1;
            vuint32_t S_LINFLEX2:1;
            vuint32_t S_LINFLEX1:1;
            vuint32_t S_LINFLEX0:1;
	    vuint32_t :1;
	    vuint32_t S_I2C_DMA2:1;
	    vuint32_t S_I2C_DMA1:1;
	    vuint32_t S_I2C_DMA0:1;
	    vuint32_t :1;
	    vuint32_t S_FLEXPWM1:1;
	    vuint32_t S_FLEXPWM0:1;
	    vuint32_t S_ETIMER2:1;
	    vuint32_t S_ETIMER1:1;
	    vuint32_t S_ETIMER0:1;
	    vuint32_t :2;
	    vuint32_t S_CTU0:1;
            vuint32_t :1;
            vuint32_t S_ADC1:1;
            vuint32_t S_ADC0:1;
        } B;
    } PS1;
    union { /* Peripheral Status 2 (Base+0x0068) */
        vuint32_t R;
        struct {
            vuint32_t :3;
            vuint32_t S_PIT_RTI:1;
            vuint32_t S_RTC_API:1;
            vuint32_t :16;
            vuint32_t S_EMIOS1:1;
            vuint32_t S_EMIOS0:1;
            vuint32_t :2;
            vuint32_t S_PERIPH69:1;
            vuint32_t S_SIUL:1;
            vuint32_t :4;
        } B;
    } PS2;
    union { /* Peripheral Status 3 (Base+0x006C) */
        vuint32_t R;
        struct {
            vuint32_t :3;
	    vuint32_t S_PIT_RTI:1;
	    vuint32_t :21;
            vuint32_t S_DRAMC:1;
            vuint32_t :4;
            vuint32_t S_EBI:1;
            vuint32_t :1;
        } B;
    } PS3;
    vuint8_t ME_reserved3[16]; /* reserved 16 bytes (Base+0x0070-0x007F) */
    union { /* RUN Peripheral Config 0..7 (+0x0080-009C) */
        vuint32_t R;
        struct {
            vuint32_t :24;
            vuint32_t RUN3:1;
            vuint32_t RUN2:1;
            vuint32_t RUN1:1;
            vuint32_t RUN0:1;
            vuint32_t DRUN:1;
            vuint32_t SAFE:1;
            vuint32_t TEST:1;
            vuint32_t RESET:1;
        } B;
    } RUNPC[8];
    union { /* Low Pwr Periph Config 0..7 (+0x00A0-0x00BC) */
	vuint32_t R;
	struct {
            vuint32_t :18;
            vuint32_t :1;
            vuint32_t :2;
            vuint32_t STOP0:1;
            vuint32_t :1;
            vuint32_t HALT0:1;
            vuint32_t :8;
        } B;
    } LPPC[8];
    /* Note on PCTL registers: There are only some PCTL implemented in      */
    /*  Komodo. In order to make the PCTL easily addressable, these      */
    /*  are defined as an array (ie ME.PCTL[x].R). This means you have      */
    /*  to be careful when addressing these registers in order not to       */
    /*  access a PCTL that is not implemented. Following are available:     */
    /*  104, 92, 91, 73, 72, 69, 68, 60, 57, 44, 33, 32, 24, 23, 21-16, 13-4*/
    union { /* Peripheral Control 0..121 (+0x00C4-0x013D) */
        vuint8_t R;
        struct {
            vuint8_t :1;
            vuint8_t DBG_F:1;
            vuint8_t LP_CFG:3;
            vuint8_t RUN_CFG:3;
        } B;
    } PCTL[121];
}; /* end of ME_tag */
/****************************************************************************/
/*          MODULE : MPU (Memory Protection Unit)                           */
/****************************************************************************/
struct MPU_tag {
    union { /* Control/Error Status (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t SPERR:8;
            vuint32_t :4;
            vuint32_t HRL:4;
            vuint32_t NSP:4;
            vuint32_t NGRD:4;
            vuint32_t :7;
            vuint32_t VLD:1;
        } B;
    } CESR;
    vuint8_t MPU_reserved0[12]; /* Reserved 12 Bytes (Base+0x0004-0x000F) */
    union { /* Error Address Slave Port0 (Base+0x0010) */
        vuint32_t R;
        struct {
            vuint32_t EADDR:32;
        } B;
    } EAR0;
    union { /* Error Detail Slave Port0 (Base+0x0014) */
        vuint32_t R;
        struct {
            vuint32_t EACD:16;
            vuint32_t EPID:8;
            vuint32_t EMN:4;
            vuint32_t EATTR:3;
            vuint32_t ERW:1;
        } B;
    } EDR0;
    union { /* Error Address Slave Port1 (Base+0x0018) */
        vuint32_t R;
        struct {
            vuint32_t EADDR:32;
        } B;
    } EAR1;
    union { /* Error Detail Slave Port1 (Base+0x001C) */
        vuint32_t R;
        struct {
            vuint32_t EACD:16;
            vuint32_t EPID:8;
            vuint32_t EMN:4;
            vuint32_t EATTR:3;
            vuint32_t ERW:1;
        } B;
    } EDR1;
    union { /* Error Address Slave Port2 (Base+0x0020) */
        vuint32_t R;
        struct {
            vuint32_t EADDR:32;
        } B;
    } EAR2;
    union { /* Error Detail Slave Port2 (Base+0x0024) */
        vuint32_t R;
        struct {
            vuint32_t EACD:16;
            vuint32_t EPID:8;
            vuint32_t EMN:4;
            vuint32_t EATTR:3;
            vuint32_t ERW:1;
        } B;
    } EDR2;
    vuint8_t MPU_reserved1[984]; /* Reserved 984 Bytes (Base+0x0028-0x03FF) */
    struct { /* Region Descriptor 0..7 (Base+0x0400-0x047F) */
        union { /* - Word 0 */
            vuint32_t R;
            struct {
                vuint32_t SRTADDR:27;
                vuint32_t :5;
            } B;
        } WORD0;
        union { /* - Word 1 */
            vuint32_t R;
            struct {
                vuint32_t ENDADDR:27;
                vuint32_t :5;
            } B;
        } WORD1;
	union { /* - Word 2 */
            vuint32_t R;
            struct {
                vuint32_t :8;
                vuint32_t M3PE:1;
                vuint32_t M3SM:2;
                vuint32_t M3UM:3;
                vuint32_t M2PE:1;
                vuint32_t M2SM1:1;
                vuint32_t M2SM0:1;
                vuint32_t M2UM:3;
                vuint32_t M1PE:1;
                vuint32_t M1SM:2;
                vuint32_t M1UM:3;
                vuint32_t M0PE:1;
                vuint32_t M0SM:2;
                vuint32_t M0UM:3;
            } B;
        } WORD2;
        union { /* - Word 3 */
            vuint32_t R;
            struct {
                vuint32_t PID:8;
                vuint32_t PIDMASK:8;
                vuint32_t :15;
                vuint32_t VLD:1;
            } B;
        } WORD3;
    }RGD[16]; /* End of Region Descriptor Structure) */
    vuint8_t MPU_reserved2[768]; /* Reserved 768 Bytes (Base+0x0500-0x07FF) */
    union { /* Region Descriptor Alt 0..7 (0x0800-0x081F) */
        vuint32_t R;
        struct {
	    vuint32_t :8;
	    vuint32_t M3PE:1;
	    vuint32_t M3SM:2;
	    vuint32_t M3UM:3;
	    vuint32_t M2PE:1;
	    vuint32_t M2SM1:1;
	    vuint32_t M2SM0:1;
	    vuint32_t M2UM:3;
	    vuint32_t M1PE:1;
	    vuint32_t M1SM:2;
	    vuint32_t M1UM:3;
	    vuint32_t M0PE:1;
	    vuint32_t M0SM:2;
	    vuint32_t M0UM:3;
        } B;
    } RGDAAC[16];
    vuint8_t MPU_reserved3[14272]; /* Reserved 14272 Bytes (+0x0840-0x03FFF) */
}; /* end of MPU_tag */
/****************************************************************************/
/*                          MODULE : PBRIDGE                                */
/****************************************************************************/
struct PBRIDGE_tag{
   union {   /* MPROT0_7 - Master Privilege Registers */
      vuint32_t R;
      struct {
         vuint32_t  MPROT0_MBW:1;      /* Master 0 Buffer Writes */
         vuint32_t  MPROT0_MTR:1;      /* Master 0 Trusted for Reads */
         vuint32_t  MPROT0_MTW:1;      /* Master 0 Trusted for Writes */
         vuint32_t  MPROT0_MPL:1;      /* Master 0 Priviledge Level */
         vuint32_t  MPROT1_MBW:1;      /* Master 1 Buffer Writes */
         vuint32_t  MPROT1_MTR:1;      /* Master 1 Trusted for Reads */
         vuint32_t  MPROT1_MTW:1;      /* Master 1 Trusted for Writes */
         vuint32_t  MPROT1_MPL:1;      /* Master 1 Priviledge Level */
         vuint32_t  MPROT2_MBW:1;      /* Master 2 Buffer Writes */
         vuint32_t  MPROT2_MTR:1;      /* Master 2 Trusted for Reads */
         vuint32_t  MPROT2_MTW:1;      /* Master 2 Trusted for Writes */
         vuint32_t  MPROT2_MPL:1;      /* Master 2 Priviledge Level */
         vuint32_t  MPROT3_MBW:1;      /* Master 3 Buffer Writes */
         vuint32_t  MPROT3_MTR:1;      /* Master 3 Trusted for Reads */
         vuint32_t  MPROT3_MTW:1;      /* Master 3 Trusted for Writes */
         vuint32_t  MPROT3_MPL:1;      /* Master 3 Priviledge Level */
         vuint32_t  MPROT4_MBW:1;      /* Master 4 Buffer Writes */
         vuint32_t  MPROT4_MTR:1;      /* Master 4 Trusted for Reads */
         vuint32_t  MPROT4_MTW:1;      /* Master 4 Trusted for Writes */
         vuint32_t  MPROT4_MPL:1;      /* Master 4 Priviledge Level */
         vuint32_t  MPROT5_MBW:1;      /* Master 5 Buffer Writes */
         vuint32_t  MPROT5_MTR:1;      /* Master 5 Trusted for Reads */
         vuint32_t  MPROT5_MTW:1;      /* Master 5 Trusted for Writes */
         vuint32_t  MPROT5_MPL:1;      /* Master 5 Priviledge Level */
         vuint32_t  MPROT6_MBW:1;      /* Master 6 Buffer Writes */
         vuint32_t  MPROT6_MTR:1;      /* Master 6 Trusted for Reads */
         vuint32_t  MPROT6_MTW:1;      /* Master 6 Trusted for Writes */
         vuint32_t  MPROT6_MPL:1;      /* Master 6 Priviledge Level */
         vuint32_t  MPROT7_MBW:1;      /* Master 7 Buffer Writes */
         vuint32_t  MPROT7_MTR:1;      /* Master 7 Trusted for Reads */
         vuint32_t  MPROT7_MTW:1;      /* Master 7 Trusted for Writes */
         vuint32_t  MPROT7_MPL:1;      /* Master 7 Priviledge Level */
      } B;
   } MPROT0_7;
   
   union {   /* MPROT8_15 - Master Privilege Registers */
      vuint32_t R;
      struct {
         vuint32_t  MPROT8_MBW:1;      /* Master 0 Buffer Writes */
         vuint32_t  MPROT8_MTR:1;      /* Master 0 Trusted for Reads */
         vuint32_t  MPROT8_MTW:1;      /* Master 0 Trusted for Writes */
         vuint32_t  MPROT8_MPL:1;      /* Master 0 Priviledge Level */
         vuint32_t  MPROT9_MBW:1;      /* Master 1 Buffer Writes */
         vuint32_t  MPROT9_MTR:1;      /* Master 1 Trusted for Reads */
         vuint32_t  MPROT9_MTW:1;      /* Master 1 Trusted for Writes */
         vuint32_t  MPROT9_MPL:1;      /* Master 1 Priviledge Level */
         vuint32_t  MPROT10_MBW:1;      /* Master 2 Buffer Writes */
         vuint32_t  MPROT10_MTR:1;      /* Master 2 Trusted for Reads */
         vuint32_t  MPROT10_MTW:1;      /* Master 2 Trusted for Writes */
         vuint32_t  MPROT10_MPL:1;      /* Master 2 Priviledge Level */
         vuint32_t  MPROT11_MBW:1;      /* Master 3 Buffer Writes */
         vuint32_t  MPROT11_MTR:1;      /* Master 3 Trusted for Reads */
         vuint32_t  MPROT11_MTW:1;      /* Master 3 Trusted for Writes */
         vuint32_t  MPROT11_MPL:1;      /* Master 3 Priviledge Level */
         vuint32_t  MPROT12_MBW:1;      /* Master 4 Buffer Writes */
         vuint32_t  MPROT12_MTR:1;      /* Master 4 Trusted for Reads */
         vuint32_t  MPROT12_MTW:1;      /* Master 4 Trusted for Writes */
         vuint32_t  MPROT12_MPL:1;      /* Master 4 Priviledge Level */
         vuint32_t  MPROT13_MBW:1;      /* Master 5 Buffer Writes */
         vuint32_t  MPROT13_MTR:1;      /* Master 5 Trusted for Reads */
         vuint32_t  MPROT13_MTW:1;      /* Master 5 Trusted for Writes */
         vuint32_t  MPROT13_MPL:1;      /* Master 5 Priviledge Level */
         vuint32_t  MPROT14_MBW:1;      /* Master 6 Buffer Writes */
         vuint32_t  MPROT14_MTR:1;      /* Master 6 Trusted for Reads */
         vuint32_t  MPROT14_MTW:1;      /* Master 6 Trusted for Writes */
         vuint32_t  MPROT14_MPL:1;      /* Master 6 Priviledge Level */
         vuint32_t  MPROT15_MBW:1;      /* Master 7 Buffer Writes */
         vuint32_t  MPROT15_MTR:1;      /* Master 7 Trusted for Reads */
         vuint32_t  MPROT15_MTW:1;      /* Master 7 Trusted for Writes */
         vuint32_t  MPROT15_MPL:1;      /* Master 7 Priviledge Level */
      } B;
   } MPROT8_15;
  
    int32_t PBRIDGE_reserved0[6]; /* (0x008 - 0x01F)/4 = 0x06 */

   
   union {   /* PACR0_7 - Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  PACR0_BW:1;        /* Buffer Writes */
         vuint32_t  PACR0_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR0_WP:1;        /* Write Protect */
         vuint32_t  PACR0_TP:1;        /* Trusted Protect */
         vuint32_t  PACR1_BW:1;        /* Buffer Writes */
         vuint32_t  PACR1_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR1_WP:1;        /* Write Protect */
         vuint32_t  PACR1_TP:1;        /* Trusted Protect */
         vuint32_t  PACR2_BW:1;        /* Buffer Writes */
         vuint32_t  PACR2_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR2_WP:1;        /* Write Protect */
         vuint32_t  PACR2_TP:1;        /* Trusted Protect */
         vuint32_t  PACR3_BW:1;        /* Buffer Writes */
         vuint32_t  PACR3_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR3_WP:1;        /* Write Protect */
         vuint32_t  PACR3_TP:1;        /* Trusted Protect */
         vuint32_t  PACR4_BW:1;        /* Buffer Writes */
         vuint32_t  PACR4_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR4_WP:1;        /* Write Protect */
         vuint32_t  PACR4_TP:1;        /* Trusted Protect */
         vuint32_t  PACR5_BW:1;        /* Buffer Writes */
         vuint32_t  PACR5_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR5_WP:1;        /* Write Protect */
         vuint32_t  PACR5_TP:1;        /* Trusted Protect */
         vuint32_t  PACR6_BW:1;        /* Buffer Writes */
         vuint32_t  PACR6_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR6_WP:1;        /* Write Protect */
         vuint32_t  PACR6_TP:1;        /* Trusted Protect */
         vuint32_t  PACR7_BW:1;        /* Buffer Writes */
         vuint32_t  PACR7_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR7_WP:1;        /* Write Protect */
         vuint32_t  PACR7_TP:1;        /* Trusted Protect */
      } B;
   } PACR0_7;

   union {   /* PACR8_15 - Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  PACR8_BW:1;        /* Buffer Writes */
         vuint32_t  PACR8_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR8_WP:1;        /* Write Protect */
         vuint32_t  PACR8_TP:1;        /* Trusted Protect */
         vuint32_t  PACR9_BW:1;        /* Buffer Writes */
         vuint32_t  PACR9_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR9_WP:1;        /* Write Protect */
         vuint32_t  PACR9_TP:1;        /* Trusted Protect */
         vuint32_t  PACR10_BW:1;       /* Buffer Writes */
         vuint32_t  PACR10_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR10_WP:1;       /* Write Protect */
         vuint32_t  PACR10_TP:1;       /* Trusted Protect */
         vuint32_t  PACR11_BW:1;       /* Buffer Writes */
         vuint32_t  PACR11_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR11_WP:1;       /* Write Protect */
         vuint32_t  PACR11_TP:1;       /* Trusted Protect */
         vuint32_t  PACR12_BW:1;       /* Buffer Writes */
         vuint32_t  PACR12_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR12_WP:1;       /* Write Protect */
         vuint32_t  PACR12_TP:1;       /* Trusted Protect */
         vuint32_t  PACR13_BW:1;       /* Buffer Writes */
         vuint32_t  PACR13_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR13_WP:1;       /* Write Protect */
         vuint32_t  PACR13_TP:1;       /* Trusted Protect */
         vuint32_t  PACR14_BW:1;       /* Buffer Writes */
         vuint32_t  PACR14_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR14_WP:1;       /* Write Protect */
         vuint32_t  PACR14_TP:1;       /* Trusted Protect */
         vuint32_t  PACR15_BW:1;       /* Buffer Writes */
         vuint32_t  PACR15_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR15_WP:1;       /* Write Protect */
         vuint32_t  PACR15_TP:1;       /* Trusted Protect */
      } B;
   } PACR8_15;

   union {   /* PACR16_23 - Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  PACR16_BW:1;       /* Buffer Writes */
         vuint32_t  PACR16_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR16_WP:1;       /* Write Protect */
         vuint32_t  PACR16_TP:1;       /* Trusted Protect */
         vuint32_t  PACR17_BW:1;       /* Buffer Writes */
         vuint32_t  PACR17_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR17_WP:1;       /* Write Protect */
         vuint32_t  PACR17_TP:1;       /* Trusted Protect */
         vuint32_t  PACR18_BW:1;       /* Buffer Writes */
         vuint32_t  PACR18_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR18_WP:1;       /* Write Protect */
         vuint32_t  PACR18_TP:1;       /* Trusted Protect */
         vuint32_t  PACR19_BW:1;       /* Buffer Writes */
         vuint32_t  PACR19_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR19_WP:1;       /* Write Protect */
         vuint32_t  PACR19_TP:1;       /* Trusted Protect */
         vuint32_t  PACR20_BW:1;       /* Buffer Writes */
         vuint32_t  PACR20_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR20_WP:1;       /* Write Protect */
         vuint32_t  PACR20_TP:1;       /* Trusted Protect */
         vuint32_t  PACR21_BW:1;       /* Buffer Writes */
         vuint32_t  PACR21_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR21_WP:1;       /* Write Protect */
         vuint32_t  PACR21_TP:1;       /* Trusted Protect */
         vuint32_t  PACR22_BW:1;       /* Buffer Writes */
         vuint32_t  PACR22_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR22_WP:1;       /* Write Protect */
         vuint32_t  PACR22_TP:1;       /* Trusted Protect */
         vuint32_t  PACR23_BW:1;       /* Buffer Writes */
         vuint32_t  PACR23_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR23_WP:1;       /* Write Protect */
         vuint32_t  PACR23_TP:1;       /* Trusted Protect */
      } B;
   } PACR16_23;

   union {   /* PACR24_31 - Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  PACR24_BW:1;       /* Buffer Writes */
         vuint32_t  PACR24_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR24_WP:1;       /* Write Protect */
         vuint32_t  PACR24_TP:1;       /* Trusted Protect */
         vuint32_t  PACR25_BW:1;       /* Buffer Writes */
         vuint32_t  PACR25_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR25_WP:1;       /* Write Protect */
         vuint32_t  PACR25_TP:1;       /* Trusted Protect */
         vuint32_t  PACR26_BW:1;       /* Buffer Writes */
         vuint32_t  PACR26_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR26_WP:1;       /* Write Protect */
         vuint32_t  PACR26_TP:1;       /* Trusted Protect */
         vuint32_t  PACR27_BW:1;       /* Buffer Writes */
         vuint32_t  PACR27_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR27_WP:1;       /* Write Protect */
         vuint32_t  PACR27_TP:1;       /* Trusted Protect */
         vuint32_t  PACR28_BW:1;       /* Buffer Writes */
         vuint32_t  PACR28_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR28_WP:1;       /* Write Protect */
         vuint32_t  PACR28_TP:1;       /* Trusted Protect */
         vuint32_t  PACR29_BW:1;       /* Buffer Writes */
         vuint32_t  PACR29_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR29_WP:1;       /* Write Protect */
         vuint32_t  PACR29_TP:1;       /* Trusted Protect */
         vuint32_t  PACR30_BW:1;       /* Buffer Writes */
         vuint32_t  PACR30_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR30_WP:1;       /* Write Protect */
         vuint32_t  PACR30_TP:1;       /* Trusted Protect */
         vuint32_t  PACR31_BW:1;       /* Buffer Writes */
         vuint32_t  PACR31_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR31_WP:1;       /* Write Protect */
         vuint32_t  PACR31_TP:1;       /* Trusted Protect */
      } B;
   } PACR24_31;

   
    int32_t PBRIDGE_reserved1[4]; /* (0x02C - 0x040)/4 = 0x04 */

   union {   /* OPACR0_7 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR0_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR0_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR0_WP:1;       /* Write Protect */
         vuint32_t  OPACR0_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR1_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR1_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR1_WP:1;       /* Write Protect */
         vuint32_t  OPACR1_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR2_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR2_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR2_WP:1;       /* Write Protect */
         vuint32_t  OPACR2_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR3_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR3_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR3_WP:1;       /* Write Protect */
         vuint32_t  OPACR3_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR4_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR4_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR4_WP:1;       /* Write Protect */
         vuint32_t  OPACR4_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR5_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR5_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR5_WP:1;       /* Write Protect */
         vuint32_t  OPACR5_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR6_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR6_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR6_WP:1;       /* Write Protect */
         vuint32_t  OPACR6_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR7_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR7_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR7_WP:1;       /* Write Protect */
         vuint32_t  OPACR7_TP:1;       /* Trusted Protect */
      } B;
   } OPACR0_7;

   union {   /* OPACR8_15 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR8_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR8_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR8_WP:1;       /* Write Protect */
         vuint32_t  OPACR8_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR9_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR9_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR9_WP:1;       /* Write Protect */
         vuint32_t  OPACR9_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR10_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR10_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR10_WP:1;      /* Write Protect */
         vuint32_t  OPACR10_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR11_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR11_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR11_WP:1;      /* Write Protect */
         vuint32_t  OPACR11_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR12_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR12_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR12_WP:1;      /* Write Protect */
         vuint32_t  OPACR12_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR13_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR13_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR13_WP:1;      /* Write Protect */
         vuint32_t  OPACR13_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR14_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR14_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR14_WP:1;      /* Write Protect */
         vuint32_t  OPACR14_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR15_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR15_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR15_WP:1;      /* Write Protect */
         vuint32_t  OPACR15_TP:1;      /* Trusted Protect */
      } B;
   } OPACR8_15;

   union {   /* OPACR16_23 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR16_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR16_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR16_WP:1;      /* Write Protect */
         vuint32_t  OPACR16_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR17_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR17_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR17_WP:1;      /* Write Protect */
         vuint32_t  OPACR17_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR18_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR18_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR18_WP:1;      /* Write Protect */
         vuint32_t  OPACR18_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR19_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR19_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR19_WP:1;      /* Write Protect */
         vuint32_t  OPACR19_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR20_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR20_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR20_WP:1;      /* Write Protect */
         vuint32_t  OPACR20_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR21_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR21_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR21_WP:1;      /* Write Protect */
         vuint32_t  OPACR21_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR22_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR22_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR22_WP:1;      /* Write Protect */
         vuint32_t  OPACR22_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR23_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR23_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR23_WP:1;      /* Write Protect */
         vuint32_t  OPACR23_TP:1;      /* Trusted Protect */
      } B;
   } OPACR16_23;

   union {   /* OPACR24_31 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR24_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR24_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR24_WP:1;      /* Write Protect */
         vuint32_t  OPACR24_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR25_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR25_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR25_WP:1;      /* Write Protect */
         vuint32_t  OPACR25_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR26_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR26_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR26_WP:1;      /* Write Protect */
         vuint32_t  OPACR26_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR27_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR27_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR27_WP:1;      /* Write Protect */
         vuint32_t  OPACR27_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR28_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR28_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR28_WP:1;      /* Write Protect */
         vuint32_t  OPACR28_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR29_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR29_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR29_WP:1;      /* Write Protect */
         vuint32_t  OPACR29_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR30_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR30_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR30_WP:1;      /* Write Protect */
         vuint32_t  OPACR30_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR31_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR31_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR31_WP:1;      /* Write Protect */
         vuint32_t  OPACR31_TP:1;      /* Trusted Protect */
      } B;
   } OPACR24_31;

   union {   /* OPACR32_39 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR32_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR32_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR32_WP:1;      /* Write Protect */
         vuint32_t  OPACR32_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR33_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR33_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR33_WP:1;      /* Write Protect */
         vuint32_t  OPACR33_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR34_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR34_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR34_WP:1;      /* Write Protect */
         vuint32_t  OPACR34_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR35_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR35_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR35_WP:1;      /* Write Protect */
         vuint32_t  OPACR35_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR36_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR36_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR36_WP:1;      /* Write Protect */
         vuint32_t  OPACR36_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR37_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR37_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR37_WP:1;      /* Write Protect */
         vuint32_t  OPACR37_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR38_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR38_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR38_WP:1;      /* Write Protect */
         vuint32_t  OPACR38_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR39_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR39_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR39_WP:1;      /* Write Protect */
         vuint32_t  OPACR39_TP:1;      /* Trusted Protect */
      } B;
   } OPACR32_39;

   union {   /* OPACR40_47 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR40_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR40_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR40_WP:1;      /* Write Protect */
         vuint32_t  OPACR40_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR41_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR41_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR41_WP:1;      /* Write Protect */
         vuint32_t  OPACR41_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR42_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR42_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR42_WP:1;      /* Write Protect */
         vuint32_t  OPACR42_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR43_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR43_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR43_WP:1;      /* Write Protect */
         vuint32_t  OPACR43_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR44_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR44_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR44_WP:1;      /* Write Protect */
         vuint32_t  OPACR44_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR45_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR45_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR45_WP:1;      /* Write Protect */
         vuint32_t  OPACR45_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR46_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR46_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR46_WP:1;      /* Write Protect */
         vuint32_t  OPACR46_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR47_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR47_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR47_WP:1;      /* Write Protect */
         vuint32_t  OPACR47_TP:1;      /* Trusted Protect */
      } B;
   } OPACR40_47;

   union {   /* OPACR48_55 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR48_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR48_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR48_WP:1;      /* Write Protect */
         vuint32_t  OPACR48_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR49_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR49_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR49_WP:1;      /* Write Protect */
         vuint32_t  OPACR49_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR50_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR50_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR50_WP:1;      /* Write Protect */
         vuint32_t  OPACR50_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR51_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR51_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR51_WP:1;      /* Write Protect */
         vuint32_t  OPACR51_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR52_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR52_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR52_WP:1;      /* Write Protect */
         vuint32_t  OPACR52_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR53_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR53_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR53_WP:1;      /* Write Protect */
         vuint32_t  OPACR53_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR54_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR54_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR54_WP:1;      /* Write Protect */
         vuint32_t  OPACR54_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR55_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR55_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR55_WP:1;      /* Write Protect */
         vuint32_t  OPACR55_TP:1;      /* Trusted Protect */
      } B;
   } OPACR48_55;

   union {   /* OPACR56_63 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR56_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR56_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR56_WP:1;      /* Write Protect */
         vuint32_t  OPACR56_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR57_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR57_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR57_WP:1;      /* Write Protect */
         vuint32_t  OPACR57_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR58_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR58_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR58_WP:1;      /* Write Protect */
         vuint32_t  OPACR58_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR59_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR59_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR59_WP:1;      /* Write Protect */
         vuint32_t  OPACR59_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR60_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR60_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR60_WP:1;      /* Write Protect */
         vuint32_t  OPACR60_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR61_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR61_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR61_WP:1;      /* Write Protect */
         vuint32_t  OPACR61_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR62_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR62_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR62_WP:1;      /* Write Protect */
         vuint32_t  OPACR62_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR63_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR63_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR63_WP:1;      /* Write Protect */
         vuint32_t  OPACR63_TP:1;      /* Trusted Protect */
      } B;
   } OPACR56_63;

   union {   /* OPACR64_71 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR64_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR64_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR64_WP:1;      /* Write Protect */
         vuint32_t  OPACR64_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR65_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR65_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR65_WP:1;      /* Write Protect */
         vuint32_t  OPACR65_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR66_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR66_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR66_WP:1;      /* Write Protect */
         vuint32_t  OPACR66_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR67_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR67_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR67_WP:1;      /* Write Protect */
         vuint32_t  OPACR67_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR68_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR68_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR68_WP:1;      /* Write Protect */
         vuint32_t  OPACR68_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR69_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR69_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR69_WP:1;      /* Write Protect */
         vuint32_t  OPACR69_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR70_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR70_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR70_WP:1;      /* Write Protect */
         vuint32_t  OPACR70_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR71_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR71_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR71_WP:1;      /* Write Protect */
         vuint32_t  OPACR71_TP:1;      /* Trusted Protect */
      } B;
   } OPACR64_71;

   union {   /* OPACR72_79 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR72_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR72_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR72_WP:1;      /* Write Protect */
         vuint32_t  OPACR72_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR73_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR73_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR73_WP:1;      /* Write Protect */
         vuint32_t  OPACR73_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR74_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR74_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR74_WP:1;      /* Write Protect */
         vuint32_t  OPACR74_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR75_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR75_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR75_WP:1;      /* Write Protect */
         vuint32_t  OPACR75_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR76_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR76_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR76_WP:1;      /* Write Protect */
         vuint32_t  OPACR76_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR77_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR77_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR77_WP:1;      /* Write Protect */
         vuint32_t  OPACR77_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR78_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR78_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR78_WP:1;      /* Write Protect */
         vuint32_t  OPACR78_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR79_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR79_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR79_WP:1;      /* Write Protect */
         vuint32_t  OPACR79_TP:1;      /* Trusted Protect */
      } B;
   } OPACR72_79;

   union {   /* OPACR80_87 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR80_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR80_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR80_WP:1;      /* Write Protect */
         vuint32_t  OPACR80_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR81_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR81_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR81_WP:1;      /* Write Protect */
         vuint32_t  OPACR81_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR82_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR82_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR82_WP:1;      /* Write Protect */
         vuint32_t  OPACR82_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR83_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR83_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR83_WP:1;      /* Write Protect */
         vuint32_t  OPACR83_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR84_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR84_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR84_WP:1;      /* Write Protect */
         vuint32_t  OPACR84_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR85_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR85_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR85_WP:1;      /* Write Protect */
         vuint32_t  OPACR85_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR86_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR86_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR86_WP:1;      /* Write Protect */
         vuint32_t  OPACR86_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR87_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR87_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR87_WP:1;      /* Write Protect */
         vuint32_t  OPACR87_TP:1;      /* Trusted Protect */
      } B;
   } OPACR80_87;

   union {   /* OPACR88_95 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR88_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR88_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR88_WP:1;      /* Write Protect */
         vuint32_t  OPACR88_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR89_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR89_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR89_WP:1;      /* Write Protect */
         vuint32_t  OPACR89_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR90_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR90_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR90_WP:1;      /* Write Protect */
         vuint32_t  OPACR90_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR91_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR91_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR91_WP:1;      /* Write Protect */
         vuint32_t  OPACR91_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR92_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR92_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR92_WP:1;      /* Write Protect */
         vuint32_t  OPACR92_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR93_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR93_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR93_WP:1;      /* Write Protect */
         vuint32_t  OPACR93_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR94_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR94_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR94_WP:1;      /* Write Protect */
         vuint32_t  OPACR94_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR95_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR95_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR95_WP:1;      /* Write Protect */
         vuint32_t  OPACR95_TP:1;      /* Trusted Protect */
      } B;
   } OPACR88_95;
}; /* end of PBRIDGE_tag */

/****************************************************************************/
/*                          MODULE : PCU                                   */
/****************************************************************************/
struct PCU_tag{
    vuint8_t PCU_reserved0[64]; /* Reserved 48 bytes (Base+0x0004-0x003F) */
    union { /* PCU Power Domain Status (Base+0x0040) */
        vuint32_t R;
        struct {
            vuint32_t :31;
            vuint32_t PD0:1;
        } B;
    } PSTAT;
    vuint8_t PCU_reserved1[60]; /* Reserved 60 bytes (Base+0x0044-0x007F) */
}; /* end of PCU_tag */
/*****************************************************************************/
/*                          MODULE : Parallel Digital Interface              */
/*****************************************************************************/
struct PDI_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t MODE:1;
            vuint32_t DAL:1;
            vuint32_t DEN:1;
            vuint32_t DMAEN:1;
            vuint32_t DMACON:1;
            vuint32_t DBIN:3;
            vuint32_t WIDTH:3;
            vuint32_t SCKE:1;
            vuint32_t FVP:1;
            vuint32_t LVP:1;
            vuint32_t INVD:1;
            vuint32_t FIFORST:1;
            vuint32_t :1;
            vuint32_t BE:1;
            vuint32_t PBS:1;
            vuint32_t ACK0:1;
            vuint32_t:9;
            vuint32_t FIFOHIPRIOTRIG:3;
        } B;
    } PDIMCR; /* PDI MODULE CONFIGURATION REGISTER */
    union {
        vuint32_t R;
        struct {
            vuint32_t ADCVALIDDELAY:8;
            vuint32_t :17;
            vuint32_t STARTC:3;
            vuint32_t:1;
            vuint32_t ENDC:3;
	} B;
    } PDIADCCR; /* PDI ADC CONFIGURATION REGISTER */
    union {
        vuint32_t R;
        struct {
            vuint32_t FF:1;
            vuint32_t FE:1;
            vuint32_t FO:1;
            vuint32_t FU:1;
	    vuint32_t :4;
            vuint32_t LVS:1;
	    vuint32_t FVS:1;
	    vuint32_t LC:1;
	    vuint32_t FC:1;
            vuint32_t :2;
	    vuint32_t HE:1;
	    vuint32_t DD:1;
	    vuint32_t :10;
	    vuint32_t FIFO_COUNT:6;
        } B;
    } PDISR; /* PDI STATUS REGISTER */
    union {
        vuint32_t R;
        struct {
            vuint32_t :2;
            vuint32_t FOC:1;
            vuint32_t FUR:1;
            vuint32_t :5;
            vuint32_t BCE:1;
            vuint32_t LCE:1;
            vuint32_t FCE:1;
            vuint32_t :2;
            vuint32_t HEE:1;
            vuint32_t DEE:1;
            vuint32_t :16;
        } B;
    } PDIINTER; /* PDI INTERRUPT ENABLE REGISTER */
    union {
        vuint32_t R;
        struct {
            vuint32_t:4;
            vuint32_t ACT_FRM_ORG_Y:12;
            vuint32_t ACT_FRM_ORG_X:16;
        } B;
    } PDIAFOR; /* PDI ACTIVE FRAME ORIGIN REGISTER */
    union {
        vuint32_t R;
        struct {
            vuint32_t:4;
            vuint32_t ACT_FRM_HEIGHT:12;
            vuint32_t ACT_FRM_WIDTH:16;
        } B;
    } PDIAFSR; /* PDI ACTIVE FRAME SIZE REGISTER */
    union {
        vuint32_t R;
        struct {
            vuint32_t DMA_BASE_ADDR:27;
            vuint32_t :5;
        } B;
    } PDIDMABAR; /* PDI DMA BASE ADDRESS REGISTER */
    union {
        vuint32_t R;
        struct {
            vuint32_t DMA_ADDR_STAT:29;
            vuint32_t :3;
        } B;
    } PDIDMAASR; /* PDI DMA ADDRESS STATUS REGISTER */
    union {
        vuint32_t R;
        struct {
            vuint32_t DMA_SIZE:32;
        } B;
    } PDIDMASR; /* PDI DMA SIZE REGISTER */
    int32_t PDI_reserved[2];
}; /* end of PDI_tag */
/****************************************************************************/
/*                          MODULE : pit                                    */
/****************************************************************************/
struct PIT_tag {
    union { /* PIT Module Control (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t:30;
            vuint32_t MDIS:1;
            vuint32_t FRZ:1;
        } B;
    } PITMCR;

    vuint8_t PIT_reserved0[252]; /* Reserved 252 Bytes (Base+0x0004-0x00FF) */

    /* PIT Timer Channels 0..7 (Base+0x0100-0x017C) */
    struct {
        union { /* PIT Timer Load Value (Offset+0x0000) */
            vuint32_t R;
            struct {
                vuint32_t TSV:32;
            } B;
        } LDVAL;
        union { /* PIT Current Timer Value (Offset+0x0004) */
            vuint32_t R;
            struct {
                vuint32_t TVL:32;
            } B;
        } CVAL;
        union { /* PIT Timer Control (Offset+0x0008) */
            vuint32_t R;
            struct {
                vuint32_t :30;
                vuint32_t TIE:1;
                vuint32_t TEN:1;
            } B;
        } TCTRL;
        union { /* PIT Timer Control (Offset+0x0008) */
            vuint32_t R;
            struct {
                vuint32_t :31;
                vuint32_t TIF:1;
            } B;
        } TFLG;
    }CH[4]; /* End of PIT Timer Channels */
}; /* end of PIT_tag */
/****************************************************************************/
/*                          MODULE : PMC                                    */
/****************************************************************************/
struct PMC_tag{
    union { /* CONFIGURATION REGISTER (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t :1;
            vuint32_t REG_TRIM3_LOCK:1;
	    vuint32_t REG_TRIM2_LOCK:1;
	    vuint32_t REG_TRIM1_LOCK:1;
	    vuint32_t :3;
	    vuint32_t REG_CONFIG_LOCK:1;
	    vuint32_t :4;
	    vuint32_t ADC_CHANNEL_SEL:4;
	    vuint32_t :3;
	    vuint32_t HVD1p2_CORE_EN:1;
	    vuint32_t :4;
	    vuint32_t LVD_ADC3p3_EN:1;
	    vuint32_t LVD_3p3_MAIN_EN:1;
	    vuint32_t :1;
	    vuint32_t LVD_1p2_CORE_EN:1;
	    vuint32_t :2;
	    vuint32_t LVD3p3IO_EN:1;
	    vuint32_t LVD_3p3_FLASH_EN:1;
        } B;
    } CFGR;
    int32_t PMC_reserved0[1]; /* (0x0004) */
    union { /* STATUS REGISTER (Base+0x0008) */
        vuint32_t R;
        struct {
            vuint32_t POR_STATUS:1;
            vuint32_t :5;
	    vuint32_t BANDGAP_RDY:1;
	    vuint32_t :12;
	    vuint32_t HVD_1p2_CORE:1;
	    vuint32_t :4;
	    vuint32_t LVD_ADC3p3:1;
	    vuint32_t LVD_3p3_MAIN:1;
	    vuint32_t :1;
	    vuint32_t LVD_1p2_CORE:1;
	    vuint32_t :2;
	    vuint32_t LVD3p3IO:1;
	    vuint32_t LVD_3p3_FLASH:1;
        } B;
    } SR;
    int32_t PMC_reserved1[1]; /* (0x000C) */
    union { /* TRIMMING REGISTER 1(Base+0x0010) */
        vuint32_t R;
        struct {
            vuint32_t :2;
            vuint32_t CLK1p2_TRIM:6;
	    vuint32_t :2;
	    vuint32_t BANDGAP1p2_ABS_TRIM:6;
	    vuint32_t :2;
	    vuint32_t BANDGAP1p2_CRV_TRIM:6;
	    vuint32_t :4;
	    vuint32_t VREG1p2_TRIM:4;
        } B;
    } TRIM1;
    union { /* TRIMMING REGISTER 2(Base+0x0014) */
        vuint32_t R;
        struct {
            vuint32_t LVD3p3_ADC_TRIM:4;
            vuint32_t LVD3p3_MAIN__TRIM:4;
	    vuint32_t :2;
	    vuint32_t LVD1p2_CORE_TRIM:6;
	    vuint32_t :8;
	    vuint32_t LVD3p3_IO_TRIM_:4;
	    vuint32_t LVD3p3_FLASH_TRIM:4;
        } B;
    } TRIM2;
    union { /* TRIMMING REGISTER 3(Base+0x0018) */
        vuint32_t R;
        struct {
            vuint32_t :10;
            vuint32_t HVD1p2_CORE__TRIM:6;
	    vuint32_t :16;
        } B;
    } TRIM3;
}; /* end of PMC_tag */
/****************************************************************************/
/*                          MODULE : RGM                                   */
/****************************************************************************/
struct RGM_tag{
    union { /* Functional Event Status (Base+0x0000) */
        vuint16_t R;
        struct {
            vuint16_t F_EXR:1;
            vuint16_t F_FCCU_HARD:1;
	    vuint16_t F_FCCU_SOFT:1;
	    vuint16_t F_ST_DONE:1;
	    vuint16_t F_CMU12_FHL:1;
            vuint16_t F_FL_ECC_RCC:1;
            vuint16_t F_PLL1:1;
            vuint16_t F_SWT:1;
            vuint16_t F_FCCU_SAFE:1;
            vuint16_t F_CMU0_FHL:1;
            vuint16_t F_CMU0_OLR:1;
            vuint16_t F_FMPLL0:1;
            vuint16_t F_CWD:1;
            vuint16_t F_SOFT_FUNC:1;
            vuint16_t F_CORE:1;
            vuint16_t F_JTAG:1;
        } B;
    } FES;
    union { /* Destructive Event Status (Base+0x0002) */
        vuint16_t R;
        struct {
            vuint16_t F_POR:1;
            vuint16_t F_SOFT_DEST:1;
	    vuint16_t :6;
	    vuint16_t F_LVD27_ADC:1;
	    vuint16_t F_LVD27_IO:1;
            vuint16_t F_LVD27_FLASH:1;
            vuint16_t F_LVD27_VREG:1;
	    vuint16_t :2;
            vuint16_t F_HVD12:1;
            vuint16_t F_LVD12:1;
        } B;
    } DES;
    union { /* Functional Event Reset Disable (+0x0004) */
        vuint16_t R;
        struct {
            vuint16_t D_EXR:1;
            vuint16_t D_FCCU_HARD:1;
	    vuint16_t D_FCCU_SOFT:1;
	    vuint16_t D_ST_DONE:1;
            vuint16_t D_CMU12_FHL:1;
            vuint16_t D_FL_ECC_RCC:1;
            vuint16_t D_PLL1:1;
            vuint16_t D_SWT:1;
	    vuint16_t D_FCCU_SAFE:1;
            vuint16_t D_CMU0_FHL:1;
            vuint16_t D_CMU0_OLR:1;
            vuint16_t D_PLL0:1;
            vuint16_t D_CWD:1;
            vuint16_t D_SOFT_FUNC:1;
            vuint16_t D_CORE:1;
            vuint16_t D_JTAG:1;
        } B;
    } FERD;
    union { /* Destructive Event Reset Disable (Base+0x0006)*/
        vuint16_t R;
        struct {
	    vuint16_t :1;
	    vuint16_t D_SOFT_DEST:1;
	    vuint16_t :6;
            vuint16_t D_COMP:1;
            vuint16_t D_LVD27_IO:1;
	    vuint16_t D_LVD27_FLASH:1;
	    vuint16_t D_LVD27_VREG:1;
	    vuint16_t :2;
            vuint16_t D_HVD12:1;
            vuint16_t D_LVD12:1;
        } B;
    } DERD;
    vuint8_t RGM_reserved0[8]; /*Reserved 8 bytes (Base+0x008-0x000F) */
    union { /* Functional Event Alt Request (Base+0x0010) */
        vuint16_t R;
        struct {
            vuint16_t :4;
            vuint16_t AR_CMU12_FHL:1;
            vuint16_t :1;
            vuint16_t AR_PLL1:1;
            vuint16_t :1;
	    vuint16_t AR_FCCU_SAFE:1;
	    vuint16_t AR_CMU0_FHL:1;
            vuint16_t AR_CMU0_OLR:1;
            vuint16_t AR_FMPLL0:1;
            vuint16_t AR_CWD:1;
            vuint16_t :3;
        } B;
    } FEAR;
    /* DEAR is not implemented in KOMODO (reads 0) */
    /*union {

      vuint16_t R;

      struct {

      vuint16_t :12;

      vuint16_t AR_LVD27:1;

      vuint16_t AR_SWT:1;

      vuint16_t AR_LVD12_PD1:1;

      vuint16_t AR_LVD12_PD0:1;

      } B;

      } DEAR;    	*/
    vuint8_t RGM_reserved1[6]; /*Reserved 6 bytes (Base+0x0012-0x0017) */
    union { /* Functional Event Short Sequence (+0x0018) */
        vuint16_t R;
        struct {
            vuint16_t SS_EXR:1;
            vuint16_t SS_FCCU_HARD:1;
	    vuint16_t SS_FCCU_SOFT:1;
	    vuint16_t SS_ST_DONE:1;
            vuint16_t SS_CMU12_FHL:1;
            vuint16_t SS_FL_ECC_RCC:1;
            vuint16_t SS_PLL1:1;
            vuint16_t SS_SWT:1;
	    vuint16_t :1;
            vuint16_t SS_CMU0_FHL:1;
            vuint16_t SS_CMU0_OLR:1;
            vuint16_t SS_PLL0:1;
            vuint16_t SS_CWD:1;
            vuint16_t SS_SOFT_FUNC:1;
            vuint16_t SS_CORE:1;
            vuint16_t SS_JTAG:1;
        } B;
    } FESS;
    vuint8_t RGM_reserved2[2]; /*Reserved 6 bytes (Base+0x001C) */
    union { /* Functional Bidirectional Reset En (+0x001C) */
        vuint16_t R;
        struct {
            vuint16_t BE_EXR:1;
            vuint16_t BE_FCCU_HARD:1;
	    vuint16_t BE_FCCU_SOFT:1;
	    vuint16_t BE_ST_DONE:1;
            vuint16_t BE_CMU12_FHL:1;
            vuint16_t BE_FL_ECC_RCC:1;
            vuint16_t BE_PLL1:1;
            vuint16_t BE_SWT:1;
	    vuint16_t :1;
            vuint16_t BE_CMU0_FHL:1;
            vuint16_t BE_CMU0_OLR:1;
            vuint16_t BE_PLL0:1;
            vuint16_t BE_CWD:1;
            vuint16_t BE_SOFT_FUNC:1;
            vuint16_t BE_CORE:1;
            vuint16_t BE_JTAG:1;
        } B;
    } FBRE;
}; /* end of RGM_tag */
/****************************************************************************/
/*          MODULE : SEMA4 (Semaphores)                                     */
/****************************************************************************/
struct SEMA4_tag {
    union { /* Gate 0..15 (Base+0x0000-0x000F) */
        vuint8_t R;
        struct {
            vuint8_t:6;
            vuint8_t GTFSM:2;
        } B;
    } GATE[16];
    vuint8_t SEMA4_reserved0[48]; /* Reserved 48 Bytes (Base+0x0010-0x003F) */
    union { /* CP0 IRQ Notification enable (Base+0x0040) */
        vuint16_t R;
        struct {
            vuint16_t INE0:1;
            vuint16_t INE1:1;
            vuint16_t INE2:1;
            vuint16_t INE3:1;
            vuint16_t INE4:1;
            vuint16_t INE5:1;
            vuint16_t INE6:1;
            vuint16_t INE7:1;
            vuint16_t INE8:1;
            vuint16_t INE9:1;
            vuint16_t INE10:1;
            vuint16_t INE11:1;
            vuint16_t INE12:1;
            vuint16_t INE13:1;
            vuint16_t INE14:1;
            vuint16_t INE15:1;
        } B;
    } CP0INE;
    vuint8_t SEMA4_reserved1[6]; /* Reserved 6 Bytes (Base+0x0042-0x0047) */
    union { /* CP1 IRQ Notification enable (Base+0x0048) */
        vuint16_t R;
        struct {
            vuint16_t INE0:1;
            vuint16_t INE1:1;
            vuint16_t INE2:1;
            vuint16_t INE3:1;
            vuint16_t INE4:1;
            vuint16_t INE5:1;
            vuint16_t INE6:1;
            vuint16_t INE7:1;
            vuint16_t INE8:1;
            vuint16_t INE9:1;
            vuint16_t INE10:1;
            vuint16_t INE11:1;
            vuint16_t INE12:1;
            vuint16_t INE13:1;
            vuint16_t INE14:1;
            vuint16_t INE15:1;
        } B;
    } CP1INE;
    vuint8_t SEMA4_reserved2[54]; /* Reserved 54 Bytes (Base+0x004A-0x007F) */
    union { /* CP0 IRQ Notification (Base+0x0080) */
        vuint16_t R;
        struct {
            vuint16_t GN0:1;
            vuint16_t GN1:1;
            vuint16_t GN2:1;
            vuint16_t GN3:1;
            vuint16_t GN4:1;
            vuint16_t GN5:1;
            vuint16_t GN6:1;
            vuint16_t GN7:1;
            vuint16_t GN8:1;
            vuint16_t GN9:1;
            vuint16_t GN10:1;
            vuint16_t GN11:1;
            vuint16_t GN12:1;
            vuint16_t GN13:1;
            vuint16_t GN14:1;
            vuint16_t GN15:1;
        } B;
    } CP0NTF;
    vuint8_t SEMA4_reserved3[6]; /* Reserved 6 Bytes (Base+0x0082-0x0087) */
    union { /* CP1 IRQ Notification (Base+0x0088) */
        vuint16_t R;
        struct {
            vuint16_t GN0:1;
            vuint16_t GN1:1;
            vuint16_t GN2:1;
            vuint16_t GN3:1;
            vuint16_t GN4:1;
            vuint16_t GN5:1;
            vuint16_t GN6:1;
            vuint16_t GN7:1;
            vuint16_t GN8:1;
            vuint16_t GN9:1;
            vuint16_t GN10:1;
            vuint16_t GN11:1;
            vuint16_t GN12:1;
            vuint16_t GN13:1;
            vuint16_t GN14:1;
            vuint16_t GN15:1;
        } B;
    } CP1NTF;
    vuint8_t SEMA4_reserved4[118]; /* Reserved 118 Bytes (+0x008A-0x00FF) */
    union { /* Reset gate (Base+0x0100) */
        vuint16_t R;
        struct {
            vuint16_t:2;
            vuint16_t RSTGSM:2;
            vuint16_t:1;
            vuint16_t RSTGMS:3;
            vuint16_t RSTGTN:8;
        } B;
    } RSTGT;
    vuint8_t SEMA4_reserved5[2]; /* Reserved 2 Bytes (Base+0x0102-0x0103) */
    union {
        vuint16_t R;
        struct {
            vuint16_t:2;
            vuint16_t RSTNSM:2;
            vuint16_t:1;
            vuint16_t RSTNMS:3;
            vuint16_t RSTNTN:8;
        } B;
    } RSTNTF;
    vuint8_t SEMA4_reserved6[16122]; /* Reserved 16122 (Base+0x0106-0x3FFF) */
}; /* end of SEMA4_tag */
/****************************************************************************/
/*          MODULE : SIU Lite (tagged as SIU for compatibility)             */
/****************************************************************************/
struct SIU_tag {
    vuint8_t SIU_reserved0[4]; /* Reserved 4 Bytes (Base+0x0) */
    union { /* MCU ID1 (Base+0x0004) */
        vuint32_t R;
        struct {
            vuint32_t PARTNUM:16;
            vuint32_t CSP:1;
            vuint32_t PKG:5;
            vuint32_t :2;
            vuint32_t MAJOR_MASK:4;
            vuint32_t MINOR_MASK:4;
        } B;
    } MIDR1;
    union { /* MCU ID2 (Base+0x0008) */
        vuint32_t R;
        struct {
            vuint32_t SF:1;
            vuint32_t FLASH_SIZE_1:4;
            vuint32_t FLASH_SIZE_2:4;
            vuint32_t :7;
            vuint32_t PARTNUM:8;
	    vuint32_t TBD:1; /* Optional Bit */
            vuint32_t :2;
            vuint32_t EE:1;
            vuint32_t :3;
            vuint32_t FR:1;
        } B;
    } MIDR2;
    vuint8_t SIU_reserved1[8]; /* Reserved 8 Bytes (Base+(0x000C--0x0013)) */
    union { /* Interrupt Status Flag (Base+0x0014)*/
        vuint32_t R;
        struct {
            vuint32_t EIF31:1;
            vuint32_t EIF30:1;
            vuint32_t EIF29:1;
            vuint32_t EIF28:1;
            vuint32_t EIF27:1;
            vuint32_t EIF26:1;
            vuint32_t EIF25:1;
            vuint32_t EIF24:1;
	    vuint32_t EIF23:1;
            vuint32_t EIF22:1;
            vuint32_t EIF21:1;
            vuint32_t EIF20:1;
            vuint32_t EIF19:1;
            vuint32_t EIF18:1;
            vuint32_t EIF17:1;
            vuint32_t EIF16:1;
            vuint32_t EIF15:1;
            vuint32_t EIF14:1;
            vuint32_t EIF13:1;
            vuint32_t EIF12:1;
            vuint32_t EIF11:1;
            vuint32_t EIF10:1;
            vuint32_t EIF9:1;
            vuint32_t EIF8:1;
            vuint32_t EIF7:1;
            vuint32_t EIF6:1;
            vuint32_t EIF5:1;
            vuint32_t EIF4:1;
            vuint32_t EIF3:1;
            vuint32_t EIF2:1;
            vuint32_t EIF1:1;
            vuint32_t EIF0:1;
        } B;
    } ISR;
    union { /* Interrupt Request Enable (Base+0x0018) */
        vuint32_t R;
        struct {
            vuint32_t EIRE31:1;
            vuint32_t EIRE30:1;
            vuint32_t EIRE29:1;
            vuint32_t EIRE28:1;
            vuint32_t EIRE27:1;
            vuint32_t EIRE26:1;
            vuint32_t EIRE25:1;
            vuint32_t EIRE24:1;
            vuint32_t EIRE23:1;
            vuint32_t EIRE22:1;
            vuint32_t EIRE21:1;
            vuint32_t EIRE20:1;
            vuint32_t EIRE19:1;
            vuint32_t EIRE18:1;
            vuint32_t EIRE17:1;
            vuint32_t EIRE16:1;
            vuint32_t EIRE15:1;
            vuint32_t EIRE14:1;
            vuint32_t EIRE13:1;
            vuint32_t EIRE12:1;
            vuint32_t EIRE11:1;
            vuint32_t EIRE10:1;
            vuint32_t EIRE9:1;
            vuint32_t EIRE8:1;
            vuint32_t EIRE7:1;
            vuint32_t EIRE6:1;
            vuint32_t EIRE5:1;
            vuint32_t EIRE4:1;
            vuint32_t EIRE3:1;
            vuint32_t EIRE2:1;
            vuint32_t EIRE1:1;
            vuint32_t EIRE0:1;
        } B;
    } IRER;
    vuint8_t SIU_reserved2[12]; /* Reserved 12 Bytes (Base+0x001C-0x0027) */
    union { /* Interrupt Rising-Edge Event Enable (+0x0028) */
        vuint32_t R;
        struct {
            vuint32_t IREE31:1;
            vuint32_t IREE30:1;
            vuint32_t IREE29:1;
            vuint32_t IREE28:1;
            vuint32_t IREE27:1;
            vuint32_t IREE26:1;
            vuint32_t IREE25:1;
            vuint32_t IREE24:1;
            vuint32_t IREE23:1;
            vuint32_t IREE22:1;
            vuint32_t IREE21:1;
            vuint32_t IREE20:1;
            vuint32_t IREE19:1;
            vuint32_t IREE18:1;
            vuint32_t IREE17:1;
            vuint32_t IREE16:1;
            vuint32_t IREE15:1;
            vuint32_t IREE14:1;
            vuint32_t IREE13:1;
            vuint32_t IREE12:1;
            vuint32_t IREE11:1;
            vuint32_t IREE10:1;
            vuint32_t IREE9:1;
            vuint32_t IREE8:1;
            vuint32_t IREE7:1;
            vuint32_t IREE6:1;
            vuint32_t IREE5:1;
            vuint32_t IREE4:1;
            vuint32_t IREE3:1;
            vuint32_t IREE2:1;
            vuint32_t IREE1:1;
            vuint32_t IREE0:1;
        } B;
    } IREER;
    union { /* Interrupt Falling-Edge Event Enable (+0x002C)*/
        vuint32_t R;
        struct {
            vuint32_t IFEE31:1;
            vuint32_t IFEE30:1;
            vuint32_t IFEE29:1;
            vuint32_t IFEE28:1;
            vuint32_t IFEE27:1;
            vuint32_t IFEE26:1;
            vuint32_t IFEE25:1;
            vuint32_t IFEE24:1;
            vuint32_t IFEE23:1;
            vuint32_t IFEE22:1;
            vuint32_t IFEE21:1;
            vuint32_t IFEE20:1;
            vuint32_t IFEE19:1;
            vuint32_t IFEE18:1;
            vuint32_t IFEE17:1;
            vuint32_t IFEE16:1;
            vuint32_t IFEE15:1;
            vuint32_t IFEE14:1;
            vuint32_t IFEE13:1;
            vuint32_t IFEE12:1;
            vuint32_t IFEE11:1;
            vuint32_t IFEE10:1;
            vuint32_t IFEE9:1;
            vuint32_t IFEE8:1;
            vuint32_t IFEE7:1;
            vuint32_t IFEE6:1;
            vuint32_t IFEE5:1;
            vuint32_t IFEE4:1;
            vuint32_t IFEE3:1;
            vuint32_t IFEE2:1;
            vuint32_t IFEE1:1;
            vuint32_t IFEE0:1;
        } B;
    } IFEER;
    union { /* Interrupt Filter Enable (Base+0x0030) */
        vuint32_t R;
        struct {
            vuint32_t IFE31:1;
            vuint32_t IFE30:1;
            vuint32_t IFE29:1;
            vuint32_t IFE28:1;
            vuint32_t IFE27:1;
            vuint32_t IFE26:1;
            vuint32_t IFE25:1;
            vuint32_t IFE24:1;
            vuint32_t IFE23:1;
            vuint32_t IFE22:1;
            vuint32_t IFE21:1;
            vuint32_t IFE20:1;
            vuint32_t IFE19:1;
            vuint32_t IFE18:1;
            vuint32_t IFE17:1;
            vuint32_t IFE16:1;
            vuint32_t IFE15:1;
            vuint32_t IFE14:1;
            vuint32_t IFE13:1;
            vuint32_t IFE12:1;
            vuint32_t IFE11:1;
            vuint32_t IFE10:1;
            vuint32_t IFE9:1;
            vuint32_t IFE8:1;
            vuint32_t IFE7:1;
            vuint32_t IFE6:1;
            vuint32_t IFE5:1;
            vuint32_t IFE4:1;
            vuint32_t IFE3:1;
            vuint32_t IFE2:1;
            vuint32_t IFE1:1;
            vuint32_t IFE0:1;
        } B;
    } IFER;
    vuint8_t SIU_reserved3[12]; /* Reserved 4 Bytes (Base+0x0034-0x003F) */
    union { /* Pad Configuration 0..235 (Base+0x0040-0x0216)*/
        vuint16_t R;
        struct {
            vuint16_t HYS:1;
            vuint16_t SMC:1;
            vuint16_t APC:1;
	    vuint16_t :1;
            vuint16_t PA:2;
            vuint16_t OBE:1;
            vuint16_t IBE:1;
            vuint16_t DSC:2;
            vuint16_t ODE:1;
            vuint16_t SRC:3;
            vuint16_t WPE:1;
            vuint16_t WPS:1;
        } B;
    } PCR[233];
    vuint8_t SIU_reserved4[750]; /*Reserved  Bytes (Base+0x0540-0x0600) */
    union { /* Pad Selection for Mux Input (0x0500-0x53C) */
        vuint8_t R;
        struct {
            vuint8_t :4;
            vuint8_t PADSEL:4;
        } B;
    } PSMI[60];
    vuint8_t SIU_reserved5[196]; /*Reserved 188 Bytes (Base+0x06EC-0x07FF) */
    union { /* GPIO Pad Data Output (Base+0x0600-0x06C7) */
        vuint8_t R;
        struct {
            vuint8_t :7;
            vuint8_t PDO:1;
        } B;
    } GPDO[235];
    vuint8_t SIU_reserved6[277]; /*Reserved 312 Bytes (Base+0x06C8-0x07FF) */
    union { /* GPIO Pad Data Input (Base+0x0800-0x08E8) */
        vuint8_t R;
        struct {
            vuint8_t :7;
            vuint8_t PDI:1;
        } B;
    } GPDI[235];
    vuint8_t SIU_reserved7[788]; /*Reserved 787 Bytes (Base+0x08EC-0x0BFF) */
    union { /* Parallel GPIO Pad Data Out 0-6 (0x0C00-0xC01C) */
        vuint32_t R;
        struct {
            vuint32_t PPD0:32;
        } B;
    } PGPDO[8];
    vuint8_t SIU_reserved8[32]; /* Reserved 35 Bytes (Base+0x0C20-0x0C3F) */
    union { /* Parallel GPIO Pad Data In 0-6 (0x0C40-0x0C5C) */
        vuint32_t R;
        struct {
            vuint32_t PPDI:32;
        } B;
    } PGPDI[8];
    vuint8_t SIU_reserved9[32]; /* Reserved 35 Bytes (Base+0x0C60-0x0C7F) */
    union { /* Masked Parallel GPIO Pad Data Out 0-12 (0x0C80-0x0CB0) */
        vuint32_t R;
        struct {
            vuint32_t MASK:16;
            vuint32_t MPPDO:16;
        } B;
    } MPGPDO[16];
    vuint8_t SIU_reserved10[831]; /*Reserved 831 Bytes (Base+0x0CC0-0x0FFF)*/
    union { /* Interrupt Filter Max Counter 0..23 (+0x1000-0x105C) */
        vuint32_t R;
        struct {
            vuint32_t :28;
            vuint32_t MAXCNT:4;
        } B;
    } IFMC[32];
//    vuint8_t SIU_reserved11[32]; /* Reserved 32 Bytes (Base+0x1084-0x10FF)*/
    union { /* Interrupt Filter Clock Prescaler (Base+0x1080) */
        vuint32_t R;
        struct {
            vuint32_t :28;
            vuint32_t IFCP:4;
        } B;
    } IFCPR;
    vuint8_t SIU_reserved12[124]; /* Reserved 124 Bytes (+0x1084-0x10FF)*/
    union { /* Parallel Input Select 0..15 (+0x1100-0x113C) */
        vuint32_t R;
        struct {
            vuint32_t IPS0:4;
            vuint32_t IPS1:4;
            vuint32_t IPS2:4;
            vuint32_t IPS3:4;
            vuint32_t IPS4:4;
            vuint32_t IPS5:4;
            vuint32_t IPS6:4;
            vuint32_t IPS7:4;
        } B;
    } PISR[16];
    vuint8_t SIU_reserved13[192]; /*Reserved 192 Bytes (Base+0x1140-0x11FF)*/
    union { /* DSPI Input Select (Base+0x1200) */
        vuint32_t R;
        struct {
            vuint32_t SINSEL0:2;
            vuint32_t SSSSEL0:2;
            vuint32_t SCKSEL0:2;
            vuint32_t TRIGSEL0:2;
            vuint32_t SINSEL1:2;
            vuint32_t SSSSEL1:2;
            vuint32_t SCKSEL1:2;
            vuint32_t TRIGSEL1:2;
            vuint32_t SINSEL2:2;
            vuint32_t SSSSEL2:2;
            vuint32_t SCKSEL2:2;
            vuint32_t TRIGSEL2:2;
            vuint32_t SINSEL3:2;
            vuint32_t SSSSEL3:2;
            vuint32_t SCKSEL3:2;
            vuint32_t TRIGSEL3:2;
        } B;
    } DISR;
}; /* end of SIU_tag */
/****************************************************************************/
/*                          MODULE : SSCM                                   */
/****************************************************************************/
struct SSCM_tag{
    union { /* Status (Base+0x0000) */
        vuint16_t R;
        struct {
            vuint16_t LSM:1;
            vuint16_t CER:1;
            vuint16_t :1;
            vuint16_t NXEN1:1;
            vuint16_t NXEN:1;
            vuint16_t PUB:1;
	    vuint16_t SEC:1;
	    vuint16_t :1;
            vuint16_t BMODE:3;
            vuint16_t VLE:1;
	    vuint16_t ABD:1;
            vuint16_t :3;
        } B;
    } STATUS ;
    union { /* System Memory Configuration (Base+0x002) */
        vuint16_t R;
        struct {
            vuint16_t JPIN:10;
            vuint16_t ILVD:1;
            vuint16_t MREV:4;
            vuint16_t DVLD:1;
        } B;
    } MEMCONFIG;
    vuint8_t SSCM_reserved0[2]; /* Reserved 2 bytes (Base+0x0004-0x0005) */
    union { /* Error Configuration (Base+0x0006) */
        vuint16_t R;
        struct {
            vuint16_t :14;
            vuint16_t PAE:1;
            vuint16_t RAE:1;
        } B;
    } ERROR;
    union { /* Debug Status Port (Base+0x0008) */
        vuint16_t R;
        struct {
            vuint16_t :13;
            vuint16_t DEBUG_MODE:3;
        } B;
    } DEBUGPORT;
    vuint8_t SSCM_reserved1[2]; /* Reserved 2 bytes (Base+0x000A-0x000B) */
    union { /* Password Comparison High Word (Base+0x000C) */
	vuint32_t R;
	struct {
	    vuint32_t PWD_HI:32;
        } B;
    } PWCMPH;
    union { /* Password Comparison Low Word (Base+0x0010)*/
	vuint32_t R;
	struct {
	    vuint32_t PWD_LO:32;
        } B;
    } PWCMPL;
    vuint8_t SSCM_reserved2[4]; /* Reserved 2 bytes (Base+0x0014-0x0017) */
    union { /* DPM Boot Register (Base+0x0018)*/
	vuint32_t R;
	struct {
	    vuint32_t P2BOOT:30;
	    vuint32_t DVLE:1;
	    vuint32_t :1;
        } B;
    } DPMBOOT;
    union { /* DPM Boot Key Register (Base+0x001C)*/
	vuint32_t R;
	struct {
	    vuint32_t :16;
	    vuint32_t KEY:16;
        } B;
    } DPMKEY;
    union { /* User Option Status (Base+0x0020)*/
	vuint32_t R;
	struct {
	    vuint32_t UOPT:32;
        } B;
    } UOPS;
    union { /* SSCM CONTROL Status (Base+0x0024)*/
	vuint32_t R;
	struct {
	    vuint32_t :30;
	    vuint32_t DSL:1;
	    vuint32_t DSM:1;
        } B;
    } SCTR;
    union { /* SSCM PROCESSOR START ADDRESS REGISTER (Base+0x0028)*/
	vuint32_t R;
	struct {
	    vuint32_t SADR:32;
        } B;
    } PSAR;
    union { /* SSCM CODE LENGHT REGISTER (Base+0x002C)*/
	vuint32_t R;
	struct {
	    vuint32_t CL:32;
        } B;
    } CLR;
}; /* end of SSCM_tag */
/****************************************************************************/
/*          MODULE : STCU (Self-Test Control Unit)                          */
/****************************************************************************/
struct STCU_tag {
    union { /* STCU Run (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t :31;
            vuint32_t RUN:1;
        } B;
    } RUN;
    vuint8_t STCU_reserved0[8]; /* Reserved 8 bytes (Base+0x0004-0x000B) */
    union { /* STCU Config (Base+0x000C) */
        vuint32_t R;
        struct {
            vuint32_t :1;
            vuint32_t PTR:7;
            vuint32_t :14;
            vuint32_t FM:1;
            vuint32_t BYP:1;
            vuint32_t :4;
            vuint32_t CLK_CFG:4;
        } B;
    } CFG;
    union { /* STCU Watchdog Granularity (Base+0x0010) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t GLBIST:13;
            vuint32_t GMBIST:3;
        } B;
    } WDGG;
    union { /* STCU CRC Expected Status (Base+0x0014) */
        vuint32_t R;
        struct {
            vuint32_t CRCE:32;
        } B;
    } CRCE;
    union { /* STCU CRC Read Status (Base+0x0018) */
        vuint32_t R;
        struct {
            vuint32_t CRCR:32;
        } B;
    } CRCR;
    union { /* STCU Error (Base+0x001C) */
        vuint32_t R;
        struct {
            vuint32_t :4;
            vuint32_t WDTOSFM:1;
            vuint32_t CRCSSFM:1;
            vuint32_t ENGESFM:1;
            vuint32_t INVPSFM:1;
            vuint32_t :4;
            vuint32_t WDTOCFM:1;
            vuint32_t CRCSCFM:1;
            vuint32_t ENGECFM:1;
            vuint32_t INVPCFM:1;
            vuint32_t :5;
            vuint32_t CFSF:1;
            vuint32_t NCFSF:1;
            vuint32_t SIRSF:1;
            vuint32_t :4;
            vuint32_t WDTO:1;
            vuint32_t CRCS:1;
            vuint32_t ENGE:1;
            vuint32_t INVP:1;
        } B;
    } ERR;
    vuint8_t STCU_reserved1[4]; /* Reserved 4 bytes (Base+0x0020) */
    union { /* STCU LBIST Status Register (Base+0x0024) */
        vuint32_t R;
        struct {
            vuint32_t :27;
            vuint32_t LBS4:1;
            vuint32_t LBS3:1;
            vuint32_t LBS2:1;
            vuint32_t LBS1:1;
            vuint32_t LBS0:1;
        } B;
    } LBS;
    union { /* STCU MBIST End Flag Register (Base+0x0028) */
        vuint32_t R;
        struct {
            vuint32_t :27;
	    vuint32_t LBE4:1;
	    vuint32_t LBE3:1;
            vuint32_t LBE2:1;
            vuint32_t LBE1:1;
            vuint32_t LBE0:1;
        } B;
    } LBE;
    vuint8_t STCU_reserved2[4]; /* Reserved 4 bytes (Base+0x002C) */
    union { /* STCU LBIST Critical FM Register (Base+0x0030) */
        vuint32_t R;
        struct {
            vuint32_t :1;
            vuint32_t LBCFM4:1;
            vuint32_t LBCFM3:1;
            vuint32_t LBCFM2:1;
            vuint32_t LBCFM1:1;
            vuint32_t LBCFM0:1;
        } B;
    } LBCFM;
    union { /* STCU LBIST Stay-In-Reset Register (Base+0x0034) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t LBSFM15:1;
            vuint32_t LBSFM14:1;
            vuint32_t LBSFM13:1;
	    vuint32_t LBSFM12:1;
	    vuint32_t LBSFM11:1;
	    vuint32_t LBSFM10:1;
	    vuint32_t LBSFM9:1;
	    vuint32_t LBSFM8:1;
	    vuint32_t LBSFM7:1;
	    vuint32_t LBSFM6:1;
	    vuint32_t LBSFM5:1;
	    vuint32_t LBSFM4:1;
	    vuint32_t LBSFM3:1;
	    vuint32_t LBSFM2:1;
	    vuint32_t LBSFM1:1;
	    vuint32_t LBSFM0:1;
        } B;
    } LBSFM;
    vuint8_t STCU_reserved3[4]; /* Reserved bytes (Base+0x0038) */
    union { /* STCU MBIST Status Low (Base+0x003C) */
        vuint32_t R;
        struct {
            vuint32_t MBS31:1;
            vuint32_t MBS30:1;
            vuint32_t MBS29:1;
            vuint32_t MBS28:1;
            vuint32_t MBS27:1;
            vuint32_t MBS26:1;
            vuint32_t MBS25:1;
            vuint32_t MBS24:1;
            vuint32_t MBS23:1;
            vuint32_t MBS22:1;
            vuint32_t MBS21:1;
            vuint32_t MBS20:1;
            vuint32_t MBS19:1;
            vuint32_t MBS18:1;
            vuint32_t MBS17:1;
            vuint32_t MBS16:1;
            vuint32_t MBS15:1;
            vuint32_t MBS14:1;
            vuint32_t MBS13:1;
            vuint32_t MBS12:1;
            vuint32_t MBS11:1;
            vuint32_t MBS10:1;
            vuint32_t MBS9:1;
            vuint32_t MBS8:1;
            vuint32_t MBS7:1;
            vuint32_t MBS6:1;
            vuint32_t MBS5:1;
            vuint32_t MBS4:1;
            vuint32_t MBS3:1;
            vuint32_t MBS2:1;
            vuint32_t MBS1:1;
            vuint32_t MBS0:1;
        } B;
    } MBSL;
    union { /* STCU MBIST Status High (Base+0x0040) */
        vuint32_t R;
        struct {
            vuint32_t :29;
            vuint32_t MBS34:1;
            vuint32_t MBS33:1;
            vuint32_t MBS32:1;
        } B;
    } MBSH;
    union { /* STCU MBIST End Flag Low (Base+0x0044) */
        vuint32_t R;
        struct {
            vuint32_t MBE31:1;
            vuint32_t MBE30:1;
            vuint32_t MBE29:1;
            vuint32_t MBE28:1;
            vuint32_t MBE27:1;
            vuint32_t MBE26:1;
            vuint32_t MBE25:1;
            vuint32_t MBE24:1;
            vuint32_t MBE23:1;
            vuint32_t MBE22:1;
            vuint32_t MBE21:1;
            vuint32_t MBE20:1;
            vuint32_t MBE19:1;
            vuint32_t MBE18:1;
            vuint32_t MBE17:1;
            vuint32_t MBE16:1;
            vuint32_t MBE15:1;
            vuint32_t MBE14:1;
            vuint32_t MBE13:1;
            vuint32_t MBE12:1;
            vuint32_t MBE11:1;
            vuint32_t MBE10:1;
            vuint32_t MBE9:1;
            vuint32_t MBE8:1;
            vuint32_t MBE7:1;
            vuint32_t MBE6:1;
            vuint32_t MBE5:1;
            vuint32_t MBE4:1;
            vuint32_t MBE3:1;
            vuint32_t MBE2:1;
            vuint32_t MBE1:1;
            vuint32_t MBE0:1;
        } B;
    } MBEL;
    union { /* STCU MBIST End Flag High (Base+0x0048) */
        vuint32_t R;
        struct {
            vuint32_t :29;
            vuint32_t MBE34:1;
            vuint32_t MBE33:1;
            vuint32_t MBE32:1;
        } B;
    } MBEH;
    vuint8_t STCU_reserved4[4]; /* Reserved 4 bytes (Base+0x004C) */
    union { /* STCU MBIST Critical FM Low (Base+0x0050) */
        vuint32_t R;
        struct {
            vuint32_t MBCFM31:1;
            vuint32_t MBCFM30:1;
            vuint32_t MBCFM29:1;
            vuint32_t MBCFM28:1;
            vuint32_t MBCFM27:1;
            vuint32_t MBCFM26:1;
            vuint32_t MBCFM25:1;
            vuint32_t MBCFM24:1;
            vuint32_t MBCFM23:1;
            vuint32_t MBCFM22:1;
            vuint32_t MBCFM21:1;
            vuint32_t MBCFM20:1;
            vuint32_t MBCFM19:1;
            vuint32_t MBCFM18:1;
            vuint32_t MBCFM17:1;
            vuint32_t MBCFM16:1;
            vuint32_t MBCFM15:1;
            vuint32_t MBCFM14:1;
            vuint32_t MBCFM13:1;
            vuint32_t MBCFM12:1;
            vuint32_t MBCFM11:1;
            vuint32_t MBCFM10:1;
            vuint32_t MBCFM9:1;
            vuint32_t MBCFM8:1;
            vuint32_t MBCFM7:1;
            vuint32_t MBCFM6:1;
            vuint32_t MBCFM5:1;
            vuint32_t MBCFM4:1;
            vuint32_t MBCFM3:1;
            vuint32_t MBCFM2:1;
            vuint32_t MBCFM1:1;
            vuint32_t MBCFM0:1;
        } B;
    } MBCFML;
    union { /* STCU MBIST Critical FM High (Base+0x0054) */
        vuint32_t R;
        struct {
            vuint32_t :29;
            vuint32_t MBCFM34:1;
            vuint32_t MBCFM33:1;
            vuint32_t MBCFM32:1;
        } B;
    } MBCFMH;
    union { /* STCU MBIST Stay-In-Reset FM Low (Base+0x0058)*/
        vuint32_t R;
        struct {
            vuint32_t MBSFM31:1;
            vuint32_t MBSFM30:1;
            vuint32_t MBSFM29:1;
            vuint32_t MBSFM28:1;
            vuint32_t MBSFM27:1;
            vuint32_t MBSFM26:1;
            vuint32_t MBSFM25:1;
            vuint32_t MBSFM24:1;
            vuint32_t MBSFM23:1;
            vuint32_t MBSFM22:1;
            vuint32_t MBSFM21:1;
            vuint32_t MBSFM20:1;
            vuint32_t MBSFM19:1;
            vuint32_t MBSFM18:1;
            vuint32_t MBSFM17:1;
            vuint32_t MBSFM16:1;
            vuint32_t MBSFM15:1;
            vuint32_t MBSFM14:1;
            vuint32_t MBSFM13:1;
            vuint32_t MBSFM12:1;
            vuint32_t MBSFM11:1;
            vuint32_t MBSFM10:1;
            vuint32_t MBSFM9:1;
            vuint32_t MBSFM8:1;
            vuint32_t MBSFM7:1;
            vuint32_t MBSFM6:1;
            vuint32_t MBSFM5:1;
            vuint32_t MBSFM4:1;
            vuint32_t MBSFM3:1;
            vuint32_t MBSFM2:1;
            vuint32_t MBSFM1:1;
            vuint32_t MBSFM0:1;
        } B;
    } MBSFML;
    union { /* STCU MBIST Stay-In-Reset FM High (Base+0x005C) */
        vuint32_t R;
        struct {
            vuint32_t :29;
            vuint32_t MBSFM34:1;
            vuint32_t MBSFM33:1;
            vuint32_t MBSFM32:1;
        } B;
    } MBSFMH;
    vuint8_t STCU_reserved5[32]; /* Reserved 8 bytes (Base+0x0060 - 0x007F) */
    union { /* STCU LBIST Control Register (Base+0x0080) */
        vuint32_t R;
        struct {
            vuint32_t :1;
            vuint32_t PTR:7;
            vuint32_t :5;
	    vuint32_t SHS:3;
            vuint32_t SCEN_OFF:4;
	    vuint32_t SCEN_ON:4;
            vuint32_t :5;
	    vuint32_t CWS:3;
        } B;
    } LB_CTRL;
    vuint8_t STCU_reserved6[4]; /* Reserved 4 bytes (Base+0x0084) */
    union { /* STCU LBIST MISR Expected Low Register 0 (Base+0x0088) */
        vuint32_t R;
        struct {
            vuint32_t MISREL:32;
        } B;
    } LB_MISREL0;
    union { /* STCU LBIST MISR Expected High Register 0 (Base+0x008C) */
        vuint32_t R;
        struct {
            vuint32_t MISREH:32;
        } B;
    } LB_MISREH0;
    union { /* STCU LBIST MISR Read Low Register 0 (Base+0x0090) */
        vuint32_t R;
        struct {
            vuint32_t MISRRL:32;
        } B;
    } LB_MISRRL0;
    union { /* STCU LBIST MISR Read High Register 0 (Base+0x0094) */
        vuint32_t R;
        struct {
            vuint32_t MISRRH:32;
        } B;
    } LB_MISRRH0;
    vuint8_t STCU_reserved7[8]; /*Reserved 8 bytes (Base+0x0098-0x009F) */
    union { /* STCU MBIST Control (Base+0x00A0) */
        vuint32_t R;
        struct {
            vuint32_t :1;
            vuint32_t PTR:7;
            vuint32_t :5;
	    vuint32_t SHS:3;
            vuint32_t SCEN_OFF:4;
	    vuint32_t SCEN_ON:4;
            vuint32_t :5;
	    vuint32_t CWS:3;
        } B;
    } LB_CTRL1;
    vuint8_t STCU_reserved8[4]; /*Reserved 4 bytes (Base+0x00A4) */
    union { /* STCU LBIST MISR Expected Low Register 1 (Base+0x00A8) */
        vuint32_t R;
        struct {
            vuint32_t MISREL:32;
        } B;
    } LB_MISREL1;
    union { /* STCU LBIST MISR Expected High Register 1 (Base+0x00AC) */
        vuint32_t R;
        struct {
            vuint32_t MISREH:32;
        } B;
    } LB_MISREH1;
    union { /* STCU LBIST MISR Read Low Register 1 (Base+0x00B0) */
        vuint32_t R;
        struct {
            vuint32_t MISRRL:32;
        } B;
    } LB_MISRRL1;
    union { /* STCU LBIST MISR Read High Register 1 (Base+0x00B4) */
        vuint32_t R;
        struct {
            vuint32_t MISRRH:32;
        } B;
    } LB_MISRRH1;
    vuint8_t STCU_reserved9[8]; /*Reserved 4 bytes (Base+0x00B8-0x00BF) */
    union { /* STCU MBIST Control 2 (Base+0x00C0) */
        vuint32_t R;
        struct {
            vuint32_t :1;
            vuint32_t PTR:7;
            vuint32_t :5;
	    vuint32_t SHS:3;
            vuint32_t SCEN_OFF:4;
	    vuint32_t SCEN_ON:4;
            vuint32_t :5;
	    vuint32_t CWS:3;
        } B;
    } LB_CTRL2;
    vuint8_t STCU_reserved10[4]; /*Reserved 4 bytes (Base+0x00C4) */
    union { /* STCU LBIST MISR Expected Low Register 2 (Base+0x00C8) */
        vuint32_t R;
        struct {
            vuint32_t MISREL:32;
        } B;
    } LB_MISREL2;
    union { /* STCU LBIST MISR Expected High Register 2 (Base+0x00CC) */
        vuint32_t R;
        struct {
            vuint32_t MISREH:32;
        } B;
    } LB_MISREH2;
    union { /* STCU LBIST MISR Read Low Register 2 (Base+0x00D0) */
        vuint32_t R;
        struct {
            vuint32_t MISRRL:32;
        } B;
    } LB_MISRRL2;
    union { /* STCU LBIST MISR Read High Register 2 (Base+0x00D4) */
        vuint32_t R;
        struct {
            vuint32_t MISRRH:32;
        } B;
    } LB_MISRRH2;
    vuint8_t STCU_reserved11[4]; /*Reserved 4 bytes  */
    union { /* STCU MBIST Control (Base+0x0300) */
        vuint32_t R;
        struct {
            vuint32_t :1;
            vuint32_t PTR:7;
            vuint32_t :2;
	    vuint32_t MB_TIME:6;
	    vuint32_t :16;
        } B;
    } MB_CTRL;
    vuint8_t STCU_reserved12[31996]; /* 31996 bytes (Base+0x0304-0x7FFF) */
}; /* end of STCU_tag */
/****************************************************************************/
/*                          MODULE : STM                                   */
/****************************************************************************/
struct STM_CHANNEL_tag{
    union { /* STM Channel Control 0..3 */
        vuint32_t R;
        struct {
            vuint32_t :31;
            vuint32_t CEN:1;
        } B;
    } CCR;
    union { /* STM Channel Interrupt 0..3 */
        vuint32_t R;
        struct {
            vuint32_t :31;
            vuint32_t CIF:1;
        } B;
    } CIR;
    union { /* STM Channel Compare 0..3 */
        vuint32_t R;
        struct {
            vuint32_t CMP:32;
        } B;
    } CMP;
    vuint8_t STM_CHANNEL_reserved0[4]; /* Reserved 4 bytes between ch reg's */
}; /* end of STM_CHANNEL_tag */
struct STM_tag{
    union { /* STM Control (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CPS:8;
            vuint32_t :6;
            vuint32_t FRZ:1;
            vuint32_t TEN:1;
        } B;
    } CR;
    union { /* STM Count (Base+0x0004) */
        vuint32_t R;
    } CNT;
    vuint8_t STM_reserved1[8]; /* Reserved 8 bytes (Base+0x0008-0x000F) */
    struct STM_CHANNEL_tag CH[4]; /*STM Channels 0..3 (Base+0x0010-0x0048) */
}; /* end of STM_tag */
/****************************************************************************/
/*                          MODULE : SWT                                   */
/****************************************************************************/
struct SWT_tag{
    union { /* SWT Control (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t MAP0:1;
            vuint32_t MAP1:1;
            vuint32_t MAP2:1;
            vuint32_t MAP3:1;
            vuint32_t MAP4:1;
            vuint32_t MAP5:1;
            vuint32_t MAP6:1;
            vuint32_t MAP7:1;
            vuint32_t :14;
	    vuint32_t KEY:1;
            vuint32_t RIA:1;
            vuint32_t WND:1;
            vuint32_t ITR:1;
            vuint32_t HLK:1;
            vuint32_t SLK:1;
            vuint32_t CSL:1;
            vuint32_t STP:1;
            vuint32_t FRZ:1;
            vuint32_t WEN:1;
        } B;
    } CR;
    union { /* SWT Interrupt (Base+0x0004) */
        vuint32_t R;
        struct {
            vuint32_t :31;
            vuint32_t TIF:1;
        } B;
    } IR;
    union { /* SWT Time-Out (Base+0x0008) */
        vuint32_t R;
        struct {
            vuint32_t WTO:32;
        } B;
    } TO;
    union { /* SWT Window (Base+0x000C) */
        vuint32_t R;
        struct {
            vuint32_t WST:32;
        } B;
    } WN;
    union { /* SWT Service (Base+0x0010) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t WSC:16;
        } B;
    } SR;
    union { /* SWT Counter Output (Base+0x0014) */
        vuint32_t R;
        struct {
            vuint32_t CNT:32;
        } B;
    } CO;
    union { /* SWT Service Key (Base+0x0018) */
        vuint32_t R; /*  New for Bolero 3M  */
        struct {
            vuint32_t :16;
            vuint32_t SK:16;
        } B;
    } SK;
}; /* end of SWT_tag */
/****************************************************************************/
/*                          MODULE : TSENS                                   */
/****************************************************************************/
struct TSENS_tag{
    union { /* TSENS CALCULATOIN CONSTANT REGISTER 0 (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t TSCV2:16;
            vuint32_t TSCV1:16;
        } B;
    } TCCR0;
    union { /* TSENS CALCULATOIN CONSTANT REGISTER 1 (Base+0x0000) */
        vuint32_t R;
        struct {
	    vuint32_t :2;
	    vuint32_t TSCV3:14;
	    vuint32_t :16;
        } B;
    } TCCR1;
}; /* end of TSENS_tag */
/****************************************************************************/
/*                          MODULE : WKUP                                   */
/****************************************************************************/
struct WKUP_tag{
    union { /* NMI Status Flag (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t NIF:1;
            vuint32_t NOVF:1;
            vuint32_t :30;
        } B;
    } NSR;
    vuint8_t WKUP_reserved0[4]; /* Reserved 4 Bytes (Base+0x0004-0x0007) */
    union { /* NMI Configuration (Base+0x0008) */
        vuint32_t R;
        struct {
            vuint32_t NLOCK:1;
            vuint32_t NDSS:2;
            vuint32_t NWRE:1;
            vuint32_t :1;
            vuint32_t NREE:1;
            vuint32_t NFEE:1;
            vuint32_t NFE:1;
            vuint32_t :24;
        } B;
    } NCR;
    vuint8_t WKUP_reserved1[16372]; /* Reserved 16328 (Base+0x000C-0x3FFF) */
}; /* end of WKUP_tag */
/****************************************************************************/
/*                          MODULE : XBAR                                   */
/****************************************************************************/
struct XBAR_tag{
    union { /* Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } MPR0;
    union { /* ALTERNATE Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } AMPR0;
    /* Register layout for all registers SGPCR... */
    int32_t XBAR_reserved0[2]; /* (0x008 - 0x00F)/4 = 0x02 */
    union { /* MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t RO:1; /* Read Only */
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } SGPCR0;
    union { /* ALTERNATE MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } ASGPCR0;

    int32_t XBAR_reserved1[58]; /* (0x018 - 0x100)/4 = 0x058 */
    
    union { /* Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } MPR1;
    union { /* ALTERNATE Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } AMPR1;
    /* Register layout for all registers SGPCR... */
    int32_t XBAR_reserved2[2]; /* (0x008 - 0x00F)/4 = 0x02 */
    union { /* MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t RO:1; /* Read Only */
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } SGPCR1;
    union { /* ALTERNATE MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } ASGPCR1;

    int32_t XBAR_reserved3[58]; /* (0x118 - 0x200)/4 = 0x058 */
    
    union { /* Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } MPR2;
    union { /* ALTERNATE Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } AMPR2;
    /* Register layout for all registers SGPCR... */
    int32_t XBAR_reserved4[2]; /* (0x204 - 0x20F)/4 = 0x03 */
    union { /* MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t RO:1; /* Read Only */
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } SGPCR2;
    union { /* ALTERNATE MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } ASGPCR2;
   
    int32_t XBAR_reserved5[58]; /* (0x0218 - 0x2FF)/4 = 0x02 */
    
    union { /* Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } MPR3;
    union { /* ALTERNATE Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } AMPR3;
    /* Register layout for all registers SGPCR... */
    int32_t XBAR_reserved6[2]; /* (0x308 - 0x30F)/4 = 0x02 */
    union { /* MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t RO:1; /* Read Only */
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } SGPCR3;
    union { /* ALTERNATE MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } ASGPCR3;

   int32_t XBAR_reserved7[58]; /* (0x318 - 0x400)/4 = 0x058 */

     union { /* Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } MPR4;
    union { /* ALTERNATE Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } AMPR4;
    /* Register layout for all registers SGPCR... */
    int32_t XBAR_reserved8[2]; /* (0x008 - 0x00F)/4 = 0x02 */
    union { /* MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t RO:1; /* Read Only */
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } SGPCR4;
    union { /* ALTERNATE MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } ASGPCR4;

   int32_t XBAR_reserved9[58]; /* (0x418 - 0x500)/4 = 0x058 */

    union { /* Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } MPR5;
    union { /* ALTERNATE Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } AMPR5;
    /* Register layout for all registers SGPCR... */
    int32_t XBAR_reserved10[2]; /* (0x008 - 0x00F)/4 = 0x02 */
    union { /* MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t RO:1; /* Read Only */
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } SGPCR5;
    union { /* ALTERNATE MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } ASGPCR5;

   int32_t XBAR_reserved11[58]; /* (0x518 - 0x600)/4 = 0x058 */
    
    union { /* Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } MPR6;
    union { /* ALTERNATE Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } AMPR6;
    /* Register layout for all registers SGPCR... */
    int32_t XBAR_reserved12[2]; /* (0x008 - 0x00F)/4 = 0x02 */
    union { /* MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t RO:1; /* Read Only */
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } SGPCR6;
    union { /* ALTERNATE MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } ASGPCR6;

   int32_t XBAR_reserved13[58]; /* (0x618 - 0x700)/4 = 0x058 */

    union { /* Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } MPR7;
    union { /* ALTERNATE Master Priority Register for slave port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t MSTR_7:3; /* Master 7 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_6:3; /* Master 6 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_5:3; /* Master 5 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_4:3; /* Master 4 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_3:3; /* Master 3 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_2:3; /* Master 2 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_1:3; /* Master 1 Priority */
	    vuint32_t:1;
	    vuint32_t MSTR_0:3; /* Master 0 Priority */
	} B;
    } AMPR7;
    /* Register layout for all registers SGPCR... */
    int32_t XBAR_reserved14[2]; /* (0x708 - 0x70F)/4 = 0x02 */
    union { /* MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t RO:1; /* Read Only */
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } SGPCR7;
    union { /* ALTERNATE MAX General Purpose Control Register for Slave Port n */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t HLP:1; /* Halt Low Priority */
	    vuint32_t:6;
	    vuint32_t HPE7:1; /* High Priority Enable */
	    vuint32_t HPE6:1; /* High Priority Enable */
	    vuint32_t HPE5:1; /* High Priority Enable */
	    vuint32_t HPE4:1; /* High Priority Enable */
	    vuint32_t HPE3:1; /* High Priority Enable */
	    vuint32_t HPE2:1; /* High Priority Enable */
	    vuint32_t HPE1:1; /* High Priority Enable */
	    vuint32_t HPE0:1; /* High Priority Enable */
	    vuint32_t:6;
	    vuint32_t ARB:2; /* Arbitration Mode */
	    vuint32_t:2;
	    vuint32_t PCTL:2; /* Parking Control */
	    vuint32_t:1;
	    vuint32_t PARK:3; /* Park */
	} B;
    } ASGPCR7;
    
    int32_t XBAR_reserved15[58]; /* (0x718 - 0x7FF)/4 = 0x02 */

    union { /* MAX_MGPCRn - Master General Purpose Control Register n */
	vuint32_t R;
	struct {
	    vuint32_t:29;
	    vuint32_t AULB:3; /* Arbitrate on Undefined Length Bursts */
	} B;
    } MGPCR0;
    int32_t XBAR_reserved16[63]; /* (0x804 - 0x8FF)/4 = 0x63 */
    union { /* MAX_MGPCRn - Master General Purpose Control Register n */
	vuint32_t R;
	struct {
	    vuint32_t:29;
	    vuint32_t AULB:3; /* Arbitrate on Undefined Length Bursts */
	} B;
    } MGPCR1;
    int32_t XBAR_reserved17[63]; /* (0x904 - 0x9FF)/4 = 0x63 */
    union { /* MAX_MGPCRn - Master General Purpose Control Register n */
	vuint32_t R;
	struct {
	    vuint32_t:29;
	    vuint32_t AULB:3; /* Arbitrate on Undefined Length Bursts */
	} B;
    } MGPCR2;
    int32_t XBAR_reserved18[63]; /* (0xA04 - 0xAFF)/4 = 0x63 */
    union { /* MAX_MGPCRn - Master General Purpose Control Register n */
	vuint32_t R;
	struct {
	    vuint32_t:29;
	    vuint32_t AULB:3; /* Arbitrate on Undefined Length Bursts */
	} B;
    } MGPCR3;
    int32_t XBAR_reserved19[63]; /* (0xB04 - 0xBFF)/4 = 0x63 */
}; /* end of XBAR_tag */
/****************************************************************** 
  | defines and macros (scope: module-local) 
  |-----------------------------------------------------------------*/
/* Define instances of modules (in address order) */

#define ADC_0     (*(volatile struct ADC_tag *)       0xFFE00000UL)     
#define ADC_1     (*(volatile struct ADC_tag *)       0xFFE04000UL)
#define ADC_2     (*(volatile struct ADC_tag *)       0xC3E50000UL)     
#define ADC_3     (*(volatile struct ADC_tag *)       0xC3E54000UL)     
#define CAN_0     (*(volatile struct FLEXCAN_tag *)   0xFFFC0000UL)
#define CAN_1     (*(volatile struct FLEXCAN_tag *)   0xFFFC4000UL)
#define CAN_2     (*(volatile struct FLEXCAN_tag *)   0xFFFC8000UL)
#define CAN_3     (*(volatile struct FLEXCAN_tag *)   0xFFFCC000UL)
#define CFLASH_0  (*(volatile struct CFLASH_tag *)    0xC3F88000UL)
#define CFLASH_1  (*(volatile struct CFLASH_tag *)    0xC3FB0000UL)
#define CFLASH_2  (*(volatile struct CFLASH_tag *)    0xC3FB4000UL)
#define CFLASH_3  (*(volatile struct CFLASH_tag *)    0xC3FB8000UL)
#define CGM       (*(volatile struct CGM_tag *)       0xC3FE0000UL) 
#define CRC_0     (*(volatile struct CRC_tag *)       0xFFE68000UL) 
#define CRC_1     (*(volatile struct CRC_tag *)       0xC3E60000UL)
#define CTU_0     (*(volatile struct CTU_tag *)       0xFFE0C000UL)
#define CTU_1     (*(volatile struct CTU_tag *)       0xC3E5C000UL)
#define DFLASH_0  (*(volatile struct DFLASH_tag *)    0xC3F8C000UL)
#define DMAMUX_0  (*(volatile struct DMAMUX_tag *)    0xFFFDC000UL)
#define DMAMUX_1  (*(volatile struct DMAMUX_tag *)    0xC3FAC000UL)
#define DSPI_0    (*(volatile struct DSPI_tag *)      0xFFF90000UL)  
#define DSPI_1    (*(volatile struct DSPI_tag *)      0xFFF94000UL)  
#define DSPI_2    (*(volatile struct DSPI_tag *)      0xFFF98000UL)
#define EBI       (*(volatile struct EBI_tag *)       0xC3F84000UL)    
#define ECSM_0    (*(volatile struct ECSM_tag *)      0xFFF40000UL)
#define ECSM_1    (*(volatile struct ECSM_tag *)      0x8FF40000UL)
#define EDMA_0    (*(volatile struct EDMA_tag *)      0xFFF44000UL)
#define EDMA_1    (*(volatile struct EDMA_tag *)      0x8FF44000UL)
#define ETIMER_0  (*(volatile struct ETIMER_tag *)    0xFFE18000UL)
#define ETIMER_1  (*(volatile struct ETIMER_tag *)    0xFFE1C000UL) 
#define ETIMER_2  (*(volatile struct ETIMER_tag *)    0xFFE20000UL)    
#define FCCU      (*(volatile struct FCCU_tag *)      0xFFE6C000UL)
#define FEC       (*(volatile struct FEC_tag *)       0xFFF4C000UL)
#define FLEXPWM_0 (*(volatile struct FLEXPWM_tag *)   0xFFE24000UL)
#define FLEXPWM_1 (*(volatile struct FLEXPWM_tag *)   0xFFE28000UL) 
#define FLEXPWM_2 (*(volatile struct FLEXPWM_tag *)   0xC3E74000UL)
//#define FLEXRAY   (*(volatile struct FLEXRAY_tag *)   0xFFFE0000UL) 
#define I2C_0     (*(volatile struct I2C_tag *)       0xFFE30000UL)
#define I2C_1     (*(volatile struct I2C_tag *)       0xFFE34000UL)
#define I2C_2     (*(volatile struct I2C_tag *)       0xFFE38000UL)
#define INTC_0    (*(volatile struct INTC_tag *)      0xFFF48000UL)
#define INTC_1    (*(volatile struct INTC_tag *)      0x8FF48000UL) 
#define LINFLEX_0 (*(volatile struct LINFLEX_tag *)   0xFFE40000UL)
#define LINFLEX_1 (*(volatile struct LINFLEX_tag *)   0xFFE44000UL) 
#define LINFLEX_2 (*(volatile struct LINFLEX_tag *)   0xFFE48000UL) 
#define LINFLEX_3 (*(volatile struct LINFLEX_tag *)   0xFFE4C000UL)
#define MDDRC     (*(volatile struct MDDRC_tag *)     0xC3F98000UL)
#define ME        (*(volatile struct ME_tag *)        0xC3FDC000UL)   
#define MPU_0     (*(volatile struct MPU_tag *)       0xFFF10000UL)
#define MPU_1     (*(volatile struct MPU_tag *)       0x8FF10000UL)    
#define PBRIDGE_0 (*(volatile struct PBRIDGE_tag *)   0xFFF00000UL)
#define PBRIDGE_1 (*(volatile struct PBRIDGE_tag *)   0x8FF00000UL) 
#define PCU       (*(volatile struct PCU_tag *)       0xC3FE8000UL) 
#define PDI       (*(volatile struct PDI_tag *)       0xC3E40000UL)
#define PMC       (*(volatile struct PMC_tag *)       0xC3FE8080UL)
#define PIT       (*(volatile struct PIT_tag *)       0xC3FF0000UL)
#define RGM       (*(volatile struct RGM_tag *)       0xC3FE4000UL)
#define SEMA4_0   (*(volatile struct SEMA4_tag *)     0xFFF24000UL)
#define SEMA4_1   (*(volatile struct SEMA4_tag *)     0x8FF24000UL)
#define SIU       (*(volatile struct SIU_tag *)       0xC3F90000UL)   
#define SSCM      (*(volatile struct SSCM_tag *)      0xC3FD8000UL) 
#define STCU      (*(volatile struct STCU_tag *)      0xC3FF4000UL)
#define STM_0     (*(volatile struct STM_tag *)       0xFFF3C000UL)
#define STM_1     (*(volatile struct STM_tag *)       0x8FF3C000UL)
#define SWT_0     (*(volatile struct SWT_tag *)       0xFFF38000UL)
#define SWT_1     (*(volatile struct SWT_tag *)       0x8FF38000UL)
#define TSENS     (*(volatile struct TSENS_tag *)     0xFFFEC000UL) 
#define WKUP      (*(volatile struct WKUP_tag *)      0xC3F94000UL)
#define XBAR_0    (*(volatile struct XBAR_tag *)      0xFFF04000UL)
#define XBAR_1    (*(volatile struct XBAR_tag *)      0x8FF04000UL)



// Flexray is NOT added to this header. Expected that Flexray is used with drivers. 



#ifdef __MWERKS__
#pragma pop
#endif

#ifdef  __cplusplus
}
#endif

#endif 

/*********************************************************************
 *
 * Copyright:
 *	Freescale Semiconductor, INC. All Rights Reserved.
 *  You are hereby granted a copyright license to use, modify, and
 *  distribute the SOFTWARE so long as this entire notice is
 *  retained without alteration in any modified and/or redistributed
 *  versions, and that such modified versions are clearly identified
 *  as such. No licenses are granted by implication, estoppel or
 *  otherwise under any patents or trademarks of Freescale
 *  Semiconductor, Inc. This software is provided on an "AS IS"
 *  basis and without warranty.
 *
 *  To the maximum extent permitted by applicable law, Freescale
 *  Semiconductor DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED,
 *  INCLUDING IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A
 *  PARTICULAR PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH
 *  REGARD TO THE SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF)
 *  AND ANY ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL Freescale Semiconductor BE LIABLE FOR ANY DAMAGES WHATSOEVER
 *  (INCLUDING WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS,
 *  BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER
 *  PECUNIARY LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  Freescale Semiconductor assumes no responsibility for the
 *  maintenance and support of this software
 *
 ********************************************************************/
/* End of file */
