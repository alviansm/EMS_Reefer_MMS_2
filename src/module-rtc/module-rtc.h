#ifndef MODULE_RTC
#define MODULE_RTC

#include <Arduino.h>
#include "uRTCLib.h" // RTC DS1307 Dependency

void setupRtc();
void loopTime();

#endif