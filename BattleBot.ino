#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;

int VRx = A0;
int VRy = A1;
int SW = 2;
int Laserscanner = 9;

void setup() {
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
  s1.attach(9);
  s2.attach(10);
  s3.attach(11);
  Serial.begin(9600);
}

void loop() {
}

// X-Value Control

int ServoOneControl() {
  int ServoOneVal;
  ServoOneVal = analogRead(VRx);
  ServoOneVal = map (ServoOneVal, 0, 1023, 0, 180);
  s1.write(ServoOneVal);
  delay(15);
}

// Y-Value Control

int ServoTwoControl() {
  int ServoTwoVal;
  ServoTwoVal = analogRead(VRy);
  ServoTwoVal = map(ServoTwoVal, 3, 1023, 0, 176);
  s2.write(ServoTwoVal);
  delay(15);
}

// DEBUG Function

int DebugFunction() {
  int ServoXVal;
  int ServoYVal;
  ServoXVal = analogRead(VRx);
  ServoYVal = analogRead(VRy);
  Serial.print("X Value:");
  Serial.println (ServoXVal);
  delay(1000);
  Serial.println ("Y Value:");
  Serial.println (ServoYVal);
  delay(1000);
}
