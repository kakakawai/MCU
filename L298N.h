//////Variable-definition//////

///////Bit-definition//////////
sbit MotorOneLeft = P2^0;	   
sbit MotorOneRight = P2^1;
sbit MotorTwoLeft = P2^2;
sbit MotorTwoRight = P2^3;

//////Function-definition//////
void Go();			  //ǰ��
void Back();		  //����
void Turn_Left();	  //��ת
void Turn_Right();	  //��ת
void Stop();		  //ֹͣ
void SStop();		  //��ͣ