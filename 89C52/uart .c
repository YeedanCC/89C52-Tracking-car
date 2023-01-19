#include <reg52.h>
#include "uart.h"

#define uint unsigned int
#define uchar unsigned char
typedef unsigned int u16;   //对数据类型进行声明定义
typedef unsigned char u8;

//串口初始化函数  9600
void UartInit(void)  //9600bps@12.000MHz
{
 PCON &= 0x7F;  //波特率不倍速
 SCON = 0x50;  //8位数据,可变波特率
 AUXR &= 0xBF;  //定时器1时钟为Fosc/12,即12T
 AUXR &= 0xFE;  //串口1选择定时器1为波特率发生器
 TMOD &= 0x0F;  //清除定时器1模式位
 TMOD |= 0x20;  //设定定时器1为8位自动重装方式
 TL1 = 0xFD;  //设定定时初值
 TH1 = 0xFD;  //设定定时器重装值
 ET1 = 0;  //禁止定时器1中断
 TR1 = 1;  //启动定时器1
 EA=1;
 ES=0;
}

//发送一个字符
void Uart_Send_Byte(unsigned char dat)
{
  SBUF = dat;
 while(!TI);
 TI=0;
} 


u8 ch;

//串口接收中断
void Uart_IRQ() interrupt 4
{
 if(RI)
 {  
   RI=0;//清标志位 
   ch=SBUF;
   if(ch=='w') 
   {/*调用前进的函数*/}
   if(ch=='s')
   {/*调用后退的函数*/}
   if (ch=='a')
   {/*调用左转的函数*/}
   if(ch=='d')
   {/*调用右转的函数*/}
   if(ch=='c')
   {/*调用右转的函数*/}
 } 
