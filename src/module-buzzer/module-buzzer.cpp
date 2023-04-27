#include "module-buzzer.h"

int buzzerPin = 5;

void setupBuzzer() {
    pinMode(buzzerPin, OUTPUT);
}

void buzzerStartFunc() {
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  delay(50);
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  delay(50);
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  delay(200);
}
void buzzerSOSFunc(){
  // S
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  delay(50);
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  delay(50);
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  delay(200);
  // O
  delay(50);
  tone(buzzerPin, 1000);
  delay(150);
  noTone(buzzerPin);
  delay(50);
  tone(buzzerPin, 1000);
  delay(150);
  noTone(buzzerPin);
  delay(50);
  tone(buzzerPin, 1000);
  delay(150);
  noTone(buzzerPin);
  delay(200);
  // S
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  delay(50);
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  delay(50);
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  delay(200);
  delay(50);
}
void buzzerInitiating(){
  //I
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  delay(50);
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  delay(50);
}
