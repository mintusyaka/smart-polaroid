#include "TelegramBotController.hpp"
#include "DisplayManager.hpp"

TelegramBotController::TelegramBotController(const String& botToken, const String& chatId, DisplayManager& displayManager)
    : botToken_(botToken), chatId_(chatId), secureClient_(), bot_(botToken_, secureClient_), displayManager_(displayManager) { 
    }

void TelegramBotController::begin() {
#ifdef HARDWARE
  secureClient_.setCACert(TELEGRAM_CERTIFICATE_ROOT);
#else
  secureClient_.setInsecure();
#endif
}

void TelegramBotController::checkForNewMessages() {
    unsigned long currentTime = millis();
    if (currentTime - lastUpdateTime_ >= BOT_POLL_MS) {
        int numNewMessages = bot_.getUpdates(bot_.last_message_received + 1);
        if (numNewMessages > 0) {
            handleNewMessages(numNewMessages);
        }
        lastUpdateTime_ = currentTime;
    }
}

void TelegramBotController::handleNewMessages(int numNewMessages) {
  for (int i = 0; i < numNewMessages; i++) {
    String chatId = bot_.messages[i].chat_id;
    String fromName = bot_.messages[i].from_name;
    String type = bot_.messages[i].type;
 
    Serial.print("New message from ");
    Serial.print(fromName);
    Serial.print(" type=");
    Serial.println(type);
 
    if (type == "voice") {
      displayManager_.showText("New voice msg\nfrom " + fromName);
    } else {
      displayManager_.showText(fromName + ":\n" + bot_.messages[i].text);
    }
  }
}
