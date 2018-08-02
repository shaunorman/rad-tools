#include <Arduino.h>
#include <RadLED.h>

void LED_flash(int pin, int no_times, int on_ms, int off_ms) {
    // When using the internal LED, the LOW and HIGH are around the wrong way. So:
    // LOW = HIGH
    // HIGH = LOW
    int _LOW = LOW;
    int _HIGH = HIGH;
    if (pin == D4) {
        _LOW = HIGH;
        _HIGH = LOW;
    }
    for (int count=0; count < no_times; count++) {
        digitalWrite(pin, LOW);
        delay(on_ms);
        digitalWrite(pin, HIGH);
        delay(off_ms);
    }
}
