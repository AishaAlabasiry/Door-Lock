/* -----------------------------------------------------------------------------------------------------
[FILE NAME]: 	< atmega_config.h >
[AUTHOR]: 		< Hossam Sayed Dessouky >
[DATE CREATED]: < 20/1/2015 >
[DESCRIPTION]: 	< This file contains the includes of the Atmega16 and the internal frequency settings >
----------------------------------------------------------------------------------------------------- */


#ifndef ATMEGA_CONFIG_H_
#define ATMEGA_CONFIG_H_

/* Set the frequency of the Atmega to 1MHz */
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/*--------------------------------------------- INCLUDES ---------------------------------------------*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#endif /* ATMEGA_CONFIG_H_ */

/*----------------------------------------------------------------------------------------------------*/