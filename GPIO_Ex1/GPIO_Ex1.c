/*
 * GPIO_Ex1.c
 *
 *  Created on: Aug 26, 2023
 *      Author: adham
 */


#include "avr/io.h"
#include "util/delay.h"

int main(void){
	DDRB|=1<<0;
	PORTB&=~(1<<0);
	while(1){
		PORTB^=(1<<0);
		_delay_ms(500);
	}
}
