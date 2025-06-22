# ⚡ Portable AC Controller

[![PlatformIO CI](https://github.com/dondfx/portable-ac-controller/actions/workflows/ci.yml/badge.svg?branch=main)

**Embedded firmware for a portable AC controller** built on an Arduino Nano. Features include user-selectable **manual** and **automatic** operation, SSD1306 OLED display, LM35 temperature sensing, and PID-based temperature regulation—all packaged in a compact, ready-to-build design.

![Final Rendering of the Controller](/hardware/images/FinalRender.JPG)

---

## 🔌 Hardware Overview

- **Microcontroller**: Arduino Nano (ATmega328P, SMD)
- **Display**: 0.96″ SSD1306 OLED (128×64) over I²C
- **Sensors**: Two LM35 analog temperature sensors (internal & ambient)
- **Controls**:
  - Two SMD rotary potentiometers for manual blower and compressor control
  - Two momentary buttons (UP/DOWN) for setting the target temperature
  - A latching switch for Manual/Auto mode selection
- **Outputs**:
  - Blower and compressor controlled via PWM (D6, D5)
  - Condenser blower output always ON (D7)
  - LED indicator (D8) for system status
- **Power**: 15V input regulated to 5V using a 7805 regulator

---

## 📁 Project Structure

```
portable-ac-controller/
├── .vscode/                 # VSCode settings
├── hardware/                # Hardware resources
│   ├── docs/
│   │   └── wiring_diagram.pdf          # High-level wiring diagram
│   ├── gerbers/
│   │   └── portable-ac-controller.ZIP  # Fabrication-ready Gerber files
│   └── images/
│       ├── FinalRender.JPG          # PCB 3D render
│       └── PCB.PNG                  # PCB layout top view
│
├── include/                # Header files
│   ├── ControlLogic.h
│   ├── DisplayManager.h
│   ├── Pins.h
│   └── TempSensors.h
│
├── lib/                    # Libraries
│
├── src/                    # Source files
│   ├── ControlLogic.cpp
│   ├── DisplayManager.cpp
│   ├── main.cpp
│   └── TempSensors.cpp
│
├── .gitignore
├── BOM.md                 # Full bill of materials
├── CONTRIBUTING.md        # Contribution guide
├── LICENSE                # MIT license
├── platformio.ini         # PlatformIO build config
└── README.md              # Project overview
```

---

## 🛠 Features

- **AUTO mode**: Maintain internal temperature using PID control
- **MANUAL mode**: Independently adjust blower and compressor speeds
- Real-time internal temperature display (large digits)
- Temperature setpoint adjustment (16–27 °C) via buttons
- Interrupt-driven button handling with debouncing
- Clean, modular codebase with independent components

---

## 🔧 Setting Up & Installing

### 1. **Clone the Repo**

```bash
git clone https://github.com/dondfx/portable-ac-controller.git
cd portable-ac-controller
```

### 2. Build & Upload Firmware

Open in PlatformIO IDE or use CLI:

```bash
pio run                             # Build project
pio run -e nanoatmega328 -t upload  # Upload to Arduino Nano
```

### 3. Power On & Test

- Provide 15 V DC to the power input
- Observe LED indicator
- Press buttons, adjust pots, and watch temperature readings

---

## 📘 Documentation & Support

- Bill of Materials: bom.md
- Contributing Guide: contributing.md

Feel free to submit improvements—feature suggestions, code enhancements, or updates to the hardware.

---

## 📝 License

This project is licensed under the MIT License. See LICENSE for details.

---

## 🏷 Topics

arduino ac-controller embedded i2c ssd1306 pid platformio

---

Build, deploy, and stay cool! 😎