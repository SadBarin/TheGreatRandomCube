#include <Arduino.h>

/*
  The Great Random Cube
  Author: SadBarin
  Date: 17.06.2021
  
  For Arduino Nano Atmega 328
*/

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void serialPrintRandomNumber(int dots) {
  Serial.print("Your random dots: ");
  Serial.println(dots);
}

int getRandomDots() {
  return random(1, 7);
}

void setRandomDots(int delayLight, int dots) {
  for (int i = 0; i <= dots + 1; i++) {
    digitalWrite(i, HIGH);
  }

  if (delayLight > 0) {
    delay(delayLight);
  } else if (delayLight == 0) {
    do {}
    while (true);
  }

  for (int i = 0; i <= dots + 1; i++) {
    digitalWrite(i, LOW);
  }
}

void loop() {
  int dots = getRandomDots();
  serialPrintRandomNumber(dots);
  for (int i = 0; i < 50; i++) {
    setRandomDots(100, dots);
  }
  setRandomDots(0, dots);
}