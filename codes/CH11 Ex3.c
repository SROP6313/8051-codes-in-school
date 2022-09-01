#include <REG51.H>
 
unsigned char table[]={
	0xF8, 0xF9, 0xFC, 0xF5, 0xF1, 0xFE,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};


 void delay_2ms(void)
 {
	 unsigned char i,j;
	 for(i=0;i<5;i++)
	   for(j=0;j<135;j++);		 	 	 		 
 }
 
 void main(void)
 {	 
	 unsigned char i,index,position,count;
	 P2=0xF3;
	 position=1;
        index=0;
	 count=0;	 
	 while(1)
	 {
		 for(i=0; i<6; i++)
		 {
			 P1=0xFF;
			 P0=~(position<<i);
			 P1=table[index+i];
			 delay_2ms();
		 }
	  if(++count>39) 
	  {
		  count=0;
		  if(++index>6) index=0;
	  }	 
	 }		 
 }