/*
 * ECU1.c
 *
 * Created: 3/10/2015 5:27:12 PM
 *  Author: Ayman
 */ 

/* --------------------------------------------------------------------------------------------------
[FILE NAME]: <lcd_test_app.c, EmbeddedC_Project2_Ayman_Younis>
[AUTHOR(S)]: <Ayman Younis>
[DATE CREATED]: <6/1/2015>
[DESCRIPTION]: <This file contains the source main functions that test the lcd module>
-------------------------------------------------------------------------------------------------- */

/*--------------------------------------------- INCLUDES ------------------------------------------*/
#include "lcd.h"
#include "keypad.h"
#include "UART.h"

/*------------------------------------------ main function ----------------------------------------*/
uint8 Passwrd[5]; // Password from user "used when user enter New one or request service"
uint8 userOption; // get key from user *, #

uint8 isPassTrue = 0;
uint8 falseTryingFlag = 3;

int main(void)
{
	/* initialize the lcd */
	LCD_init(LCD_CURSOR_OFF);
	UART_init();
	_delay_ms(50);
	
	ECU1_checkIfPassExist();
	
	while(1)
	{
		LCD_clearScreen();
		LCD_displayString("Door is Locked!");
		LCD_displayStringRowColumn(1,0,"#:Change *:Open");
		userOption = KeyPad_getPressedKey();
		
		switch(userOption)
		{
			case '#':
				LCD_clearScreen();
				LCD_displayString("Plz Enter Current");
				LCD_displayStringRowColumn(1,2,"Pass: ");
				_delay_ms(200);
				ECU1_getPass();
				UART_sendByte('C'); // Let ECU2 know that I want to check
				ECU1_sendPassToMCU2();
				isPassTrue = UART_recieveByte();
				if (isPassTrue==1)
				{
					falseTryingFlag=3;
					LCD_clearScreen();
					LCD_displayString("Valid, Enter New");
					LCD_displayStringRowColumn(1,2,"Pass: ");
					_delay_ms(200);
					ECU1_getPass();
					UART_sendByte('S'); // Let ECU2 know that I want to save new password
					_delay_ms(100);
					ECU1_sendPassToMCU2();
					LCD_clearScreen();
					LCD_displayString("PASSWORD SAVED!");
					LCD_goToRowColumn(1,4);
					ECU1_displayPass();
					_delay_ms(500);
				}
				else if (isPassTrue==0)
				{
					falseTryingFlag--;
					if (falseTryingFlag==0)
					{
						falseTryingFlag=3;
						LCD_clearScreen();
						LCD_displayString("  Invalid...!");
						UART_sendByte('F');
						_delay_ms(200);
					}
					else
					{
						LCD_clearScreen();
						LCD_displayString("Invalid!, You've");
						LCD_goToRowColumn(1,0);
						LCD_displayNumber(falseTryingFlag, 10);
						LCD_displayString(" More Tries!");
						_delay_ms(500);
					}
				}
				break;
			case '*':
				LCD_clearScreen();
				LCD_displayString("Plz Enter Current");
				LCD_displayStringRowColumn(1,2,"Pass: ");
				_delay_ms(200);
				ECU1_getPass();
				UART_sendByte('C'); // Let ECU2 know that I want to check
				ECU1_sendPassToMCU2();
				isPassTrue = UART_recieveByte();
				if (isPassTrue==1)
				{
					falseTryingFlag=3;
					LCD_clearScreen();
					UART_sendByte('U');
					LCD_displayString("Valid!, MOTOR IS");
					LCD_displayStringRowColumn(1,0," UNLOCKING..");
					_delay_ms(5000);
					UART_sendByte('L');
					LCD_clearScreen();
					LCD_displayString("Done, MOTOR IS");
					LCD_displayStringRowColumn(1,0," LOCKING..");
					_delay_ms(5000);
					UART_sendByte('M');
				}
				else if (isPassTrue==0)
				{
					falseTryingFlag--;
					if (falseTryingFlag==0)
					{
						falseTryingFlag=3;
						LCD_clearScreen();
						LCD_displayString("  Invalid...!");
						UART_sendByte('F');
						_delay_ms(200);
					}
					else
					{
						LCD_clearScreen();
						LCD_displayString("Invalid!, You've");
						LCD_goToRowColumn(1,0);
						LCD_displayNumber(falseTryingFlag, 10);
						LCD_displayString(" More Tries!");
						_delay_ms(500);
					}
				}
				break;
			default:
				LCD_clearScreen();
				LCD_displayString("Invalid Option!");
				_delay_ms(500);
				break;
		}
	}
}

// This function get pass from user
void ECU1_getPass()
{
	uint8 i;
	for (i=0; i<5; i++)
	{
		Passwrd[i] = KeyPad_getPressedKey();
		 		
		if (Passwrd[i]== '*' || Passwrd[i]== '#')
			LCD_displayCharacter(Passwrd[i]);
		else
 			LCD_displayNumber(Passwrd[i], 10);

		_delay_ms(100);
		LCD_sendCommand(LCD_MOVE_CURSOR_LEFT);
		LCD_displayCharacter('*');
		_delay_ms(100);
	}
}

void ECU1_sendPassToMCU2()
{
	uint8 i;
	_delay_ms(200);
	for (i=0; i<5; i++)
	{
		UART_sendByte(Passwrd[i]);
		_delay_ms(100);
	}
}

void ECU1_getPassFromMCU2()
{
	uint8 i;
	UART_sendByte('G');
	_delay_ms(100);
	for (i=0; i<5; i++)
	{
		Passwrd[i] = UART_recieveByte();
	}
}

void ECU1_displayPass()
{
	uint8 i;
	ECU1_getPassFromMCU2();
	for(i=0;i<5;i++)
	{
		if (Passwrd[i]== '*' || Passwrd[i]== '#')
			LCD_displayCharacter(Passwrd[i]);
		else
			LCD_displayNumber(Passwrd[i], 10);
	}
}

void ECU1_checkIfPassExist()
{
	uint8 isNewPasswrd;
	isNewPasswrd = UART_recieveByte();
	if (isNewPasswrd==1)	// 1st time initializing!
	{
		LCD_clearScreen();
		LCD_displayString("Hello Mr. Ayman!");
		_delay_ms(500);
		LCD_clearScreen();
		LCD_displayString("Initializing Ur");
		LCD_displayStringRowColumn(1,4,"Pass: ");
		_delay_ms(200);
		ECU1_getPass();
		ECU1_sendPassToMCU2();
	}
	else if(isNewPasswrd==0)
	{
		LCD_clearScreen();
		LCD_displayString("  Welcome back");
		LCD_displayStringRowColumn(1,0,"   Mr. Ayman! ");
	}
}