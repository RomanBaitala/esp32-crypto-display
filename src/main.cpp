#include "config.hpp"
#include "display.hpp"
#include "buttons.hpp"
#include "binance.hpp"
#include "controller.hpp"
#include "network_status.hpp"
#include <wifi.hpp>

const uint32_t errorPause = 10000;
uint32_t lastTimeError = 0;
const uint32_t getDataPause = 10000;
uint32_t lastGetDataPause = 0;

float prices[24];

Button buttonNext(38, false, 2000);
Button buttonPrev(37, false, 2000);

void setup() {
  Serial.begin(115200);
  initDisplay();

  buttonNext.begin();
  buttonPrev.begin();

  buttonNext.setLongPressCallback(handleToggleIP);
  buttonNext.setShortPressCallback(handleNextPair);
  buttonPrev.setShortPressCallback(handlePrevPair);

  WiFi.onEvent(wifiEventHandler);
  connectWiFi();
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
    
    buttonNext.tick();
    buttonPrev.tick();

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