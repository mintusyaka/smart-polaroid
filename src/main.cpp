#include "modules/SmartPolaroidApp.hpp"

#define LED_PIN 38   // або 48, залежно від того, що спрацювало у Фазі 1
#define BUTTON_PIN 4

const char* _telegramBotToken = "8952161732:AAGLJmVqU3yzFHrZn2RvTfjk79LKeiQSWEw";
const char* _telegramChatId = "801685009";

SmartPolaroidApp app(BUTTON_PIN, LED_PIN, _telegramBotToken, _telegramChatId);

void setup() {
  app.setup();
}


void loop() {
  app.loop();
}