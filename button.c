#include "button.h"

void Button_Init(void)
{
    /* Enable GPIOC clock */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    /* PC13 input */
    GPIOC->MODER &= ~(3<<(13*2));

    /* pull-up resistor */
    GPIOC->PUPDR &= ~(3<<(13*2));
    GPIOC->PUPDR |=  (1<<(13*2));
}

static void delay_ms(uint32_t ms)
{
    for(uint32_t i=0;i<ms*4000;i++)
        __NOP();
}

uint8_t Button_Pressed(void)
{
    if(!(GPIOC->IDR & (1<<13)))
    {
        delay_ms(50);

        if(!(GPIOC->IDR & (1<<13)))
        {
            while(!(GPIOC->IDR & (1<<13)));
            return 1;
        }
    }

    return 0;
}
