#include "i2c.h"

void I2C1_Init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    /* PB8 SCL , PB9 SDA */

    GPIOB->MODER &= ~((3U<<(8*2)) | (3U<<(9*2)));
    GPIOB->MODER |=  ((2U<<(8*2)) | (2U<<(9*2)));

    GPIOB->AFR[1] &= ~((0xF<<0) | (0xF<<4));
    GPIOB->AFR[1] |=  ((4U<<0) | (4U<<4));

    GPIOB->OTYPER |= (1U<<8) | (1U<<9);
    GPIOB->PUPDR  |= (1U<<(8*2)) | (1U<<(9*2));

    I2C1->CR2   = 16;
    I2C1->CCR   = 80;
    I2C1->TRISE = 17;

    I2C1->CR1 |= I2C_CR1_PE;
}

void I2C_Write(uint8_t addr, uint8_t control, uint8_t data)
{
    while(I2C1->SR2 & I2C_SR2_BUSY);

    I2C1->CR1 |= I2C_CR1_START;

    while(!(I2C1->SR1 & I2C_SR1_SB));

    I2C1->DR = addr;

    while(!(I2C1->SR1 & I2C_SR1_ADDR));

    (void)I2C1->SR2;

    I2C1->DR = control;

    while(!(I2C1->SR1 & I2C_SR1_TXE));

    I2C1->DR = data;

    while(!(I2C1->SR1 & I2C_SR1_BTF));

    I2C1->CR1 |= I2C_CR1_STOP;
}
