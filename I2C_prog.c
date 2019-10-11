/*
 * I2C_prog.c
 *
 *  Created on: Jul 28, 2018
 *      Author: Sedra Frimware
 */
#include"../lib/std_types.h"
#include"../lib/macros.h"
#include"LCD_interface.h"
#include"I2C_interface.h"
#include"DIO_interface.h"
#include<avr/io.h>

void I2C_voidInit(void){

	TWCR=(1<<2);  //enable I2c
	TWBR=8;
	TWBR=0;
    TWAR=2;      // address

}

void I2C_voidSendStart(void){
	TWCR=(1<<5) |  (1<<2) | (1<<7);
	while(GET_BIT(TWCR,7)==0);
}
void I2C_voidSendStop(void){
	TWCR=(1<<4) | (1<<2) | (1<<7);

}
void I2C_voidSendSLA_W(u8 SLA){

    CLEAR_BIT(SLA,0);
    TWDR=SLA;
	TWCR= (1<<7) | (1<<2);
	while(GET_BIT(TWCR,7)==0);
}
void I2C_voidSendSLA_R(u8 SLA){

    SET_BIT(SLA,0);
    TWDR=SLA;
	TWCR= (1<<7) | (1<<2);
	while(GET_BIT(TWCR,7)==0);
}
void I2C_voidSendData(u8 Data){

    TWDR=Data;
	TWCR= (1<<7) | (1<<2);
	while(GET_BIT(TWCR,7)==0);
}
u8 I2C_voidRecieveData(void){

	TWCR= (1<<7) | (1<<2);
	while(GET_BIT(TWCR,7)==0);

     return TWDR;
}

u8 I2C_u8SendCheckStatus(u8 Status){

    if((TWSR&0xf8)==Status)
    {
    	return 1;

    }else{

    	return 0;
    }
}
