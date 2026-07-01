#include "LedController.hpp"

void LedController::begin(uint8_t pin) {
  ledPin_ = pin;
  pinMode(ledPin_, OUTPUT);
}

void LedController::update() {
  unsigned long currentTime = millis();
  if (currentTime - lastToggleTime_ >= LED_BLINK_MS) {
    lastToggleTime_ = currentTime;
    ledOn_ = !ledOn_;
    digitalWrite(ledPin_, ledOn_ ? HIGH : LOW);
  }
}