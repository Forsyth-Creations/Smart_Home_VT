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
  #endif

  #ifdef WEATHER_STATION
      //weather station
  #endif

  #ifdef NIGHT_LIGHT
      //start night light
      #include "core\nightlight\NightLight.h"
  #endif

  #ifdef ACTIVATE_OLCD
      //start OLCD
  #endif

  #ifdef SECURITY_SYSTEM
      //start ultrasonic
  #endif

  #ifdef SPEAKER
      //start speaker
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
  #endif

  #ifdef WEATHER_STATION

  #endif

  #ifdef NIGHT_LIGHT
      NightLight _Light;
      //start night light
  #endif

  #ifdef ACTIVATE_OLCD
      //start OLCD
  #endif

  #ifdef SECURITY_SYSTEM
      //start ultrasonic
  #endif

  #ifdef SPEAKER
      //start speaker
  #endif

  int _pin; //underscore is used for local variables


};

#endif