/*******************************************************************************************/
#ifndef LABS_H
#define LABS_H

/*******************************************************************************************/
#ifndef F_CPU
#define F_CPU 1000000UL
#endif
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


#endif
/*******************************************************************************************/