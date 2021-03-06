#include "MCUInit.h"
#include "em_system.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_assert.h"
#include "em_adc.h"
#include "em_gpio.h"
#include "em_i2c.h"
#include "em_rtcc.h"
#include "em_usart.h"
#include "em_cryotimer.h"
#include "em_leuart.h"
#include "em_wdog.h"

void EMUInit()
{
	EMU_DCDCPowerOff();
	/* Initialize EM2/EM3 mode */
	EMU_EM23Init_TypeDef em23Init = EMU_EM23INIT_DEFAULT;

	em23Init.em23VregFullEn = 0;

	EMU_EM23Init(&em23Init);
	/* Initialize EM4H/S mode */
	EMU_EM4Init_TypeDef em4Init = EMU_EM4INIT_DEFAULT;

	em4Init.retainLfrco = 0;
	em4Init.retainLfxo = 0;
	em4Init.retainUlfrco = 1;
	em4Init.em4State = emuEM4Shutoff;
	em4Init.pinRetentionMode = emuPinRetentionEm4Exit;

	EMU_EM4Init(&em4Init);
}
void CMUInit()
{

	// $[High Frequency Clock Setup]
	/* Initializing HFXO */
	CMU_HFXOInit_TypeDef hfxoInit = CMU_HFXOINIT_DEFAULT;

	CMU_HFXOInit(&hfxoInit);

	/* Using HFRCO as high frequency clock, HFCLK */
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO);
	// [High Frequency Clock Setup]$

	// $[LE clocks enable]
	/* Enable clock to LE modules */
	CMU_ClockEnable(cmuClock_CORELE, true);
	/* Initializing LFXO */
	CMU_LFXOInit_TypeDef lfxoInit = CMU_LFXOINIT_DEFAULT;

	CMU_LFXOInit(&lfxoInit);

	/* Enable LFXO oscillator, and wait for it to be stable */
	CMU_OscillatorEnable(cmuOsc_LFXO, true, true);

	/* Setting system LFXO frequency */
	SystemLFXOClockSet(32768);

	// [LE clocks enable]$
	CMU_OscillatorEnable(cmuOsc_LFRCO, true, true);
	// $[LFACLK Setup]
	/* LFACLK is disabled */
	// [LFACLK Setup]$
	// $[LFBCLK Setup]
	/* Select LFXO as clock source for LFBCLK */
	CMU_ClockSelectSet(cmuClock_LFB, cmuSelect_LFXO);
	// [LFBCLK Setup]$
	// $[LFECLK Setup]
	/* Select LFXO as clock source for LFECLK */
	CMU_ClockSelectSet(cmuClock_LFE, cmuSelect_LFXO);
	// [LFECLK Setup]$
	// $[Peripheral Clock enables]
	/* Enable clock for HF peripherals */
	CMU_ClockEnable(cmuClock_HFPER, true);

	/* Enable clock for CRYOTIMER */
	CMU_ClockEnable(cmuClock_CRYOTIMER, true);

	/* Enable clock for I2C0 */
	CMU_ClockEnable(cmuClock_I2C0, true);

	/* Enable clock for LEUART0 */
	CMU_ClockEnable(cmuClock_LEUART0, true);

	/*  Enable clock for ADC */
	CMU_ClockEnable(cmuClock_ADC0, true);

	/* Enable clock for RTCC */
	CMU_ClockEnable(cmuClock_RTCC, true);

	/* Enable clock for USART1 */
	CMU_ClockEnable(cmuClock_USART1, true);

	/* Enable clock for GPIO by default */
	CMU_ClockEnable(cmuClock_GPIO, true);

	// [Peripheral Clock enables]$

	// $[Clock output]
	/* Disable CLKOUT0 output */
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_CLKOUTSEL0_MASK)
			| CMU_CTRL_CLKOUTSEL0_DISABLED;
	/* Disable CLKOUT1 output */
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_CLKOUTSEL1_MASK)
			| CMU_CTRL_CLKOUTSEL1_DISABLED;

	// [Clock output]$

	// $[CMU_IO]
	/* Disable CLKOUT0 pin */
	CMU->ROUTEPEN &= ~CMU_ROUTEPEN_CLKOUT0PEN;

	/* Disable CLKOUT1 pin */
	CMU->ROUTEPEN &= ~CMU_ROUTEPEN_CLKOUT1PEN;

	// [CMU_IO]$

}



