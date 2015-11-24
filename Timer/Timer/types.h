/* -----------------------------------------------------------------------------------------------------
[FILE NAME]: 	< types.h >
[AUTHOR]: 		< Hossam Sayed Dessouky >
[DATE CREATED]: < 20/1/2015 >
[DESCRIPTION]: 	< This file contains the definitions for all the data types used during the program >
----------------------------------------------------------------------------------------------------- */


#ifndef TYPES_H_
#define TYPES_H_

/*--------------------------------------------- INCLUDES ---------------------------------------------*/

#include "atmega_config.h"

/*---------------------------------- Definitions and configurations ----------------------------------*/

/* define an unsigned 8 bit (1 byte) integer from an unsigned character */
typedef unsigned char uint8;

/* define a signed 8 bit (1 byte) integer from a signed character */
typedef signed char sint8;

/* define an unsigned 16 bit (2 byte) integer from an unsigned short */
typedef unsigned short uint16;

/* define a signed 16 bit (2 byte) integer from a signed short */
typedef signed short sint16;

/* define an unsigned 32 bit (4 byte) integer from an unsigned long */
typedef unsigned long uint32;

/* define a signed 32 bit (4 byte) integer from a signed long */
typedef signed long sint32;

#endif /* TYPES_H_ */

/*----------------------------------------------------------------------------------------------------*/