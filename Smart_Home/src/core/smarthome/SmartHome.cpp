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
#ifdef HC05_ACTIVE
    //start bluetooth
    _HC05 = HC05();
#endif

#ifdef TEMP_SENSOR //weather station part 1
    _Temp = Temp();
#endif

#ifdef AC_UNIT
    _ACunit = ACunit();
#endif

#ifdef HUMIDITY_SENSOR //weather station part 2
    _Humidity = Humidity();
#endif

#ifdef NIGHT_LIGHT
    //start night light
    _Light = NightLight();
#endif

#ifdef LIGHTS
    //start lights
    _Lights = Lights();
#endif

#ifdef ACTIVATE_OLCD
    //start OLCD
    _Screen = Screen();
#endif

#ifdef SECURITY_SYSTEM
    //start ultrasonic
    _Security = Security();
#endif

#ifdef SPEAKER
    //start speaker
    _Speaker = Speaker();
#endif
    Serial.println("Running smart home");
    nightLightToggler = true;
    ultransonicToggler = false;
    speakTempToggler = false;
}

boolean SmartHome::init() //runs a test script on each piece to make sure everything is working correctly
{
    pinMode(TEMP_LED_PIN, OUTPUT);
#ifdef DEBUG
    Serial.println("\nSmart Home - DEBUG MODE ACTIVE\n");
//to-do: make sure all attributes of the projet (aka any requirements) are built out below
//this #ifdef structure repeats a bunch, so may be wise to build out one and then copy-paste
#endif

#ifdef HC05_ACTIVE
    //start bluetooth
    _HC05.init();
#endif

#ifdef TEMP_SENSOR
    //weather station
    _Temp.init();
#endif

#ifdef AC_UNIT
    _ACunit.init();
#endif

#ifdef HUMIDITY_SENSOR
    _Humidity.init();
#endif

#ifdef NIGHT_LIGHT
    //start night light
    _Light.init();
#endif

#ifdef LIGHTS
    //start night light
    _Lights.init();
#endif

#ifdef ACTIVATE_OLCD
    //start OLCD
    _Screen.init();
#endif

#ifdef SECURITY_SYSTEM
    //start ultrasonic
    _Security.init();
#endif

#ifdef SPEAKER
    //start speaker
    _Speaker.init();
    _Speaker.sayGreeting();
#endif
    return true;
}

boolean SmartHome::run()
{
    humidityVal = 999;
    tempVal = 999;

#ifdef TEMP_SENSOR
    boolean changed;
    tempVal = _Temp.getTempF();
#ifdef DEBUG
    //Serial.println("getTempValue is " + String(_Temp.getTempValue()) + " and getTemp is " + String(_Temp.getTempF()));
#endif
    changed = _Temp.getTempF() != _Temp.getTempValue();
    //changed = false;
#endif

#ifdef HUMIDITY_SENSOR
    humidityVal = _Humidity.getValue();
#endif

#ifdef HC05_ACTIVE
    _HC05.getSerialData();
    this->FSM();
#endif

#ifdef AC_UNIT
    _ACunit.Activate_ACunit();
#endif

#ifdef NIGHT_LIGHT
    if (nightLightToggler)
        digitalWrite(NIGHT_LIGHT_PIN, _Light.getSensorState(150) == true ? HIGH : LOW);
#endif

#ifdef LIGHTS
    digitalWrite(LIGHTS_LED_PIN, _Lights.ActivateLights());
#endif

#ifdef ACTIVATE_OLCD
    _Screen.displayValues(humidityVal, tempVal);
#endif

#ifdef SPEAKER

#endif

#if (defined SPEAKER && defined TEMP_SENSOR)
    if (changed && speakTempToggler)
    {
        _Temp.updateTempVal();
        _Speaker.sayTheTempIs();
        _Speaker.sayNumber(tempVal);
        _Speaker.say(sp3_DEGREES);
    }
    changed = false;
#endif

#if (defined SECURITY_SYSTEM && defined SPEAKER)
    if (_Security.isInDanger() && ultransonicToggler)
    {
        _Speaker.sayIntruderAlert();
    }
#endif

    return true;
    //check all appendages here. Should look like "nightlight.read()", or something like that. Make sure you only run what is defined
    //inact any actions here. Shoud look like "lights.on()", or something to that effect. Make sure you only run what is defined
}

#define COMMAND_LENGTH 4 //For simplicity, we are going to assume that every command sent is 8 characters long. This will help write the stripped-down FSM

boolean SmartHome::FSM() //only works for bluetooth module. Will extend functionality when get back some space on Uno
{
    int returnVal = false;
#ifdef HC05_ACTIVE

    char *command = _HC05.getFullCommand();

    if (command != NULL && strlen(command) == COMMAND_LENGTH || strlen(command) == COMMAND_LENGTH + 1)
    {
#ifdef DEBUG
        Serial.println("IN FSM");
        Serial.println(command);
#endif

        char firstCommand[] = {command[0], command[1], '\0'};
        char secondCommand[] = {command[2], command[3], '\0'};

#ifdef DEBUG
        Serial.println("First Command:" + String(firstCommand));
        Serial.println("Second Command:" + String(secondCommand));
#endif

        if (String(firstCommand) == "G0")
        {
#ifdef DEBUG
            Serial.println("G0 Found");
#endif
            //TODO: Temp and Humidity Grab Data
            if (String(secondCommand) == "A5") //Temp
            {
                Serial.println("Grabbing Temp");
                // _HC05.write(tempVal);
                _HC05.write(tempVal);
            }
            if (String(secondCommand) == "A6") //Humidity
            {
                Serial.println("Grabbing Humidity");
                _HC05.write(humidityVal);
            }
        }

        if (String(firstCommand) == "G1")
        {
            int thirdCommand = (int)command[4] - 48;
            //#ifdef DEBUG
            //Serial.println("G1 Found");
            //Serial.println(thirdCommand);
            //#endif
            if (String(secondCommand) == "A2") //Ultrasonic
            {
                ultransonicToggler = thirdCommand == 1 ? true : false;
                Serial.println("Toggling Ultrasonic");
            }

            if (String(secondCommand) == "A3") //Night Light
            {
                nightLightToggler = thirdCommand == 1 ? true : false;
                Serial.println("Toggling Night Light");
            }
            if (String(secondCommand) == "A5") //Temp Toggle
            {
                speakTempToggler = thirdCommand == 1 ? true : false;
                Serial.println("Toggling Temp");
            }
            if (String(secondCommand) == "A7") //Temp Toggle
            {
                digitalWrite(TEMP_LED_PIN, thirdCommand == 1 ? HIGH : LOW);
                Serial.println("Toggling Light");
            }
            // TODO : night light and secuirty system functionality needs to be toggled here
        }

        returnVal = true;
    }
#endif

    return returnVal;
}
