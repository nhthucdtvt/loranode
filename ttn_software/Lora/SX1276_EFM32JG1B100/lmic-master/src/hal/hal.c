/*******************************************************************************
 * Copyright (c) 2015 Matthijs Kooijman
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * This the HAL to run LMIC on top of the Arduino environment.
 *******************************************************************************/

#include "../../../lmic-master/src/lmic/lmic.h"

#include "em_system.h"
#include "em_assert.h"
#include "em_chip.h"
#include "em_device.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_int.h"
#include "em_emu.h"
#include "em_rtcc.h"
#include "em_usart.h"

#include <stdio.h>
// -----------------------------------------------------------------------------
// I/O
#define PORT_DIO0			gpioPortA	//DIO0 = PA0
#define PIN_DIO0			0
#define PORT_DIO1			gpioPortF	//DIO1 = PF4
#define PIN_DIO1			4
#define PORT_DIO2			gpioPortF	//DIO2 = PF3
#define PIN_DIO2			3
#define PORT_DIO3			gpioPortB	//DIO3 = PB12
#define PIN_DIO3			12
#define PORT_DIO4			gpioPortB	//DIO4 = PB11
#define PIN_DIO4			11
#define PORT_DIO5			gpioPortB	//DIO5 = PB13
#define PIN_DIO5			13
#define USART_USED                USART1
//#define USART_LOCATION            USART_ROUTE_LOCATION_LOC3
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

#define PIN_WAKEUP			10
#define PORT_WAKEUP			gpioPortC
// HAL state
static struct
{
    //int irqlevel;
    u4_t ticks;
} HAL;

bool Motion_detect = 0;
// -----------------------------------------------------------------------------
// I/O

static void hal_io_init ()
{
	//Enable module clocks
	CMU_ClockEnable(cmuClock_HFPER, true);
	CMU_ClockEnable(cmuClock_GPIO, true);

	GPIO_PinModeSet(PORT_DIO0, PIN_DIO0, gpioModeInputPull, 0);	//DIO0=PayLoadReady
	GPIO_PinModeSet(PORT_DIO1, PIN_DIO1, gpioModeInputPull, 0);	//DIO1=FifoLevel
	GPIO_PinModeSet(PORT_DIO2, PIN_DIO2, gpioModeInputPull, 0);	//DIO2=SyncAddr
	#if !defined PA53
	GPIO_PinModeSet(PORT_DIO3, PIN_DIO3, gpioModeInputPull, 0);	//DIO3=FifoEmpty
	#endif
	GPIO_PinModeSet(PORT_DIO4, PIN_DIO4, gpioModeInputPull, 0);	//DIO4=PreambleDetect/RSSI
	GPIO_PinModeSet(PORT_DIO5, PIN_DIO5, gpioModeInputPull, 0);	//DIO5=ModeReady

	GPIO_IntConfig(PORT_DIO0, PIN_DIO0, true, false, true);
	GPIO_IntConfig(PORT_DIO1, PIN_DIO1, true, false, true);
	GPIO_IntConfig(PORT_DIO2, PIN_DIO2, true, false, true);
	GPIO_IntConfig(PORT_WAKEUP, PIN_WAKEUP, true, false, true);
	NVIC_EnableIRQ(GPIO_ODD_IRQn);
	NVIC_EnableIRQ(GPIO_EVEN_IRQn);
}

// val ==1  => tx 1, rx 0 ; val == 0 => tx 0, rx 1
void hal_pin_rxtx (u1_t val)
{
	//not used in PA52 nor PA53
}


// set radio NSS pin to given value
void hal_pin_nss (u1_t val)
{
	if (val)
		GPIO_PinOutSet(PORT_SPI_CS, PIN_SPI_CS);	//  SPI Disable
	else
		GPIO_PinOutClear(PORT_SPI_CS, PIN_SPI_CS);	//  SPI Enable (Active Low)
}

