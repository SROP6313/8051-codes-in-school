#include <REG51.H>
 
unsigned char timer=0,counter=0;

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
	 if(++timer>1)
	 {
		 if(++counter>99) counter=0;
               timer=0;		 
	 }
 }
 
 void main(void)
 {	 
	 unsigned char i,position;
	 TMOD=0x01;
	 TL0=(65536-50000)%256;
	 TH0=(65536-50000)/256;
	 TR0=1;
	 ET0=1;
	 EA=1;
	 P2=0xF3;
	 position=1;
        counter=0;	 
	 while(1)
	 {
		 for(i=0; i<6; i++)
		 {
			 P1=0xFF;
			 P0=~(position<<i);
			 switch(i)
			 {
				 case 0:
					 P1=(0xF0|counter/10);
				        break;
				 case 1:
					 P1=(0xF0|counter%10);
				        break;
			 }
			 delay_2ms();
		 }   	  		  	 
	 }		 
 }