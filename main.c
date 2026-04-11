#include <rtc.h>
#include "stm32f411xe.h"
#include "oled.h"
#include "i2c.h"
#include "gpio.h"
#include "buzzer.h"
#include "button.h"
#include "servo.h"
#include "key.h"
#include <stdio.h>

void delay_ms(uint32_t ms)
{
    for(uint32_t i=0;i<ms*4000;i++)
        __NOP();
}

int main(void)
{
    GPIO_Init();
    I2C1_Init();
    OLED_Init();
    Button_Init();
    Servo_Init();
    Key_Init();
    rtc_init();   // RTC initialization

    uint8_t temp;

    char time_buff[20];

    while(1)
    {
        /* Idle screen */

        OLED_Clear();
        OLED_SetCursor(2,30);
        OLED_Print("SAFE DRIVE");

        OLED_SetCursor(4,30);
        OLED_Print("INSERT KEY");

        /* Wait for joystick key */

        while(!Key_Detected());

        /* LED + buzzer immediately after key insertion */

        Buzzer_On();
        delay_ms(150);
        Buzzer_Off();

        /* ENGINE START */

        OLED_Clear();
        OLED_SetCursor(2,25);
        OLED_Print("ENGINE START");

        for(int i=0;i<4;i++)
        {
            Servo_180();
            delay_ms(250);
        }

        delay_ms(200);

        /* -------- NEW SCREEN -------- */

        OLED_Clear();

        OLED_SetCursor(1,20);
        OLED_Print("STATUS: RUNNING");

        OLED_SetCursor(3,20);
        OLED_Print("THRESHOLD: 39");

        OLED_SetCursor(5,20);
        OLED_Print("TEMP:");

        temp = 25;

        while(temp < 40)
        {
            Servo_180();

            /* update only value */

            OLED_SetCursor(5,60);
            OLED_PrintNum(temp);

            delay_ms(300);

            temp += 2;
        }

        /* -------- OVERHEAT -------- */

        OLED_Clear();

        OLED_SetCursor(1,10);
        OLED_Print("ENGINE OVERHEAT");

        OLED_SetCursor(3,10);
        OLED_Print("SYSTEM SHUTDOWN");

        /* -------- TIMESTAMP -------- */

        uint8_t hour = rtc_convert_bcd2dec(rtc_time_get_hour());
        uint8_t min  = rtc_convert_bcd2dec(rtc_time_get_minute());
        uint8_t sec  = rtc_convert_bcd2dec(rtc_time_get_second());

        sprintf(time_buff,"%02d:%02d:%02d",hour,min,sec);

        OLED_SetCursor(5,30);
        OLED_Print(time_buff);

        /* LED + buzzer stay ON */

        LED_On();
        Buzzer_On();

        /* SYSTEM OFF */

        OLED_SetCursor(7,30);
        OLED_Print("PRESS RESET");

        /* wait restart */

        while(!Button_Pressed());

        LED_Off();
        Buzzer_Off();

        delay_ms(100);
    }
}
