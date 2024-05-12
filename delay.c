/*
 * delay.c
 *
 *  Created on: 12-May-2024
 *      Author: Sharun
 */
#include "delay.h"


void delay (int itr)
{
	int volatile counter = 0;
	while(counter < itr)
	{
		counter++;
	}
}


