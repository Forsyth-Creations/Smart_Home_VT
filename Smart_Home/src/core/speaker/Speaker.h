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
#include "Words.h"
#include "Talkie.h"


class Speaker
{
  public:
    Speaker();
    boolean init();
    void sayIntruderAlert();
    void sayGreeting();
    void sayNumber(int number);
    void sayTheTempIs();
    void say(const uint8_t * aWordDataAddress);
  private:
};

#endif

// #if defined(__AVR_ATmega32U4__)
//     while (!Serial); //delay for Leonardo, but this loops forever for Maple Serial
// #endif
//     // Just to know which program is running on my Arduino
//     Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_TALKIE));

// //    voice.doNotUseUseInvertedOutput();
// #if defined(TEENSYDUINO)
//     pinMode(5, OUTPUT);
//     digitalWrite(5, HIGH); //Enable Amplified PROP shield
// #endif
//   pinMode(3, OUTPUT);