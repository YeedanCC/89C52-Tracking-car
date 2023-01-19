#ifndef  __UART_H__
#define  __UART_H__

extern unsigned char RX_DAT[10],RX_OVER;
extern unsigned char i;
//º¯Êý
void URATinit();
void Uart_Send_Byte(unsigned char dat);
void Uart_IRQ();
#endif
