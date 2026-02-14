#include "buttons.hpp"

bool wasNextPressed = false;
bool wasPrevPressed = false;

const uint8_t totalSymbols = 20;

void initButtons() {
  pinMode(buttonNext, INPUT);
  pinMode(buttonPrev, INPUT);
}

void checkButtons(uint8_t &currentPairIndex) {
  if (digitalRead(buttonNext) == LOW && !wasNextPressed) {
    currentPairIndex = (currentPairIndex + 1) % totalSymbols;
    wasNextPressed = true;
  } else if (digitalRead(buttonNext) == HIGH) {
    wasNextPressed = false;
  }

  if (digitalRead(buttonPrev) == LOW && !wasPrevPressed) {
    currentPairIndex = (currentPairIndex == 0) ? totalSymbols - 1 : currentPairIndex - 1;
    wasPrevPressed = true;
  } else if (digitalRead(buttonPrev) == HIGH) {
    wasPrevPressed = false;
  }
}
