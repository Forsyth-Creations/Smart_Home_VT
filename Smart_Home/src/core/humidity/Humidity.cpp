/**
 * 
 * This file was written by Henry Forsyth and Jack Michaud
 * March 26, 2021
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
#include "Humidity.h"

#ifdef HUMIDITY_SENSOR

//init code
Humidity::Humidity()
{
}

boolean Humidity::init()
{
    if (this->Active())
    {
        Serial.println("Humidity Sensor - Online");
    }
    else
    {
        Serial.println("Humidity Sensor Issue Detected");
    }
    return true;
}

int Humidity::getValue()
{
    int value = analogRead(humiditypin); //converts Analog to Digital
    int Humidity_Percent = (0.00155515 * pow(value, 2)) + 30;
    pinMode(6,OUTPUT);
    analogWrite(6,127);
    #ifdef DEBUG

if (value>0){
    if (value > 0 && value < 215)
    {
        Serial.print("The Humidity is about: ");
        Serial.print(Humidity_Percent);
        Serial.print("%");
        Serial.println("");
        //delay(1000);
    }
    else
    {
        Serial.println("Humidity too High. Please check your configuration");
        //delay(1000);
    }
}
    #endif

    return Humidity_Percent;
}

int Humidity::Active()
{
    int val = this->getValue();
    if (val >= 0 && val <= 100)
    {
        return true;
    }
    return false;
}

#endif