#include "dht11.h"

#define DHT_PORT GPIOB
#define DHT_PIN 5

void delay_us(uint32_t us)
{
    for(uint32_t i=0;i<us*16;i++)
        __NOP();
}

void DHT11_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    /* PB5 input */
    DHT_PORT->MODER &= ~(3<<(DHT_PIN*2));
}

static void set_output(void)
{
    DHT_PORT->MODER &= ~(3<<(DHT_PIN*2));
    DHT_PORT->MODER |=  (1<<(DHT_PIN*2));
}

static void set_input(void)
{
    DHT_PORT->MODER &= ~(3<<(DHT_PIN*2));
}

uint8_t DHT11_ReadTemperature(void)
{
    uint8_t data[5] = {0};

    set_output();

    /* start signal */
    DHT_PORT->ODR &= ~(1<<DHT_PIN);

    for(volatile int i=0;i<800000;i++);

    DHT_PORT->ODR |= (1<<DHT_PIN);

    delay_us(40);

    set_input();

    while(DHT_PORT->IDR & (1<<DHT_PIN));
    while(!(DHT_PORT->IDR & (1<<DHT_PIN)));
    while(DHT_PORT->IDR & (1<<DHT_PIN));

    for(int j=0;j<5;j++)
    {
        for(int i=0;i<8;i++)
        {
            while(!(DHT_PORT->IDR & (1<<DHT_PIN)));

            delay_us(40);

            if(DHT_PORT->IDR & (1<<DHT_PIN))
                data[j] |= (1<<(7-i));

            while(DHT_PORT->IDR & (1<<DHT_PIN));
        }
    }

    return data[2];
}
