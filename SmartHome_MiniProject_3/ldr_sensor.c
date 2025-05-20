/****************************************************************************************************************************************
 Module      : LDR Sensor
 Name        : ldr_sensor.c
 Author      : Salma Hamdy
 Description : Source file for the ATmega32 LDR Sensor driver
 ****************************************************************************************************************************************/

#include "ldr_sensor.h"
#include "adc.h"

/*
 * Description :
 * Function responsible for calculate the light intensity from the ADC digital value.
 */
uint8 LDR_getLightIntensity(void)
{
	uint8 light_intensity_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	light_intensity_value = (uint8)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

	return light_intensity_value;
}
