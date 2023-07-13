#ifndef CALCULATION_FUNCTIONS
#define CALCULATION_FUNCTIONS

#include <Arduino.h>
#include "math.h"
#include "variables/variables.h"
#include "module-rtc/module-rtc.h"
#include "module-buzzer/module-buzzer.h"

void temperature1ToLEnthalpy();
void temperature2ToEnthalpy();
void temperature3ToEnthalpy();
void calculateCOP();
void calculatePower();
void calculatePCM1PickLoad();
void ecoActivation();
void mqtt_switch();
void run_setpoint_temperature();

#endif