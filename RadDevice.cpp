#include <Arduino.h>
#include <RadDevice.h>
#include <EEPROM.h>

String get_device_id() {
    // device id is stored at pos 0 and is 6 bytes long.
    EEPROM.begin(6);
    String device_id;
    for (int i=0 ; i < 6 ; i++) {
        char f = EEPROM.read(i);
        device_id += (f);
    }
    EEPROM.end();
    return device_id;
}