#include "sensor-current1.h"
#include "variables/variables.h"

EnergyMonitor emon1;

void setupCurrentSensor1() {
    emon1.current(12, 0.6); // (Pin, Calibration)
}

void loopCurrentSensor1() {
    int Irms = (emon1.calcIrms(1480));

    // Assign to global sensing variables
    senseCurrent1 = String(Irms);
}