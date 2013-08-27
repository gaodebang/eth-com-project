#include "mqx.h"
#include "bsp.h"
#include "rtcs.h"
#include "ipcfg.h"
#include "fio.h"

#define	INIT_TASKS_TASK                 5

#define TCP_SERVER_TASK                 6
#define TCP_CLIENT_TASK0                7
#define TCP_CLIENT_TASK1                8
#define TCP_CLIENT_TASK2                9
#define TCP_CLIENT_TASK3                10
#define UDP_CONNECT_TASK0               11
#define UDP_CONNECT_TASK1               12
#define UDP_CONNECT_TASK2               13
#define UDP_CONNECT_TASK3               14

#define COM_SERVER_TASK_TCP_SERVER      15
#define COM_SERVER_TASK_TCP_CLIENT      16
#define COM_SERVER_TASK_UDP_CONNECT     17

#define GPIO_SERVER_TASK                18

#define SHELL_SERVER_TASK               19

#define TCP_CFG_TASK	                20
#define COM_SERVER_TASK_TCP_CFG	        21
#define TCP_CFG_START	        		22
#define BROAD_CAST_TASK		        	23