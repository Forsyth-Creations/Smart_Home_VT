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

//-----------Include all necessary libraries for this project----------

//To-to: Ensure all libraries are being imported properly

  #ifdef HC06_ACTIVE
      //start bluetooth
      #include "core\bluetooth\HC06.h"
  #endif

  #ifdef WEATHER_STATION
      //weather station
      #include "core\humidity\Humidity.h"
      #include "core\temp\Temp.h"
  #endif

  #ifdef NIGHT_LIGHT
      //start night light
      #include "core\nightlight\NightLight.h"
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
#ifdef HC06_ACTIVE
    //start bluetooth
    HC06 _HC06;
#endif

#ifdef WEATHER_STATION
    //weather station
    Temp _Temp;
    Humidity _Humidity;
#endif

#ifdef NIGHT_LIGHT
    //start night light
    NightLight _Light;
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

  int _pin; //underscore is used for local variables


};

#endif