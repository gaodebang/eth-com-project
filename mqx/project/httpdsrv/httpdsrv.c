#include <mqx.h>
#include <bsp.h> 
#include <fio.h>
#include <rtcs.h>
#include <ipcfg.h>


#include "httpd.h"
#include "tfs.h"

#if ! BSPCFG_ENABLE_IO_SUBSYSTEM
#error This application requires BSPCFG_ENABLE_IO_SUBSYSTEM defined non-zero in user_config.h. Please recompile BSP with this option.
#endif

#ifndef BSP_DEFAULT_IO_CHANNEL_DEFINED
#error This application requires BSP_DEFAULT_IO_CHANNEL to be not NULL. Please set corresponding BSPCFG_ENABLE_TTYx to non-zero in user_config.h and recompile BSP with this option.
#endif

/* Task IDs */
#define TASKINIT_TASK 		5


extern void taskinit_task(uint_32);


const TASK_TEMPLATE_STRUCT  MQX_template_list[] = 
{ 
		/* Task Index,   			Function,   			Stack,  Priority, 	Name,     						Attributes,          	Param, Time Slice */
    { TASKINIT_TASK,   		taskinit_task, 		1500,   9,      		"init tasks",  				MQX_AUTO_START_TASK, 	0,     0 },
    { 0 }
};

const HTTPD_ROOT_DIR_STRUCT root_dir[] = {
    { "", "tfs:" },
    { 0, 0 }
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
		uint_32           error;
		char*						 index;
    _enet_address                       address;
    IPCFG_IP_ADDRESS_DATA								ip_data;
    HTTPD_STRUCT                        *server;
    extern const TFS_DIR_ENTRY          tfs_data[];
		error = RTCS_create();
		if (error != RTCS_OK) 
    {
        printf("RTCS failed to initialize, error = 0x%X\n", error);
        _task_block();
    }
    
		ip_data.ip      = IPADDR(192, 168, 0, 66);
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
		
		//index = (char*) _mem_alloc(sizeof("\\index_x.html"));

    error = _io_tfs_install("tfs:", tfs_data);
    
    server = httpd_server_init((HTTPD_ROOT_DIR_STRUCT*)root_dir, "\\index.html");

		httpd_server_run(server);

		_task_block();
}