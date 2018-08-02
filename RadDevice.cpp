#include <Arduino.h>
#include <RadDevice.h>
// NOTE: this must be included in main.cpp to compile
#include <EEPROM.h>

String get_device_id() {
    // device id is stored at pos 0 and is X bytes long.
    // As soon as it hits the first NULL char it bails.
    EEPROM.begin(50);
    String device_id;

    for (int i=0 ; i < 50 ; i++) {
        char f = EEPROM.read(i);
        if (f == NULL) {
            break;
        }
        device_id += (f);
    }
    EEPROM.end();
    return device_id;
}