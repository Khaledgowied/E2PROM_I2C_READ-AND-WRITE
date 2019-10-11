/*
 * main.c
 *
 *  Created on: Jul 28, 2018
 *      Author: Sedra Frimware
 */
#include"../lib/std_types.h"
#include"../lib/macros.h"
#include"LCD_interface.h"
#include"I2C_interface.h"
#include"DIO_interface.h"
#include"EEPROM_interface.h"
#include<util/delay.h>
#include<avr/io.h>
#define F_CPU 12000000

int main (void){
	EEPROM_voidInit();
	LCD_voidInit();

	while(1){ // write

		EEPROM_voidWriteByte(0b10100000, 0,'0');
		_delay_ms(200);
		EEPROM_voidWriteByte(0b10100000, 1,'m');
		_delay_ms(200);

	}




	/* read

	u8 x ;
   x= EEPROM_voidReadByte(0b10100000,0);
   LCD_voidWriteCharachter(x);
   x= EEPROM_voidReadByte(0b10100000,1);
   LCD_voidWriteCharachter(x);


*/
	return 0;
}

