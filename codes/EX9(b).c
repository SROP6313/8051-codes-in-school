#include <REG51.H>
 
unsigned int i;
unsigned char Rled,Lled;

 void T0_int(void) interrupt 1
 {
	 if(++i>10)
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
	 TMOD=0x01;
	 TL0=(65536-50000)%256;
	 TH0=(65536-50000)/256;
	 TR0=1;
	 ET0=1;
	 EA=1;
	 i=0;
	 P2=0xFE;
	 Rled=0x80;
        Lled=0x01;
	 while(1);
	  
 }
