#include "module-rtc.h"
#include "variables/variables.h"

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
  senseTime.concat("-");
  senseTime.concat(rtc_date);
  senseTime.concat("-");
  senseTime.concat(rtc_clock);
}