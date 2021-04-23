 /**
 * HC06.cpp - Foc pulling data from PhotoSensor
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * Open for public usage
 **/

#ifndef HC06_h
#define HC06_h
#include "core\pins.h"
#include "Arduino.h"
#include "HC06.h"
#include <SoftwareSerial.h>

#define MAX_COMMAND_LENGTH 100
#define ENDING_CHARACTER ';'

class HC06
{
  public:
    HC06();
    boolean init();
    boolean getSerialData();
    char* getFullCommand();
  private:
    char recvString[MAX_COMMAND_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    boolean commandReady = false;
    int index = 0;
    SoftwareSerial bluetooth;
};

#endif