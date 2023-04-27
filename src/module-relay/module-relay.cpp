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
