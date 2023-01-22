#include <Arduino.h>
#include "Configuration.h"
#include "WebServer.h"
#include "WebSocketsCommunication.h"

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