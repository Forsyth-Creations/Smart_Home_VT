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
#include "HC05.h"

#ifdef HC05_ACTIVE

//init code
HC05::HC05()
    : bluetooth(SOFTWARE_SERIAL_RX, SOFTWARE_SERIAL_TX)
{
}

boolean HC05::init()
{
    // if (bluetooth.available())
    // {
    Serial.println("HC05 - Online");
    // }
    // else
    // {
    // Serial.println("HC05 - Offline");
    // }
    bluetooth.begin(9600);
    commandReady = false;
    delay(1000);
    bluetooth.println("Active BlooToof");

    return true;
}

void HC05::print(int val)
{
    bluetooth.println(val);
}

boolean HC05::getSerialData()
{
    // Serial.println("Getting Bluetooth Data");
    if (bluetooth.available())
    {
        char chRecv = bluetooth.read();
        if (chRecv != ENDING_CHARACTER)
        {
            recvString[index] = chRecv;
#ifdef DEBUG
            Serial.print(chRecv);
#endif
            index++;
            //build out command string
        }
        else //ending character found
        {
            recvString[index] = '\0';
            commandReady = true;
            int i = 0;
            for (i = 0; i < index; i++)
                command[i] = recvString[i];
            command[i] = '\0';

            memset(recvString, '\0', strlen(recvString));
            memset(command, '\0', strlen(recvString));
#ifdef DEBUG
            Serial.println("");
            Serial.println("Full command found. The command is:");
            Serial.println(command);
#endif

            index = 0;
        }
    }
    return true;
}

// note: you can only retrieve the full command once
// make it count!!
char *HC05::getFullCommand()
{
    if (commandReady)
    {
        commandReady = false;
        //----------------------------- Remove Spaces ------------------------------------
        int len = strlen(command);
        for (int i = 0; i < len; i++)
        {
            if (command[i] == ' ')
            {
                for (int j = i; j < len; j++)
                    command[j] = command[j + 1];
                len--;
            }
        }
            //---------------------------------------------------------------------------------
            return command;
        }
        else
        {
            return NULL;
        }
    }

#endif