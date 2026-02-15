#include "config.hpp"
#include "display.hpp"
#include "buttons.hpp"
#include "binance.hpp"
#include <wifi.hpp>

const uint32_t errorPause = 10000;
uint32_t lastTimeError = 0;
const uint32_t getDataPause = 10000;
uint32_t lastGetDataPause = 0;

uint8_t currentPairIndex = 0;
float prices[24];

void setup() {
  Serial.begin(115200);
  connectWiFi();
  initDisplay();
  initButtons();
}

void loop() {
  if (WiFi.getMode() == WIFI_AP || WiFi.getMode() == WIFI_AP_STA) {
    dnsServer.processNextRequest();
    webServer.handleClient();
    
    return; 
  }

  if (WiFi.status() != WL_CONNECTED) {
    return;
  }

  if (WiFi.status() == WL_CONNECTED) {
    
    checkButtons(currentPairIndex);
    
    if (wasNextPressed || wasPrevPressed) {
      const char* symbol = symbols[currentPairIndex];
      if (fetchBinancePrices(symbol, prices)) {
        updateDisplay(symbol, prices);
      } else {
        Serial.println("Manual update failed");
      }
    }

    uint32_t currentTime = millis();
    if (currentTime - lastGetDataPause > getDataPause) {
      lastGetDataPause = currentTime;
      
      const char* symbol = symbols[currentPairIndex];
      if (fetchBinancePrices(symbol, prices)) {
        updateDisplay(symbol, prices);
        Serial.println("Auto-update success");
      } else {
        if (currentTime - lastTimeError > errorPause) {
          Serial.println("Error fetching prices (API/DNS)");
          lastTimeError = currentTime;
        }
      }
    }
  } else {

    static uint32_t lastReconnectMsg = 0;
    if (millis() - lastReconnectMsg > 5000) {
      Serial.println("Waiting for WiFi connection...");
      lastReconnectMsg = millis();
    }
  }
}