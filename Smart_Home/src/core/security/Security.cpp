/**
 * 
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * 
 * 
 * The objective of this file is to
 * run the bluetooth chip for the project,
 * most likely utilizing the Serial communication
 * protocol to impact change on the device from the GUI
 * 
 * Functionality can be enabled in the "Configuration.h" file
 * Should debugging be needed, disable all other features and simply
 * enable the "DEBUG" variable. This will output appropriate unit testing values
 **/

// Note that there is a conflict with the Tone.cpp file
// (used for talkie) and the NewPing.cpp. I believe they
// overlap on the timers they use for interupts. Since Tone comes
// stock and NewPing is third parts, I am going to abandon NewPing and
// simply use the pulseIn feature of the Arduino
#include "Configuration.h"
#include "Security.h"
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define USPOWER_PIN 4

#ifdef SECURITY_SYSTEM

//init code
Security::Security()
{
}

boolean Security::init()
{
    Serial.println("Security System - Online");
    pinMode(USPOWER_PIN, OUTPUT);
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    digitalWrite(USPOWER_PIN, HIGH);
    return true;
}

int Security::getDistance()
{
    unsigned long duration;
    int distance;

    digitalWrite(TRIGGER_PIN, HIGH);
    delay(1);
    digitalWrite(TRIGGER_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH, 5700); // Timeout if distance > 100 cm

    distance = duration / 57; // Divide by round-trip microseconds per cm to get cm

    if (distance >= 200 || distance <= 0)
    {
        Serial.println("Out of range");
    } // Conversely, if you still get a false echo, you may need to increase
    return duration;
}

#endif