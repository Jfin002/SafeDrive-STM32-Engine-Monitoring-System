#ifndef DHT11_H
#define DHT11_H

#include "stm32f411xe.h"
#include <stdint.h>

void DHT11_Init(void);
uint8_t DHT11_ReadTemperature(void);

#endif
