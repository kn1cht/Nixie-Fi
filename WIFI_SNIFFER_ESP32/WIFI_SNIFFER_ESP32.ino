#include <WiFi.h>
#include "wifi_sniffer.hpp"
#define	WIFI_CHANNEL_MAX		(13)
#define	WIFI_CHANNEL_SWITCH_INTERVAL	(500)

uint8_t channel = 1;


WiFiSniffer* sniffer;

void setup() {
  Serial.begin(115200);
  delay(10);
	sniffer = new WiFiSniffer();
}

void loop() {
  delay(1000);
  vTaskDelay(WIFI_CHANNEL_SWITCH_INTERVAL / portTICK_PERIOD_MS);
  sniffer->set_channel(channel);
  channel = (channel % WIFI_CHANNEL_MAX) + 1;
}
