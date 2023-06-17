#include "sensor-pressure3.h"

const int pressureInput3 = A7; //select the analog input pin for the pressure transducer
const int pressureZero3 = 102; //analog reading of pressure transducer at 0psi
const int pressureMax3 = 817; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI3 = 500; //psi value of transducer being used
float pressureValue3 = 0; //variable to store the value coming from the pressure transducer

void sensorPressureLoop3() {
  pressureValue3 = analogRead(pressureInput3); //reads value from input pin and assigns to variable
  // pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert analog reading to psi

	sensePT1 = String(pressureValue3);
}