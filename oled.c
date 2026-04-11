#include "oled.h"

/* Send command */
void OLED_Command(uint8_t cmd)
{
    I2C_Write(OLED_ADDR,0x00,cmd);
}

/* Send data */
void OLED_Data(uint8_t data)
{
    I2C_Write(OLED_ADDR,0x40,data);
}

/* Set cursor */
void OLED_SetCursor(uint8_t page,uint8_t column)
{
    OLED_Command(0xB0 + page);
    OLED_Command(0x00 + (column & 0x0F));
    OLED_Command(0x10 + (column >> 4));
}

/* Clear display */
void OLED_Clear(void)
{
    for(uint8_t page=0;page<8;page++)
    {
        OLED_SetCursor(page,0);

        for(uint8_t col=0;col<128;col++)
        {
            OLED_Data(0x00);
        }
    }
}

/* OLED initialization */
void OLED_Init(void)
{
    for(volatile int i=0;i<100000;i++);

    OLED_Command(0xAE);
    OLED_Command(0x20);
    OLED_Command(0x00);
    OLED_Command(0xB0);
    OLED_Command(0xC8);
    OLED_Command(0x00);
    OLED_Command(0x10);
    OLED_Command(0x40);
    OLED_Command(0x81);
    OLED_Command(0xFF);
    OLED_Command(0xA1);
    OLED_Command(0xA6);
    OLED_Command(0xA8);
    OLED_Command(0x3F);
    OLED_Command(0xD3);
    OLED_Command(0x00);
    OLED_Command(0xD5);
    OLED_Command(0xF0);
    OLED_Command(0xD9);
    OLED_Command(0x22);
    OLED_Command(0xDA);
    OLED_Command(0x12);
    OLED_Command(0xDB);
    OLED_Command(0x20);
    OLED_Command(0x8D);
    OLED_Command(0x14);
    OLED_Command(0xAF);
}

/* 5x7 Font Table A-Z */
static const uint8_t font5x7[26][5] =
{
{0x7C,0x12,0x11,0x12,0x7C}, //A
{0x7F,0x49,0x49,0x49,0x36}, //B
{0x3E,0x41,0x41,0x41,0x22}, //C
{0x7F,0x41,0x41,0x22,0x1C}, //D
{0x7F,0x49,0x49,0x49,0x41}, //E
{0x7F,0x09,0x09,0x09,0x01}, //F
{0x3E,0x41,0x49,0x49,0x7A}, //G
{0x7F,0x08,0x08,0x08,0x7F}, //H
{0x41,0x41,0x7F,0x41,0x41}, //I
{0x20,0x40,0x41,0x3F,0x01}, //J
{0x7F,0x08,0x14,0x22,0x41}, //K
{0x7F,0x40,0x40,0x40,0x40}, //L
{0x7F,0x02,0x04,0x02,0x7F}, //M
{0x7F,0x04,0x08,0x10,0x7F}, //N
{0x3E,0x41,0x41,0x41,0x3E}, //O
{0x7F,0x09,0x09,0x09,0x06}, //P
{0x3E,0x41,0x51,0x21,0x5E}, //Q
{0x7F,0x09,0x19,0x29,0x46}, //R
{0x46,0x49,0x49,0x49,0x31}, //S
{0x01,0x01,0x7F,0x01,0x01}, //T
{0x3F,0x40,0x40,0x40,0x3F}, //U
{0x1F,0x20,0x40,0x20,0x1F}, //V
{0x7F,0x20,0x18,0x20,0x7F}, //W
{0x63,0x14,0x08,0x14,0x63}, //X
{0x03,0x04,0x78,0x04,0x03}, //Y
{0x61,0x51,0x49,0x45,0x43}  //Z
};

/* 5x7 Font Table 0-9 */
static const uint8_t fontDigits[10][5] =
{
{0x3E,0x51,0x49,0x45,0x3E}, //0
{0x00,0x42,0x7F,0x40,0x00}, //1
{0x62,0x51,0x49,0x49,0x46}, //2
{0x22,0x49,0x49,0x49,0x36}, //3
{0x18,0x14,0x12,0x7F,0x10}, //4
{0x2F,0x49,0x49,0x49,0x31}, //5
{0x3E,0x49,0x49,0x49,0x32}, //6
{0x01,0x71,0x09,0x05,0x03}, //7
{0x36,0x49,0x49,0x49,0x36}, //8
{0x26,0x49,0x49,0x49,0x3E}  //9

};

/* Draw character */
void OLED_DrawChar(char c)
{
    if(c == ' ')
    {
        for(int i=0;i<6;i++)
            OLED_Data(0x00);
        return;
    }

    /* A-Z */
    if(c >= 'A' && c <= 'Z')
    {
        uint8_t index = c - 'A';

        for(int i=0;i<5;i++)
        {
            OLED_Data(font5x7[index][i]);
        }

        OLED_Data(0x00);
        return;
    }

    /* 0-9 */
    if(c >= '0' && c <= '9')
    {
        uint8_t index = c - '0';

        for(int i=0;i<5;i++)
        {
            OLED_Data(fontDigits[index][i]);
        }

        OLED_Data(0x00);
        return;
    }

    /* Special characters */
    static const uint8_t fontSpecial[3][5] =
    {
    /* : */
    {0x00,0x36,0x36,0x00,0x00},

    /* ; */
    {0x00,0x56,0x36,0x00,0x00},

    /* / */
    {0x20,0x10,0x08,0x04,0x02}
    };

    /* : */
    if(c == ':')
    {
        for(int i=0;i<5;i++)
            OLED_Data(fontSpecial[0][i]);

        OLED_Data(0x00);
        return;
    }

    /* ; */
    if(c == ';')
    {
        for(int i=0;i<5;i++)
            OLED_Data(fontSpecial[1][i]);

        OLED_Data(0x00);
        return;
    }

    /* / */
    if(c == '/')
    {
        for(int i=0;i<5;i++)
            OLED_Data(fontSpecial[2][i]);

        OLED_Data(0x00);
        return;
    }
}

/* Print string */
void OLED_Print(char *str)
{
    while(*str)
    {
        OLED_DrawChar(*str++);
    }
}

void OLED_PrintNum(uint8_t num)
{
    uint8_t digits[3];
    int count = 0;

    if(num >= 100)
    {
        digits[count++] = num / 100;
        num %= 100;
    }

    if(num >= 10)
    {
        digits[count++] = num / 10;
        num %= 10;
    }

    digits[count++] = num;

    for(int d = 0; d < count; d++)
    {
        for(int i = 0; i < 5; i++)
        {
            OLED_Data(fontDigits[digits[d]][i]);
        }

        OLED_Data(0x00);
    }
}
