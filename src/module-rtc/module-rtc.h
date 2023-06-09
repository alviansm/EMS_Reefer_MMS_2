#ifndef MODULE_RTC
#define MODULE_RTC

#include <Arduino.h>
#include "uRTCLib.h" // RTC DS1307 Dependency
#include "variables/variables.h"

void setupRtc();
void determineDay();
void initializeInitiation();
void calculateUptime();
void calculateChargeTime();
void loopTime();

#endif