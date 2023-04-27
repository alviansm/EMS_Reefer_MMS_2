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
    myFile.close();
  } else {    
    Serial.print("Error opening ");
    Serial.print(SDCardFileName);
    Serial.println();
  }
}

void writeMonitorSDCard() {
  // write data rows
  myFile = SD.open(SDCardFileName, FILE_WRITE);
  if (myFile) {
      // print data to sd card
      myFile.println("Write data here");
      myFile.close();
    } else {
    // if the file didn't open, print an error:
    Serial.print("error writing ");
    Serial.print(SDCardFileName);
    Serial.println();
  }
}