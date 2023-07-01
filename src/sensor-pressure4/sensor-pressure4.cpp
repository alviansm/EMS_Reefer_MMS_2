#include "sensor-pressure4.h"

const int pressureInput4 = A9; //select the analog input pin for the pressure transducer
const int pressureZero4 = 102; //analog reading of pressure transducer at 0psi
const int pressureMax4 = 817; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI4 = 500; //psi value of transducer being used
float pressureValue4 = 0; //variable to store the value coming from the pressure transducer

void sensorPressureLoop4() {
  pressureValue4 = analogRead(pressureInput4); //reads value from input pin and assigns to variable
  // pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert analog reading to psi

	sensePT4 = String(pressureValue4);
}