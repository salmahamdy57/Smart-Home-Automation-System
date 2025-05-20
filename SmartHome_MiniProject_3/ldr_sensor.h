/****************************************************************************************************************************************
 Module      : LDR Sensor
 Name        : ldr_sensor.h
 Author      : Salma Hamdy
 Description : Header file for the ATmega32 LDR Sensor driver
 ****************************************************************************************************************************************/

#ifndef LDR_SENSOR_H_
#define LDR_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LDR_SENSOR_CHANNEL_ID            0
#define LDR_SENSOR_MAX_VOLT_VALUE        2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY   100

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the light intensity from the ADC digital value.
 */
uint8 LDR_getLightIntensity(void);

#endif /* LDR_SENSOR_H_ */
