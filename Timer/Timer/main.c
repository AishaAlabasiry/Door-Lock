/*
 * Timer.c
 *
 * Created: 4/23/2015 10:55:11 AM
 *  Author: Hossam
 */ 

#include "timer.h"
#include "motor.h"

int main(void)
{
	MOTOR_init();
	DDRA = 0xFF;
	PORTA = 0x00;
	
	sei(); // global interrupt enable 
	//TIMER0_init('r', 2);
	TIMER1_init(1024, 10);
	MOTOR_clockWise();
	
    while(1)
    {
        
    }
}

ISR(TIMER1_COMPA_vect)
{
	if (MOTOR_status() == MOTOR_CLOCK_WISE)
	{
		MOTOR_antiClockWise();
	}
	else if (MOTOR_status() == MOTOR_ANTI_CLOCK_WISE)
	{
		MOTOR_setOFF();
		TIMER1_init(0,10);
	}
	/*if (PINA == 0)
	{
		PORTA = 0xFF;
	}
	else
		PORTA = 0x00;*/
}
/*
ISR(TIMER0_COMP_vect)
{
	if (PINA == 0)
	{
		PORTA = 0xFF;
	}
	else
		PORTA = 0x00;
}
*/
/*
int main(void)
{
	MOTOR_init();
	
	while(1)
	{
		MOTOR_clockWise();
		_delay_ms(1000);
		MOTOR_antiClockWise();
		_delay_ms(1000);
		MOTOR_setOFF();
		_delay_ms(1000);
	}
}
*/