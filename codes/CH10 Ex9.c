#include <REG51.H>
 
unsigned char push, led;

 void delay(void)
 {
	 unsigned char i,j;
	 for(i=0;i<220;i++)
	        for(j=0;j<150;j++);	 	 
 }
 
 void T0_int(void) interrupt 1
 {
	 EA=0;
	 delay();
	 while(T0!=1);
	 if(++push>1)
	 {
		 if(led==0)
			 led=0x03;
		 else
			 led=led<<2;
		 push=0;
	 }
	 TL0=0xFF;
	 TH0=0xFF;
	 EA=1;
 }
 void main(void)
 {	 
	 TMOD=0x05;
	 TL0=0xFF;
	 TH0=0xFF;
	 TR0=1;
	 ET0=1;
	 EA=1;
	 push=0;
	 P2=0xFE;
	 led=0x03;
	 while(1)
	 {
		 P1=~led;
	 }		 
 }