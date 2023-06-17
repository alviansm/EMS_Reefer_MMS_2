#include "module-tftlcd.h"

//====DISPLAY CODE====
#define TOUCH_ORIENTATION  1 //1 for landscape
#define TITLE "Energy Management System Dashboard"

LCDWIKI_KBV my_lcd(ILI9341,A3,A2,A1,A0,A4); //model,cs,cd,wr,rd,reset
#define YP A1  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 6   // can be a digital pin

//param calibration from kbv
//touch sensitivity for X
#define TS_MINX 124
#define TS_MAXX 906

//touch sensitivity for Y
#define TS_MINY 83
#define TS_MAXY 893

#define MINPRESSURE 10
#define MAXPRESSURE 1000

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

//human readable color
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

TouchScreen mytouch(XP, YP, XM, YM, 300);
TSPoint tp;                      //Touchscreen_due branch uses Point

//variables
uint32_t cx, cy;
uint32_t rx[8], ry[8];
int32_t clx, crx, cty, cby;
float px, py;
int dispx, dispy, text_y_center, swapxy;
uint32_t calx, caly, cals;
char buf[13];
char page = '0';
int randNm;
int iteration = 0;

//====DISPLAY PAGES FUNCTIONS====
void show_string(uint8_t *str,int16_t x,int16_t y,uint8_t csize,uint16_t fc, uint16_t bc,boolean mode)
{
    my_lcd.Set_Text_Mode(mode);
    my_lcd.Set_Text_Size(csize);
    my_lcd.Set_Text_colour(fc);
    my_lcd.Set_Text_Back_colour(bc);
    my_lcd.Print_String(str,x,y);
}

void Read_Resistive(void)
{
    tp = mytouch.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   //because TFT control pins
    digitalWrite(XM, HIGH);
}

boolean is_pressed(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t px,int16_t py)
{
    if((px > x1 && px < x2) && (py > y1 && py < y2))
    {
        return true;  
    } 
    else
    {
        return false;  
    }
}

//startup page to main dashboard
void draw_home_screen()
{
    my_lcd.Fill_Screen(BLUE);

    // CIRCLE ACTIVE COLOR LIGHT BLUE (186, 230, 253)
    // CIRCLE INACTIVE COLOR LIGHT GRAY (203, 213, 225)
  
    //display date
    show_string("22/09/22", LEFT, 6, 2, WHITE, BLACK, 1);
    show_string("10:21:45", LEFT, 32, 2, WHITE, BLACK, 1);

    //display status
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Circle(288, 32, 16);
    show_string("PCM", 278, 4, 1, WHITE, BLACK, 1);

    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Circle(246, 32, 16);
    show_string("V.C.", 238, 4, 1, WHITE, BLACK, 1);

    show_string("Data logged.", CENTER, 16, 1, GREEN, BLACK, 1);

    //===========================monitoring square=====================
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(4, 64, 68, 96);
    show_string("38", 24, 74, 2, BLACK, BLACK, 1);
    show_string("AMBIENT (C)", 5, 102, 1, WHITE, BLACK, 1);

    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(87, 64, 151, 96);
    show_string("20", 104, 74, 2, BLACK, BLACK, 1);
    show_string("INSIDE (C)", 92, 102, 1, WHITE, BLACK, 1);

    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(170, 64, 234, 96);
    show_string("0,6", 182, 74, 2, BLACK, BLACK, 1);
    show_string("POWER (W)", 174, 102, 1, WHITE, BLACK, 1);
    
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(252, 64, 314, 96);
    show_string("2,44", 262, 74, 2, BLACK, BLACK, 1);
    show_string("I. KOND. (C)", 252, 102, 1, WHITE, BLACK, 1);

    //relative humidity
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(87, 128, 151, 160);
    show_string("-20", 104, 140, 2, BLACK, BLACK, 1);
    show_string("RH INS. (%)", 84, 166, 1, WHITE, BLACK, 1);
    
    //pcm
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(170, 128, 234, 160);
    show_string("-20", 182, 140, 2, BLACK, BLACK, 1);
    show_string("PCM (C)", 180, 166, 1, WHITE, BLACK, 1);
    
    //uptime
    show_string("Uptime: ", 4, 185, 1, GREEN, BLACK, 1);
    show_string("0", 4, 200, 1, WHITE, BLACK, 1);
		show_string("hours", 4, 215, 1, WHITE, BLACK, 1);
    
    //charging
    show_string("PCM Charging: ", 52, 185, 1, GREEN, BLACK, 1);
    show_string("0", 52, 200, 1, WHITE, BLACK, 1);
		show_string("hours", 52, 215, 1, WHITE, BLACK, 1);

    //button goto setting
    my_lcd.Set_Draw_color(0, 255, 255);
    my_lcd.Fill_Rectangle(320, 240, 246, 208);    
    show_string("->", 270, 220, 2, BLACK, BLACK, 2);
}

