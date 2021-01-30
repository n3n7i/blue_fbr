
#include "Arduino.h"

#ifndef fbrCore_h
#define fbrCore_h

//#define blueRegister _SFR_IO8(0x40001000)

#ifdef NRF_RADIO
#define BLUE_msg "radio found"
#define BLUE_state NRF_RADIO->STATE
#define BLUE_power NRF_RADIO->POWER
#define BLUE_txpower NRF_RADIO->TXPOWER
#define BLUE_mode NRF_RADIO->MODE

#define BLUE_init NRF_RADIO->TASKS_START
#define BLUE_end NRF_RADIO->TASKS_STOP
#define BLUE_disable NRF_RADIO->TASKS_DISABLE

#define BLUE_txen NRF_RADIO->TASKS_TXEN
#define BLUE_rxen NRF_RADIO->TASKS_RXEN

#define BLUE_data NRF_RADIO->PACKETPTR
#define BLUE_channel NRF_RADIO->FREQUENCY

#define BLUE_sfd NRF_RADIO->SFD

#define BLUE_cfg0 NRF_RADIO->PCNF0
#define BLUE_cfg1 NRF_RADIO->PCNF1

#define BLUE_dab32x NRF_RADIO->DAB //[0..7]
#define BLUE_dap16x NRF_RADIO->DAP //[0..7]

#define BLUE_baddr0 NRF_RADIO->BASE0
#define BLUE_baddr1 NRF_RADIO->BASE1

#define BLUE_pref03 NRF_RADIO->PREFIX0
#define BLUE_pref47 NRF_RADIO->PREFIX1

#define BLUE_txaddr NRF_RADIO->TXADDRESSES //&0x7
#define BLUE_rxaddr NRF_RADIO->RXADDRESSES //&0xFF

#define BLUE_ready NRF_RADIO->EVENTS_READY

#define BLUE_txready NRF_RADIO->EVENTS_TXREADY
#define BLUE_rxready NRF_RADIO->EVENTS_RXREADY

#define BLUE_rtcomp NRF_RADIO->EVENTS_END
#define BLUE_crcok NRF_RADIO->EVENTS_CRCOK

#define BLUE_short NRF_RADIO->SHORTS

enum stateBlue {BL_disable, BL_rxru, BL_rxidle, BL_rx, BL_rxdisable};
enum stateBluetx {BL_txru = BL_rxru+8, BL_txidle = BL_rxidle+8, BL_tx = BL_rx+8, BL_txdisable = BL_rxdisable+8};

class confBLUE{

  public:
    confBLUE(int s, uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e);
    confBLUE(int s);
    int standard;
    uint8_t len_offset;
    uint8_t len_field;
    uint8_t tx_str;
    uint8_t len_preamb;
    uint8_t len_addr;
    
  };

confBLUE::confBLUE(int s, uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e){
  standard = s; len_offset=a; len_field=b; tx_str=c; len_preamb=d; len_addr=e;
  }

confBLUE::confBLUE(int s){
  if(s==1){ 
    confBLUE(s, 0, 8, 0, 1, 2);
  }
  
}

/*
Nrf_1Mbit       0
1 Mbit/s Nordic proprietary radio mode
pream =x

Nrf_2Mbit       1
2 Mbit/s Nordic proprietary radio mode
pream =x

Ble_1Mbit       3 
1 Mbit/s BLE
pream =0

Ble_2Mbit       4
2 Mbit/s BLE
pream =1

Ble_LR125Kbit   5 
Long range 125 kbit/s TX, 125 kbit/s and 500 kbit/s RX
pream= 3

Ble_LR500Kbit   6 
Long range 500 kbit/s TX, 125 kbit/s and 500 kbit/s RX
pream= 3

Ieee802154_250Kbit    15 
IEEE 802.15.4-2006 250 kbit/s
pream = 2
*/

#endif


#ifndef BLUE_msg
#define BLUE_msg "definition unknown"
#define BLUE_state "-1"
#define BLUE_power "-1"
#endif

#endif
