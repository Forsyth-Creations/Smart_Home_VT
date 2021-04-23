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
#include "HC06.h"

#ifdef HC06_ACTIVE

    //init code
    HC06::HC06()
        : bluetooth(SOFTWARE_SERIAL_RX, SOFTWARE_SERIAL_TX)
    {
            
    }

    boolean HC06::init()
    {
        // if (bluetooth.available())
        // {
        Serial.println("HC06 - Online");
        // }
        // else
        // {
        // Serial.println("HC06 - Offline");
        // }
        bluetooth.begin(9600);
        bluetooth.println("Active BlooToof");
        commandReady = false;
        return true;
    }

    boolean HC06::getSerialData()
    {
       // Serial.println("Getting Bluetooth Data");
        if(bluetooth.available())
        {
            char chRecv = bluetooth.read();
            if (chRecv != ENDING_CHARACTER)
            {
                recvString[index] = chRecv;
                Serial.print(chRecv);
                index++;
                //build out command string
            }
            else //ending character found
            {
                recvString[index] = '\0';
                commandReady = true;
                int i = 0;
                for(i = 0; i<index; i++)
                    command[i] = recvString[i];
                command[i] = '\0';

                memset(recvString, '\0', strlen(recvString));
                memset(command, '\0', strlen(recvString));
                Serial.println("");
                Serial.println("Full command found. The command is:");
                Serial.println(command);

                index = 0;
            }
        }
        return true;
    }

    // note: you can only retrieve the full command once
    // make it count!!
    char* HC06::getFullCommand()
    {
        if (commandReady)
        {
            commandReady = false;
            return command;
        }
        else
        {
            return NULL;
        }
    }

#endif