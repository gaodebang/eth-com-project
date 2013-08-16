#include "mqx_eth_com_main.h"

typedef struct enet_parameter
{
    _enet_address G_Mac_Address;
    IPCFG_IP_ADDRESS_DATA G_Ip_Data;
    uint_8 G_Enet_Mode;
    sockaddr G_Addr_TCP_SERVER;
    sockaddr G_Addr_TCP_CLIENT[4];
    sockaddr G_Addr_UDP_LOCAL;
    sockaddr G_Addr_UDP_REMOTE[4];
    uint_8 MAX_SOCKET_NUM;
}ENET_PARAMETER;

extern ENET_PARAMETER Enet_Device;

extern MQX_FILE_PTR SCI0;

extern uint_8 Sys_Mode;

extern void Init_Default_Parameter(void);
extern void Reset_Parameter_Data(void);
