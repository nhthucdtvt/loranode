/*
 * delay.c
 *
 *  Created on: Dec 21, 2017
 *      Author: khiemtt
 */
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "config.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "delay.h"

volatile uint32_t msTicks; /* counts 1ms timeTicks */

void SysTick_Handler(void)
{
  msTicks++;       /* increment counter necessary in Delay()*/
}

void delayMs(uint32_t dlyTicks)
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks) ;
}

void initDelay()
{
	if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) {
		while (1) ;
	}
}
