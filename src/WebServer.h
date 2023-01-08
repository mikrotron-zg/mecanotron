/*******************************************************************
 * Basic web server HTTP handling, needs files from data directory
 * to be uploaded to ESP32 SPIFFS in order to work properly
 *******************************************************************/

#ifndef WEBSERVER_H
    #define WEBSERVER_H
    #define HTTP_PORT         80    // web server will listen for HTTP requests on port 80

    #include "Credentials.h" // please read the instructions in include/CredentialsTemplate.h file
    // Public functions
    void startWebServer();
#endif