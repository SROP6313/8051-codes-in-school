#include <REG51.H>
 
unsigned char i, index;
unsigned char led[]={
	0xE7, 0xDB, 0xBD, 0x7E, 
	0xBD, 0xDB, 0xE7, 0xFF
};

 void T1_int(void) interrupt 3
 {
	 TL1=(65536-50000)%256;
	 TH1=(65536-50000)/256;
	 if(++i>15)
	 {	       
		 P1=led[index];
		 if(++index>7) index=0;
		 i=0;
	 }
	 	 
 }
 

 void main(void)
 {	 
	 TMOD=0x10;
	 TL1=(65536-50000)%256;
	 TH1=(65536-50000)/256;
	 TR1=1;
	 ET1=1;
	 EA=1;
	 i=0;
	 index=0;
	 P2=0xFE;
	 
	 while(1);
	  
 }