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
#include "board.h"
#include "spi-board.h"
#include "em_cmu.h"
#include "em_gpio.h"

#define USART_USED          USART1
#define USART_LOCATION      1	//?
#define USART_CLK           cmuClock_USART1

typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus;

void SpiInit( Spi_t *obj, PinNames mosi, PinNames miso, PinNames sclk, PinNames nss )
{
	BoardDisableIrq( );

	USART_InitSync_TypeDef init = USART_INITSYNC_DEFAULT;
	/* Enable module clocks */
	CMU_ClockEnable(cmuClock_HFPER, true);
	CMU_ClockEnable(USART_CLK, true);
	CMU_ClockEnable(cmuClock_GPIO, true);

	/* Configure SPI pins */
	GPIO_PinModeSet(PORT_SPI_TX, PIN_SPI_TX, gpioModePushPull, 0);
	GPIO_PinModeSet(PORT_SPI_RX, PIN_SPI_RX, gpioModeInputPull, 0);
	GPIO_PinModeSet(PORT_SPI_CLK,PIN_SPI_CLK,gpioModePushPull, 0);
	GPIO_PinModeSet(PORT_SPI_CS, PIN_SPI_CS, gpioModePushPull, 1);

	/* Reset USART just in case */
	USART_Reset(USART_USED);

	init.clockMode = usartClockMode0;

	// Configure to use SPI master with manual CS //
	init.refFreq = 0;
	init.baudrate = 1000000;
	init.msbf = true;	// Send most significant bit first. //
	USART_InitSync(USART_USED, &init);


	/* Enabling pins and setting location, SPI CS not enable */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_CLKLOC_MASK))
			| LOC_SPI_CLK;
	USART1->ROUTEPEN = USART1->ROUTEPEN | USART_ROUTEPEN_CLKPEN;

	/*  CS pin */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_CSLOC_MASK))
			| LOC_SPI_CS;
	USART1->ROUTEPEN = USART1->ROUTEPEN & (~USART_ROUTEPEN_CSPEN);

	/* Disable CTS pin */
	USART1->ROUTELOC1 = (USART1->ROUTELOC1 & (~_USART_ROUTELOC1_CTSLOC_MASK))
			| USART_ROUTELOC1_CTSLOC_LOC2;
	USART1->ROUTEPEN = USART1->ROUTEPEN & (~USART_ROUTEPEN_CTSPEN);

	/* Disable RTS pin */
	USART1->ROUTELOC1 = (USART1->ROUTELOC1 & (~_USART_ROUTELOC1_RTSLOC_MASK))
			| USART_ROUTELOC1_RTSLOC_LOC1;
	USART1->ROUTEPEN = USART1->ROUTEPEN & (~USART_ROUTEPEN_RTSPEN);

	/* Set up RX pin */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_RXLOC_MASK))
			| LOC_SPI_RX;
	USART1->ROUTEPEN = USART1->ROUTEPEN | USART_ROUTEPEN_RXPEN;

	/* Set up TX pin */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_TXLOC_MASK))
			| LOC_SPI_TX;
	USART1->ROUTEPEN = USART1->ROUTEPEN | USART_ROUTEPEN_TXPEN;

	USART1->CTRLX = USART1->CTRLX & (~USART_CTRLX_CTSEN);
	/* Set CTS active low */
	USART1->CTRLX = USART1->CTRLX & (~USART_CTRLX_CTSINV);
	/* Set RTS active low */
	USART1->CTRLX = USART1->CTRLX & (~USART_CTRLX_RTSINV);
	/* Set CS active low */
	USART1->CTRL = USART1->CTRL & (~USART_CTRL_CSINV);
	/* Set TX active high */
	USART1->CTRL = USART1->CTRL & (~USART_CTRL_TXINV);
	/* Set RX active high */
	USART1->CTRL = USART1->CTRL & (~USART_CTRL_RXINV);

	USART_Enable(USART1, usartEnable);
	BoardEnableIrq( );
}

void SpiDeInit( Spi_t *obj )
{
	assert_param( FAIL );
}

void SpiFormat( Spi_t *obj, int8_t bits, int8_t cpol, int8_t cpha, int8_t slave )
{
	(void)cpha; // Falling vs rising edge is already part of cpol

    obj->Spi.Init.databits = bits;

    obj->Spi.Init.clockMode = cpol;
    obj->Spi.Init.msbf = true;
    obj->Spi.Init.refFreq = 0;

    obj->Spi.Init.master = !slave;
}

void SpiFrequency( Spi_t *obj, uint32_t hz )
{
	obj->Spi.Init.baudrate = hz;
}

FlagStatus SpiGetFlag( Spi_t *obj, uint16_t flag )
{
	assert_param( FAIL );
	return 0; // never reached
}

uint16_t SpiInOut( Spi_t *obj, uint16_t outData )
{
/*	uint8_t data;
	data = USART_SpiTransfer(USART_USED, outData);
	return (uint16_t)data;*/

	// For every byte sent, one is received
	USART_Tx(USART_USED, outData);
	return USART_Rx(USART_USED);
}


