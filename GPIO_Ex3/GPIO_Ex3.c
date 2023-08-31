/*
 * GPIO_Ex3.c
 *
 *  Created on: Aug 30, 2023
 *      Author: adham
 */
#include "avr/io.h"
void setBit(unsigned char *x, unsigned char bitNumber);
void clearBit(unsigned char *x, unsigned char bitNumber);
void toggleBit(unsigned char *x, unsigned char bitNumber);
unsigned char checkBit(unsigned char *x, unsigned char bitNumber);

int main(void) {
	clearBit(&DDRB, 0);
	clearBit(&DDRB, 1);
	setBit(&DDRC, 0);
	setBit(&DDRC, 1);
	setBit(&PORTC, 0);
	setBit(&PORTC, 1);

	while (1) {
		if (checkBit(&PINB, 0)) {
			clearBit(&PORTC, 0);

		} else {
			setBit(&PORTC, 0);
		}
		if (checkBit(&PINB, 1)) {
			clearBit(&PORTC, 1);

		} else {
			setBit(&PORTC, 1);
		}
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
