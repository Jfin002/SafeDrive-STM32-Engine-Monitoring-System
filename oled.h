#ifndef __OLED_H
#define __OLED_H

#include "i2c.h"
#include <stdint.h>

#define OLED_ADDR (0x3C << 1)

void OLED_Init(void);
void OLED_Command(uint8_t cmd);
void OLED_Data(uint8_t data);
void OLED_SetCursor(uint8_t page, uint8_t column);
void OLED_Clear(void);
void OLED_DrawChar(char c);
void OLED_Print(char *str);
void OLED_PrintNum(uint8_t num);

#endif
