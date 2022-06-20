#include "labs.h"

extern int Test;

void LED_DelayWhenBClosed(void)
{
	TCNT1  = 0x0BDC;										// contain of TCNT = 3036 to reach at 65563 at 4 sec by CLK pre-scaler 64.
	TCCR1A = 0x00;
	TCCR1B = 0x03;											// 64 Pre-scaler ,normal mode ,T1

	while(((TIFR&(1<<TOV1))==0) & (Button_State == Closed)) // wait 4 sec if the button is closed
	{
		if ((PINA & (1<<PA0))==0)							// If the pressure applied again --> reset the timer.
		{
			TCNT1  = 0x0BDC;
		}
	}
	TCCR1B = 0x00;											// stop timer1
	TIFR |= (1<<TOV1);										// clear TOV1
}

/****** if the the button closed when this delay is runing return to the normal state ******/
void LED_DelayWhenBOpen(void)
{
	TCNT1  = 0x0BDC;
	TCCR1A = 0x00;
	TCCR1B = 0x03;

	while((TIFR&(1<<TOV1))==0)
	{
		if((Button_State == Closed) & ((PINA & (1<<PA0))==0))
		{
			LED_DelayWhenBClosed();
			TCCR1B = 0x00;
			TIFR |= (1<<TOV1);
			return;
		}
	}
	TCCR1B = 0x00;
	TIFR |= (1<<TOV1);
}

/*This function used to check the press time if achieve the target the Led become on */
void Pressure_LongCheckwhenBOpen(void)
{
	TCNT1  = 0x0BDC;
	TCCR1A = 0x00;
	TCCR1B = 0x03;

	while((TIFR & (1<<TOV1))==0)
	{
		if((PINA & (1<<PA0))==Open)
		{
			Test = 0;
			TCCR1B = 0x00;
			TIFR |= (1<<TOV1);

			return;
		}
	}
	TCCR1B = 0x00;
	TIFR |= (1<<TOV1);
	Test = 1;
}
