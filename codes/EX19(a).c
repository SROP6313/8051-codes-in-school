#include <REG51.H>

int ms=99,sec=59,minute=59;

void T1_int(void) interrupt 3
{
	TH1=(65536-10000)/256;
	TL1=(65536-10000)%256;
	if(--ms<0)
	{
		if(--sec<0)
		{
			if(--minute<0)
			{
				minute=59;
			}
			sec=59;
		}
		ms=99;
	}
}
