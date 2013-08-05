#include "com_server.h"
#include "config_parameter.h"
#include "tcp_server.h"
#include "tcp_client.h"
#include "udp_connect.h"

void com_server_task_tcp_server(uint_32 initial_data)
{
    char data_buffer[4096]; 
    uint_32 count, count0, error;
    uint_8 i;
	while(TRUE)
    {
        count = fread(data_buffer, 1, 4096, SCI3); 
        for (i=0; i<4; i++)
        {
            if (Tcp_Server_Sock[i] != 0)
            {
                count0 = send(Tcp_Server_Sock[i], data_buffer, count, 0);
                if (count0 == RTCS_ERROR)
                {
                    error = RTCS_geterror(initial_data);
                    shutdown(initial_data, FLAG_CLOSE_TX);
                    Tcp_Server_Sock[i] = 0;
                    if(Socket_Num--);
                }
            }
        }
        _time_delay (200);
    }
}

void com_server_task_tcp_client(uint_32 initial_data)
{
    char data_buffer[4096]; 
    uint_8 i;
    uint_32 count, count0, error;
	while(TRUE)
    {
        count = fread(data_buffer, 1, 4096, SCI3); 
        for (i=0; i<4; i++)
        {
            if (Tcp_Client_Sock[i] != 0)
            {
                count0 = send(Tcp_Client_Sock[i], data_buffer, count, 0);
                if (count0 == RTCS_ERROR)
                {
                    error = RTCS_geterror(Tcp_Client_Sock[i]);
                    shutdown(Tcp_Client_Sock[i], FLAG_CLOSE_TX);
                    Tcp_Client_Sock[i] = 0;
                    Tcp_Connect_Mark[i] = 0;
                }
            }
        }
        _time_delay (200);
    }
}

void com_server_task_udp_connect(uint_32 initial_data)
{
    char data_buffer[4096]; 
    uint_8 i;
    uint_32 count, count0, error;
    sockaddr         addr;
	while(TRUE)
    {
        count = fread(data_buffer, 1, 4096, SCI3);
        for (i=0; i<4; i++)
        {
            if (Udp_Connect_Sock[i] != 0)
            {
                addr = Enet_Device.G_Addr_UDP_REMOTE[i];              
                count0 = sendto(Udp_Connect_Sock[i], data_buffer, count, 0, &addr, sizeof(sockaddr));
                if (count0 == RTCS_ERROR)
                {
                    error = RTCS_geterror(Udp_Connect_Sock[i]);
                    shutdown(Udp_Connect_Sock[i], FLAG_CLOSE_TX);
                    Udp_Connect_Sock[i] = 0;
                }
            }
        }
        _time_delay (200);
    }
}