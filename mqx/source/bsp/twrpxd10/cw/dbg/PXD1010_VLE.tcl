#  This script is compatible with PXD1010 device / Z0H core.
#  This script performs minimal intialization like ECC SRAM, IVORs.

##############################################
# Initialize a RAM range from 'start' address
##############################################
proc init_ram {start range} {
    # same registrer group name for all PowerPC
    variable GPR_GROUP "General Purpose Registers/"

    # load code start - start + 0x18
    set addr [expr $start + 0x18]
    reg ${GPR_GROUP}GPR11 %d = $addr
    #  actual range
    set c [expr ($range - 0x18)/128]
    reg ${GPR_GROUP}GPR12 %d = $c
    # execute init ram code
    #mtctr r12
    mem v:$start = 0x7D8903A6
    #stmw r0,0(r11)
    mem v:[format %x [expr $start + 0x4]] = 0x180B0900
    #addi r11,r11,128
    mem v:[format %x [expr $start + 0x8]] = 0x1D6B0080
    #bdnz -8
    mem v:[format %x [expr $start + 0xc]] = 0x7A20FFF8
    # init the rest of RAM
    #stmw   r6,0(r11)  - last 104 bytes of the range
    mem v:[format %x [expr $start + 0x10]] = 0x18CB0900
    # infinte loop
    #bl
    mem v:[format %x [expr $start + 0x14]] = 0x78000001
    
    # set PC to the first init instruction
    reg ${GPR_GROUP}PC = $start
    
    # execute init ram code
    # timeout 1 second
    go 1
    stop
}

################################
# Initialize the PXD10xx system
################################
proc system_init {} {
   
    # Disable SWT Watchdog Timer
    mem v:0xfff38010 = 0x0000c520
    mem v:0xfff38010 = 0x0000d928
    mem v:0xfff38000 = 0xff00000A
}

#################################
# Initialization for e200Z0H core
#################################
proc PXD10xx_z0h_vle {} {
    #  ---------------------------------------------------------------------------------------
    #  Interrupt vectors IVOR 0-15, these SPRs are hardwired to specific
    # values, and are readable, but a mtspr results in an unimplemented or 
    # privileged exception
    # IVOR 16-31 are reserved
    #  ---------------------------------------------------------------------------------------
    variable e200SPR_GROUP "e200z0h Special Purpose Registers/"
    reg ${e200SPR_GROUP}IVPR = 0x40000000
   
    # set program counter
    reg "General Purpose Registers/PC" = 0x40000000
}

#################################
# Initialization for PXD1010
#################################
proc PXD1010_init {} {
    reset hard

    # Explicitly stop the core
    stop
    
    # system init
    system_init
    
    # initialize PXD1010 ECC SRAM 48K:  0x40000000 - 0x4000BFFF
    # Graphics SRAM (no ECC protection, no standby support)
    init_ram 0x40000000 0xC000
    
    # core init
    PXD10xx_z0h_vle
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
# Note:  some PXD10xx connections provider may initializes the core upon connect, eg. PnE

PXD1010_init
