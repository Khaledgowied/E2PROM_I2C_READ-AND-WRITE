/*
 * EEPROM_interface.h
 *
 *  Created on: Jul 28, 2018
 *      
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidWriteByte(u8 Page,u8 Location,u8 Byte);
void EEPROM_voidInit(void);
u8 EEPROM_voidReadByte(u8 Page,u8 Location);

#endif /* EEPROM_INTERFACE_H_ */
