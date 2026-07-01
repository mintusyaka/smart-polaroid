#include "WiFiManager.hpp"

WiFiManager::WiFiManager() : ipAddress_("") {}

void WiFiManager::connect() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  ipAddress_ = WiFi.localIP().toString();
}


String WiFiManager::getIp() const {
  return ipAddress_;
}
