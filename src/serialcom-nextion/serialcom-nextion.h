#ifndef SERIALCOM_NEXTION
#define SERIALCOM_NEXTION

#include <Arduino.h>
#include <SoftwareSerial.h>

void setupSerialcomNextion();
void nextionWrite();
void updateNextionDashboard();
void updateNextionDetails();

#endif