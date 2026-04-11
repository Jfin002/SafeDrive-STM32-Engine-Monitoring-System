#include "key.h"

void Key_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    GPIOC->MODER &= ~(3<<(0*2));

    GPIOC->PUPDR &= ~(3<<(0*2));
    GPIOC->PUPDR |= (1<<(0*2));
}

uint8_t Key_Detected(void)
{
    if(!(GPIOC->IDR & (1<<0)))
        return 1;
    else
        return 0;
}
