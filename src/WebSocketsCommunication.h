/*******************************************************************
 * Handles WebSocket communication with and from client
 *******************************************************************/

#ifndef WEBSOCKETSCOMMUNICATION_H
    #define WEBSOCKETSCOMMUNICATION_H
    #define WS_PORT 1337    // ;-) web socket server port number
    #define WS_MSG_BUFFER_SIZE 10 // increase if needed

    // Includes
    #include <WebSocketsServer.h>

    extern WebSocketsServer ws_server;

    // Public functions
    void startWebSocketsServer();
    void onWebSocketEvent(uint8_t client_num, WStype_t type, uint8_t *payload, size_t length);
#endif