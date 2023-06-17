#include "sensor-current2.h"
#include"variables/variables.h"

EnergyMonitor emon3;

void setupCurrentSensor3() {
    emon3.current(9, 1.35); 
}

void loopCurrentSensor3() {
    float Irms3 = (emon2.calcIrms(1480));

    // Assign to global sensing variables
    senseCurrent3 = Irms3;
}