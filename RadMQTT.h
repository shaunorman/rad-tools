#pragma once

#include <Arduino.h>
#include <RadConfig.h>
#include <PubSubClient.h>

class RadMQTT {
    public:
        RadMQTT (RadConfig config);
        void connect();
        void loop();

        PubSubClient *client;
    private:
        RadConfig _config;
        unsigned long _last_poll;
};
