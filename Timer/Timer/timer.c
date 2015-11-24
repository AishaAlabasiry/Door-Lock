/* -----------------------------------------------------------------------------------------------------
[FILE NAME]: 	< timer.c >
[AUTHOR]: 		< Hossam Sayed Dessouky >
[DATE CREATED]: < 23/4/2015 >
[DESCRIPTION]: 	< Timer Module >
----------------------------------------------------------------------------------------------------- */

/*--------------------------------------------- INCLUDES ---------------------------------------------*/

#include "timer.h"

/*------------------------------------- FUNCTION Definitions -----------------------------------------*/

/* -----------------------------------------------------------------------------------------------------
[Function Name] : TIMER0_init
[Description]   : This function is responsible for :	1. Initialize Timer0 HW Driver to run in CTC Mode 
 													    2. Set the Compare Register Value to generate interrupt every Tick_Time ms.
[Args]		    : uint16 a_prescaler, uint8 a_compare
[Returns] 		: This return shall indicate void	
----------------------------------------------------------------------------------------------------- */
void TIMER0_init(uint16 a_prescaler, uint8 a_compare) 
{
	
	#if (TIMER0_TYPE == NORMAL)
		TCCR0 |= (1<<FOC0); /*  non-PWM mode Force Output Compare */
		TCCR0 &= ~(1<<WGM01 | 1<<WGM00); /* Normal mode operation */
	#elif (TIMER0_TYPE == PWM)
		TCCR0 &= ~(1<<FOC0 | 1<<WGM01); /* operating in PWM mode, PWM, Phase Correct */
		TCCR0 |= (1<<WGM00);
	#elif (TIMER0_TYPE == CTC)
		TCCR0 |= (1<<FOC0 | 1<<WGM01); /* non-PWM mode, CTC */
		TCCR0 &= ~(1<<WGM00);
	#elif (TIMER0_TYPE == FAST_PWM)
		TCCR0 &= ~(1<<FOC0); /* operating in PWM mode */
		TCCR0 |= (1<<WGM01 | 1<<WGM00); /* Fast PWM */
	#endif
	
	TCCR0 &= ~(1<<COM01 | 1<<COM00); /* Normal port operation, OC0 disconnected */
	
	switch(a_prescaler)
	{
		case 1:
			TCCR0 &= ~(1<<CS02 | 1<<CS01); /* clk/256 (From prescaler) */
			TCCR0 |= (1<<CS00);
			break;
		case 8:
			TCCR0 &= ~(1<<CS02 | 1<<CS00); /* clk/8 (From prescaler) */
			TCCR0 |= (1<<CS01);
			break;
		case 64:
			TCCR0 &= ~(1<<CS02); /* clk/64 (From prescaler) */
			TCCR0 |= (1<<CS01 | 1<<CS00);  
			break;
		case 256:
			TCCR0 &= ~(1<<CS01 | 1<<CS00); /* clk ((No prescaling) */
			TCCR0 |= (1<<CS02);
			break;
		case 1024:
			TCCR0 &= ~(1<<CS01);  /* clk/1024 (From prescaler) */
			TCCR0 |= (1<<CS02 | 1<<CS00);
			break;
		case 'f':
			TCCR0 &= ~(1<<CS00); /* External clock source on T0 pin. Clock on falling edge */
			TCCR0 |= (1<<CS02 | 1<<CS01);
			break;
		case 'r':
			TCCR0 |= (1<<CS02 | 1<<CS01 | 1<<CS00); /* External clock source on T0 pin. Clock on rising edge */
			break;
		default:
			TCCR0 &= ~(1<<CS02 | 1<<CS01 | 1<<CS00); /* No clock source (Timer/Counter stopped) */
	}
	
	TCNT0 = 0; 
	OCR0 = a_compare;
	TIMSK |= (1<<OCIE0); /*  Compare Match Interrupt Enable */
}

