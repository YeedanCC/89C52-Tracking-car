#ifndef __MoveState_H_
#define __MoveState_H_
extern	 int m;
void CarGo();  //С��ֱ��

void CarBack();  //С������

void CarRight();  //С����ת

void CarLeft();  //С����ת

void CarStop();
	
void lcd1602_init();
void lcd1602_write_cmd(del);
void lcd1602_write_data(unsigned char del);
void delay1ms();
void ddelay(unsigned char n);

void lcd1602_char(unsigned char hang,unsigned char lie,char dat);
void delay_ms(unsigned int n);
#endif

//�˺���Ϊ����С���˶�״̬�ĺ���