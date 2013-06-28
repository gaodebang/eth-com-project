# This configuration script is compatible with PXN devices and
# performs minimal intialization like ECC SRAM, IVORs.
#
# Init SRAM ECC
# Disable Watchdog Timer
# Init IPVR and IVORx
# Init and start second core

proc changecore {b} {
	switchtarget -quiet -pid=$b
}

################################################
# Initialize the Z6 core registers: enable SPE
# reset watchdog timer, invalidate stack pointer
################################################
proc init_z6 {} {
  	# GPR registrer group
  	set GPR_GROUP "General Purpose Registers/"
  	# special purpose register group
  	set SPR_GROUP "e200z6 Special Purpose Registers/"
	puts "init Core0 Z6"
    # set SP to an unaligned (4bytes) to avoid creating
	# invalid stack frames
    reg ${GPR_GROUP}SP = 0x3 
   	# reset watchdog timer
	change ${SPR_GROUP}TCR = 0x0
	#enable SPE
	change ${SPR_GROUP}MSR = 0x02000200
	
	# Set up interrupt vector offsets
	reg ${SPR_GROUP}IVPR = 0x40000000
	for {set i 0} {$i < 15} {incr i} {
		reg ${SPR_GROUP}IVOR${i} %d = [expr $i * 0x10]
	}
	reg ${SPR_GROUP}IVOR32 = 0x100
	reg ${SPR_GROUP}IVOR33 = 0x110
	reg ${SPR_GROUP}IVOR34 = 0x120
}

#################################
# Initialization for e200Z0H core
#################################
proc init_z0 {} {
	puts "init Core1 Z0H"
	# Interrupt vectors IVOR 0-15, these SPRs are hardwired to specific
	# values, and are readable, but a mtspr results in an unimplemented or 
	# privileged exception IVOR 16-31 are reserved.
    variable e200SPR_GROUP "e200z0h Special Purpose Registers/"
    reg ${e200SPR_GROUP}IVPR = 0x40000000
}

#################################################
# Initialize a RAM 'range' from 'start' address,
# downloading the init program at 0x4000_0000.
#################################################
proc init_ram_vle {start range vle_on} {
  	# GPR registrer group
  	set GPR_GROUP "General Purpose Registers/"
    puts "init SRAM $start:$range"
	set pstart 0x40000000
	if {$start == $pstart} {
		# init first 4 bytes (mem access) x 128 = 512
		# bytes to avoid reading the memory around PC
		# after stopping the core
    	mem v:$start 128 = 0xA
		# base init address
		set offset 0x80
		# load code start = start + base address
	    set $start [expr ($start + $offset)]
	} else {
		set offset 0x0
	}
	
	# load add into GPR     
    reg ${GPR_GROUP}GPR11 %d = $start
    set bsize 0x80

    # compute actual range, 128 = 4bytes * 32 GPRS
    set c [expr ((($range - $offset)/$bsize))]
    reg ${GPR_GROUP}GPR2 = $bsize
    reg ${GPR_GROUP}GPR12 %d = $c

    # execute init ram code
    if {$vle_on == 1} {
	    #mtctr r12
	    mem v:$pstart = 0x7D8903A6
	    #stmw r0,0(r11)
	    mem v:[format %x [expr $pstart + 0x4]] = 0x180B0900
	    #addi r11,r11,128
	    mem v:[format %x [expr $pstart + 0x8]] = 0x1D6B0080
	    #bdnz -8
	    mem v:[format %x [expr $pstart + 0xc]] = 0x7A20FFF8
	    # infinte loop
	    #se_b *+0
	    mem v:[format %x [expr $pstart + 0x10]] = 0xE8000000
    } else {
	    #mtctr r12
	    mem v:$pstart = 0x7D8903A6
	    #stmw r0,0(r11)
	    mem v:[format %x [expr $pstart + 0x4]] = 0xBC0B0000
	    #addi r11,r11,128
	    mem v:[format %x [expr $pstart + 0x8]] = 0x396B0080
	    #bdnz -8
	    mem v:[format %x [expr $pstart + 0xc]] = 0x4200FFF8
	    # infinte loop
	    #se_b *+0
	    mem v:[format %x [expr $pstart + 0x10]] = 0x48000000    
    }
    
    # set PC to the first init instruction
    reg ${GPR_GROUP}PC = $pstart
    # execute init ram code
    # timeout 1 second to allow the code to execute
    go 2
    stop
}

