#include "config_parameter.h"

ENET_PARAMETER Enet_Device;

MQX_FILE_PTR SCI3;

static void get_mac_address(void)
{
   Enet_Device.G_Mac_Address[0] = (SIM_UIDL & 0xFF);
   Enet_Device.G_Mac_Address[1] = (SIM_UIDL & 0xFF00) >> 8;
   Enet_Device.G_Mac_Address[2] = (SIM_UIDL & 0xFF0000) >> 16;
   Enet_Device.G_Mac_Address[3] = (SIM_UIDL & 0xFF000000) >> 24;
   Enet_Device.G_Mac_Address[4] = 0x55;
   Enet_Device.G_Mac_Address[5] = 0xAA;    
}



void Init_Default_Parameter(void)
{
    uint_8 i;
    get_mac_address();
    
    Enet_Device.G_Ip_Data.ip      = IPADDR(192, 168, 0, 99);
    Enet_Device.G_Ip_Data.mask    = IPADDR(255, 255, 255, 0);
    Enet_Device.G_Ip_Data.gateway = IPADDR(192, 168, 0, 1);
    
    Enet_Device.G_Enet_Mode = 2;
    
    Enet_Device.G_Addr_TCP_SERVER.sin_family       = PF_INET;
    Enet_Device.G_Addr_TCP_SERVER.sin_port         = 4001;
    Enet_Device.G_Addr_TCP_SERVER.sin_addr.s_addr  = INADDR_ANY;
    
    for (i=0; i<4; i++)
    {
        Enet_Device.G_Addr_TCP_CLIENT[i].sin_family       = PF_INET;
        Enet_Device.G_Addr_TCP_CLIENT[i].sin_port         = 6000+i;
        Enet_Device.G_Addr_TCP_CLIENT[i].sin_addr.s_addr  = IPADDR(192, 168, 0, 77);
    }
    
    Enet_Device.G_Addr_UDP_LOCAL.sin_family       = PF_INET;
    Enet_Device.G_Addr_UDP_LOCAL.sin_port         = 4001;
    Enet_Device.G_Addr_UDP_LOCAL.sin_addr.s_addr  = INADDR_ANY;
    for (i=0; i<4; i++)
    {
        Enet_Device.G_Addr_UDP_REMOTE[i].sin_family       = PF_INET;
        Enet_Device.G_Addr_UDP_REMOTE[i].sin_port         = 6000+i;
        Enet_Device.G_Addr_UDP_REMOTE[i].sin_addr.s_addr  = IPADDR(192, 168, 0, 77);
    }
    Enet_Device.MAX_SOCKET_NUM = 4;
    
}