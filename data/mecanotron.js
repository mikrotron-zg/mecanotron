/* JS component of web application needed to control UI
 * and hadle WebSocket communication
 * by Mikrotron d.o.o. 2023.
 */

// Global variables
var debug_mode = true; // Should be false for production
var url = "ws://192.168.4.1:1337/"; // ESP32 WebSocket server listens on port 1337 ;-)
var connectedToServer = false;      // Keep track if we're connected to WebSocket server
var systemStatus = "not connected"; // Keep track of the system status
var panels = [];                  // Store different control panels

// Use this function for initialization
function init() {
  writeLog("Application start");
  panelsToArray();
  wsConnect(url); // Connect to ESP32 websocket server
}

// Store panels in an array
function panelsToArray() {
  panels.push(document.getElementById("testDrive"));
  panels.push(document.getElementById("manualDrive"));
  panels.push(document.getElementById("assistedDrive"));
  panels.push(document.getElementById("autonomousDrive"));
  onDriveModeChange(1);
}

// Hide panel
function hidePanel(value) {
  value.style.display = "none";
}

// Call the init function as soon as the page loads
window.addEventListener("load", init, false);

// Write timestamped log to console
function writeLog(message) {
  if (debug_mode) { // Write to log only if in debug mode
    message = new Date().toLocaleString() + " - " + message;
    console.log(message);
  }
}

// On drive mode change
function onDriveModeChange(value) {
  writeLog("Selected value: " + value);
  panels.forEach(hidePanel); // hide all panels
  panels[value].style.display = "inline";
}

/*****************************************************************************
 ********************* WebSocket communication handling **********************
 *****************************************************************************/

// Connect to WebSocket server
function wsConnect(url) {
  websocket = new WebSocket(url);
  // Assign callbacks
  websocket.onopen = function(wsEvent) { wsOnOpen(wsEvent) };
  websocket.onclose = function(wsEvent) { wsOnClose(wsEvent) };
  websocket.onmessage = function(wsEvent) { wsOnMessage(wsEvent) };
  websocket.onerror = function(wsEvent) { wsOnError(wsEvent) };
}

// On WebSocket open wsEvent
function wsOnOpen(wsEvent) {
  connectedToServer = true;
  wsSendMessage("getStatus"); // Get status first
  writeLog("Connected to websocket server");
}

// On Websocket close wsEvent
function wsOnClose(wsEvent) {
  connectedToServer = false;
  setStatus(-1); // <0 will default to 'not connected'
  writeLog("Connection to websocket server closed");
}

// On WebSocket incoming message
function wsOnMessage(wsEvent) {
  var msg = wsEvent.data;
  writeLog("Message received: " + msg);
  // Parse received message
  switch(msg.slice(0,1)) {
    case "s": setStatus(parseInt(msg.slice(2))); break;
    default: writeLog("ERROR: Unknown message received"); 
  }
}

// On Websocket error
function wsOnError(wsEvent) {
  writeLog("ERROR: " + wsEvent.data);
}

// On drive button command
function doDrive(buttonId) {
  wsSendMessage(buttonId);
}

// On stop command
function doStop() {
  wsSendMessage("btn0");
}

// On wheel test command
function doWheelTest() {
  wsSendMessage("wtest");
}

// On demo command
function doDemo() {
  wsSendMessage("demo");
}

// Send message to WebSocket server
function wsSendMessage(message) {
  if (!connectedToServer) {
    writeLog("Not connected to server");
    return;
  }
  writeLog("Sending: " + message);
  websocket.send(message);
}

/*****************************************************************************
 ************************** HTML elements handling ***************************
 *****************************************************************************/

function setStatus(value) {
  switch(value) {
    case 0: systemStatus = "not initialized"; break;
    case 1: systemStatus = "initializing"; break;
    case 2: systemStatus = "idle"; break;
    case 3: systemStatus = "running"; break;
    default: systemStatus = "not connected";
  }
  document.getElementById("status").innerHTML = systemStatus;
}