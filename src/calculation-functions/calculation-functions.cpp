#include "calculation-functions.h"

void temperature1ToLEnthalpy(){
  // Enthalpy at state 1 is determined by linear regression using equation that obtained by using Freon R-404a saturation table.
  // State 1 of the cycle is supposed to be sat. vapor
  float temperatureState1 = 0.00;
  enthalpy1 = ((0.5334*(temperatureState1))+363.52); 
}

void temperature2ToEnthalpy() {
  // State 2 of the cycle is supposed to be sat. vapor
  float temperatureState2 = 0.00;
  enthalpy2 = ((0.5334*temperatureState2)+363.52);
}

void temperature3ToEnthalpy() {
  // State 3 of the cycle is supposed to be sat. liquid
  float temperatureState3 = 0.00;
  enthalpy3 = ((1.4143*temperatureState3)+206.36);
  // Assuming ideal cycle, enthalpy at state 4 is equal to enthalpy at state 3
  enthalpy4 = enthalpy3;
}

void calculateCOP() {
  calculatedCOP = String((enthalpy1-enthalpy4)/(enthalpy2-enthalpy1));
}

void calculatePower() {
  calculatedPower = String(((senseCurrent1.toFloat())*220.00*0.80));
}

void calculatePCM1PickLoad() {
  calculatedPCM1Pickload = "6"; // 6 hours by default
}

void ecoActivation() {
  int sampelPCM1;
  int sampelPCM2;
  sampelPCM1 = senseTemperature3.toInt(); // change this later
  sampelPCM2 = senseTemperature7.toInt();

  if (senseTemperatureHumid.toInt() > (-10)) {
    relaystate1 = 1;
    return;
  }
  if ((sampelPCM1 <= calculatedFP.toInt() && (sampelPCM2 <= calculatedFP.toInt()))) {
    relaystate1 = 0; // turn off the relay for contactor 1 (compressor & condenser)
  }
}