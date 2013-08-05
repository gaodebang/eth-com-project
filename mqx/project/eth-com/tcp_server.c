#include "tcp_server.h"
#include "config_parameter.h"

uint_32 Tcp_Server_Sock[4];
uint_8 Socket_Num;

void tcp_server_task(uint_32 initial_data)
{
	char data_buffer[4096];
    uint_32 count, error;

	while(TRUE)
	{
		count = recv(initial_data, data_buffer, 4096, 0);
		if (count == RTCS_ERROR)
		{
			error = RTCS_geterror(initial_data);
		    if(error == RTCS_OK)
		    {
		  	    shutdown(initial_data, FLAG_CLOSE_TX);
		  	    _task_destroy(MQX_NULL_TASK_ID);
		  	    if(Socket_Num--);
		    }
		    else
		    {
		  	    shutdown(initial_data, FLAG_CLOSE_TX);
		  	    _task_destroy(MQX_NULL_TASK_ID);
		  	    if(Socket_Num--);
		    }
		}
		else
		{
            write(SCI3, data_buffer, count);
            fflush(SCI3);
        }
        _time_delay (200);
	}
}