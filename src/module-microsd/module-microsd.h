#ifndef MODULE_MICROSD
#define MODULE_MICROSD

#include <SPI.h>
#include <SD.h>
#include <Arduino.h>

void setupMicrosd(); // setup()
void randomizeFileName(); // setup()
void writeHeaderSDCard(); // setup()
void writeMonitorSDCard(); // loop()

#endif
