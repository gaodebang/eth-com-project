#include "tcp_client.h"
#include "config_parameter.h"

uint_32 Tcp_Client_Sock[4] = {0, 0, 0, 0};
uint_8 Tcp_Connect_Mark[4] = {0, 0, 0, 0};

void tcp_client_task0(uint_32 initial_data)
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
		  	    Tcp_Connect_Mark[0] = 0;
		  	    _task_destroy(MQX_NULL_TASK_ID);
		    }
		    else
		    {
		        shutdown(initial_data, FLAG_CLOSE_TX);
		  	    Tcp_Connect_Mark[0] = 0;
		  	    _task_destroy(MQX_NULL_TASK_ID);
		    }
		    Tcp_Client_Sock[0] = 0;
		}
		else
		{
            write(SCI0, data_buffer, count);
            fflush(SCI0);
        }
        _time_delay (200);
	}
}

void tcp_client_task1(uint_32 initial_data)
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
		  	    Tcp_Connect_Mark[1] = 0;
		  	    _task_destroy(MQX_NULL_TASK_ID);
		    }
		    else
		    {
		        shutdown(initial_data, FLAG_CLOSE_TX);
		  	    Tcp_Connect_Mark[1] = 0;
		  	    _task_destroy(MQX_NULL_TASK_ID);
		    }
		    Tcp_Client_Sock[1] = 0;
		}
		else
		{
            write(SCI0, data_buffer, count);
            fflush(SCI0);
        }
        _time_delay (200);
	}
}

void tcp_client_task2(uint_32 initial_data)
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
		  	    Tcp_Connect_Mark[2] = 0;
		  	    _task_destroy(MQX_NULL_TASK_ID);
		    }
		    else
		    {
		        shutdown(initial_data, FLAG_CLOSE_TX);
		  	    Tcp_Connect_Mark[2] = 0;
		  	    _task_destroy(MQX_NULL_TASK_ID);
		    }
		    Tcp_Client_Sock[2] = 0;
		}
		else
		{
            write(SCI0, data_buffer, count);
            fflush(SCI0);
        }
        _time_delay (200);
	}
}

void tcp_client_task3(uint_32 initial_data)
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
		  	    Tcp_Connect_Mark[3] = 0;
		  	    _task_destroy(MQX_NULL_TASK_ID);
		    }
		    else
		    {
		        shutdown(initial_data, FLAG_CLOSE_TX);
		  	    Tcp_Connect_Mark[3] = 0;
		  	    _task_destroy(MQX_NULL_TASK_ID);
		    }
		    Tcp_Client_Sock[3] = 0;
		}
		else
		{
            write(SCI0, data_buffer, count);
            fflush(SCI0);
        }
        _time_delay (200);
	}
}