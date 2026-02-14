#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <Arduino.h>

const char* symbols[] = {
  "BTCUSDT", "ETHUSDT", "BNBUSDT", "XRPUSDT", "SOLUSDT",
  "ADAUSDT", "DOGEUSDT", "DOTUSDT", "TRXUSDT", "AVAXUSDT",
  "MATICUSDT", "LINKUSDT", "LTCUSDT", "BCHUSDT", "XLMUSDT",
  "ATOMUSDT", "FILUSDT", "ETCUSDT", "HBARUSDT", "APTUSDT"
};

const uint32_t totalSymbols = sizeof(symbols) / sizeof(symbols[0]);

#endif