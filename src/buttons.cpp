#include "buttons.hpp"

Button::Button(
  uint8_t pin, 
  bool internalPullup, 
  uint32_t longPressDuration
) :
  _pin(pin), 
  _internalPullup(internalPullup), 
  _longPressDuration(longPressDuration) {}

void Button::setShortPressCallback(ButtonCallback cb) {
  _shortPressCallback = cb;
}

void Button::setLongPressCallback(ButtonCallback cb) {
  _longPressCallback = cb;
}

void Button::begin() {
  if (_internalPullup) {
    pinMode(_pin, INPUT_PULLUP);
  } else {
    pinMode(_pin, INPUT);
  }
}

uint8_t Button::check() {
  bool currentState = digitalRead(_pin) == LOW;
  uint8_t result = 0;

  if (currentState == LOW && _lastState == HIGH) {
    _timer = millis();
    _isLongPress = false;
  } 
  else if (currentState == HIGH && _lastState == LOW) {
    if (millis() - _timer >= _longPressDuration){
      _isLongPress = true;
      result = 2; 
    } 
  }
  else if (currentState == HIGH && _lastState == LOW) {
    if (!_isLongPress) {
      result = 1;
    }
  }

  _lastState = currentState;
  return result;
}

void Button::tick() {
  uint8_t res = check();
  if (res == 1 && _shortPressCallback) _shortPressCallback();
  if (res == 2 && _longPressCallback) _longPressCallback();
}
