#include <Arduino.h>
#include <PubSubClient.h>
#include <RadConfig.h>

String float_to_string(float value, int decimals) {
    char c_value[10];
    dtostrf(value, 1, decimals, c_value);
    return c_value;
}


void mqtt_reconnect(PubSubClient &client, String dev_id, RadConfig config) {
    Serial.println("[MQTT] Attempting MQTT connection...");
    while (!client.connected()) {
        if (client.connect(dev_id.c_str())) {
            Serial.println("[MQTT] Connected");
        }
        else {
            Serial.println("[MQTT] Failed, rc=" + String(client.state()));
            delay(5000);
        }
    }
}