#include "modules/SmartPolaroidApp.hpp"
#include "modules/include/secrets.h"

#define LED_PIN 38   // або 48, залежно від того, що спрацювало у Фазі 1
#define BUTTON_PIN 4

SmartPolaroidApp app(BUTTON_PIN, LED_PIN, BOT_TOKEN, CHAT_ID);

void setup() {
  app.setup();
}


void loop() {
  app.loop();
}