#include "com_push.h"
#include "config_parameter.h"
//
//#define TXDDATAMAX 1000
//#define RXDDATAMAX 1000
//
//uint_8 COM_BUFFER_RX[RXDDATAMAX];
//uint_32 COM_RXDCON = 0;
//uint_8 COM_NOEMPTY_MARK = 0;
//
//static uint_8 COM_BUFFER_TX[TXDDATAMAX];
//static uint_32 TxdConL = 0, TxdConH = 0;
//
//void write_com_buffer(uint_32 initial_data, uint_8 * datain, uint_32 num)
//{
//    uint_32 i;
//    for(i=0;i<num;i++)
//    {
//        COM_BUFFER_TX[TxdConH + i] = *(datain + i);
//    }
//    TxdConH += num;
//}

void com_buffer_push(uint_32 initial_data)
{
	while(TRUE)
    {
        _task_block();
    }
}