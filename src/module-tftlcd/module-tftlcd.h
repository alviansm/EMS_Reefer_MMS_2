#ifndef MODULE_TFTLCD
#define MODULE_TFTLCD

#include <Arduino.h>
#include <TouchScreen.h>
#include <LCDWIKI_GUI.h>
#include <LCDWIKI_KBV.h>

void show_string(uint8_t *str,int16_t x,int16_t y,uint8_t csize,uint16_t fc, uint16_t bc,boolean mode);
void Read_Resistive(void);
boolean is_pressed(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t px,int16_t py);
void draw_home_screen();
void show_setting_menu();
void draw_info_page();
void setupLCD();
void loopLCD();

#endif