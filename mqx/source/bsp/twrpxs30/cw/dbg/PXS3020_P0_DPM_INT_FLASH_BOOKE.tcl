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

	# reset watchdog timer
	reg ${SPR_GROUP}TCR = 0x0
	#enable SPE
	reg ${SPR_GROUP}MSR = 0x02000200   
	
#	# PC at __start_p1 in SSCM.DPMBOOT
#	mem v:0xC3FD8018 = 0x00004068
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
#	# PC at __start_p1
#	catch {reg ${GPR_GROUP}PC = [evaluate __start_p1]}
#
#	# set SP to an unaligned (4bytes) to avoid any attempts to unwind
#	reg ${GPR_GROUP}SP = 0x3 
#
#	#enable SPE
#	#reg ${SPR_GROUP}MSR = 0x02000200  
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
