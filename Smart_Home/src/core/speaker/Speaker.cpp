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
#include "Speaker.h"
#include "Talkie.h"
//#include "Words.h"

#ifdef SPEAKER

    //init code
    Speaker::Speaker()
    {
        pinMode(SPEAKER_PIN, OUTPUT);
    }

    boolean Speaker::init()
    {
        Serial.println("Speaker - Online");
        voice.say(spt_HELLO);   
        voice.say(spt_I); 
        voice.say(spt_AM); 
        voice.say(READY_TO_START);  
        return true;
    }

    void Speaker::sayIntruderAlert()
    {
        voice.say(spINTRUDER);
        voice.say(spALERT);
    }


#endif