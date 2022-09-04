#include <REG51.H>
 
unsigned int i;
unsigned char index;
unsigned char led[]={
	0x7E, 0xBD, 0xDB, 0xE7, 
	0xE7, 0xDB, 0xBD, 0x7E
};

 void T1_int(void) interrupt 3
 {
	 if(++i>2199)
	 {	       
		 P1=led[index];
		 if(++index>7) index=0;
		 i=0;
	 }
	 	 
 }
 

 void main(void)
 {	 
	 TMOD=0x20;
	 TL1=256-250;
	 TH1=256-250;
	 TR1=1;
	 ET1=1;
	 EA=1;
	 i=0;
	 index=0;
	 P2=0xFE;
	 
	 while(1);
	  
 }
