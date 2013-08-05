#include "init_tasks.h"

#include "config_parameter.h"
#include "tcp_server.h"
#include "com_server.h"
#include "tcp_client.h"
#include "udp_connect.h"
#include "gpio_with_config.h"
#include "shell_at.h"
#include "com_push.h"

static void get_mac_address(_enet_address intent, _enet_address source)
{
    uint_8 i;
    for (i=0; i<6; i++)
    {
        intent[i] = source[i];
    }
}

static void init_rtcs(void)
{
    uint_32 error;
    IPCFG_IP_ADDRESS_DATA ip_data;
    _enet_address address;
    
    Init_Default_Parameter();
    error = RTCS_create();
    if (error != RTCS_OK)
    {
        _task_block();       
    }
    get_mac_address(address, Enet_Device.G_Mac_Address);
    ip_data = Enet_Device.G_Ip_Data;
    error = ipcfg_init_device(BSP_DEFAULT_ENET_DEVICE, address);
    if (error != RTCS_OK)
    {
        _task_block();
    }
    error = ipcfg_bind_staticip (BSP_DEFAULT_ENET_DEVICE, &ip_data);
    //error = ipcfg_bind_dhcp_wait(BSP_DEFAULT_ENET_DEVICE, TRUE, &ip_data);--*/
    if (error != RTCS_OK) 
    {
        _task_block();
    }
}

static void tcp_server_start(void)
{
    uint_32 listensock, error, sock, option;
    uint_8 max_socket_num;
    sockaddr addr;
    _task_id task_id;
    listensock = socket(PF_INET, SOCK_STREAM, 0);
    if(listensock == RTCS_SOCKET_ERROR)
    {
        _task_block();
    }

    option = FALSE;
    error = setsockopt(listensock, SOL_TCP, OPT_SEND_NOWAIT, &option, sizeof(uint_32));
    if (error != RTCS_OK) 
    {
        _task_block();
    }

    option = TRUE;
    error = setsockopt(listensock, SOL_TCP, OPT_RECEIVE_NOWAIT, &option, sizeof(uint_32));
    if (error != RTCS_OK) 
    {
        _task_block();
    }

    addr = Enet_Device.G_Addr_TCP_SERVER;
    error = bind(listensock, &addr, sizeof(sockaddr));
    if (error != RTCS_OK) 
    {
        _task_block();
    }
    error = listen(listensock, 0);
    if(error != RTCS_OK)
    {
        _task_block();
    }
    max_socket_num = Enet_Device.MAX_SOCKET_NUM;
    while(1)
    {
        /* Wait for a connection */
        sock= accept(listensock, NULL, NULL);
        if(Socket_Num<max_socket_num)
        {
        	if (sock != RTCS_SOCKET_ERROR)
        	{
        	    task_id = _task_create(0, TCP_SERVER_TASK, sock);
        	    if (task_id != MQX_NULL_TASK_ID)
        	    {
        	        Tcp_Server_Sock[Socket_Num]= sock;
        	        Socket_Num++;
        	    }
            }
            else
            {
           	    _task_block();
            }
        }
        else
        {
        	shutdown(sock, FLAG_CLOSE_TX);
        }
    }
}

