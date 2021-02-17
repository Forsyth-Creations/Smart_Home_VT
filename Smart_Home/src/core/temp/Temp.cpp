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
#include "Temp.h"

#ifdef WEATHER_STATION

    //init code
    Temp::Temp()
    {
        Temp(5000000); 
    }

    Temp::Temp(float bVal)
    {
         _bVal = bVal;   
    }

    boolean Temp::init()
    {
        Serial.println("Temp - Online");
    }

    float Temp::getTemp()
    {
        this.getTemp(500, 1000);
    }

    float Temp::getTemp(float r1, float r2)
    {
        //Formula:
        //      1
        // ------------
        // (ln(R1/R2)/B) + (1/R2)
        float B = _bVal;
        return 1/((log(r1/r2)/B + (1/r1)));
    }

#endif