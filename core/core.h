
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

#endif


#ifndef BLUE_msg
#define BLUE_msg "definition unknown"
#define BLUE_state "-1"
#define BLUE_power "-1"
#endif

#endif
