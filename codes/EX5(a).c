#include <REG51.H>
 
 void delay(void)
 {
	 int i=0;
	 while(i<2800)
	 {	       
		 TR1=1;
		 while(TF1!=1);
		 TR1=0;
		 TF1=0;
		 i++;	     
	 }
	 	 
 }
 

 void main(void)
 {	 
	 unsigned char led;
	 TL1=256-250;
	 TH1=256-250;
	 P2=0xFE;
	 TMOD=0x20;
	 led=0x00;
	 
	 while(1)
	 {
		 P1=led;
		 delay();
		 led=~led;	 
	 }
	  
 }
