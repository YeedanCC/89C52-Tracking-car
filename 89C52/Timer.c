#include <reg52.h>

sbit ENR=P2^0;
sbit ENL=P2^1;

unsigned int PWMR=0,PWML=0,t=0; 
			

void Timer0_Init()		//100΢�
{
			

	TMOD=0X21;

	TH0=(65536-100)/256;	//F=f/12=11.0592M/12=0.9216MHZ   T=1/F=1.085us 
	TL0=(65536-100)%256;	
	ET0=1;
	TR0=1;
	EA=1;
}




void Timer0_Routinue() interrupt 1
{
	
	TH0=(65536-100)/256; 
	TL0=(65536-100)%256;
			t++;
			if(t<PWML)
				{
					ENL=1;
				}
			else
				{
					ENL=0;
				}
			if(t<PWMR)
				{
					ENR=1;
				}
			else
				{
					ENR=0;
				}
			
			if(t>=100)
				{
					t=0;
				}
}
