#include <Arduino.h>
#include "devices-integration/devices-integration.h"
#include "module-buzzer/module-buzzer.h"
#include "module-relay/module-relay.h"

void setup() {
  Serial.begin(9600);

  completeSensorSetup();
  completeModuleSetup();
  completeSerialcomSetup();
  buzzerStartFunc();
}

void loop() {
  calculationLoop();
  puttingThingsTogether();
  Serial.println();
  Serial.print(relaystate1);
  Serial.print(relaystate2);
  Serial.print(relaystate3);
  Serial.print(relaystate4);
  Serial.println();
}