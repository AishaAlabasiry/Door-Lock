/* ---------------------------------------------------------------------------------------------------
[FILE NAME]   : buz.c
[AUTHOR]      : Aisha Alabasiry
[DATE CREATED]: 21/4/2015
[DESCRIPTION] : buz Module
--------------------------------------------------------------------------------------------------- */
/*--------------------------------------------- INCLUDES -----------------------------------------------*/
#include "buz.h"
/*------------------------------------------ Global Variables -------------------------------------------*/
/* BUZ Configurations Structure */
static DIO_config   g_s_buzConfig;
/*------------------------------------- FUNCTION Definitions ----------------------------------------*/

static void BUZ_configurations(void)
{
	g_s_buzConfig.port = BUZ_PORT; /* BUZ Port*/
	g_s_buzConfig.pin_num = BUZ_PIN_NUM; /* BUZ PIN Number */
	g_s_buzConfig.direction = OUTPUT; /* BUZ is OUTPUT */
	g_s_buzConfig.value = BUZ_OFF; /* initial value */
}
/*********************************************************************************************/
 void BUZ_init(void)
{
	BUZ_configurations(); /* fill the g_s_buzConfig structure with the buz configurations */
	DIO_setPinDirection(& g_s_buzConfig); /* set the direction of the BUZ */
	DIO_writePin(& g_s_buzConfig); /* set the Default value (initial value) */
}
/*********************************************************************************************/
void BUZ_setOn(void)
{
	g_s_buzConfig.value = BUZ_ON;
	DIO_writePin(& g_s_buzConfig); 
}
/*********************************************************************************************/
void BUZ_setOff(void)
{
	g_s_buzConfig.value = BUZ_OFF;
	DIO_writePin(& g_s_buzConfig);
}
/*********************************************************************************************/
