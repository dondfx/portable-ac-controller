#include "TempSensors.h"
#include "Pins.h"

// === Global Sensor Readings ===

// Ambient temperature in °C (scaled from raw ADC value)
// Used for display or future logic
uint16_t amb_temp = 0;

// Internal (target-controlled) temperature in °C (used by PID)
double int_temp = 0;

// === Sensor Reading Function ===
// Reads both ambient and internal temperatures from analog inputs
void readTemp() {
  // Read and convert ambient temperature:
  // - Assumes sensor outputs a voltage mapped from 0–150°C over 0–5V
  // - ADC range: 0–1023 → scale: (value * 150) / 300 = (value * 0.5)
  amb_temp = analogRead(AMBIENT_TEMP_PIN) * 150UL / 300;

  // Read and convert internal temperature:
  // - Uses double precision for PID accuracy
  int_temp = analogRead(INTERNAL_TEMP_PIN) * 150.0 / 300.0;
}
