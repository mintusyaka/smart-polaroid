#pragma once

#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C


class DisplayManager {
public:
  DisplayManager();
  void begin();
  void showText(const String& text);
private:
  Adafruit_SSD1306 display_{SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1};
};