#include "devices-integration.h"

void completeSensorSetup() {
    setupTemperatureSensor();
    setupCurrentSensor1();
    setupCurrentSensor2();
    setupHumiditySensor();
}

void completeModuleSetup() {
    setupBuzzer();
    setupMicrosd();
    setupRelay();
    setupRtc();
    writeHeaderSDCard();
}

void completeSerialcomSetup() {
    setupSerialcomNextion();
    setupESP32();
}

void calculationLoop() {
    calculateCOP();
    calculatePower();
    calculateUptime();
    calculateChargeTime();
    ecoActivation();
}

void puttingThingsTogether() {
    loopTime();
    loopTemperatureSensors();
    loopHumiditySensor();
    loopCurrentSensor1();
    loopCurrentSensor2();
    relayStandBy();
    writeMonitorSDCard();
    updateNextionDashboard();
    updateNextionDetails();
}