#include <REG51.H>

char minute=59,second=59,ms=99;

void delay_2ms()
{
	unsigned char i,j;
	for(i=0;i<5;i++)
	   for(j=0;j<135;j++);
}

void T1_int(void) interrupt 3
{
	TL1=(65536-10000)%256;
	TH1=(65536-10000)/256;
	if(--ms<0)
	{
		if(--second<0) 
		{
			if(--minute<0) minute=59;
			second=59;
		}
		ms=99;
	}
}
void main(void)
{
	unsigned char i,position,val[6];
	
	TMOD=0x10;
	TL0=(65536-10000)%256;
	TH0=(65536-10000)/256;
	TR1=1;
	ET1=1;
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