// set radio RST pin to given value (or keep floating!)
void hal_pin_rst (u1_t val)
{
	#if defined PA52
		//not used in PA52
	#elif defined PA53
	if(val == 0 || val == 1) { // drive pin
        hw_cfg_pin(GPIOx(RST_PORT), RST_PIN, GPIOCFG_MODE_OUT | GPIOCFG_OSPEED_40MHz | GPIOCFG_OTYPE_PUPD | GPIOCFG_PUPD_PUP);
        hw_set_pin(GPIOx(RST_PORT), RST_PIN, val);
    } else { // keep pin floating
        hw_cfg_pin(GPIOx(RST_PORT), RST_PIN, GPIOCFG_MODE_INP | GPIOCFG_OSPEED_40MHz | GPIOCFG_OTYPE_OPEN);
    }
	#endif
}

extern void radio_irq_handler(u1_t dio);

void GPIO_ODD_IRQHandler(void)	//impar
 {
	u4_t i = GPIO_IntGet();
	if (i & 1<<PIN_DIO0)
		radio_irq_handler(0);
	else if (i & 1<<PIN_DIO1)
		radio_irq_handler(1);
	GPIO_IntClear(0xAAAA);

 }

void GPIO_EVEN_IRQHandler(void)	//par
 {
	u4_t i = GPIO_IntGet();
	if (i & 1<<PIN_DIO2)
		radio_irq_handler(2);
	else if (i & 1<<PIN_WAKEUP)
		Motion_detect = 1;
	GPIO_IntClear(0x5555);
	//GPIO_IntClear(1<<10);
 }

static void hal_spi_init ()
{

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

//	USART_InitSync_TypeDef initsync = USART_INITSYNC_DEFAULT;
//
//		initsync.enable = usartDisable;
//		initsync.baudrate = 1000000;
//		initsync.databits = usartDatabits8;
//		initsync.master = 1;
//		initsync.msbf = 1;
//		initsync.clockMode = usartClockMode0;
//	#if defined( USART_INPUT_RXPRS ) && defined( USART_TRIGCTRL_AUTOTXTEN )
//		initsync.prsRxEnable = 0;
//		initsync.prsRxCh = 0;
//		initsync.autoTx = 0;
//	#endif
//
//		USART_InitSync(USART1, &initsync);
//		// [USART_InitSync]$
//
//		// $[USART_InitPrsTrigger]
//		USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;
//
//		initprs.rxTriggerEnable = 0;
//		initprs.txTriggerEnable = 0;
//		initprs.prsTriggerChannel = usartPrsTriggerCh0;
//
//		USART_InitPrsTrigger(USART1, &initprs);



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
}

// perform SPI transaction with radio
u1_t hal_spi (u1_t out)
{
	/* For every byte sent, one is received */
	USART_Tx(USART_USED, out);
	return USART_Rx(USART_USED);
}


// -----------------------------------------------------------------------------
// TIME
static uint8_t       rtcInitialized = 0;    /**< 1 if rtc is initialized */
static uint32_t      rtcFreq;               /**< RTC Frequence. 32.768 kHz */

/***************************************************************************//**
 * @brief RTC Interrupt Handler, invoke callback function if defined.
 ******************************************************************************/
void RTCC_IRQHandler(void)
{
	if (RTCC_IntGet() & RTCC_IF_OF)
	{
		HAL.ticks ++;
	}

    if(RTCC_IntGet() & RTCC_IEN_CC1) // expired
    {
        // do nothing, only wake up cpu
    }
	RTCC_IntClear(_RTCC_IF_MASK); // clear IRQ flags
}


