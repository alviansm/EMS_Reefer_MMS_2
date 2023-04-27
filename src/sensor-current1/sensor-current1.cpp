#include "sensor-current1.h"
#include "variables/variables.h"

EnergyMonitor emon1;

void setupCurrentSensor1() {
    emon1.current(1, 100.11); 
}

void loopCurrentSensor1() {
    double Irms = (emon1.calcIrms(1480)/100);

    // Assign to global sensing variables
    senseCurrent1 = String(Irms);
}