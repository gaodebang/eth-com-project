#include "flash.h"
#include "config_parameter.h"
#include <string.h>

MQX_FILE_PTR   Inside_Flash_File;

void Flash_Read(int_32  offset, uint_32  mode, char_ptr flash_data, uint_32 num)
{
    fseek(Inside_Flash_File, offset, mode);
    read(Inside_Flash_File, flash_data, num);
}

void Flash_Write(int_32  offset, uint_32  mode, char_ptr flash_data, uint_32 num)
{
    uint_32        ioctl_param;
    
    fseek(Inside_Flash_File, offset, mode);
    
    ioctl_param = 0;
    ioctl(Inside_Flash_File, FLASH_IOCTL_WRITE_PROTECT, &ioctl_param); 
       
    write(Inside_Flash_File, flash_data, num);
    
    ioctl_param = 1;
    ioctl(Inside_Flash_File, FLASH_IOCTL_WRITE_PROTECT, &ioctl_param);
}

