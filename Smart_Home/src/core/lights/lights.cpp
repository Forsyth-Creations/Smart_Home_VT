/**
 * Light.cpp - 
 * This file was written by Jack Michaud
 * April 20, 2021
 * Open for public usage
 * 
 * The objective of this file is to 
 * write out all the code necessary for the night light
 * object, which will be directly referenced by the smart
 * home object. This logic will be critical
 * 
 * Functionality can be enabled in the "Configuration.h" file
 * Should debugging be needed, disable all other features and simply
 * enable the "DEBUG" variable. This will output appropriate unit testing values
 **/

#include "Arduino.h"
#include "Configuration.h"
#include "lights.h"

#ifdef LIGHTS

//init code

Lights::Lights()
{
}

boolean Lights::init()
{
    Serial.println("Lights - Online");
    return true;
}

int Lights::ActivateLights() //can feed it a threshold
{
    int returnState = 1; 

    #ifdef DEBUG
        Serial.print("ReturnState: ");
        Serial.println(returnState);
    #endif

    return returnState;
}

#endif

