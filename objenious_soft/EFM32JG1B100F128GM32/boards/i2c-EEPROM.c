/*
 * i2c-EEPROM.c
 *
 *  Created on: March 30, 2018
 *      Author: khiemtt
 */

#include "i2c-EEPROM.h"
#include "em_gpio.h"
#include "delay.h"

int readEepromData (int addrEEPROM, uint8_t addrMemory)
{
	I2C_TransferSeq_TypeDef seq;

	seq.addr = addrEEPROM;

	uint8_t BufSend[1]; //send 2 bytes address memory
	uint8_t BufReceive[1]; //receive 1 byte
	uint8_t temp;

	BufSend[0] = addrMemory;
	seq.buf[0].data = BufSend;
	seq.buf[0].len = 1; //send 2 bytes

	seq.buf[1].data = BufReceive;
	seq.buf[1].len=1; //receive 1 byte

	seq.flags = I2C_FLAG_WRITE_READ;
	I2C_TransferInit(I2C0, &seq);
	int status = I2C_TransferInit(I2C0, &seq);

	DelayMs(10);

	while (status == i2cTransferInProgress){
	  status = I2C_Transfer(I2C0);
	}

	if (status != i2cTransferDone) {
		return((int)status);
	}

	temp = BufReceive[0];
	return temp;
}

int writeEepromData(int addrEEPROM, uint8_t addrMemory, uint8_t val)
{
	I2C_TransferSeq_TypeDef seq;
	seq.addr = addrEEPROM;
	uint8_t BufSend[2]; //send 1 bytes

	BufSend[0] = addrMemory;
	BufSend[1] = val;
	seq.buf[0].data = (uint8_t*)BufSend;
	seq.buf[0].len = 2; //send 2 bytes

	seq.flags = I2C_FLAG_WRITE;
	I2C_TransferInit(I2C0, &seq);
	int status = I2C_TransferInit(I2C0, &seq);

	DelayMs(5);
	while (status == i2cTransferInProgress){

	  status = I2C_Transfer(I2C0);
	}
	DelayMs(10);
	return status;
}
