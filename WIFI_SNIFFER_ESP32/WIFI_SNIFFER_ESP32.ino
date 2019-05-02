#include <WiFi.h>
#include "wifi_sniffer.hpp"

uint8_t channel = 1;

void setup() {
  Serial.begin(115200);
  delay(10);
  wifi_sniffer_init();
}

void loop() {
  delay(1000);
  vTaskDelay(WIFI_CHANNEL_SWITCH_INTERVAL / portTICK_PERIOD_MS);
  wifi_sniffer_set_channel(channel);
  channel = (channel % WIFI_CHANNEL_MAX) + 1;
}
