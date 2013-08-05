#include "shell_at.h"
#include "config_parameter.h"

void shell_server_task(uint_32 initial_data)
{
    uint_8 data_buffer[1]={0x33};
    while(TRUE)
    {
        write(SCI3, data_buffer, 1);
        fflush(SCI3);
        _time_delay(200);
        _task_block();
    }
}
