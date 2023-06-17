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
  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, HIGH);
  digitalWrite(relay_3, HIGH);
  digitalWrite(relay_4, HIGH);    
}

void relayOn1() {
  relaystate1 = 1;
  digitalWrite(relay_1, HIGH);
  return;
}

void relayOff1() {
  relaystate1 = 0;
  digitalWrite(relay_1, LOW);
  return;
}

void relayOn2() {
  relaystate2 = 1;
  digitalWrite(relay_2, HIGH);
  return;
}

void relayOff2() {
  relaystate2 = 0;
  digitalWrite(relay_2, LOW);
  return;
}

void relayOn3() {
  relaystate3 = 1;
  digitalWrite(relay_3, HIGH);
  return;
}

void relayOff3() {
  relaystate3 = 0;
  digitalWrite(relay_3, LOW);
  return;
}

void relayStandBy() {
  if (relaystate1 == 1) {
    relayOn1();
  }
  if (relaystate1 == 0) {
    relayOff1();
  }
  if (relaystate2 == 1) {
    relayOn2();
  }
  if (relaystate2 == 0) {
    relayOff2();
  }
  if (relaystate3 == 1) {
    relayOn3();
  }
  if (relaystate3 == 0) {
    relayOff3();
  }
}