void draw_monitoring_screen() {
	my_lcd.Fill_Screen(BLUE);
  
  // T1 --- 1       
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(4, 4, 68, 36);
  show_string("0", 12, 12, 2, BLACK, BLACK, 1);
  show_string("T1 (C)", 9, 38, 1, WHITE, BLACK, 1);
  // T2
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(87, 4, 151, 36);
  show_string("0", 95, 12, 2, BLACK, BLACK, 1);
  show_string("T2 (C)", 92, 38, 1, WHITE, BLACK, 1);
  // T3
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(170, 4, 234, 36);
  show_string("0", 178, 12, 2, BLACK, BLACK, 1);
  show_string("T3 (C)", 176, 38, 1, WHITE, BLACK, 1);
  // T4
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(252, 4, 314, 36);
  show_string("0", 260, 12, 2, BLACK, BLACK, 1);
  show_string("T4 (C)", 252, 38, 1, WHITE, BLACK, 1);
  // T5 --- 2
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(4, 52, 68, 84);
  show_string("0", 12, 60, 2, BLACK, BLACK, 1);
  show_string("T5 (C)", 9, 86, 1, WHITE, BLACK, 1);
  // T6
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(87, 52, 151, 84);
  show_string("0", 95, 60, 2, BLACK, BLACK, 1);
  show_string("T6 (C)", 92, 86, 1, WHITE, BLACK, 1);
  // T7
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(170, 52, 234, 84);
  show_string("0", 178, 60, 2, BLACK, BLACK, 1);
  show_string("T7 (C)", 176, 86, 1, WHITE, BLACK, 1);
  // Current 1
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(252, 52, 314, 84);
  show_string("0", 260, 60, 2, BLACK, BLACK, 1);
  show_string("I1 (A)", 252, 86, 1, WHITE, BLACK, 1);
  // Current 2 --- 3
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(4, 100, 68, 132);
  show_string("0", 12, 108, 2, BLACK, BLACK, 1);
  show_string("I2 (A)", 9, 134, 1, WHITE, BLACK, 1);
  // TH
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(87, 100, 151, 132);
  show_string("0", 95, 108, 2, BLACK, BLACK, 1);
  show_string("T.INS. (C)", 92, 134, 1, WHITE, BLACK, 1);
  // HUMID
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(170, 100, 234, 132);
  show_string("0", 178, 108, 2, BLACK, BLACK, 1);
  show_string("RH (%)", 176, 134, 1, WHITE, BLACK, 1);
  // T8
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(252, 100, 314, 132);
  show_string("0", 260, 108, 2, BLACK, BLACK, 1);
  show_string("T9 (C)", 256, 134, 1, WHITE, BLACK, 1);
  // T9 ---- 4
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(4, 148, 68, 180);
  show_string("0", 12, 156, 2, BLACK, BLACK, 1);
  show_string("T10 (C)", 9, 182, 1, WHITE, BLACK, 1);
  // T10
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(87, 148, 151, 180);
  show_string("0", 95, 156, 2, BLACK, BLACK, 1);
  show_string("T11 (C)", 92, 182, 1, WHITE, BLACK, 1);
  // T11
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(170, 148, 234, 180);
  show_string("0", 178, 156, 2, BLACK, BLACK, 1);
  show_string("T12 (C)", 176, 182, 1, WHITE, BLACK, 1);
  // PT1
  my_lcd.Set_Draw_color(220, 255, 255);
  my_lcd.Fill_Rectangle(252, 148, 314, 180);
  show_string("0", 260, 156, 2, BLACK, BLACK, 1);
  show_string("PT1 (BAR)", 252, 182, 1, WHITE, BLACK, 1);
  // PT2 ---- 5
  // PT3
  // PT4

	// Navigation Button -- NEXT
  my_lcd.Set_Draw_color(0, 255, 255);
  my_lcd.Fill_Rectangle(320, 240, 246, 208);    
  show_string("->", 270, 220, 2, BLACK, BLACK, 2);

  // Navigation Button -- BACK
  my_lcd.Set_Draw_color(0, 255, 255);
  my_lcd.Fill_Rectangle(74, 240, 0, 208);    
  show_string("<-", 24, 220, 2, BLACK, BLACK, 2);
}

