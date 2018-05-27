#pragma once

#include <Arduino.h>
#include <PubSubClient.h>
#include <RadConfig.h>
#include <RadLED.h>

String float_to_string(float value, int decimals);

void mqtt_reconnect(PubSubClient &client, String dev_id, RadConfig config);