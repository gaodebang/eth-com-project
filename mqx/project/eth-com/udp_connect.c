#include "udp_connect.h"
#include "config_parameter.h"

uint_32 Udp_Connect_Sock[4] = {0, 0, 0, 0};

void udp_connect_task0(uint_32 initial_data)
{
	char  data_buffer[4096];
    uint_32 count, error;
    static sockaddr         addr;
    uint_16      remote_len = sizeof(sockaddr);
	addr = Enet_Device.G_Addr_UDP_REMOTE[0];
	while(TRUE)
	{
        count = recvfrom(initial_data, data_buffer, 4096, 0, &addr, &remote_len);
        if (count == RTCS_ERROR)
        {
            error = RTCS_geterror(initial_data);
			error = error;
        }
        else
        {
            write(SCI0, data_buffer, count);
            fflush(SCI0);
        }
        _time_delay (50);
	}
}