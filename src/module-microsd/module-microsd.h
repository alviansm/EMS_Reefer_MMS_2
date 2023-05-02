#ifndef MODULE_MICROSD
#define MODULE_MICROSD

#include <SPI.h>
#include <SD.h>
#include <Arduino.h>
#include "variables/variables.h"
#include "module-buzzer/module-buzzer.h"

void setupMicrosd();
void randomizeFileName();
void writeHeaderSDCard();
void completeSDCardSetup(); // setup()
void writeMonitorSDCard(); // loop()

#endif