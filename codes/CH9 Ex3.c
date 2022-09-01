#include <REG51.H>
 
 unsigned char push;
  void delay(void)
 {
	 unsigned char i,j;
	 for(i=0;i<220;i++)
	        for(j=0;j<150;j++);
 }
 
 void INT1_int(void) interrupt 2
 {
	 EA=0;
	 delay();
	 while(!INT1);
	 push++;
	 EA=1;
 }
 void main(void)
 {
	 P0=0xFF;
	 P1=0xFF;
	 P2=0xFF;
	 P3=0xFF;
	 IE=0x84;
	 P2=0xFE;
	 push=0;
	 while(1)
	 {
		 P1=~push;
	 }
	  
 }
