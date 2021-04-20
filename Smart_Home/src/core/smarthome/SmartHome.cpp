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
    _HC06 = HC06();
#endif

#ifdef TEMP_SENSOR //weather station part 1
    _Temp = Temp();
#endif

#ifdef HUMIDITY_SENSOR //weather station part 2
    _Humidity = Humidity();
#endif

#ifdef NIGHT_LIGHT
    //start night light
    _Light = NightLight();
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
}

boolean SmartHome::init() //runs a test script on each piece to make sure everything is working correctly
{
#ifdef DEBUG
    Serial.println("\nSmart Home - DEBUG MODE ACTIVE\n");
//to-do: make sure all attributes of the projet (aka any requirements) are built out below
//this #ifdef structure repeats a bunch, so may be wise to build out one and then copy-paste
#endif

#ifdef HC06_ACTIVE
    //start bluetooth
    _HC06.init();
#endif

#ifdef TEMP_SENSOR
    //weather station
    _Temp.init();
#endif

#ifdef HUMIDITY_SENSOR
    _Humidity.init();
#endif

#ifdef NIGHT_LIGHT
    //start night light
    _Light.init();
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
    //_Speaker.sayGreeting();
#endif
    return true;
}

boolean SmartHome::run()
{
int humidityVal = 999;
int tempVal = 999;
    //if (Serial.available())
    // {
    //     //connected to GUI, be slave to it
    //     Serial.println("Connected to Serial");
    // }
    // else
    // {
    //     //run headless
    //     Serial.println("Running Headless");
    // }
    //delay(200);

#ifdef TEMP_SENSOR
    tempVal = _Temp.getTempF();
#endif



#ifdef NIGHT_LIGHT
    digitalWrite(NIGHT_LIGHT_PIN, _Light.getSensorState(100));
#endif

#ifdef HUMIDITY_SENSOR
    humidityVal = _Humidity.getValue();
    //digitalWrite(humidityLEDpin, _Humidity.init());
#endif

#ifdef ACTIVATE_OLCD
    _Screen.displayValues(humidityVal, tempVal);
#endif

#ifdef SPEAKER
   // _Speaker.sayTheTempIs(tempVal);
   _Speaker.sayIntruderAlert();
#endif

#ifdef DEBUG
    //Serial.println("----------------------------------------------");
#endif

    return true;

//check all appendages here. Should look like "nightlight.read()", or something like that. Make sure you only run what is defined
//inact any actions here. Shoud look like "lights.on()", or something to that effect. Make sure you only run what is defined
}



// boolean SmartHome::FSM()
// {
//     if (Serial.available())
//     {
//         _message = Serial.readString();
//         if (_message == NULL)
//         {
//             return false;
//         }
//         else
//         {
//             if (_message)
//         }

//     }
// }
