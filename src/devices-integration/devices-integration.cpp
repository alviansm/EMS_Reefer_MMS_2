#include "devices-integration.h"

void completeSensorSetup() {
    setupTemperatureSensor();
    setupCurrentSensor1();
    setupCurrentSensor2();
    setupHumiditySensor();
}

void completeModuleSetup() {
    setupRelay();
    setupBuzzer();
    setupMicrosd();
    setupRtc();
    setupLCD();
    initializeInitiation();
}

void completeSerialcomSetup() {
    // setupSerialcomNextion();
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
    loopCurrentSensor3();
    sensorPressureLoop();
    sensorPressureLoop2();
    sensorPressureLoop3();
    sensorPressureLoop4();
    relayStandBy();
    writeMonitorSDCard();
    sendDataToESP();
    // updateNextionDashboard();
    // updateNextionDetails();
}