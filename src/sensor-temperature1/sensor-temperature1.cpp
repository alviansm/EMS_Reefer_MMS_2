#include "sensor-temperature1.h"
#include "variables/variables.h"

#define ONE_WIRE_BUS A10 // Data wire is plugged into port 4 on the Arduino
OneWire oneWire(ONE_WIRE_BUS); // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature. 
int numberOfDevices; // Number of temperature devices found
DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address

int prev_senseTemperature9 = 0;
int prev_senseTemperature10 = 0;
int prev_senseTemperature11 = 0;
int prev_senseTemperature12 = 0;

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
        senseTemperature9 = String(tempC);
      }
      if (i == 1 && tempC != -127) {
        senseTemperature10 = String(tempC);
      }
      if (i == 2 && tempC != -127) {
        senseTemperature11 = String(tempC);
      }
      if (i == 3 && tempC != -127) {
        senseTemperature12 = String(tempC);
      }
    }

    if ((i == 0) && (tempC != -127) && ((tempC - senseTemperature9.toInt() >= -5) && (tempC - senseTemperature9.toInt() <= 5))) {
      senseTemperature9 = String(tempC);
    }
    if ((i == 1) && (tempC != -127) && ((tempC - senseTemperature10.toInt() >= -5) && (tempC - senseTemperature10.toInt() <= 5))) {
      senseTemperature10 = String(tempC);
    }
    if ((i == 2) && (tempC != -127) && ((tempC - senseTemperature11.toInt() >= -5) && (tempC - senseTemperature11.toInt() <= 5))) {
      senseTemperature11 = String(tempC);
    }
    if ((i == 3) && (tempC != -127) && ((tempC - senseTemperature12.toInt() >= -5) && (tempC - senseTemperature12.toInt() <= 5))) {
      senseTemperature12 = String(tempC);
    }

    }
  // Serial.println();
  }
  iteration_temperature++;
}