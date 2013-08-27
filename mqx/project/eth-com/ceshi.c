uint_8 abc(char * a, uint_8 b)
{
    uint_8 temp_ip[4];
    uint_8 i, j, temp_data, mark_addr;
    for(i=0;i<b;i++)
    {
        temp_data = *(a+i);
        if(((temp_data<0x30)&&(temp_data!='.'))||(temp_data>0x39))
        {
            return 0;
        }
        if((temp_data>=0x30)&&(temp_data<=0x39))
        {
            *(a+i)-=0x30;
        }
    }
    for(i=0;i<b;i++)
    {
        temp_data = *(a+i);
        if(temp_data=='.')
        {
            if(i==1)
            {
                temp_ip[0]+=(*(a+i-1-j))*
                
            }
        }
    }
}