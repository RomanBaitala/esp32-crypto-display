#include "controller.hpp"

bool isShowingIP = false;
uint8_t currentPairIndex = 0;
bool forceRefresh = false;
uint32_t lastGetDataPause = 0;


void handleNextPair() {
  if (isShowingIP) {
    isShowingIP = false;
  } else {
    currentPairIndex = (currentPairIndex + 1) % totalSymbols;
  }
  forceRefresh = true;
}

void handlePrevPair() {
  if (isShowingIP) {
    isShowingIP = false;
  } else {
    currentPairIndex = (currentPairIndex == 0) ? totalSymbols - 1 : currentPairIndex - 1;
  }
  forceRefresh = true;
}

void handleToggleIP() {
  isShowingIP = !isShowingIP;
  forceRefresh = true;
}