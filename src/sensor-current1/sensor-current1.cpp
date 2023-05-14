#include "sensor-current1.h"
#include "variables/variables.h"

EnergyMonitor emon1;

void setupCurrentSensor1() {
    emon1.current(12, 100.11); // (Pin, Calibration)
}

void loopCurrentSensor1() {
    int Irms = (emon1.calcIrms(1480)/100);

    // Assign to global sensing variables
    senseCurrent1 = String(Irms);
}