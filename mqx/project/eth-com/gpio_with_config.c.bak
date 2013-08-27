#include "gpio_with_config.h"

#include "config_parameter.h"

extern void __boot(void);

LWGPIO_STRUCT Btn_Cfg, Btn_Rst, Led;

LWGPIO_VALUE Btn_Cfg_Value, Btn_Rst_Value;

uint_8 Rst_Cmd_Set;

void Gpio_Init(void)
{
    if (!lwgpio_init(&Btn_Cfg, LWGPIO_PORT_C | LWGPIO_PIN9, LWGPIO_DIR_INPUT, LWGPIO_VALUE_NOCHANGE))
    {
        _task_block();
    }
    lwgpio_set_functionality(&Btn_Cfg, LWGPIO_MUX_C9_GPIO);
    lwgpio_set_attribute(&Btn_Cfg, LWGPIO_ATTR_PULL_UP, LWGPIO_AVAL_ENABLE);
    lwgpio_set_value(&Btn_Cfg, LWGPIO_VALUE_HIGH);
    Btn_Cfg_Value = lwgpio_get_raw(&Btn_Cfg);
    
    if (!lwgpio_init(&Btn_Rst, LWGPIO_PORT_E | LWGPIO_PIN3, LWGPIO_DIR_INPUT, LWGPIO_VALUE_NOCHANGE))
    {
        _task_block();
    }
    lwgpio_set_functionality(&Btn_Rst, LWGPIO_MUX_E3_GPIO);
    lwgpio_set_attribute(&Btn_Rst, LWGPIO_ATTR_PULL_UP, LWGPIO_AVAL_ENABLE);
    lwgpio_set_value(&Btn_Rst, LWGPIO_VALUE_HIGH);    
    Btn_Rst_Value = lwgpio_get_raw(&Btn_Rst);
    
    if (!lwgpio_init(&Led, LWGPIO_PORT_E | LWGPIO_PIN2, LWGPIO_DIR_OUTPUT, LWGPIO_VALUE_NOCHANGE))
    {
        _task_block();
    }
    lwgpio_set_functionality(&Led, LWGPIO_MUX_E2_GPIO);
    lwgpio_set_value(&Led, LWGPIO_VALUE_HIGH); 
    
    if(Btn_Cfg_Value == 0)
    {
        Sys_Mode = 0;
    }
    else
    {
        Sys_Mode = 1;
    }
    
    if(Btn_Rst_Value == 0)
    {
        Rst_Cmd_Set = 0;
    }
    else
    {
        Rst_Cmd_Set = 1;
    }
}

static void led_display(void)
{
    static uint_8 time_add_led = 0;
    if(Rst_Cmd_Set == 1)
    {
        if(Sys_Mode == 0)
        {
            lwgpio_set_value(&Led, LWGPIO_VALUE_LOW);
        }
        else
        {
            if (++time_add_led >= 30)
            {
                time_add_led = 0;
                lwgpio_set_value(&Led, LWGPIO_VALUE_LOW);
            }
            else
            {
                if(time_add_led == 5)
                {
                    lwgpio_set_value(&Led, LWGPIO_VALUE_HIGH);
                }
            }        
        }

    }        
    else
    {
        if (++time_add_led >= 10)
        {
            time_add_led = 0;
            lwgpio_set_value(&Led, LWGPIO_VALUE_LOW);
        }
        else
        {
            if(time_add_led == 5)
            {
                lwgpio_set_value(&Led, LWGPIO_VALUE_HIGH);
            }
        } 
    }
}

void gpio_server_task(uint_32 initial_data)
{
    static uint_8 time_add_cfg = 0, time_add_rst = 0;
    static LWGPIO_VALUE btn_cfg_value_temp, btn_rst_value_temp;
    while(1)
    {
        btn_cfg_value_temp = lwgpio_get_raw(&Btn_Cfg);
        btn_rst_value_temp = lwgpio_get_raw(&Btn_Rst);
        
        if (Btn_Cfg_Value != btn_cfg_value_temp)
        {
            if(++time_add_cfg > 4)
            {
                time_add_cfg = 0;
                Btn_Cfg_Value = btn_cfg_value_temp;
                __boot();
            }
        }
        else
        {
            time_add_cfg = 0;
        }
        
        if(Rst_Cmd_Set == 1)
        {
            if ((Btn_Rst_Value == LWGPIO_VALUE_HIGH)&&(btn_rst_value_temp == LWGPIO_VALUE_LOW))
            {
                if(++time_add_rst > 40)
                {
                    time_add_rst = 0;
                    Btn_Rst_Value = LWGPIO_VALUE_LOW;
                    lwgpio_set_value(&Led, LWGPIO_VALUE_LOW);
                    /*
                    reset flash
                    */
                }
            }
            else if((Btn_Rst_Value == LWGPIO_VALUE_LOW)&&(btn_rst_value_temp == LWGPIO_VALUE_LOW))
            {
                lwgpio_set_value(&Led, LWGPIO_VALUE_LOW);
                _time_delay(2000);
                lwgpio_set_value(&Led, LWGPIO_VALUE_HIGH);
                _time_delay(200);
                lwgpio_set_value(&Led, LWGPIO_VALUE_LOW);
                _time_delay(200);
                lwgpio_set_value(&Led, LWGPIO_VALUE_HIGH);
                _time_delay(200);
                lwgpio_set_value(&Led, LWGPIO_VALUE_LOW);
            }
            else if((Btn_Rst_Value == LWGPIO_VALUE_LOW)&&(btn_rst_value_temp == LWGPIO_VALUE_HIGH))
            {
                __boot();
            }
            else
            {
                time_add_rst = 0;
            }
            
        }
        led_display();
        _time_delay(50);
    }
}
