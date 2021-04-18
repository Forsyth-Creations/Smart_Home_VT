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
    : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)
{
        //display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

boolean Screen::init()
{
        Serial.println("Screen - Online");
        display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
        return true;
}

void Screen::displayValues()
{
        //static Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
        //display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
        //Serial.println("Running LCD");
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("Humidity: ");
        display.setCursor(0, 10);
        display.print("Temperature: ");
        display.display();
}

#endif