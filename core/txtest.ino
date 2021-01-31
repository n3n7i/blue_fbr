include "api0.h"

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

  (*radio).txEn();
  
  while(BLUE_txready==0);
  
  (*radio).start();
  
  for(int i=0; i<10; i++){
  
    delay(250);
  
    if(BLUE_rtcomp){
    
      Serial.print("Bytes sent: ");      
      Serial.println((&BLUE_data) - (&xbuffer), HEX);      
      (*radio).setdataPtr(&xbuffer);
      (*radio).start();
      
      }
    
    }
    
  (*radio).stop();
  
  (*radio).disable();
    
  }

void data_Config(){
  xbuffer[0] = 127;
  for(int i=0; i<127; i++){
    xbuffer[i] = i;
    }
  }

  
void rx2Serial(){

  cbrFun radioRX(1); //mode 1
  
  radioRX.setchannel(10);
  radioRX.config.tx_str = 0xFF - 16;
  radioRX.setdataPtr(&xbuffer);
  radioRX.setconfig();
  
  radio = radioRX;
  }
  
void loop(){

  delay(500);
}
