/**
 * 
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * 
 * 
 * The objective of this file is to
 * run the bluetooth chip for the project,
 * most likely utilizing the Serial communication
 * protocol to impact change on the device from the GUI
 * 
 * Functionality can be enabled in the "Configuration.h" file
 * Should debugging be needed, disable all other features and simply
 * enable the "DEBUG" variable. This will output appropriate unit testing values
 **/


#include "Configuration.h"
#include "Screen.h"

#ifdef ACTIVATE_OLCD

    //init code
    Screen::Screen()
    {
            Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
            display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
            display.clearDisplay();
    }

    boolean Screen::init()
    {
            Serial.println("Screen - Online");
            
           
            //display.drawBitmap(0,0,custom_start_bmp, 128, 64, SSD1306_WHITE);
            //display.drawPixel(10, 10, SSD1306_WHITE);

            return true;
    }

#endif