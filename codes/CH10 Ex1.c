#include <REG51.H>
 
 void delay(void)
 {
	 unsigned char i=0;
	 while(i<80)
	 {
	        TL0=(8192-5000)%32;
		 TH0=(8192-5000)/32;
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
	 
	 P2=0xFE;
	 TMOD=0x00;
	 led=0x00;
	 
	 while(1)
	 {
		 P1=led;
		 delay();
		 led=~led;	 
	 }
	  
 }