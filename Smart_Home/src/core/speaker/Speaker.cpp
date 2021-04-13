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
//#include "Words.h"

#ifdef SPEAKER

    //init code
    Speaker::Speaker()
    {
        pinMode(SPEAKER_PIN, OUTPUT);
        Talkie voice;
        _voice = &voice;
    }

    boolean Speaker::init()
    {
        Serial.println("Speaker - Online");
        (*_voice).say(spt_HELLO);   
        //_voice.say(spt_I); 
        //_voice.say(spt_AM); 
        //_voice.say(READY_TO_START);  
        return true;
    }

    void Speaker::sayIntruderAlert()
    {
        //_voice.say(spINTRUDER);
        //_voice.say(spALERT);
    }


#endif