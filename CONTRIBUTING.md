# Contributing to Portable AC Controller Firmware ❄️🔧

Thanks for your interest in contributing! This is a modular Arduino-based firmware project for a portable air conditioner controller running on an **Arduino Nano (ATmega328P)**.

While this is primarily a solo-built embedded project, contributions are welcome under the following guidelines:

---

## 🛠 How to Contribute

### 1. Fork the Repo

Click the **Fork** button at the top-right of this page to create your own copy.

### 2. Clone Your Fork

```bash
git clone https://github.com/your-username/portable-ac-controller.git
cd portable-ac-controller
```

### 3. Create a New Branch

```bash
git checkout -b feature/your-feature-name
```

### 4. Make Your Changes

Please follow the existing structure in src/, keep naming consistent, and add professional inline comments.

### 5. Test Your Changes

Ensure the firmware still builds:

```bash
platformio run
```

If you have access to hardware or Proteus simulation, verify functionality manually.

### 6. Push and Create a Pull Request

```bash
git push origin feature/your-feature-name
```

Then, open a pull request (PR) against the main branch.

✨ Contribution Scope

Examples of meaningful contributions:

- 🔧 Bug fixes or logic optimizations
- 📊 Enhancements to OLED display (e.g. show setpoint, ambient temp, mode)
- 💡 EEPROM persistence for settings
- ⚙️ PID tuning refinements
- 📐 Hardware pinout corrections or Proteus schematics
- 📄 Documentation (README, wiring tables, diagrams)

❗ Things to Avoid

- Switching the framework (this project uses the Arduino framework via PlatformIO)
- Moving core logic back to monolithic .ino format
- Adding large libraries or unnecessary dependencies
- Changing logic for specific hardware unless made optional via #define or config

📜 License

By contributing, you agree that your code will be released under the MIT License.

Thanks again for helping improve this open-source embedded controller!

— Lakmal Weerasinghe