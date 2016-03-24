#include <stdio.h>
#include "UART.h"
#include "Kalman.h"

unsigned char xdata log[10];

float xdata ts = 0.015;         //�˲�������Ƶ��(ms)
float xdata q_acc = 0.01;       //���ٶȼ�Э����->���γ̶�
float xdata q_gyro = 0.005;      //������Э����->���γ̶�
int uk = 0;          //U(k)Ϊ����״̬�Ŀ����������û�п�������������Ϊ0��
int zk;          //Z(k)Ϊkʱ�̵Ĳ���ֵ����new_angle
float xdata r_acc = 0.056;       //��������Э�������
float temp;

float idata a[2][2]; //��Ϊֻ��һ��������������aȡa[0][0],bȡb[0]
float xdata b[2];
float xdata q[2][2];
float xdata h[2] = {0,1};
float xdata k[2] = {0,0};     //���������� 
float xdata p[2][2] = {{0,0},{0,0}};

float KalmanTest(float new_angle,float new_gyro,float Angle)
{
	//��ʼ��
	a[0][0] = 1; //��Ϊֻ��һ��������������aȡa[0][0],bȡb[0]
	b[0] = ts;
	p[0][0] = q_acc;
	p[0][1] = 0;
	p[1][0] = 0;
	p[1][1] = q_gyro;

	//�������
	Angle = Angle + ts * new_gyro;

	//������Ƶ�Э����
	p[0][0] -= ts * (p[1][0] + p[0][1]); 
	p[0][1] -= ts * p[1][1];
	p[1][0] -= ts * p[1][1];
	p[1][1] = p[1][1];

	//����������
	temp = p[0][0] + r_acc;
	k[0] = p[0][0] / temp;
	k[1] = p[1][0] / temp;

	//kʱ�̵�����ֵ
	Angle += k[0] * (new_angle - Angle);
	//Gyro = Gyro + k[1] * (new_angle - Angle);

	//����k״̬�µ�Э����
	p[0][0] -= k[0] * p[0][0];
	p[0][1] -= k[0] * p[0][1];
	p[1][0] -= k[1] * p[0][0];
	p[1][1] -= k[1] * p[0][1];
	return Angle;
} 

/*
float code Q_angle=0.01;//0.001;  
float code Q_gyro=0.005;
float code R_angle=0.056;//0.5;
float code ts=0.02;	                  //dtΪkalman�˲�������ʱ��;
char  code C_0 = 1;
float xdata Q_bias=0;
float xdata Angle_err;
float xdata PCt_0, PCt_1, E;
float xdata K_0, K_1, t_0, t_1;
float xdata Pdot[4] ={0,0,0,0};
float xdata PP[2][2] = { { 1, 0 },{ 0, 1 } };
//*********************************************************
// �������˲�
//*********************************************************
//Q:����������Q���󣬶�̬��Ӧ��죬�����ȶ��Ա仵
//R:����������R���󣬶�̬��Ӧ�����������ȶ��Ա��
void Kalman_Filter(float Angle_a,float Gyro,float *Angle_out)		
{	
	
	*Angle_out+=(Gyro - Q_bias) * ts; //�������

	sprintf(log,"a1=%.2f\n",*Angle_out);
	Send_Str(log);

	Pdot[0]=Q_angle - PP[0][1] - PP[1][0]; // Pk-����������Э�����΢��
	Pdot[1]=- PP[1][1];
	Pdot[2]=- PP[1][1];
	Pdot[3]=Q_gyro;
	PP[0][0] += Pdot[0] * ts;   // Pk-����������Э����΢�ֵĻ���
	PP[0][1] += Pdot[1] * ts;   // =����������Э����
	PP[1][0] += Pdot[2] * ts;
	PP[1][1] += Pdot[3] * ts;

	sprintf(log,"p%.4f,%.4f,%.4f,%.4f\n",PP[0][0],PP[0][1],PP[1][0],PP[1][1]);
	Send_Str(log);

	Angle_err = Angle_a - *Angle_out;	//zk-�������
	PCt_0 = C_0 * PP[0][0];
	PCt_1 = C_0 * PP[1][0];
	E = R_angle + C_0 * PCt_0;
	K_0 = PCt_0 / E;
	K_1 = PCt_1 / E;
	
	sprintf(log,"%.2f,%.2f\n",K_0,K_1);
	Send_Str(log);
		
	t_0 = PCt_0;
	t_1 = C_0 * PP[0][1];
	PP[0][0] -= K_0 * t_0;		 //����������Э����
	PP[0][1] -= K_0 * t_1;
	PP[1][0] -= K_1 * t_0;
	PP[1][1] -= K_1 * t_1;		
	*Angle_out += K_0 * Angle_err;	 //�������

	sprintf(log,"%.2f\n",*Angle_out);
	Send_Str(log);

	Q_bias += K_1 * Angle_err;	 //�������
	//Gyro_y   = Gyro - Q_bias;	 //���ֵ(�������)��΢��=���ٶ�
}
*/
