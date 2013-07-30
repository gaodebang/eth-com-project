#include "udp_connect.h"
#include "config_parameter.h"

uint_32 Udp_Connect_Sock[4] = {0, 0, 0, 0};

void udp_connect_task0(uint_32 initial_data)
{
	char  data_buffer[1500];
    uint_32 count, error;
    sockaddr         addr;
    uint_16      remote_len = sizeof(sockaddr);
    addr = Enet_Device.G_Addr_UDP_REMOTE[0];

	while(TRUE)
	{
        count = recvfrom(initial_data, data_buffer, 1500, 0, &addr, &remote_len);
        if (count == RTCS_ERROR)
        {
            error = RTCS_geterror(initial_data);
            if(error == RTCS_OK)
		    {
            	shutdown(initial_data, FLAG_CLOSE_TX);
    	  	    _task_destroy(MQX_NULL_TASK_ID);
    	  	}
    	  	else
    	  	{
            	shutdown(initial_data, FLAG_CLOSE_TX);
    	  	    _task_destroy(MQX_NULL_TASK_ID);    	  	    
    	  	}
    	  	Udp_Connect_Sock[0] = 0;
        }
        else
        {
            write(SCI3, data_buffer, count);
            fflush(SCI3);
        }
        _time_delay(200);
	}
}

void udp_connect_task1(uint_32 initial_data)
{
	char  data_buffer[1500];
    uint_32 count, error;
    sockaddr         addr;
    uint_16      remote_len = sizeof(sockaddr);
    addr = Enet_Device.G_Addr_UDP_REMOTE[1];

	while(TRUE)
	{
        count = recvfrom(initial_data, data_buffer, 1500, 0, &addr, &remote_len);
        if (count == RTCS_ERROR)
        {
            error = RTCS_geterror(initial_data);
            if(error == RTCS_OK)
		    {
            	shutdown(initial_data, FLAG_CLOSE_TX);
    	  	    _task_destroy(MQX_NULL_TASK_ID);
    	  	}
    	  	else
    	  	{
            	shutdown(initial_data, FLAG_CLOSE_TX);
    	  	    _task_destroy(MQX_NULL_TASK_ID);    	  	    
    	  	}
    	  	Udp_Connect_Sock[1] = 0;
        }
        else
        {
            write(SCI3, data_buffer, count);
            fflush(SCI3);
        }
        _time_delay(200);
	}
}
void udp_connect_task2(uint_32 initial_data)
{
	char  data_buffer[1500];
    uint_32 count, error;
    sockaddr         addr;
    uint_16      remote_len = sizeof(sockaddr);
    addr = Enet_Device.G_Addr_UDP_REMOTE[2];

	while(TRUE)
	{
        count = recvfrom(initial_data, data_buffer, 1500, 0, &addr, &remote_len);
        if (count == RTCS_ERROR)
        {
            error = RTCS_geterror(initial_data);
            if(error == RTCS_OK)
		    {
            	shutdown(initial_data, FLAG_CLOSE_TX);
    	  	    _task_destroy(MQX_NULL_TASK_ID);
    	  	}
    	  	else
    	  	{
            	shutdown(initial_data, FLAG_CLOSE_TX);
    	  	    _task_destroy(MQX_NULL_TASK_ID);    	  	    
    	  	}
    	  	Udp_Connect_Sock[2] = 0;
        }
        else
        {
            write(SCI3, data_buffer, count);
            fflush(SCI3);
        }
        _time_delay(200);
	}
}

void udp_connect_task3(uint_32 initial_data)
{
	char  data_buffer[1500];
    uint_32 count, error;
    sockaddr         addr;
    uint_16      remote_len = sizeof(sockaddr);
    addr = Enet_Device.G_Addr_UDP_REMOTE[3];

	while(TRUE)
	{
        count = recvfrom(initial_data, data_buffer, 1500, 0, &addr, &remote_len);
        if (count == RTCS_ERROR)
        {
            error = RTCS_geterror(initial_data);
            if(error == RTCS_OK)
		    {
            	shutdown(initial_data, FLAG_CLOSE_TX);
    	  	    _task_destroy(MQX_NULL_TASK_ID);
    	  	}
    	  	else
    	  	{
            	shutdown(initial_data, FLAG_CLOSE_TX);
    	  	    _task_destroy(MQX_NULL_TASK_ID);    	  	    
    	  	}
    	  	Udp_Connect_Sock[3] = 0;
        }
        else
        {
            write(SCI3, data_buffer, count);
            fflush(SCI3);
        }
        _time_delay(200);
	}
}