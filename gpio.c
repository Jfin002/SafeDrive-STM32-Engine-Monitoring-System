#include "stm32f411xe.h"
#include "gpio.h"

void GPIO_Init(void)
{
    /* Enable clocks */

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    /* LED PD12 */

    GPIOD->MODER &= ~(3<<(12*2));
    GPIOD->MODER |=  (1<<(12*2));

    /* BUZZER PD13 */

    GPIOD->MODER &= ~(3<<(13*2));
    GPIOD->MODER |=  (1<<(13*2));

    /* BUTTON PC13 */

    GPIOC->MODER &= ~(3<<(13*2));

    GPIOC->PUPDR &= ~(3<<(13*2));
    GPIOC->PUPDR |=  (1<<(13*2));
}

void LED_On(void)
{
    GPIOD->ODR |= (1<<12);
}

void LED_Off(void)
{
    GPIOD->ODR &= ~(1<<12);
}
