/*******************************************************************
 * This files contains macros and debugging variables. If you want
 * to turn debug mode on, place the line
 * #define DEBUG_MODE
 * in file main.cpp before the include call for this file, i.e.
 * #include "Debug.h"
 * If you want to turn debug mode off, comment out or delete the
 * DEBUG_MODE definition line:
 * //#define DEBUG_MODE
 *******************************************************************/

#ifndef DEBUG_H
    #define DEBUG_H
    #ifdef DEBUG_MODE // debug development settings
        #warning "WARNING! Debug mode is enabled, disable for production!"
        // calls to DEBUG will be replaced with Serial.print command
        #define DEBUG(x) Serial.print(x)
        // calls to DEBUGLN will be replaced with Serial.println command
        #define DEBUGLN(x) Serial.println(x)
    #else // production settings
        // calls to DEBUG and DEBUGLN will be replaced with nothing
        #define DEBUG(x)
        #define DEBUGLN(x)
    #endif
#endif