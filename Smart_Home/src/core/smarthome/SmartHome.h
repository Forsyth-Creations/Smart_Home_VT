/**
 * SmartHome.cpp - For Running the entire system
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * Open for public usage
 **/

#ifndef SmartHome_h
#define SmartHome_h
#include "Arduino.h"
#include "Configuration.h"
#include "core\pins.h"
//#include <SoftwareSerial.h>

//-----------Include all necessary libraries for this project----------

//To-to: Ensure all libraries are being imported properly

#ifdef HC06_ACTIVE
//start bluetooth
#include "core\bluetooth\HC06.h"
#endif

#ifdef TEMP_SENSOR
//weather station
    #include "core\temp\Temp.h"
#endif

#ifdef HUMIDITY_SENSOR
    #include "core\humidity\Humidity.h" 
#endif

#ifdef NIGHT_LIGHT
//start night light
#include "core\nightlight\NightLight.h"
#endif

#ifdef LIGHTS
//start night light
#include "core\lights\Lights.h"
#endif

#ifdef ACTIVATE_OLCD
//start OLCD
#include "core\screen\Screen.h"
#endif

#ifdef SECURITY_SYSTEM
//start ultrasonic
#include "core\security\Security.h"
#endif

#ifdef SPEAKER
//start speaker
#include "core\speaker\Speaker.h"
#endif
//---------------------------------------------------------------------

class SmartHome
{
public:
    SmartHome();
    boolean init();
    boolean run();

    //To-do: create all the object declations alongside their
    //appropriate libraries

private:
boolean FSM();

#ifdef HC06_ACTIVE
    //start bluetooth
    HC06 _HC06;
#endif

#ifdef TEMP_SENSOR
    //weather station
    Temp _Temp;
#endif

#ifdef HUMIDITY_SENSOR
    Humidity _Humidity;
#endif

#ifdef NIGHT_LIGHT
    //start night light
    NightLight _Light;
#endif

#ifdef LIGHTS
    //start night light
    Lights _Lights;
#endif

#ifdef ACTIVATE_OLCD
    //start OLCD
    Screen _Screen;
#endif

#ifdef SECURITY_SYSTEM
    //start ultrasonic
    Security _Security;
#endif

#ifdef SPEAKER
    //start speaker
    Speaker _Speaker;

#endif
    
    String _message;

};
#endif