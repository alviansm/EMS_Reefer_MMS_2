#ifndef SENSOR_TEMPERATURE
#define SENSOR_TEMPERATURE

#include <OneWire.h> // DS18B20
#include <DallasTemperature.h> // DS18B20

void printAddress(DeviceAddress deviceAddress);
void setupTemperatureSensor();
void loopTemperatureSensors();

#endif