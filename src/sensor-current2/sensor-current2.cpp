#include "sensor-current2.h"
#include"variables/variables.h"

EnergyMonitor emon2;

void setupCurrentSensor2() {
    emon2.current(11, 1.35); 
}

void loopCurrentSensor2() {
    float Irms2 = (emon2.calcIrms(1480));

    // Assign to global sensing variables
    senseCurrent2 = Irms2;
}