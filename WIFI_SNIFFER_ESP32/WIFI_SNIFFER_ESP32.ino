#include <WiFi.h>
#include "moving_counter.hpp"
#include "wifi_handler.hpp"
#include "wifi_sniffer.hpp"

uint8_t count = 0;
volatile xSemaphoreHandle countMutex;
MovingCounter counter(10);

void packet_handler(void* buff, wifi_promiscuous_pkt_type_t type) {
  const wifi_promiscuous_pkt_t  *ppkt = (wifi_promiscuous_pkt_t *)buff;
  //printf("CHAN=%02d, RSSI=%02d\n", ppkt->rx_ctrl.channel, ppkt->rx_ctrl.rssi);
  count++;
}

void setup() {
  Serial.begin(115200);
  delay(10);
  countMutex = xSemaphoreCreateMutex();
  new WifiHandler(); // start Wi-Fi connection
  uint8_t channel; wifi_second_chan_t _;
  esp_wifi_get_channel(&channel, &_);
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_promiscuous_rx_cb(&packet_handler);
  esp_wifi_set_channel(channel, WIFI_SECOND_CHAN_NONE);
}

void loop() {
  counter += count;
  Serial.printf("%02d\t%02d\n", WiFi.RSSI(), uint16_t(counter));
  count = 0;
  delay(200);
}
