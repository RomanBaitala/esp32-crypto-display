#ifndef APP_CONTROLLER_HPP
#define APP_CONTROLLER_HPP

#include <Arduino.h>
#include "config.hpp"

void handleNextPair();
void handlePrevPair();
void handleToggleIP();

extern bool isShowingIP;
extern uint8_t currentPairIndex;
extern bool forceRefresh;

#endif