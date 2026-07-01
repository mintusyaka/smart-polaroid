#include <Arduino.h>
#include <WiFi.h>

#define LED_PIN 38   // або 48, залежно від того, що спрацювало у Фазі 1

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASS = "";

void connectWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected. IP=");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  Serial.println("Boot OK");

  connectWiFi();
}

void loop() {
  neopixelWrite(LED_PIN, 20, 0, 0);
  delay(500);
  neopixelWrite(LED_PIN, 0, 0, 0);
  delay(500);
}