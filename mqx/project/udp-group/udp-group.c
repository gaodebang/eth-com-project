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
#define UDPSERVER_TASK 		6

#define PUERTO 5000
#define GRUPO "224.3.0.1"


extern void taskinit_task(uint_32);
extern void udpserver_task(uint_32);


const TASK_TEMPLATE_STRUCT  MQX_template_list[] = 
{ 
		/* Task Index,   			Function,   			Stack,  Priority, 	Name,     						Attributes,          	Param, Time Slice */
    { TASKINIT_TASK,   		taskinit_task, 		1500,   9,      		"init tasks",  				MQX_AUTO_START_TASK, 	0,     0 },
    { UDPSERVER_TASK,   	udpserver_task,  	3000,   10,        	"udpserver task",  		0, 										0,     0 },	
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
		uint_32          listensock, error, option;
		sockaddr         addr;
		ip_mreq 				 mreq;
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

		listensock =  socket(PF_INET, SOCK_DGRAM, 0);
		if(listensock == RTCS_SOCKET_ERROR)
		{
				printf("\n Socket initialize failure \n");
				_task_block();
		}

		addr.sin_family         = PF_INET;
		addr.sin_port           = PUERTO;
		inet_aton(GRUPO, &(addr.sin_addr));
		error = bind(listensock, &addr, sizeof(sockaddr));
   	if(error == RTCS_OK)
		{
			task_id = _task_create(0, UDPSERVER_TASK, listensock);
			if (task_id != MQX_NULL_TASK_ID)
			{
				printf("\n Socket task create success \n");
			}
	  }
	  else
	  {
	  	printf("\n Bind socket failure \n");
	  	shutdown (listensock, FLAG_CLOSE_TX);
	  	_task_block();
	  }
	  inet_aton(GRUPO, &(mreq.imr_multiaddr));
	  inet_aton("192.168.0.99", &(mreq.imr_interface));
	   
    error = setsockopt(listensock, SOL_IGMP, RTCS_SO_IGMP_ADD_MEMBERSHIP, &mreq, sizeof(ip_mreq));
		if(error != RTCS_OK)
		{
				printf("\n Set socket option failure \n");
				_task_block();
		}
}


/*TASK*-----------------------------------------------------
* 
* Task Name    : udpserver_task
* Comments     :
*    This task
*
*END*-----------------------------------------------------*/
void udpserver_task(uint_32 initial_data)
{
	char  data_buffer[1500];
  uint_32 count, handle;
  sockaddr         addr;
  uint_16      remote_len = sizeof(sockaddr);
		addr.sin_family         = PF_INET;
		addr.sin_port           = PUERTO;
		inet_aton(GRUPO, &(addr.sin_addr));
	while(TRUE)
	{
		count = recvfrom(initial_data, data_buffer, 1500, 0, &addr, &remote_len);
		if (count == RTCS_ERROR)
		{
		  printf("\n Error, recv() failed with error code %lx \n",RTCS_geterror(handle));
		}
	  sendto(initial_data, data_buffer, count, 0, &addr, sizeof(sockaddr));
	}
}