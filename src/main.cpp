#include <Arduino.h>
#include "devices-integration/devices-integration.h"
#include "module-buzzer/module-buzzer.h"

void setup() {
  Serial.begin(9600);

  completeSensorSetup();
  completeModuleSetup();
  completeSerialcomSetup();
  buzzerStartFunc();
}

void loop() {
  puttingThingsTogether();
  Serial.println(relaystate1);
  Serial.print(relaystate2);
  Serial.print(relaystate3);
  Serial.print(relaystate4);
  delay(1000);
}