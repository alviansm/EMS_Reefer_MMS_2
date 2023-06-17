#include "sensor-pressure2.h"

const int pressureInput2 = A6; //select the analog input pin for the pressure transducer
const int pressureZero2 = 102; //analog reading of pressure transducer at 0psi
const int pressureMax2 = 817; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI2 = 500; //psi value of transducer being used
float pressureValue2 = 0; //variable to store the value coming from the pressure transducer

void sensorPressureLoop2() {
  pressureValue2 = analogRead(pressureInput2); //reads value from input pin and assigns to variable
  // pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert analog reading to psi

	sensePT1 = String(pressureValue2);
}