#include <REG51.H>

unsigned char timer=0,counter=0;
unsigned char i,position,start;

void delay()
{
	unsigned char i,j;
	for(i=0;i<220;i++)
	   for(j=0;j<150;j++);
}

void T0_int(void) interrupt 1
{
	TL0=(65536-50000)%256;
	TH0=(65536-50000)/256;
	if(++counter>99) counter=0;	
}

void T1_int(void) interrupt 3
{
	TL1=(65536-10000)%256;
	TH1=(65536-10000)/256;
	P1=0xFF;
	switch(i)
	{
		case 0:
			P0=0xEF;
		       P1=(0xF0|counter/10);
		       break;
		case 1:
			P0=0xDF;
			P1=(0xF0|counter%10);
			break;
	}
	if(++i>1) i=0;
}

void INT1_int(void) interrupt 2
{
	EA=0;
	delay();
	while(!INT1);
	if(++start>1)
	{
		start=0;
		TR0=0;
	}
	else
	{
		start=1;
		TR0=1;
	}
	EA=1;
}

void main(void)
{	
	TMOD=0x11;
	TL0=(65536-50000)%256;
	TH0=(65536-50000)/256;
	TL1=(65536-10000)%256;
	TH1=(65536-10000)/256;
	TR0=0;
	ET0=1;
	TR1=1;
	ET1=1;
	INT1=1;
	EX1=1;
	EA=1;
	P2=0xF3;
	position=1;
	i=0;
	counter=0;
	start=0;
	
	while(1);	
}