static void tcp_client_start(void)
{
    uint_32 listensock, error, option;
    sockaddr addr;
    _task_id task_id;
    uint_8 max_socket_num, i;
    max_socket_num = Enet_Device.MAX_SOCKET_NUM;
    while(1)
    {
        for (i=0; i<max_socket_num; i++)
        {
            if (Tcp_Connect_Mark[i] == 0)
            {
                listensock = socket(PF_INET, SOCK_STREAM, 0);
                if(listensock == RTCS_SOCKET_ERROR)
                {
                    _task_block();
                }
                
                option = FALSE;
                error = setsockopt(listensock, SOL_TCP, OPT_SEND_NOWAIT, &option, sizeof(uint_32));
                if (error != RTCS_OK) 
                {
                    _task_block();
                }
            
                option = TRUE;
                error = setsockopt(listensock, SOL_TCP, OPT_RECEIVE_NOWAIT, &option, sizeof(uint_32));
                if (error != RTCS_OK) 
                {
                    _task_block();
                }
                
                addr = Enet_Device.G_Addr_TCP_CLIENT[i];
                error = connect(listensock, &addr, sizeof(sockaddr));
        		if (error == RTCS_OK)
        		{
        			task_id = _task_create(0, TCP_CLIENT_TASK0 + i, listensock);
        			if (task_id != MQX_NULL_TASK_ID)
        			{
        			    Tcp_Client_Sock[i] = listensock;
        				Tcp_Connect_Mark[i] = 1;
        			}
                }
                else
                {
                    shutdown (listensock, FLAG_CLOSE_TX);
        		}
        	}
        	else
        	{
        		_time_delay(100);
        	}
        }
        _time_delay(5000);
	}
}

static void udp_connect_start(void)
{
    uint_32 listensock, error, option;
    sockaddr addr;
    _task_id task_id;
    uint_8 max_socket_num, i;
    max_socket_num = Enet_Device.MAX_SOCKET_NUM;
    listensock =  socket(PF_INET, SOCK_DGRAM, 0);
    if(listensock == RTCS_SOCKET_ERROR)
    {
        _task_block();
    }
    
    option = FALSE;
    error = setsockopt(listensock, SOL_UDP, OPT_SEND_NOWAIT, &option, sizeof(uint_32));
    if (error != RTCS_OK) 
    {
        _task_block();
    }

    option = TRUE;
    error = setsockopt(listensock, SOL_UDP, OPT_RECEIVE_NOWAIT, &option, sizeof(uint_32));
    if (error != RTCS_OK) 
    {
        _task_block();
    }
    addr = Enet_Device.G_Addr_UDP_LOCAL;
    error = bind(listensock, &addr, sizeof(sockaddr));
    if(error == RTCS_OK)
    {
        for (i=0; i<max_socket_num; i++)
        {
        	task_id = _task_create(0, UDP_CONNECT_TASK0+i, listensock);
        	if (task_id != MQX_NULL_TASK_ID)
        	{
        		Udp_Connect_Sock[i] = listensock;
        	}
        }
    }
    _task_block();
}

static void at_server_start(void)
{
    
}

void init_tasks_task(uint_32 initial_data)
{
    uint_8 enet_mode;
    _task_id task_id;

    task_id = _task_create(0, GPIO_SERVER_TASK, 0);
    if (task_id == MQX_NULL_TASK_ID)
    {
        _task_block();
    }
    
    task_id = _task_create(0, SHELL_SERVER_TASK, 0);
    if (task_id == MQX_NULL_TASK_ID)
    {
        _task_block();
    }
    
    SCI3 = fopen("ittyd:", (char const *)IO_SERIAL_NON_BLOCKING);

    init_rtcs();
    enet_mode = Enet_Device.G_Enet_Mode;
    if (enet_mode == 0)
    {
        task_id = _task_create(0, COM_SERVER_TASK_TCP_SERVER, 0);
        if (task_id == MQX_NULL_TASK_ID)
        {
            _task_block();
        }
        tcp_server_start();
    }
    else if (enet_mode == 1)
    {
        task_id = _task_create(0, COM_SERVER_TASK_TCP_CLIENT, 0);
        if (task_id == MQX_NULL_TASK_ID)
        {
            _task_block();
        }
        tcp_client_start();
    }
    else if (enet_mode == 2)
    {
        task_id = _task_create(0, COM_SERVER_TASK_UDP_CONNECT, 0);
        if (task_id == MQX_NULL_TASK_ID)
        {
            _task_block();
        }
        udp_connect_start();
    }
    else if (enet_mode == 3)
    {
        at_server_start();
    }
    else
    {}
    _task_block();
}