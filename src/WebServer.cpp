#include <WiFi.h>
#include <AsyncTCP.h>
#include <AsyncElegantOTA.h>
#include "Configuration.h"
#include "WebServer.h"

AsyncWebServer server(80);

/***********************************************************************
 *************************** HTTP handling *****************************
 ***********************************************************************/
void onRootRequest(AsyncWebServerRequest *request) {
  // Client root request
  IPAddress remote_ip = request->client()->remoteIP();
  DEBUG(remote_ip.toString()); DEBUG(" requested "); DEBUGLN(request->url());
  request->send(SPIFFS, "/index.html", "text/html"); // send back index page
}

void onJSrequest(AsyncWebServerRequest *request) {
  // Client JavaScript request
  IPAddress remote_ip = request->client()->remoteIP();
  DEBUG(remote_ip.toString()); DEBUG(" requested "); DEBUGLN(request->url());
  request->send(SPIFFS, "/mechanotron.js", "text/javascript"); // send back JS file
}

void onCSSRequest(AsyncWebServerRequest *request) {
  // Client CSS request
  IPAddress remote_ip = request->client()->remoteIP();
  DEBUG(remote_ip.toString()); DEBUG(" requested "); DEBUGLN(request->url());
  request->send(SPIFFS, "/bootstrap.min.css", "text/css"); // send back CSS file
}

void onCSSMapRequest(AsyncWebServerRequest *request) {
  // Client CSS request
  IPAddress remote_ip = request->client()->remoteIP();
  DEBUG(remote_ip.toString()); DEBUG(" requested "); DEBUGLN(request->url());
  request->send(SPIFFS, "/bootstrap.min.css.map", "text/css"); // send back CSS file
}

void onPageNotFound(AsyncWebServerRequest *request) {
  // Unknown request
  IPAddress remote_ip = request->client()->remoteIP();
  DEBUG(remote_ip.toString()); DEBUG(" requested "); DEBUGLN(request->url());
  request->send(404, "text/plain", "Page not found"); // send back 404
}

/***********************************************************************
 ***************************** Services ********************************
 ***********************************************************************/
void startAccessPoint() {
  // Start access point
  WiFi.softAP(AP_SSID, AP_PASSWORD);
  DEBUG("AP is running, ESP32 IP address: "); DEBUGLN(WiFi.softAPIP());
}

void startWebServer() {
  // Start web server
  startAccessPoint();

  // HTTP requests handling
  server.on("/", HTTP_GET, onRootRequest); // root request
  server.on("/slidertron.js", HTTP_GET, onJSrequest); //JavaScript request
  server.on("/bootstrap.min.css", HTTP_GET, onCSSRequest); // CSS request
  server.on("/bootstrap.min.css.map", HTTP_GET, onCSSMapRequest); // CSS map request
  server.onNotFound(onPageNotFound); // anything else

  AsyncElegantOTA.begin(&server);    // Start AsyncElegantOTA
  DEBUGLN("AsyncElegantOTA enabled");
  server.begin();
  DEBUGLN("HTTP server started");
}