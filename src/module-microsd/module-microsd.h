#ifndef MODULE_MICROSD
#define MODULE_MICROSD

#include <SPI.h>
#include <SD.h>
#include <Arduino.h>

void setupMicrosd();
void randomizeFileName();
void writeHeaderSDCard();
void completeSDCardSetup(); // setup()
void writeMonitorSDCard(); // loop()

#endif