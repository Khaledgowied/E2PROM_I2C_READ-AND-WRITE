/*
 * EEPROM_prog.c
 *
 *  Created on: Jul 28, 2018
 *   
 */
#include"../lib/std_types.h"
#include"../lib/macros.h"
#include"I2C_interface.h"
#include"EEPROM_interface.h"
#include<avr/io.h>

void EEPROM_voidInit(void){
	I2C_voidInit();
}

u8 EEPROM_voidWriteByte(u8 Page,u8 Location,u8 Byte){
    I2C_voidSendStart();
    if(I2C_u8SendCheckStatus(0x08)==0){ // table 74 slide 183 (08)->check start FINISHED
    	return;
    }
    I2C_voidSendSLA_W(Page);
    if(I2C_u8SendCheckStatus(0x18)==0){  //(18) -> check SLA FINISHED
        	return;
     }
    I2C_voidSendData(Location);
    if(I2C_u8SendCheckStatus(0x28)==0){  //(28) -> CEHCK  ON DATA
            return;
     }
    I2C_voidSendData(Byte);
    if(I2C_u8SendCheckStatus(0x28)==0){
            	return;
     }
    I2C_voidSendStop();

}
u8 EEPROM_voidReadByte(u8 Page,u8 Location){
u8 x;
I2C_voidSendStart();
if(I2C_u8SendCheckStatus(0x08)==0){
   	return 0;
   }
I2C_voidSendSLA_W(Page);
   if(I2C_u8SendCheckStatus(0x18)==0){
       	return 0;
    }
I2C_voidSendData(Location);
   if(I2C_u8SendCheckStatus(0x28)==0){
         return 0;
    }
I2C_voidSendStart();
if(I2C_u8SendCheckStatus(0x10)==0){ // REPEATED START
     return 0;
   }
I2C_voidSendSLA_R(Page);
if(I2C_u8SendCheckStatus(0x40)==0){ // if want to read
     return 0;
   }
x=I2C_voidRecieveData();
I2C_voidSendStop();
return x;

}
