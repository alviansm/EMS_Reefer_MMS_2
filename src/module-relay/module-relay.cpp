#include "module-relay.h"

// ==== RELAY CONFIGURATION ====
int relay_1 = 22;
int relay_2 = 23;
int relay_3 = 24;
int relay_4 = 25;

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
}

void relayOff1() {
  relaystate1 = 0;
  digitalWrite(relay_1, HIGH);
}

void relayStandBy() {
  if (relaystate1 == 1) {
    relayOn1();
  }
  if (relaystate1 == 0) {
    relayOff1();
  }
}