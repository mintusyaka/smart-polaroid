#include "SmartPolaroidApp.hpp"

SmartPolaroidApp::SmartPolaroidApp() : display_(), wifi_(), button_(), led_() {}

SmartPolaroidApp::SmartPolaroidApp(const uint8_t buttonPin, const uint8_t ledPin)
    : display_(), wifi_(), button_(), led_(), buttonPin_(buttonPin), ledPin_(ledPin) {}

void SmartPolaroidApp::setup() {
  display_.begin();
  wifi_.connect();
  button_.begin(buttonPin_);
  led_.begin(ledPin_);

  while (wifi_.getIp().isEmpty()) {
    delay(100);
  }
  display_.showText("Smart Polaroid App\nIP: " + wifi_.getIp());
}

void SmartPolaroidApp::loop() {
  button_.update();
  led_.update();

  if (button_.wasPressed()) {
    buttonPressedCount_++;
    display_.showText("Button Pressed!\nCount: " + String(buttonPressedCount_));
    button_.resetPressedFlag();
  }
}
