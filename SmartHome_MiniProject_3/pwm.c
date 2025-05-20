/****************************************************************************************************************************************
 Module      : PWM
 Name        : pwm.c
 Author      : Salma Hamdy
 Description : Source file for the ATmega32 PWM driver
 ****************************************************************************************************************************************/

#include "pwm.h"
#include "gpio.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */

/*
 * Description :
 * Function responsible for initialize the PWM driver.
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	OCR0  = (duty_cycle * 255) / 100;                                                 /* Set Compare Value */

	GPIO_setupPinDirection(PWM_OC0_PORT_ID,PWM_OC0_PIN_ID,PIN_OUTPUT);  /* Set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC. */

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00) | (1<<CS02);
}
