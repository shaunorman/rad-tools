#pragma once

#include <Arduino.h>
#include <RadConfig.h>
#include <ESP8266WiFi.h>

class RadWiFi {
    public:
        RadWiFi (RadConfig config);
        void connect();
        void loop();

    private:
        RadConfig _config;
        unsigned long _wifi_last_check;
};
