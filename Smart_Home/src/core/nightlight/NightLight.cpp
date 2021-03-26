/**
 * NightLight.cpp - Foc pulling data from PhotoSensor
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
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
#include "NightLight.h"

#ifdef NIGHT_LIGHT

//init code

NightLight::NightLight()
{
}

boolean NightLight::init()
{
    Serial.println("Night Light - Online");
}

boolean NightLight::getSensorState() //default
{
    return getSensorState(200);
}

boolean NightLight::getSensorState(int threshold) //can feed it a threshold
{
    int value = analogRead(photoPin);
    boolean returnState = false; 

    #ifdef DEBUG
    Serial.println("The value from photoresistor: ");
    Serial.println(value);
    #endif

    returnState = (value >= 0 && value < threshold);

    #ifdef DEBUG
        Serial.print("ReturnState: ");
        Serial.println(returnState);
    #endif

    return returnState;
}

#endif
