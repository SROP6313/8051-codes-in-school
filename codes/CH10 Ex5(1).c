#include <REG51.H>
 
unsigned char i, led;

 void T0_int(void) interrupt 1
 {
	 TL0=(65536-50000)%256;
	 TH0=(65536-50000)/256;
	 if(++i>15)
	 {	       
		 P1=~led;
		 led=led>>1;
		 if(led==0) led=0x80;
		 i=0;
	 }
	 	 
 }
 

 void main(void)
 {	 
	 TMOD=0x01;
	 TL0=(65536-50000)%256;
	 TH0=(65536-50000)/256;
	 TR0=1;
	 ET0=1;
	 EA=1;
	 i=0;
	 P2=0xFE;
	 led=0x80;
	 
	 while(1);
	  
 }