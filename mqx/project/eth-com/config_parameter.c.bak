#include "config_parameter.h"

#include "flash.h"
#include <string.h>

ENET_PARAMETER Enet_Device;
SCI_PARAMETER Sci0_Parameter;

MQX_FILE_PTR SCI0;

uint_8 Sys_Mode;

uint_8 Ip_Get_Mode;
uint_32 Web_Port=80;
uint_32 Cmd_Port=3003;
uint_32 Cfg_Port=65000;
uint_32 Broad_Cast_Port=55148;
uint_8 Global_Password[16];
uint_8 Global_Name[16];

const uint_8 flash_parameter_cmp_data[16]={"Falsh is data ok"};
const uint_8 flash_parameter_default_data[]=
{
      6,0x45,0x58,0x50,0x4f,0x52,0x54,  0,  0,  0,  0,  0,  0,  0,  0,  0,

      5,0x38,0x38,0x38,0x38,0x38,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    
      0,  1,194,  0,  8,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,
    
    192,168,  0, 77,  0,  0,  0,  0,  0,  0,  0,  0, 23,116,  0,  0,
    192,168,  0, 77,  0,  0,  0,  0,  0,  0,  0,  0, 23,115,  0,  0,
    192,168,  0, 77,  0,  0,  0,  0,  0,  0,  0,  0, 23,114,  0,  0,
    192,168,  0, 77,  0,  0,  0,  0,  0,  0,  0,  0, 23,113,  0,  0,
                                                                    
    192,168,  0, 77,  0,  0,  0,  0,  0,  0,  0,  0, 23,116,  0,  0,
    192,168,  0, 77,  0,  0,  0,  0,  0,  0,  0,  0, 23,115,  0,  0,
    192,168,  0, 77,  0,  0,  0,  0,  0,  0,  0,  0, 23,114,  0,  0,
    192,168,  0, 77,  0,  0,  0,  0,  0,  0,  0,  0, 23,113,  0,  0,
    
    192,168,  0, 99,255,255,255,  0,192,168,  0,  1, 15,161,  0,  4
};

static void get_mac_address(void)
{
   Enet_Device.G_Mac_Address[0] = (SIM_UIDL & 0xFF);
   Enet_Device.G_Mac_Address[1] = (SIM_UIDL & 0xFF00) >> 8;
   Enet_Device.G_Mac_Address[2] = (SIM_UIDL & 0xFF0000) >> 16;
   Enet_Device.G_Mac_Address[3] = (SIM_UIDL & 0xFF000000) >> 24;
   Enet_Device.G_Mac_Address[4] = 0x55;
   Enet_Device.G_Mac_Address[5] = 0xAA;
}

static uint_8 check_falsh_ok(void)
{
    uint_8 flash_data[16];
    Flash_Read(-16,3,(char_ptr)flash_data,16);
    return strncmp((char *)flash_data, (char *)flash_parameter_cmp_data,16);
}

