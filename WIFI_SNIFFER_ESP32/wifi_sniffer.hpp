#ifndef __WIFI_SNIFFER_HPP__
#define __WIFI_SNIFFER_HPP__

#include <esp_wifi.h>

extern esp_err_t event_handler();

class WiFiSniffer {
private:
	struct wifi_ieee80211_mac_hdr_t {
		uint8_t addr1[6]; /* receiver address */
		uint8_t addr2[6]; /* sender address */
		uint8_t addr3[6]; /* filtering address */
		uint8_t addr4[6]; /* optional */
		unsigned duration_id:16;
		unsigned frame_ctrl:16;
		unsigned sequence_ctrl:16;
	};
	struct wifi_ieee80211_packet_t {
		wifi_ieee80211_mac_hdr_t hdr;
		uint8_t payload[0]; /* network data ended with 4 bytes csum (CRC32) */
	};
  const wifi_country_t wifi_country = {"JP", 1, 13, 0, WIFI_COUNTRY_POLICY_AUTO};
	static const char* packet_type_to_str(wifi_promiscuous_pkt_type_t type);
	static void packet_handler(void* buff, wifi_promiscuous_pkt_type_t type);

public:
  WiFiSniffer(/* args */);
	void set_channel(uint8_t channel);
};

#endif // WIFI_SNIFFER_HPP
