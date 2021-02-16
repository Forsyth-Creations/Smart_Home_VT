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
#include "Security.h"

#ifdef SECURITY_SYSTEM

    //init code
    Security::Security()
    {
            
    }

    boolean Security::init()
    {
            Serial.println("Security System - Online");
    }

#endif