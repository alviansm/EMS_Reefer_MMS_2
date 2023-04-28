#ifndef SERIALCOM_NEXTION
#define SERIALCOM_NEXTION

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Nextion.h>

#include "variables/variables.h"

// monitoring
void setupSerialcomNextion();
void nextionWrite();
void updateNextionDashboard();
void updateNextionDetails();

// relay control
void setupNextionControlBtn(); // setup()
void loopNextionControlBtn(); // loop()
void bt0ReleaseCallback(void *ptr);
void bt1ReleaseCallback(void *pt);
void bt3ReleaseCallback(void *pt);
void bt4ReleaseCallback(void *pt);
void bt5ReleaseCallback(void *pt);
void bt6ReleaseCallback(void *pt);
// Page change event:
void page0PushCallback(void *ptr);
void page1PushCallback(void *ptr);
void page2PushCallback(void *ptr);
void page3PushCallback(void *ptr);
void page4PushCallback(void *ptr);
void page5PushCallback(void *ptr);

#endif