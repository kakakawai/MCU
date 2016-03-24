#ifndef __IIC_H__
#define __IIC_H__

#include "main.h"

sbit    SCL=P1^1;			//IICʱ�����Ŷ���
sbit    SDA=P1^0;			//IIC�������Ŷ���

void Delay5us();
void I2C_Start();						   
void I2C_Stop();
void I2C_SendACK(bit ack);				   
bit I2C_RecvACK();
void I2C_SendByte(unsigned char dat);		//IIC����1�ֽ�
unsigned char I2C_RecvByte();				//IIC����1�ֽ�
void Single_WriteI2C(unsigned char REG_Address,unsigned char REG_data);	 //ͨ��IIC���ڲ���ַд��
unsigned char Single_ReadI2C(unsigned char REG_Address);

#endif