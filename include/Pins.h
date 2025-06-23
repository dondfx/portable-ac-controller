#ifndef PINS_H
#define PINS_H

// Analog Pins
#define INTERNAL_TEMP_PIN A2
#define AMBIENT_TEMP_PIN  A3
#define BLOWER_SET_SIG    A0
#define MAN_TEMP_SET_SIG  A1

// Digital Outputs
#define EVAPORATOR_BLOWER_PIN 6
#define CONDENSOR_BLOWER_PIN  7
#define COMPRESSOR_PIN        5
#define INDICATOR             8

// Digital Inputs
#define MAN_AUTO_SEL  4
#define BTN_SET_UP    2
#define BTN_SET_DOWN  3

// Operation Modes
#define MANUAL 0
#define AUTO   1

#endif
