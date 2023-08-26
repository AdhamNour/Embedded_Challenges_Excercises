/*
 * GPIO_Ex1.c
 *
 *  Created on: Aug 26, 2023
 *      Author: adham
 */

#include "avr/io.h"
#include "util/delay.h"

void setBit(unsigned char *x, unsigned char bitNumber);
void clearBit(unsigned char *x, unsigned char bitNumber);
void toggleBit(unsigned char *x, unsigned char bitNumber);
unsigned char checkBit(unsigned char *x,unsigned char bitNumber);

int main(void) {
	setBit(&DDRC, DDC1); //seting the pin zero as output pin
	clearBit(&PORTC, PC1); // initial output to be zero
	clearBit(&DDRD,DDD2);// setting the second pin to be input pin

	while (1) {
		if(!checkBit(&PIND,PIND2)){
			setBit(&PORTC, PC1);
		}
		else{
			clearBit(&PORTC, PC1);
		}
	}
}
void setBit(unsigned char *x, unsigned char bitNumber){
	(*x)|=(1<<bitNumber);
}

void clearBit(unsigned char *x, unsigned char bitNumber){
	(*x)&=~(1<<bitNumber);
}
void toggleBit(unsigned char *x, unsigned char bitNumber){
	(*x)^=(1<<bitNumber);
}
unsigned char checkBit(unsigned char *x,unsigned char bitNumber){
	return (*x)&(1<<bitNumber);
}
