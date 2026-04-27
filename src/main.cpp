#include "config.hpp"
#include "display.hpp"
#include "buttons.hpp"
#include "binance.hpp"
#include "controller.hpp"
#include "network_status.hpp"
#include <wifi.hpp>

void handleDataUpdate();
void handleDataLogic();
float prices[24];

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
  buttonNext.tick();
  buttonPrev.tick();

  if (WiFi.getMode() == WIFI_MODE_AP) {
    dnsServer.processNextRequest();
    webServer.handleClient();
  }

  if (WiFi.status() == WL_CONNECTED) {
    if (isShowingIP){
      showIP(WiFi.localIP());
    } else {
      handleDataLogic();
    }
  }
}

void handleDataLogic() {
  uint32_t currentTime = millis();
  if (currentTime - lastGetDataPause > getDataPause) {
    lastGetDataPause = currentTime;
    handleDataUpdate();
  } else if (forceRefresh) {
    lastGetDataPause = currentTime;
    forceRefresh = false;
    handleDataUpdate();
  }
}

void handleDataUpdate() {
  const char* symbol = symbols[currentPairIndex];
  if (fetchBinancePrices(symbol, prices)) {
    updateDisplay(symbol, prices);
  }
}