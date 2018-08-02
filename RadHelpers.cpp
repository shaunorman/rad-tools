#include <Arduino.h>

String float_to_string(float value, int decimals) {
    char c_value[10];
    dtostrf(value, 1, decimals, c_value);
    return c_value;
}
