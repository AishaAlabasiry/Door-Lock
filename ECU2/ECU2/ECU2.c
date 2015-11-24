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
#include "UART.h"
#include "External_EEPROM.h"
#define BUZZER		0
#define MOTOR_CW	0
#define MOTOR_ACW	1

uint8 ECU2_IsNewPasswrd(uint8 startAddress);

uint8 Passwrd[5]; // From ECU1
uint8 sysPasswrd[5]; // Saved Password 
uint8 isPassTrue = 1;
uint8 isNewPasswrd = 1;

const uint8 eepromAddress = 0x0315;

/*------------------------------------------ main function ----------------------------------------*/
int main(void)
{
	uint8 i;
	uint8 usrOption;
	
	DDRB |= (1<<BUZZER);
	PORTB &= ~(1<<BUZZER);
	
	DDRA |= (1<<MOTOR_CW) | (1<<MOTOR_ACW);
	PORTA &= ~((1<<MOTOR_CW) | (1<<MOTOR_ACW));
	
	UART_init();
	EEPROM_Init();
	_delay_ms(500);
	
	// Check if it's first time to enter password or not and send the result to ECU1
	UART_sendByte(ECU2_IsNewPasswrd(eepromAddress));
	
	if (isNewPasswrd==1) // 1st time to enter password
	{
		for (i=0;i<5;i++)
		{
			sysPasswrd[i] = UART_recieveByte();
			EEPROM_Write_Byte(eepromAddress+i, sysPasswrd[i]);
			_delay_ms(50);
		}
	} 
	else // Password Exist
	{
		_delay_ms(200);
	}
	
	// Get password in both cases
	ECU2_getPassFromEEPROM();
	
	while(1)
	{
			usrOption = UART_recieveByte();
			switch(usrOption)
			{
				case 'C': // MCU1 Need to check for password
					for (i=0; i<5; i++)
					{
						Passwrd[i] = UART_recieveByte();
					}
					ECU2_checkPass();
					UART_sendByte(isPassTrue);
					break;
				case 'S':
					for (i=0; i<5; i++)
					{
						sysPasswrd[i] = UART_recieveByte();
					}
					for (i=0; i<5; i++)
					{
						EEPROM_Write_Byte(eepromAddress+i, sysPasswrd[i]);
						_delay_ms(50);
					}
					break;
				case 'G': // ECU1 needs the saved password
					ECU2_getPassFromEEPROM();
					for (i=0; i<5; i++)
					{
						 UART_sendByte(sysPasswrd[i]);
					}
					break;
				case 'U': // ECU1 needs to open the door
					PORTA |= (1<<MOTOR_CW);
					PORTA &= ~(1<<MOTOR_ACW);
					break;
				case 'L': // ECU1 needs to close the door
					PORTA &= ~(1<<MOTOR_CW);
					PORTA |= (1<<MOTOR_ACW);
					break;
				case 'M': // ECU1 needs to stop the motor
					PORTA |= (1<<MOTOR_CW);
					PORTA |= (1<<MOTOR_ACW);
					break;
				case 'F':
					PORTB |= (1<<BUZZER);
					break;
			}
	}
	
	return 0;
}

uint8 ECU2_IsNewPasswrd(uint8 startAddress)
{
	EEPROM_Read_Byte(startAddress, &Passwrd[0]);
	if (Passwrd[0]==255)
		isNewPasswrd = 1;
	else
		isNewPasswrd = 0;
		
	return isNewPasswrd;
}

void ECU2_getPassFromEEPROM()
{
	uint8 i;
	for (i=0;i<5;i++)
	{
		EEPROM_Read_Byte(eepromAddress+i, &sysPasswrd[i]);
		_delay_ms(50);
	}
}

void ECU2_checkPass()
{
	uint8 i;
	for (i=0;i<5;i++)
	{
		if (sysPasswrd[i] != Passwrd[i])
		{
			isPassTrue = 0;
			break;
		}
		else
			isPassTrue = 1;
		
		_delay_ms(50);
	}
}