#include <Arduino.h>
#include "devices-integration/devices-integration.h"

void setup() {
  Serial.begin(9600);

  completeSensorSetup();
  completeModuleSetup();
  completeSerialcomSetup();  
}

void loop() {
  puttingThingsTogether();
  delay(1000);
}