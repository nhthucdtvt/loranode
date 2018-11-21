/*
 * EepromData.c
 *
 *  Created on: Apr 12, 2018
 *      Author: khiemtt
 */

#include "board.h"
#include "EepromData.h"

int joinedChecking()
{
	return readEepromData(addrEeprom, 0);
}

void getStoredNwsKey(uint8_t *result)
{
	for (int i = 0; i < 16; i++) {
		result[i] = readEepromData(addrEeprom, (i+1));
	}
}

void getStoredAppsKey(uint8_t *result)
{
	for (int i = 0; i < 16; i++) {
		result[i] = readEepromData(addrEeprom, (i+17));
	}
}

uint16_t getStoredDevNonce()
{
	uint8_t EepromData[2];
	for (int i = 0; i < 2; i++) {
		EepromData[i] = readEepromData(addrEeprom, (i+33));
	}
	return reverse8BitsArrayTo16(&EepromData);
}

uint32_t getStoredNetID()
{
	uint8_t EepromData[4];
	for (int i = 0; i < 4; i++) {
		EepromData[i] = readEepromData(addrEeprom, (i+35));
	}
	return reverse8BitsArrayTo32(&EepromData);
}

uint32_t getStoredDevAddr()
{
	uint8_t EepromData[4];
	for (int i = 0; i < 4; i++) {
		EepromData[i] = readEepromData(addrEeprom, (i+39));
	}
	return reverse8BitsArrayTo32(&EepromData);
}

uint32_t getStoredUplCounter()
{
	uint8_t EepromData[4];
	for (int i = 0; i < 4; i++) {
		EepromData[i] = readEepromData(addrEeprom, (i+43));
	}
	return reverse8BitsArrayTo32(&EepromData);
}

uint32_t getStoredDownlCounter()
{
	uint8_t EepromData[4];
	for (int i = 0; i < 4; i++) {
		EepromData[i] = readEepromData(addrEeprom, (i+47));
	}
	return reverse8BitsArrayTo32(&EepromData);
}


/****************SET FUNCTION*******************/

void setJoinedChecking()
{
	writeEepromData(addrEeprom, 0, 1);
}

void clearJoinedChecking()
{
	writeEepromData(addrEeprom, 0, 255);
}

void setStoredNwsKey(uint8_t *result)
{
	for (int i = 0; i < 16; i++) {
		writeEepromData(addrEeprom, i+1, result[i]);
	}
}

void setStoredAppsKey(uint8_t *result)
{
	for (int i = 0; i < 16; i++) {
		writeEepromData(addrEeprom, i+17, result[i]);
	}
}

void setStoredDevNonce(uint16_t inputDevNonce)
{
	uint8_t EepromData[2];
	convert16to8(inputDevNonce, &EepromData);
	for (int i = 0; i < 2; i++) {
		writeEepromData(addrEeprom, i+33, EepromData[i]);
	}
}

void setStoredNetID(uint32_t inputNetId)
{
	uint8_t EepromData[4];
	convert32to8(inputNetId, &EepromData);
	for (int i = 0; i < 4; i++) {
		writeEepromData(addrEeprom, i+35, EepromData[i]);
	}
}

void setStoredDevAddr(uint32_t inputDevAddr)
{
	uint8_t EepromData[4];
	convert32to8(inputDevAddr, &EepromData);
	for (int i = 0; i < 4; i++) {
		writeEepromData(addrEeprom, i+39, EepromData[i]);
	}
}

void setStoredUplCounter(uint32_t inputUplCounter)
{
	uint8_t EepromData[4];
	convert32to8(inputUplCounter, &EepromData);
	for (int i = 0; i < 4; i++) {
		writeEepromData(addrEeprom, i+43, EepromData[i]);
	}
}

void setStoredDownlCounter(uint32_t inputDownlCounter)
{
	uint8_t EepromData[4];
	convert32to8(inputDownlCounter, &EepromData);
	for (int i = 0; i < 4; i++) {
		writeEepromData(addrEeprom, i+47, EepromData[i]);
	}
}


void convert32to8 (uint32_t inputNumber, uint8_t *result)
{
	result[0] = inputNumber & 0x000000ff;
	result[1] = (inputNumber & 0x0000ff00) >> 8;
	result[2] = (inputNumber & 0x00ff0000) >> 16;
	result[3] = (inputNumber & 0xff000000) >> 24;
	//result = (uint8_t*)inputNumber;
}

void convert16to8 (uint16_t inputNumber, uint8_t *result)
{
	result[0] = inputNumber & 0x00ff;
	result[1] = (inputNumber & 0xff00) >> 8;
}

uint32_t reverse8BitsArrayTo32 (uint8_t *inputArray)
{
	return ((inputArray[3] & 0xffffffff) << 24) | ((inputArray[2] & 0xffffffff) << 16) | ((inputArray[1] & 0xffffffff) << 8) | (inputArray[0] & 0xffffffff);
}

uint16_t reverse8BitsArrayTo16 (uint8_t *inputArray)
{
	return ((inputArray[1] & 0xffff) << 8) | (inputArray[0] & 0xffff);
}


