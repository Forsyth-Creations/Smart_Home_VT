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
#include "Humidity.h"

#ifdef HUMIDITY_SENSOR

    //init code
    Humidity::Humidity()
    {
    }

    boolean Humidity::init()
    {
    Serial.println("Humidity Sensor - Online");
    return true;
    }

    int Humidity::Active()
    {
    int value = analogRead(humiditypin); //converts Analog to Digital

    int Humidity_Percent = (0.00155515*pow(value,2))+30;

     if (value>0){
     if (value < 215){
         Serial.print("The Humidity is about: ");
         Serial.print(Humidity_Percent);
         Serial.print("%");
         Serial.println("");
         delay(1000);}
     
    else{
        Serial.println("Humidity to High");
         delay(1000);}
    }

    return Humidity_Percent;
    }
#endif