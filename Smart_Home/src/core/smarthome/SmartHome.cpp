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
#include "SmartHome.h"

//init code

SmartHome::SmartHome() //creates all the objects for relavant hardware (based on config file)
{
#ifdef HC06_ACTIVE
    //start bluetooth
#endif

#ifdef WEATHER_STATION
    //weather station
#endif

#ifdef NIGHT_LIGHT
    //start night light
    _Light = NightLight();
#endif

#ifdef ACTIVATE_OLCD
    //start OLCD
#endif

#ifdef SECURITY_SYSTEM
    //start ultrasonic
#endif

#ifdef SPEAKER
    //start speaker
#endif
}

boolean SmartHome::init() //runs a test script on each piece to make sure everything is moving slowly
{
#ifdef DEBUG

    //to-do: make sure all attributes of the projet (aka any requirements) are built out below
    //this #ifdef structure repeats a bunch, so may be wise to build out one and then copy-paste
    #ifdef HC06_ACTIVE
        //start bluetooth
        _HC06.init();
    #endif

    #ifdef ACTIVATE_OLCD
        //start OLCD
        _OLCD.init();
    #endif

    #ifdef SECURITY_SYSTEM
        //start ultrasonic
        _Security.init();
    #endif

    #ifdef NIGHT_LIGHT
        //start night light
        _Light.init();
    #endif

    #ifdef SPEAKER
        //start speaker
        _speaker.init();
    #endif

    Serial.println("\nSmart Home - DEBUG MODE ACTIVE");

#endif
    return true;
}

boolean SmartHome::run()
{
    //run the smart home from here. This is basically the new main
    //for this small project
    Serial.println("Running smart home");
    delay(4000);

    //check all appendages here. Should look like "nightlight.read()", or something like that. Make sure you only run what is defined

    //inact any actions here. Shoud look like "lights.on()", or something to that effect. Make sure you only run what is defined
}
