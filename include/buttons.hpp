#ifndef BUTTONS_OPERATIONS_H
#define BUTTONS_OPERATIONS_H

#include <stdint.h>
#include <Arduino.h>

const uint8_t buttonNext = 38;
const uint8_t buttonPrev = 37;


extern bool wasNextPressed;
extern bool wasPrevPressed;

void initButtons();
void checkButtons(uint8_t &currentPairIndex);

#endif