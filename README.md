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

https://cdn1.botland.store/95624-large_default/stm32f411e-disco-discovery-stm32f411e-discovery.jpg


### 🔹 OLED Display (SSD1306)

https://docs.sunfounder.com/projects/elite-explorer-kit/en/latest/_images/oled.png

### 🔹 Servo Motor (SG90)

https://cdn11.bigcommerce.com/s-brqw2bd7p4/images/stencil/1280x1280/products/29375/28666/ELMOTOR.SG90.02-D.MR__63032.1709947494.jpg?c=1


### 🔹 DHT11 Temperature Sensor

https://kernelmasters.com/wp-content/uploads/2025/11/201811131511263384442.jpg


### 🔹 Buzzer + LED

https://europe1.discourse-cdn.com/arduino/original/4X/8/0/c/80cba55c39ab1f531e5c6d3776fc1b37fe743716.jpeg
https://5.imimg.com/data5/SELLER/Default/2022/11/LB/PF/PN/28950456/r1278392-01-1000x1000.jpg


### 🔹 Push Button & Joystick

https://ibots.in/wp-content/uploads/2024/02/z1-7.webp
https://static-01.daraz.com.bd/p/01cca905c820534e2e8ec797954c5134.jpg


---

## 🔌 Connections

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

## 🖼️ Hardware Setup
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/0d331718-65ec-4f52-868a-6b73fbe8ab8e" />


---

## ⚙️ Working Principle

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

## 🛠️ Implementation Steps

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

## ⚠️ Challenges Faced

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

## 💡 Future Improvements

- Replace DHT11 with more accurate sensor (LM35 / DS18B20)
- Add EEPROM logging for fault history
- Mobile app integration via Bluetooth
- Real vehicle interface (CAN bus)

---

## 👨‍💻 Author

**Jeffin Paul**  
Embedded Systems Engineer (Aspiring)

---
