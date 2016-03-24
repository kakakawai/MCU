# include <stdio.h>

struct _pid{
    float SetSpeed;            //�趨ֵ
    float ActualSpeed;        //ʵ��ֵ
    float err;                //���
    float err_last;            //��һ�����
    float Kp,Ki,Kd;            
    float voltage;            //���ֵ
    float integral;            //����ֵ
}pid;

/*
	�Ӻ�Сkd��kp������
	ki�Ӵ����Ͽ�ظ�
	��kd����������ʧ
*/


void PID_init(){
    printf("PID begin \n");
    pid.SetSpeed=0.0;
    pid.ActualSpeed=0.0;
    pid.err=0.0;
    pid.err_last=0.0;
    pid.voltage=0.0;
    pid.integral=0.0;
    pid.Kp=1.1;//0.54;
    pid.Ki=0.855;//0.878;//0.469;
    pid.Kd=0.0001;//0.00001;
    printf("PID end \n");
}


void PID(void){
    //pid.SetSpeed=speed;
    pid.err=pid.SetSpeed-pid.ActualSpeed;
    pid.integral+=pid.err;

    pid.voltage=pid.Kp*pid.err+pid.Ki*pid.integral+pid.Kd*(pid.err-pid.err_last);

    pid.err_last=pid.err;
    pid.ActualSpeed += pid.voltage*1.0;
//    return pid.ActualSpeed;
}

int main(void)
{
	int count=0;
    printf("System begin \n");
    PID_init();
	printf("�����趨ֵ��");
	scanf("%f",&pid.SetSpeed);
	printf("�趨ֵΪ��%f\n",pid.SetSpeed);
    while(count<18)
    {
        PID();
        printf("%f\n",pid.ActualSpeed);
        count++;
    }
return 0;
}