#include <REG51.H>
 
unsigned char count, led;

 void delay(void)
 {
	 unsigned char i,j;
	 for(i=0;i<220;i++)
	        for(j=0;j<150;j++);	 	 
 }
 
 void main(void)
 {	 
	 TMOD=0x06;
	 TL0=256-1;
	 TH0=256-1;
	 TR0=1;
	 count=0;
	 P2=0xFE;
	 led=0x03;
	 while(1)
	 {
		 if(TF0==1)
		 {
			TR0=0;
                     delay();
			while(!T0);
			if(++count>1)
			{
				count=0;
				if(led==0)
					led=0x03;
				else
					led=led<<2;
			}
			TF0=0;
			TL0=256-1;
	              TH0=256-1;
			TR0=1;
		 }
		 P1=~led;
	 }		 
 }
