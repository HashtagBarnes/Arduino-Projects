#include <IRremote.h>

int IRpin = 9;
IRrecv IR(IRpin);
decode_results cmd;
String myCom;

void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
}

void loop() {
  while (IR.decode(&cmd) == 0){
  }
  delay(1500);
  IR.resume();
  if (cmd.value == 0xFF6897 && cmd.value == 16738455) {
    myCom = "zero";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF30CF && cmd.value == 16724175) {
    myCom = "one";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF18E7 && cmd.value == 16718055) {
    myCom = "two";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF7A85 && cmd.value == 16743045) {
    myCom = "three";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF10EF && cmd.value == 16716015) {
    myCom = "four";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF38C7 && cmd.value == 16726215) {
    myCom = "five";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF5AA5 && cmd.value == 16734885) {
    myCom = "six";
    Serial.println(myCom); 
  }
  if (cmd.value == 0xFF42BD && cmd.value == 16728765) {
    myCom = "seven";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF4AB5) {
    myCom = "eight";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF52AD) {
    myCom = "nine";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF9867) {
    myCom = "Equalizer";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFFB04F) {
    myCom = "ST/REPT";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFFE01F) {
    myCom = "DWN";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFFA857) {
    myCom = "VOL DWN";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF906F) {
    myCom = "UP";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF22DD) {
    myCom = "RWND";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF02FD) {
    myCom = "P/P";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFFC23D) {
    myCom = "FFWD";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFFA25D) {
    myCom = "PWR";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFF629D) {
    myCom = "VOL UP";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFFE21D) {
    myCom = "FUNC/STOP";
    Serial.println(myCom);
  }
}
