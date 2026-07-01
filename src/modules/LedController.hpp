#pragma once

#include <Arduino.h>

#define LED_BLINK_MS 500

class LedController {
public:
  void begin(uint8_t pin);
  void update();
private:
  uint8_t ledPin_;
  bool ledOn_ = false;
  unsigned long lastToggleTime_ = 0;
};