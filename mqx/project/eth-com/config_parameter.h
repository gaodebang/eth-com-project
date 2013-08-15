#include "mqx_eth_com_main.h"

//
//typedef struct enet_parameter
//{
//    _enet_address           G_Mac_Address;      //mac��ַռ6���ֽڣ�offset��0
//    IPCFG_IP_ADDRESS_DATA   G_Ip_Data;          //ip��ַ������ռ3*4=12���ֽ�
//    uint_8 G_Enet_Mode;                         //��̫������ģʽ��tcp-server��tcp-clinet��udp
//    sockaddr G_Addr_TCP_SERVER;                            //socket����
//    
//    sockaddr G_Addr_TCP_CLIENT[4];                            //socket����
//    
//    sockaddr G_Addr_UDP_LOCAL;                            //socket����
//    sockaddr G_Addr_UDP_REMOTE[4];                            //socket����
//    
//    uint_8 MAX_SOCKET_NUM;                      //socket���������
//}ENET_PARAMETER;


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

extern void Init_Default_Parameter(void);
