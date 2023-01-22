/*******************************************************************
 * This files contains global variables, settings and includes
 * needed for multiple project modules
 *******************************************************************/

#ifndef CONFIGURATION_H
    #define CONFIGURATION_H
    // Settings
    #define DEBUG_MODE // please read the instructions in include/Debug.h file

    // Global constants
    #define DELAY_LONG 5000 // in miliseconds
    #define DELAY_SHORT 250 // in miliseconds

    // Pin connections
    #define FRONT_LEFT_WHEEL_PIN_A 4 // front left wheel pin A
    #define FRONT_LEFT_WHEEL_PIN_B 2 // front left wheel pin B
    #define FRONT_RIGHT_WHEEL_PIN_A 33 // front right wheel pin A
    #define FRONT_RIGHT_WHEEL_PIN_B 32 // front right wheel pin B
    #define BACK_LEFT_WHEEL_PIN_A 17 // back left wheel pin A
    #define BACK_LEFT_WHEEL_PIN_B 16 // back left wheel pin B
    #define BACK_RIGHT_WHEEL_PIN_A 26 // back right wheel pin A
    #define BACK_RIGHT_WHEEL_PIN_B 25 // back right wheel pin B


    // Includes
    #include <SPIFFS.h>
    #include <ESPAsyncWebServer.h>
    #include "Debug.h"
    #include "MecanumDrive.h"

    // Global variables
    extern MecanumDrive drive;
#endif