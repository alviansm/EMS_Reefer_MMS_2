#include "serialcom-nextion.h"

SoftwareSerial lcd(2, 3); //RX, TX

// Control page dual-state button
// compressor
NexDSButton bt0 = NexDSButton(2, 4, "bt4"); // (page, id, the name of the object)
// condensor
NexDSButton bt1 = NexDSButton(2, 6, "bt1");
// evaporator
NexDSButton bt3 = NexDSButton(2, 10, "bt3");
// heater
NexDSButton bt4 = NexDSButton(2, 11, "bt4");
// phase-change material
NexDSButton bt5 = NexDSButton(2, 12, "bt5");
// iot status
NexDSButton bt6 = NexDSButton(2, 15, "bt6");
// Nextion Pages
NexPage dashboard = NexPage(0, 0, "Dashboard");
NexPage mainpage = NexPage(1, 0, "Main");
NexPage control = NexPage(2, 0, "Control");
NexPage details = NexPage(3, 0, "Details");
NexPage iot = NexPage(4, 0, "IoT");
NexPage about = NexPage(5, 0, "About");
// Declare touch event objects to the touch event list: 
// You just need to add the names of the objects that send a touch event.
// Format: &<object name>,
NexTouch *nex_listen_list[] {
  &bt0, // compressor -> contactor 1 -> relaystate 1
  &bt1, // condensor -> contactor 1 -> relaystate 1
  &bt3, // evaporator -> contactor 3 -> relaystate 3
  &bt4, // heater -> contactor 2 -> relaystate 2
  &bt5, // phase-change material
  &bt6, // internet of things
  &dashboard,
  &mainpage,
  &control,
  &details,
  &iot,
  &about,
  NULL
};

void setupNextionControlBtn() {
  // Register the event callback functions of each touch event:
  // You need to register press events and release events seperatly.
  // Format for press events: <object name>.attachPush(<object name>PushCallback);
  // Format for release events: <object name>.attachPop(<object name>PopCallback);
  bt0.attachPop(bt0ReleaseCallback);
  bt1.attachPop(bt1ReleaseCallback);
  bt3.attachPop(bt3ReleaseCallback);
  bt4.attachPop(bt4ReleaseCallback);
  bt5.attachPop(bt5ReleaseCallback);
  bt6.attachPop(bt6ReleaseCallback);
  // pages
  dashboard.attachPush(page0PushCallback);  // Page press event
  mainpage.attachPush(page1PushCallback);
  control.attachPush(page2PushCallback);
  details.attachPush(page3PushCallback);
  iot.attachPush(page4PushCallback);
  about.attachPush(page5PushCallback);
}

void loopNextionControlBtn() {
  // Function to wait for the user input
  nexLoop(nex_listen_list);
}

void bt0ReleaseCallback(void *ptr) {
  uint32_t number5 = 0;
  bt0.getValue(&number5);

  if (number5 == 1) {
    relaystate1 = 1;
  } else {
    relaystate1 = 0;
  }
}

void bt1ReleaseCallback(void *pt) {
  uint32_t number5 = 0;
  bt0.getValue(&number5);

  if (number5 == 1) {
    relaystate1 = 1;
  } else {
    relaystate1 = 0;
  }
}

void bt3ReleaseCallback(void *pt) {
  uint32_t number5 = 0;
  bt0.getValue(&number5);

  if (number5 == 1) {
    relaystate3 = 1;
  } else {
    relaystate3 = 0;
  } 
}

void bt4ReleaseCallback(void *pt) {
  uint32_t number5 = 0;
  bt0.getValue(&number5);

  if (number5 == 1) {
    relaystate2 = 1;
  } else {
    relaystate2 = 0;
  } 
}

void bt5ReleaseCallback(void *pt) {
  
}

void bt6ReleaseCallback(void *pt) {
  
}

// Page change event:
void page0PushCallback(void *ptr)  // If page 0 is loaded on the display, the following is going to execute:
{
  currentNextionPage = 0;  // Set variable as 0 so from now on arduino knows page 0 is loaded on the display
}  // End of press event
void page1PushCallback(void *ptr)  
{
  currentNextionPage = 1;
}  // End of press event
void page2PushCallback(void *ptr)
{
  currentNextionPage = 2;
}  // End of press event
void page3PushCallback(void *ptr)
{
  currentNextionPage = 3;
}  // End of press event
void page4PushCallback(void *ptr)
{
  currentNextionPage = 4;  
}  // End of press event
void page5PushCallback(void *ptr)
{
  currentNextionPage = 5;  
}  // End of press event

void setupSerialcomNextion() {
  lcd.begin(9600);
}

void nextionWrite() {
  lcd.write(0xff);
  lcd.write(0xff);
  lcd.write(0xff);
}

