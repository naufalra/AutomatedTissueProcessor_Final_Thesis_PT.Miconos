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


// ========== PID =============
#include <PID_v1.h>
//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp = 2, Ki = 5, Kd = 1;
int valKp = Kp, valKi = Ki, valKd = Kd;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

int WindowSize = 5000;
unsigned long windowStartTime;
// ============================

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

unsigned long mulaitimer = 0;     // Variable to store the previous timestamp
const unsigned long waktukirim = 200;  // Interval in milliseconds between data retrievals

void setup() {
  Serial.begin(115200);
  initiate();
  PIDSetup();
}

void loop() {

  //  sensorTest();
  //heaterPID();


  manualOverrideRelay();



  unsigned long saatini = millis();  // Get the current timestamp
  if (saatini - mulaitimer >= waktukirim) {  // Check if the interval has passed
    mulaitimer = saatini;                  // Update the previous timestamp
    // Kirim data setiam 500ms
    //    sendtoSlavePID();
    serialDebug();
  }

  getData();

  sevseg.setNumber(parameter, 0);
  sevseg.refreshDisplay();  // Must run repeatedly
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
