//MAIN
//
//#include <reg52.h>	
//#include "1602.h"
//
//unsigned char PuZh[]="I LOVE YOU 23154254778963";
//
//void main(void)
//{
//	unsigned char i;
//	Init_LCD();
//	for(i=0;i<24;i++)
//	{
//		LCD_write_data(PuZh[i]);
//		LCD_Delay1ms(250);
//	}
//	while(1)
//	{
//	}				
//}

#include "1602.h"
#include <reg52.h>

void LCD_write_com(unsigned char com)
{	
	LCDEn = 0;
	LCDRs = 0;
	LCDRw = 0;
	
	P0 = com;
	LCD_Delay1ms(5);
	LCDEn = 1;
	LCD_Delay1ms(5);
	LCDEn = 0;	
}

void LCD_write_data(unsigned char dat)
{
	LCDEn = 0;
	LCDRs = 1;
	LCDRw = 0;

	P0 = dat;
	LCD_Delay1ms(5);
	LCDEn = 1;
	LCD_Delay1ms(5);
	LCDEn = 0;
}

void Init_LCD()
{
	LCD_write_com(0x38);  //����ʾ
	LCD_write_com(0x0c);  //����ʾ����ʾ���
	LCD_write_com(0x06);  //дһ��ָ���1
	LCD_write_com(0x01);  //����
	LCD_write_com(0x80);  //��������ָ�����
}

void LCD_Delay1ms(unsigned int time)   //��� 0us
{
    unsigned char a,b;
	for (; time>0; time--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}
    	
}