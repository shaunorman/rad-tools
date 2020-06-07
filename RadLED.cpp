#include <Arduino.h>
#include <RadLED.h>


RadLED::RadLED(int pin) {
    _pin = pin;
    _init();
}

RadLED::RadLED() {
    _pin = _internal_pin;
    _init();
}


void RadLED::_init() {
    pinMode(_pin, OUTPUT);

    // The internal LED on my devices is the opposite, HIGH for off, LOW for on
    if (_pin == _internal_pin) {
        _high = LOW;
        _low = HIGH;
    }
    else {
        _high = HIGH;
        _low = LOW;
    }

    digitalWrite(_pin, _low);
}


void RadLED::on() {
    digitalWrite(_pin, _high);
}


void RadLED::off() {
    digitalWrite(_pin, _low);
}


void RadLED::flash(int no_times, int on_ms, int off_ms) {
    for (int count=0; count < no_times; count++) {
        on();
        delay(on_ms);
        off();
        // No point locking up the system to wait for it to be off.
        if (count < no_times - 1) {
            delay(off_ms);
        }
    }
}
