/****************************************************************************************************************************************
 Module      : Flame Sensor
 Name        : flame_sensor.h
 Author      : Salma Hamdy
 Description : Header file for the ATmega32 Flame Sensor driver
 ****************************************************************************************************************************************/

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Flame Sensor HW Ports and Pin Ids */
#define FLAME_PORT_ID                 PORTD_ID
#define FLAME_PIN_ID                  PIN2_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initializes the flame sensor pin direction.
 */
void FlameSensor_init(void);

/*
 * Description :
 * Reads the value from the flame
 */
uint8 FlameSensor_getValue(void);



#endif /* FLAME_SENSOR_H_ */
