/*
    @file   LinkerScript.ld
    @author Ziad Mohammed Fathi.
    @brief  Linker script for STM32F103xx Device from STM32F103 series
*/

_estack = ORIGIN(RAM) + LENGTH(RAM);

_Min_Heap_Size  = 0x200;
_Min_Stack_Size = 0x400; 

MEMORY
{
    FLASH (xr)  :   ORIGIN = 0x08000000 , LENGTH = 64K
    RAM   (rwx) :   ORIGIN = 0x20000000 , LENGTH = 20K
}

SECTIONS
{
    /* .isr_vector segment in flash memory */
    .isr_vector :
    {
        . = ALIGN(4);
        *(isr_vector)
        . = ALIGN(4);
    } >FLASH
    /* .text segment in flash memory */
    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        . = ALIGN(4);
        _etext = .;
    } >FLASH
    
    /* .rodata segment in flash memory */
    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
        _erodata = .;
    } >FLASH

    _sidata = LOADADDR(.data);

    /* .data segment in RAM memory */
    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } >RAM AT>FLASH   

    /* .bss segment in RAM memory */
    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(4);
        _ebss = .;
    } >RAM  

    /* .User_heap_stack section, used to check that there is enough "RAM" Ram  type memory left */
    ._user_heap_stack :
    {
        . = ALIGN(8);
        . = . + _Min_Heap_Size;
        . = . + _Min_Stack_Size;
        . = ALIGN(8);
    } >RAM          
}