#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>

//
// Initializes the OLED display (SSD1306, 128x64 over I2C).
// Must be called once in setup().
//
void initDisplay();

//
// Prints a custom string to the OLED screen at a specified size and position.
// Parameters:
//   str       - Null-terminated string to print
//   text_size - Text scaling factor (1 = normal, 2 = double, etc.)
//   x_pos     - Horizontal pixel position (0–127)
//   y_pos     - Vertical pixel position (0–31)
//
void OLEDPrintText(const char* str, uint8_t text_size, uint8_t x_pos, uint8_t y_pos);

//
// Displays the current internal temperature as a large number in center of screen.
// Parameters:
//   nowTemp - Temperature value (uint8_t) to display
//
void OLEDPrintTemp(uint8_t nowTemp);

#endif
