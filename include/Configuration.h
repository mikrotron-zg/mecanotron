/*
 * This file is part of Mecanotron project (https://github.com/mikrotron-zg/mecanotron)
 * developed by Mikrotron d.o.o. (http://mikrotron.hr). It contains global variables, 
 * settings and includes needed for multiple project modules.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. See the LICENSE file at the 
 * top-level directory of this distribution for details 
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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

    // Enums
    typedef enum { // enum values corespondent to HTML button ids
        STOP, 
        FORWARD_LEFT_DIAGONAL, CIRCLE_FRONT_COUNTERCLOCKWISE, CIRCLE_FRONT_CLOCKWISE, FORWARD_RIGHT_DIAGONAL,
        CIRCLE_LEFT_COUNTERCLOCKWISE, FORWARD, CIRCLE_RIGHT_CLOCKWISE,
        SIDEWAYS_LEFT, ROTATE_COUNTERCLOCKWISE, ROTATE_CLOCKWISE, SIDEWAYS_RIGHT,
        CIRCLE_LEFT_CLOCKWISE, REVERSE, CIRCLE_RIGHT_COUNTERCLOCKWISE,
        BACKWARD_LEFT_DIAGONAL, CIRCLE_BACK_CLOCKWISE, CIRCLE_BACK_COUNTERCLOCKWISE, BACKWARD_RIGHT_DIAGONAL
    } DriveCommand;

    // Global variables
    extern MecanumDrive drive;

    // Global functions
    void handleDriveCommand(int driveCommand);
#endif