/*
 * i2c-MMA8652.c
 *
 *  Created on: Dec 18, 2017
 *      Author: trungnh
 */
#include "i2c-MMA8652.h"
#include "em_gpio.h"
#include "delay.h"

void MMA8652_I2CInit(void)
{
	// $[I2C0 I/O setup]
	/* Set up SCL */
	I2C0->ROUTEPEN = I2C0->ROUTEPEN | I2C_ROUTEPEN_SCLPEN;
	I2C0->ROUTELOC0 = (I2C0->ROUTELOC0 & (~_I2C_ROUTELOC0_SCLLOC_MASK))
			| I2C_ROUTELOC0_SCLLOC_LOC21;
	/* Set up SDA */
	I2C0->ROUTEPEN = I2C0->ROUTEPEN | I2C_ROUTEPEN_SDAPEN;
	I2C0->ROUTELOC0 = (I2C0->ROUTELOC0 & (~_I2C_ROUTELOC0_SDALOC_MASK))
			| I2C_ROUTELOC0_SDALOC_LOC23;
	// [I2C0 I/O setup]$

	// $[I2C0 initialization]
	I2C_Init_TypeDef init = I2C_INIT_DEFAULT;

	init.enable = 1;
	init.master = 1;
	init.freq = I2C_FREQ_FAST_MAX;
	init.clhr = i2cClockHLRAsymetric;
	I2C_Init(I2C0, &init);
	// [I2C0 initialization]$
	/* Pin PD14 is configured to Open-drain with pull-up and filter */
	GPIO_PinModeSet(gpioPortD, 14, gpioModeWiredAndPullUpFilter, 0);
	/* Pin PD15 is configured to Open-drain with pull-up and filter */
	GPIO_PinModeSet(gpioPortD, 15, gpioModeWiredAndPullUpFilter, 0);

	// Place MMA8652 in standby mode
	standBy();
	DelayMs(1);
	// Accelerometer range of +/-2g range with 0.244mg/LSB, filter
	MMA8652_RegisterSet(MMA8652_XYZ_DATA_CFG, 0x10);
	DelayMs(1);
	// Enable interrupts - Open-drain output
	// Pulse function interrupt can wake-up system
	// Orientation interrupt can wake-up system
	// Free-fall/motion function interrupt can wake-up system
	MMA8652_RegisterSet(MMA8652_CTRL_REG3, 0x3B);
	DelayMs(1);
//	MMA8652_RegisterSet(MMA8652_TRIG_CFG,0x3C);
	// Enter active mode
	active();
}

/* Reads register
 *   Returns value get
 */
uint8_t MMA8652_RegisterGet(MMA8652_Register_TypeDef reg)
{
	I2C_TransferSeq_TypeDef seq;

	seq.addr = MMA8652_ADDR;

	uint8_t BufSend[1]; //send 1 bytes
	uint8_t BufReceive[1]; //receive 1 byte
	uint8_t temp;

	BufSend[0] = reg;
	seq.buf[0].data = BufSend;
	seq.buf[0].len = 1; //send 1 bytes

	seq.buf[1].data = BufReceive;
	seq.buf[1].len = 1; //receive 1 byte

	seq.flags=I2C_FLAG_WRITE_READ;
	I2C_TransferInit(I2C0, &seq);
	int status= I2C_TransferInit(I2C0, &seq);

	while (status==i2cTransferInProgress){
	  status=I2C_Transfer(I2C0);
	}
	temp = BufReceive[0];
	return temp;
}

/* Write register
 */
void MMA8652_RegisterSet(MMA8652_Register_TypeDef reg, int8_t val)
{
	I2C_TransferSeq_TypeDef seq;
	seq.addr = MMA8652_ADDR;
	uint8_t BufSend[2]; //send 1 bytes

	BufSend[0] = reg;
	BufSend[1] = val;
	seq.buf[0].data = BufSend;
	seq.buf[0].len = 2; //send 2 bytes

	seq.flags=I2C_FLAG_WRITE;
	I2C_TransferInit(I2C0, &seq);
	int status= I2C_TransferInit(I2C0, &seq);

	while (status==i2cTransferInProgress){

	  status=I2C_Transfer(I2C0);
	}
}

/**
 * enableInt
 *
 * Enable interrupt and attach interrupt to output pin
 *
 * @param source Source of interrupt - mask (SRC_ASLP_MASK, SRC_FIFO_MASK, SRC_TRANS_MASK
 *   SRC_LNDPRT_MASK, SRC_PULSE_MASK, SRC_FF_MT_MASK, SRC_DRDY_MASK)
 */
void enableInt(uint8_t source)
{
//	uint8_t reg = MMA8652_RegisterGet(MMA8652_CTRL_REG4);
//	reg |= source;
	MMA8652_RegisterSet(MMA8652_CTRL_REG4, source);
	DelayMs(1);
	MMA8652_RegisterSet(MMA8652_CTRL_REG5, source);
}

