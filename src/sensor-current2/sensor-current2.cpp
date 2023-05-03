#include "sensor-current2.h"
#include"variables/variables.h"

EnergyMonitor emon2;

void setupCurrentSensor2() {
    emon2.current(8, 100.11); 
}

void loopCurrentSensor2() {
    int Irms2 = (emon2.calcIrms(1480)/100);

    // Assign to global sensing variables
    senseCurrent2 = String(Irms2);
}