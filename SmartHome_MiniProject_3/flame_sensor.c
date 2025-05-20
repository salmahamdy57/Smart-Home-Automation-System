/****************************************************************************************************************************************
 Module      : Flame Sensor
 Name        : flame_sensor.c
 Author      : Salma Hamdy
 Description : Source file for the ATmega32 Flame Sensor driver
 ****************************************************************************************************************************************/

#include "common_macros.h" /* For GET_BIT Macro */
#include "flame_sensor.h"
#include "gpio.h"

/*
 * Description :
 * Initializes the flame sensor pin direction.
 */
void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_PORT_ID, FLAME_PIN_ID, PIN_INPUT);
}

/*
 * Description :
 * Reads the value from the flame
 */
uint8 FlameSensor_getValue(void)
{
	uint8 flame_value = 0;

	flame_value = GPIO_readPin(FLAME_PORT_ID, FLAME_PIN_ID);

	return flame_value;
}
