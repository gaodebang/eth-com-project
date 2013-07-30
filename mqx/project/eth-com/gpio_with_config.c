#include "gpio_with_config.h"
#include "config_parameter.h"

extern void __boot(void);

void gpio_server_task(uint_32 initial_data)
{
    static uint_8 time_add = 0;
    static LWGPIO_VALUE btn1_value = LWGPIO_VALUE_HIGH;
    
    _task_id task_id;
    
    LWGPIO_STRUCT btn1, led1;
    LWGPIO_VALUE btn1_value_temp;
    
    if (!lwgpio_init(&btn1, BSP_BUTTON1, LWGPIO_DIR_INPUT, LWGPIO_VALUE_HIGH))
    {
        _task_block();
    }
    lwgpio_set_functionality(&btn1, BSP_BUTTON1_MUX_GPIO);
    if (!lwgpio_init(&led1, BSP_LED1, LWGPIO_DIR_OUTPUT, LWGPIO_VALUE_HIGH))
    {
        _task_block();
    }
    lwgpio_set_functionality(&led1, BSP_LED1_MUX_GPIO);

    btn1_value = lwgpio_get_raw(&btn1);

    if (btn1_value == LWGPIO_VALUE_LOW)
    {
        //task_id = _task_create(0, SHELL_SERVER_TASK, 0);
        if (task_id == MQX_NULL_TASK_ID)
        {
            _task_block();
        }        
    }
    while(1)
    {
        btn1_value_temp = lwgpio_get_raw(&btn1);
        if (btn1_value != btn1_value_temp)
        {
            if(++time_add > 4)
            {
                time_add = 0;
                btn1_value = btn1_value_temp;
                lwgpio_set_value(&led1, btn1_value);
                __boot();
            }
        }
        else
        {
            time_add = 0;
        }
        _time_delay(50);
    }
}