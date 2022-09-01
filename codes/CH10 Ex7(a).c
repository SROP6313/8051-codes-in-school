#include <REG51.H>
 
unsigned int i;
unsigned char Rled,Lled;

 void T1_int(void) interrupt 3
 {
	 if(++i>2199)
	 {	       
		 P1=~(Rled|Lled);
		 Rled=Rled>>1;
		 Lled=Lled<<1;
		 if((Lled||Rled)==0)  
		 {
			 Rled=0x80,Lled=0x01;
		 }
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
	 P2=0xFE;
	 Rled=0x80;
        Lled=0x01;
	 while(1);
	  
 }