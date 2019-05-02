#include <esp_event_loop.h>
#include <WiFi.h>
#include "wifi_handler.hpp"
#include "wifi_sniffer.hpp"

uint8_t channel = 1;
WiFiSniffer* sniffer;

void setup() {
  Serial.begin(115200);
  delay(10);
  //new WifiHandler(); // start Wi-Fi connection
	sniffer = new WiFiSniffer();
  sniffer->set_channel(3);
}

void loop() {
  delay(1000);
}
