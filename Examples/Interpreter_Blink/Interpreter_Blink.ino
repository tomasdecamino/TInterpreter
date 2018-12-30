/*
   Sophisticated Blink
   Written by Tomas de Camino Beck for FunCR

*/

#include "TInterpreter.h"

#define LED 13
#define TIME 100

String cmd;

TInterpreter interpreter(3);//commands to use

void setup() {
  // add command (char) and corresponding function with "&" prefix
  interpreter.add('P', &ledOn);
  interpreter.add('A', &ledOff);
  interpreter.add('+', &timeDelay);

  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    cmd = Serial.readStringUntil('\n');//
    Serial.flush();
  }
  interpreter.execute(cmd);
}

//function definitions

void ledOn() {
  digitalWrite(13,HIGH);
}

void ledOff() {
  digitalWrite(13,LOW);
}

void timeDelay() {
  delay(TIME);
}
