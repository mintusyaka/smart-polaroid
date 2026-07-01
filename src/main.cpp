#include "modules/SmartPolaroidApp.hpp"

#define LED_PIN 38   // або 48, залежно від того, що спрацювало у Фазі 1
#define BUTTON_PIN 4

SmartPolaroidApp app(BUTTON_PIN, LED_PIN);

void setup() {
  app.setup();
}


void loop() {
  app.loop();
}