#include <reg52.h>
#include "mpu6050_module.h"
#include "IIC.h"
#include "Kalman.h"
#include "UART.h"
 

/*
//float xdata Angle_x;
//float xdata Angle_y;
//float xdata Angle_z;
float xdata Angle_ax;
float xdata Angle_ay;
float xdata Angle_az;
float xdata Angle_outx = 0;
float xdata Angle_outy = 0;
float xdata Angle_outz = 0;
float xdata Angle_gx;
float xdata Angle_gy;
float xdata Angle_gz;
float xdata Qgx = 0;
float xdata Qgy = 0;
float xdata Qgz = 0;
float xdata Qax = 0;
float xdata Qay = 0;
float xdata Qaz = 0;
*/



void Init_mpu6050()
{
	Single_WriteI2C(PWR_MGMT_1, 0x00);	//�������״̬
	Single_WriteI2C(SMPLRT_DIV, 0x07);
	Single_WriteI2C(CONFIG, 0x06);
	Single_WriteI2C(GYRO_CONFIG, 0x18);
	Single_WriteI2C(ACCEL_CONFIG, 0x01);	
}

float Get_Data(unsigned char REG_Address)  //����IIC��ַ��������ݣ����ٶȣ����ٶȣ�
{
	unsigned int H;
	unsigned char L;
	H = Single_ReadI2C(REG_Address);
	L = Single_ReadI2C(REG_Address+1);
	return (H<<8)+L;
}

float Accel_To_Angle(unsigned char REG_Address,float Q)   //����IIC��ַ���������������ĽǶ�ֵ
{
	float Angle,Accel;
	Accel = Get_Data(REG_Address);
	Angle = (Accel - Q) /16384;   //����Ƕȣ����ȣ�
	Angle = Angle*1.54*180/3.14;  //����ɽǶ�
	if(Angle > 100)
	{
		Angle -= 360;
	}
	return Angle;
}

float Gyro_To_Angle(unsigned char REG_Address,float Q)
{
	float Gyro;
	Gyro = Get_Data(REG_Address);	     
	Gyro = -(Gyro-Q)/16.4*0.01;         //ȥ�����ƫ�ƣ����ּ�����ٶ�ֵ,����Ϊ������
	//Angle_g = Angle_a + Gyro*0.01 - Q;
	return Gyro;
}

/*
void Angle_Calcu(float Angles[]) //�������飬���Angles[0]��Angles[1]��Angles[2]��ӦAx,Ay,Az	 
{
	Angle_ax = Accel_To_Angle(ACCEL_XOUT_H,Qax);	 //����ת��Ϊ�Ƕȣ�1.2Ϊ�ʵ��Ŵ�
	Angle_ay = Accel_To_Angle(ACCEL_YOUT_H,Qay);
	Angle_az = Accel_To_Angle(ACCEL_ZOUT_H,Qaz);
	Angle_gx = Gyro_To_Angle(GYRO_XOUT_H,Qgx);
	Angle_gy = Gyro_To_Angle(GYRO_YOUT_H,Qgy);
	Angle_gz = Gyro_To_Angle(GYRO_ZOUT_H,Qgz);
	Kalman_Filter(Angle_ax,Angle_gy,&Angle_outx);
	Kalman_Filter(Angle_ay,Angle_gz,&Angle_outy);
	Kalman_Filter(Angle_az,Angle_gx,&Angle_outz);
	Angles[0] = Angle_outx;
	Angles[1] = Angle_outy;
	Angles[2] = Angle_outz;
} */



