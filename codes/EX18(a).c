#include <REG51.H>

unsigned char timer=0,start;
long counter=999999,value;

void delay_2ms()
{
	unsigned char i,j;
	for(i=0;i<5;i++)
	    for(j=0;j<135;j++);
}

void T1_int(void) interrupt 3     //count and reset
{
	if(T1==1&&start==1)
	{
		TH1=(65536-50000)/256;
	       TL1=(65536-50000)%256;
		if(++timer>1)
	       {
		   value=counter;
		   counter--;
		   if(counter==0) counter=999999;
		   timer=0;
	       }
	}
	else if(T1==0)
	{
		counter=0;
		value=0;
	}
}

void INT1_int(void) interrupt 2    //start
{
	TR1=1;
	start=1;
}

void T0_int(void) interrupt 1    //stop
{
	start=0;
	counter=value;
}

void main(void)
{
	unsigned char i,position,val[6];
	long tmp;
	TMOD=0x10;
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	TR1=0;
	ET1=1;
	T1=1;
	TR0=1;
	ET0=1;
	T0=1;
	INT1=1;
	EX1=1;
	EA=1;
	P2=0xF3;
	position=1;
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
			P1=(0xF0|val[i]);
			delay_2ms();
		}
	}
}
