/*
 * i2c-EEPROM.h
 *
 *  Created on: March 30, 2018
 *      Author: khiemtt
 */
#ifndef I2C_EEPROM_H_
#define I2C_EEPROM_H_

#include "stdbool.h"
#include "em_i2c.h"
#include "em_gpio.h"

#define addrEeprom 0x50 << 1

int readEepromData (int addrEEPROM, uint8_t addrMemory);
int writeEepromData(int addrEEPROM, uint8_t addrMemory, uint8_t val);

#endif /* I2C_EEPROM_H_ */
