#include <reg52.h>

sbit IN1 = P1^7;
sbit IN2 = P1^6;
sbit IN3 = P1^5;
sbit IN4 = P1^4;


void RightMotoForward()
{IN3=0; IN4=1;}
void RightMotoBack()
{IN3=1; IN4=0;}
void LeftMotoBack()
{IN1=0; IN2=1;}
void LeftMotoForward()
{IN1=1; IN2=0;}
void RightMotoStop()
{IN3=1; IN4=1;}
void LeftMotoStop()
{IN1=1; IN2=1;}
