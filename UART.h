#ifndef __UART_H__
#define __UART_H__

#define XTAL 11059200
#define baudrate 9600

void Init_UART();						   //������9600
void Send_Byte(unsigned char dat);		   //���ڷ���һ�ֽ�
void Send_Str(unsigned char *str);
unsigned char Recv_Byte();
//void Recv_Str(unsigned char *StrArray);  //��δ��ɡ����ڽ������λ���ַ���
#endif