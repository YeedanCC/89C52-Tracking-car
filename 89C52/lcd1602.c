#include<reg51.h>
#include<intrins.h >
#include<lcd1602.h >
#define LCD_PORT P0
//#define uchar unsigned char
//#define uint unsigned int
sbit RS=P1^0;
sbit RW=P1^1;
sbit E=P1^2;

////	lcd1602_init();
//	lcd1602_write_cmd(); //ȷ����ʾλ�� 
//	lcd1602_write_data();//ȷ����ʾ���� 
//	lcd1602_char(); 

void delay1ms()
{
	unsigned char i,j;
	for(i=0;i<10;i++)
	 for(j=0;j<33;j++)
	 ;
 } 
void ddelay(unsigned char n)
{
	unsigned char i;
	for(i=0;i<n;i++)
	delay1ms();
}


void lcd1602_write_cmd(del)
{
	LCD_PORT = del;
	RS=0;
	RW=0;
	E=0;
	ddelay(2);
//	P0=dictate;
	E=1;
	ddelay(2);
	
}
//void lcd1602_write_data(viod)
//{
	
//}
void lcd1602_write_data(unsigned char del)//д����? ���룺RS=H��RW=L��
{
	LCD_PORT = del; //D0~D7=���ݣ�E=������
	RS = 1;
	RW = 0;  //�������
	E = 0;
	ddelay(2);
	E = 1;
	ddelay(2);
} 

//unsigned char busytest(void)
//{
//	bit result;
//	RS=0;
//	RW=1;
//	E=1;
//	_nop_();
//	_nop_();
//	_nop_();
//	_nop_();
//	E=0; 
//}

void lcd1602_char(unsigned char hang,unsigned char lie,char dat)
{
	unsigned char a;
	if(hang == 0) a = 0x80;
	if(hang == 1) a = 0xc0;
	a = a + lie;
	lcd1602_write_cmd(a);//����дָ���
	lcd1602_write_data(dat);//����д���ݺ���* 
}  //���� : �У��У���Ҫ����1602������

void lcd1602_init(void)
{
	ddelay(15);
	lcd1602_write_cmd(0x38);
	ddelay(5);
	lcd1602_write_cmd(0x38);
	lcd1602_write_cmd(0x08);
	lcd1602_write_cmd(0x01);
	lcd1602_write_cmd(0x06);
	lcd1602_write_cmd(0x0c);
} 

// int xianshi(void)
//{
//	while(1){	
//	lcd1602_init();
//	lcd1602_write_cmd(0x82); //ȷ����ʾλ�� 
//	lcd1602_write_data(0x41);//ȷ����ʾ���� 
//	lcd1602_char(0,3,'b'); }
//
//}

