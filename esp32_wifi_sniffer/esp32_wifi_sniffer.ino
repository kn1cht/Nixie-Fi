#include <WiFi.h>
#include "moving_counter.hpp"
#include "wifi_handler.hpp"
#include "wifi_sniffer.hpp"

uint8_t count = 0;
volatile xSemaphoreHandle sema;
MovingCounter packetCounter(10);
MovingCounter rssiCounter(10);

void packet_handler(void* buff, wifi_promiscuous_pkt_type_t type) {
  const wifi_promiscuous_pkt_t  *ppkt = (wifi_promiscuous_pkt_t *)buff;
  xSemaphoreTake(sema, portMAX_DELAY);
  count++;
  xSemaphoreGive(sema);
}

void setup() {
  Serial.begin(115200);
  delay(10);
  sema = xSemaphoreCreateMutex();
  new WifiHandler(); // start Wi-Fi connection
  uint8_t channel; wifi_second_chan_t _;
  esp_wifi_get_channel(&channel, &_);
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_promiscuous_rx_cb(&packet_handler);
  esp_wifi_set_channel(channel, WIFI_SECOND_CHAN_NONE);
}

void loop() {
  packetCounter += count;
  rssiCounter += WiFi.RSSI();
  Serial.printf("%3.1f\t%02d\n", rssiCounter.get_average(), packetCounter.get());
  xSemaphoreTake(sema, portMAX_DELAY);
  count = 0;
  xSemaphoreGive(sema);
  delay(200);
}
