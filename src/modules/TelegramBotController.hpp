#pragma once

#include "Arduino.h"
#include <UniversalTelegramBot.h>
#include "WiFiClientSecure.h"
#include "include/secrets.h"

#define BOT_POLL_MS 1000

class DisplayManager;

class TelegramBotController {
public:
  TelegramBotController(const String& botToken, const String& chatId, DisplayManager& displayManager);
  void begin();
  void checkForNewMessages();

private:
  String botToken_;
  String chatId_;

  WiFiClientSecure secureClient_;
  UniversalTelegramBot bot_;

  DisplayManager& displayManager_;

  unsigned long lastUpdateTime_ = 0;

  void handleNewMessages(int numNewMessages); 
};