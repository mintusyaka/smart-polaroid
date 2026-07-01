#include <Arduino.h>
#include <WiFi.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LED_PIN 38   // або 48, залежно від того, що спрацювало у Фазі 1

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASS = "";

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

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

void showText(const String& text) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(text);
  display.display();
}

void initOLED() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("SSD1306 allocation failed");
  } else {
    showText("Booting...");
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Boot OK");

  initOLED();

  connectWiFi();

  showText("WiFi Connected\nIP: " + WiFi.localIP().toString());
}

void loop() {
  neopixelWrite(LED_PIN, 20, 0, 0);
  delay(500);
  neopixelWrite(LED_PIN, 0, 0, 0);
  delay(500);
}