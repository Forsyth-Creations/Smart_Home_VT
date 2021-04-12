 /**
 * Humidity.cpp - Foc pulling data from PhotoSensor
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * Open for public usage
 **/

/**
 * Docs
 * https://www.digikey.com/en/products/detail/amphenol-advanced-sensors/HS12SP/4780894
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
    int getValue();
    int Active();
  private:
    int _sensorPin = HUMIDITY_PIN;
    //int _ledPin = HUMIDITY_LED_PIN;
};

#endif