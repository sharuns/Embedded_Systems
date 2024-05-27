/* Board Support Package */
#include "TM4C123GH6PM.h"
#include "bsp.h"


/*IAR version of this funtion used IAR based c extensions to perform the stackless creation of a function
 *
 * _stackless void assert_failed (char const *file, int line) {
    NVIC_SystemReset();
	}
 *
 *
 * */


__attribute__((naked)) void assert_failed (char const *file, int line) {
    /* TBD: damage control */
    NVIC_SystemReset(); /* reset the system */
}

void SysTick_Handler(void) {
    GPIOF_AHB->DATA_Bits[LED_RED] ^= LED_RED;
}
