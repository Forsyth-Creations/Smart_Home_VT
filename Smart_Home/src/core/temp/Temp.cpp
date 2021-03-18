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
#include "Temp.h"

#ifdef TEMP_SENSOR

//init code
Temp::Temp()
{
}

boolean Temp::init(double bVal)
{
     _bVal = bVal;
    Serial.println("Temp - Online");
    return true;
}

boolean Temp::init(void)
{
    this->init(3949);
    return true;
}

double Temp::getTemp()
{
    return getTemp(9940);
}

double Temp::getTemp(double BALANCE_RESISTOR)
{
    //Formula:
    //      1
    // ------------
    // (ln(R1/R2)/B) + (1/R2)
    

    const int SAMPLE_NUMBER = 10;
    int adcSamples[SAMPLE_NUMBER]; 
    double adcAverage  = 0; 
    double rThermistor = 0;
    const double MAX_ADC = 1023.0;

    //----------------- Calculate Average Temp --------------------------------------
    for (int i = 0; i < SAMPLE_NUMBER; i++)
    {
        adcSamples[i] = analogRead(tempPin); // read from pin and store
        delay(10);                                 // wait 10 milliseconds
    }

    /* Then, we will simply average all of those samples up for a "stiffer"
     measurement. */

    for (int i = 0; i < SAMPLE_NUMBER; i++)
    {
        adcAverage += adcSamples[i]; // add all samples up . . .
    }
    adcAverage /= SAMPLE_NUMBER; // . . . average it w/ divide

    /* Here we calculate the thermistor’s resistance using the equation 
     discussed in the article. */
    rThermistor = BALANCE_RESISTOR * ((MAX_ADC / adcAverage) - 1);

    double tempRead =  ((_bVal * ROOM_TEMP) / (_bVal + (ROOM_TEMP * log(rThermistor / RESISTOR_ROOM_TEMP)))) - 273.15;

    #ifdef DEBUG
        Serial.print("The Temperature Reading is: ");
        Serial.println(tempRead);
    #endif

    return tempRead;
}

#endif