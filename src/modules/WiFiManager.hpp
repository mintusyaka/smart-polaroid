#pragma once

#include <Arduino.h>

#include <WiFi.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""

class WiFiManager {
public:
  WiFiManager();
  void connect();
  String getIp() const;
private:
  String ipAddress_;
};