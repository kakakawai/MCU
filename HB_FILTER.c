#include "HB_Filter.h"



float dt=0.01; 						//��������
float tau = 0.1;					//ʱ�䳣�������Լ�ȷ���ģ�
#define a (tau/(tau+dt))	//�˲���ϵ��

float HB_Filter(float gyro, float acc, float angle)
{
	angle = a*(angle+gyro*dt) + (1-a)*acc;
	return angle;
}


