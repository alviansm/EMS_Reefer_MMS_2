#include "sensor-temperature.h"
#include "variables/variables.h"

#define ONE_WIRE_BUS 4 // Data wire is plugged into port 4 on the Arduino
OneWire oneWire(ONE_WIRE_BUS); // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature. 
int numberOfDevices; // Number of temperature devices found
DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address

void printAddress(DeviceAddress deviceAddress) {
  for (uint8_t i = 0; i < 8; i++) {
    if (deviceAddress[i] < 16) Serial.print("0");
      Serial.print(deviceAddress[i], HEX);
  }
}

void setupTemperatureSensor() {
  sensors.begin();
  numberOfDevices = sensors.getDeviceCount();
  Serial.print("Locating devices...");
  Serial.print("Found ");
  Serial.print(numberOfDevices, DEC);
  Serial.println(" devices.");
  for(int i=0;i<numberOfDevices; i++) {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i)) {
      Serial.print("Found device ");
      Serial.print(i, DEC);
      Serial.print(" with address: ");
      printAddress(tempDeviceAddress);
      Serial.println();
    } else {
      Serial.print("Found ghost device at ");
      Serial.print(i, DEC);
      Serial.print(" but could not detect address. Check power and cabling");
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

    // Assign to sensing temperature
    if (i == 0 ) {
      senseTemperature1 = String(tempC);
    }
    if (i == 1 ) {
      senseTemperature2 = String(tempC);
    }
    if (i == 2 ) {
      senseTemperature3 = String(tempC);
    }
    if (i == 3 ) {
      senseTemperature4 = String(tempC);
    }
    if (i == 4 ) {
      senseTemperature5 = String(tempC);
    }
    if (i == 5 ) {
      senseTemperature6 = String(tempC);
    }  
    if (i == 6 ) {
      senseTemperature7 = String(tempC);
    }    
    if (i == 7 ) {
      senseTemperature8 = String(tempC);
    }

    }
  // Serial.println();
  }
}