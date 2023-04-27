#include <Arduino.h>

#include "variables/variables.h"

// Sensors
#include "sensor-temperature/sensor-temperature.h"
#include "sensor-current1/sensor-current1.h"
#include "sensor-current2/sensor-current2.h"

// Modules
#include "module-buzzer/module-buzzer.h"
#include "module-microsd/module-microsd.h"
#include "module-rtc/module-rtc.h"
#include "module-relay/module-relay.h"

// Serial Communication - Devices
#include "serialcom-nextion/serialcom-nextion.h"
#include "serialcom-esp/serialcom-esp.h"

void setup() {
  Serial.begin(9600);

  setupBuzzer();
  setupTemperatureSensor();
}

void loop() {
  buzzerSOSFunc();
  loopTemperatureSensors();
  randomizeFileName();
  Serial.print("Halo: ");
  Serial.print(SDCardFileName);
  Serial.println();
}