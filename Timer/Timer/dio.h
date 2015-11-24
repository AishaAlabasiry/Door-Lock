/* -----------------------------------------------------------------------------------------------------
[FILE NAME]: 	< dio.h >
[AUTHOR]: 		< Hossam Sayed Dessouky >
[DATE CREATED]: < /4/2015 >
[DESCRIPTION]: 	< This file contains the prototypes of the functions in the "dio.c" file and the declaration
				  of the structure DioConfig that configures the registers direction and values >
----------------------------------------------------------------------------------------------------- */

#ifndef DIO_H_
#define DIO_H_

/*--------------------------------------------- INCLUDES ---------------------------------------------*/

#include "types.h"
#include "macros.h"

/*---------------------------------- Definitions and configurations ----------------------------------*/

/* Define the input direction to 0 and the output direction to 1 */
#define INPUT 0
#define OUTPUT 1

/* Define the logic high value to 1 and logic low value to 0 */
#define LOGIC_HIGH 1
#define LOGIC_LOW 0

/*-------------------------------------- Structures and Unions ---------------------------------------*/

/* -----------------------------------------------------------------------------------------------------
Structure Name]: DioConfig
[Structure Description]:
		This structure is responsible for configuring the port name and pin number, direction and value
----------------------------------------------------------------------------------------------------- */
typedef struct 
{
	/* (port) contains a character that specifies which port the hardware belongs to 'A' 'B' 'C' or 'D' */
	uint8 port;
	/* (pinNum) contains the number of the pin in the PORT '1 -> 7' */
	uint8 pinNum;
	/* (direction) contains the direction of pin 'INPUT' or 'OUTPUT' */
	uint8 direction;
	/* (value) contains the value of the pin 'LOGIC_HIGH' or 'LOGIC_LOW' */
	uint8 value;
}DioConfig;

/*--------------------------------------- FUNCTION DECLARATIONS --------------------------------------*/

/* configure the pin to input or output pin */
void DIO_setDirection(const DioConfig * a_s_CONFIG_MSG_Ptr );

/* write 1 or 0 on the pin */
void DIO_writePin(const DioConfig * a_s_STATE_Ptr);

/* read the pin */
uint8 DIO_readPin(const DioConfig * a_s_STATE_Ptr);

#endif /* DIO_H_ */

/*----------------------------------------------------------------------------------------------------*/