#include "SevSeg.h"
SevSeg sevseg;  //Instantiate a seven segment controller object

//Sensor Setup
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 5

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
int temp;

// Pin Definitions
const int buttonIncreasePin = 4;
const int buttonDecreasePin = 3;
const int relayPin = A4;
int relaystate;
int ledstate;
const int ledPin = A0;

// Global Variables
int parameter  = 50;                 // Current parameter
const int limitparameterUp = 90;    // Desired limit parameter
const int limitparameterDown = 50;  // Desired limit parameter

String str;


unsigned long previoussenddata = 0;
const long intervalsendserial = 500; // 2 seconds

void setup() {
  Serial.begin(115200);
  initiate();
}

void loop() {
  manualOverrideRelay();

  //  sendSerial(); // Call the function to send data via serial
  //  serialDebug();
  unsigned long currentMillis = millis();
  if (currentMillis - previoussenddata >= intervalsendserial) {
    previoussenddata = currentMillis; // Reset the timer

    getData();

    //    sendSerial(); // Call the function to send data via serial
    serialDebug();
  }
}


/// END OF SEVEN SEGMENT///
void increaseParameter() {
  parameter += 5;
  if (parameter > limitparameterUp) {
    parameter = limitparameterUp;  // Set the parameter to the limit
  }
  //  Serial.println("Increased parameter: " + String(parameter));
}

void decreaseParameter() {
  parameter -= 5;
  if (parameter < limitparameterDown) {
    parameter = limitparameterDown;  // Set the parameter to the limit
  }
  //  Serial.println("Decreased parameter: " + String(parameter));
}
