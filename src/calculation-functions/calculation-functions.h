#ifndef CALCULATION_FUNCTIONS
#define CALCULATION_FUNCTIONS

#include <Arduino.h>
#include "variables/variables.h"
#include "module-rtc/module-rtc.h"

void temperature1ToLEnthalpy();
void temperature2ToEnthalpy();
void temperature3ToEnthalpy();
void calculateCOP();
void calculatePower();
void calculatePCM1PickLoad();

#endif