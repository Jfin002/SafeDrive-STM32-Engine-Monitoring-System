/*
 * I2C.h
 *
 *  Created on: Feb 4, 2026
 *      Author: JEFFIN PAUL
 */

#ifndef __I2C_H
#define __I2C_H

#include "stm32f411xe.h"
#include <stdint.h>

void I2C1_Init(void);
void I2C_Write(uint8_t addr, uint8_t control, uint8_t data);

#endif
