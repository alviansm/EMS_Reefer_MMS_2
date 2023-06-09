#ifndef VARIABLES
#define VARIABLES

#include <Arduino.h>

extern String senseTimeDay;
extern String senseTimeDate;
extern String senseTimeClock;
extern String senseTime;

extern String senseTemperature1;
extern String senseTemperature2;
extern String senseTemperature3;
extern String senseTemperature4;
extern String senseTemperature5;
extern String senseTemperature6;
extern String senseTemperature7;
extern String senseTemperature8;
extern String senseTemperatureHumid;
extern String senseHumid;
extern String senseCurrent1;
extern String senseCurrent2;
extern String senseCurrent3;
extern String senseVoltage;
extern String sensePressure;
extern String senseTemperature9;
extern String senseTemperature10;
extern String senseTemperature11;
extern String senseTemperature12;
extern String sensePT1;
extern String sensePT2;
extern String sensePT3;
extern String sensePT4;
extern int relaystate1;
extern int relaystate2;
extern int relaystate3;
extern int relaystate4;
extern String calculatedCOP;
extern float enthalpy4;
extern float enthalpy3;
extern float enthalpy2;
extern float enthalpy1;
extern float tempOutEvap;
extern float tempInEvap;
extern String calculatedPower;
extern String calculatedUptime;
extern String calculatedPCM1Pickload;
extern String calculatedFP;
extern String calculatedIteration;
extern String calculatedPrice;
extern String calculatedCharging;
extern String fullData;
extern int currentNextionPage;
extern bool is_eco_active;
extern String mqtt_received_message;

#endif