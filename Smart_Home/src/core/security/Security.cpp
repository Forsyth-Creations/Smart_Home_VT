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

#include "Configuration.h"
#include "Security.h"
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define USPOWER_PIN 4

#ifdef SECURITY_SYSTEM

//init code
Security::Security()
{
    pinMode(USPOWER_PIN, OUTPUT);
    digitalWrite(USPOWER_PIN, HIGH);
}

boolean Security::init()
{
    Serial.println("Security System - Online");
}

int Security::getTemp()
{
    unsigned int cm = sonar.ping_cm();
    if (cm != 0)
    {
        Serial.print("Ping: ");
        Serial.print(cm); // Send ping, get distance in cm and print result (0 = outside set distance range)
        Serial.println("cm");
        delay(30); // Wait 30ms between pings (about 30 pings/sec). 29ms should be the shortest delay between pings.
    }
    if (cm <= 8 * 2.54 * 12 && cm != 0)
    {
        Serial.println("Intruder Alert");
    }
    if (cm == 0 && digitalRead(ECHO_PIN) == HIGH)
    {
        digitalWrite(USPOWER_PIN, LOW);
        delay(50);                       // 50 mS is the minimum Off time to get clean restart
        digitalWrite(USPOWER_PIN, HIGH); // Adjust this value if your sensors don't read after reset
        delay(60);                       // Some sensors throw out a very short false echo after timeout
        cm = sonar.ping_cm();                 // 5cm-10cm value.  If your sensors do not throw out
                                         // this false echo, you can get rid of this delay and ping after power HIGH
    }                                    // Conversely, if you still get a false echo, you may need to increase
    return cm;
}

#endif