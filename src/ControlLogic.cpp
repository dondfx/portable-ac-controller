#include "ControlLogic.h"
#include "Pins.h"
#include "TempSensors.h"

// === Global State Variables ===

// Current operating mode: MANUAL or AUTO
uint8_t opMode = AUTO;

// User-set temperature (setpoint) in AUTO mode
double set_temp = 20;

// Final compressor output value (inverted PID output or manual input)
double compressor_setting = 0;

// Flags set by button interrupts (debounced in loop)
volatile uint8_t up_pressed = 0;
volatile uint8_t down_pressed = 0;

// Blower speed value (from potentiometer)
uint16_t evaporator_setting = 0;

// === Interrupt Service Routines ===

// Triggered when UP button is pressed (via INT0)
void isr_up() {
  up_pressed = 1;
}

// Triggered when DOWN button is pressed (via INT1)
void isr_down() {
  down_pressed = 1;
}

// === Initialization Function ===
// Configures I/O pins and attaches interrupts
void initControl() {
  // Configure control input pins with internal pull-ups
  pinMode(MAN_AUTO_SEL, INPUT_PULLUP);
  pinMode(BTN_SET_UP, INPUT_PULLUP);
  pinMode(BTN_SET_DOWN, INPUT_PULLUP);

  // Configure actuator output pins
  pinMode(EVAPORATOR_BLOWER_PIN, OUTPUT);
  pinMode(CONDENSOR_BLOWER_PIN, OUTPUT);
  pinMode(COMPRESSOR_PIN, OUTPUT);
  pinMode(INDICATOR, OUTPUT);

  // Attach interrupts to buttons (trigger on logic LOW)
  attachInterrupt(digitalPinToInterrupt(BTN_SET_UP), isr_up, LOW);
  attachInterrupt(digitalPinToInterrupt(BTN_SET_DOWN), isr_down, LOW);
}

// === Button Handling ===
// Increments or decrements the AUTO mode setpoint
void checkButtons() {
  if (up_pressed) {
    noInterrupts();
    up_pressed = 0;
    interrupts();
    delay(100);  // Debounce delay

    // Only allow setpoint adjustment in AUTO mode
    if (digitalRead(BTN_SET_UP) == LOW && opMode == AUTO && set_temp < 27) {
      set_temp++;
    }
  }

  if (down_pressed) {
    noInterrupts();
    down_pressed = 0;
    interrupts();
    delay(100);  // Debounce delay

    // Only allow setpoint adjustment in AUTO mode
    if (digitalRead(BTN_SET_DOWN) == LOW && opMode == AUTO && set_temp > 16) {
      set_temp--;
    }
  }
}

// === Mode Switching ===
// Reads the manual/auto switch and updates `opMode` accordingly
void checkModeSwitch() {
  if (digitalRead(MAN_AUTO_SEL) == HIGH && opMode == MANUAL)
    opMode = AUTO;
  else if (digitalRead(MAN_AUTO_SEL) == LOW && opMode == AUTO)
    opMode = MANUAL;
}

// === Manual Mode Control ===
// Reads potentiometers and directly sets compressor and blower speeds
void manualProcedure() {
  if (opMode == MANUAL) {
    evaporator_setting = analogRead(BLOWER_SET_SIG) / 4;      // Scale 0–1023 to 0–255
    compressor_setting = analogRead(MAN_TEMP_SET_SIG) / 4;

    digitalWrite(CONDENSOR_BLOWER_PIN, HIGH);  // Condenser always on
    analogWrite(EVAPORATOR_BLOWER_PIN, evaporator_setting);
    analogWrite(COMPRESSOR_PIN, compressor_setting);
  }
}

// === Automatic Mode Control ===
// Blower is user-controlled; compressor is PID-controlled
void automaticProcedure() {
  if (opMode == AUTO) {
    evaporator_setting = analogRead(BLOWER_SET_SIG) / 4;

    digitalWrite(CONDENSOR_BLOWER_PIN, HIGH);  // Condenser always on
    analogWrite(EVAPORATOR_BLOWER_PIN, evaporator_setting);
    analogWrite(COMPRESSOR_PIN, compressor_setting);  // From PID
  }
}
