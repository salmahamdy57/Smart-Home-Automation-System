/****************************************************************************************************************************************
 Name        : main.c
 Author      : Salma Hamdy
 Description : Smart Home Automation Using ATmega32, LCD, Temperature Sensor, LDR Sensor, Flame Sensor and Motor Control
 ****************************************************************************************************************************************/

#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include "dc_motor.h"
#include "flame_sensor.h"
#include "lm35_sensor.h"
#include "ldr_sensor.h"
#include "adc.h"


int main(void)
{

	uint8 light_intensity = 0;
	uint8 temperature = 0;
	//uint8 flame_sensor = 0;

	LCD_init();
	ADC_init();
	LEDS_init();
	DcMotor_Init();
	FlameSensor_init();
	Buzzer_init();

	while(1)
	{
		/*********************************************************** LCD Display ********************************************************************/
		LCD_moveCursor(0,3);
		LCD_displayString("FAN IS ");

		LCD_moveCursor(1,0);
		LCD_displayString("TEMP=");
		LCD_intgerToString(temperature);

		LCD_displayString(" LDR=");
		LCD_intgerToString(light_intensity);
		LCD_displayString("%  ");

		/************************************************** Automatic Lighting Control **************************************************************/
		light_intensity = LDR_getLightIntensity();

		if(light_intensity <= 15)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
		}
		else if(light_intensity >= 16 && light_intensity <= 50)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_off(LED_BLUE);
		}
		else if(light_intensity >= 51 && light_intensity <= 70)
		{
			LED_on(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
		}
		else if(light_intensity > 70)
		{
			LED_off(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
		}

		/************************************************** Automatic Fan Speed Control **************************************************************/
		temperature = LM35_getTemperature();
		LCD_moveCursor(0,10);
		if(temperature >= 40)
		{
			DcMotor_Rotate(Clockwise,100);
			LCD_displayString("ON ");
		}
		else if(temperature >= 35 && temperature < 40)
		{
			DcMotor_Rotate(Clockwise,75);
			LCD_displayString("ON ");
		}
		else if(temperature >= 30 && temperature < 35)
		{
			DcMotor_Rotate(Clockwise,50);
			LCD_displayString("ON ");
		}
		else if(temperature >= 25 && temperature < 30)
		{
			DcMotor_Rotate(Clockwise,25);
			LCD_displayString("ON ");
		}
		else if(temperature < 25)
		{
			DcMotor_Rotate(Stop,0);
			LCD_displayString("OFF");
		}

		/************************************************** Fire Detection and Alert **************************************************************/
		if(FlameSensor_getValue())
		{
			LCD_clearScreen();
			LCD_displayString("Critical Alert!");
			Buzzer_on();
			while (FlameSensor_getValue());
			LCD_clearScreen();
			Buzzer_off();
			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS ");

			LCD_moveCursor(1,0);
			LCD_displayString("TEMP=");
			LCD_intgerToString(temperature);

			LCD_displayString(" LDR=");
			LCD_intgerToString(light_intensity);
			LCD_displayString("%  ");
		}
	}

	return 0;
}
