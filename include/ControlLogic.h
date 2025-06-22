#ifndef CONTROL_LOGIC_H
#define CONTROL_LOGIC_H

#include <Arduino.h>

//
// === Global Variables Shared with Other Modules ===
//

// Current operating mode: MANUAL (0) or AUTO (1)
extern uint8_t opMode;

// Desired temperature setpoint (used in AUTO mode only)
extern double set_temp;

// Compressor output value (from PID or manual control)
extern double compressor_setting;

// Interrupt flags triggered by button presses
extern volatile uint8_t up_pressed;
extern volatile uint8_t down_pressed;

//
// === Function Prototypes ===
//

//
// Initializes GPIO pins, configures input pullups,
// output modes, and attaches interrupts for control buttons.
//
void initControl();

//
// Executes control logic in MANUAL mode.
// Reads potentiometers and sets compressor and blower speeds directly.
//
void manualProcedure();

//
// Executes control logic in AUTO mode.
// Uses PID-controlled compressor and user-set blower speed.
//
void automaticProcedure();

//
// Handles increment/decrement of temperature setpoint
// via UP/DOWN buttons (with debouncing and safety limits).
//
void checkButtons();

//
// Checks the MANUAL/AUTO mode selector switch and
// updates the global `opMode` accordingly.
//
void checkModeSwitch();

#endif
