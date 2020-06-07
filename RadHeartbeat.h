#pragma once

#include <Arduino.h>
#include <RadConfig.h>

class RadHeartbeat {
    public:
        RadHeartbeat (RadConfig config);
        void loop();

    private:
        RadConfig _config;
        unsigned long _last_beat;
};
