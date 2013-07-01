#include <mqx.h>
#include <bsp.h> 
#include <fio.h>
#include <rtcs.h>
#include <ipcfg.h>

#if ! BSPCFG_ENABLE_IO_SUBSYSTEM
#error This application requires BSPCFG_ENABLE_IO_SUBSYSTEM defined non-zero in user_config.h. Please recompile BSP with this option.
#endif

#ifndef BSP_DEFAULT_IO_CHANNEL_DEFINED
#error This application requires BSP_DEFAULT_IO_CHANNEL to be not NULL. Please set corresponding BSPCFG_ENABLE_TTYx to non-zero in user_config.h and recompile BSP with this option.
#endif

/* Task IDs */
#define TASKINIT_TASK 		5
#define TCPSERVER_TASK 		6

uint_32 SOCKET_NUM = 0;

extern void taskinit_task(uint_32);
extern void tcpserver_task(uint_32);


const TASK_TEMPLATE_STRUCT  MQX_template_list[] = 
{ 
		/* Task Index,   			Function,   			Stack,  Priority, 	Name,     						Attributes,          	Param, Time Slice */
    { TASKINIT_TASK,   		taskinit_task, 		1500,   9,      		"init tasks",  				MQX_AUTO_START_TASK|MQX_TIME_SLICE_TASK, 	0,     10 },
    { TCPSERVER_TASK,   	tcpserver_task,  	3000,   10,        	"tcpserver task",  		0, 										0,     0 },	
    { 0 }
};

/*TASK*-----------------------------------------------------
* 
* Task Name    : init_task
* Comments     :
*    This task initialize other tasks.
*
*END*-----------------------------------------------------*/
void taskinit_task (uint_32 initial_data)
{	
		uint_32          listensock, error, sock;
		sockaddr         addr;
		_task_id 				 task_id;
		
    _enet_address                       address;
    IPCFG_IP_ADDRESS_DATA								ip_data;
    
		error = RTCS_create();
		if (error != RTCS_OK) 
    {
        printf("RTCS failed to initialize, error = 0x%X\n", error);
        _task_block();
    }
    
		ip_data.ip      = IPADDR(192, 168, 0, 99);
    ip_data.mask    = IPADDR(255, 255, 255, 0);
    ip_data.gateway = IPADDR(192, 168, 0, 1);

		ENET_get_mac_address (0, ip_data.ip, address);
    error = ipcfg_init_device (0, address);
    if (error != RTCS_OK) 
    {
        printf("IPCFG: Device init failed. Error = 0x%X\n", error);
        _task_set_error(MQX_OK);
    }

    error = ipcfg_bind_staticip (0, &ip_data);
    //error = ipcfg_bind_dhcp_wait(0, TRUE, &ip_data);

    if (error != RTCS_OK) 
    {
        printf("\nIPCFG: Failed to bind IP address. Error = 0x%X", error);
        _task_block();
    }

		listensock =  socket(PF_INET, SOCK_STREAM, 0);
		if(listensock == RTCS_SOCKET_ERROR)
		{
				printf("\n Socket initialize failure \n");
				_task_block();
		}

		((sockaddr_in*)(&addr))->sin_family         = PF_INET;
		((sockaddr_in*)(&addr))->sin_port           = 2020;
		((sockaddr_in*)(&addr))->sin_addr.s_addr    = INADDR_ANY;
		error = bind(listensock, &addr, sizeof(sockaddr));
   	if(error != RTCS_OK)
		{
				printf("\n Bind socket failure \n");
				_task_block();
		}
		
		error = listen(listensock, 0);
		if(error != RTCS_OK)
		{
				printf("\n Listen socket failure \n");
				_task_block();
		}
		else
		{
				printf("\n Listen socket success \n");
		}

	  while(1)
	  {
		  /* Wait for a connection */
		  sock= accept(listensock, NULL, NULL);
		  if(SOCKET_NUM<4)
		  {
			  if (sock != RTCS_SOCKET_ERROR)
				{
					task_id = _task_create(0, TCPSERVER_TASK, sock);
					if (task_id != MQX_NULL_TASK_ID)
					{
						printf("\n Socket task create success \n");
						SOCKET_NUM++;
					}
			  }
			  else
			  {
			  	printf("\n Socket accept failure \n");
	       	_task_block();
			  }
			}
			else
			{
				shutdown(sock, FLAG_CLOSE_TX);
			}
		}
}


/*TASK*-----------------------------------------------------
* 
* Task Name    : tcpserver_task
* Comments     :
*    This task
*
*END*-----------------------------------------------------*/
void tcpserver_task(uint_32 initial_data)
{
	char  data_buffer[1500];
  uint_32 count, error;
	while(TRUE)
	{
		count = recv(initial_data, data_buffer, 1500, 0);
		if (count == RTCS_ERROR)
		{
			error = RTCS_geterror(initial_data);
		  if(error == RTCS_OK)
		  {
		  	shutdown(initial_data, FLAG_CLOSE_TX);
		  	if(SOCKET_NUM--);
		  	_task_destroy(MQX_NULL_TASK_ID);
		  }
		  else
		  {
		  	shutdown(initial_data, FLAG_CLOSE_TX);
		  	if(SOCKET_NUM--);
		  	_task_destroy(MQX_NULL_TASK_ID);
		  }
		}
	  send(initial_data, data_buffer, count, 0);
	}
}