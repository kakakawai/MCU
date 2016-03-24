#include <reg52.h>
#include <intrins.h>
#include "IIC.h"
#include "MPU6050_module.h"



void I2C_Start()
{
	SDA = 1;
	SCL = 1;
	Delay5us();
	SDA = 0;
	Delay5us();
	SCL = 0;
}

void I2C_Stop()
{
	SDA = 0;
	SCL = 1;
	Delay5us();
	SDA = 1;
	Delay5us();
}

void Delay5us()
{
	_nop_();
	_nop_();
}

void I2C_SendACK(bit ack)
{
	SDA = ack;
	SCL = 1;
	Delay5us();
	SCL = 0;
	Delay5us();	
}

bit I2C_RecvACK()
{
	SCL = 1;
	Delay5us();
	CY = SDA;
	SCL = 0;
	Delay5us();
	return CY;
}

void I2C_SendByte(unsigned char dat)
{
	unsigned char i;
	for(i=0; i<8; i++)
	{
 		dat <<= 1;
		SDA = CY;
		SCL = 1;
		Delay5us();
		SCL = 0;
		Delay5us();
	}
	I2C_RecvACK();
}
unsigned char I2C_RecvByte()
{
	unsigned char i;
	unsigned char dat = 0;
	SDA = 1;
	for(i=0; i<8; i++)
	{
		dat <<= 1;
		SCL = 1;
		Delay5us();
		dat |= SDA;
		SCL = 0;
		Delay5us();
	}
	return dat;
}

void Single_WriteI2C(unsigned char REG_Address,unsigned char REG_data)
{
    I2C_Start();                  //��ʼ�ź�
    I2C_SendByte(SlaveAddress);   //�����豸��ַ+д�ź�
    I2C_SendByte(REG_Address);    //�ڲ��Ĵ�����ַ��
    I2C_SendByte(REG_data);       //�ڲ��Ĵ������ݣ�
    I2C_Stop();                   //����ֹͣ�ź�
}

unsigned char Single_ReadI2C(unsigned char REG_Address)
{
	unsigned char REG_data;
	I2C_Start();                   //��ʼ�ź�
	I2C_SendByte(SlaveAddress);    //�����豸��ַ+д�ź�
	I2C_SendByte(REG_Address);     //���ʹ洢��Ԫ��ַ����0��ʼ
	I2C_Start();                   //��ʼ�ź�
	I2C_SendByte(SlaveAddress+1);  //�����豸��ַ+���ź�
	REG_data=I2C_RecvByte();       //�����Ĵ�������
	I2C_SendACK(1);                //����Ӧ���ź�
	I2C_Stop();                    //ֹͣ�ź�
	return REG_data;
}