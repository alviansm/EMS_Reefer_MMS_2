#include "module-rtc.h"

// ==== RTC DS1307 CONFIGURATION ====
uRTCLib rtc(0x68);
// char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; // EN
// const char* daysOfTheWeek[7] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"}; // ID

String rtc_day = "";
String rtc_date = "";
String rtc_clock = "";
// for timer function
int interval;
int previous_time_hour;
int previous_time_minute;
int current_time_hour;
int current_time_minute;
int calculating_uptime;
// for timer function - charging PCM
int previous_time_hour_charging;
int previous_time_minute_charging;
int current_time_hour_charging;
int current_time_minute_charging;
int calculating_uptime_charging;

void setupRtc() {
  URTCLIB_WIRE.begin();
  delay(1000);

  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // for example to set January 13 2022 at 12:56 you would call:
  // rtc.set(0, 45, 12, 5, 13, 7, 23);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)

  // for timer function
  calculating_uptime = 0;
}

void initializeInitiation() {
  rtc.refresh();
  interval = 1;
  previous_time_hour = String(rtc.hour()).toInt();
  previous_time_minute = String(rtc.minute()).toInt();
  previous_time_hour_charging = String(rtc.hour()).toInt();
  previous_time_minute_charging = String(rtc.minute()).toInt();
  calculatedUptime = String(0);
}

void calculateUptime() {
  // Serial.println();
  // Serial.print("Hour: ");
  // Serial.print(previous_time_hour);
  // Serial.println();
  // Serial.print("Minute: ");
  // Serial.print(previous_time_minute);
  // Serial.println();
  rtc.refresh();
  current_time_hour = String(rtc.hour()).toInt();
  current_time_minute = String(rtc.minute()).toInt();

  if (((current_time_hour - previous_time_hour >= 1) || (current_time_hour - previous_time_hour == -23)) && (current_time_minute - previous_time_minute == 0)) {
    calculating_uptime++;
    calculatedUptime = String(calculating_uptime);
    previous_time_hour = current_time_hour; 
  }
}

void calculateChargeTime() {
  rtc.refresh();
  current_time_hour_charging = String(rtc.hour()).toInt();
  current_time_minute_charging = String(rtc.minute()).toInt();

  if (((current_time_hour_charging - previous_time_hour_charging >= 1) || (current_time_hour_charging - previous_time_hour_charging == -23)) && (current_time_minute_charging - previous_time_minute_charging == 0)) {
    calculating_uptime_charging++;
    calculatedCharging = String(calculating_uptime_charging);
    previous_time_hour_charging = current_time_hour_charging; 
  }
  // reset the charging time if the pcm is discharged. using the relaystate (turn off the vapor compression refrigeration cycle) as parameter
  if (relaystate1 == 0) {
    calculating_uptime_charging = 0;
  }
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