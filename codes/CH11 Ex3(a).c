#include <REG51.H>

unsigned char table[]={
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xF8,0xF9,0xFC,0xF5,0xF1,0xFF,
};

void delay_2ms()
{
	unsigned char i,j;
	for(i=0;i<5;i++)
	   for(j=0;j<135;j++);
}

void main(void)
{
	unsigned char i,index,position,count,time;
	P2=0xF3;
	index=0;
	position=1;
	count=0;
	time=1;
	
	while(1)
	{
		for(i=0;i<6;i++)
		{
			P1=0xFF;
			P0=~(position<<i);
			P1=table[index+i];
			delay_2ms();
		}
		if(++count>49)
		{						
			count=0;
			if(time<7)
			{
				index++;
			}
			else
			{
				index--;
			}
			time++;
			if(time>12) time=1;
		}
	}
}