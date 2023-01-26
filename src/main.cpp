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