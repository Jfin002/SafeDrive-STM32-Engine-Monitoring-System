# SafeDrive-STM32-Engine-Monitoring-System
SafeDrive is a bare-metal embedded system built on STM32F411 that simulates an intelligent engine monitoring unit. It features real-time temperature tracking, RTC-based timestamp logging, overheat detection, and alert mechanisms using OLED, servo, buzzer, and LED, with a key-based ignition and manual reset system.

# SafeDrive – Engine Heat Monitoring System

## Overview
SafeDrive is an embedded system built using STM32F411 that simulates an engine monitoring system. It detects temperature rise, alerts the user during overheating, and shuts down the system with a timestamp.

---

## Aim of the Project
To design a real-time embedded system that:
- Simulates engine start using a key (joystick)
- Monitors temperature continuously
- Detects overheating conditions
- Triggers alerts (LED + buzzer)
- Logs time of failure using RTC
- Requires manual reset for restart

---

## Components Used

### 🔹 STM32F411VET6

<img width="225" height="225" alt="image" src="https://github.com/user-attachments/assets/422c0853-2825-4e3f-9a90-ebba22e6dc27" />

### 🔹 OLED Display (SSD1306)

<img width="225" height="225" alt="image" src="https://github.com/user-attachments/assets/b6835e59-e203-4c14-9657-ce8871ad412c" />

### 🔹 Servo Motor (SG90)

<img width="255" height="255" alt="image" src="https://github.com/user-attachments/assets/c3b1b84d-f5c1-4465-ac8a-107626fb3270" />

### 🔹 DHT11 Temperature Sensor

<img width="255" height="255" alt="image" src="https://github.com/user-attachments/assets/09707521-22a9-4dc2-adb3-e60a27a019bb" />

### 🔹 Buzzer + LED

<img width="255" height="255" alt="image" src="https://github.com/user-attachments/assets/93eec624-8d65-4a50-9f3d-9da5579bbef9" />
<img width="255" height="255" alt="image" src="https://github.com/user-attachments/assets/0e27209c-7f96-4704-9a21-97ff125aa4bd" />

### 🔹 Push Button & Joystick

<img width="255" height="255" alt="image" src="https://github.com/user-attachments/assets/b14fffaf-6833-49ac-9c31-d643eea40b95" />
<img width="185" height="185" alt="image" src="https://github.com/user-attachments/assets/34800fa0-03a0-4c3f-afec-5c568b4f8662" />

---

## Connections

| Component | Pin |
|----------|-----|
| OLED SDA | PB9 |
| OLED SCL | PB8 |
| Servo Signal | PA8 |
| Buzzer | PD14 |
| LED | PD13 |
| Button | PA0 |
| Joystick (Key) | PA1 |
| DHT11 Data | PA2 |

---

## Hardware Setup
![WhatsApp Image 2026-03-17 at 12 10 06 PM](https://github.com/user-attachments/assets/4f5adc25-a5d0-4f8b-9652-e8cd620a63f7)



---

## Working Principle

1. System powers ON → Displays **SAFE DRIVE**
2. Waits for **key input (joystick)**
3. On key detection:
   - Engine starts
   - Servo rotates
   - LED + buzzer alert briefly
4. Displays:
   - STATUS: RUNNING
   - LIVE TIME (RTC)
   - TEMPERATURE
   - THRESHOLD (39°C)
5. Temperature increases continuously
6. When threshold is crossed:
   - Displays **ENGINE OVERHEAT**
   - Shows timestamp
   - LED + buzzer stay ON
7. System waits for reset button

---

## Implementation Steps

1. GPIO configuration (LED, buzzer, button)
2. I2C setup for OLED
3. OLED driver development
4. PWM setup for servo (TIM1)
5. Key detection using joystick
6. Temperature simulation (DHT11 / random)
7. RTC integration for real-time clock
8. System state machine design
9. Overheat detection logic
10. Final system integration

---

## Challenges Faced

- Servo not working due to insufficient current
- OLED text flickering
- Incorrect font mapping (characters missing)
- RTC time formatting issues
- Button debounce problems
- SPI (RFID) issues (later replaced with joystick)

---

## 📚 References

- STM32F411 Reference Manual : https://www.st.com/resource/en/user_manual/um1842-discovery-kit-with-stm32f411ve-mcu-stmicroelectronics.pdf
- STM32 Datasheet: https://www.st.com/resource/en/datasheet/stm32f205rb.pdf
- SSD1306 Datasheet: http://exploreembedded.com/wiki/images/9/95/SSD1306.pdf
- DHT11 Datasheet: https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf?srsltid=AfmBOoqaGdSG_m4HjdOYV_y310dR5mGL90QWLMglfDEVpES3W4kCQHDe
- ARM Cortex-M4 technical reference manual: https://users.ece.utexas.edu/~valvano/EE345L/Labs/Fall2011/CortexM4_TRM_r0p1.pdf
- Last Minute Engineers site: https://lastminuteengineers.com/

---

## Future Improvements

- Replace DHT11 with more accurate sensor (LM35 / DS18B20)
- Add EEPROM logging for fault history
- Mobile app integration via Bluetooth
- Real vehicle interface (CAN bus)

---

## Author

**Jeffin Paul**  
Embedded Systems Engineer (Aspiring)

---
