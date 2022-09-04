#include <REG51.H>
 
unsigned long counter=0;

 void delay_2ms(void)
 {
	 unsigned char i,j;
	 for(i=0;i<5;i++)
	   for(j=0;j<135;j++);		 	 	 		 
 }
 
 void T0_int(void) interrupt 1
 {
	 TL0=(65536-50000)%256;
	 TH0=(65536-50000)/256;
	 if(++counter>999999)
	 		  counter=0;		 	
 }
 
 void main(void)
 {	 
	 unsigned char i,position,val[6];
	 unsigned long tmp;
	 TMOD=0x01;
	 TL0=(65536-50000)%256;
	 TH0=(65536-50000)/256;
	 TR0=1;
	 ET0=1;
	 EA=1;
	 P2=0xF3;
	 position=1;	 
	 while(1)
	 {
		 val[0]=counter/100000;
		 tmp=counter%100000;
		 val[1]=tmp/10000;
		 tmp=tmp%10000;
		 val[2]=tmp/1000;
		 tmp=tmp%1000;
		 val[3]=tmp/100;
		 tmp=tmp%100;
		 val[4]=tmp/10;
		 val[5]=tmp%10;
		 for(i=0; i<6; i++)
		 {
			 P1=0xFF;
			 P0=~(position<<i);
			 P1=0xF0|val[i];
			 delay_2ms();
		 }   	  		  	 
	 }		 
 }
