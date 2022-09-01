#include <REG51.H>
 
 void delay_500ms(void)
 {
	 int i=0;
	 while(i<2000)
	 {	       
		 TL0=256-250;
		 TR0=1;
		 while(TF0!=1);
		 TR0=0;
		 TF0=0;
		 i++;	     
	 }
	 	 
 }
 
 void delay_1s(void)
 {
	 int i=0;
	 while(i<4000)
	 {
		 TH0=256-250;
		 TR1=1;
		 while(TF1!=1);
		 TR1=0;
		 TF1=0;
		 i++;
	 }
 }

 void main(void)
 {	 
	 P2=0xFE;
	 TMOD=0x03;
	 
	 while(1)
	 {
		 P1=0x00;
		 delay_1s();
		 P1=0xFF;
               delay_500ms();		 
	 }
	  
 }