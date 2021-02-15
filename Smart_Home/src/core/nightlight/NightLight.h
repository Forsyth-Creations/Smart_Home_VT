 /**
 * NightLight.cpp - Foc pulling data from PhotoSensor
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * Open for public usage
 **/

#ifndef NightLight_h
#define NightLight_h
#include "core\pins.h"
#include "Arduino.h"

class NightLight
{
  public:
    NightLight();
  private:
    int _pin = photoPin;
};

#endif