/* -----------------------------------------------------------------------------------------------------
[Function Name] : 	TIMER1_init
[Description]   : This function is responsible for :	1. Initialize Timer1 HW Driver to run in CTC Mode 
 													    2. Set the Compare Register Value to generate interrupt every Tick_Time ms.
[Args]		    : uint16 a_prescaler, uint16 a_compare
[Returns] 		: This return shall indicate void
----------------------------------------------------------------------------------------------------- */
void TIMER1_init(uint16 a_prescaler, uint16 a_compare)
{
	uint32 clocksNo = 0;
	DDRD |= (1<<PD5); /* set pin PD5 as an output pin */
	PORTD &= ~(1<<PD5); /* timer is dissabled at first */
	
	TCCR1A |= (1<<COM1A1); /*  Compare Output Mode for Channel A */
	TCCR1A &= ~(1<<COM1A0); 
	
	TCCR1A |= (1<<FOC1A); /* Force Output Compare for Channel A */
	
	TCCR1A &= ~(1<<WGM11 | 1<<WGM10); /*  Waveform Generation for CTC Mode */
	TCCR1B |= (1<<WGM12); 
	TCCR1B &= ~(1<<WGM13);
	
	switch(a_prescaler)
	{
		case 1:
			TCCR1B &= ~(1<<CS12 | 1<<CS11);
			TCCR1B |= (1<<CS10);
			clocksNo = F_CPU;
			break;
		case 8:
			TCCR1B &= ~(1<<CS12 | 1<<CS10);
			TCCR1B |= (1<<CS11);
			clocksNo = (F_CPU / 8);
			break;
		case 64:
			TCCR1B &= ~(1<<CS12);
			TCCR1B |= (1<<CS11 | 1<<CS10);
			clocksNo = (F_CPU / 64);
			break;
		case 256:
			TCCR1B &= ~(1<<CS11 | 1<<CS10);
			TCCR1B |= (1<<CS12);
			clocksNo = (F_CPU / 256);
			break;
		case 1024:
			TCCR1B &= ~(1<<CS11);
			TCCR1B |= (1<<CS12 | 1<<CS10);
			clocksNo = (F_CPU / 1024);
			break;
		default:
			TCCR1B &= ~(1<<CS12 | 1<<CS11 | 1<<CS10);
	}
	TCNT1 = 0;
	OCR1A = a_compare * clocksNo;
	TIMSK |= (1<<OCIE1A);
}

/* -----------------------------------------------------------------------------------------------------
[Function Name] : 	TIMER2_init
[Description]   : This function is responsible for :	1. Initialize Timer2 HW Driver to run in CTC Mode 
 													    2. Set the Compare Register Value to generate interrupt every Tick_Time ms.
[Args]		    : uint16 a_prescaler, uint16 a_compare
[Returns] 		: This return shall indicate void
----------------------------------------------------------------------------------------------------- */
void TIMER2_init(uint16 a_prescaler, uint16 a_compare)
{	
	#if (TIMER2_TYPE == NORMAL)
		TCCR2 |= (1<<FOC2);  /*  non-PWM mode Force Output Compare */
		TCCR2 &= ~(1<<WGM21 | 1<<WGM20);  /* Normal mode operation */
	#elif (TIMER2_TYPE == PWM)
		TCCR2 &= ~(1<<FOC2 | 1<<WGM21); /* operating in PWM mode, PWM, Phase Correct */
		TCCR2 |= (1<<WGM20);
	#elif (TIMER2_TYPE == CTC)
		TCCR2 |= (1<<FOC2 | 1<<WGM21); /* non-PWM mode, CTC */
		TCCR2 &= ~(1<<WGM20);
	#elif (TIMER0_TYPE == FAST_PWM)
		TCCR2 &= ~(1<<FOC2); /* operating in PWM mode */
		TCCR2 |= (1<<WGM21 | 1<<WGM20); /* Fast PWM */
	#endif
	
	TCCR2 &= ~(1<<COM21 | 1<<COM20);
	
	switch(a_prescaler)
	{
		case 1:
			TCCR2 &= ~(1<<CS22 | 1<<CS21);
			TCCR2 |= (1<<CS20);
			break;
		case 8:
			TCCR2 &= ~(1<<CS22 | 1<<CS20);
			TCCR2 |= (1<<CS21);
			break;
		case 32:
			TCCR2 &= ~(1<<CS22);
			TCCR2 |= (1<<CS21 | 1<<CS20);
			break;
		case 64:
			TCCR2 |= (1<<CS22);
			TCCR2 &= ~(1<<CS21 | 1<<CS20);
			break;
		case 128:
			TCCR2 &= ~(1<<CS21);
			TCCR2 |= (1<<CS22 | 1<<CS20);
			break;
		case 256:
			TCCR2 |= (1<<CS21 | 1<<CS22);
			TCCR2 &= ~(1<<CS20);
			break;
		case 1024:
			TCCR2 |= (1<<CS22 | 1<<CS21 | 1<<CS20);
			break;
		default:
			TCCR2 &= ~(1<<CS22 | 1<<CS21 | 1<<CS20);
	}
	
	TCNT2 = 0;
	OCR2 = a_compare;
	TIMSK |= (1<<OCIE2);
}