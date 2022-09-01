#include <REG51.H>
 
 void delay(void)
 {
	 unsigned char i=0;
	 while(i<60)
	 {
	        TL1=(8192-5000)%32;
		 TH1=(8192-5000)/32;
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