#include "shell_at.h"
#include "flash.h"
#include "config_parameter.h"
#include <string.h>
#include <stdlib.h>
extern void __boot(void);

const char Num_Buffer[]={"0123456789"};
const char Error_Buffer[]={"\r\nERROR\r\n"};
const char Error0_Buffer[]={"\r\n0_Command Invalid\r\nERROR\r\n"};
const char Error1_Buffer[]={"\r\n1_No Login\r\nERROR\r\n"};
const char Error2_Buffer[]={"\r\n2_PassWord Error\r\nERROR\r\n"};
const char Error3_Buffer[]={"\r\n3_Parameter Format Error\r\nERROR\r\n"};
const char Error4_Buffer[]={"\r\n4_Parameter Number Error\r\nERROR\r\n"};
const char Error5_Buffer[]={"\r\n5_Para meter Read Only\r\n"};

const char Login_Ok_Buffer[]={"\r\nLogin success\r\nOK\r\n"};

const char OK_Buffer[]={"\r\nOK\r\n"};
const char OK_Buffer0[]={"\"\r\nOK\r\n"};

const char welcom0[]={"Pelse Input \"at+login='password'\" Login NETCOM Config Tool.\r\n"};


const char Type_Buffer[]={"\r\n[TYPE] Value is:\"EXPORT\"\r\nOK\r\n"};
const char Name_Buffer[]={"\r\n[NAME] Value is:\""};
const char Pass_Buffer[]={"\r\n[PASS] Value is:\""};
const char Ip_Buffer[]={"\r\n[IP] Value is:\""};
const char Mark_Buffer[]={"\r\n[MARK] Value is:\""};
const char GateWay_Buffer[]={"\r\n[GATEWAY] Value is:\""};
const char Dns_Buffer[]={"\r\n[DNS] Value is:\""};
const char Mac_Buffer[]={"\r\n[MAC] Value is:\""};
const char Ip_Mode_Buffer[]={"\r\n[IP_MODE] Value is:\""};
const char Web_Port_Buffer[]={"\r\n[WEB_PORT] Value is:\""};
const char Cmd_Port_Buffer[]={"\r\n[CMD_PORT] Value is:\""};

const char Echo_Buffer[]={"\r\n[ECHO] Value is:\""};

const char C1_Op_Buffer[]={"\r\n[C1_OP] Value is:\""};
const char C1_Port_Buffer[]={"\r\n[C1_PORT] Value is:\""};
const char C1_Baud_Buffer[]={"\r\n[C1_BAUD] Value is:\""};
const char C1_DataB_Buffer[]={"\r\n[C1_DATAB] Value is:\""};
const char C1_StopB_Buffer[]={"\r\n[C1_STOPB] Value is:\""};
const char C1_Parity_Buffer[]={"\r\n[C1_PARITY] Value is:\""};

const char C1_Link_Num_Buffer[]={"\r\n[C1_LINK_NUM] Value is:\""};
const char C1_Cli_Pp1_Buffer[]={"\r\n[C1_CLI_PP1] Value is:\""};
const char C1_Cli_Ip1_Buffer[]={"\r\n[C1_CLI_IP1] Value is:\""};
const char C1_Cli_Pp2_Buffer[]={"\r\n[C1_CLI_PP2] Value is:\""};
const char C1_Cli_Ip2_Buffer[]={"\r\n[C1_CLI_IP2] Value is:\""};
const char C1_Cli_Pp3_Buffer[]={"\r\n[C1_CLI_PP3] Value is:\""};
const char C1_Cli_Ip3_Buffer[]={"\r\n[C1_CLI_IP3] Value is:\""};
const char C1_Cli_Pp4_Buffer[]={"\r\n[C1_CLI_PP4] Value is:\""};
const char C1_Cli_Ip4_Buffer[]={"\r\n[C1_CLI_IP4] Value is:\""};


const char List_Buffer0[]={"\r\nTYPE		NAME		PASS		IP		MARK\r\n"};
const char List_Buffer1[]={"\r\nGATEWAY		DNS		MAC		IP_MODE		WEB_PORT\r\n"};
const char List_Buffer2[]={"\r\nCMD_PORT	IPF1		IPF2		IPF3		IPF4\r\n"};
const char List_Buffer3[]={"\r\nIPF5		IPF6		IPF7		IPF8		PPPOE_EN\r\n"};
const char List_Buffer4[]={"\r\nPPPOE_USER	PPPOE_PASS	PPPOE_IP	NETCFGEN	TCPCLICONCTL\r\n"};
const char List_Buffer5[]={"\r\nCLI_IP_RAM	CLI_PP_RAM	GATEWAY_RAM	TYPE		NAME\r\n"};
const char List_Buffer6[]={"\r\nPASS		IP		MARK		GATEWAY		DNS\r\n"};
const char List_Buffer7[]={"\r\nMAC		IP_MODE		WEB_PORT	CMD_PORT	IPF1\r\n"};
const char List_Buffer8[]={"\r\nIPF2		IPF3		IPF4		IPF5		IPF6\r\n"};
const char List_Buffer9[]={"\r\nIPF7		IPF8		PPPOE_EN	PPPOE_USER	PPPOE_PASS\r\n"};
const char List_Buffer10[]={"\r\nPPPOE_IP	NETCFGEN	TCPCLICONCTL	CLI_IP_RAM	CLI_PP_RAM\r\n"};
const char List_Buffer11[]={"\r\nGATEWAY_RAM	C*_OP		C*_PORT		C*_BAUD		C*_DATAB\r\n"};
const char List_Buffer12[]={"\r\nC*_STOPB	C*_PARITY	C*_SER_C	C*_BUF_CLS	C*_TCP_TURBO\r\n"};
const char List_Buffer13[]={"\r\nC*_SER_LEN	C*_SER_T	C*_D1		C*_D2		C*_IT\r\n"};
const char List_Buffer14[]={"\r\nC*_TCPAT	C*_TCP_CLS	C*_LINK_NUM	C*_LINK_P	C*_LINK_S\r\n"};
const char List_Buffer15[]={"\r\nC*_LINK_T	C*_CLI_IP1	C*_CLI_PP1	C*_CLI_IP2	C*_CLI_PP2\r\n"};
const char List_Buffer16[]={"\r\nC*_CLI_IP3	C*_CLI_PP3	C*_CLI_IP4	C*_CLI_PP4	C*_SEND_NUM\r\n"};
const char List_Buffer17[]={"\r\nC*_RCV_NUM	C*_LINE_STA	C*_LINK_STA	LIST		LOGIN\r\n"};
const char List_Buffer18[]={"\r\nLANGUAGE	MODE		ECHO		DEFAULT		RESET\r\n"};
const char List_Buffer19[]={"\r\nBootloader	NETSEND		NETSENDOK	NETRCV		NETRCVOK\r\n"};
const char List_Buffer20[]={"\r\nRUNTIME		TCPSTATUS	FileDownload	IOSTASETTOE	IOOUTTOE\r\n"};
const char List_Buffer21[]={"\r\nIOSTASET	IORDORWR	IOADC0		IOADC1		EXIT\r\n"};



