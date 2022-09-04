#include <REG51.H>
 
unsigned char table[]={
	0xF8, 0xF9, 0xF5, 0xF1, 0xFF, 0xFF
};

 void delay(void)
 {
	 unsigned char i=0;
	 while(i<1)
	 {
		 TL0=(65536-2000)%256;
		 TH0=(65536-2000)/256;
		 TR0=1;
		 while(TF0!=1);
		 TR0=0;
		 TF0=0;
		 i++;
	 }	 	 
 }
 
 void main(void)
 {	 
	 unsigned char i, position;
	 P2=0xF3;
	 TMOD=0x01;
	 position=1;		 
	 while(1)
	 {
		 for(i=0; i<6; i++)
		 {
			 P1=0xFF;
			 P0=~(position<<i);
			 P1=table[i];
			 delay();
		 }		 
	 }		 
 }
