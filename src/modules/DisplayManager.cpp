#include "DisplayManager.hpp"

DisplayManager::DisplayManager() : display_(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1) {}

void DisplayManager::begin() {
  if (!display_.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("SSD1306 allocation failed");
  } else {
    showText("Booting...");
  }
}

void DisplayManager::showText(const String& text) {
  display_.clearDisplay();
  display_.setTextSize(1);
  display_.setTextColor(SSD1306_WHITE);
  display_.setCursor(0, 0);
  display_.println(text);
  display_.display();
}