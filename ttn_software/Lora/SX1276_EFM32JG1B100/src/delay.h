/*
 * delay.h
 *
 *  Created on: Dec 21, 2017
 *      Author: khiemtt
 */

#ifndef _DELAY_H_
#define _DELAY_H_

void SysTick_Handler(void);
void delayMs(uint32_t dlyTicks);;
void initDelay();

#endif /* _DELAY_H_ */