void disableInt(uint8_t source)
{
//	uint8_t reg = MMA8652_RegisterGet(MMA8652_CTRL_REG4);
//	reg &= ~source;
	MMA8652_RegisterSet(MMA8652_CTRL_REG4,~source);
	DelayMs(1);
	MMA8652_RegisterSet(MMA8652_CTRL_REG5,~source);
}

/**
 * enableTapInt
 *
 * Enable tap interrupt and attach interrupt to output pin
 *
 * @param sensibility 0 is the highest sensibility, 255 is the lowest
 */
void enableTapInt(uint8_t sensibility, bool doubleTap)
{
  uint8_t cfg;

  // Enter stand-by mode
  standBy();
  DelayMs(1);
  enableInt(SRC_PULSE_MASK);
  DelayMs(1);
  if (doubleTap)
	cfg = 0x2A;
  else
	cfg = 0x15;

  // Enable single pulse detection on each axis
  MMA8652_RegisterSet(MMA8652_PULSE_CFG, cfg);
  DelayMs(1);

  MMA8652_RegisterSet(MMA8652_PULSE_THSX, sensibility);
  DelayMs(1);
  MMA8652_RegisterSet(MMA8652_PULSE_THSY, sensibility);
  DelayMs(1);
  MMA8652_RegisterSet(MMA8652_PULSE_THSZ, sensibility);
  DelayMs(1);

  // Back to active mode
  active();
}

void disableTapInt(void)
{
  // Enter stand-by mode
  standBy();
  DelayMs(1);
  disableInt(SRC_PULSE_MASK);
  DelayMs(1);
  // Disable Portrait/Ladscape orientation detection
  MMA8652_RegisterSet(MMA8652_PULSE_CFG, 0);
  DelayMs(1);
  // Back to active mode
  active();
}

void clearFlagTapInt(void)
{
	MMA8652_RegisterGet(MMA8652_PULSE_SRC);
}
/**
 * enableFreeFallInt
 *
 * Enable free-fall interrupt and attach interrupt to output pin
 *
 * @param sensibility 0 is the highest sensibility, 255 is the lowest
 */
void enableFreeFallInt(uint8_t sensibility)
{
  // Enter stand-by mode
  standBy();
  DelayMs(1);
  enableInt(SRC_FF_MT_MASK);
  DelayMs(1);
  // Enable single pulse detection on each axis
  MMA8652_RegisterSet(MMA8652_FF_MT_CFG, 0xF8); // Motion detection - XYZ events enabled
  DelayMs(1);
  MMA8652_RegisterSet(MMA8652_FF_MT_THS, sensibility);
  DelayMs(1);
  // Back to active mode
  active();
}
void disableFreeFallInt(void)
{
  // Enter stand-by mode
  standBy();
  DelayMs(1);
  disableInt(SRC_FF_MT_MASK);
  DelayMs(1);
  // Disable Portrait/Ladscape orientation detection
  MMA8652_RegisterSet(MMA8652_FF_MT_CFG, 0);
  DelayMs(1);
  // Back to active mode
  active();
}
void clearFlagFreeFallInt(void)
{
	MMA8652_RegisterGet(MMA8652_FF_MT_SRC);
}

/**
 * enablePlInt
 *
 * Enable portrait-landscape orientation interrupt and attach interrupt
 * to output pin
 */
void enablePlInt(void)
{
  // Enter stand-by mode
  standBy();
  DelayMs(1);
  enableInt(SRC_LNDPRT_MASK);
  DelayMs(1);
  // Enable Portrait/Ladscape orientation detection
  MMA8652_RegisterSet(MMA8652_PL_CFG, PL_EN_MASK);
  DelayMs(1);
  // Back to active mode
  active();
}
void disablePlInt(void)
{
  // Enter stand-by mode
  standBy();
  DelayMs(1);
  disableInt(SRC_LNDPRT_MASK);
  DelayMs(1);
  // Disable Portrait/Ladscape orientation detection
  MMA8652_RegisterSet(MMA8652_PL_CFG, 0);
  DelayMs(1);
  // Back to active mode
  active();
}
void clearFlagPlInt(void)
{
	MMA8652_RegisterGet(MMA8652_PL_STATUS);
}

/**
 * sleep
 *
 * Enter sleep mode, ready to be brought back to the active mode by an
 * interrupt
 */
void sleep(void)
{
  if (MMA8652_RegisterGet(MMA8652_CTRL_REG4) && SRC_LNDPRT_MASK)
  {
    // Disable Portrait/Landscape orientation interrupt, which is incompatible
    // With the current sleep mode
    disablePlInt();
    DelayMs(1);
  }

  // Re-enter active mode first
  active();
  DelayMs(2);
  // Enter stand-by mode
  standBy();
  DelayMs(2);
  MMA8652_RegisterSet(MMA8652_ASLP_COUNT, 1);
  DelayMs(2);
  MMA8652_RegisterSet(MMA8652_CTRL_REG2, 0x0C);

  DelayMs(1);
  // Back to active mode
  active();
}

void active(void)
{
	MMA8652_RegisterSet(MMA8652_CTRL_REG1, 0x49);
}

void standBy(void)
{
	MMA8652_RegisterSet(MMA8652_CTRL_REG1, 0);
}
