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


  /*if (&NRF_RADIO == &blueRegister)  {Serial.println("OK Same address \n");}  // control   addresses  are the same
  else {Serial.println("KO Not same address \n");}
  */
}

void loop() {

  delay(1000);
  // put your main code here, to run repeatedly:

}
