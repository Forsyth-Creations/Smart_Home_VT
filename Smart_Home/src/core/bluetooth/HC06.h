 /**
 * HC06.cpp - Foc pulling data from PhotoSensor
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * Open for public usage
 **/

#ifndef HC06_h
#define HC06_h
#include "core\pins.h"
#include "Arduino.h"
#include "HC06.h"

class HC06
{
  public:
    HC06();
    boolean init();
  private:

};

#endif