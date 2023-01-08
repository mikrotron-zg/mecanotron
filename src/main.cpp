#include <Arduino.h>
#include "Configuration.h"
#include "WebServer.h"

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
}

void loop() {
  // put your main code here, to run repeatedly:
}