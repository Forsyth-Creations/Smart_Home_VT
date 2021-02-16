 /**
 * Humidity.cpp - Foc pulling data from PhotoSensor
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * Open for public usage
 **/

#ifndef Humidity_h
#define Humidity_h
#include "core\pins.h"
#include "Arduino.h"
#include "Humidity.h"

class Humidity
{
  public:
    Humidity();
    boolean init();
  private:

};

#endif