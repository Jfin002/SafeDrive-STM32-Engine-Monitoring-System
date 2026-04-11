/*
 * buzzer.c
 *
 *  Created on: Mar 11, 2026
 *      Author: jeffin
 */


#include "buzzer.h"

/* Initialize buzzer GPIO */
void Buzzer_Init(void)
{
    /* Enable GPIOD clock */
	RCC->AHB1ENR |= (1<<3);

    /* Clear mode bits for PD13 */
    GPIOD->MODER &= ~(3U << (BUZZER_PIN * 2));

    /* Set PD13 as output */
    GPIOD->MODER |= (1U << (BUZZER_PIN * 2));
}

/* Turn buzzer ON */
void Buzzer_On(void)
{
    GPIOD->ODR |= (1U << BUZZER_PIN);
}

/* Turn buzzer OFF */
void Buzzer_Off(void)
{
    GPIOD->ODR &= ~(1U << BUZZER_PIN);
}

/* Toggle buzzer */
void Buzzer_Toggle(void)
{
    GPIOD->ODR ^= (1U << BUZZER_PIN);
}
