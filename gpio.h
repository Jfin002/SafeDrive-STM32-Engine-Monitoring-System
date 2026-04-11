/*
 * gpio.h
 *
 *  Created on: Mar 11, 2026
 *      Author: jeffin
 */

#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx.h"

#define LED_PIN 12

void GPIO_Init_LED(void);
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);

#endif
