#include "mqx_eth_com_main.h"

extern MQX_FILE_PTR   Inside_Flash_File;

extern void Inside_Flash_Init(void); 
extern void Flash_Read(int_32  offset, uint_32  mode, char_ptr flash_data, uint_32 num);
extern void Flash_Write(int_32  offset, uint_32  mode, char_ptr flash_data, uint_32 num);