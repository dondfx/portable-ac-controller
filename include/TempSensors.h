#ifndef TEMP_SENSORS_H
#define TEMP_SENSORS_H

#include <Arduino.h>

// === Global Temperature Variables ===

// Ambient temperature in °C (scaled from sensor)
extern uint16_t amb_temp;

// Internal temperature in °C (used for PID)
extern double int_temp;

// Reads and updates ambient and internal temperature values
void readTemp();

#endif
