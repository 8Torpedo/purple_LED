#include "board.h"
#include <stdio.h>

#define TICKRATE_HZ (100)	/* 100 ticks per second */

/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	int i=0;
	Board_LED_Set(0 ,true);
	for(i=0; i<=1800; i++)
	{
		Board_LED_Set(2 ,false);
	}
	Board_LED_Set(2 ,true);
}


int main(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable SysTick Timer */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ);
	/* Loop forever */
	while (1) {
		__WFI();
	}
}
