/*
 * buzzer.h
 *
 *  Created on: Mar 11, 2026
 *      Author: jeffin
 */

#ifndef BUZZER_H
#define BUZZER_H

#include "stm32f4xx.h"

#define BUZZER_PIN 13

void Buzzer_Init(void);
void Buzzer_On(void);
void Buzzer_Off(void);
void Buzzer_Toggle(void);

#endif
