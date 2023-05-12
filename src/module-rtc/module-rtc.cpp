#include "module-rtc.h"

// ==== RTC DS1307 CONFIGURATION ====
uRTCLib rtc(0x68);
// char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; // EN
// const char* daysOfTheWeek[7] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"}; // ID

String rtc_day = "";
String rtc_date = "";
String rtc_clock = "";
// for timer function
String baseDate = "";
String newDate = "";
String baseTime;
String newTime = "";
String timeElapsed = "";

void setupRtc() {
  URTCLIB_WIRE.begin();
  delay(3000);

  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // for example to set January 13 2022 at 12:56 you would call:
  // rtc.set(0, 20, 17, 3, 9, 5, 23);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)

  baseTime = rtc.second();
  Serial.println();
  Serial.print("baseTime: ");
  Serial.print(baseTime);
}

void calculateUptime() {
  
}

void calculateChargeTime() {

}

void determineDay() {
  String readDayOfWeeks = String(rtc.dayOfWeek());
  if (readDayOfWeeks.toInt() == 1) {
    rtc_day = "Minggu";
  }
  if (readDayOfWeeks.toInt() == 2) {
    rtc_day = "Senin";
  }
  if (readDayOfWeeks.toInt() == 3) {
    rtc_day = "Selasa";
  }
  if (readDayOfWeeks.toInt() == 4) {
    rtc_day = "Rabu";
  }
  if (readDayOfWeeks.toInt() == 5) {
    rtc_day = "Kamis";
  }
  if (readDayOfWeeks.toInt() == 6) {
    rtc_day = "Jumat";
  }
  if (readDayOfWeeks.toInt() == 7) {
    rtc_day = "Sabtu";
  }
}

void loopTime() {
  rtc.refresh();

  rtc_clock = (String(rtc.hour()));
  rtc_clock.concat(":");
  rtc_clock.concat(String(rtc.minute()));
  rtc_clock.concat(":");
  rtc_clock.concat(String(rtc.second()));

  determineDay();

  rtc_date = String(rtc.day());
  rtc_date.concat("-");
  rtc_date.concat(String(rtc.month()));
  rtc_date.concat("-");
  rtc_date.concat(String(rtc.year()));

  senseTimeDay = rtc_day;
  senseTimeDate = rtc_date;
  senseTimeClock = rtc_clock;

  senseTime = rtc_day;
  senseTime.concat("_");
  senseTime.concat(rtc_date);
  senseTime.concat("_");
  senseTime.concat(rtc_clock);
}