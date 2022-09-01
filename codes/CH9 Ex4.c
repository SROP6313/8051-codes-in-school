#include <REG51.H>
 
 unsigned char push;
 
 void delay_100ms(unsigned char ms)
 {
	 unsigned char i,j;
	 while(ms)
	 {
	 for(i=0;i<220;i++)
	        for(j=0;j<150;j++);
		 ms--;
	 }
	 	 
 }
 
 void INT1_int(void) interrupt 2 using 1
 {
	 unsigned char i,led; 
	 EA=0;
	  delay_100ms(1);
	 while(!INT1);
	 led=0xF0;
	 for(i=0;i<20;i++)
	 {
		 P1=led;
		 delay_100ms(2);
		 led=~led;
	 }
	 EA=1;
 }
 void main(void)
 {
	 unsigned char led;
	 P0=0xFF;
	 P1=0xFF;
	 P2=0xFF;
	 P3=0xFF;
	 IE=0x84;
	 P2=0xFE;
	 led=0;
	 while(1)
	 {
		 P1=led;
		 delay_100ms(2);
		 led=~led;
	 }
	  
 }