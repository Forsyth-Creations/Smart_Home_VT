/**
 * This is the configuration file for the smart home system
 * Inspired by the Marlin Firmware setup, this page will act as a 
 * "settings" page of sorts. When a variable is defined,
 * that functionaliy will be acitve. You will also have the option
 * from this menu to enable debugging for various features,
 * which will be beyond helpful.
 * 
 * 
 * 
 * Written by Henry Forsyth, April 23, 2021 2:00 AM
 * */
 
//#define DEBUG

#define LIGHTWEIGHT //disables all unnecessary functionality to decrease size of program

//Activates the bluetooth functionality
#define HC05_ACTIVE

//Activates the OLCD functionality (about 40% of flash memory, shoot)
#define ACTIVATE_OLCD

//Activates the Ultrasonic functionality
#define SECURITY_SYSTEM

//Activates the Night Light functionality, including sensor and lighting
#define NIGHT_LIGHT

//Activates the Lights functionality, including sensor and lighting
#define LIGHTS

//Activates the Speaker functionality
#define SPEAKER

//Activates the temperature functionality
#define TEMP_SENSOR

//Activates the AC unit
#define AC_UNIT

///Activates the humidity functionality
#define HUMIDITY_SENSOR