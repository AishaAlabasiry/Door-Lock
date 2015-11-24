/* ---------------------------------------------------------------------------------------------------
[FILE NAME]   : led.c
[AUTHOR]      : Aisha Alabasiry
[DATE CREATED]: 21/4/2015
[DESCRIPTION] : led Module
--------------------------------------------------------------------------------------------------- */
/*--------------------------------------------- INCLUDES -----------------------------------------------*/
#include "led.h"
/*------------------------------------------ Global Variables -------------------------------------------*/
/* LED Configurations Structure */
static DIO_config   g_s_ledConfig;
/*------------------------------------- FUNCTION Definitions ----------------------------------------*/

static void LED_configurations(void)
{
	g_s_ledConfig.port = LED_PORT; /* LED Port*/
	g_s_ledConfig.pin_num = LED_PIN_NUM; /* LED PIN Number */
	g_s_ledConfig.direction = OUTPUT; /* LED is OUTPUT */
	g_s_ledConfig.value = LED_OFF; /* initial value */
}
/*********************************************************************************************/
 void LED_init(void)
{
	LED_configurations(); /* fill the g_s_ledConfig structure with the led configurations */
	DIO_setPinDirection(& g_s_ledConfig); /* set the direction of the LED */
	DIO_writePin(& g_s_ledConfig); /* set the Default value (initial value) */
}
/*********************************************************************************************/
void LED_setOn(void)
{
	g_s_ledConfig.value = LED_ON;
	DIO_writePin(& g_s_ledConfig); 
}
/*********************************************************************************************/
void LED_setOff(void)
{
	g_s_ledConfig.value = LED_OFF;
	DIO_writePin(& g_s_ledConfig);
}
/*********************************************************************************************/
void LED_toggle(void)
{
	if(g_s_ledConfig.value == LED_OFF)
	{
		LED_setOn();
	}
	else
	{
		LED_setOff();
	}
}
/*********************************************************************************************/