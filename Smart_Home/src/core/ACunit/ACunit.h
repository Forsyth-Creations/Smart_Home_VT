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
        //            1                 <---------- Numerator
        // ----------------------
        // (ln(R1/R2)/B) + (1/R2)       <---------- Denominator

// We have a thermistor with the XV designation, which has a nominal B-Constant of somewhere between
// 3900-3949K. Will need to investigate this further (Found on Page 4 of Documentation)

// R naught is the voltage divider resistor, R is the resistance of the thermistor

//https://www.allaboutcircuits.com/projects/measuring-temperature-with-an-ntc-thermistor/

#ifndef ACunit_h
#define ACunit_h
#include "core\pins.h"
#include "Arduino.h"
#include "ACunit.h"

class ACunit
{
  public:
   ACunit();
    boolean init();
    void Activate_ACunit();
  private:
    int _ACunitPin = AC_UNIT_LED_PIN;
};

#endif