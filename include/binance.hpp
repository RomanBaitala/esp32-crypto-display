#ifndef BINANCE_OPERATIONS_H
#define BINANCE_OPERATIONS_H

#include <Arduino.h>
#include <WiFi.h> 
#include <ArduinoJson.h>
#include <HTTPClient.h>

bool fetchBinancePrices(const char* symbol, float prices[24]);

#endif