/*
 * motor.c
 *
 * Created: 4/24/2015 9:50:54 AM
 *  Author: Hossam
 */ 

/*--------------------------------------------- INCLUDES ---------------------------------------------*/

#include "motor.h"

/*----------------------------------------- Global Variables -----------------------------------------*/

static DioConfig g_s_leftMotorConfig;
static DioConfig g_s_rightMotorConfig;

/*------------------------------------- FUNCTION Definitions -----------------------------------------*/

static void MOTOR_configurations(void)
{
	g_s_leftMotorConfig.port		= MOTOR_LEFT_PORT;
	g_s_rightMotorConfig.port		= MOTOR_RIGHT_PORT;
	
	g_s_leftMotorConfig.pinNum		= MOTOR_LEFT_PIN_NUM;
	g_s_rightMotorConfig.pinNum		= MOTOR_RIGHT_PIN_NUM;
	
	g_s_leftMotorConfig.direction	= OUTPUT;
	g_s_rightMotorConfig.direction	= OUTPUT;
	
	g_s_leftMotorConfig.value		= MOTOR_OFF;
	g_s_rightMotorConfig.value		= MOTOR_OFF;
}

void MOTOR_init(void)
{
	MOTOR_configurations();
	
	DIO_setDirection(& g_s_leftMotorConfig);
	DIO_setDirection(& g_s_rightMotorConfig);
	
	DIO_writePin(& g_s_leftMotorConfig);
	DIO_writePin(& g_s_rightMotorConfig);
}

void MOTOR_setOFF(void)
{
	g_s_leftMotorConfig.value =	MOTOR_OFF;
	g_s_rightMotorConfig.value = MOTOR_OFF;
	
	DIO_writePin(& g_s_leftMotorConfig);
	DIO_writePin(& g_s_rightMotorConfig);
}

void MOTOR_clockWise(void)
{
	g_s_leftMotorConfig.value =	MOTOR_ON;
	g_s_rightMotorConfig.value = MOTOR_OFF;
	
	DIO_writePin(& g_s_leftMotorConfig);
	DIO_writePin(& g_s_rightMotorConfig);
}

void MOTOR_antiClockWise(void)
{
	g_s_leftMotorConfig.value =	MOTOR_OFF;
	g_s_rightMotorConfig.value = MOTOR_ON;
	
	DIO_writePin(& g_s_leftMotorConfig);
	DIO_writePin(& g_s_rightMotorConfig);
}

uint8 MOTOR_status(void)
{
	if (g_s_leftMotorConfig.value)
	{
		return MOTOR_CLOCK_WISE;
	}
	else if (g_s_rightMotorConfig.value)
	{
		return MOTOR_ANTI_CLOCK_WISE;
	}
	else
		return MOTOR_OFF;
}