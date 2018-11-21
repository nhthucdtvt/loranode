/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech
Description: Bleeper board SPI driver implementation
License: Revised BSD License, see LICENSE.TXT file include in the project
Maintainer: Miguel Luis and Gregory Cristian
*/
#ifndef __SPI_MCU_H__
#define __SPI_MCU_H__

#include "em_usart.h"

#define USART_CLK                 cmuClock_USART1
#define PIN_SPI_TX                9		//MOSI = PC9
#define PORT_SPI_TX               gpioPortC
#define PIN_SPI_RX                11			//MISO = PC11
#define PORT_SPI_RX               gpioPortC
#define PIN_SPI_CLK               8			//SCK = PC8
#define PORT_SPI_CLK              gpioPortC
#define PIN_SPI_CS                7 		//CSN = PC7
#define PORT_SPI_CS               gpioPortC
#define LOC_SPI_TX				USART_ROUTELOC0_TXLOC_LOC14
#define LOC_SPI_RX				USART_ROUTELOC0_RXLOC_LOC15
#define LOC_SPI_CLK				USART_ROUTELOC0_CLKLOC_LOC11
#define LOC_SPI_CS				USART_ROUTELOC0_CSLOC_LOC9
#define USART_USED                USART1

typedef struct
{
	USART_InitSync_TypeDef Init;
	void* Instance;
} SPI_HandleTypeDef;

/*!
 * SPI driver structure definition
 */
struct Spi_s
{
    SPI_HandleTypeDef Spi;
    Gpio_t Mosi;
    Gpio_t Miso;
    Gpio_t Sclk;
    Gpio_t Nss;
};

#endif // __SPI_MCU_H__
