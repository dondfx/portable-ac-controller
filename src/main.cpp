#include <Arduino.h>
#include <AutoPID.h>

// --- Project Modules ---
#include "Pins.h"
#include "TempSensors.h"
#include "DisplayManager.h"
#include "ControlLogic.h"

// === PID Controller ===
// AutoPID instance to control compressor output based on internal temp
AutoPID myPID(&int_temp, &set_temp, &compressor_setting, 0, 255, 0.12, 0.0003, 0);

// === SETUP FUNCTION ===
// Runs once on startup
void setup() {
  Serial.begin(115200);         // Start serial for debugging (optional)

  initDisplay();                // Initialize SSD1306 OLED display
  initControl();                // Set up GPIO, buttons, outputs, interrupts

  digitalWrite(INDICATOR, HIGH); // Turn ON indicator LED

  readTemp();                   // Read sensors once for initial values

  // PID configuration
  myPID.setBangBang(4);         // Force full on/off if outside ±4°C
  myPID.setTimeStep(4000);      // Run PID every 4 seconds
}

// === MAIN LOOP FUNCTION ===
// Runs repeatedly after setup()
void loop() {
  checkButtons();               // Respond to UP/DOWN button interrupts
  checkModeSwitch();           // Update AUTO/MANUAL mode based on switch

  readTemp();                  // Read temperature sensors

  OLEDPrintTemp((uint8_t)int_temp); // Display internal temperature

  myPID.run();                 // Run PID control logic
  compressor_setting = 255 - compressor_setting; // Invert PID output for hardware logic

  // Run the selected control routine
  if (opMode == MANUAL)
    manualProcedure();         // Manual: set by potentiometers
  else
    automaticProcedure();      // Auto: PID-controlled compressor

  delay(10);                   // Short delay to avoid overloading loop
}
