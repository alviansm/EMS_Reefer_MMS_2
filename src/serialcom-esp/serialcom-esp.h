#ifndef SERIALCOM_ESP
#define SERIALCOM_ESP

#include <Arduino.h>
#include <SoftwareSerial.h>

#include "variables/variables.h"

void setupESP32();
void sendDataToESP();
void receiveDataFromESP();

#endif