#include <REG51.H>
 
 void delay(void)
 {
	 unsigned char i,j;
	 for(i=0;i<220;i++)
	        for(j=0;j<150;j++);	 	 
 }
 

 void main(void)
 {	 
	 unsigned char count, led;
	 TMOD=0x60;
	 TL1=256-1;
	 TH1=256-1;
	 TR1=1;
	 count=0;
	 P2=0xFE;
	 led=0x0F;
	 while(1)
	 {
		 if(TF1==1)
		 {
			 TR1=0;
			 delay();
			 while(!T1);
			 if(++count>3)
			 {
				 count=0;
				 led=~led;
			 }
			 TF1=0;
			 TL1=256-1;
			 TH1=256-1;
			 TR1=1;
		 }
		 P1=led;
	 }		 
 }