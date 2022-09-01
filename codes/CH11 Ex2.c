#include <REG51.H>
 
unsigned char table1[]={
	0xF8, 0xF9, 0xF5, 0xF1, 0xFF, 0xFF
};

unsigned char table2[]={
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
 void delay_2ms(void)
 {
	 unsigned char i,j;
	 for(i=0;i<5;i++)
          for(j=0;j<135;j++);	 
 }
 
 void main(void)
 {	 
	 unsigned char i, position,count;
	 P2=0xF3;
	 position=1;
        count=0;	 
	 while(1)
	 {
		 for(i=0; i<6; i++)
		 {
			 P1=0xFF;
			 P0=~(position<<i);
			 if(count<40)
				 P1=table1[i];
			 else
				 P1=table2[i];
			 
			 delay_2ms();
		 }
	  if(++count>79) count=0;	 
	 }		 
 }