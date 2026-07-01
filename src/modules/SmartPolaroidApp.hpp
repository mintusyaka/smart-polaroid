#pragma once

#include "ButtonHandler.hpp"
#include "DisplayManager.hpp"
#include "LedController.hpp"
#include "WiFiManager.hpp"


class SmartPolaroidApp {
public:
  SmartPolaroidApp();
  SmartPolaroidApp(const uint8_t buttonPin, const uint8_t ledPin);
  void setup();
  void loop();

private:
  DisplayManager display_;
  WiFiManager wifi_;
  ButtonHandler button_;
  LedController led_;

  uint8_t buttonPin_ = 4;  // Пін кнопки
  uint8_t ledPin_ = 48;    // Пін світлодіода

  int buttonPressedCount_ = 0;  // Лічильник натискань кнопки
};