#include "tcp_cfg.h"
#include "config_parameter.h"

uint_8 Cfg_Socket_Num;

void tcp_cfg_task(uint_32 initial_data)
{
	char data_buffer[4096];
    uint_32 count, count0, error;

	while(TRUE)
	{
		count = recv(initial_data, data_buffer, 4096, 0);
		if (count == RTCS_ERROR)
		{
			error = RTCS_geterror(initial_data);
		    if(error == RTCS_OK)
		    {
		  	    shutdown(initial_data, FLAG_CLOSE_TX);		  	    
		  	    if(Cfg_Socket_Num--);
		  	    _task_destroy(MQX_NULL_TASK_ID);

		    }
		    else
		    {
		  	    shutdown(initial_data, FLAG_CLOSE_TX);
		  	    if(Cfg_Socket_Num--);
		  	    _task_destroy(MQX_NULL_TASK_ID);
		    }
		}
		else
		{
            count0 = send(initial_data, data_buffer, count, 0);
            if (count0 == RTCS_ERROR)
            {
                error = RTCS_geterror(initial_data);
                error = error;
                shutdown(initial_data, FLAG_CLOSE_TX);
                if(Cfg_Socket_Num--);
                _task_destroy(MQX_NULL_TASK_ID);
                
            }
        }
        _time_delay (50);
	}
}