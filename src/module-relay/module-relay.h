#ifndef MODULE_RELAY
#define MODULE_RELAY

#include <Arduino.h>
#include "variables/variables.h"

void setupRelay(); // setup()
void relayStandBy(); // loop()

void relayOn1();
void relayOff1();
void relayOn2();
void relayOff2();
void relayOn3();
void relayOff3();
void relayOn4();
void relayOff4();

#endif