#include "serialcom-esp.h"

void setupESP32() {
	Serial2.begin(4800);
}

void sendDataToESP() {
	Serial2.println(fullData);
}

void receiveDataFromESP(){
	mqtt_received_message = "";
	while ((Serial2.available() > 0)) {
		mqtt_received_message = Serial2.readString();
	}
	mqtt_received_message.trim();
}