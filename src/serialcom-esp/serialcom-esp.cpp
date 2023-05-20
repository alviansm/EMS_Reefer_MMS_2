#include "serialcom-esp.h"

void setupESP32() {
	Serial2.begin(4800);
}

void sendDataToESP() {
	Serial2.println(fullData);
}