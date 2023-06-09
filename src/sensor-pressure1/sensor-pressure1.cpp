#include "sensor-pressure1.h"

const int pressureInput = A6; //select the analog input pin for the pressure transducer
const int pressureZero = 102; //analog reading of pressure transducer at 0psi
const int pressureMax = 817; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI = 500; //psi value of transducer being used
float pressureValue = 0; //variable to store the value coming from the pressure transducer

void sensorPressureLoop() {
  pressureValue = analogRead(pressureInput); //reads value from input pin and assigns to variable
  // pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert analog reading to psi

	sensePT1 = String(pressureValue);
}