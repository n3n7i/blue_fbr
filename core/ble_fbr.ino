#include "core.h"


char xbuffer[1024];

void setup() {

  unsigned long dataAddr;
  // put your setup code here, to run once:
  delay(5000);
  Serial.begin(57600);
  Serial.println(BLUE_msg);

  Serial.println(BLUE_state);
  Serial.println(BLUE_power);

  Serial.println(BLUE_sfd, HEX);

  dataAddr = BLUE_data;
  Serial.println(dataAddr, HEX);

  dataAddr = (long) &xbuffer;
  Serial.println(dataAddr, HEX);

  BLUE_data = dataAddr;

  dataAddr = BLUE_data;
  Serial.println(dataAddr, HEX);

  dataAddr = (long) &BLUE_dab32x[3];
  Serial.println(dataAddr, HEX);

  dataAddr = BLUE_dab32x[0];
  Serial.println(dataAddr, HEX);

  dataAddr = BLUE_dap16x[0];
  Serial.println(dataAddr, HEX);

  
  Serial.println(BLUE_baddr0, HEX);
  Serial.println(BLUE_baddr1, HEX);

  //Serial.println(dataAddr, HEX);

  delay(500);

  BLUE_cfg1 = 0x200FF;

  BLUE_rxen = 1;

  delay(500);
  while(BLUE_ready ==0);

  Serial.println(BLUE_state);
  Serial.println(BLUE_power);

  Serial.println(BLUE_sfd, HEX);

  delay(500);

  BLUE_disable=1;

  Serial.println(BLUE_state);
  Serial.println(BLUE_power);


  /*if (&NRF_RADIO == &blueRegister)  {Serial.println("OK Same address \n");}  // control   addresses  are the same
  else {Serial.println("KO Not same address \n");}
  */
}

void loop() {

  delay(1000);
  // put your main code here, to run repeatedly:

}
