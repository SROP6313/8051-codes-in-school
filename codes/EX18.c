#include <REG51.H>

unsigned char timer=0;
long counter=999999;

void delay_2ms()
{
	unsigned char i,j;
	for(i=0;i<5;i++)
	   for(j=0;j<135;j++);
}

void T0_int(void) interrupt 3
{
	TL1=(65536-50000)%256;
	TH1=(65536-50000)/256;
	if(++timer>1)
	{
		if(--counter<0) counter=999999;
		timer=0;	
	}
}
void main(void)
{
	unsigned char i,position,val[6];
	long tmp;
	
	TMOD=0x01;
	TL0=(65536-50000)%256;
	TH0=(65536-50000)/256;
	TR1=1;
	ET1=1;
	EA=1;
	position=1;
	P2=0xF3;
	
	while(1)
	{
		val[0]=counter/100000;
		tmp=counter%100000;
		val[1]=tmp/10000;
		tmp=tmp%10000;
		val[2]=tmp/1000;
		tmp=tmp%1000;
		val[3]=tmp/100;
		tmp=tmp%100;
		val[4]=tmp/10;
		val[5]=tmp%10;
		for(i=0;i<6;i++)
		{
			P1=0xFF;
			P0=~(position<<i);
			P1=0xF0|val[i];
			delay_2ms();
		}
	}
}
