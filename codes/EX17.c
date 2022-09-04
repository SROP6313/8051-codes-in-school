#include <REG51.H>

unsigned char minute=0,second=0,ms=0;

void delay_2ms()
{
	unsigned char i,j;
	for(i=0;i<5;i++)
	   for(j=0;j<135;j++);
}

void T0_int(void) interrupt 1
{
	TL0=(65536-10000)%256;
	TH0=(65536-10000)/256;
	if(++ms>99)
	{
		if(++second>59)
		{	
			if(++minute>59) minute=0;
			second=0;										
		}
              ms=0;		
	}
}
void main(void)
{
	unsigned char i,position,val[6];
	TMOD=0x01;
	TL0=(65536-10000)%256;
	TH0=(65536-10000)/256;
	TR0=1;
	ET0=1;
	EA=1;
	P2=0xF3;
	position=1;
	
	while(1)
	{
		val[0]=0xF0|(minute/10);
		val[1]=0xB0|(minute%10);
		val[2]=0xF0|(second/10);
		val[3]=0xB0|(second%10);
		val[4]=0xF0|(ms/10);
		val[5]=0xF0|(ms%10);
		for(i=0;i<6;i++)
		{
			P1=0xFF;
			P0=~(position<<i);
			P1=val[i];
			delay_2ms();
		}
	}
}
