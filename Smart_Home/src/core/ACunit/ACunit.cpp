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
#include "ACunit.h"

#ifdef AC_UNIT

//init code
ACunit::ACunit()
{
}

boolean ACunit::init()
{
    Serial.println("ACunit- Online");
    return true;
}

void ACunit::Activate_ACunit()
{
    if (90 > 80){ //to be changed
        digitalWrite(AC_UNIT_LED_PIN, HIGH);
    }
    else 
    {
        digitalWrite(AC_UNIT_LED_PIN, LOW);
    }

}

#endif