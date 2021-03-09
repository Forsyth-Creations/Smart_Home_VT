 /**
 * Speaker.cpp - Foc pulling data from PhotoSensor
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * Open for public usage
 **/

// Docs:
// https://www.ti.com/lit/ds/symlink/lm386.pdf?ts=1613454370752&ref_url=https%253A%252F%252Fwww.google.com%252F
// See page page 10, Figure 9.2.2

#ifndef Speaker_h
#define Speaker_h
#include "core\pins.h"
#include "Arduino.h"
#include "Speaker.h"

class Speaker
{
  public:
    Speaker();
    boolean init();
  private:
};

#endif