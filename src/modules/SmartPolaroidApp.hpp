#pragma once

#include "ButtonHandler.hpp"
#include "DisplayManager.hpp"
#include "LedController.hpp"
#include "WiFiManager.hpp"
#include "TelegramBotController.hpp"


class SmartPolaroidApp {
public:
  SmartPolaroidApp();
  SmartPolaroidApp(const uint8_t buttonPin, const uint8_t ledPin, const String& botToken, const String& chatId);
  void setup();
  void loop();

private:
  DisplayManager display_;
  WiFiManager wifi_;
  ButtonHandler button_;
  LedController led_;
  TelegramBotController telegramBot_;

  uint8_t buttonPin_ = 4;  // Пін кнопки
  uint8_t ledPin_ = 48;    // Пін світлодіода

  int buttonPressedCount_ = 0;  // Лічильник натискань кнопки
};