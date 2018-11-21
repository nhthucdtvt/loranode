/*
 * config.h
 *
 *  Created on: Dec 15, 2017
 *      Author: khiemtt
 */
#ifndef _CONFIG_H_
#define _CONFIG_h_

#define GPS_EN_PIN          (10)
#define GPS_EN_PORT         (gpioPortD)

#define LED1_PIN            (9)
#define LED1_PORT           (gpioPortD)

#define LORA_DIO0_PIN       (0)
#define LORA_DIO0_PORT      (gpioPortA)

#define LORA_DIO1_PIN       (4)
#define LORA_DIO1_PORT      (gpioPortF)

#define LORA_DIO2_PIN       (3)
#define LORA_DIO2_PORT      (gpioPortF)

#define LORA_DIO3_PIN       (12)
#define LORA_DIO3_PORT      (gpioPortB)

#define LORA_DIO4_PIN       (11)
#define LORA_DIO4_PORT      (gpioPortB)

#define LORA_DIO5_PIN       (13)
#define LORA_DIO5_PORT      (gpioPortB)

#define LORA_EN_PIN         (11)
#define LORA_EN_PORT        (gpioPortD)

void init_function(void);
void init_EMU(void);
void init_CMU(void);
void init_LEUART0(void);
void init_I2C0(void);
void init_GPIO(void);

#endif
