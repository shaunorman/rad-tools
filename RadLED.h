#pragma once

#include <Arduino.h>


class RadLED {
    public:
        RadLED();
        RadLED(int pin);
        void flash(int no_times, int on_ms, int off_ms);
        void on();
        void off();

    private:
        void _init();
        int _internal_pin = D4;
        int _pin;
        int _low;
        int _high;
};
