/*
 * rtc.h
 *
 *  Created on: Feb 24, 2026
 *      Author: jeffin
 */

#ifndef INC_RTC_H_
#define INC_RTC_H_

#include <stdint.h>
#include "stm32f4xx.h"

void rtc_init(void);

uint8_t rtc_convert_bcd2dec(uint8_t value);
uint8_t rtc_convert_dec2bcd(uint8_t value);

uint32_t rtc_date_get_day(void);
uint32_t rtc_date_get_year(void);
uint32_t rtc_date_get_month(void);

uint32_t rtc_time_get_second(void);
uint32_t rtc_time_get_minute(void);
uint32_t rtc_time_get_hour(void);

#endif /* INC_RTC_H_ */
