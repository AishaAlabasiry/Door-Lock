#ifndef BUZ_H_
#define BUZ_H_

/*--------------------------------------------- INCLUDES -------------------------------------------*/
#include "std_type.h"
#include "common_macro.h" 

/* Set the buz ON/OFF according to its configuration Positive logic or negative logic */
#define BUZ_ON  LOGIC_HIGH
#define BUZ_OFF LOGIC_LOW

/* Set the BUZ Port */
#define BUZ_PORT 'B'

/* Set the BUZ Pin Number */
#define BUZ_PIN_NUM 1


 /***************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : BUZ_configurations
[Description]   : This function is responsible for Calling by the BUZ_Init function (only) used to fill the buz configurations structure 	
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
static void BUZ_configurations(void);

 /***************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : BUZ_init
[Description]   : This function is responsible for 1. fill the buz configurations structure 
                								   2. set the PIN direction which the buz is connected to OUTPUT
 												   3. Initialize the buz ON/OFF according to the initial value .
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void BUZ_init(void);


/***************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : BUZ_setOn
[Description]   : This function is responsible for Set the BUZ state to ON .
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void BUZ_setOn(void);


/***************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : BUZ_setOff
[Description]   : This function is responsible for Set the BUZ state to OFF .
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void BUZ_setOff(void);











#endif /*buz.h*/