#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DisplayManager.h"

// === OLED Display Configuration ===

#define SCREEN_WIDTH 128        // OLED width in pixels
#define SCREEN_HEIGHT 64        // OLED height in pixels
#define OLED_RESET -1           // Use Arduino reset pin

// Instantiate the OLED display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// === Initialization ===
// Initializes the OLED display using I2C
void initDisplay() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    // 0x3C is the I2C address for most 128x64 SSD1306 OLEDs
    while (true); // Halt if initialization fails
  }
  display.clearDisplay(); // Clear buffer on start
}

// === Generic Text Print Function ===
// Draws a custom string on screen with specified text size and position
void OLEDPrintText(const char* str, uint8_t text_size, uint8_t x_pos, uint8_t y_pos) {
  display.clearDisplay();              // Clear previous content
  display.setTextSize(text_size);      // Text scale factor
  display.setTextColor(SSD1306_WHITE); // White text
  display.setCursor(x_pos, y_pos);     // Position on screen
  display.println(str);                // Print string
  display.display();                   // Push to screen
}

// === Temperature Display Function ===
// Formats and displays a temperature value in large digits
void OLEDPrintTemp(uint8_t nowTemp) {
  char buf[4] = {0};                       // Buffer to hold string representation
  String(nowTemp).toCharArray(buf, 4);    // Convert number to string
  OLEDPrintText(buf, 5, 40, 0);           // Print in large font centered
}
