/*
 * UART.h
 *
 * Created: 2/19/2014 8:08:52 PM
 *  Author: Mohamed Tarek
 */  


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

// #define U2X				1
// #define RXEN				4
// #define TXEN				3


void UART_init(void);

void UART_sendByte(const char data);

char UART_recieveByte(void);

void UART_sendString(const char *Str);

void UART_receiveString(char *Str); // Receive until #

#endif /* UART_H_ */