void Get_Parameter_Data(void)
{
    uint_8 i, flash_data[16];
    uint_32 sci_set_data;
    
    Flash_Read(-16*2,3,(char_ptr)flash_data,16);
    
    Enet_Device.G_Enet_Mode = flash_data[14];
    
    Enet_Device.G_Ip_Data.ip      = IPADDR(flash_data[0], flash_data[1], flash_data[2], flash_data[3]);
    Enet_Device.G_Ip_Data.mask    = IPADDR(flash_data[4], flash_data[5], flash_data[6], flash_data[7]);
    Enet_Device.G_Ip_Data.gateway = IPADDR(flash_data[8], flash_data[9], flash_data[10], flash_data[11]);
    
    Enet_Device.G_Addr_UDP_LOCAL.sin_family			= Enet_Device.G_Addr_TCP_SERVER.sin_family       = PF_INET;
    Enet_Device.G_Addr_UDP_LOCAL.sin_port			= Enet_Device.G_Addr_TCP_SERVER.sin_port         = (((uint_32)(flash_data[12])&0xFF)<<8)|((uint_32)(flash_data[13])&0xFF);
    Enet_Device.G_Addr_UDP_LOCAL.sin_addr.s_addr 	= Enet_Device.G_Addr_TCP_SERVER.sin_addr.s_addr  = INADDR_ANY;  
    
    Enet_Device.MAX_SOCKET_NUM = flash_data[15];    
    
    for (i=0; i<4; i++)
    {
        Flash_Read(-(16*(3+i)),3,(char_ptr)flash_data,16);
        Enet_Device.G_Addr_UDP_REMOTE[i].sin_family 		= Enet_Device.G_Addr_TCP_CLIENT[i].sin_family       = PF_INET;
        Enet_Device.G_Addr_UDP_REMOTE[i].sin_port 			= Enet_Device.G_Addr_TCP_CLIENT[i].sin_port         = (((uint_32)(flash_data[12])&0xFF)<<8)|((uint_32)(flash_data[13])&0xFF);
        Enet_Device.G_Addr_UDP_REMOTE[i].sin_addr.s_addr 	= Enet_Device.G_Addr_TCP_CLIENT[i].sin_addr.s_addr  = IPADDR(flash_data[0], flash_data[1], flash_data[2], flash_data[3]);
    }

    
    Flash_Read(-(16*(11)),3,(char_ptr)flash_data,16);
    
    sci_set_data = (((uint_32)(flash_data[0])&0xFF)<<24)|(((uint_32)(flash_data[1])&0xFF)<<16)|(((uint_32)(flash_data[2])&0xFF)<<8)|((uint_32)(flash_data[3])&0xFF);
    Sci0_Parameter.Baud = sci_set_data;
    ioctl( SCI0, IO_IOCTL_SERIAL_SET_BAUD, (pointer)&sci_set_data );
    
    sci_set_data = flash_data[4];
    Sci0_Parameter.Data_Bits = sci_set_data;
    ioctl( SCI0, IO_IOCTL_SERIAL_SET_DATA_BITS, (pointer)&sci_set_data );
        
    Sci0_Parameter.Stop_Bits = flash_data[5];
    switch(Sci0_Parameter.Stop_Bits)
    {
    	case 1:
    		sci_set_data = 1;
    	break;	
    	case 2:
    		sci_set_data = 3;
    	break;
    	default:
    		sci_set_data = 1;
    	break;
   	}
    ioctl( SCI0, IO_IOCTL_SERIAL_SET_STOP_BITS, (pointer)&sci_set_data );
    
    Sci0_Parameter.Parity = flash_data[6];
    switch(Sci0_Parameter.Parity)
    {
    	case 0:
    		sci_set_data = 1;
    	break;
    	case 1:
    		sci_set_data = 2;
    	break;	
    	case 2:
    		sci_set_data = 3;
    	break;
    	case 3:
    		sci_set_data = 6;
    	break;
    	case 4:
    		sci_set_data = 5;
    	break;
    	default:
    		sci_set_data = 1;
    	break;
   	}
    ioctl( SCI0, IO_IOCTL_SERIAL_SET_PARITY, (pointer)&sci_set_data );
    Ip_Get_Mode = flash_data[15];
    Flash_Read(-(16*(12)),3,(char_ptr)flash_data,16);
    for (i=0; i<16; i++)
    {
        Global_Password[i]= flash_data[i];
    }
    Flash_Read(-(16*(13)),3,(char_ptr)flash_data,16);
    for (i=0; i<16; i++)
    {
        Global_Name[i]= flash_data[i];
    } 
}

void Reset_Parameter_Data(void)
{
    Flash_Write(-(16*13),3,(char_ptr)flash_parameter_default_data,16*12);
    Flash_Write(-16,3,(char_ptr)flash_parameter_cmp_data,16); 
    Get_Parameter_Data();
}


void Init_Default_Parameter(void)
{
    get_mac_address();
    /**/
    if(check_falsh_ok()!=0)
    {
        Reset_Parameter_Data();
    }
    else
    {
        Get_Parameter_Data();
    }
}
