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
        if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
        {
                Serial.println("Screen - Offline");
        }
        else
        {
                Serial.println("Screen - Online");
        }

        const int LOGO_WIDTH = 128;
        const int LOGO_HEIGHT = 32;

        // 'undefined', 128x32pxdis
        static const unsigned char logo_bmp[] PROGMEM =
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
             0xff, 0xf8, 0x03, 0xf0, 0x3c, 0x01, 0x88, 0x00, 0x08, 0x0f, 0xc0, 0xe0, 0x1e, 0x70, 0x0f, 0x80,
             0xe0, 0x3e, 0x07, 0xf0, 0x3c, 0x07, 0x8e, 0x00, 0x38, 0x1f, 0xc0, 0xf0, 0x1e, 0x7c, 0x0f, 0x80,
             0xf0, 0x1e, 0x0f, 0xf8, 0x3c, 0x07, 0x8f, 0x80, 0xf8, 0x3f, 0xe0, 0xfc, 0x1e, 0x7f, 0x0f, 0x80,
             0xf0, 0x3e, 0x0f, 0x7c, 0x3c, 0x07, 0x8f, 0xe3, 0xf8, 0x3d, 0xe0, 0xff, 0x1e, 0x7f, 0xcf, 0x80,
             0xff, 0xfc, 0x1f, 0x3c, 0x3c, 0x07, 0x8f, 0xff, 0xf8, 0x78, 0xf0, 0xf7, 0xde, 0x7d, 0xef, 0x80,
             0xf8, 0x3e, 0x1e, 0x3e, 0x3c, 0x07, 0x8f, 0x3e, 0x78, 0xf8, 0xf8, 0xf1, 0xfe, 0x7c, 0x7f, 0x80,
             0xf0, 0x1e, 0x3f, 0xfe, 0x3e, 0x07, 0x8f, 0x18, 0x78, 0xff, 0xf8, 0xf0, 0x7e, 0x7c, 0x3f, 0x80,
             0xf8, 0x3e, 0x7f, 0xff, 0x1e, 0x0f, 0x8f, 0x00, 0x79, 0xff, 0xfc, 0xf0, 0x1e, 0x7c, 0x0f, 0x80,
             0xf3, 0xf8, 0x78, 0x0f, 0x8f, 0xfe, 0x0f, 0x00, 0x79, 0xe0, 0x3c, 0xf0, 0x0e, 0x7c, 0x03, 0x80,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x80,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x07, 0x80, 0x78, 0x00, 0x1f, 0xf0, 0x0f, 0xff, 0xc0, 0x3c, 0x03, 0xff, 0xf0, 0x00, 0x00,
             0x00, 0x07, 0x8f, 0xff, 0xc0, 0x3f, 0xff, 0x8f, 0xff, 0xc7, 0xff, 0xe3, 0xff, 0xf0, 0x00, 0x00,
             0x00, 0x07, 0x9f, 0x03, 0xc0, 0x3c, 0x07, 0xcf, 0x00, 0x0f, 0x81, 0xf0, 0x1e, 0x00, 0x00, 0x00,
             0x00, 0x07, 0x9f, 0x02, 0x00, 0x3e, 0x07, 0xcf, 0x00, 0x0f, 0x80, 0x00, 0x1e, 0x00, 0x00, 0x00,
             0x00, 0x07, 0x8f, 0xfe, 0x00, 0x3f, 0xff, 0x8f, 0xff, 0x87, 0xff, 0x00, 0x1e, 0x00, 0x00, 0x00,
             0x00, 0x07, 0x80, 0xff, 0xc0, 0x3f, 0xff, 0x8f, 0xff, 0x00, 0x7f, 0xe0, 0x1e, 0x00, 0x00, 0x00,
             0x00, 0x07, 0x82, 0x03, 0xc0, 0x3e, 0x07, 0xcf, 0x00, 0x01, 0x81, 0xf0, 0x1e, 0x00, 0x00, 0x00,
             0x00, 0x07, 0x9f, 0x03, 0xc0, 0x3e, 0x07, 0xcf, 0x00, 0x07, 0x81, 0xf0, 0x1e, 0x00, 0x00, 0x00,
             0x00, 0x07, 0x8f, 0xff, 0x80, 0x3e, 0xff, 0x8f, 0xff, 0x87, 0xff, 0xe0, 0x1e, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

        // 'Brander', 128x32px
        static const unsigned char myBitmap [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xfe, 0x7f, 0xdf, 0xf3, 0xfd, 0xe7, 0x7f, 0xdc, 0x70, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xfe, 0x7f, 0xdf, 0xf7, 0xf9, 0xe7, 0x7f, 0xdc, 0x70, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xc0, 0x73, 0xdc, 0xf7, 0x81, 0xe7, 0x0f, 0x1c, 0x70, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xc0, 0x71, 0xdc, 0x77, 0x81, 0xe7, 0x0e, 0x1c, 0x70, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xfc, 0x71, 0xdc, 0x77, 0xfd, 0xff, 0x0e, 0x1f, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xfc, 0x71, 0xdf, 0xf3, 0xfc, 0xff, 0x0e, 0x1f, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xc0, 0x71, 0xdf, 0xc0, 0x1c, 0x38, 0x0e, 0x1c, 0x70, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xc0, 0x71, 0xdd, 0xc0, 0x1c, 0x38, 0x0e, 0x1c, 0x70, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xc0, 0x7f, 0xdd, 0xe1, 0xfc, 0x38, 0x0e, 0x1c, 0x70, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xc0, 0x7f, 0xdc, 0xf3, 0xfc, 0x38, 0x0e, 0x1c, 0x70, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xc0, 0x7f, 0x9c, 0xf3, 0xfc, 0x38, 0x0e, 0x1c, 0x70, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xff, 0x7f, 0x9f, 0xf0, 0x70, 0x7f, 0xdd, 0xfe, 0x7f, 0x9f, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xfe, 0x7f, 0x9f, 0xe0, 0xf8, 0x7f, 0xdd, 0xff, 0x7f, 0xdf, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xfe, 0x7f, 0x9f, 0xe0, 0xf8, 0x7f, 0x9d, 0xff, 0x7f, 0xdf, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xc0, 0x73, 0x9c, 0x00, 0xf8, 0x0e, 0x1d, 0xc7, 0x71, 0xdc, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xc0, 0x73, 0x9c, 0x01, 0xfc, 0x0e, 0x1d, 0xc7, 0x71, 0xdc, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xc0, 0x73, 0x9f, 0xc1, 0xfc, 0x0e, 0x1d, 0xc7, 0x71, 0xdf, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xc0, 0x7f, 0x9f, 0xc1, 0xde, 0x0e, 0x1d, 0xc7, 0x71, 0xcf, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xc0, 0x7f, 0x1c, 0x03, 0xde, 0x0e, 0x1d, 0xc7, 0x71, 0xc0, 0x70, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xc0, 0x77, 0x1c, 0x03, 0x8e, 0x0e, 0x1d, 0xc7, 0x71, 0xc0, 0x70, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xff, 0x77, 0x9f, 0xf7, 0xbf, 0x0e, 0x1d, 0xff, 0x71, 0xcf, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xfe, 0x73, 0xdf, 0xe7, 0xbf, 0x0e, 0x1d, 0xff, 0x71, 0xcf, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


        display.clearDisplay();
        display.drawBitmap((display.width() - LOGO_WIDTH) / 2, (display.height() - LOGO_HEIGHT) / 2, myBitmap, LOGO_WIDTH, LOGO_HEIGHT, 1);
        display.display(); //you must always update the screen with "display" to push the latest image

        delay(2000);

        return true;
}

void Screen::displayValues(int humVal, int tempVal)
{
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("Humidity: " + String(humVal));
        display.setCursor(0, 10);
        display.print("Temperature: " + String(tempVal));
        display.display();
}

void Screen::displayValues()
{
        displayValues(0, 0);
}


#endif