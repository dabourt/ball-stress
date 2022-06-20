/*
 * Stress ball.c
 *
 * Created: 3/16/2022 12:18:13 AM
 * Author : DABOUR
 */ 

#include "main.h"

int Test ;

int main(void)
{
	DDRA &= ~(1<<PA0);
	PORTA |= (1<<PA0);

	DDRB &= ~(1<<PB0);
	PORTB |= (1<<PB0);

	DDRD |= (1<<PD0);
	
    while (1) 
    {
		while(Button_State == Closed)
		{
			if ((PINA & (1<<PA0))==0)
			{
				LED_ON();
				LED_DelayWhenBClosed();
				LED_OFF();
			}
		}
		while(Button_State == Open)
		{
			if((PINA & (1<<PA0))==Closed)
			{	
				Pressure_LongCheckwhenBOpen();
				if (Test == 1)
				{
					LED_ON();
					LED_DelayWhenBOpen();
					LED_OFF();
				}
			}
		}
    }
}
