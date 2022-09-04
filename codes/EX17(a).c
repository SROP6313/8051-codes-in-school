#include <REG51.H>

unsigned char minute=0,second=0,ms=0,start,tmpmin,tmpsec,tmpms;

void delay_2ms()
{
	unsigned char i,j;
	for(i=0;i<5;i++)
	   for(j=0;j<135;j++);
}

void T0_int(void) interrupt 1          //count and stop
{
	if((T0==1)&&(start==1))
	{
		TL0=(65536-10000)%256;
	       TH0=(65536-10000)/256;
	       tmpms=ms;
		ms++;
		if(ms>99)
	       {
			tmpsec=second;
			second++;
			if(second>59)
		      {	
			      tmpmin=minute;
			      minute++;
			      if(minute>59) minute=0;
			         second=0;										
		      }
                    ms=0;		
	       }
	}	
	else
	{
		start=0;
		ms=tmpms;
		second=tmpsec;
		minute=tmpmin;
	}		
}

void INT1_int(void) interrupt 2     //start
{
	TR0=1;
	start=1;
}

void T1_int(void) interrupt 3      //reset
{
	if(T1==0)
	{
		ms=0;
	       tmpms=0;
	       second=0;
	       tmpsec=0;
	       minute=0;
	       tmpmin=0;
	}	
}

void main(void)
{
	unsigned char i,position,val[6];
	TMOD=0x01;
	TL0=(65536-10000)%256;
	TH0=(65536-10000)/256;
	TR0=0;
	ET0=1;
	T0=1;
	T1=1;
	TR1=1;
	ET1=1;
	INT1=1;
	EX1=1;
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
