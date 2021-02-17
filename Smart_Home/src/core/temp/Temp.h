 /**
 * Temp.cpp - Foc pulling data from PhotoSensor
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * Open for public usage
 **/

// Docs:
// https://www.murata.com/~/media/webrenewal/support/library/catalog/products/thermistor/ntc/r44e.ashx?la=en-us
// Please refer to page 7 for the equation for use. Equation should be as follows:
        //Formula:
        //      1
        // ------------
        // (ln(R1/R2)/B) + (1/R2)

#ifndef Temp_h
#define Temp_h
#include "core\pins.h"
#include "Arduino.h"
#include "Temp.h"

class Temp
{
  public:
    Temp();
    Temp(float bVal); //need B constant value for thermistor
    boolean init();
  private:
    int _tempPin;
    float _bVal;
};

#endif