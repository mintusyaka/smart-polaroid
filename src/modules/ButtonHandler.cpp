#include "ButtonHandler.hpp"

ButtonHandler::ButtonHandler() : pin_(0), lastRawReading_(HIGH), buttonState_(HIGH), lastDebounceTime_(0), pressedFlag_(false) {}

void ButtonHandler::begin(uint8_t pin) {
  pin_ = pin;
  pinMode(pin_, INPUT_PULLUP);
}

void ButtonHandler::update() {
  bool reading = digitalRead(pin_);

  if (reading != lastRawReading_) {
    lastDebounceTime_ = millis();
  }

  if ((millis() - lastDebounceTime_) > DEBOUNCE_MS) {
    if (reading != buttonState_) {
      buttonState_ = reading;
      if (buttonState_ == LOW) {
        pressedFlag_ = true;
      }
    }
  }

  lastRawReading_ = reading;
}

bool ButtonHandler::wasPressed() const {
  return pressedFlag_;
}

void ButtonHandler::resetPressedFlag() {
  pressedFlag_ = false;
}