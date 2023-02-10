#include "Configuration.h"
#include "WebSocketsCommunication.h"

WebSocketsServer ws_server = WebSocketsServer(WS_PORT);
uint8_t current_client = 0;  // client currently sending commands
typedef enum {
  MSG_STATUS = 's',
  MSG_POSITION = 'p'
} MessageType;

/***********************************************************************
 ************************** Events handling ****************************
 ***********************************************************************/
void sendMessage(char type, int value) {
  // Sends message currently in the message buffer to current client
  char msg_buf[WS_MSG_BUFFER_SIZE];
  sprintf(msg_buf, "%c:%d", type, value);
  DEBUG(current_client); DEBUG(" - sending message: "); DEBUGLN(msg_buf);
  ws_server.sendTXT(current_client, msg_buf);
}

void onWebSocketEvent(uint8_t client_num, WStype_t type, uint8_t *payload, size_t length) {
  // WebSocket message handler
  String clientIP = ws_server.remoteIP(client_num).toString();
  current_client = client_num;

  switch(type) {

    case WStype_CONNECTED: // new client connected
      DEBUG("New connection from "); DEBUGLN(clientIP);
      break;

    case WStype_DISCONNECTED: // client disconnected
      DEBUG(clientIP); DEBUGLN(" - disconnected");
      break;

    case WStype_TEXT: // client sent text message
      {
        String text = (char *)payload;
        DEBUG("Received: "); DEBUGLN(text);
        
        if (text.substring(0,3) == "btn") {
          // Handle drive buttons
          handleDriveCommand((text.substring(3)).toInt());
        } else if (text == "getStatus") {
          // send the current status
          sendMessage(MSG_STATUS, 0); // TODO we need status enum
        } else if (text == "wtest") {
          drive.wheelTest();
        } else if (text == "demo") {
          drive.demo();
        }
        break;
      }
    // Ignore any other case
    case WStype_BIN:
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
    default:
      break;
  }
}

/***********************************************************************
 ***************************** Services ********************************
 ***********************************************************************/
void startWebSocketsServer() {
  // Start WebSocket server
  ws_server.begin();
  ws_server.onEvent(onWebSocketEvent); // WebSocket callback
  DEBUGLN("Web socket server started");
}