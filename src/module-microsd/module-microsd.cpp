#include "module-microsd.h"

// ==== MICROSD CONFIGURATION ====
SdFat SD;
#define FILE_BASE_NAME "DataSkripsi-"

const uint8_t CS_PIN = 53;

File myFile;

const uint8_t BASE_NAME_SIZE = sizeof(FILE_BASE_NAME) - 1;
char fileName[] = FILE_BASE_NAME "00.csv";


void setupMicrosd() {
  // ==== SETUP FOR MICROSD ====
  if (!SD.begin(CS_PIN)) {
    // Serial.println(F("begin failed"));
    return;
  }
  while (SD.exists(fileName)) {
    if (fileName[BASE_NAME_SIZE + 1] != '9') {
      fileName[BASE_NAME_SIZE + 1]++;
    } else if (fileName[BASE_NAME_SIZE] != '9') {
      fileName[BASE_NAME_SIZE + 1] = '0';
      fileName[BASE_NAME_SIZE]++;
    } else {
      // Serial.println(F("Can't create file name"));
      return;
    }
  }
  myFile = SD.open(fileName, FILE_WRITE);
  if (!myFile) {
    // Serial.println(F("open failed"));
    return;
  }
  myFile.println("Time_Day, Time_Date, Time_Clock, SenseT1, SenseT2, SenseT3, SenseT4, SenseT5, SenseT6, SenseT7, SenseT8, SenseTH1, SenseRH, SenseCurrent1, SenseCurrent2, COP, Power, Uptime, ChargeTime, Charging, senseT9, senseT10, senseT11, senseT12, mentahan_sensePT1, mentahan_sensePT2, mentahan_sensePT3, mentahan_sensePT4"); // SD Card .CSV header row  
  // Serial.print(F("opened: "));
  // Serial.println(fileName);
  myFile.close();
}

void writeMonitorSDCard() {
  // concat all sensing variables
  fullData = ""; // reset to empty
  fullData = senseTimeDay;
  fullData.concat(",");
  fullData.concat(senseTimeDate);
  fullData.concat(",");
  fullData.concat(senseTimeClock);
  fullData.concat(",");
  fullData.concat(senseTemperature1);
  fullData.concat(",");
  fullData.concat(senseTemperature2);
  fullData.concat(",");
  fullData.concat(senseTemperature3);
  fullData.concat(",");
  fullData.concat(senseTemperature4);
  fullData.concat(",");
  fullData.concat(senseTemperature5);
  fullData.concat(",");
  fullData.concat(senseTemperature6);
  fullData.concat(",");
  fullData.concat(senseTemperature7);
  fullData.concat(",");
  fullData.concat(senseTemperature8);
  fullData.concat(",");
  fullData.concat(senseTemperatureHumid);
  fullData.concat(",");
  fullData.concat(senseHumid);
  fullData.concat(",");
  fullData.concat(senseCurrent1);
  fullData.concat(",");
  fullData.concat(senseCurrent2);
  fullData.concat(",");
  fullData.concat(calculatedCOP);
  fullData.concat(",");
  fullData.concat(calculatedPower);
  fullData.concat(",");
  fullData.concat(calculatedUptime);
  fullData.concat(",");
  fullData.concat(calculatedPCM1Pickload);
  fullData.concat(",");
  fullData.concat(calculatedCharging);
  fullData.concat(",");
  fullData.concat(senseTemperature9);
  fullData.concat(",");
  fullData.concat(senseTemperature10);
  fullData.concat(",");
  fullData.concat(senseTemperature11);
  fullData.concat(",");
  fullData.concat(senseTemperature12);
  fullData.concat(",");
  fullData.concat(sensePT1);
  fullData.concat(",");
  fullData.concat(sensePT2);
  fullData.concat(",");
  fullData.concat(sensePT3);
  fullData.concat(",");
  fullData.concat(sensePT4);

  // Testing & send data in serial communication to esp32
  Serial.println(fullData);
  
  // write data rows
  myFile = SD.open(fileName, FILE_WRITE);
  if (myFile) {    
      // print data to sd card
      myFile.println(fullData);
      // Serial.print("success writing ");
      // Serial.print(fileName);
      myFile.close();
    } else {
    // if the file didn't open, print an error:
    // buzzerSOSFunc();
    // Serial.print("error writing ");
    // Serial.print(fileName);
    // Serial.println();
  }
}