#ifndef BUTTONS_OPERATIONS_H
#define BUTTONS_OPERATIONS_H

#include <stdint.h>
#include <Arduino.h>

const uint8_t buttonNext = 38;
const uint8_t buttonPrev = 37;

class Button {
private:
    uint8_t _pin;
    bool _lastState;
    bool _isLongPress = false;
    bool _internalPullup = true;
    uint32_t _timer = 0;
    uint32_t _longPressDuration = 2000;

public:
    Button(uint8_t pin, bool internalPullup = true, uint32_t longPressDuration = 2000);
    
    void begin();

    /// @brief Function to check current button state and determine between short and long presses.
    /// @return 0 - not pressed, 1 - short press, 2 - long press 
    uint8_t check();
};

#endif