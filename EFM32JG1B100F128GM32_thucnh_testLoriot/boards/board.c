/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech
Description: Target board general functions implementation
License: Revised BSD License, see LICENSE.TXT file include in the project
Maintainer: Miguel Luis and Gregory Cristian
*/
#include "board.h"
#include "gpio.h"
#include "em_device.h"
#include "em_gpio.h"
#include "em_emu.h"
#include "sx1276.h"

/*!
 * Unique Devices IDs register set ( EFM32GG )
 */
#define         ID1                                 0x0FE081F0
#define         ID2                                 0x0FE081F4

Gpio_t rejoinBtn;
Gpio_t LORA_Enable;
Gpio_t GPS_Enable;

Adc_t Vin;

Gpio_t WakeUp;
/*!
 * Used to measure and calibrate the system wake-up time from STOP mode
 */
static void CalibrateSystemWakeupTime( void );


/*!
 * Timer used at first boot to calibrate the SystemWakeupTime
 */
static TimerEvent_t CalibrateSystemWakeupTimeTimer;

/*!
 * Flag to indicate if the MCU is Initialized
 */
static bool McuInitialized = false;

/*!
 * Flag to indicate if the SystemWakeupTime is Calibrated
 */
static bool SystemWakeupTimeCalibrated = false;

/*!
 * Callback indicating the end of the system wake-up time calibration
 */
static void OnCalibrateSystemWakeupTimeTimerEvent( void )
{
    SystemWakeupTimeCalibrated = true;
}

/*!
 * Nested interrupt counter.
 *
 * \remark Interrupt should only be fully disabled once the value is 0
 */
static uint8_t IrqNestLevel = 0;

void BoardReadRegVersion(uint8_t * data){
	SX1272ReadBuffer(0x42, data, 1);
}

void BoardDisableIrq( void )
{
    __disable_irq( );
    IrqNestLevel++;
}

void BoardEnableIrq( void )
{
    IrqNestLevel--;
    if( IrqNestLevel == 0 )
    {
        __enable_irq( );
    }
}

void BoardInitPeriph( void )
{
	/* Initialize Rejoin Button */
	GpioInit( &rejoinBtn, REJOIN_BTN, PIN_INPUT, PIN_PUSH_PULL, PIN_PULL_UP, 1 );

	/* Initialize LORA */
	GpioInit( &LORA_Enable, LORA_EN, PIN_OUTPUT, PIN_PUSH_PULL, PIN_PULL_UP, 1 );

	/* Initialize GPS */
	GpioInit( &GPS_Enable, GPS_EN, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0 );

	/* Pin PD12 is configured to Input enabled with pull-down */
	GPIO_PinModeSet(gpioPortD, 12, gpioModeInputPull, 0);

	/* Pin PD13 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortD, 13, gpioModePushPull, 0);

	/* Pin PD14 is configured to Open-drain with pull-up and filter */
	GPIO_PinModeSet(gpioPortD, 14, gpioModeWiredAndPullUpFilter, 0);

	/* Pin PD15 is configured to Open-drain with pull-up and filter */
	GPIO_PinModeSet(gpioPortD, 15, gpioModeWiredAndPullUpFilter, 0);


	/* Initialize input */

	// Pin PC10 is configured to Input enabled with pull-down
	GPIO_PinModeSet(gpioPortC, 10, gpioModeInputPullFilter, 0);

	while (GPIO_PinInGet(gpioPortC, 10));
	GPIO_IntClear(1<<10);
	// Set rising edge interrupt
	GPIO_IntConfig(gpioPortC, 10, true, false, true);

	// Enable interrupt in core for even gpio interrupts
	NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
	NVIC_EnableIRQ (GPIO_EVEN_IRQn);

	// Enable EM4 wake on PC10 high
	GPIO_EM4EnablePinWakeup(_GPIO_EXTILEVEL_EM4WU12_MASK, GPIO_EXTILEVEL_EM4WU12);

	/*sx1272 Init*/
	SX1276IoInit();

	SpiInit(&SX1276.Spi, RADIO_MOSI, RADIO_MISO, RADIO_SCLK, RADIO_NSS);
}


void BoardDeInitMcu( void )
{
	assert_param( FAIL );
}

uint32_t BoardGetRandomSeed( void )
{
    return ( ( *( uint32_t* )ID1 ) ^ ( *( uint32_t* )ID2 ) );
}

void BoardGetUniqueId( uint8_t *id )
{
	id[7] = ( ( *( uint32_t* )ID1 ) ) >> 24;
    id[6] = ( ( *( uint32_t* )ID1 ) ) >> 16;
    id[5] = ( ( *( uint32_t* )ID1 ) ) >> 8;
    id[4] = ( ( *( uint32_t* )ID1 ) );
    id[3] = ( ( *( uint32_t* )ID2 ) ) >> 24;
    id[2] = ( ( *( uint32_t* )ID2 ) ) >> 16;
    id[1] = ( ( *( uint32_t* )ID2 ) ) >> 8;
    id[0] = ( ( *( uint32_t* )ID2 ) );
}

uint8_t BoardGetBatteryLevel( void )
{
	assert_param( FAIL );
	return 0; // never reached
}

void CalibrateSystemWakeupTime( void )
{
    if( SystemWakeupTimeCalibrated == false )
    {
        TimerInit( &CalibrateSystemWakeupTimeTimer, OnCalibrateSystemWakeupTimeTimerEvent );
        TimerSetValue( &CalibrateSystemWakeupTimeTimer, 1000 );
        TimerStart( &CalibrateSystemWakeupTimeTimer );
        while( SystemWakeupTimeCalibrated == false )
        {
            TimerLowPowerHandler( );
        }
    }
}


uint8_t GetBoardPowerSource( void )
{
#if defined( USE_USB_CDC )
    if( UartUsbIsUsbCableConnected( ) == 0 )
    {
        return BATTERY_POWER;
    }
    else
    {
        return USB_POWER;
    }
#else
    return BATTERY_POWER;
#endif
}

#ifdef USE_FULL_ASSERT
/*
 * Function Name  : assert_failed
 * Description    : Reports the name of the source file and the source line number
 *                  where the assert_param error has occurred.
 * Input          : - file: pointer to the source file name
 *                  - line: assert_param error line source number
 * Output         : None
 * Return         : None
 */
void assert_failed( uint8_t* file, uint32_t line )
{
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while( 1 )
    {
    }
}
#endif
