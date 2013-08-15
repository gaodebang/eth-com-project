#include "mqx_eth_com_main.h"

extern LWGPIO_STRUCT Btn_Cfg, Btn_Rst, Led;
extern uint_8 Rst_Cmd_Set;

extern void gpio_server_task(uint_32 initial_data);
extern void Gpio_Init(void);
