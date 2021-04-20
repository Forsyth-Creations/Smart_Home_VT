 /**
 * light.cpp - 
 * This file was written by Jack Michaud
 * April 20, 2021
 * Open for public usage
 **/

#ifndef Lights_h
#define Lights_h
#include "core\pins.h"
#include "Arduino.h"
#include "lights.h"

class Lights
{
  public:
    Lights();
    boolean init();
    int ActivateLights();
  private:
    int _ledPin = LIGHTS_LED_PIN;
};

#endif