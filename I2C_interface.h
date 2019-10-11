/*
 * I2C_interface.h
 *
 *  Created on: Jul 27, 2018
 *      Author: Sedra Frimware
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void I2C_voidInit(void);
void I2C_voidSendStart(void);
void I2C_voidSendStop(void);
void I2C_voidSendSLA_W(u8 SLA);
void I2C_voidSendSLA_R(u8 SLA);
void I2C_voidSendData(u8 Data);
u8 I2C_voidRecieveData(void);
u8 I2C_u8SendCheckStatus(u8 Status);


#endif /* I2C_INTERFACE_H_ */
