#include <REG51.H>
 
unsigned char table1[]={
	0xF8, 0xF9, 0xF5, 0xF1, 0xFF, 0xFF
};

unsigned char table2[]={
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
 void delay(void)
 {
	 unsigned char i;
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
	 int count;
	 P2=0xF3;
	 TMOD=0x01;
	 position=1;
        count=0;	 
	 while(1)
	 {
		 for(i=0; i<6; i++)
		 {
			 P1=0xFF;
			 P0=~(position<<i);
			 if(count<1200)
				 P1=table1[i];
			 else
				 P1=table2[i];
			 
			 delay();
		 }
	  if(++count>2399) count=0;	 
	 }		 
 }