#include "tm4c.h"


int main()
{
	SYSCTL_RCGCGPIO_R = 0x20; // clock gate register to provide clock pulse to port f
	GPIO_PORTF_DIR_R = 0xe; // set pin 1,2 &  3 asd outputs
	GPIO_PORTF_DEN_R = 0xe;


	while(1){
		GPIO_PORTF_DATA_R = 0x4;

	int counter = 0;
	while(counter < 100000)
	{
		counter++;
	}


	GPIO_PORTF_DATA_R = 0x2;

	counter = 0;
		while(counter < 100000)
		{
			counter++;
		}

		GPIO_PORTF_DATA_R = 0x8;
		counter = 0;
		while(counter < 100000)
		{
			counter++;
		}

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
