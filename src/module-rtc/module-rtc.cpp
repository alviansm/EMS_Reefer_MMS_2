#include "module-rtc.h"

// ==== RTC DS1307 CONFIGURATION ====
uRTCLib rtc(0x68);
// char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; // EN
char daysOfTheWeek[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"}; // ID

String rtc_day = "";
String rtc_date = "";
String rtc_clock = "";
String rtc_clock_minute = "";

void setupRtc() {
  URTCLIB_WIRE.begin();

  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // for example to set January 13 2022 at 12:56 you would call:
  rtc.set(0, 00, 11, 2, 8, 5, 23);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)
}

void calculateUptime() {
  String previous_minute = "";

  previous_minute = rtc_clock_minute;
  rtc_clock_minute = rtc.minute();
  if (rtc_clock_minute != previous_minute) {
    calculatedUptime = calculatedUptime+1;
  }  
}

void loopTime() {
  rtc.refresh();

  rtc_clock = (rtc.hour());
  rtc_clock.concat(":");
  rtc_clock.concat((rtc.minute()));
  rtc_clock.concat(":");
  rtc_clock.concat((rtc.second()));

  rtc_day = daysOfTheWeek[rtc.dayOfWeek()-1];
  rtc_date = rtc.day();
  rtc_date.concat("-");
  rtc_date.concat(rtc.month());
  rtc_date.concat("-");
  rtc_date.concat(rtc.year());

  senseTimeDate = rtc_day;
  senseTimeDate = rtc_date;
  senseTimeClock = rtc_clock;

  senseTime = rtc_day;
  senseTime.concat("_");
  senseTime.concat(rtc_date);
  senseTime.concat("_");
  senseTime.concat(rtc_clock);
}