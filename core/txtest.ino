#include "api0.h"

char xbuffer[1024];

cbrFun* radio;

void setup() {

  unsigned long dataAddr;
  // put your setup code here, to run once:
  delay(5000);
  Serial.begin(57600);
  Serial.println(BLUE_msg);
  
  rx2Serial();
  
  data_Config();

  //(*radio).txEn();
  (*radio).rxEn();
  
  //while(BLUE_txready==0);
  while(BLUE_rxready==0);
  
  (*radio).start();
  
  for(int i=0; i<240; i++){
  
    delay(250);
  
    if(BLUE_rtcomp){
    
      Serial.print("Bytes sent/received: ");      
      Serial.print(BLUE_data);
      Serial.print(" ");
      Serial.println((uint32_t) &xbuffer);

      Serial.println(BLUE_data - ((uint32_t) &xbuffer), HEX);
      (*radio).setdataPtr(xbuffer);
      (*radio).start();
      
      }
    Serial.print("iter: ");
    Serial.println(i);
    }
    
  (*radio).stop();
  
  (*radio).disable();

  Serial.println("completed.");
  Serial.println((uint32_t) &xbuffer, HEX);
  Serial.println(BLUE_data, HEX);

  Serial.end();
  }

void data_Config(){
  xbuffer[0] = 32;
  for(int i=0; i<255; i++){
    xbuffer[i+1] = i;
    }
  }

  
void rx2Serial(){

  cbrFun radioRX(1); //mode 1
  
  radioRX.setchannel(10);
  radioRX.config.tx_str = 0xFF - 16;
  radioRX.setdataPtr(xbuffer);
  radioRX.setconfig();

  radioRX.localaddr();
  radioRX.remoteaddr(0, 0x0, 0x0);
  radioRX.enableremote(0);
  
  radio = &radioRX;
  }
  
void loop(){

  delay(500);
}
