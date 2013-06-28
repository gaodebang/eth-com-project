# This configuration script is compatible with PXS30xx devices and
# performs minimal intialization like ECC SRAM, IVORs.
#
# MMU: single 4GB addrss space, BOOKE
# Init SRAM ECC
# Disable Watchdog Timer
# Init IPVR and IVORx

proc changecore {b} {
	set a [switchtarget -quiet -cur]
	if {$b == 0} {set c [expr {$a - 1}]} else {set c [expr {$a + 1}]}	
	switchtarget -quiet $c
} 

proc PXS30xx_booke {} {
  	# GPR registrer group
  	set GPR_GROUP "General Purpose Registers/"
  	# special purpose register group
  	variable SPR_GROUP "e200z760n3 Special Purpose Registers/"
  	#TLB1 registers group
  	variable TLB1_GROUP "regPPCTLB1/"
    
	reset hard

	# Explicitly stop the core
	stop

   	# Setup MMU for entire 4GB address space
	# Base address = 0x0000_0000
	# TLB0, 4 GByte Memory Space, Not Guarded, Cache inhibited, All Access, BOOKE
	reg ${TLB1_GROUP}MMU_CAM0 = 0xB0000000FC0800000000000000000001	

	# Disable Watchdog Timers
	mem v:0xfff38010 = 0x0000C520
	mem v:0xfff38010 = 0x0000D928
	mem v:0xfff38000 = 0x8000010A

    # Set up all interrupt vectors
	reg ${SPR_GROUP}IVPR = 0x40000000
	for {set i 0} {$i < 15} {incr i} {
		reg ${SPR_GROUP}IVOR${i} %d = [expr $i * 0x10]
	}
   
   	# reset watchdog timer
	reg ${SPR_GROUP}TCR = 0x0
	#enable SPE
	reg ${SPR_GROUP}MSR = 0x02000200
	
	# init memory 0x40000080 - 0x4003ffff
	reg ${GPR_GROUP}GPR11 = 0x40000080
	reg ${GPR_GROUP}GPR12 = 0x7ff
	 #mtctr r12
	mem v:0x40000000 = 0x7D8903A6
	 #stmw r0,0(r11)
	mem v:0x40000004 = 0xBC0B0000
	 #addi r11,r11,128
	mem v:0x40000008 = 0x396B0080
	 #bdnz -8
	mem v:0x4000000c = 0x4200FFF8
	 #b 0
	mem v:0x40000010 = 0x48000000
    # set PC
	reg ${GPR_GROUP}PC = 0x40000000
    #wait 1 second for the program to finish
	go 1
	stop

#	# PC at __start_p1 in SSCM.DPMBOOT
#	mem v:0xC3FD8018 = 0x50001068
#	# SSCM.DPMKEY
#	mem v:0xC3FD801C = 0x00005AF0
#	mem v:0xC3FD801C = 0x0000A50F
#
#	changecore 1
#
#	# Explicitly stop the core
#	stop
#
#	# Setup MMU for entire 4GB address space
#	# Base address = 0x0000_0000
#	# TLB0, 4 GByte Memory Space, Not Guarded, Cache inhibited, All Access, BOOKE
#	reg ${TLB1_GROUP}MMU_CAM0 = 0xB0000000FC0800000000000000000001
#
#....# Set up all interrupt vectors
#	reg ${SPR_GROUP}IVPR = 0x50000000
#	for {set i 0} {$i < 15} {incr i} {
#		reg ${SPR_GROUP}IVOR${i} %d = [expr $i * 0x10]
#	}
#
#    #enable SPE
#	reg ${SPR_GROUP}MSR = 0x02000200
#
#	# init memory 0x50000080 - 0x5003ffff
#	reg ${GPR_GROUP}GPR11 = 0x50000080
#	reg ${GPR_GROUP}GPR12 = 0x7ff
#
#	 #mtctr r12
#	mem v:0x50000000 = 0x7D8903A6
#	 #stmw r0,0(r11)
#	mem v:0x50000004 = 0xBD8B0000
#	 #addi r11,r11,128
#	mem v:0x50000008 = 0x396B0080
#	 #bdnz -8
#	change 0x5000000c = 0x4200FFF8
#	 #b 0
#	change 0x50000010 = 0x48000000
#	reg ${GPR_GROUP}PC = 0x50000000
#....#wait 1 second for the program to finish
#	go 1
#	stop
#
#	# PC at __start_p1
#	catch {reg ${GPR_GROUP}PC = [evaluate __start_p1]}
#
#    # set SP to an unaligned (4bytes) to avoid any attempts to unwind
#	reg ${GPR_GROUP}SP = 0x3
#
#	changecore 0

}

proc envsetup {} {
	# Environment Setup
	radix x 
	config hexprefix 0x
	config MemIdentifier v 
	config MemWidth 32 
	config MemAccess 32 
	config MemSwap off
}

#-------------------------------------------------------------------------------
# Main                                                                          
#-------------------------------------------------------------------------------

  envsetup
  PXS30xx_booke
