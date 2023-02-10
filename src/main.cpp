/*
 * This file is part of Mecanotron project (https://github.com/mikrotron-zg/mecanotron)
 * developed by Mikrotron d.o.o. (http://mikrotron.hr)
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

#include <Arduino.h>
#include "Configuration.h"
#include "WebServer.h"
#include "WebSocketsCommunication.h"

// See Configuration.h for pin connection definitions
MecanumWheel wheels[] = {MecanumWheel(FRONT_LEFT_WHEEL_PIN_A, FRONT_LEFT_WHEEL_PIN_B), 
                         MecanumWheel(FRONT_RIGHT_WHEEL_PIN_A, FRONT_RIGHT_WHEEL_PIN_B),
                         MecanumWheel(BACK_LEFT_WHEEL_PIN_A, BACK_LEFT_WHEEL_PIN_B),
                         MecanumWheel(BACK_RIGHT_WHEEL_PIN_A, BACK_RIGHT_WHEEL_PIN_B)};

MecanumDrive drive (wheels);

/**
 * @brief Handles drive command received from controller.
 * 
 * @param driveCommand Enum value 0-18, 0 being stop command.
 */
void handleDriveCommand(int driveCommand) {
  DEBUG("Handeling drive command: "); DEBUGLN(driveCommand);
  drive.stop();
  delay(150);
  switch (driveCommand) {
    case STOP: break; // already stopped, do nothing
    case FORWARD_LEFT_DIAGONAL: drive.diagonal(false, true); break;
    case CIRCLE_FRONT_COUNTERCLOCKWISE: drive.angular(false, true); break;
    case CIRCLE_FRONT_CLOCKWISE: drive.angular(); break;
    case FORWARD_RIGHT_DIAGONAL: drive.diagonal();break;
    case CIRCLE_LEFT_COUNTERCLOCKWISE: drive.circle(false, true);break;
    case FORWARD: drive.forward(); break;
    case CIRCLE_RIGHT_CLOCKWISE: drive.circle();break;
    case SIDEWAYS_LEFT: drive.sideways(false);break;
    case ROTATE_CLOCKWISE: drive.rotate(); break;
    case ROTATE_COUNTERCLOCKWISE: drive.rotate(false); break;
    case SIDEWAYS_RIGHT: drive.sideways();break;
    case CIRCLE_LEFT_CLOCKWISE: drive.circle(false, false); break;
    case REVERSE: drive.reverse(); break;
    case CIRCLE_RIGHT_COUNTERCLOCKWISE: drive.circle(true, false); break;
    case BACKWARD_LEFT_DIAGONAL: drive.diagonal(true, false); break;
    case CIRCLE_BACK_CLOCKWISE: drive.angular(true, false); break;
    case CIRCLE_BACK_COUNTERCLOCKWISE: drive.angular(false, false); break;
    case BACKWARD_RIGHT_DIAGONAL: drive.diagonal(false, false); break;
    default: drive.stop();
  }
}

void setup() {
    // Program start
  #ifdef DEBUG_MODE
    // Enable serial if in debug mode
    Serial.begin(115200);
    delay(DELAY_LONG);
  #endif
  DEBUGLN("Debug mode: on");

  // Mount SPIFFS file system
  if(!SPIFFS.begin()){
    DEBUGLN("SPIFFS mounting error");
  }

  // Start servers
  delay(DELAY_SHORT);
  startWebServer();
  delay(DELAY_SHORT);
  startWebSocketsServer();
  delay(DELAY_SHORT);
}

void loop() {
  ws_server.loop(); // Wait for websocket data
}