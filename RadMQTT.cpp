#include <Arduino.h>
#include <ESP8266WiFi.h>

#include <RadConfig.h>
#include <RadMQTT.h>
#include <PubSubClient.h>
#include <RadLED.h>

WiFiClient wclient;

RadMQTT::RadMQTT(RadConfig config) {
    _config = config;
    client = new PubSubClient(config.mqtt_server, config.mqtt_port, wclient);
    connect();
}

void RadMQTT::connect() {
    if (WiFi.status() != WL_CONNECTED) {
        // Do nothing here as the wifi isn't even connected.
        return;
    }

    _config.log("[MQTT] Attempting MQTT connection...");
    while (!client->connected()) {
        if (client->connect(_config.device_id.c_str())) {
            _config.log("[MQTT] Connected");
            // Connected! 3 success flashes
            delay(1000);
            LED_flash(D4, 3, 500, 500);
            delay(1000);
        }
        else {
            _config.log("[MQTT] Failed, rc=" + String(client->state()));
            LED_flash(D4, 10, 100, 100);
            delay(5000);
        }
    }
}

/**
 * I have found with the MQTT library you can't hammer it with a .loop()
 * on every arduino loop otherwise it causes it to disconnect randomly and
 * then try to reconnect again causing a ~5 second lock.
 *
 * Unsure if this is the mosquitto server, or the device.
 */
void RadMQTT::loop() {
    if (!client->connected()) {
        connect();
        _last_poll = millis();
    }
    else if (millis() - _last_poll > 2000) {
        client->loop();
        _last_poll = millis();
    }
}
