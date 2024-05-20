#include "tm4c_cmsis.h"
#include "delay.h"
#include <stdint.h>


#define LED_RED (1U << 1)
#define LED_BLUE (1U<< 2)
#define LED_GREEN (1U << 3)




int main()
{
	//if the register have read write permission only,
	// BIT set and clear IDIOM , better to use this everywhere

	SYSCTL->RCGC2 |= (1U << 5);
	SYSCTL->GPIOHSCTL  |= (1U << 5);
	GPIOF_HS->DIR |= (LED_RED |LED_BLUE | LED_GREEN); // set pin 1,2 &  3 asd outputs
	GPIOF_HS->DEN |= (LED_RED |LED_BLUE | LED_GREEN); // set pin 1,2 &  3 asd outputs

	GPIOF_HS->DATA_Bits[LED_BLUE] = LED_BLUE;

	while(1){

		GPIOF_HS->DATA_Bits[LED_RED] =  LED_RED;
		delay(1000000);
		GPIOF_HS->DATA_Bits[LED_RED] =  0;
		delay(1000000);
	}

	return 0;
}


#if 0
#include "TM4C123GH6PM.h"
#include "bsp.h"

int main(void) {
    SYSCTL->GPIOHBCTL |= (1U << 5); /* enable AHB for GPIOF */
    SYSCTL->RCGCGPIO  |= (1U << 5); /* enable Run mode for GPIOF */

    GPIOF_AHB->DIR |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIOF_AHB->DEN |= (LED_RED | LED_BLUE | LED_GREEN);

    /* turn all LEDs off */
    GPIOF_AHB->DATA_Bits[LED_RED | LED_BLUE | LED_GREEN] = 0U;

    SysTick->LOAD = SYS_CLOCK_HZ/2U - 1U;
    SysTick->VAL  = 0U;
    SysTick->CTRL = (1U << 2) | (1U << 1) | 1U;

    SysTick_Handler();

    __enable_irq();
    while (1) {
        GPIOF_AHB->DATA_Bits[LED_GREEN] = LED_GREEN;
        GPIOF_AHB->DATA_Bits[LED_GREEN] = 0U;
    }
    //return 0; // unreachable code
}
#endif
