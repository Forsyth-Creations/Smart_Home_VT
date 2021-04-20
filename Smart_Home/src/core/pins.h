/**
 * pins.h -- Written by Henry Forsyth
 * February 15, 2021
 * Long file of pin define statements
 * in order to make our coding process seamless
 **/
#include "Arduino.h"

#define PHOTO_PIN A0
#define TEMP_PIN A1
#define HUMIDITY_PIN_READ A2
#define HUMIDITY_PIN_WRITE 6
#define SCREEN_SDA A4
#define SCREEN_SCL A5

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.

#define NIGHT_LIGHT_PIN 13
#define TEMP_LED_PIN 10
#define SPEAKER_PIN 3
#define LIGHTS_LED_PIN 11
#define AC_UNIT_LED_PIN 12

//#define HUMIDITY_LED_PIN 6
