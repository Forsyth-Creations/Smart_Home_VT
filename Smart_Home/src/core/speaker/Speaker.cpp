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
    #ifndef LIGHTWEIGHT
    Serial.println("Speaker - Online");
    #endif
    return true;
}

void Speaker::sayGreeting()
{
    Talkie voice;
    //Serial.println("Saying Greeing");
    #ifndef LIGHTWEIGHT
    voice.say(spt_HELLO);
    voice.say(spt_I);
    voice.say(spt_AM);
    voice.say(READY_TO_START);
    #endif
    digitalWrite(SPEAKER_PIN, LOW);
}

void Speaker::sayIntruderAlert()
{
    Talkie voice;
    voice.say(spINTRUDER);
    voice.say(spALERT);
    digitalWrite(SPEAKER_PIN, LOW);
}


void Speaker::sayNumber(int number)
{
    #ifndef LIGHTWEIGHT

    //Zero to nine case
    Talkie voice;

    if (number >= 0 && number <= 19)
    {
        switch (number)
        {
        case 0:
            voice.say(sp3_ZERO);
            break;
        case 1:
            voice.say(sp3_ONE);
            break;
        case 2:
            voice.say(sp3_TWO);
            break;
        case 3:
            voice.say(sp3_THREE);
            break;
        case 4:
            voice.say(sp3_FOUR);
            break;
        case 5:
            voice.say(sp3_FIVE);
            break;
        case 6:
            voice.say(sp3_SIX);
            break;
        case 7:
            voice.say(sp3_SEVEN);
            break;
        case 8:
            voice.say(sp3_EIGHT);
            break;
        case 9:
            voice.say(sp3_NINE);
            break;
        case 10:
            voice.say(sp3_TEN);
            break;
        case 11:
            voice.say(sp3_ELEVEN);
            break;
        case 12:
            voice.say(sp3_TWELVE);
            break;
        case 13:
            voice.say(sp3_THIRTEEN);
            break;
        case 14:
            voice.say(sp3_FOURTEEN);
            break;
        case 15:
            voice.say(sp3_FIFTEEN);
            break;
        case 16:
            voice.say(sp3_SIXTEEN);
            break;
        case 17:
            voice.say(sp3_SEVENTEEN);
            break;
        case 18:
            voice.say(sp3_EIGHTEEN);
            break;
        case 19:
            voice.say(sp3_NINETEEN);
            break;
        }
    }
    if (number >= 20 && number <= 100)
    {
        int teen = number % 10;
        switch (number - teen)
        {
        case 20:
            voice.say(sp3_TWENTY);
            break;
        case 30:
            voice.say(sp3_THIRTY);
            break;
        case 40:
            voice.say(sp3_FOURTY);
            break;
        case 50:
            voice.say(sp3_FIFTY);
            break;
        case 60:
            voice.say(sp3_SIXTY);
            break;
        case 70:
            voice.say(sp3_SEVENTY);
            break;
        case 80:
            voice.say(sp3_EIGHTY);
            break;
        case 90:
            voice.say(sp3_NINETY);
            break;
        case 100:
            voice.say(sp3_HUNDRED);
            break;
        }
        if (teen != 0)
        {
            if (teen > 10)
            {
                voice.say(sp3_AND);
            }
            sayNumber(teen);
        }
    }
    #endif
}
void Speaker::sayTheTempIs()
{
    #ifndef LIGHTWEIGHT

    Talkie voice;
    voice.say(sp3_THE);
    voice.say(spTEMPERATURE);
    voice.say(sp3_IS);
    
    #endif
    //sayNumber(number);
}

void Speaker::say(const uint8_t * aWordDataAddress)
{
    Talkie voice;
    voice.say(aWordDataAddress);
}

#endif