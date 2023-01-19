#ifndef __MoveState_H_
#define __MoveState_H_
extern	 int m;
void CarGo();  //小车直行

void CarBack();  //小车后退

void CarRight();  //小车右转

void CarLeft();  //小车左转

void CarStop();
	
void lcd1602_init();
void lcd1602_write_cmd(del);
void lcd1602_write_data(unsigned char del);
void delay1ms();
void ddelay(unsigned char n);

void lcd1602_char(unsigned char hang,unsigned char lie,char dat);
void delay_ms(unsigned int n);
#endif

//此函数为控制小车运动状态的函数