# 📦 Bill of Materials – Portable AC Controller

This document lists all components used in the Portable AC Controller project, including their function, quantity, and packaging. The design is based on the Arduino Nano (SMD) platform and is compatible with standard 0.96" I2C OLED displays.

---

## 🔧 Main Components

| Part Name                    | Reference(s)               | Qty | Package       | Notes                                           |
|-----------------------------|----------------------------|-----|----------------|-------------------------------------------------|
| Arduino Nano (SMD Type)     | U1                         | 1   | SMD            | Main microcontroller                            |
| OLED Display 0.96" 128x64   | DISPLAY                    | 1   | I2C Header     | SSD1306-based I2C display                       |
| Latching Switch (6-pin, sqr)| POWER, AUTO                | 2   | Through Hole   | For power on/off and AC Auto/Manual Selection   |
| Push Button (4-pin, square) | UP, DOWN                   | 2   | Through Hole   | For user setting increase/decrease              |
| Rotary Potentiometer (SMD)  | FAN, AC                    | 2   | SMD            | Analog input for manual blower and AC control   |
| LM35 Temperature Sensor     | TEMP_INT, TEMP_AMB         | 2   | TO-92          | Internal & ambient temperature monitoring       |

---

## 🔌 Power Supply

| Part Name              | Reference | Qty | Package | Notes                                 |
|------------------------|-----------|-----|---------|---------------------------------------|
| 7805 Voltage Regulator | U4        | 1   | D2PAK   | Regulates input to 5V                 |
| Electrolytic Capacitor | C1, C2    | 2   | 0805    | 1µF each for regulator filtering      |

---

## ⚙️ Passive Components

| Part Name         | Reference         | Qty | Package | Notes                                |
|-------------------|------------------|-----|---------|--------------------------------------|
| Resistors 10kΩ    | R6–R8, R10–R12   | 6   | 0805    | Pull-downs / divider for inputs      |
| Indicator LED     | LED              | 1   | SMD     | Status or power indicator            |

---

## 📌 Notes

- This controller is designed for **manual or automatic** AC compressor control using onboard sensors and user inputs.
- Input voltage to the 7805 regulator should be < 35V.
- OLED uses **I2C interface** (SCL/SDA) and requires a 3.3V/5V tolerant supply (SSD1306 compatible).
- The **rotary potentiometers** are connected via voltage dividers for manual analog adjustments.
- **Interrupt-driven push buttons** are debounced in software and allow precise temp setpoint control.
- Always ensure **thermal dissipation** for the 7805 regulator if housed in an enclosure.
- Debug interfaces were dropped to save space.
- The Arduino Nano is socketed on the PCB and can be reprogrammed via USB.

---

**Revision:** 1.0  
**Author:** Lakmal Weerasinghe  
**License:** MIT  
