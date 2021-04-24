//Activates the bluetooth functionality

/**
 * Here is the GCode scheme for pinging in the device from the GUI. It's a simple scheme that the finite
 * state machine uses for coordinating with the GUI.
 * 
 * Codes Avalible to GUI
 * G0: Get Data
 * G1: Send Data
 * G2: Enable Funcitonaliy (Presently Disabled, too little space on UNO)
 * G3: Disable Functionality (Presently Disabled, too little space on UNO)
 * 
 * Component Codes:
 * A0 - HC-06 Bluetooth
 * A1 - OLED
 * A2 - Ultrasonic
 * A3 - Night Light
 * A4 - Speaker
 * A5 - Temp 
 * A6 - Humidity
 * 
 * Now certianly one cannot set data for the Humidity, but one can send data to the 
 * as a message of what to display. What values dictate what behavior/what is shown
 * can be found within the finite state machine, written within the SmartHome.cpp file.
 * As for now, here is an example code of getting temp data. Ignore the spaces between the tokens
 * 
 * G0 A5;
 * 
 * Notice that a semicolon ends the line. This designates the end of a command
 * 
 **/


#define G0 //GUI calls this command to retrieve data
#define G1 //GUI calls this when it is attempting to send data. Typically a boolean for lighting and such. Each module only has one specific G1 command functionaliy

#ifdef HC05_ACTIVE
    #define A0
#endif

//Activates the OLCD functionality
#ifdef ACTIVATE_OLCD
    #define A1
#endif
//Activates the Ultrasonic functionality
#ifdef SECURITY_SYSTEM
    #define A2
#endif

//Activates the Night Light functionality, including sensor and lighting
#ifdef NIGHT_LIGHT
    #define A3
#endif

//Activates the Speaker functionality
#ifdef SPEAKER
    #define A4
#endif

#ifdef TEMP_SENSOR
    #define A5
#endif

#ifdef HUMIDITY_SENSOR
    #define A6
#endif