#include <reg52.h>
#include "uart.h"

#define uint unsigned int
#define uchar unsigned char
typedef unsigned int u16;   //���������ͽ�����������
typedef unsigned char u8;

//���ڳ�ʼ������  9600
void UartInit(void)  //9600bps@12.000MHz
{
 PCON &= 0x7F;  //�����ʲ�����
 SCON = 0x50;  //8λ����,�ɱ䲨����
 AUXR &= 0xBF;  //��ʱ��1ʱ��ΪFosc/12,��12T
 AUXR &= 0xFE;  //����1ѡ��ʱ��1Ϊ�����ʷ�����
 TMOD &= 0x0F;  //�����ʱ��1ģʽλ
 TMOD |= 0x20;  //�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
 TL1 = 0xFD;  //�趨��ʱ��ֵ
 TH1 = 0xFD;  //�趨��ʱ����װֵ
 ET1 = 0;  //��ֹ��ʱ��1�ж�
 TR1 = 1;  //������ʱ��1
 EA=1;
 ES=0;
}

//����һ���ַ�
void Uart_Send_Byte(unsigned char dat)
{
  SBUF = dat;
 while(!TI);
 TI=0;
} 


u8 ch;

//���ڽ����ж�
void Uart_IRQ() interrupt 4
{
 if(RI)
 {  
   RI=0;//���־λ 
   ch=SBUF;
   if(ch=='w') 
   {/*����ǰ���ĺ���*/}
   if(ch=='s')
   {/*���ú��˵ĺ���*/}
   if (ch=='a')
   {/*������ת�ĺ���*/}
   if(ch=='d')
   {/*������ת�ĺ���*/}
   if(ch=='c')
   {/*������ת�ĺ���*/}
 } 
