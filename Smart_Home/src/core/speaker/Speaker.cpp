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
//#include <SoftwareSerial.h>

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
    //(*_voice).say(spt_HELLO);
    //_voice.say(spt_I);
    //_voice.say(spt_AM);
    //_voice.say(READY_TO_START);
    return true;
}

void Speaker::sayGreeting()
{
    static Talkie voice;
    //Serial.println("Saying Greeing");
    voice.say(spt_HELLO);
    voice.say(spt_I);
    voice.say(spt_AM);
    voice.say(READY_TO_START);
    digitalWrite(SPEAKER_PIN, LOW);
}

void Speaker::sayIntruderAlert()
{
    static Talkie voice;
    voice.say(spINTRUDER);
    voice.say(spALERT);
    digitalWrite(SPEAKER_PIN, LOW);
}

#endif