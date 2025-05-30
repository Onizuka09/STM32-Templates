// #include <stm32f4xx.h>
// #include <stm32f401xe.h>
#include "led.h"

int x,y = 0; 
void do_somthing(int i){
i++; 
i=i*2;
}

int main(void)
{
    Led_init();
    TurOn_led();
	while (1)
		{
			TurOn_led();

		}
return 0;
}