void draw_control_screen()
{
    my_lcd.Fill_Screen(BLUE);

    show_string("KONTROL", CENTER, 4, 2, GREEN, BLACK, 1);

    //===========================monitoring square=====================
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(4, 24, 68, 56);
    show_string("0", 12, 32, 2, BLACK, BLACK, 1);
    show_string("PT2 (BAR)", 5, 60, 1, WHITE, BLACK, 1);

    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(87, 24, 151, 56);
    show_string("0", 95, 32, 2, BLACK, BLACK, 1);
    show_string("PT3 (BAR)", 92, 60, 1, WHITE, BLACK, 1);

    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(170, 24, 234, 56);
    show_string("0", 178, 32, 2, BLACK, BLACK, 1);
    show_string("PT4 (BAR)", 174, 60, 1, WHITE, BLACK, 1);

    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(252, 24, 314, 56);
    show_string("0", 260, 32, 2, BLACK, BLACK, 1);
    show_string("I3 (A)", 264, 60, 1, WHITE, BLACK, 1);

    my_lcd.Set_Draw_color(0, 255, 0);
    my_lcd.Fill_Rectangle(4, 72, 100, 105);
    show_string("NYALA", 12, 80, 1, BLACK, BLACK, 1);
    show_string("KOMPRESOR LOW STATE", 104, 88, 1, WHITE, BLACK, 1);

    my_lcd.Set_Draw_color(0, 255, 0);
    my_lcd.Fill_Rectangle(4, 117, 100, 149);
    show_string("NYALA", 12, 125, 1, BLACK, BLACK, 1);
    show_string("KOMPRESOR HIGH STATE", 104, 133, 1, WHITE, BLACK, 1);

    my_lcd.Set_Draw_color(0, 255, 0);
    my_lcd.Fill_Rectangle(4, 161, 100, 193);
    show_string("NYALA", 12, 169, 1, BLACK, BLACK, 1);
    show_string("FAN EVAP", 104, 177, 1, WHITE, BLACK, 1);

    my_lcd.Set_Draw_color(0, 255, 0);
    my_lcd.Fill_Rectangle(4, 205, 100, 237);
    show_string("NYALA", 12, 213, 1, BLACK, BLACK, 1);
    show_string("MODE ECO", 104, 221, 1, WHITE, BLACK, 1);

    //button goto setting
    my_lcd.Set_Draw_color(0, 255, 255);
    my_lcd.Fill_Rectangle(320, 240, 246, 208);    
    show_string("->", 270, 220, 2, BLACK, BLACK, 2);
}

void draw_loading_screen() {
  my_lcd.Fill_Screen(BLUE);
  my_lcd.Set_Draw_color(0, 0, 0);
  show_string("Memuat Halaman...", 60, 120, 2, BLACK, BLACK, 2);
}

