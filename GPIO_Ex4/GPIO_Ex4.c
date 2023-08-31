/*
 * GPIO_Ex4.c
 *
 *  Created on: Aug 31, 2023
 *      Author: adham
 */

/*
 * GPIO_Ex3.c
 *
 *  Created on: Aug 30, 2023
 *      Author: adham
 */
#include "avr/io.h"
#include "util/delay.h"

void setBit(unsigned char *x, unsigned char bitNumber);
void clearBit(unsigned char *x, unsigned char bitNumber);
void toggleBit(unsigned char *x, unsigned char bitNumber);
unsigned char checkBit(unsigned char *x, unsigned char bitNumber);

int main(void) {
	clearBit(&DDRB, 0);
	setBit(&PORTB, 0);

	setBit(&DDRC, 0);
	setBit(&PORTC, 0);

	while (1) {
		if (checkBit(&PINB, 0)) {
			_delay_ms(30);
			if (!checkBit(&PINB, 0)) {
				toggleBit(&PORTC, 0);
				while (!checkBit(&PINB, 0))
					;
			}

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
