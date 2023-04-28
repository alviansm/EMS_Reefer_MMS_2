#ifndef SENSOR_HUMIDITY
#define SENSOR_HUMIDITY

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include "variables/variables.h"

void setupHumiditySensor();
void loopHumiditySensor();

#endif