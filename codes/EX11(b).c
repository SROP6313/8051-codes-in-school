#include <REG51.H>
 
unsigned char push, led;

 void delay(void)
 {
	 unsigned char i,j;
	 for(i=0;i<220;i++)
	        for(j=0;j<150;j++);	 	 
 }
 
 void T0_int(void) interrupt 3
 {
	 EA=0;
	 delay();
	 while(T1!=1);
	 if(++push>1)
	 {
		 if(led==0)
			 led=0x03;
		 else
			 led=led<<2;
		 push=0;
	 }
	 TL1=0xFF;
	 TH1=0xFF;
	 EA=1;
 }
 void main(void)
 {	 
	 TMOD=0x50;
	 TL1=0xFF;
	 TH1=0xFF;
	 TR1=1;
	 ET1=1;
	 EA=1;
	 push=0;
	 P2=0xFE;
	 led=0x03;
	 while(1)
	 {
		 P1=~led;
	 }		 
 }
