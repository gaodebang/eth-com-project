#include "broad_cast.h"
#include "config_parameter.h"

void broad_cast_task(uint_32 initial_data)
{
	char  data_buffer[4096];
    uint_32 count, error;
    static sockaddr         addr;
    uint_16      remote_len = sizeof(sockaddr);
	while(TRUE)
	{
        count = recvfrom(initial_data, data_buffer, 4096, 0, &addr, &remote_len);
        if (count == RTCS_ERROR)
        {
            error = RTCS_geterror(initial_data);
			error = error;
			//////////////
			
			//////////////
        }
        else
		{
			addr. sin_addr.s_addr = INADDR_BROADCAST;
            sendto(initial_data, data_buffer, count, 0, &addr, sizeof(sockaddr));
        }
        _time_delay (100);
	}
}
