#include <Arduino.h>
#include <WiFi.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LED_PIN 38   // або 48, залежно від того, що спрацювало у Фазі 1

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

#define BUTTON_PIN 4
#define DEBOUNCE_MS 50

#define LED_BLINK_MS 500

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASS = "";

bool lastRawReading = HIGH;   // сире значення піна з попередньої ітерації — лише для виявлення дребезгу
bool buttonState = HIGH;      // підтверджений стан ПІСЛЯ антидребезгу — саме він порівнюється для лічильника
unsigned long lastDebounceTime = 0;
int pressCount = 0;

bool ledOn = false;
unsigned long lastLedToggle = 0;

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

void checkButton() {
  bool reading = digitalRead(BUTTON_PIN);

  if (reading != lastRawReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_MS) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        pressCount++;
        Serial.print("Button pressed. Count=");
        Serial.println(pressCount);
        showText("Button: " + String(pressCount));
      }
    }
  }

  lastRawReading = reading;
}

void updateLed() {
  if (millis() - lastLedToggle >= LED_BLINK_MS) {
    lastLedToggle = millis();
    ledOn = !ledOn;
    if (ledOn) {
      neopixelWrite(LED_PIN, 20, 0, 0);
    } else {
      neopixelWrite(LED_PIN, 0, 0, 0);
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Boot OK");

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  initOLED();

  connectWiFi();

  showText("WiFi Connected\nIP: " + WiFi.localIP().toString());
}


void loop() {
  checkButton();

  updateLed();
}