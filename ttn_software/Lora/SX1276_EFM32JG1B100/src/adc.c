/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech
Description: Implements a generic ADC driver
License: Revised BSD License, see LICENSE.TXT file include in the project
Maintainer: Miguel Luis and Gregory Cristian
*/

#include "em_adc.h"

/*!
 * Flag to indicates if the ADC is initialized
 */
static bool AdcInitialized = false;

void init_ADC()
{
    if( AdcInitialized == false )
    {
        AdcInitialized = true;

    	ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
    	ADC_InitSingle_TypeDef singleInit = ADC_INITSINGLE_DEFAULT;

    	/* Init common settings for both single conversion and scan mode */
    	init.timebase = ADC_TimebaseCalc(0);

    	/* Might as well finish conversion as quickly as possibly since polling */
    	/* for completion. Set ADC clock to 7 MHz, use default HFPERCLK */
    	init.prescale = ADC_PrescaleCalc(7000000, 0);

    	/* WARMUPMODE must be set to Normal according to ref manual before
    	 * entering EM2. In this example, the warmup time is not a big problem
    	 * due to relatively infrequent polling. Leave at default NORMAL, */
    	ADC_Init(ADC0, &init);

    	/* Init for single conversion use, measure DAC output with 1.25 reference. */
    	singleInit.reference = adcRef2V5;

    	/* DAC otput channel 0 as ADC input */
    	singleInit.posSel = _ADC_SINGLECTRL_NEGSEL_APORT4XCH9;

    	singleInit.resolution = adcRes12Bit;

    	/* The datasheet specifies a minimum aquisition time when sampling vdd/3 */
    	/* 32 cycles should be safe for all ADC clock frequencies */
    	singleInit.acqTime = adcAcqTime32;

    	ADC_InitSingle(ADC0, &singleInit);

    	// $[ADC0_Init]
    	ADC_Init_TypeDef ADC0_init = ADC_INIT_DEFAULT;

    	ADC0_init.ovsRateSel = adcOvsRateSel2;
    	ADC0_init.warmUpMode = adcWarmupNormal;
    	ADC0_init.timebase = ADC_TimebaseCalc(0);
    	ADC0_init.prescale = ADC_PrescaleCalc(7000000, 0);
    	ADC0_init.tailgate = 0;
    	ADC0_init.em2ClockConfig = adcEm2Disabled;

    	ADC_Init(ADC0, &ADC0_init);
    	// [ADC0_Init]$

    	// $[ADC0_InputConfiguration]
    	// [ADC0_InputConfiguration]$
    }
}


uint16_t AdcReadChannel()
{
	ADC_Start(ADC0, adcStartSingle);
		/* Wait while conversion is active */
		while (ADC0->STATUS & ADC_STATUS_SINGLEACT) ;
		/* Get ADC result */
		return ADC_DataSingleGet(ADC0);
}


