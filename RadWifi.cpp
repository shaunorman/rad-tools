#include <Arduino.h>
#include <ESP8266WiFi.h>

#include <RadConfig.h>
#include <RadLED.h>
#include <RadWifi.h>
#include <RadLED.h>

RadWiFi::RadWiFi(RadConfig config) {
     _config = config;
}

void RadWiFi::connect() {
    // The devices first digits are the last digits of the IP Address
    int first_digits = _config.device_id.substring(0, 3).toInt();
    IPAddress this_ip(_config.gateway[0], _config.gateway[1], _config.gateway[2], first_digits);

    // Turn off broadcoasting.
    WiFi.mode(WIFI_STA);
    // Set static IP
    WiFi.config(this_ip, _config.gateway_ip(), _config.gateway_ip());
    WiFi.hostname(_config.device_id);
    _config.log("[WIFI] Connecting to " + String(_config.wifi_ssid));
    WiFi.begin(_config.wifi_ssid, _config.wifi_password);

    bool on = false;
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        // Flash the internal LED while its connecting.
        if (on) {
            digitalWrite(D4, LOW);
            on = false;
        }
        else {
            digitalWrite(D4, HIGH);
            on = true;
        }

        delay(100);
    }

    _config.log("\n[WIFI] Connected!");

    _config.log("[WIFI] IP Address: " + WiFi.localIP());

    // Turn the led off
    digitalWrite(D4, HIGH);

    // Connected! 2 success flashes
    delay(1000);
    LED_flash(D4, 2, 500, 500);
    delay(1000);

    _wifi_last_check = millis();
}

void RadWiFi::loop() {
    // 5 minutes
    if (millis() - _wifi_last_check > 300000) {
        if (WiFi.status() != WL_CONNECTED) {
            _config.log("[WIFI] Disconnected");
            connect();
        }
        _wifi_last_check = millis();
    }
}
