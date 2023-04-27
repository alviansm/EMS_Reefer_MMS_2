#include "serialcom-nextion.h"
#include "variables/variables.h"

SoftwareSerial lcd(2, 3); //RX, TX

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
  lcd.print(senseTemperature1);
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
  lcd.print(senseTemperature1);
  lcd.print('"');
  nextionWrite();

  // PCM Temperature 2
  lcd.print("tempPCM2Val.txt=");
  lcd.print('"');
  lcd.print(senseTemperature1);
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