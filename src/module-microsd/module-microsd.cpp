#include "module-microsd.h"
#include "variables/variables.h"

// ==== MICROSD CONFIGURATION ====
File myFile;
const int chipSelect = 53; // change this to match your SD shield or module;

void setupMicrosd() {
  // ==== SETUP FOR MICROSD ====
  Serial.print("Initializing SD Card...");
  if(!SD.begin(chipSelect)) {
  Serial.println("SD card initialization failed!");
  Serial.println("SD card initialization done.");
  }
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
  randomizeFileName();
  delay(200);
  myFile = SD.open(SDCardFileName, FILE_WRITE);
  if (myFile) {
    myFile.println("Time, SenseT1, SenseT2, SenseT3, SenseT4, SenseT5, SenseT6, SenseT7, SenseT8, SenseTH1, SenseRH, SenseCurrent1, SenseCurrent2, voltage, COP, Power, Uptime, PCM Freezing Point, Pickload"); // SD Card .CSV header row    

    myFile.close();
  } else {    
    Serial.print("Error opening ");
    Serial.print(SDCardFileName);
    Serial.println();
  }
}

void completeSDCardSetup() {
  setupMicrosd();
  writeHeaderSDCard();
}

void writeMonitorSDCard() {
  // concat all sensing variables
  String fullData;
  fullData = senseTime;
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
  myFile = SD.open(SDCardFileName, FILE_WRITE);
  if (myFile) {    
      // print data to sd card
      myFile.println(fullData);
      myFile.close();
    } else {
    // if the file didn't open, print an error:
    Serial.print("error writing ");
    Serial.print(SDCardFileName);
    Serial.println();
  }
}