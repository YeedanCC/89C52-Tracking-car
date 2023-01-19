#include <reg52.h>
#include "Motordirver.h"
#include "Delay.h"
#include "lcd1602.h"
#include "Timer.h"

unsigned int m; 

void CarGo()
{RightMotoForward();LeftMotoForward();m=1; 

		
//	lcd1602_init();
//	lcd1602_write_cmd(0x82); //确定显示位置 
//	lcd1602_write_data(0x41);//确定显示内容 
//	lcd1602_char(0,3,'P'); 

}

void CarBack()
{RightMotoBack();LeftMotoBack();m=0;}
	
void CarRight()
{RightMotoStop();LeftMotoForward();}
	
void CarLeft()
{LeftMotoStop();RightMotoForward();}

void CarStop()
{RightMotoStop();LeftMotoStop();	
lcd1602_init();
	lcd1602_write_cmd(0x82); //确定显示位置 
	lcd1602_write_data(0x41);//确定显示内容 
	lcd1602_char(1,3,'9');
	delay_ms(500);	
		lcd1602_init();
	lcd1602_write_cmd(0x82); //确定显示位置 
	lcd1602_write_data(0x41);//确定显示内容 
	lcd1602_char(1,3,'8');
	delay_ms(500);
		lcd1602_init();
	lcd1602_write_cmd(0x82); //确定显示位置 
	lcd1602_write_data(0x41);//确定显示内容 
	lcd1602_char(1,3,'7');
	delay_ms(500);
		lcd1602_init();
	lcd1602_write_cmd(0x82); //确定显示位置 
	lcd1602_write_data(0x41);//确定显示内容 
	lcd1602_char(1,3,'6');
	delay_ms(500);
		lcd1602_init();
	lcd1602_write_cmd(0x82); //确定显示位置 
	lcd1602_write_data(0x41);//确定显示内容 
	lcd1602_char(1,3,'5');
	delay_ms(500);
		lcd1602_init();
	lcd1602_write_cmd(0x82); //确定显示位置 
	lcd1602_write_data(0x41);//确定显示内容 
	lcd1602_char(1,3,'4');
	delay_ms(500);
		lcd1602_init();
	lcd1602_write_cmd(0x82); //确定显示位置 
	lcd1602_write_data(0x41);//确定显示内容 
	lcd1602_char(1,3,'3');
	delay_ms(500);
		lcd1602_init();
	lcd1602_write_cmd(0x82); //确定显示位置 
	lcd1602_write_data(0x41);//确定显示内容 
	lcd1602_char(1,3,'2');
	delay_ms(500);
		lcd1602_init();
	lcd1602_write_cmd(0x82); //确定显示位置 
	lcd1602_write_data(0x41);//确定显示内容 
	lcd1602_char(1,3,'1');
	delay_ms(500);
		lcd1602_init();
	lcd1602_write_cmd(0x82); //确定显示位置 
	lcd1602_write_data(0x41);//确定显示内容 
	lcd1602_char(1,3,'0');
	delay_ms(500);
//	lcd1602_init();
//	lcd1602_write_cmd(0x82); //确定显示位置 
//	lcd1602_write_data(0x41);//确定显示内容 
//	lcd1602_char(0,3,'Q');
//	delay_ms(5000);
////	 PWML=75;
////	 PWMR=75;
//	CarGo();
//	delay_ms(1000);
//	delay_ms(5000);
//	 PWML=75;
//	 PWMR=75;
	CarGo();
	delay_ms(1000);

} 
