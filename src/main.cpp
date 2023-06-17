#include <Arduino.h>
#include "devices-integration/devices-integration.h"
#include "module-buzzer/module-buzzer.h"
#include "module-relay/module-relay.h"
#include "module-tftlcd/module-tftlcd.h"

void setup() {  
  Serial.begin(9600);

  completeSensorSetup();
  completeModuleSetup();
  completeSerialcomSetup();
  buzzerStartFunc();
}

void loop() {
  loopLCD();
  calculationLoop();
  puttingThingsTogether();
}