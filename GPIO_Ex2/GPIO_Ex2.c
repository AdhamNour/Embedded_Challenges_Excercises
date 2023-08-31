/*
 * GPIO_Ex2.c
 *
 *  Created on: Aug 29, 2023
 *      Author: adham
 */

#include "avr/io.h"
#include "util/delay.h"

void setBit(unsigned char *x, unsigned char bitNumber);
void clearBit(unsigned char *x, unsigned char bitNumber);
void toggleBit(unsigned char *x, unsigned char bitNumber);
unsigned char checkBit(unsigned char *x, unsigned char bitNumber);

int main(void) {
	setBit(&PORTC, 2);
	clearBit(&PORTC, 2);
	while (1) {
		toggleBit(&PORTC, 2);
		_delay_ms(250);
		toggleBit(&PORTC, 2);
		_delay_ms(750);
	}
}

void setBit(unsigned char *x, unsigned char bitNumber) {
	(*x) |= (1 << bitNumber);
}

void clearBit(unsigned char *x, unsigned char bitNumber) {
	(*x) &= ~(1 << bitNumber);
}
void toggleBit(unsigned char *x, unsigned char bitNumber) {
	(*x) ^= (1 << bitNumber);
}
unsigned char checkBit(unsigned char *x, unsigned char bitNumber) {
	return (*x) & (1 << bitNumber);
}
