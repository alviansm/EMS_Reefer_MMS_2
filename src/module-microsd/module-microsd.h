#ifndef MODULE_MICROSD
#define MODULE_MICROSD

#include <SPI.h>
#include <SdFat.h>
#include <Arduino.h>
#include "variables/variables.h"
#include "module-buzzer/module-buzzer.h"
#include "serialcom-esp/serialcom-esp.h"

void setupMicrosd(); // loop
void writeMonitorSDCard(); // loop()

#endif