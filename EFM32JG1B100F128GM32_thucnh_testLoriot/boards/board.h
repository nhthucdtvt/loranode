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
#ifndef __BOARD_H__
#define __BOARD_H__

#include "em_device.h"
#include "em_assert.h"


typedef struct
{
  ADC_TypeDef* Instance;
}ADC_HandleTypeDef;

typedef struct
{
  I2C_TypeDef* Instance;
}I2C_HandleTypeDef;

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "utilities.h"
#include "timer.h"
#include "delay.h"
#include "gpio.h"
#include "adc.h"
#include "spi.h"
#include "i2c-MMA8652.h"
#include "i2c-EEPROM.h"
#include "radio.h"
#include "sx1276.h"
#include "rtc-board.h"
#include "sx1276-board.h"

#define assert_param(expr) (EFM_ASSERT( expr ))

/*!
 * Generic definition
 */
#ifndef SUCCESS
#define SUCCESS                                     1
#endif

#ifndef FAIL
#define FAIL                                        0
#endif


/*!
 * Board MCU pins definitions
 */
#define RADIO_MOSI                                  PC_9
#define RADIO_MISO                                  PC_11
#define RADIO_SCLK                                  PC_8
#define RADIO_NSS                                   PC_7
#define RADIO_RESET                                 NC

#define RADIO_DIO_0                                 PA_0
#define RADIO_DIO_1                                 PF_4
#define RADIO_DIO_2                                 PF_3
#define RADIO_DIO_3                                 PB_12
#define RADIO_DIO_4                                 PB_11
#define RADIO_DIO_5                                 PB_13

#define RADIO_ANT_SWITCH_TX							NC
#define RADIO_ANT_SWITCH_RX							NC

#define RADIO_ANT_SWITCH_LF							NC
#define RADIO_ANT_SWITCH_HF							NC

#define REJOIN_BTN                                  PD_9

#define ADC_VIN										PA_1

#define GPS_EN										PD_10
#define LORA_EN										PD_11

#define I2C_SCL                                     PD_14
#define I2C_SDA                                     PD_15

#define WAKE_UP										PC_10


/*!
 * LED GPIO pins objects
 */
/*
extern Gpio_t IrqMpl3115;
extern Gpio_t IrqMag3110;
extern Gpio_t GpsPowerEn;
extern Gpio_t NcIoe3;
extern Gpio_t NcIoe4;
extern Gpio_t NcIoe5;
extern Gpio_t NcIoe6;
extern Gpio_t NcIoe7;
extern Gpio_t NIrqSX9500;
extern Gpio_t Irq1Mma8451;
extern Gpio_t Irq2Mma8451;
extern Gpio_t TxEnSX9500;
*/
extern Gpio_t LORA_Enable;
extern Gpio_t GPS_Enable;
extern Gpio_t Rejoin_Btn;
extern Gpio_t Pb0;
extern Gpio_t Pb1;

extern void WakeUp_ISR(void);
/*!
 * Debug GPIO pins objects
 */
/*
#if defined( USE_DEBUG_PINS )
extern Gpio_t DbgPin1;
extern Gpio_t DbgPin2;
extern Gpio_t DbgPin3;
extern Gpio_t DbgPin4;
extern Gpio_t DbgPin5;
#endif
*/


/*
extern Gpio_t GpsPps;
extern Gpio_t GpsRx;
extern Gpio_t GpsTx;
*/
enum BoardPowerSource
{
    USB_POWER = 0,
    BATTERY_POWER
};

void BoardReadRegVersion(uint8_t * data);

/*!
 * \brief Disbale interrupts
 *
 * \remark IRQ nesting is managed
 */
void BoardDisableIrq( void );

/*!
 * \brief Enable interrupts
 *
 * \remark IRQ nesting is managed
 */
void BoardEnableIrq( void );

/*!
 * \brief Initializes the target board peripherals.
 */
void BoardInitMcu( void );

/*!
 * \brief Initializes the boards peripherals.
 */
void BoardInitPeriph( void );

/*!
 * \brief Initializes the boards wakeup.
 */
void WakeupInit( void );

/*!
 * \brief Get the current battery level
 *
 * \retval value  battery level ( 0: very low, 254: fully charged )
 */
uint8_t BoardGetBatteryLevel( void );

/*!
 * Returns a pseudo random seed generated using the MCU Unique ID
 *
 * \retval seed Generated pseudo random seed
 */
uint32_t BoardGetRandomSeed( void );

/*!
 * \brief Gets the board 64 bits unique ID
 *
 * \param [IN] id Pointer to an array that will contain the Unique ID
 */
void BoardGetUniqueId( uint8_t *id );

/*!
 * \brief Get the board power source
 *
 * \retval value  power source ( 0: USB_POWER,  1: BATTERY_POWER )
 */
uint8_t GetBoardPowerSource( void );

void WakeUp_ISR() __attribute__ ((weak));

#endif // __BOARD_H__