proc init_z6_MMU {vle_on} {
  	#TLB1 registers group
  	variable TLB1_GROUP "regPPCTLB1/"
  	
  	if {$vle_on == 1} {
	  	# Setup MMU for for Periph B Modules
	  	# Base address = $FFF0_0000
	    # TLB0, 1 MByte Memory Space, Guarded, Don't Cache, All Access, VLE
	  	reg ${TLB1_GROUP}MMU_CAM0 = 0x5000000afe080000fff00000fff00001	
	
		# Set up MMU to put internal Flash at 0...
		# Virtual address 0x0 -> Physical address = $0000_0000
		# TLB1, 16 MByte Memory Space, Not Guarded, Cachable, All Access, VLE
	  	reg ${TLB1_GROUP}MMU_CAM1 = 0x70000000fe0800000000000000000001
	
		# Set up MMU for External Memory
		# Base address = $2000_0000
		# TLB2, 16 MByte Memory Space, Not Guarded, Cachable, All Access, VLE
	  	reg ${TLB1_GROUP}MMU_CAM2 = 0x70000000fe0800002000000020000001	
	
		# Set up MMU for Internal SRAM
		# Base address = $4000_0000
		# TLB3, 1 MByte Memory Space, Not Guarded, Don't Cache, All Access, VLE
	  	reg ${TLB1_GROUP}MMU_CAM3 = 0x50000008fe0800004000000040000001
  	} else {
	  	# Setup MMU for for Periph B Modules
	  	# Base address = $FFF0_0000
	    # TLB0, 1 MByte Memory Space, Guarded, Don't Cache, All Access, BOOKE
	  	reg ${TLB1_GROUP}MMU_CAM0 = 0x5000000afc080000fff00000fff00001
	
		# Set up MMU to put internal Flash at 0...
		# Virtual address 0x0 -> Physical address = $0000_0000
		# TLB1, 16 MByte Memory Space, Not Guarded, Cachable, All Access, BOOKE
	  	reg ${TLB1_GROUP}MMU_CAM1 = 0x70000000fc0800000000000000000001
	
		# Set up MMU for External Memory
		# Base address = $2000_0000
		# TLB2, 16 MByte Memory Space, Not Guarded, Cachable, All Access, BOOKE
	  	reg ${TLB1_GROUP}MMU_CAM2 = 0x70000000fc0800002000000020000001
	
		# Set up MMU for Internal SRAM
		# Base address = $4000_0000
		# TLB3, 1 MByte Memory Space, Not Guarded, Don't Cache, All Access, BOOKE
	  	reg ${TLB1_GROUP}MMU_CAM3 = 0x50000008fc0800004000000040000001
  	}
}

proc PXN_init {enable_z0 ram vle_on} {
	set SPR_GROUP "e200z6 Special Purpose Registers/"
	set GPR_GROUP "General Purpose Registers/"
	
	reset hard
	
	# Explicitly stop Core0
	stop
	
	#initialize Core0
	init_z6

	#initialize Z6 MMU
	init_z6_MMU $vle_on
	
	# Disable Watchdog Timers
	mem v:0xFFF38010 = 0x0000C520
	mem v:0xFFF38010 = 0x0000D928
	mem v:0xFFF38000 = 0x8000010A
   	# reset watchdog timer
	change ${SPR_GROUP}TCR = 0x0

	#initialze ECC SRAM	
	init_ram_vle 0x40000000 $ram $vle_on
	
	# enable z0 core
	if {$enable_z0 == 1} {
		# set infinite loop in order to catch the core 1
		# before executing start up code
		if {$vle_on == 1} {
			mem p:0x40000000 = 0xE8000000
		} else {
			mem p:0x40000000 = 0x48000000
		}
		# activate z0h: set reset address
		mem p:0xFFFEC054 = 0x40000000
		#initialize z0 core
		changecore 1
		stop
		# initialize core 1
		init_z0
		#set entry point for core 1
		catch {reg ${GPR_GROUP}PC = [evaluate __start_p1]}
	}
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
  
  # param1 0 = disable z0, 1 = enable z0
  # param2 init ECC RAM length = 0x94000 (592K) PXN2020 or 0x20000 (128K) PXN2120
  # param3 0 = BOOKE, 1 = VLE
  PXN_init 0 0x94000 0
 
