 /**
 * Security.cpp - Foc pulling data from PhotoSensor
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * Open for public usage
 **/

#ifndef Security_h
#define Security_h
#include "core\pins.h"
#include "Arduino.h"
#include "Security.h"
#include <NewPing.h>

#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.


class Security
{
  public:
    Security();
    boolean init();
    int getDistance();
  private:
    NewPing *sonar;
};

#endif