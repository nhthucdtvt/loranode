/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech
Description: Board ADC driver implementation
License: Revised BSD License, see LICENSE.TXT file include in the project
Maintainer: Andreas Pella (IMST GmbH), Miguel Luis and Gregory Cristian
*/
#include "board.h"
#include "adc-board.h"
#include "em_adc.h"

/*!
 * Calibration Data Bytes base address for medium density devices
 */
#define FACTORY_TSCALIB_BASE                        ( ( uint32_t )0x1FF80078 )
#define PDDADC_AVG_SLOPE                            1610 // 1.61 * 1000
#define PDDADC_OVERSAMPLE_FACTOR                    0x04

void AdcMcuInit( Adc_t *obj, PinNames adcInput )
{
	assert_param( FAIL );
}

uint16_t AdcMcuRead()
{
	ADC_Start(ADC0, adcStartSingle);
	/* Wait while conversion is active */
	while (ADC0->STATUS & ADC_STATUS_SINGLEACT) ;
	/* Get ADC result */
	return ADC_DataSingleGet(ADC0);

}
