#include "sensor-temperature1.h"
#include "variables/variables.h"

#define ONE_WIRE_BUS A10 // Data wire is plugged into port 4 on the Arduino
OneWire oneWire2(ONE_WIRE_BUS); // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
DallasTemperature sensors2(&oneWire2); // Pass our oneWire reference to Dallas Temperature. 
int numberOfDevices2; // Number of temperature devices found
DeviceAddress tempDeviceAddress2; // We'll use this variable to store a found device address

int prev_senseTemperature9 = 0;
int prev_senseTemperature10 = 0;
int prev_senseTemperature11 = 0;
int prev_senseTemperature12 = 0;
int iteration_temperature2 = 0;

void printAddress2(DeviceAddress deviceAddress) {
  for (uint8_t i = 0; i < 8; i++) {
    if (deviceAddress[i] < 16) Serial.print("0");
      Serial.print(deviceAddress[i], HEX);
  }
}

void setupTemperatureSensor1() {
  sensors2.begin();
  numberOfDevices2 = sensors2.getDeviceCount();
  Serial.print("Locating devices...");
  Serial.print("Found ");
  Serial.print(numberOfDevices2, DEC);
  Serial.println(" devices.");
  for(int i=0;i<numberOfDevices2; i++) {
    // Search the wire for address
    if(sensors2.getAddress(tempDeviceAddress2, i)) {
      Serial.print("Found device ");
      Serial.print(i, DEC);
      Serial.print(" with address: ");
      printAddress(tempDeviceAddress2);
      Serial.println();
    } else {
      // Serial.print("Found ghost device at ");
      // Serial.print(i, DEC);
      // Serial.print(" but could not detect address. Check power and cabling");
    }
  }
}

void loopTemperatureSensors1() {
  sensors2.requestTemperatures(); // Send the command to get temperatures
  // Loop through each device, then print out temperature data
  for(int i=0;i<numberOfDevices2; i++) {
    // Search the wire for address
    if(sensors2.getAddress(tempDeviceAddress2, i)){
    // Print the data
    int tempC = sensors2.getTempC(tempDeviceAddress2);
    // Serial.print(tempC);
    // Serial.print(","); 
    // Assign initial iteration
    if (iteration_temperature2 <= 60) {
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
  iteration_temperature2++;
}