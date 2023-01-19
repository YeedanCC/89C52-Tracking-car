#ifndef __lcd1602_H_
#define __lcd1602_H_

//int xianshi();
void lcd1602_init();
void lcd1602_write_cmd(del);
void lcd1602_write_data(unsigned char del);
void delay1ms();
void ddelay(unsigned char n);
void lcd1602_char(unsigned char hang,unsigned char lie,char dat);

#endif


