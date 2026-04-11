#include "stm32f411xe.h"

extern uint8_t SPI1_Transfer(uint8_t data);

#define RC522_CS_LOW()  GPIOA->ODR &= ~(1<<4)
#define RC522_CS_HIGH() GPIOA->ODR |=  (1<<4)

uint8_t RC522_Read(uint8_t reg)
{
    uint8_t value;

    RC522_CS_LOW();

    SPI1_Transfer((reg<<1) | 0x80);
    value = SPI1_Transfer(0x00);

    RC522_CS_HIGH();

    return value;
}
