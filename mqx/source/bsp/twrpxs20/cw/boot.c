#ifdef __cplusplus
extern "C" {
#endif

__declspec(section ".init") extern void __boot(int argc, char **argv, char **envp);  /* primary entry point */
extern asm void __start(register int argc, register char **argv, register char **envp);

#ifdef __cplusplus
}
#endif


asm void __boot(register int argc, register char **argv, register char **envp)
{
	nofralloc  /* explicitly no stack frame allocation */

	// Set the MSR[SPE] bit so code can use "evmergelo" instruction.
	lis r6,0x200
	ori r6,r6,0x0
	mtmsr r6
	isync 

	// 32 64-bit GPR0-31

	lis       r1, 0      // Initialize the lower 32-bits of GPR1 to 0
	
	evmergelo r0,r1,r1   // Initialize the 64-bits of GPR0 to 0
	evmergelo r1,r0,r0   // Continue initializing the other 64-bit GPRs
	evmergelo r2,r0,r0   // ...
	mr		  r1, argc	 // save argc
	evmergelo r3,r0,r0   //
	mr		  r3, r1	 // restore argc
	mr		  r1, argv	 // save argv
	evmergelo r4,r0,r0   //
	mr		  r4, r1	 // restore argv
	mr		  r1, envp	 // save envp
	evmergelo r5,r0,r0   //
	mr		  r5, r1	 // restore envp
	lis       r1, 0      // Re-initialize the lower 32-bits of GPR1 to 0 
	evmergelo r6,r0,r0   //
	evmergelo r7,r0,r0   //
	evmergelo r8,r0,r0   //
	evmergelo r9,r0,r0   //
	evmergelo r10,r0,r0  //
	evmergelo r11,r0,r0  //
	evmergelo r12,r0,r0  // 
	evmergelo r13,r0,r0  //
	evmergelo r14,r0,r0  //
	evmergelo r15,r0,r0  // 
	evmergelo r16,r0,r0  //
	evmergelo r17,r0,r0  //
	evmergelo r18,r0,r0  // 
	evmergelo r19,r0,r0  //
	evmergelo r20,r0,r0  //
	evmergelo r21,r0,r0  // 
	evmergelo r22,r0,r0  //
	evmergelo r23,r0,r0  //
	evmergelo r24,r0,r0  //
	evmergelo r25,r0,r0  //
	evmergelo r26,r0,r0  //
	evmergelo r27,r0,r0  //
	evmergelo r28,r0,r0  //
	evmergelo r29,r0,r0  //
	evmergelo r30,r0,r0  //
	evmergelo r31,r0,r0  // Initialize the 64-bit GPR31 to 0 
	
	mtcrf 0xFF,r29
	mtspr 285,r29       /* TBU     */
	mtspr 284,r29       /* TBL     */
	mtspr 272,r29       /* SPRG1-7 */
	mtspr 273,r29
	mtspr 274,r29
	mtspr 275,r29
	mtspr 276,r29
	mtspr 277,r29
	mtspr 278,r29
	mtspr 279,r29
	mtspr 604,r29       /* SPRG8-9 */
	mtspr 605,r29
	mtspr 26,r29        /* SRR0-1  */
	mtspr 27,r29
	mtspr 58,r29        /* CSRR0-1 */
	mtspr 59,r29
	mtspr 63,r29        /* IVPR    */
	mtspr 61,r29        /* DEAR    */
	mtspr 62,r29        /* ESR     */
	mtspr 570,r29       /* MCSRR0  */
	mtspr 571,r29       /* MCSRR1  */
	mtspr 340,r29       /* TCR     */
	mtspr 512,r29       /* SPEFSCR */

	mtspr 1,r29         /* XER     */
	mtspr 256,r29       /* USPRG0  */
	mtspr 9,r29         /* CTR     */

	mtspr 308,r29       /* DBCR0-6 */
	mtspr 309,r29
	mtspr 310,r29
	mtspr 561,r29
	mtspr 563,r29
	mtspr 564,r29
	mtspr 603,r29

	bl __start  /* call standard application initialization */
}
