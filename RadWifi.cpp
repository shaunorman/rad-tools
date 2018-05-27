#include <Arduino.h>

#include <RadConfig.h>
#include <ESP8266WiFi.h>
#include <RadLED.h>

void setup_wifi(String device_id, RadConfig config) {

    // The devices last digits of the IP are based on the last digits of the device id + a starting point.
    int last_digits = device_id.substring(4, 6).toInt();
    IPAddress this_ip(config.gateway[0], config.gateway[1], config.gateway[2], config.ip_start + last_digits);

    // Turn off broadcoasting.
    WiFi.mode(WIFI_STA);
    // Set static IP
    WiFi.config(this_ip, config.gateway_ip(), config.gateway_ip());
    WiFi.hostname(device_id);
    Serial.println("[WIFI] Connecting to '" + String(config.wifi_ssid));
    WiFi.begin(config.wifi_ssid, config.wifi_password);

    while (WiFi.status() != WL_CONNECTED) {
        LED_flash(LED_BUILTIN, 3, 100, 100);
        Serial.print(String(WiFi.status() + "."));
    }
    Serial.println("\n[WIFI] Connected!");

    Serial.print("[WIFI] IP Address: ");
    Serial.println(WiFi.localIP());
}