void CryotimerInit()
{
	// $[CRYOTIMER_Init]
	CRYOTIMER_Init_TypeDef cryoInit = CRYOTIMER_INIT_DEFAULT;

	// Clear CRYOTIMER_IF PERIOD flag; it will be set upon EM4 wake
	CRYOTIMER_IntClear(CRYOTIMER_IF_PERIOD);

	/* General settings */
	cryoInit.enable = 0;
	cryoInit.debugRun = 0;
	cryoInit.em4Wakeup = 1;

	/* Clocking settings */
	/* Using ULFRCO with 1Khz for cryotimer, this will result in a 16.00 seconds timeout */
	cryoInit.osc = cryotimerOscULFRCO;
	cryoInit.presc = cryotimerPresc_1;
	cryoInit.period = cryotimerPeriod_32k;
	CRYOTIMER_Init(&cryoInit);
	// [CRYOTIMER_Init]$
	// Interrupt setup
	CRYOTIMER_IntClear(CRYOTIMER_IF_PERIOD);
	CRYOTIMER_IntEnable(CRYOTIMER_IEN_PERIOD);
	NVIC_ClearPendingIRQ(CRYOTIMER_IRQn);
	NVIC_EnableIRQ(CRYOTIMER_IRQn);

	CRYOTIMER_Enable(true);
}

void GpsInit()
{

	// $[LEUART0 initialization]
	LEUART_Init_TypeDef initleuart = LEUART_INIT_DEFAULT;

	initleuart.enable = leuartEnable;
	initleuart.baudrate = 9600;
	initleuart.databits = leuartDatabits8;
	initleuart.parity = leuartNoParity;
	initleuart.stopbits = leuartStopbits1;
	LEUART_Init(LEUART0, &initleuart);

	/* Configuring LEUART I/O */
	/* Set up RX pin */
	LEUART0->ROUTELOC0 = (LEUART0->ROUTELOC0 & (~_LEUART_ROUTELOC0_RXLOC_MASK))
			| LEUART_ROUTELOC0_RXLOC_LOC19;
	LEUART0->ROUTEPEN = LEUART0->ROUTEPEN | LEUART_ROUTEPEN_RXPEN;

	/* Set up TX pin */
	LEUART0->ROUTELOC0 = (LEUART0->ROUTELOC0 & (~_LEUART_ROUTELOC0_TXLOC_MASK))
			| LEUART_ROUTELOC0_TXLOC_LOC21;
	LEUART0->ROUTEPEN = LEUART0->ROUTEPEN | LEUART_ROUTEPEN_TXPEN;
	/* Configuring non-standard properties */
	LEUART_TxDmaInEM2Enable(LEUART0, 0);
	LEUART_RxDmaInEM2Enable(LEUART0, 0);

	// [LEUART0 initialization]$

	LEUART_IntClear(LEUART0, LEUART_IF_RXDATAV);
	LEUART_IntEnable(LEUART0, LEUART_IF_RXDATAV);

	NVIC_ClearPendingIRQ (LEUART0_IRQn);
	NVIC_EnableIRQ(LEUART0_IRQn);
	LEUART_Enable(LEUART0, leuartEnable);

}

void WDOGInit()
{
	WDOG_Init_TypeDef wdogInit = WDOG_INIT_DEFAULT;

	wdogInit.enable = 1;
	wdogInit.debugRun = 0;
	wdogInit.clkSel = wdogClkSelULFRCO;
	wdogInit.perSel = wdogPeriod_128k;
	wdogInit.warnSel = wdogWarnDisable;
	wdogInit.winSel = wdogIllegalWindowDisable;
	wdogInit.resetDisable = false;

	WDOGn_Init(WDOG0, &wdogInit);
}