char Logined = 0;
char Echo_En = 1;


uint_8 find_at(char_ptr data_addr, char num)
{
    uint_32 temp_long_ip;
    uint_8 i, length;
    uint_8 temp_net_data[16];
    if((data_addr[0]=='t')&&(data_addr[1]=='y')&&(data_addr[2]=='p')&&(data_addr[3]=='e')&&(data_addr[4]=='?')&&(num==5))
    {
        write(SCI0, (char *)Type_Buffer, sizeof(Type_Buffer));
        fflush(SCI0);
    }
    else if((data_addr[0]=='n')&&(data_addr[1]=='a')&&(data_addr[2]=='m')&&(data_addr[3]=='e')&&((data_addr[4]=='?')||(data_addr[4]=='=')))
    {
        if(data_addr[4]=='?')
        {
            write(SCI0, (char *)Name_Buffer, sizeof(Name_Buffer));
            fflush(SCI0);
            
            write(SCI0, (char *)(Global_Name+1), Global_Name[0]);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if((data_addr[4]=='=')&&(num>5)&&(num<=20))
        {
            Global_Name[0]=num-5;
            for (i=0; i<Global_Name[0]; i++)
            {
                Global_Name[1+i]=data_addr[5+i];
            }
            Flash_Write(-(16*(13)),3,(char_ptr)(Global_Name),16);
            write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);            
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
    else if((data_addr[0]=='p')&&(data_addr[1]=='a')&&(data_addr[2]=='s')&&(data_addr[3]=='s')&&((data_addr[4]=='?')||(data_addr[4]=='=')))
    {
        if(data_addr[4]=='?')
        {
            write(SCI0, (char *)Pass_Buffer, sizeof(Pass_Buffer));
            fflush(SCI0);
            
            write(SCI0, (char *)(Global_Password+1), Global_Password[0]);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if((data_addr[4]=='=')&&(num>5)&&(num<=20))
        {
            Global_Password[0]=num-5;
            for (i=0; i<Global_Password[0]; i++)
            {
                Global_Password[1+i]=data_addr[5+i];
            }
            Flash_Write(-(16*(12)),3,(char_ptr)(Global_Password),16);
            write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);            
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
    else if((data_addr[0]=='i')&&(data_addr[1]=='p')&&((data_addr[2]=='?')||(data_addr[2]=='=')))
    {
        if(data_addr[2]=='?')
        {
            write(SCI0, (char *)Ip_Buffer, sizeof(Ip_Buffer));
            fflush(SCI0);
            for(i=16;i>=7;i--)
            {
                if(inet_ntop(AF_INET, &Enet_Device.G_Ip_Data.ip, (char *)temp_net_data, i)==NULL)
                {
                    inet_ntop(AF_INET, &Enet_Device.G_Ip_Data.ip, (char *)temp_net_data, i+1);
                    break;
                }
            }
            
            write(SCI0, (char *)(temp_net_data), i);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if(data_addr[2]=='=')
        {
            temp_long_ip = inet_addr(data_addr+3);
            Enet_Device.G_Ip_Data.ip = temp_long_ip;
            
            temp_net_data[0] = ((temp_long_ip)>>24)&0xFF;
            temp_net_data[1] = ((temp_long_ip)>>16)&0xFF;
            temp_net_data[2] = ((temp_long_ip)>>8)&0xFF;
            temp_net_data[3] = (temp_long_ip)&0xFF;
            
            Flash_Write(-(16*(2)),3,(char *)(temp_net_data),4);
            
            write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
    else if((data_addr[0]=='m')&&(data_addr[1]=='a')&&(data_addr[2]=='r')&&(data_addr[3]=='k')&&((data_addr[4]=='?')||(data_addr[4]=='=')))
    {
        if(data_addr[4]=='?')
        {
            write(SCI0, (char *)Mark_Buffer, sizeof(Mark_Buffer));
            fflush(SCI0);
            for(i=16;i>=7;i--)
            {
                if(inet_ntop(AF_INET, &Enet_Device.G_Ip_Data.mask, (char *)temp_net_data, i)==NULL)
                {
                    inet_ntop(AF_INET, &Enet_Device.G_Ip_Data.mask, (char *)temp_net_data, i+1);
                    break;
                }
            }
            
            write(SCI0, (char *)(temp_net_data), i);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if(data_addr[4]=='=')
        {
            temp_long_ip = inet_addr(data_addr+5);
            Enet_Device.G_Ip_Data.mask = temp_long_ip;
            
            temp_net_data[0] = ((temp_long_ip)>>24)&0xFF;
            temp_net_data[1] = ((temp_long_ip)>>16)&0xFF;
            temp_net_data[2] = ((temp_long_ip)>>8)&0xFF;
            temp_net_data[3] = (temp_long_ip)&0xFF;
            
            Flash_Write(-(16*(2))+4,3,(char *)(temp_net_data),4);
            
            write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
    else if((data_addr[0]=='g')&&(data_addr[1]=='a')&&(data_addr[2]=='t')&&(data_addr[3]=='e')&&(data_addr[4]=='w')&&(data_addr[5]=='a')&&(data_addr[6]=='y')&&((data_addr[7]=='?')||(data_addr[7]=='=')))
    {
        if(data_addr[7]=='?')
        {
            write(SCI0, (char *)GateWay_Buffer, sizeof(GateWay_Buffer));
            fflush(SCI0);
            for(i=16;i>=7;i--)
            {
                if(inet_ntop(AF_INET, &Enet_Device.G_Ip_Data.gateway, (char *)temp_net_data, i)==NULL)
                {
                    inet_ntop(AF_INET, &Enet_Device.G_Ip_Data.gateway, (char *)temp_net_data, i+1);
                    break;
                }
            }
            
            write(SCI0, (char *)(temp_net_data), i);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if(data_addr[7]=='=')
        {
            temp_long_ip = inet_addr(data_addr+8);
            Enet_Device.G_Ip_Data.gateway = temp_long_ip;
            
            temp_net_data[0] = ((temp_long_ip)>>24)&0xFF;
            temp_net_data[1] = ((temp_long_ip)>>16)&0xFF;
            temp_net_data[2] = ((temp_long_ip)>>8)&0xFF;
            temp_net_data[3] = (temp_long_ip)&0xFF;
            
            Flash_Write(-(16*(2))+8,3,(char *)(temp_net_data),4);
            
            write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
    else if((data_addr[0]=='d')&&(data_addr[1]=='n')&&(data_addr[2]=='s')&&((data_addr[3]=='?')||(data_addr[3]=='=')))
    {
        if(data_addr[3]=='?')
        {
            write(SCI0, (char *)Dns_Buffer, sizeof(Dns_Buffer));
            fflush(SCI0);
            for(i=16;i>=7;i--)
            {
                if(inet_ntop(AF_INET, &Enet_Device.Dns_Ip_Data, (char *)temp_net_data, i)==NULL)
                {
                    inet_ntop(AF_INET, &Enet_Device.Dns_Ip_Data, (char *)temp_net_data, i+1);
                    break;
                }
            }
            
            write(SCI0, (char *)(temp_net_data), i);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if(data_addr[3]=='=')
        {
            temp_long_ip = inet_addr(data_addr+8);
            Enet_Device.Dns_Ip_Data = temp_long_ip;
            
            temp_net_data[0] = ((temp_long_ip)>>24)&0xFF;
            temp_net_data[1] = ((temp_long_ip)>>16)&0xFF;
            temp_net_data[2] = ((temp_long_ip)>>8)&0xFF;
            temp_net_data[3] = (temp_long_ip)&0xFF;
            
            //Flash_Write(-(16*(2))+8,3,(char *)(temp_net_data),4);
            
            write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
    else if((data_addr[0]=='m')&&(data_addr[1]=='a')&&(data_addr[2]=='c')&&(data_addr[3]=='?')&&(num==4))
    {
        write(SCI0, (char *)Mac_Buffer, sizeof(Mac_Buffer));
        fflush(SCI0);
        
        write(SCI0, (char *)(Enet_Device.G_Mac_Address), 6);
        fflush(SCI0);
        
        write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
        fflush(SCI0);
    }
    else if((data_addr[0]=='i')&&(data_addr[1]=='p')&&(data_addr[2]=='_')&&(data_addr[3]=='m')&&(data_addr[4]=='o')&&(data_addr[5]=='d')&&(data_addr[6]=='e')&&((data_addr[7]=='?')||(data_addr[7]=='=')))
    {
        if(data_addr[7]=='?')
        {
            write(SCI0, (char *)Ip_Mode_Buffer, sizeof(Ip_Mode_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Ip_Get_Mode);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if((data_addr[7]=='=')&&(num==9))
        {
            if(data_addr[8]==0x30)
            {
                Ip_Get_Mode = 0;
            	Flash_Write(-(16*(11)+15),3,(char *)(&Ip_Get_Mode),1);
                
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);                 
            }
            else if(data_addr[8]==0x31)
            {
                Ip_Get_Mode = 1;
            	Flash_Write(-(16*(11)+15),3,(char *)(&Ip_Get_Mode),1);
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);                   
            }
            else
            {
                write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
                fflush(SCI0);
            }
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
    else if((data_addr[0]=='w')&&(data_addr[1]=='e')&&(data_addr[2]=='b')&&(data_addr[3]=='_')&&(data_addr[4]=='p')&&(data_addr[5]=='o')&&(data_addr[6]=='r')&&(data_addr[7]=='t')&&((data_addr[8]=='?')||(data_addr[8]=='=')))
    {
        if(data_addr[8]=='?')
        {
            write(SCI0, (char *)Web_Port_Buffer, sizeof(Web_Port_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Web_Port);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);        	
        }
        else if((data_addr[8]=='=')&&(num<=15))
        {
        	Web_Port = atoi((char *)(data_addr+9));
        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
  	}
    else if((data_addr[0]=='c')&&(data_addr[1]=='m')&&(data_addr[2]=='d')&&(data_addr[3]=='_')&&(data_addr[4]=='p')&&(data_addr[5]=='o')&&(data_addr[6]=='r')&&(data_addr[7]=='t')&&((data_addr[8]=='?')||(data_addr[8]=='=')))
    {
        if(data_addr[8]=='?')
        {
            write(SCI0, (char *)Cmd_Port_Buffer, sizeof(Cmd_Port_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Cmd_Port);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);        	
        }
        else if((data_addr[8]=='=')&&(num<=15))
        {
        	Cmd_Port = atoi((char *)(data_addr+9));
        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
  	}  	
    else if((data_addr[0]=='e')&&(data_addr[1]=='x')&&(data_addr[2]=='i')&&(data_addr[3]=='t')&&(num==4))
    {
        write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
        fflush(SCI0); 
        Logined = 0;
    }
    else if((data_addr[0]=='r')&&(data_addr[1]=='e')&&(data_addr[2]=='s')&&(data_addr[3]=='e')&&(data_addr[4]=='t')&&(data_addr[5]=='='))
    {
        if(num!=Global_Password[0]+6)
        {
            write(SCI0, (char *)Error2_Buffer, sizeof(Error2_Buffer));
            fflush(SCI0);
            return 0;                    
        }
        for (i=0; i<Global_Password[0]; i++)
        {
            if(Global_Password[1+i] != data_addr[6+i])
            {
                write(SCI0, (char *)Error2_Buffer, sizeof(Error2_Buffer));
                fflush(SCI0);
                return 0;
            }
        }
        write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
        fflush(SCI0);
        _time_delay(100);
        __boot();
    }
    else if((data_addr[0]=='d')&&(data_addr[1]=='e')&&(data_addr[2]=='f')&&(data_addr[3]=='a')&&(data_addr[4]=='u')&&(data_addr[5]=='l')&&(data_addr[6]=='t')&&(data_addr[7]=='='))
    {
        if(num!=Global_Password[0]+8)
        {
            write(SCI0, (char *)Error2_Buffer, sizeof(Error2_Buffer));
            fflush(SCI0);
            return 0;                    
        }
        for (i=0; i<Global_Password[0]; i++)
        {
            if(Global_Password[1+i] != data_addr[8+i])
            {
                write(SCI0, (char *)Error2_Buffer, sizeof(Error2_Buffer));
                fflush(SCI0);
                return 0;
            }
        }
        write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
        fflush(SCI0);
        Reset_Parameter_Data();
        _time_delay(100);
        __boot();
    }
    else if((data_addr[0]=='l')&&(data_addr[1]=='o')&&(data_addr[2]=='g')&&(data_addr[3]=='i')&&(data_addr[4]=='n')&&(num==5))
    {
        write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
        fflush(SCI0);
    }
    else if((data_addr[0]=='e')&&(data_addr[1]=='c')&&(data_addr[2]=='h')&&(data_addr[3]=='o')&&(num==4))
    {
        if(data_addr[4]=='?')
        {
            write(SCI0, (char *)Echo_Buffer, sizeof(Echo_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Echo_En);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if((data_addr[4]=='=')&&(num==6))
        {
            if(data_addr[5]==0x30)
            {
                Echo_En = 0;
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);                 
            }
            else if(data_addr[5]==0x31)
            {
                Echo_En = 1;
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);                   
            }
            else
            {
                write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
                fflush(SCI0);
            }
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
    else if((data_addr[0]=='l')&&(data_addr[1]=='i')&&(data_addr[2]=='s')&&(data_addr[3]=='t')&&(data_addr[4]=='?')&&(num==5))
    {
    	write(SCI0, (char *)(List_Buffer0), sizeof(List_Buffer0));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer1), sizeof(List_Buffer1));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer2), sizeof(List_Buffer2));
    	fflush(SCI0);
    	
    	write(SCI0, (char *)(List_Buffer4), sizeof(List_Buffer4));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer5), sizeof(List_Buffer5));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer6), sizeof(List_Buffer6));
    	fflush(SCI0);
    	
    	write(SCI0, (char *)(List_Buffer7), sizeof(List_Buffer7));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer8), sizeof(List_Buffer8));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer9), sizeof(List_Buffer9));
    	fflush(SCI0);
    	
    	write(SCI0, (char *)(List_Buffer10), sizeof(List_Buffer10));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer11), sizeof(List_Buffer11));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer12), sizeof(List_Buffer12));
    	fflush(SCI0);
    	
    	write(SCI0, (char *)(List_Buffer13), sizeof(List_Buffer13));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer14), sizeof(List_Buffer14));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer15), sizeof(List_Buffer15));
    	fflush(SCI0);
    	
    	write(SCI0, (char *)(List_Buffer16), sizeof(List_Buffer16));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer17), sizeof(List_Buffer17));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer18), sizeof(List_Buffer18));
    	fflush(SCI0);
    	
    	write(SCI0, (char *)(List_Buffer19), sizeof(List_Buffer19));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer20), sizeof(List_Buffer20));
    	fflush(SCI0);
    	write(SCI0, (char *)(List_Buffer21), sizeof(List_Buffer21));
    	fflush(SCI0);
    	
    	write(SCI0, (char *)(OK_Buffer), sizeof(OK_Buffer));
    	fflush(SCI0);

    }
    else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='o')&&(data_addr[4]=='p')&&((data_addr[5]=='?')||(data_addr[5]=='=')))
	{
        if(data_addr[5]=='?')
        {
            write(SCI0, (char *)C1_Op_Buffer, sizeof(C1_Op_Buffer));
            fflush(SCI0);

            length = sprintf((char *)temp_net_data, "%d", Enet_Device.G_Enet_Mode);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if((data_addr[5]=='=')&&(num==7))
        {
            if(data_addr[6]==0x30)
            {
                Enet_Device.G_Enet_Mode = 0;
                Flash_Write(-16*2+14,3,(char_ptr)&Enet_Device.G_Enet_Mode,1);
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);                 
            }
            else if(data_addr[6]==0x31)
            {
                Enet_Device.G_Enet_Mode = 1;
                Flash_Write(-16*2+14,3,(char_ptr)&Enet_Device.G_Enet_Mode,1);
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);                   
            }
            else if(data_addr[6]==0x32)
            {
                Enet_Device.G_Enet_Mode = 2;
                Flash_Write(-16*2+14,3,(char_ptr)&Enet_Device.G_Enet_Mode,1);
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);                   
            }
            else if(data_addr[6]==0x33)
            {
                Enet_Device.G_Enet_Mode = 3;
                Flash_Write(-16*2+14,3,(char_ptr)&Enet_Device.G_Enet_Mode,1);
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);                   
            }
            else if(data_addr[6]==0x34)
            {
                Enet_Device.G_Enet_Mode = 4;
                Flash_Write(-16*2+14,3,(char_ptr)&Enet_Device.G_Enet_Mode,1);
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);                   
            }
            else
            {
                write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
                fflush(SCI0);
            }
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }		
	}
    else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='p')&&(data_addr[4]=='o')&&(data_addr[5]=='r')&&(data_addr[6]=='t')&&((data_addr[7]=='?')||(data_addr[7]=='=')))
	{
        if(data_addr[7]=='?')
        {
            write(SCI0, (char *)C1_Port_Buffer, sizeof(C1_Port_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Enet_Device.G_Addr_TCP_SERVER.sin_port);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if((data_addr[7]=='=')&&(num<=14))
        {
        	Enet_Device.G_Addr_TCP_SERVER.sin_port = Enet_Device.G_Addr_UDP_LOCAL.sin_port = atoi((char *)(data_addr+8));
        	temp_net_data[0] = ((Enet_Device.G_Addr_TCP_SERVER.sin_port)>>8)&0xFF;
            temp_net_data[1] = (Enet_Device.G_Addr_TCP_SERVER.sin_port)&0xFF;
			Flash_Write(-16*2+12,3,(char_ptr)temp_net_data,2);
        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }		
	}
    else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='b')&&(data_addr[4]=='a')&&(data_addr[5]=='u')&&(data_addr[6]=='d')&&((data_addr[7]=='?')||(data_addr[7]=='=')))
	{
        if(data_addr[7]=='?')
        {
            write(SCI0, (char *)C1_Baud_Buffer, sizeof(C1_Baud_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Sci0_Parameter.Baud);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if((data_addr[7]=='=')&&(num<=15))
        {
        	Sci0_Parameter.Baud = atoi((char *)(data_addr+8));
        	temp_net_data[0] = ((Enet_Device.G_Addr_TCP_SERVER.sin_port)>>24)&0xFF;
            temp_net_data[1] = ((Enet_Device.G_Addr_TCP_SERVER.sin_port)>>16)&0xFF;
            temp_net_data[2] = ((Enet_Device.G_Addr_TCP_SERVER.sin_port)>>8)&0xFF;
            temp_net_data[3] = (Enet_Device.G_Addr_TCP_SERVER.sin_port)&0xFF;
			Flash_Write(-16*11,3,(char_ptr)temp_net_data,4);
        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }		
	}
    else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='d')&&(data_addr[4]=='a')&&(data_addr[5]=='t')&&(data_addr[6]=='a')&&(data_addr[7]=='b')&&((data_addr[8]=='?')||(data_addr[8]=='=')))
	{
        if(data_addr[8]=='?')
        {
            write(SCI0, (char *)C1_DataB_Buffer, sizeof(C1_DataB_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Sci0_Parameter.Data_Bits);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if((data_addr[8]=='=')&&(num==10))
        {
            if(0x35<=(*(data_addr+9))&&(*(data_addr+9))<=0x38)
            {
	        	Sci0_Parameter.Data_Bits = atoi((char *)(data_addr+9));
	            temp_net_data[0] = (Sci0_Parameter.Data_Bits);
				Flash_Write(-16*11+4,3,(char_ptr)temp_net_data,1);
	        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
	            fflush(SCI0);            	
            }
            else
            {
                write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
                fflush(SCI0);
            }
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }		
	}
    else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='s')&&(data_addr[4]=='t')&&(data_addr[5]=='o')&&(data_addr[6]=='p')&&(data_addr[7]=='b')&&((data_addr[8]=='?')||(data_addr[8]=='=')))
	{
        if(data_addr[8]=='?')
        {
            write(SCI0, (char *)C1_StopB_Buffer, sizeof(C1_StopB_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Sci0_Parameter.Stop_Bits);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if((data_addr[8]=='=')&&(num==10))
        {
            if(0x31<=(*(data_addr+9))&&(*(data_addr+9))<=0x32)
            {
	        	Sci0_Parameter.Stop_Bits = atoi((char *)(data_addr+9));
	            temp_net_data[0] = (Sci0_Parameter.Stop_Bits);
				Flash_Write(-16*11+5,3,(char_ptr)temp_net_data,1);
	        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
	            fflush(SCI0);           	
            }
            else
            {
                write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
                fflush(SCI0);
            }
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }		
	}
    else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='p')&&(data_addr[4]=='a')&&(data_addr[5]=='r')&&(data_addr[6]=='i')&&(data_addr[7]=='t')&&(data_addr[8]=='y')&&((data_addr[9]=='?')||(data_addr[9]=='=')))
	{
        if(data_addr[9]=='?')
        {
            write(SCI0, (char *)C1_Parity_Buffer, sizeof(C1_Parity_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Sci0_Parameter.Parity);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if((data_addr[9]=='=')&&(num==11))
        {
            if(0x30<=(*(data_addr+10))&&(*(data_addr+10))<=0x34)
            {
	        	Sci0_Parameter.Parity = atoi((char *)(data_addr+10));
	            temp_net_data[0] = (Sci0_Parameter.Parity);
				Flash_Write(-16*11+6,3,(char_ptr)temp_net_data,1);
	        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
	            fflush(SCI0);           	
            }
            else
            {
                write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
                fflush(SCI0);
            }
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }		
	}
    else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='l')&&(data_addr[4]=='i')&&(data_addr[5]=='n')&&(data_addr[6]=='k')&&(data_addr[7]=='_')&&(data_addr[8]=='n')&&(data_addr[9]=='u')&&(data_addr[10]=='m')&&((data_addr[11]=='?')||(data_addr[11]=='=')))
	{
        if(data_addr[11]=='?')
        {
            write(SCI0, (char *)C1_Link_Num_Buffer, sizeof(C1_Link_Num_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Enet_Device.MAX_SOCKET_NUM);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if((data_addr[11]=='=')&&(num==13))
        {
            if(0x31<=(*(data_addr+12))&&(*(data_addr+12))<=0x34)
            {
	        	Enet_Device.MAX_SOCKET_NUM = atoi((char *)(data_addr+10));
	            temp_net_data[0] = (Sci0_Parameter.Parity);
				Flash_Write(-16*2+15,3,(char_ptr)temp_net_data,1);
	        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
	            fflush(SCI0);           	
            }
            else
            {
                write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
                fflush(SCI0);
            }
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }		
	}
	else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='c')&&(data_addr[4]=='l')&&(data_addr[5]=='i')&&(data_addr[6]=='_')&&(data_addr[7]=='p')&&(data_addr[8]=='p')&&(data_addr[9]=='1')&&((data_addr[10]=='?')||(data_addr[10]=='=')))
    {
        if(data_addr[10]=='?')
        {
            write(SCI0, (char *)C1_Cli_Pp1_Buffer, sizeof(C1_Cli_Pp1_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Enet_Device.G_Addr_TCP_CLIENT[0].sin_port);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);        	
        }
        else if(data_addr[10]=='=')
        {
        	Enet_Device.G_Addr_UDP_REMOTE[0].sin_port = Enet_Device.G_Addr_TCP_CLIENT[0].sin_port = atoi((char *)(data_addr+11));
        	temp_net_data[0] = ((Enet_Device.G_Addr_TCP_CLIENT[0].sin_port)>>8)&0xFF;
            temp_net_data[1] = (Enet_Device.G_Addr_TCP_CLIENT[0].sin_port)&0xFF;
			Flash_Write(-16*3+12,3,(char_ptr)temp_net_data,2);
        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
	else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='c')&&(data_addr[4]=='l')&&(data_addr[5]=='i')&&(data_addr[6]=='_')&&(data_addr[7]=='i')&&(data_addr[8]=='p')&&(data_addr[9]=='1')&&((data_addr[10]=='?')||(data_addr[10]=='=')))
    {
        if(data_addr[10]=='?')
        {
            write(SCI0, (char *)C1_Cli_Ip1_Buffer, sizeof(C1_Cli_Ip1_Buffer));
            fflush(SCI0);
            for(i=16;i>=7;i--)
            {
                if(inet_ntop(AF_INET, &Enet_Device.G_Addr_TCP_CLIENT[0].sin_addr.s_addr, (char *)temp_net_data, i)==NULL)
                {
                    inet_ntop(AF_INET, &Enet_Device.G_Addr_TCP_CLIENT[0].sin_addr.s_addr, (char *)temp_net_data, i+1);
                    break;
                }
            }
            
            write(SCI0, (char *)(temp_net_data), i);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if(data_addr[10]=='=')
        {
            temp_long_ip = inet_addr(data_addr+11);
            Enet_Device.G_Addr_TCP_CLIENT[0].sin_addr.s_addr = Enet_Device.G_Addr_UDP_REMOTE[0].sin_addr.s_addr = temp_long_ip;
            
            temp_net_data[0] = ((temp_long_ip)>>24)&0xFF;
            temp_net_data[1] = ((temp_long_ip)>>16)&0xFF;
            temp_net_data[2] = ((temp_long_ip)>>8)&0xFF;
            temp_net_data[3] = (temp_long_ip)&0xFF;
            
            Flash_Write(-(16*(3)),3,(char *)(temp_net_data),4);
            
            write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
	else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='c')&&(data_addr[4]=='l')&&(data_addr[5]=='i')&&(data_addr[6]=='_')&&(data_addr[7]=='p')&&(data_addr[8]=='p')&&(data_addr[9]=='2')&&((data_addr[10]=='?')||(data_addr[10]=='=')))
    {
        if(data_addr[10]=='?')
        {
            write(SCI0, (char *)C1_Cli_Pp2_Buffer, sizeof(C1_Cli_Pp2_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Enet_Device.G_Addr_TCP_CLIENT[1].sin_port);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);        	
        }
        else if(data_addr[10]=='=')
        {
        	Enet_Device.G_Addr_UDP_REMOTE[0].sin_port = Enet_Device.G_Addr_TCP_CLIENT[1].sin_port = atoi((char *)(data_addr+11));
        	temp_net_data[0] = ((Enet_Device.G_Addr_TCP_CLIENT[0].sin_port)>>8)&0xFF;
            temp_net_data[1] = (Enet_Device.G_Addr_TCP_CLIENT[0].sin_port)&0xFF;
			Flash_Write(-16*4+12,3,(char_ptr)temp_net_data,2);
        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
	else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='c')&&(data_addr[4]=='l')&&(data_addr[5]=='i')&&(data_addr[6]=='_')&&(data_addr[7]=='i')&&(data_addr[8]=='p')&&(data_addr[9]=='2')&&((data_addr[10]=='?')||(data_addr[10]=='=')))
    {
        if(data_addr[10]=='?')
        {
            write(SCI0, (char *)C1_Cli_Ip2_Buffer, sizeof(C1_Cli_Ip2_Buffer));
            fflush(SCI0);
            for(i=16;i>=7;i--)
            {
                if(inet_ntop(AF_INET, &Enet_Device.G_Addr_TCP_CLIENT[1].sin_addr.s_addr, (char *)temp_net_data, i)==NULL)
                {
                    inet_ntop(AF_INET, &Enet_Device.G_Addr_TCP_CLIENT[1].sin_addr.s_addr, (char *)temp_net_data, i+1);
                    break;
                }
            }
            
            write(SCI0, (char *)(temp_net_data), i);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if(data_addr[10]=='=')
        {
            temp_long_ip = inet_addr(data_addr+11);
            Enet_Device.G_Addr_TCP_CLIENT[0].sin_addr.s_addr = Enet_Device.G_Addr_UDP_REMOTE[1].sin_addr.s_addr = temp_long_ip;
            
            temp_net_data[0] = ((temp_long_ip)>>24)&0xFF;
            temp_net_data[1] = ((temp_long_ip)>>16)&0xFF;
            temp_net_data[2] = ((temp_long_ip)>>8)&0xFF;
            temp_net_data[3] = (temp_long_ip)&0xFF;
            
            Flash_Write(-(16*(4)),3,(char *)(temp_net_data),4);
            
            write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
	else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='c')&&(data_addr[4]=='l')&&(data_addr[5]=='i')&&(data_addr[6]=='_')&&(data_addr[7]=='p')&&(data_addr[8]=='p')&&(data_addr[9]=='3')&&((data_addr[10]=='?')||(data_addr[10]=='=')))
    {
        if(data_addr[10]=='?')
        {
            write(SCI0, (char *)C1_Cli_Pp3_Buffer, sizeof(C1_Cli_Pp3_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Enet_Device.G_Addr_TCP_CLIENT[2].sin_port);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);        	
        }
        else if(data_addr[10]=='=')
        {
        	Enet_Device.G_Addr_UDP_REMOTE[2].sin_port = Enet_Device.G_Addr_TCP_CLIENT[0].sin_port = atoi((char *)(data_addr+11));
        	temp_net_data[0] = ((Enet_Device.G_Addr_TCP_CLIENT[0].sin_port)>>8)&0xFF;
            temp_net_data[1] = (Enet_Device.G_Addr_TCP_CLIENT[0].sin_port)&0xFF;
			Flash_Write(-16*5+12,3,(char_ptr)temp_net_data,2);
        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
	else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='c')&&(data_addr[4]=='l')&&(data_addr[5]=='i')&&(data_addr[6]=='_')&&(data_addr[7]=='i')&&(data_addr[8]=='p')&&(data_addr[9]=='3')&&((data_addr[10]=='?')||(data_addr[10]=='=')))
    {
        if(data_addr[10]=='?')
        {
            write(SCI0, (char *)C1_Cli_Ip3_Buffer, sizeof(C1_Cli_Ip3_Buffer));
            fflush(SCI0);
            for(i=16;i>=7;i--)
            {
                if(inet_ntop(AF_INET, &Enet_Device.G_Addr_TCP_CLIENT[2].sin_addr.s_addr, (char *)temp_net_data, i)==NULL)
                {
                    inet_ntop(AF_INET, &Enet_Device.G_Addr_TCP_CLIENT[2].sin_addr.s_addr, (char *)temp_net_data, i+1);
                    break;
                }
            }
            
            write(SCI0, (char *)(temp_net_data), i);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if(data_addr[10]=='=')
        {
            temp_long_ip = inet_addr(data_addr+11);
            Enet_Device.G_Addr_TCP_CLIENT[0].sin_addr.s_addr = Enet_Device.G_Addr_UDP_REMOTE[2].sin_addr.s_addr = temp_long_ip;
            
            temp_net_data[0] = ((temp_long_ip)>>24)&0xFF;
            temp_net_data[1] = ((temp_long_ip)>>16)&0xFF;
            temp_net_data[2] = ((temp_long_ip)>>8)&0xFF;
            temp_net_data[3] = (temp_long_ip)&0xFF;
            
            Flash_Write(-(16*(5)),3,(char *)(temp_net_data),4);
            
            write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
	else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='c')&&(data_addr[4]=='l')&&(data_addr[5]=='i')&&(data_addr[6]=='_')&&(data_addr[7]=='p')&&(data_addr[8]=='p')&&(data_addr[9]=='4')&&((data_addr[10]=='?')||(data_addr[10]=='=')))
    {
        if(data_addr[10]=='?')
        {
            write(SCI0, (char *)C1_Cli_Pp4_Buffer, sizeof(C1_Cli_Pp4_Buffer));
            fflush(SCI0);
            
            length = sprintf((char *)temp_net_data, "%d", Enet_Device.G_Addr_TCP_CLIENT[3].sin_port);
            write(SCI0, (char *)(temp_net_data), length);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);        	
        }
        else if(data_addr[10]=='=')
        {
        	Enet_Device.G_Addr_UDP_REMOTE[3].sin_port = Enet_Device.G_Addr_TCP_CLIENT[3].sin_port = atoi((char *)(data_addr+11));
        	temp_net_data[0] = ((Enet_Device.G_Addr_TCP_CLIENT[0].sin_port)>>8)&0xFF;
            temp_net_data[1] = (Enet_Device.G_Addr_TCP_CLIENT[0].sin_port)&0xFF;
			Flash_Write(-16*6+12,3,(char_ptr)temp_net_data,2);
        	write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
	else if((data_addr[0]=='c')&&(data_addr[1]=='1')&&(data_addr[2]=='_')&&(data_addr[3]=='c')&&(data_addr[4]=='l')&&(data_addr[5]=='i')&&(data_addr[6]=='_')&&(data_addr[7]=='i')&&(data_addr[8]=='p')&&(data_addr[9]=='4')&&((data_addr[10]=='?')||(data_addr[10]=='=')))
    {
        if(data_addr[10]=='?')
        {
            write(SCI0, (char *)C1_Cli_Ip4_Buffer, sizeof(C1_Cli_Ip4_Buffer));
            fflush(SCI0);
            for(i=16;i>=7;i--)
            {
                if(inet_ntop(AF_INET, &Enet_Device.G_Addr_TCP_CLIENT[3].sin_addr.s_addr, (char *)temp_net_data, i)==NULL)
                {
                    inet_ntop(AF_INET, &Enet_Device.G_Addr_TCP_CLIENT[3].sin_addr.s_addr, (char *)temp_net_data, i+1);
                    break;
                }
            }
            
            write(SCI0, (char *)(temp_net_data), i);
            fflush(SCI0);
            
            write(SCI0, (char *)OK_Buffer0, sizeof(OK_Buffer0));
            fflush(SCI0);
        }
        else if(data_addr[10]=='=')
        {
            temp_long_ip = inet_addr(data_addr+11);
            Enet_Device.G_Addr_TCP_CLIENT[3].sin_addr.s_addr = Enet_Device.G_Addr_UDP_REMOTE[3].sin_addr.s_addr = temp_long_ip;
            
            temp_net_data[0] = ((temp_long_ip)>>24)&0xFF;
            temp_net_data[1] = ((temp_long_ip)>>16)&0xFF;
            temp_net_data[2] = ((temp_long_ip)>>8)&0xFF;
            temp_net_data[3] = (temp_long_ip)&0xFF;
            
            Flash_Write(-(16*(6)),3,(char *)(temp_net_data),4);
            
            write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
            fflush(SCI0);
        }
        else
        {
            write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
            fflush(SCI0);            
        }
    }
    else
    {
        write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
        fflush(SCI0);
    }
    return 0;
}

uint_8 analyse_at_cmd(char_ptr data_addr, char_ptr num)
{
    uint_8 i;
    if((data_addr[0]=='a')&&(data_addr[1]=='t')&&*num>=2)
    {
        if(Logined == 1)
        {
            if(*num == 2)
            {
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);
            }
            else if((*num > 3)&&(data_addr[2]=='+'))
            {
                find_at(data_addr+3,*num-3);
            }
            else
            {
                write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
                fflush(SCI0);
            }
        }
        else
        {
            if((data_addr[2]=='+')&&(data_addr[3]=='l')&&(data_addr[4]=='o')&&(data_addr[5]=='g')&&(data_addr[6]=='i')&&(data_addr[7]=='n')&&(data_addr[8]=='='))
            {
                if(*num!=Global_Password[0]+9)
                {
                    write(SCI0, (char *)Error2_Buffer, sizeof(Error2_Buffer));
                    fflush(SCI0);
                    return 0;                    
                }
                for (i=0; i<Global_Password[0]; i++)
                {
                    if(Global_Password[1+i] != data_addr[9+i])
                    {
                        write(SCI0, (char *)Error2_Buffer, sizeof(Error2_Buffer));
                        fflush(SCI0);
                        return 0;
                    }
                }
                Logined = 1;
                write(SCI0, (char *)Login_Ok_Buffer, sizeof(Login_Ok_Buffer));
                fflush(SCI0);
            }
            else
            {
                write(SCI0, (char *)Error1_Buffer, sizeof(Error1_Buffer));
                fflush(SCI0);            
            }
        }
    }
    else
    {  
        write(SCI0, (char *)Error_Buffer, sizeof(Error_Buffer));
        fflush(SCI0);
    }
    return 0;
}

void echo_server(MQX_FILE_PTR SCI, char * buffer_addr, uint_32 num)
{
    if(Echo_En)
    {
        write(SCI, buffer_addr, num);
    }
}

void shell_server_task(uint_32 initial_data)
{
    char data_buffer[100];
    char cmd_data[200];
    char cmd_data_at[200];
    uint_32 count;
    static char con = 0 ;
    uint_8 i,con_at;
    static uint_32 time_add;
    echo_server(SCI0, (char *)welcom0, sizeof(welcom0));
    fflush(SCI0);

    while(TRUE)
    {
        count = fread(data_buffer, 1, 100, SCI0);
        if (count == 1)
        {
            time_add=0;
            if((0x20<=data_buffer[0])&&(data_buffer[0]<=0x7E))
            {
                echo_server(SCI0, data_buffer, 1);
                fflush(SCI0);
                if((0x41<=data_buffer[0])&&(data_buffer[0]<=0x5A))
                {
                    data_buffer[0]+=0x20;
                }
                cmd_data[con]=data_buffer[0];
                con ++;
            }
            else if (data_buffer[0] == 0x0D)
            {
                if(con == 0)
                {
                    echo_server(SCI0, data_buffer, 1);
                    fflush(SCI0);                    
                }
                else
                {
                    data_buffer[1] = 0x0A;
                    echo_server(SCI0, data_buffer, 2);
                    fflush(SCI0);
                    for(i=0,con_at=0;i<con;i++)
                    {
                        if(cmd_data[i] != 0x20)
                        {
                            cmd_data_at[con_at]=cmd_data[i];
                            con_at++;
                        }
                    }
                    analyse_at_cmd(cmd_data_at, (char *)&con_at);
                    con = 0;
                }
            }
            else if(data_buffer[0] == 0x08)
            {
                if(con>0)
                {
                    con--;
                    cmd_data[con]=0;
                    data_buffer[1] = 0x20;
                    data_buffer[2] = 0x08;
                    echo_server(SCI0, data_buffer, 3);
                    fflush(SCI0);
                }
            }
        }
        else if(count > 1)
        {
            time_add=0;
            if((data_buffer[0]==0x1B)&&(data_buffer[1]==0x4F))
            {
                
            }
            else if((data_buffer[0]==0x1B)&&(data_buffer[1]==0x5B))
            {
                
            }
            else if((data_buffer[0]==0x08)&&(data_buffer[1]==0x08))
            {
            	if(con>0)
                {
                    con--;
                }
        		data_buffer[1] = 0x20;
            	data_buffer[2] = 0x08;
            	echo_server(SCI0, data_buffer, 3);
           	}
            else
            {
                
                if(data_buffer[count-1]==0x0D)
                {
                    data_buffer[count] = 0x0A;
                    data_buffer[count+1] = 0x0A;                 
                    echo_server(SCI0, data_buffer, count+2);
                    fflush(SCI0);
                    for(i=0;i<count-1;i++)
                    {                    
                        if((0x41<=data_buffer[i])&&(data_buffer[i]<=0x5A))
                        {
                            cmd_data[con] = data_buffer[i]+0x20;
                            con ++;
                        }
                        else
                        {
                            cmd_data[con] = data_buffer[i];
                            con ++;                            
                        }
                    }
                    for(i=0,con_at=0;i<con;i++)
                    {
                        if(cmd_data[i] != 0x20)
                        {
                            cmd_data_at[con_at]=cmd_data[i];
                            con_at++;
                        }
                    }
                    analyse_at_cmd(cmd_data_at, (char *)&con_at);
                    con = 0;
                }
                else if(((data_buffer[count-1]==0x0D)&&(data_buffer[count-2]==0x0A))
                      ||((data_buffer[count-1]==0x0A)&&(data_buffer[count-2]==0x0D)))
                {
                    data_buffer[count] = 0x0A;                 
                    echo_server(SCI0, data_buffer, count+1);
                    fflush(SCI0);
                    for(i=0;i<count-2;i++)
                    {                    
                        if((0x41<=data_buffer[i])&&(data_buffer[i]<=0x5A))
                        {
                            cmd_data[con] = data_buffer[i]+0x20;
                            con ++;
                        }
                        else
                        {
                            cmd_data[con] = data_buffer[i];
                            con ++;                            
                        }
                    }
                    for(i=0,con_at=0;i<con;i++)
                    {
                        if(cmd_data[i] != 0x20)
                        {
                            cmd_data_at[con_at]=cmd_data[i];
                            con_at++;
                        }
                    }
                    analyse_at_cmd(cmd_data_at, (char *)&con_at);
                    con = 0;
                }
                else
                {
                    echo_server(SCI0, data_buffer, count);
                    fflush(SCI0);
                    for(i=0;i<count;i++)
                    {
                        if((0x41<=data_buffer[i])&&(data_buffer[i]<=0x5A))
                        {
                            cmd_data[con] = data_buffer[i]+0x20;
                            con ++;
                        }
                        else
                        {
                            cmd_data[con] = data_buffer[i];
                            con ++;                            
                        }
                    }
                }
            }
        }
        else
        {
            if(Logined)
            {
                if(++time_add>=1200)
                {
                    time_add=0;
                    Logined=0;
                }
            }
        }
        for(i=0;i<200;i++)
        {   
            cmd_data_at[i]=0;
        }
        _time_delay(100);
    }
}
