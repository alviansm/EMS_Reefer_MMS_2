#include "devices-integration.h"

void completeSensorSetup() {
    setupTemperatureSensor();
    setupTemperatureSensor1();
    setupCurrentSensor1();
    setupCurrentSensor2();
    setupCurrentSensor3();
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
    mqtt_switch();
    run_setpoint_temperature();
}

void puttingThingsTogether() {
    loopTime();
    loopTemperatureSensors();
    // loopTemperatureSensors1();
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
    receiveDataFromESP();
    // updateNextionDashboard();
    // updateNextionDetails();
}