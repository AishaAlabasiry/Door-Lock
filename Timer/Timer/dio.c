/* -----------------------------------------------------------------------------------------------------
[FILE NAME]: 	< dio.c >
[AUTHOR]: 		< Hossam Sayed Dessouky >
[DATE CREATED]: < /4/2015 >
[DESCRIPTION]: 	< This file contains all the functions that deals with the digital input/output ports
				  registers, set the direction of the port, send output to and read input from it >
----------------------------------------------------------------------------------------------------- */

/*--------------------------------------------- INCLUDES ---------------------------------------------*/

#include "dio.h"

/*------------------------------------- FUNCTION Definitions -----------------------------------------*/

/* -----------------------------------------------------------------------------------------------------
[Function Name] : DIO_setDirection
[Description]  :  This function is responsible for setting direction of the selected pin
[Args]   :
[in]			  const DioConfig * a_s_CONFIG_MSG_Ptr :
				  	This argument is the address of an object of the struct DioConfig containing all 
					information about the targeted registers of the hardware
					The received struct will contain :
				  		1. The PORT Which the hardware belongs to 'A' 'B' 'C' or 'D'
				  		2. The number of the pin in the PORT '0 -> 7'
				  		3. The direction of pin 'INPUT' or 'OUTPUT'
				  		4. The value of the pin 'Logic_High' or 'Logic_Low'
[Returns] : 	  (void) This function returns nothing
----------------------------------------------------------------------------------------------------- */
void DIO_setDirection( const DioConfig * a_s_CONFIG_MSG_Ptr )
{
	uint8 * ddr_Ptr;
	/* point to the required DDR Register */
	switch( a_s_CONFIG_MSG_Ptr->port )
	{
		case 'A':
			ddr_Ptr = &DDRA;
			break;
		case 'B':
			ddr_Ptr = &DDRB;
			break;
		case 'C':
			ddr_Ptr = &DDRC;
			break;
		case 'D':
			ddr_Ptr = &DDRD;
			break;		  		  
	}
	if( a_s_CONFIG_MSG_Ptr->direction == INPUT )
	{
		/* clear the corresponding bit in the DDR register to configure it as input pin */
		CLEAR_BIT( *ddr_Ptr , a_s_CONFIG_MSG_Ptr->pinNum );
	}
	else if( a_s_CONFIG_MSG_Ptr->direction == OUTPUT )	
	{
		/* set the corresponding bit in the DDR register to configure it as output pin */
		SET_BIT( *ddr_Ptr , a_s_CONFIG_MSG_Ptr->pinNum );
	}				
}

/* -----------------------------------------------------------------------------------------------------
[Function Name] : DIO_writePin
[Description]  :  This function is responsible for setting output value of the selected port and pin
[Args]   :
[in]			  const DioConfig * a_s_STATE_Ptr :
				  	This argument is the address of an object of the struct DioConfig containing all 
					information about the targeted registers of the hardware
					The received struct will contain :
				  		1. The PORT Which the hardware belongs to 'A' 'B' 'C' or 'D'
				  		2. The number of the pin in the PORT '0 -> 7'
				  		3. The direction of pin 'INPUT' or 'OUTPUT'
				  		4. The value of the pin 'Logic_High' or 'Logic_Low'
[Returns] :		  (void) This function returns nothing
----------------------------------------------------------------------------------------------------- */
void DIO_writePin( const DioConfig * a_s_STATE_Ptr )
{
	uint8 * port_Ptr;
	/* point to the required PORT Register */
	switch(a_s_STATE_Ptr->port)
	{
		case 'A':
			port_Ptr = &PORTA;
			break;
		case 'B':
			port_Ptr = &PORTB;
			break;
		case 'C':
			port_Ptr = &PORTC;
			break;
		case 'D':
			port_Ptr = &PORTD;
			break;	  		  
	}
	if( a_s_STATE_Ptr->value == LOGIC_HIGH )
	{
		/* set the corresponding pin in the PORT register */
		SET_BIT( *port_Ptr , a_s_STATE_Ptr->pinNum );
	}				
    else if( a_s_STATE_Ptr->value == LOGIC_LOW )
	{
		/* clear the corresponding pin in the PORT register */
        CLEAR_BIT( *port_Ptr , a_s_STATE_Ptr->pinNum );
	}		
}

/* -----------------------------------------------------------------------------------------------------
[Function Name] : DIO_readPin
[Description]  :  This function is responsible for reading the input value of the selected port and pin
[Args]   :
[in]			  const DioConfig * a_s_STATE_Ptr :
				  	This argument is the address of an object of the struct DioConfig containing all 
					information about the targeted registers of the hardware
					The received struct will contain :
				  		1. The PORT Which the hardware belongs to 'A' 'B' 'C' or 'D'
				  		2. The number of the pin in the PORT '0 -> 7'
				  		3. The direction of pin 'INPUT' or 'OUTPUT'
				  		4. The value of the pin 'Logic_High' or 'Logic_Low'
[out]			  uint8 output :
					This variable will store the value of the targeted pin
[Returns] :		  output is the value of the targeted pin ( Logic High or Logic Low )
----------------------------------------------------------------------------------------------------- */
uint8 DIO_readPin( const DioConfig * a_s_STATE_Ptr )
{
	uint8 * pin_Ptr;
	uint8 output;
	/* point to the required PORT Register */
	switch( a_s_STATE_Ptr->port )
	{
		case 'A':
			pin_Ptr = &PINA;
			break;
		case 'B':
			pin_Ptr = &PINB;
			break;
		case 'C':
			pin_Ptr = &PINC;
			break;
		case 'D':
			pin_Ptr = &PIND;
			break;			  		  
	}
	/* check if the corresponding bit is set in the PIN register */
	if( BIT_IS_SET( *pin_Ptr , a_s_STATE_Ptr->pinNum ) )
	{ 
		output =  LOGIC_HIGH;
	}
	/* check if the corresponding bit is clear in the PIN register */
	else if( BIT_IS_CLEAR( *pin_Ptr , a_s_STATE_Ptr->pinNum ) )
	{
		output = LOGIC_LOW;
	}
	return output;	
}

/*----------------------------------------------------------------------------------------------------*/