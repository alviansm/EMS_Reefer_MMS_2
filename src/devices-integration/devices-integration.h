#ifndef DEVICES_INTEGRATION
#define DEVICES_INTEGRATION

#include <Arduino.h>

// sensors
#include "sensor-temperature/sensor-temperature.h"
#include "sensor-current1/sensor-current1.h"
#include "sensor-current2/sensor-current2.h"
#include "sensor-humidity/sensor-humidity.h"

// modules
#include "module-buzzer/module-buzzer.h"
#include "module-microsd/module-microsd.h"
#include "module-relay/module-relay.h"
#include "module-rtc/module-rtc.h"
#include "module-tftlcd/module-tftlcd.h"

// serialcom
#include "serialcom-nextion/serialcom-nextion.h"
#include "serialcom-esp/serialcom-esp.h"

// calculation functions
#include "calculation-functions/calculation-functions.h"

// functions
void completeSensorSetup();
void completeModuleSetup();
void completeSerialcomSetup();
void calculationLoop();
void puttingThingsTogether();

#endif