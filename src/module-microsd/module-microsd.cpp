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
    Serial.println(F("begin failed"));
    return;
  }
  while (SD.exists(fileName)) {
    if (fileName[BASE_NAME_SIZE + 1] != '9') {
      fileName[BASE_NAME_SIZE + 1]++;
    } else if (fileName[BASE_NAME_SIZE] != '9') {
      fileName[BASE_NAME_SIZE + 1] = '0';
      fileName[BASE_NAME_SIZE]++;
    } else {
      Serial.println(F("Can't create file name"));
      return;
    }
  }
  myFile = SD.open(fileName, FILE_WRITE);
  if (!myFile) {
    Serial.println(F("open failed"));
    return;
  }
  Serial.print(F("opened: "));
  Serial.println(fileName);
  myFile.close();
}

void randomizeFileName() {
  // Randomize file name variables that want to be used later for SD card file name, local storage save
  SDCardFileName = "";
  int random_length = 4;
  int temporary_random_num = random(0, 9);
  SDCardFileName = String(temporary_random_num);

  for (int i=0;i<random_length;i++){
    temporary_random_num = random(0,9);
    SDCardFileName.concat(String(temporary_random_num));
  }

  // adding format file
  SDCardFileName.concat(".CSV");
}

void writeHeaderSDCard() {
  // Write first row for csv data (header)
  myFile = SD.open(fileName, FILE_WRITE);
  if (myFile) {
    myFile.println("Time_Day, Time_Date, Time_Clock, SenseT1, SenseT2, SenseT3, SenseT4, SenseT5, SenseT6, SenseT7, SenseT8, SenseTH1, SenseRH, SenseCurrent1, SenseCurrent2, voltage, COP, Power, Uptime, PCM Freezing Point, Pickload"); // SD Card .CSV header row    

    myFile.close();
  } else {    
    Serial.print("Error opening ");
    Serial.print(fileName);
    Serial.println();
  }
}

void completeSDCardSetup() {
  setupMicrosd();
  writeHeaderSDCard();
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
  fullData.concat(senseVoltage);
  fullData.concat(",");
  fullData.concat(calculatedCOP);
  fullData.concat(",");
  fullData.concat(calculatedPower);
  fullData.concat(",");
  fullData.concat(calculatedUptime);
  fullData.concat(",");
  fullData.concat(calculatedFP);
  fullData.concat(",");
  fullData.concat(calculatedPCM1Pickload);

  // Testing
  Serial.println(fullData);

  // write data rows
  myFile = SD.open(fileName, FILE_WRITE);
  if (myFile) {    
      // print data to sd card
      myFile.println(fullData);
      Serial.print("success writing ");
      Serial.print(fileName);
      myFile.close();
    } else {
    // if the file didn't open, print an error:
    buzzerSOSFunc();
    Serial.print("error writing ");
    Serial.print(fileName);
    Serial.println();
  }
}