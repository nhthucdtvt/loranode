/*
 * i2c-MMA8652.h
 *
 *  Created on: Dec 18, 2017
 *      Author: trungnh
 */

#ifndef I2C_MMA8652_H_
#define I2C_MMA8652_H_

#include "mma8652_regs.h"
#include "stdbool.h"
#include "em_i2c.h"

/**
 * MACROS
 */
enum{
	FAIL	= 0,
	SUCCESS = 1
};

// Enable double-pulse detection on each axis
#define enableDoubleTapInt(sens)  enableTapInt(sens, true)
// Read interrupt source register (see MMA8652FC datasheet, p. 28)
#define readIntSource()  MMA8652_RegisterGet(MMA8652_INT_SOURCE)
// Read portrait/landscape status register (see MMA8652FC datasheet, p. 32)
#define readPlStatus()  MMA8652_RegisterGet(MMA8652_PL_STATUS)
// Read pulse source register (see MMA8652FC datasheet, p. 45)
#define readPulseSource()  MMA8652_RegisterGet(MMA8652_PULSE_SRC)
// Read free-fall source register (see MMA8652FC datasheet, p. 36)
#define readFreeFallSource()  MMA8652_RegisterGet(MMA8652_FF_MT_SRC)
// Read "who am I" register. It should return 0x4A
#define whoAmI() MMA8652_RegisterGet(MMA8652_WHO_AM_I)

void MMA8652_I2CInit(void);
uint8_t MMA8652_RegisterGet(MMA8652_Register_TypeDef reg);
void MMA8652_RegisterSet(MMA8652_Register_TypeDef reg, int8_t val);

void enableInt(uint8_t source);
void disableInt(uint8_t source);

void enableTapInt(uint8_t sensibility, bool doubleTap);
void disableTapInt(void);
void clearFlagTapInt(void);

void enableFreeFallInt(uint8_t sensibility);
void disableFreeFallInt(void);
void clearFlagFreeFallInt(void);

/*portrait-landscape*/
void enablePlInt(void);
void disablePlInt(void);
void clearFlagPlInt(void);

void sleep(void);
void active(void);
void standBy(void);

#endif /* I2C_MMA8652_H_ */
