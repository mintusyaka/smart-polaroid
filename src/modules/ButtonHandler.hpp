#pragma once

#include <Arduino.h>

#define DEBOUNCE_MS 50

class ButtonHandler {
public:
  ButtonHandler();
  void begin(uint8_t pin);
  void update();
  bool wasPressed() const;
  void resetPressedFlag();

private:
  uint8_t pin_;
  bool lastRawReading_;
  bool buttonState_;
  unsigned long lastDebounceTime_;
  bool pressedFlag_;

};