/**
 * Screen.h - Foc pulling data from PhotoSensor
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * Open for public usage
 **/

#ifndef Screen_h
#define Screen_h
#include "core\pins.h"
#include "Arduino.h"
#include "Screen.h"
///////////////////////////////////////////////////////////////////
//   the header file named "Adafruit_SSD1306" in the "Adafruit_SSD1306-master" folder
//   uncomment "#define SSD1306_128_64" and comment "#define SSD1306_128_32" the statement if ur using 128x64 led display
//////////////////////////////////////////////////////////////////

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

class Screen
{
public:
  Screen();
  boolean init();
  void displayValues();
private:
  Adafruit_SSD1306 display;
};
#endif