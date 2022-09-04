#include <REG51.H>
 
unsigned char i, index;
unsigned char led[]={
	0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00,
	0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF
};

 void T1_int(void) interrupt 3
 {
	 TL1=(65536-50000)%256;
	 TH1=(65536-50000)/256;
	 if(++i>15)
	 {	       
		 P1=led[index];
		 if(++index>15) index=0;
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
