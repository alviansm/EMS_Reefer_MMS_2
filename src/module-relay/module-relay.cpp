#include "module-relay.h"

// ==== RELAY CONFIGURATION ====
int relay_1 = 49;
int relay_2 = 48;
int relay_3 = 47;
int relay_4 = 46;

void setupRelay() {
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
  digitalWrite(relay_3, LOW);
  digitalWrite(relay_4, LOW);    
}

void relayOn1() {
  relaystate1 = 1;
  digitalWrite(relay_1, LOW);
  return;
}

void relayOff1() {
  relaystate1 = 0;
  digitalWrite(relay_1, HIGH);
  return;
}

void relayStandBy() {
  if (relaystate1 == 1) {
    relayOn1();
    return;
  }
  if (relaystate1 == 0) {
    relayOff1();
    return;
  }
}