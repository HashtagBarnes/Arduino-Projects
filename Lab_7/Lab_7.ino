#include <IRremote.h>
// IR Initialize
int IRpin = 6;
IRrecv IR(IRpin);
decode_results cmd;
String myCom;

//RGB Initialize
int rPin = 11;
int gPin = 10;
int bPin = 9;
int rBright = 255;
int gBright = 255;
int bBright = 255;
float dFact = 1;

void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  while (IR.decode(&cmd) == 0){
  }
  delay(1500);
  IR.resume();
  // ZERO
  if (cmd.value == 0xFF6897 && cmd.value == 16738455) {
    myCom = "zero";
    Serial.println(myCom);
  }
  // ONE
  if (cmd.value == 0xFF30CF && cmd.value == 16724175) {
    myCom = "one";
    Serial.println(myCom);
  }
  // TWO
  if (cmd.value == 0xFF18E7 && cmd.value == 16718055) {
    myCom = "two";
    Serial.println(myCom);
  }
  // THREE
  if (cmd.value == 0xFF7A85 && cmd.value == 16743045) {
    myCom = "three";
    Serial.println(myCom);
  }
  // FOUR
  if (cmd.value == 0xFF10EF && cmd.value == 16716015) {
    myCom = "four";
    Serial.println(myCom);
  }
  // FIVE
  if (cmd.value == 0xFF38C7 && cmd.value == 16726215) {
    myCom = "five";
    Serial.println(myCom);
  }
  // SIX
  if (cmd.value == 0xFF5AA5 && cmd.value == 16734885) {
    myCom = "six";
    Serial.println(myCom); 
  }
  // SEVEN
  if (cmd.value == 0xFF42BD && cmd.value == 16728765) {
    myCom = "seven";
    Serial.println(myCom);
  }
  // EIGHT
  if (cmd.value == 0xFF4AB5) {
    myCom = "eight";
    Serial.println(myCom);
  }
  // NINE
  if (cmd.value == 0xFF52AD) {
    myCom = "nine";
    Serial.println(myCom);
  }
  // EQ
  if (cmd.value == 0xFF9867) {
    myCom = "Equalizer";
    Serial.println(myCom);
  }
  // ST/REPT
  if (cmd.value == 0xFFB04F) {
    myCom = "ST/REPT";
    Serial.println(myCom);
  }
  // DWN
  if (cmd.value == 0xFFE01F) {
    myCom = "DWN";
    Serial.println(myCom);
  }
  // VOL DWN
  if (cmd.value == 0xFFA857) {
    myCom = "VOL DWN";
    Serial.println(myCom);
  }
  // UP
  if (cmd.value == 0xFF906F) {
    myCom = "UP";
    Serial.println(myCom);
  }
  // RWND
  if (cmd.value == 0xFF22DD) {
    myCom = "RWND";
    Serial.println(myCom);
  }
  // P/P
  if (cmd.value == 0xFF02FD) {
    myCom = "P/P";
    Serial.println(myCom);
  }
  // FFWD
  if (cmd.value == 0xFFC23D) {
    myCom = "FFWD";
    Serial.println(myCom);
  }
  // PWR
  if (cmd.value == 0xFFA25D) {
    myCom = "PWR";
    Serial.println(myCom);
  }
  // VOL UP
  if (cmd.value == 0xFF629D) {
    myCom = "VOL UP";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFFE21D) {
    myCom = "FUNC/STOP";
    Serial.println(myCom);
  }
  if (myCom=="pwr") {
    rBright = 255;
    gBright = 255;
    bBright = 255;
    dFact = 1;
  }
  if (myCom=="FUNC/STOP") {
    rBright = 0;
    gBright = 0;
    bBright = 0;
    dFact = 0;
  }
  if (myCom=="one") {
    rBright = 255;
    gBright = 0;
    bBright = 0;
  }
  if (myCom=="two") {
    rBright = 0;
    gBright = 128;
    bBright = 0;
  }
  if (myCom=="three") {
    rBright = 0;
    gBright = 0;
    bBright = 255;
  }
  if (myCom=="four") {
    rBright = 0;
    gBright = 255;
    bBright = 255;
  }
  if (myCom=="five") {
    rBright = 255;
    gBright = 0;
    bBright = 255;
  }
  if (myCom=="six") {
    rBright = 255;
    gBright = 255;
    bBright = 0;
  }
  if (myCom=="zero") {
    rBright = 255;
    gBright = 255;
    bBright = 255;
  }
  if (myCom=="DWN") {
    dFact = (0.1 - dFact);
    if (dFact <= 0) {
      dFact = 0.1;
    }
  }
  if (myCom=="UP") {
    dFact = (0.1 + dFact);
    if (dFact >= 1) {
      dFact = 1;
    }
  }

analogWrite(rPin, rBright*dFact);
analogWrite(gPin, gBright*dFact);
analogWrite(bPin, bBright*dFact);
  
}
