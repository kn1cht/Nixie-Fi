#ifndef __WIFI_SNIFFER_HPP__
#define __WIFI_SNIFFER_HPP__

#include <esp_wifi.h>

struct wifi_ieee80211_mac_hdr_t { /* DO NOT Change the order */
  unsigned frame_ctrl:16;
  unsigned duration_id:16;
  uint8_t addr1[6]; /* receiver address */
  uint8_t addr2[6]; /* sender address */
  uint8_t addr3[6]; /* filtering address */
  unsigned sequence_ctrl:16;
  uint8_t addr4[6]; /* optional */
};
struct wifi_ieee80211_packet_t {
  wifi_ieee80211_mac_hdr_t hdr;
  uint8_t payload[0]; /* network data ended with 4 bytes csum (CRC32) */
};

const char* packet_type_to_str(wifi_promiscuous_pkt_type_t type);
void packet_handler(void* buff, wifi_promiscuous_pkt_type_t type);

#endif // WIFI_SNIFFER_HPP
