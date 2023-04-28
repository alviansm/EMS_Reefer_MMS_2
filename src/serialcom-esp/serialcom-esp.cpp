#include "serialcom-esp.h"

SoftwareSerial arduino(13, 12); // RX, TX

void setupESP32() {
    arduino.begin(9600);
}

void sendDataToESP() {
    arduino.println(fullData);
}