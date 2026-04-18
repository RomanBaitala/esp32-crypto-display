#include "network_status.hpp"

void wifiEventHandler(WiFiEvent_t event) {
    switch (event) {
        case ARDUINO_EVENT_WIFI_AP_START:
            showStatus("WIFI SETUP", "Connect to: ESP32-AP", "IP: 192.168.4.1");
            break;
        case ARDUINO_EVENT_WIFI_STA_GOT_IP:
            showIP(WiFi.localIP());
            break;
        case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
            showStatus("WIFI ERROR", "Connection lost", "Retrying...");
            break;
        default: break;
    }
}