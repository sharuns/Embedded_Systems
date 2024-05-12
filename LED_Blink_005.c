#include "tm4c.h"
#include "delay.h"

#define LED_RED (1U << 1)
#define LED_BLUE (1U<< 2)
#define LED_GREEN (1U << 3)




int main()
{
	//if the register have read write permission only,
	// BIT set and clear IDIOM , better to use this everywhere
 	SYSCTL_RCGCGPIO_R |= (1U << 5);
	SYSCTL_GPIOHBCTL_R = (1U << 5);//enabling AHB// clock gate register to provide clock pulse to port f
	GPIO_PORTF_AHB_DIR_R |= (LED_RED |LED_BLUE | LED_GREEN); // set pin 1,2 &  3 asd outputs
	GPIO_PORTF_AHB_DEN_R |= (LED_RED |LED_BLUE | LED_GREEN);


	GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;

	while(1){

		GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] =  LED_RED;
		delay(1000000);
		GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] =  0;
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