void draw_loading_process() {
  my_lcd.Fill_Screen(BLUE);
  my_lcd.Set_Draw_color(0, 0, 0);
  show_string("Memproses Perintah...", 40, 120, 2, BLACK, BLACK, 2);
}

/*
 * Page
 * 0 -> Dashboard
 */

void setupLCD() {
  //dashboard setting
  digitalWrite(A0, HIGH);
  pinMode(A0, OUTPUT);
  my_lcd.Init_LCD();
  my_lcd.Set_Rotation(TOUCH_ORIENTATION);  

  draw_home_screen();
}

void loopLCD() {
	// loop the sensing variables (inside power cop pcm)
	const char* char_senseDate = senseTimeDate.c_str();
	const char* char_senseClock = senseTimeClock.c_str();
	const char* char_senseHumid = senseHumid.c_str();
	const char* char_temperatureAmbient = senseTemperature5.c_str();
	const char* char_temperatureInside = senseTemperatureHumid.c_str();
	const char* char_power = calculatedPower.c_str();
	const char* char_cop = calculatedCOP.c_str();
	const char* char_temperaturePCM = senseTemperature3.c_str();
	const char* char_uptime = calculatedUptime.c_str();
  const char* char_charging = calculatedCharging.c_str();
  const char* char_pressure1 = senseTemperature6.c_str();

  //
  const char* char_temperature1 = senseTemperature1.c_str();
  const char* char_temperature2 = senseTemperature2.c_str();
  const char* char_temperature3 = senseTemperature3.c_str();
  const char* char_temperature4 = senseTemperature4.c_str();
  const char* char_temperature5 = senseTemperature5.c_str();
  const char* char_temperature6 = senseTemperature6.c_str();
  const char* char_temperature7 = senseTemperature7.c_str();
  const char* char_temperature9 = senseTemperature9.c_str();
  const char* char_temperature10 = senseTemperature10.c_str();
  const char* char_temperature11 = senseTemperature11.c_str();
  const char* char_temperature12 = senseTemperature12.c_str();
  const char* char_sensePressure1 = sensePT1.c_str();
  const char* char_sensePressure2 = sensePT2.c_str();
  const char* char_sensePressure3 = sensePT3.c_str();
  const char* char_sensePressure4 = sensePT4.c_str();
  const char* char_senseCurrent1 = senseCurrent1.c_str();
  const char* char_senseCurrent2 = senseCurrent2.c_str();
  const char* char_senseCurrent3 = senseCurrent3.c_str();

	uint16_t i;
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  pinMode(XM, OUTPUT); 
  pinMode(YP, OUTPUT);
	
	// update variables
  if (page == '0' && iteration == 0) {
    draw_home_screen();
    iteration = 1;
  }
  if (page == '1' && iteration == 0) {
    draw_monitoring_screen();
    iteration = 1;    
  }
  if (page == '2' && iteration == 0) {
    draw_control_screen();
    iteration = 1;    
  }

	if (page == '0' && iteration == 1) {
		my_lcd.Set_Draw_color(0, 0, 255);
    my_lcd.Fill_Rectangle(0, 0, 96, 24);
		show_string(char_senseDate, LEFT, 6, 2, WHITE, BLACK, 1);

		my_lcd.Set_Draw_color(0, 0, 255);
    my_lcd.Fill_Rectangle(0, 24, 96, 48);
    show_string(char_senseClock, LEFT, 32, 2, WHITE, BLACK, 1);

		my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(4, 64, 68, 96);
    show_string(char_temperatureAmbient, 24, 74, 2, BLACK, BLACK, 1);
    show_string("AMBIENT (C)", 5, 102, 1, WHITE, BLACK, 1);

		my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(87, 64, 151, 96);
    show_string(char_temperatureInside, 104, 74, 2, BLACK, BLACK, 1);
    show_string("INSIDE (C)", 92, 102, 1, WHITE, BLACK, 1);

		my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(170, 64, 234, 96);
    show_string(char_power, 182, 74, 2, BLACK, BLACK, 1);
    show_string("POWER (W)", 174, 102, 1, WHITE, BLACK, 1);

		my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(252, 64, 314, 96);
    show_string(char_pressure1, 262, 74, 2, BLACK, BLACK, 1);
    show_string("I. KOND. (C)", 252, 102, 1, WHITE, BLACK, 1);
		
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(87, 128, 151, 160);
    show_string(char_senseHumid, 104, 140, 2, BLACK, BLACK, 1);
    show_string("RH INS. (%)", 84, 166, 1, WHITE, BLACK, 1);

		my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(170, 128, 234, 160);
    show_string(char_temperaturePCM, 182, 140, 2, BLACK, BLACK, 1);
    show_string("PCM (C)", 180, 166, 1, WHITE, BLACK, 1);

		my_lcd.Set_Draw_color(0, 0, 255);
    my_lcd.Fill_Rectangle(0, 200, 96, 215);
		show_string(char_uptime, 4, 200, 1, WHITE, BLACK, 1);

    //charging
    my_lcd.Set_Draw_color(0, 0, 255);
    my_lcd.Fill_Rectangle(52, 200, 148, 215);
    show_string(char_charging, 52, 200, 1, WHITE, BLACK, 1);
	} 

  if (page == '1' && iteration == 1) {
    // T1 --- 1       
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(4, 4, 68, 36);
    show_string(char_temperature1, 12, 12, 2, BLACK, BLACK, 1);
    // T2
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(87, 4, 151, 36);
    show_string(char_temperature2, 95, 12, 2, BLACK, BLACK, 1);
    // T3
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(170, 4, 234, 36);
    show_string(char_temperature3, 178, 12, 2, BLACK, BLACK, 1);
    // T4
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(252, 4, 314, 36);
    show_string(char_temperature4, 260, 12, 2, BLACK, BLACK, 1);
    // T5 --- 2
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(4, 52, 68, 84);
    show_string(char_temperature5, 12, 60, 2, BLACK, BLACK, 1);
    // T6
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(87, 52, 151, 84);
    show_string(char_temperature6, 95, 60, 2, BLACK, BLACK, 1);
    // T7
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(170, 52, 234, 84);
    show_string(char_temperature7, 178, 60, 2, BLACK, BLACK, 1);
    // Current 1
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(252, 52, 314, 84);
    show_string(char_senseCurrent1, 260, 60, 2, BLACK, BLACK, 1);
    // Current 2 --- 3
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(4, 100, 68, 132);
    show_string(char_senseCurrent2, 12, 108, 2, BLACK, BLACK, 1);
    // TH
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(87, 100, 151, 132);
    show_string(char_temperatureInside, 95, 108, 2, BLACK, BLACK, 1);
    // HUMID
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(170, 100, 234, 132);
    show_string(char_senseHumid, 178, 108, 2, BLACK, BLACK, 1);
    // T8
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(252, 100, 314, 132);
    show_string(char_temperature9, 260, 108, 2, BLACK, BLACK, 1);
    // T9 ---- 4
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(4, 148, 68, 180);
    show_string(char_temperature9, 12, 156, 2, BLACK, BLACK, 1);
    // T10
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(87, 148, 151, 180);
    show_string(char_temperature9, 95, 156, 2, BLACK, BLACK, 1);
    // T11
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(170, 148, 234, 180);
    show_string(char_temperature9, 178, 156, 2, BLACK, BLACK, 1);
    // PT1
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(252, 148, 314, 180);
    show_string(char_sensePressure1, 260, 156, 2, BLACK, BLACK, 1);
  }

  if (page == '2' && iteration == 1) {
    // lanjutan monitoring
    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(4, 24, 68, 56);
    show_string(char_sensePressure2, 12, 32, 2, BLACK, BLACK, 1);

    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(87, 24, 151, 56);
    show_string(char_sensePressure3, 95, 32, 2, BLACK, BLACK, 1);

    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(170, 24, 234, 56);
    show_string(char_sensePressure4, 178, 32, 2, BLACK, BLACK, 1);

    my_lcd.Set_Draw_color(220, 255, 255);
    my_lcd.Fill_Rectangle(252, 24, 314, 56);
    show_string(char_senseCurrent3, 260, 32, 2, BLACK, BLACK, 1);

    // kontrol
    if (relaystate1 == 0) {
      my_lcd.Set_Draw_color(255, 0, 0);
      my_lcd.Fill_Rectangle(4, 72, 100, 105);
      show_string("MATI", 12, 80, 1, BLACK, BLACK, 1);
      show_string("KOMPRESOR LOW STATE", 104, 88, 1, WHITE, BLACK, 1);
    }
    if (relaystate1 == 1) {
      my_lcd.Set_Draw_color(0, 255, 0);
      my_lcd.Fill_Rectangle(4, 72, 100, 105);
      show_string("NYALA", 12, 80, 1, BLACK, BLACK, 1);
      show_string("KOMPRESOR LOW STATE", 104, 88, 1, WHITE, BLACK, 1);
    }

    if (relaystate2 == 0) {
      my_lcd.Set_Draw_color(255, 0, 0);
      my_lcd.Fill_Rectangle(4, 117, 100, 149);
      show_string("MATI", 12, 125, 1, BLACK, BLACK, 1);
      show_string("KOMPRESOR HIGH STATE", 104, 133, 1, WHITE, BLACK, 1);
    }
    if (relaystate2 == 1) {
      my_lcd.Set_Draw_color(0, 255, 0);
      my_lcd.Fill_Rectangle(4, 117, 100, 149);
      show_string("NYALA", 12, 125, 1, BLACK, BLACK, 1);
      show_string("KOMPRESOR HIGH STATE", 104, 133, 1, WHITE, BLACK, 1);
    }

    if (relaystate3 == 0) {
      my_lcd.Set_Draw_color(255, 0, 0);
      my_lcd.Fill_Rectangle(4, 161, 100, 193);
      show_string("MATI", 12, 169, 1, BLACK, BLACK, 1);
      show_string("FAN EVAP", 104, 177, 1, WHITE, BLACK, 1);
    }
    if (relaystate3 == 1) {
      my_lcd.Set_Draw_color(0, 255, 0);
      my_lcd.Fill_Rectangle(4, 161, 100, 193);
      show_string("NYALA", 12, 169, 1, BLACK, BLACK, 1);
      show_string("FAN EVAP", 104, 177, 1, WHITE, BLACK, 1);
    }    

    if (is_eco_active) {
      my_lcd.Set_Draw_color(0, 255, 0);
      my_lcd.Fill_Rectangle(4, 205, 100, 237);
      show_string("NYALA", 12, 213, 1, BLACK, BLACK, 1);
      show_string("MODE ECO", 104, 221, 1, WHITE, BLACK, 1);
    }
    if (!is_eco_active) {
      my_lcd.Set_Draw_color(255, 0, 0);
      my_lcd.Fill_Rectangle(4, 205, 100, 237);
      show_string("MATI", 12, 213, 1, BLACK, BLACK, 1);
      show_string("MODE ECO", 104, 221, 1, WHITE, BLACK, 1);
    }
  }
	
	//page naviagtion looping
	if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
		p.x = map(p.x, TS_MINX, TS_MAXX, 0, my_lcd.Get_Display_Width());
		p.y = map(p.y, TS_MINY, TS_MAXY, 0, my_lcd.Get_Display_Height());      

    Serial.println("X: ");
    Serial.print(p.x);
    Serial.println("Y: ");
    Serial.print(p.y);
    Serial.println("RELAY: ");
    Serial.print(relaystate1);
    Serial.println();

		//===============in dashboard -> main menu====================
		if (is_pressed(0, 180, 64, 240, p.x, p.y) && page =='0'){        
      //button goto main menu (page 1) - pressed
      page = '1';      
      iteration = 0;
      my_lcd.Set_Draw_color(55, 55, 55);
      my_lcd.Fill_Rectangle(320, 240, 246, 208);  
      show_string("->", 270, 220, 2, WHITE, BLACK, 2);     
      draw_loading_screen();     				            
      delay(500);
      return;
    }     
    if (is_pressed(0, 180, 64, 240, p.x, p.y) && page =='1'){        
      //button goto main menu (page 1) - pressed
      page = '2';      
      iteration = 0;
      my_lcd.Set_Draw_color(55, 55, 55);
      my_lcd.Fill_Rectangle(320, 240, 246, 208);  
      show_string("->", 270, 220, 2, WHITE, BLACK, 2);       
      draw_loading_screen();   				
      delay(500);
      return;      
		} 
    if (is_pressed(0, 180, 64, 240, p.x, p.y) && page =='2'){        
      //button goto main menu (page 1) - pressed
      page = '0';      
      iteration = 0;
      my_lcd.Set_Draw_color(55, 55, 55);
      my_lcd.Fill_Rectangle(320, 240, 246, 208);  
      show_string("->", 270, 220, 2, WHITE, BLACK, 2);       
      draw_loading_screen();   				
      delay(500);
      return;      
		}  
    if (is_pressed(0, 0, 60, 80, p.x, p.y) && page =='1'){        
      //button goto main menu (page 1) - pressed
      page = '0';      
      iteration = 0;
      my_lcd.Set_Draw_color(55, 55, 55);
      my_lcd.Fill_Rectangle(74, 240, 0, 208);    
      show_string("<-", 24, 220, 2, WHITE, BLACK, 2);      
      draw_loading_screen();   				
      delay(500);
      return;      
		}   
    // Control Page
    // Comp1
    if (is_pressed(180, 20, 240, 70, p.x, p.y) && page =='2' && relaystate1 == 1 && !is_eco_active) {
      relaystate1 = 0;
      iteration = 0;
      draw_loading_process();
      delay(500);
      return;
    } else if (is_pressed(180, 20, 240, 70, p.x, p.y) && page =='2' && relaystate1 == 0 && !is_eco_active) {      
      draw_loading_process();
      delay(60000);
      relaystate1 = 1;
      iteration = 0;    
      return;
    }
    // Comp2
    if (is_pressed(140, 20, 170, 70, p.x, p.y) && page =='2' && relaystate2 == 1 && !is_eco_active) {
      relaystate2 = 0;
      iteration = 0;
      draw_loading_process();
      delay(500); 
      return;
    } else if (is_pressed(140, 20, 170, 70, p.x, p.y) && page =='2' && relaystate2 == 0 && !is_eco_active) {      
      draw_loading_process();
      delay(60000);
      relaystate2 = 1;
      iteration = 0;    
      return;
    }
    // Fan Evap
    if (is_pressed(70, 20, 100, 95, p.x, p.y) && page =='2' && relaystate3 == 1) {
      draw_loading_process();
      delay(5000);
      relaystate3 = 0;
      iteration = 0;
      return;
    } else if (is_pressed(70, 20, 95, 70, p.x, p.y) && page =='2' && relaystate3 == 0) {      
      relaystate3 = 1;
      iteration = 0;    
      draw_loading_process();
      delay(500);  
      return;
    }
    // Eco
    if (is_pressed(20, 15, 60, 70, p.x, p.y) && page =='2' && is_eco_active) {
      is_eco_active = !is_eco_active;
      iteration = 0;
      draw_loading_process();
      delay(500);
      return;
    } else if (is_pressed(20, 15, 60, 70, p.x, p.y) && page =='2' && !is_eco_active) {      
      is_eco_active = !is_eco_active;
      iteration = 0;
      draw_loading_process();
      delay(500);
      return;
    }
	} 	
}