
#include "core.h"

class cbrFun{

  public:
    cbrFun(confBLUE x);
    cbrFun(int standard);
    confBLUE config;
    
    void txEn();
    void rxEn();

    void start();
    void stop();
    void disable();

    void setconfig();
    void setchannel(uint8_t c);
    void setdataPtr(uint8_t* d)
  };


cbrFun::cbrFun(confBLUE x){
  config = x;
  }

cbrFun::cbrFun(int standard){
  config = confBLUE(standard);
  }

void cbrFun::txEn(){
  BLUE_txen = 1;
  }

void cbrFun::rxEn(){
  BLUE_rxen = 1;
  }


void cbrFun::start(){
  BLUE_init = 1;
  }

void cbrFun::stop(){
  BLUE_end = 1;
  }

void cbrFun::disable(){
  BLUE_disable = 1;
  }

void cbrFun::setconfig(){

//// 030F010F [preamb || S1 len bits || S0 len bytes || len bits]
//BLUE_cfg1 = 0x200FF; // 2+1B addr, 0 static, maxlen 255 //

  BLUE_cfg0 = (config.len_preamb & 0x03) << 24 | 0x08; // length field 8 bits  
  BLUE_cfg1 = (config.len_addr & 0x07) << 16 | config.len_field;

//  BLUE_data = dataaddr?
//  BLUE_channel = channel?

  BLUE_txpower = config.tx_str;
  BLUE_mode = config.standard;
  }

void cbrFun::setchannel(uint8_t c){
  BLUE_channel = c;
  }

void cbrFun::setdataPtr(uint8_t* d){
  BLUE_data = d;
  }


  
