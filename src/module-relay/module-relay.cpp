#include "module-relay.h"

// ==== RELAY CONFIGURATION ====
int relay_1 = 34;
int relay_2 = 35;
int relay_3 = 36;
int relay_4 = 37;
int relay_5 = 38;
int relay_6 = 39;

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
}

void relayOff1() {
  relaystate1 = 0;
  digitalWrite(relay_1, LOW);
}

void relayOn2() {
  relaystate2 = 1;
  digitalWrite(relay_2, HIGH);
}

void relayOff2() {
  relaystate2 = 0;
  digitalWrite(relay_2, LOW);
}

void relayOn3() {
  relaystate3 = 1;
  digitalWrite(relay_3, HIGH);
}

void relayOff3() {
  relaystate3 = 0;
  digitalWrite(relay_3, LOW);
}

void relayOn4() {
  relaystate4 = 1;
  digitalWrite(relay_4, HIGH);
}

void relayOff4() {
  relaystate4 = 0;
  digitalWrite(relay_4, LOW);
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
  if (relaystate4 == 1) {
    relayOn4();
  }
  if (relaystate4 == 0) {
    relayOff4();
  }
}