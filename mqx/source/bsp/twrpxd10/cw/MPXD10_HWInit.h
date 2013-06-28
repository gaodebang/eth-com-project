/*
 * FILE : PXD1010_HWInit.h
 *
 * DESCRIPTION:
 *  This file contains the functions prototypes for initializing the PXD1010 derivative.
 * - SRAM ECC
 * - PCR registers 
 */

#ifndef _PXD1010_M07N_HWINIT_H_
#define _PXD1010_M07N_HWINIT_H_

#define Z0H_CORE        1
#define VLE_IS_ON       1

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************/
/* User hardware initialization for PXD1010 derivative           */
/*******************************************************/ 

/* Derivative specific hardware initializations */
__asm void INIT_Derivative(void); 

/* Set up access to external memory (inc. chip select and MMU) */
__asm void INIT_ExternalBusAndMemory(void);

#ifdef __cplusplus
}
#endif

#endif
