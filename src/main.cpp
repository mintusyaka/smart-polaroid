#include <Arduino.h>

#define LED_PIN 38   // вбудований адресний LED плати

void setup() {
  Serial.begin(115200);
  Serial.println("Boot OK");
}

void loop() {
  neopixelWrite(LED_PIN, 20, 0, 0);  // тьмяний червоний
  delay(500);
  neopixelWrite(LED_PIN, 0, 0, 0);   // вимкнено
  delay(500);
}