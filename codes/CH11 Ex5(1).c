#include <REG51.H>
 
unsigned char timer=0,start,tmp,val[6];
unsigned long value,counter=0;

 void delay_2ms(void)
 {
	 unsigned char i,j;
	 for(i=0;i<5;i++)
	   for(j=0;j<135;j++);		 	 	 		 
 }
 
 void T0_int(void) interrupt 1   //count and stop
 {
     if((T0==1)&&(start==1))
     {	 
	 TL0=(65536-50000)%256;
	 TH0=(65536-50000)/256;	 		 
	 tmp=counter;
	 counter++;
	 if(counter>999999) counter=0;
        timer=0;		 	 
     }
     else
     {
	   counter=tmp;
 	   start=0;  
     }
 }
 
 void INT1_int(void) interrupt 2  //start
 {
	 TR0=1;
	 start=1;
 }
 
 void T1_int(void) interrupt 3  //reset
 {
	 if(T1==0) 
	 {
		 tmp=0;
		 counter=0;
	 }
 }
 
 void main(void)
 {	 
	 unsigned char i,position;
	 TMOD=0x01;
	 TL0=(65536-50000)%256;
	 TH0=(65536-50000)/256;
	 TR0=0;
	 ET0=1;
	 INT1=1;
	 EX1=1;
	 T0=1;
	 T1=1;
	 TR1=1;
	 ET1=1;
	 EA=1;
	 P2=0xF3;
	 position=1;
        counter=0;	 
	 while(1)
	 {
		 val[0]=counter/100000;
		 value=counter%100000;
		 val[1]=value/10000;
		 value=value%10000;
		 val[2]=value/1000;
		 value=value%1000;
		 val[3]=value/100;
		 value=value%100;
		 val[4]=value/10;
		 val[5]=value%10;
		 for(i=0; i<6; i++)
		 {
			 P1=0xFF;
			 P0=~(position<<i);
			 P1=0xF0|val[i];
			 delay_2ms();
		 }   	  		  	 
	 }		 
 }