#include <REG51.H>
 
unsigned char table[]={
	0xF8, 0xF9, 0xF5, 0xF1, 0xFF, 0xFF
};

 void delay_2ms(void)
 {
	 unsigned char i,j;
	 for(i=0;i<5;i++)
	        for(j=0;j<135;j++);	 	 
 }
 
 void main(void)
 {	 
	 unsigned char i, position;
	 P2=0xF3;
	 position=1;		 
	 while(1)
	 {
		 for(i=0; i<6; i++)
		 {
			 P1=0xFF;
			 P0=~(position<<i);
			 P1=table[i];
			 delay_2ms();
		 }		 
	 }		 
 }