#pragma once

#include <Arduino.h>
#include <RadConfig.h>
#include <PubSubClient.h>

class RadMQTT {
    public:
        RadMQTT (RadConfig config);
        void connect();
        void loop();
        bool publish(const char* topic, const char* payload);

        PubSubClient *client;
    private:
        RadConfig _config;
        unsigned long _last_poll;
};
