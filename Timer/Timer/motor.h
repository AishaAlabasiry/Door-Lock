/* -----------------------------------------------------------------------------------------------------
[FILE NAME]: 	< motor.h >
[AUTHOR]: 		< Hossam Sayed Dessouky >
[DATE CREATED]: < /4/2015 >
[DESCRIPTION]: 	<  >
----------------------------------------------------------------------------------------------------- */

#ifndef MOTOR_H_
#define MOTOR_H_

/*--------------------------------------------- INCLUDES ---------------------------------------------*/

#include "dio.h"

/*---------------------------------- Definitions and configurations ----------------------------------*/

#define MOTOR_OFF 0
#define MOTOR_ON 1

#define MOTOR_CLOCK_WISE 2
#define MOTOR_ANTI_CLOCK_WISE 3

#define MOTOR_LEFT_PORT 'C'
#define MOTOR_RIGHT_PORT 'C'

#define MOTOR_LEFT_PIN_NUM 2
#define MOTOR_RIGHT_PIN_NUM 3

/*--------------------------------------- FUNCTION DECLARATIONS --------------------------------------*/

void MOTOR_init(void);

void MOTOR_setOFF(void);

void MOTOR_clockWise(void);

void MOTOR_antiClockWise(void);

uint8 MOTOR_status(void);

#endif /* MOTOR_H_ */