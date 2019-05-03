#include <WiFi.h>
#include "wifi_handler.hpp"
#include "wifi_sniffer.hpp"

void setup() {
  Serial.begin(115200);
  delay(10);
  new WifiHandler(); // start Wi-Fi connection
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_promiscuous_rx_cb(&packet_handler);
  esp_wifi_set_channel(3, WIFI_SECOND_CHAN_NONE);
}

void loop() {
  delay(1000);
}
