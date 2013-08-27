#include "mqx_eth_com_main.h"

#include "config_parameter.h"

#include "init_tasks.h"
#include "gpio_with_config.h"

#include "shell_at.h"

#include "tcp_cfg.h"
#include "broad_cast.h"
#include "tcp_server.h"
#include "tcp_client.h"
#include "com_server.h"
#include "udp_connect.h"



const TASK_TEMPLATE_STRUCT  MQX_template_list[] = 
{
	/* Task Index,                  Function,                   Stack,  Priority, 	Name,                               Attributes,          	Param, Time Slice */
	{ INIT_TASKS_TASK,              init_tasks_task,            1000,    9,            "init tasks task",                MQX_AUTO_START_TASK,    0,     0 },
	
	{ GPIO_SERVER_TASK,             gpio_server_task,           2000,   10,           "gpio server task",               0,                      0,     0 },
	{ SHELL_SERVER_TASK,            shell_server_task,          5000,   11,           "shell server task",              0,                      0,     0 },
	{ TCP_CFG_TASK,              	tcp_cfg_task,            	5000,   12,           "tcp cfg task",   	            0,    					0,     0 },
	{ TCP_CFG_START,      			tcp_cfg_start,    			5000,   13,           "tcp cfg start",			   	    0,    					0,     0 },
	{ BROAD_CAST_TASK,      		broad_cast_task,    		5000,   13,           "broad cast task",		   	    0,    					0,     0 },
	
	{ COM_SERVER_TASK_TCP_SERVER,   com_server_task_tcp_server, 5000,   15,           "com server task tcp server",     0,                      0,     0 },
	{ COM_SERVER_TASK_TCP_CLIENT,   com_server_task_tcp_client, 5000,   15,           "com server task tcp client",     0,                      0,     0 },
	{ COM_SERVER_TASK_UDP_CONNECT,  com_server_task_udp_connect,5000,   15,           "com server task udp connect",    0,                      0,     0 },	
	
	{ TCP_SERVER_TASK,              tcp_server_task,            5000,   16,           "tcp server task",                0,    					0,     0 },
	
	{ TCP_CLIENT_TASK0,             tcp_client_task0, 	        5000,   16,           "com client task0",               0,    					0,     0 },
	{ TCP_CLIENT_TASK1,             tcp_client_task1, 	        5000,   16,           "com client task1",               0,    					0,     0 },
	{ TCP_CLIENT_TASK2,             tcp_client_task2, 	        5000,   16,           "com client task2",               0,    					0,     0 },
	{ TCP_CLIENT_TASK3,             tcp_client_task3, 	        5000,   16,           "com client task3",               0,    					0,     0 },
	
	{ UDP_CONNECT_TASK0,            udp_connect_task0, 	        5000,   16,           "udp connect task0",              0,    					0,     0 },
	{ 0 }
};
