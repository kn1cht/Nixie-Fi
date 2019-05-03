#include "wifi_sniffer.hpp"

const char* packet_type_to_str(wifi_promiscuous_pkt_type_t type) {
  switch(type) {
    case WIFI_PKT_MGMT: return "MGMT";
    case WIFI_PKT_DATA: return "DATA";
    case WIFI_PKT_CTRL: return "DATA";
    case WIFI_PKT_MISC: return "MISC";
    default: return "????";
  }
}

void packet_handler(void* buff, wifi_promiscuous_pkt_type_t type) {
  const wifi_promiscuous_pkt_t  *ppkt = (wifi_promiscuous_pkt_t *)buff;
  const wifi_ieee80211_packet_t *ipkt = (wifi_ieee80211_packet_t *)ppkt->payload;
  const wifi_ieee80211_mac_hdr_t *hdr = &ipkt->hdr;

  printf(
    "PACKET TYPE=%s, CHAN=%02d, RSSI=%02d,"
    " ADDR1=%02x:%02x:%02x:%02x:%02x:%02x,"
    " ADDR2=%02x:%02x:%02x:%02x:%02x:%02x,"
    " ADDR3=%02x:%02x:%02x:%02x:%02x:%02x\n",
    packet_type_to_str(type),
    ppkt->rx_ctrl.channel,
    ppkt->rx_ctrl.rssi,
    hdr->addr1[0],hdr->addr1[1],hdr->addr1[2],hdr->addr1[3],hdr->addr1[4],hdr->addr1[5],
    hdr->addr2[0],hdr->addr2[1],hdr->addr2[2],hdr->addr2[3],hdr->addr2[4],hdr->addr2[5],
    hdr->addr3[0],hdr->addr3[1],hdr->addr3[2],hdr->addr3[3],hdr->addr3[4],hdr->addr3[5]
  );
}
