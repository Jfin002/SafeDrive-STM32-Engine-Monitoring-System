#ifndef SERVO_H
#define SERVO_H

#include "stm32f411xe.h"

void Servo_Init(void);
void Servo_MoveSmooth(uint16_t start,uint16_t end);
void Servo_180(void);

#endif
