#include <Arduino.h>

#include <RadConfig.h>
#include <RadLED.h>
#include <RadHeartbeat.h>


RadHeartbeat::RadHeartbeat(RadConfig config) {
    _config = config;
}


/**
 * Every _config.heartbeat_ms the light flashes on twice real fast, just so you can see the
 * device is still on and running

 */
void RadHeartbeat::loop() {
    if (millis() - _last_beat > _config.heartbeat_ms) {
        _config.led.flash(2, 200, 200);
        _last_beat = millis();
    }
}
