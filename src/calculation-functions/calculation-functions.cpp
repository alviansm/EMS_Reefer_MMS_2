#include "calculation-functions.h"

int sampelPCM1;
int sampelPCM2;

void temperature1ToLEnthalpy(){
  // Enthalpy at state 1 is determined by linear regression using equation that obtained by using Freon R-404a saturation table.
  // State 1 of the cycle is supposed to be sat. vapor
  float temperatureState1 = senseTemperature4.toFloat(); // make sure senseTemperature4 is inlet compressor
  enthalpy1 = ((0.5334*(temperatureState1))+363.52); 
}

void temperature2ToEnthalpy() {
  // State 2 of the cycle is supposed to be sat. vapor
  float temperatureState2 = senseTemperature6.toFloat(); // make sure senseTemperature6 is inlet condensor
  enthalpy2 = ((0.5334*temperatureState2)+363.52);
}

void temperature3ToEnthalpy() {
  // State 3 of the cycle is supposed to be sat. liquid
  float temperatureState3 = senseTemperature2.toFloat(); // make sure senseTemperature2 is inlet txv
  enthalpy3 = ((1.4143*temperatureState3)+206.36);
  // Assuming ideal cycle, enthalpy at state 4 is equal to enthalpy at state 3
  enthalpy4 = enthalpy3;
}

void calculateCOP() {
  temperature1ToLEnthalpy();
  temperature2ToEnthalpy();
  temperature3ToEnthalpy();
  if ((enthalpy2-enthalpy1) <= 0) {
    calculatedCOP = String(0.00);
  } else {
    calculatedCOP = String((enthalpy1-enthalpy4)/(enthalpy2-enthalpy1));
  }
}

void calculatePower() {
  calculatedPower = String(String((senseCurrent2)*220.00*0.80).toInt());
}

void calculatePCM1PickLoad() {
  calculatedPCM1Pickload = "14"; // 6 hours by default
}

void ecoActivation() {
  sampelPCM1 = senseTemperature3.toInt(); // make sure the variable is from the correct sensor
  sampelPCM2 = senseTemperature7.toInt(); // OK - 16.05.2023

  if (is_eco_active) {
    // skip if there's data error / noise
    if ((sampelPCM1 == -127) || (sampelPCM2 == -127) || (senseTemperature5.toInt() == -127)) {
      return;
    }
    // turn off vapor compression refrigeration cycle after pch is charged. (14 hours based on the calculation)
    // if ((calculatedCharging.toInt() == 14) && (sampelPCM1 <= -10) && (sampelPCM2 <= -10)) {
    // if (senseTemperature5.toInt() >= 35) {
    //   relaystate1 = 0; // turn off compressor & condensor relay
    //   calculatedCharging = "0"; // reset PCM charging
    //   return;
    // }
    if (calculatedCharging.toInt() == 14) { // for demonstration purpose
      relaystate1 = 0; // turn off compressor & condensor relay
      calculatedCharging = "0"; // reset PCM charging
      return;
    }
    // second charging, add temperature parameter
    if ((calculatedUptime.toInt() >= 14) && (sampelPCM1 <= -14 && sampelPCM2 <= -14)) {
      relaystate1 = 0; // turn off compressor & condensor relay
      calculatedCharging = "0"; // reset PCM charging
      return;
    }
    if ((sampelPCM1 >= -10) && (sampelPCM2 >= -10) && (relaystate1 == 0)) { // if pcm is discharged to -10, and relay for vapor-compression is off, then turn on it's relay for charging again
    // if (senseTemperature5.toInt() >= 40) { // for demo purpose, use ambient temperature
    delay(10000);
    relaystate1 = 1; // turn on relay state
    return;
    }
  }  
}