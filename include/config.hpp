#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <Arduino.h>
#include "buttons.hpp"

extern const uint32_t getDataPause;

extern const uint8_t BUTTON_NEXT_PIN;
extern const uint8_t BUTTON_PREV_PIN;

extern Button buttonNext;
extern Button buttonPrev;

extern const char* symbols[];

extern const uint32_t totalSymbols;

#endif