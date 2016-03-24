#ifndef  __MPU6050_MODULE_H__
#define  __MPU6050_MODULE_H__


//mpu6050�ڲ���ַ
#define	SMPLRT_DIV		0x19	//�����ǲ����ʣ�����ֵ��0x07(125Hz)
#define	CONFIG			0x1A	//��ͨ�˲�Ƶ�ʣ�����ֵ��0x06(5Hz)
#define	GYRO_CONFIG		0x1B	//�������Լ켰������Χ������ֵ��0x18(���Լ죬2000deg/s)
#define	ACCEL_CONFIG	0x1C	//���ټ��Լ졢������Χ����ͨ�˲�Ƶ�ʣ�����ֵ��0x01(���Լ죬2G��5Hz)
#define	ACCEL_XOUT_H	0x3B	//���ٶȵ�ַ
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41	
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43	//���ٶȵ�ַ
#define	GYRO_XOUT_L		0x44
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B	//��Դ��������ֵ��0x00(��������)
#define	WHO_AM_I		0x75	//IIC��ַ�Ĵ���(Ĭ����ֵ0x68��ֻ��)
#define	SlaveAddress	0xD0	//IICд��ʱ�ĵ�ַ�ֽ����ݣ�+1Ϊ��ȡ

/////////Variable-definition//////////





///////////Bit-definition/////////////

/////////Function-definition//////////
void Init_mpu6050();					   //��ʼ��mpu6050
float Get_Data(unsigned char REG_Address); //����mpu6050�ڲ���ַ��ȡ������ٶȣ�Accel���ͼ��ٶȣ�Gyro��
float Accel_To_Angle(unsigned char REG_Address,float Q);	   //������ٶȺ����������Ƕȣ����˲�
float Gyro_To_Angle(unsigned char REG_Address,float Q);
void Angle_Calcu(float Angles[]);

#endif