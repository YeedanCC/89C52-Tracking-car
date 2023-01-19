#include <reg52.h>
#include "lcd1602.h "
#include "MoveState.h"
#include "Motordirver.h"
#include "Timer.h"
#include "Delay.h"
#include "Infraredtrack.h"
#include "uart.h"
#include "string.h" 
unsigned char ch;                      //strlen������ͷ�ļ�
//#define uint unsigned int 
//#define uint8 unsigned char
// 
//sbit lcden=P2^4;
//sbit lcdrs=P2^5;
//sbit dula=P2^6;
//sbit wela=P2^7;
//
//uint8 code table[]="Hello everyone!"; 
//uint8 code table1[]="Welcome to my blog!";
//uint8 num;
//void xianshi();
//void delay(uint z);
//void write_com(uint8 com);
//void write_data(uint8 date);
//void init();
//void Write1602_Str(uint addr,uint length,uint *pbuf);
//unsigned int m=0; 
 void UartInit();
void Uart_Send_Byte(unsigned char dat);
void  main()
{
	  UartInit();
	Timer0_Init();
	EA=1;
	PWMR=30;
	PWML=30;
		while(1)
		{
		Track();
			if((PWML==0)&&(PWMR==0)&&(m==1))
	   {Uart_Send_Byte('Q'); }
	    if((PWML>PWMR)&&(m==1))
       {Uart_Send_Byte('A'); }
		 if((PWML<PWMR)&&(m==1))
       {Uart_Send_Byte('D'); }
	    if((PWML>0)&&(PWMR>0)&&(m==0) )
	    {Uart_Send_Byte('S');}
	   if((PWML>0)&&(PWMR>0)&&(m==1))
	    {Uart_Send_Byte('P');}	
		}

//������
	
	
	}
	void UartInit(void)		//9600bps@12.000MHz
{
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����			
	TMOD = 0x21;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xFD;		//�趨��ʱ��ֵ
	TH1 = 0xFD;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
	EA=1;
	ES=1;
	REN=1;
}



//���ڽ����ж�
void Uart_IRQ() interrupt 4
{
 if(RI==1)
{  
   RI=0;//���־λ 
   
   ch=SBUF;
   if(ch=='w')
   { PWML=70;
     PWMR=70;
	 	lcd1602_init();
	lcd1602_write_cmd(0x82); //ȷ����ʾλ�� 
	lcd1602_write_data(0x41);//ȷ����ʾ���� 
	lcd1602_char(0,3,'P'); 
    CarGo();}
	
   if(ch=='s')
   { PWML=70;
     PWMR=70;
	 	lcd1602_init();
	lcd1602_write_cmd(0x82); //ȷ����ʾλ�� 
	lcd1602_write_data(0x41);//ȷ����ʾ���� 
	lcd1602_char(0,3,'S');  
    CarBack();}

   if(ch=='a')
   { PWML=70;
     PWMR=0;
	 	lcd1602_init();
	lcd1602_write_cmd(0x82); //ȷ����ʾλ�� 
	lcd1602_write_data(0x41);//ȷ����ʾ���� 
	lcd1602_char(0,3,'A'); 
	 CarGo();}
    if(ch=='d')	  
   {PWML=0;
     PWMR=70;
	 	lcd1602_init();
	lcd1602_write_cmd(0x82); //ȷ����ʾλ�� 
	lcd1602_write_data(0x41);//ȷ����ʾ���� 
	lcd1602_char(0,3,'D'); 
	 CarGo();}
   if(ch=='c')	  
   { PWML=0;
     PWMR=0;
	 	lcd1602_init();
	lcd1602_write_cmd(0x82); //ȷ����ʾλ�� 
	lcd1602_write_data(0x41);//ȷ����ʾ���� 
	lcd1602_char(0,3,'Q'); 
   CarGo();}	 	   
 }
 } 
  void Uart_Send_Byte(unsigned char dat)
{	
 	SBUF = dat;
	while(!TI);
	TI=0;
} 