void updateNextionDashboard() {
  // Please refer to the nextion editor for the display variables

  // Day and date concatination
  String day_date = senseTimeDay;
  day_date.concat(", ");
  day_date.concat(senseTimeDate);

  // Day and date
  lcd.print("rtcDayVal.txt=");
  lcd.print('"');
  lcd.print(day_date);
  lcd.print('"');
  nextionWrite();

  // Clock
  lcd.print("rtcClockVal.txt=");
  lcd.print('"');
  lcd.print(senseTimeClock);
  lcd.print('"');
  nextionWrite();

  // Inside temperature
  lcd.print("tempInsideVal.txt=");
  lcd.print('"');
  lcd.print(senseTemperatureHumid);
  lcd.print('"');
  nextionWrite();

  // Inside humidity
  lcd.print("humidInsideVal.txt=");
  lcd.print('"');
  lcd.print(senseHumid);
  lcd.print('"');
  nextionWrite();

  // Ambient Temperature
  lcd.print("tempAmbientVal.txt=");
  lcd.print('"');
  lcd.print(senseTemperature5);
  lcd.print('"');
  nextionWrite();

  // COP
  lcd.print("copVal.txt=");
  lcd.print('"');
  lcd.print(calculatedCOP);
  lcd.print('"');
  nextionWrite();

  // PCM Temperature
  lcd.print("tempPCM1Val.txt=");
  lcd.print('"');
  lcd.print(senseTemperature3);
  lcd.print('"');
  nextionWrite();

  // PCM Temperature 2
  lcd.print("tempPCM2Val.txt=");
  lcd.print('"');
  lcd.print(senseTemperature7);
  lcd.print('"');
  nextionWrite();

  // Power
  lcd.print("powerVal.txt=");
  lcd.print('"');
  lcd.print(calculatedPower);
  lcd.print('"');
  nextionWrite();

  // Asset status
  lcd.print("assetStatusVal.txt=");
  lcd.print('"');
  lcd.print(calculatedPower);
  lcd.print('"');
  nextionWrite();

  // Uptime
  lcd.print("uptimeVal.txt=");
  lcd.print('"');
  lcd.print(calculatedUptime);
  lcd.print('"');
  nextionWrite();
}

void updateNextionDetails() {
  // detailsT1
  lcd.print("detailsT1.txt=");
  lcd.print('"');
  lcd.print(senseTemperature1);
  lcd.print('"');
  nextionWrite();

  // detailsT2
  lcd.print("detailsT2.txt=");
  lcd.print('"');
  lcd.print(senseTemperature2);
  lcd.print('"');
  nextionWrite();

  // detailsT3
  lcd.print("detailsT3.txt=");
  lcd.print('"');
  lcd.print(senseTemperature3);
  lcd.print('"');
  nextionWrite();

  // detailsT4
  lcd.print("detailsT4.txt=");
  lcd.print('"');
  lcd.print(senseTemperature4);
  lcd.print('"');
  nextionWrite();

  // detailsT5
  lcd.print("detailsT5.txt=");
  lcd.print('"');
  lcd.print(senseTemperature5);
  lcd.print('"');
  nextionWrite();

  // detailsT6
  lcd.print("detailsT6.txt=");
  lcd.print('"');
  lcd.print(senseTemperature8);
  lcd.print('"');
  nextionWrite();

  // detailsT7
  lcd.print("detailsT7.txt=");
  lcd.print('"');
  lcd.print(senseTemperature7);
  lcd.print('"');
  nextionWrite();

  // detailsCurr1
  lcd.print("detailsCurr1.txt=");
  lcd.print('"');
  lcd.print(senseCurrent1);
  lcd.print('"');
  nextionWrite();

  // detailsCurr2
  lcd.print("detailsCurr2.txt=");
  lcd.print('"');
  lcd.print(senseCurrent2);
  lcd.print('"');
  nextionWrite();

  // detailsCurr3
  lcd.print("detailsCurr3.txt=");
  lcd.print('"');
  lcd.print(senseCurrent2);
  lcd.print('"');
  nextionWrite();

  // detailsCurr4
  lcd.print("detailsCurr4.txt=");
  lcd.print('"');
  lcd.print(senseCurrent2);
  lcd.print('"');
  nextionWrite();

  // detailsVoltage
  lcd.print("detailsVoltage.txt=");
  lcd.print('"');
  lcd.print(senseVoltage);
  lcd.print('"');
  nextionWrite();
  
  // detailsRH
  lcd.print("detailsRH.txt=");
  lcd.print('"');
  lcd.print(senseHumid);
  lcd.print('"');
  nextionWrite();

  // detailsT8
  lcd.print("detailsT8.txt=");
  lcd.print('"');
  lcd.print(senseTemperatureHumid);
  lcd.print('"');
  nextionWrite();

  // detailsPower
  lcd.print("detailsPower.txt=");
  lcd.print('"');
  lcd.print(calculatedPower);
  lcd.print('"');
  nextionWrite();

  // detailsCOP
  lcd.print("detailsCOP.txt=");
  lcd.print('"');
  lcd.print(calculatedCOP);
  lcd.print('"');
  nextionWrite();

  // detailsPick
  lcd.print("detailsPick.txt=");
  lcd.print('"');
  lcd.print(calculatedPCM1Pickload);
  lcd.print('"');
  nextionWrite();

  // detailsFP
  lcd.print("detailsFP.txt=");
  lcd.print('"');
  lcd.print(calculatedFP);
  lcd.print('"');
  nextionWrite();

  // detailsUptime
  lcd.print("detailsUptime.txt=");
  lcd.print('"');
  lcd.print(calculatedUptime);
  lcd.print('"');
  nextionWrite();

  // detailsIter
  lcd.print("detailsIter.txt=");
  lcd.print('"');
  lcd.print(calculatedIteration);
  lcd.print('"');
  nextionWrite();

  // detailsPrice
  lcd.print("detailsPrice.txt=");
  lcd.print('"');
  lcd.print(calculatedPrice);
  lcd.print('"');
  nextionWrite();

}

