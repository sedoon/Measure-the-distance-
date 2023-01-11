/*
 ============================================================================
 Name        : Mini_Project4.c
 Author      : SAYED IBRAHIM
 Description : System control fan speed based on the room temperature
 Date        : 02/4/2022
 ============================================================================
 */

#include "../HAL/ULTRASONIC/ultrasonic.h"
#include "../HAL/LCD/lcd.h"
#include "avr/io.h" /* To use the SREG Register */
#include "../MCAL/GIE/GIE.h"


int main(void)
{
	uint16 distance = 0;

	/* Enable Global Interrupt I-Bit */
	GIE_Enable();

	/* Initialize the LCD driver */
	LCD_init();

	/* Initialize the Ultrasonic driver */
	Ultrasonic_init();

	/* Display the distance on LCD screen */
	LCD_moveCursor(0,0);
	LCD_displayString("Distance=   cm ");

	while(1)
	{
		/* Read the distance from the Ultrasonic sensor */
		distance = Ultrasonic_readDistance();

		LCD_moveCursor(0,9);

		if(distance >=100)
		{
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			LCD_displayCharacter(' ');
		}
	}
}
