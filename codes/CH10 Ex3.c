#include <REG51.H>
 
 void delay(void)
 {
	 int i=0;
	 while(i<1800)
	 {	       
		 TR0=1;
		 while(TF0!=1);
		 TR0=0;
		 TF0=0;
		 i++;	     
	 }
	 	 
 }
 

 void main(void)
 {	 
	 unsigned char led;
	 TL0=256-250;
	 TH0=256-250;
	 P2=0xFE;
	 TMOD=0x02;
	 led=0x00;
	 
	 while(1)
	 {
		 P1=led;
		 delay();
		 led=~led;	 
	 }
	  
 }