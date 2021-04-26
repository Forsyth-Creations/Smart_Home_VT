 /**
 * HC05.cpp - Foc pulling data from PhotoSensor
 * This file was written by Henry Forsyth
 * Februrary 15, 2021
 * Open for public usage
 **/

#ifndef HC05_h
#define HC05_h
#include "core\pins.h"
#include "Arduino.h"
#include "HC05.h"
#include <SoftwareSerial.h>

#define MAX_COMMAND_LENGTH 100
#define ENDING_CHARACTER ';'

class HC05
{
  public:
    HC05();
    boolean init();
    boolean getSerialData();
    char* getFullCommand();
    void print(int val);
  private:
    char recvString[MAX_COMMAND_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    boolean commandReady = false;
    int index = 0;
    SoftwareSerial bluetooth;
};

#endif