static void hal_time_init ()
{
	RTCC_Init_TypeDef init;

	rtcInitialized = 1;

	// Ensure LE modules are accessible //
	CMU_ClockEnable(cmuClock_CORELE, true);

	// Enable LFACLK in CMU (will also enable oscillator if not enabled) //
	CMU_ClockSelectSet(cmuClock_LFE, cmuSelect_LFXO);
	RTCC_CCChConf_TypeDef rtccInitCompareChannel = RTCC_CH_INIT_COMPARE_DEFAULT;// RTCC_CH_INIT_COMPARE_DEFAULT

//	init.enable   = false;
//	init.debugRun = false;
//	init.cntWrapOnCCV1 = true;        /* Clear counter on compare match */
//	init.presc = rtccCntPresc_1;

	/* Setting the compare value of the RTCC */
	//RTCC_ChannelInit(1, &rtccInitCompareChannel);
	 // RTCC_ChannelCCVSet(1, RTC_COUNT_BETWEEN_WAKEUP);

	// Use the prescaler to reduce power consumption. //
	CMU_ClockDivSet(cmuClock_RTCC, cmuClkDiv_1);

	rtcFreq = CMU_ClockFreqGet(cmuClock_RTCC);

	// Enable clock to RTC module //
	CMU_ClockEnable(cmuClock_RTCC, true);


//	init.comp0Top = false;
	//init.comp0Top = true; // Count to max before wrapping //
	RTCC_Init(&init);

	// Disable interrupt generation from RTC0 //
	RTCC_IntDisable(RTCC_IF_OF);
	RTCC_IntClear(RTCC_IF_OF);
	// Enable RTC //
	RTCC_Enable(true);

	// Enable interrupts //
	NVIC_ClearPendingIRQ(RTCC_IRQn);
	NVIC_EnableIRQ(RTCC_IRQn);
	RTCC_IntEnable(RTCC_IF_OF);

	RTCC_Enable(true);
}


u4_t hal_ticks ()
{
    hal_disableIRQs();
    u4_t t = HAL.ticks;
    u4_t cnt = RTCC_CounterGet();
	if (RTCC_IntGet() & RTCC_IF_OF)	// Overflow before we read CNT?
	{
        cnt = RTCC_CounterGet();
        t ++;	// Include overflow in evaluation but leave update of state to ISR once interrupts enabled again
    }
    hal_enableIRQs();
    return (t<<24)|cnt;
}

// return modified delta ticks from now to specified ticktime (0 for past, FFFF for far future)
static u2_t deltaticks (u4_t time)
{
    u4_t t = hal_ticks();
    s4_t d = time - t;
    if( d<=0 ) return 0;    // in the past
    if( (d>>16)!=0 ) return 0xFFFF; // far ahead
    return (u2_t)d;
}

void hal_waitUntil (u4_t time)
{
    while( deltaticks(time) != 0 ); // busy wait until timestamp is reached
}

// check and rewind for target time
u1_t hal_checkTimer (u4_t time)
{
    u2_t dt;
	RTCC_IntClear(RTCC_IEN_CC1);		//clear any pending interrupts
    if((dt = deltaticks(time)) < 5) // event is now (a few ticks ahead)
    {
    	RTCC_IntDisable(RTCC_IEN_CC1);	// disable IE
        return 1;
    }
    else // rewind timer (fully or to exact time))
    {
    	RTCC_CCChConf_TypeDef rtccInitCompareChannel;
    	/* Setting the compare value of the RTCC */
    	RTCC_ChannelInit(1, &rtccInitCompareChannel);
    	RTCC_ChannelCCVSet(1, RTCC_CounterGet() + dt);// set comparator
    	RTCC_IntEnable(RTCC_IEN_CC1);  // enable IE
        return 0;
    }
}



// -----------------------------------------------------------------------------
// IRQ

void hal_disableIRQs ()
{
	INT_Disable();
}

void hal_enableIRQs ()
{
	INT_Enable();
}

void hal_sleep ()
{
	EMU_EnterEM2(false);
}

// -----------------------------------------------------------------------------

void hal_init ()
{
    memset(&HAL, 0x00, sizeof(HAL));
    hal_disableIRQs();

    hal_io_init();	// configure radio I/O and interrupt handler

    hal_spi_init();	// configure radio SPI

    hal_time_init();	// configure timer and interrupt handler

    hal_enableIRQs();
}

void hal_failed ()
{
	//debug_led(1);
	// HALT...
    hal_disableIRQs();
    hal_sleep();
    while(1);
}
