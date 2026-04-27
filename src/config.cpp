#include "config.hpp"

const uint32_t getDataPause = 10000;

const uint8_t BUTTON_NEXT_PIN = 38;
const uint8_t BUTTON_PREV_PIN = 37;

Button buttonNext(BUTTON_NEXT_PIN, false, 2000);
Button buttonPrev(BUTTON_PREV_PIN, false, 2000);

const char* symbols[] = {
  "BTCUSDT", "ETHUSDT", "BNBUSDT", "XRPUSDT", "SOLUSDT",
  "ADAUSDT", "DOGEUSDT", "DOTUSDT", "TRXUSDT", "AVAXUSDT",
  "MATICUSDT", "LINKUSDT", "LTCUSDT", "BCHUSDT", "XLMUSDT",
  "ATOMUSDT", "FILUSDT", "ETCUSDT", "HBARUSDT", "APTUSDT"
};

const uint32_t totalSymbols = sizeof(symbols) / sizeof(symbols[0]);