#include "stm32f411xe.h"
#include "servo.h"

/*
 TIM1 CH1 -> PA8
 PWM:
 50Hz (20ms period)
 1ms = 0°
 1.5ms = 90°
 2ms = 180°
*/

void Servo_Init(void)
{
    /* Enable clocks */
    RCC->AHB1ENR |= (1<<0);   // GPIOA
    RCC->APB2ENR |= (1<<0);   // TIM1

    /* PA8 -> Alternate Function */
    GPIOA->MODER &= ~(3<<(8*2));
    GPIOA->MODER |=  (2<<(8*2));

    /* AF1 (TIM1) */
    GPIOA->AFR[1] &= ~(0xF<<0);
    GPIOA->AFR[1] |=  (1<<0);

    /* Timer base config */
    TIM1->PSC = 16-1;        // 16 MHz /16 = 1 MHz (1us)
    TIM1->ARR = 20000-1;     // 20ms period

    /* PWM mode 1 */
    TIM1->CCMR1 &= ~(7<<4);
    TIM1->CCMR1 |=  (6<<4);

    /* Enable preload */
    TIM1->CCMR1 |= (1<<3);

    /* Enable output */
    TIM1->CCER |= (1<<0);

    /* Main output enable */
    TIM1->BDTR |= (1<<15);

    /* Auto reload preload */
    TIM1->CR1 |= (1<<7);

    /* Start timer */
    TIM1->CR1 |= (1<<0);

    /* Default position */
    Servo_SetAngle(0);
}

/* Core function */
void Servo_SetAngle(uint8_t angle)
{
    if(angle > 180) angle = 180;

    /* 1000us to 2000us */
    uint16_t pulse = 1000 + ((angle * 1000) / 180);

    TIM1->CCR1 = pulse;
}

/* Helper functions */
void Servo_0(void)
{
    Servo_SetAngle(0);
}

void Servo_90(void)
{
    Servo_SetAngle(90);
}

void Servo_180(void)
{
    Servo_SetAngle(180);
}
