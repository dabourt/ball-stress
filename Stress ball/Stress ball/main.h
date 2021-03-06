#ifndef MAIN_H
#define MAIN_H

/*******************************************************************************************/
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
/*******************************************************************************************/

/******************************* To control the switch state *******************************/
#define Button_State (PINB & (1<<PB0))
/*******************************************************************************************/

/************************************ Functions For LED ************************************/
#define LED_ON()(PORTD |= (1<<PD0))
#define LED_OFF()(PORTD &= ~(1<<PD0))
/*******************************************************************************************/

/************************************ States of switch *************************************/
#define Closed 0
#define Open 1
/*******************************************************************************************/
void LED_DelayWhenBOpen(void);
void LED_DelayWhenBClosed(void);
void Pressure_LongCheckwhenBOpen(void);

#endif