#include <REG51.H>

unsigned char table[]={
0xFF,0xF8,0xF9,0xFC,0xF5,0xF1,
0xFF,0xF8,0xF9,0xFC,0xF5,
};

void delay_2ms()
{
	unsigned char i,j;
	for(i=0;i<5;i++)
	   for(j=0;j<135;j++);
}

void main(void)
{
	unsigned char i,position,index,count;
	index=0;
	position=1;
	count=0;
	P2=0xF3;
	
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
			if(index<5)
			     index=index+1;
		       else
			     index=0;
			count=0;
		}	
	}
}