#include "shell_at.h"

#include "config_parameter.h"

#include <string.h>

const char Error_Buffer[]={"ERROR\n\r"};
const char Error0_Buffer[]={"0_Command Invalid\r\nERROR\r\n"};
const char Error1_Buffer[]={"1_No Login\r\nERROR\r\n"};
const char Error2_Buffer[]={"2_PassWord Error\r\nERROR\r\n"};
const char Error3_Buffer[]={"3_Parameter Format Error\r\nERROR\r\n"};
const char Error4_Buffer[]={"4_Parameter Number Error\r\nERROR\r\n"};
const char Error5_Buffer[]={"5_Para meter Read Only\r\n"};
const char OK_Buffer[]={"OK\n\r"};
const char welcom0[]={"Pelse Input \"at+login='password' \" Login NETCOM Config Tool.\r\n"};

char Logined = 0;

void find_at(char_ptr data_addr, char num)
{
    if(Logined == 1)
    {
        if((data_addr[0]=='a')&&(data_addr[1]=='t')&&(data_addr[2]=='+'))
        {
             
                data_addr[num] = 0x0A;
                write(SCI0, data_addr, num+1);
                fflush(SCI0);
        }
        else
        {
            if((data_addr[0]=='a')&&(data_addr[1]=='t')&&((data_addr[2]==0x0D)||((data_addr[2]==' ')&&(data_addr[3]==0x0d))))
            {
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);
            }
            else
            {
                write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
                fflush(SCI0);            
            }
        }
    }
    else
    {
        if((data_addr[0]=='a')&&(data_addr[1]=='t')&&(data_addr[2]=='+')
         &&(data_addr[3]=='l')&&(data_addr[4]=='o')&&(data_addr[5]=='g')&&(data_addr[6]=='i')&&(data_addr[7]=='n')&&(data_addr[8]=='='))
        {
            if((data_addr[9]=='8')&&(data_addr[10]=='8')&&(data_addr[11]=='8')&&(data_addr[12]=='8')&&(data_addr[13]=='8'))
            {
                Logined = 1;
                write(SCI0, (char *)OK_Buffer, sizeof(OK_Buffer));
                fflush(SCI0);
            }
            else
            {
                write(SCI0, (char *)Error2_Buffer, sizeof(Error2_Buffer));
                fflush(SCI0);                    
            }
        }
        else
        {
            write(SCI0, (char *)Error1_Buffer, sizeof(Error1_Buffer));
            fflush(SCI0);            
        }
    }
}

void analyse_at_cmd(char_ptr data_addr, char_ptr num)
{
    uint_8 i;
    for(i=0;i<*num;i++)
    {
        if(data_addr[i]!=' ')
        {
            if((data_addr[i]=='a')&&(data_addr[i+1]=='t'))
            {
                find_at(&data_addr[i],*num - i);
            }
            else
            {    
                write(SCI0, (char *)Error0_Buffer, sizeof(Error0_Buffer));
                fflush(SCI0);
            }
            break;
        }
    }
}

void shell_server_task(uint_32 initial_data)
{
    char data_buffer[10];
    char cmd_data[50];
    uint_32 count;
    static char con = 0 ;
    
    write(SCI0, (char *)welcom0, sizeof(welcom0));
    fflush(SCI0);

    while(TRUE)
    {
        count = fread(data_buffer, 1, 10, SCI0);
        if (count == 1)
        {
            if((0x20<=data_buffer[0])&&(data_buffer[0]<=0x7E))
            {
                write(SCI0, data_buffer, 1);
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
                    data_buffer[1] = 0x0A;
                    write(SCI0, data_buffer, 2);
                    fflush(SCI0);                    
                }
                else
                {
                    cmd_data[con]=data_buffer[0];
                    con ++; 
                    data_buffer[1] = 0x0A;
                    data_buffer[2] = 0x0A;
                    write(SCI0, data_buffer, 3);
                    fflush(SCI0);
                    analyse_at_cmd(cmd_data, &con);
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
                    write(SCI0, data_buffer, 3);
                    fflush(SCI0);
                }
            }
        }
        else if(count > 1)
        {
            if((data_buffer[0]==0x1B)&&((data_buffer[0]==0x5B)||(data_buffer[0]==0x4F)))
            {
                
            }
            else
            {
                
            }
        }
        _time_delay(10);
    }
}
