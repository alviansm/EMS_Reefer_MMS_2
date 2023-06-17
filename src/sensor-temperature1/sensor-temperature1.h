#ifndef SENSOR_TEMPERATURE1
#define SENSOR_TEMPERATURE1

#include <OneWire.h> // DS18B20
#include <DallasTemperature.h> // DS18B20

void printAddress(DeviceAddress deviceAddress);
void setupTemperatureSensor1();
void loopTemperatureSensors1();

#endif