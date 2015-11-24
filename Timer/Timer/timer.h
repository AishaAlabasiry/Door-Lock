/* -----------------------------------------------------------------------------------------------------
[FILE NAME]: 	< timer.h >
[AUTHOR]: 		< Hossam Sayed Dessouky >
[DATE CREATED]: < 23/4/2015 >
[DESCRIPTION]: 	< timer Module header file >
----------------------------------------------------------------------------------------------------- */

#ifndef TIMER_H_
#define TIMER_H_

/*--------------------------------------------- INCLUDES ---------------------------------------------*/

#include "types.h"

/*---------------------------------- Definitions and configurations ----------------------------------*/

#define NORMAL 0
#define PWM 1
#define CTC 2
#define FAST_PWM 3

#define TIMER0_TYPE NORMAL

#define TIMER2_TYPE NORMAL

/*--------------------------------------- FUNCTION DECLARATIONS --------------------------------------*/

 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : TIMER0_init
[Description]   : This function is responsible for :	1. Initialize Timer0 HW Driver to run in CTC Mode 
 													    2. Set the Compare Register Value to generate interrupt every Tick_Time ms.
[Args]		    : uint16 a_prescaler, uint8 a_compare
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void TIMER0_init(uint16 a_prescaler, uint8 a_compare);

 
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : TIMER1_init
[Description]   : This function is responsible for :	1. Initialize Timer1 HW Driver to run in CTC Mode 
 													    2. Set the Compare Register Value to generate interrupt every Tick_Time ms.
[Args]		    : uint16 a_prescaler, uint16 a_compare
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void TIMER1_init(uint16 a_prescaler, uint16 a_compare);

 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : TIMER2_init
[Description]   : This function is responsible for :	1. Initialize Timer2 HW Driver to run in CTC Mode 
 													    2. Set the Compare Register Value to generate interrupt every Tick_Time ms.
[Args]		    : uint16 a_prescaler, uint16 a_compare
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void TIMER2_init(uint16 a_prescaler, uint16 a_compare);

#endif /* TIMER_H_ */