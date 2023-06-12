#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "Grace";
const char* password = "yangkiri";

ESP8266WebServer server(80);

int param;  // Variable to store Sensor 1 value
int sensor;  // Variable to store Sensor 2 value
int relay;  // Variable to store Sensor 3 value
int led;  // Variable to store Sensor 4 value

String Param, Sensor, Relay, Led;

//String temp, hum;

void handleRoot() {
  server.send(200, "text/plain", "hello from esp8266!");
}



void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

unsigned long previousMillis = 0;     // Variable to store the previous timestamp
const unsigned long interval = 500;  // Interval in milliseconds between data retrievals

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  initWifi();
}

void loop() {
  // put your main code here, to run repeatedly:

  getSerial();
  server.handleClient();

  //  unsigned long currentMillis = millis();  // Get the current timestamp
  //
  //  if (currentMillis - previousMillis >= interval) {  // Check if the interval has passed
  //    previousMillis = currentMillis;                  // Update the previous timestamp
  //
  //    getSerial();
  //    server.handleClient();
  //  }
}
