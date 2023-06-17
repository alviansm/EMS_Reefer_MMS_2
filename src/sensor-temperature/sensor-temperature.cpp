#include "sensor-temperature.h"
#include "variables/variables.h"

#define ONE_WIRE_BUS A14 // Data wire is plugged into port 4 on the Arduino
OneWire oneWire(ONE_WIRE_BUS); // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature. 
int numberOfDevices; // Number of temperature devices found
DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address

int prev_senseTemperature1 = 0;
int prev_senseTemperature2 = 0;
int prev_senseTemperature3 = 0;
int prev_senseTemperature4 = 0;
int prev_senseTemperature5 = 0;
int prev_senseTemperature6 = 0;
int prev_senseTemperature7 = 0;
int prev_senseTemperature8 = 0;
int iteration_temperature = 0;

void printAddress(DeviceAddress deviceAddress) {
  for (uint8_t i = 0; i < 8; i++) {
    if (deviceAddress[i] < 16) Serial.print("0");
      Serial.print(deviceAddress[i], HEX);
  }
}

void setupTemperatureSensor() {
  sensors.begin();
  numberOfDevices = sensors.getDeviceCount();
  // Serial.print("Locating devices...");
  // Serial.print("Found ");
  // Serial.print(numberOfDevices, DEC);
  // Serial.println(" devices.");
  for(int i=0;i<numberOfDevices; i++) {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i)) {
      // Serial.print("Found device ");
      // Serial.print(i, DEC);
      // Serial.print(" with address: ");
      // printAddress(tempDeviceAddress);
      // Serial.println();
    } else {
      // Serial.print("Found ghost device at ");
      // Serial.print(i, DEC);
      // Serial.print(" but could not detect address. Check power and cabling");
    }
  }
}

void loopTemperatureSensors() {
  sensors.requestTemperatures(); // Send the command to get temperatures
  // Loop through each device, then print out temperature data
  for(int i=0;i<numberOfDevices; i++) {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i)){
    // Print the data
    int tempC = sensors.getTempC(tempDeviceAddress);
    // Serial.print(tempC);
    // Serial.print(","); 
    // Assign initial iteration
    if (iteration_temperature <= 60) {
      if (i == 0 && tempC != -127) {
        senseTemperature1 = String(tempC);
      }
      if (i == 1 && tempC != -127) {
        senseTemperature2 = String(tempC);
      }
      if (i == 2 && tempC != -127) {
        senseTemperature3 = String(tempC);
      }
      if (i == 3 && tempC != -127) {
        senseTemperature4 = String(tempC);
      }
      if (i == 4 && tempC != -127) {
        senseTemperature5 = String(tempC);
      }
      if (i == 5 && tempC != -127) {
        senseTemperature6 = String(tempC);
      }
      if (i == 6 && tempC != -127) {
        senseTemperature7 = String(tempC);
      }
      if (i == 7 && tempC != -127) {
        senseTemperature8 = String(tempC);
      }
    }

    if ((i == 0) && (tempC != -127) && ((tempC - senseTemperature1.toInt() >= -5) && (tempC - senseTemperature1.toInt() <= 5))) {
      senseTemperature1 = String(tempC);
    }
    if ((i == 1) && (tempC != -127) && ((tempC - senseTemperature2.toInt() >= -5) && (tempC - senseTemperature2.toInt() <= 5))) {
      senseTemperature2 = String(tempC);
    }
    if ((i == 2) && (tempC != -127) && ((tempC - senseTemperature3.toInt() >= -5) && (tempC - senseTemperature3.toInt() <= 5))) {
      senseTemperature3 = String(tempC);
    }
    if ((i == 3) && (tempC != -127) && ((tempC - senseTemperature4.toInt() >= -5) && (tempC - senseTemperature4.toInt() <= 5))) {
      senseTemperature4 = String(tempC);
    }
    if ((i == 4) && (tempC != -127) && ((tempC - senseTemperature5.toInt() >= -5) && (tempC - senseTemperature5.toInt() <= 5))) {
      senseTemperature5 = String(tempC);
    }
    if ((i == 5) && (tempC != -127) && ((tempC - senseTemperature6.toInt() >= -5) && (tempC - senseTemperature6.toInt() <= 5))) {
      senseTemperature6 = String(tempC);
    }
    if ((i == 6) && (tempC != -127) && ((tempC - senseTemperature7.toInt() >= -5) && (tempC - senseTemperature7.toInt() <= 5))) {
      senseTemperature7 = String(tempC);
    }
    if ((i == 7) && (tempC != -127) && ((tempC - senseTemperature8.toInt() >= -5) && (tempC - senseTemperature8.toInt() <= 5))) {
      senseTemperature8 = String(tempC);
    }

    }
  // Serial.println();
  }
  iteration_temperature++;
}