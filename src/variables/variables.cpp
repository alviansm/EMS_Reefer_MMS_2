#include "variables.h"

// ==== SENSING VARIABLES FROM SENSOR ====
String senseTimeDay = "";
String senseTimeDate = "";
String senseTimeClock = "";
String senseTime = "";

String senseTemperature1 = "";
String senseTemperature2 = "";
String senseTemperature3 = "";
String senseTemperature4 = "";
String senseTemperature5 = "";
String senseTemperature6 = "";
String senseTemperature7 = "";
String senseTemperature8 = "";
String senseTemperatureHumid = "";
String senseHumid = "";
float senseCurrent1 = 0;
float senseCurrent2 = 0;
String senseVoltage = "220.00";
String sensePressure = "";

// ==== RELAY STATE VARIABELS ====
int relaystate1 = 1;
int relaystate2 = 1;
int relaystate3 = 1;
int relaystate4 = 1;

// ==== VARIABLES TO CALCUALTE COPs ====
String calculatedCOP = "";
float enthalpy4 = 0.00;
float enthalpy3 = 0.00;
float enthalpy2 = 0.00;
float enthalpy1 = 0.00;
float tempOutEvap = 0.00;
float tempInEvap = 0.00;
String calculatedPower = "";
String calculatedUptime = "14";
String calculatedPCM1Pickload = "";
String calculatedFP = "-15";
String calculatedIteration = "0";
String calculatedPrice = "1444";
String calculatedCharging = "0";

// ==== Full Data Row ====
String fullData = "";
bool is_eco_active = false;

// ==== Nextion Display Variables ====
int currentNextionPage = 0;
