ENTRY(__boot)
EXTERN(main __vector_table ram_vector)

MEMORY
{
    text        (RX): ORIGIN = 0x3f000000, LENGTH = 0x0003fff0
    data        (RW): ORIGIN = 0x3f800000, LENGTH = 0x00007ff0
    tcml        (RW): ORIGIN = 0x1f800000, LENGTH = 0x00007ff0
}

CODE_BASE_ADDR_START            = ORIGIN(text);
CODE_SIZE                       = LENGTH(text);
CODE_BASE_ADDR_END              = CODE_BASE_ADDR_START + CODE_SIZE;

DATA_BASE_ADDR_START            = ORIGIN(data);
DATA_SIZE                       = LENGTH(data);
DATA_BASE_ADDR_END              = DATA_BASE_ADDR_START + DATA_SIZE;

TCML_BASE_ADDR_START            = ORIGIN(tcml);
TCML_SIZE                       = LENGTH(tcml);
TCML_END                        = TCML_BASE_ADDR_START + TCML_SIZE;

/* exported symbols */
__DEFAULT_PROCESSOR_NUMBER      = 1;
/* __DEFAULT_INTERRUPT_STACK_SIZE  = 3000; //used BSP_DEFAULT_INTERRUPT_STACK_SIZE instead */

/* 64kB of  shared memory */
__SHARED_RAM_START              = 0x3f040000;
__SHARED_RAM_END                = 0x3f04fff0;
__SRAM_POOL_START               = DATA_BASE_ADDR_START;
__SRAM_POOL_END                 = DATA_BASE_ADDR_END;
__UNCACHED_DATA_START           = DATA_BASE_ADDR_START;
__UNCACHED_DATA_END             = DATA_BASE_ADDR_END;

/* mem_init writes a storeblock_struct at the end of kernel data, max size 32 bytes, so use 0x100 offset */
__BOOT_STACK_ADDRESS            = TCML_END - 0x100;
__VECTOR_TABLE_ROM_START        = CODE_BASE_ADDR_START;
__VECTOR_TABLE_RAM_START        = DATA_BASE_ADDR_START;
__KERNEL_DATA_END               = DATA_BASE_ADDR_END;

SECTIONS
{
    /* place vectors at the start, each section has only one symbol */
    .vectors :
    {
        *(.vectors_rom)
        *(.cfmconfig)
    } > text
    
    /* place text */
    .text :
    {
        *(KERNEL)
        *(.text*)
        *(.rodata*)
        
        /* glue arm/thumb and thumb/arm code */
        *(.glue_7)
        *(.glue_7t)
        
        /* unwind exception frame */
        KEEP(*(.eh_frame))
        KEEP(*(.eh_frame_hdr))
        
        . = ALIGN(0x8);
        KEEP (*crtbegin.o(.ctors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*crtend.o(.ctors))
        
        KEEP (*crtbegin.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*crtend.o(.dtors))
        
        /* preinit_array */
        __preinit_array_start = .;
        KEEP (*(.preinit_array*))
        __preinit_array_end = .;
        
        /* init_array */
        __init_array_start = .;
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array*))
        __init_array_end = .;
        
        /* fini_array */
        __fini_array_start = .;
        KEEP (*(SORT(.fini_array.*)))
        KEEP (*(.fini_array*))
        __fini_array_end = .;
        
        /* codesourcery init table */
        __cs3_regions = .;
        LONG(0)
        LONG(_bss_start)
        LONG(_bss_start)
        LONG(0)
        LONG(_bss_end - _bss_start)
        __cs3_regions_end = .;
        . = ALIGN (8);
    } > text
    
    /* number of region, keep outside any section */
    __cs3_region_num = 1;
    /* don't use codesourcery heap */
    __cs3_heap_start = 0;
    
    /* unwind exception frame */
    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > text
    .ARM :
    {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } > text
    
    /* place data, region address must be 8B aligned */
    .data :
    {
        *(.vectors_ram)
        *(.data*)
        . = ALIGN(8);
    } > data
    
    /* place bss, section size must be 8 aligned because of startup */
    .bss BLOCK(8) :
    {
      _bss_start = .;
      *(.bss*)
      *(COMMON)
      . = ALIGN(8);
      _bss_end = .;
    } > data
    
    .kernel_data BLOCK(0x10) : 
    {
        __KERNEL_DATA_START = ALIGN(0x10);
    } > data
}

