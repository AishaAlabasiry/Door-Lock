#ifndef LED_H_
#define LED_H_

/*--------------------------------------------- INCLUDES -------------------------------------------*/
#include "std_type.h"
#include "common_macro.h"

/* Set the led ON/OFF according to its configuration Positive logic or negative logic */
#define LED_ON  LOGIC_HIGH
#define LED_OFF LOGIC_LOW

/* Set the LED Port */
#define LED_PORT 'B'

/* Set the LED Pin Number */
#define LED_PIN_NUM 0

 /***************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LED_configurations
[Description]   : This function is responsible for Calling by the LED_Init function (only) used to fill the led configurations structure 	
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
static void LED_configurations(void);

 /***************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LED_init
[Description]   : This function is responsible for 1. fill the led configurations structure 
                								   2. set the PIN direction which the led is connected to OUTPUT
 												   3. Initialize the led ON/OFF according to the initial value .
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void LED_init(void);


/***************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LED_setOn
[Description]   : This function is responsible for Set the LED state to ON .
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void LED_setOn(void);


/***************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LED_setOff
[Description]   : This function is responsible for Set the LED state to OFF .
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void LED_setOff(void);

#endif /*led.h*/