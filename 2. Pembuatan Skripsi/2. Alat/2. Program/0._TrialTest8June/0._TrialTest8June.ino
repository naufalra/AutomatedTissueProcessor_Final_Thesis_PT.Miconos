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
float temp;

// Pin Definitions
const int buttonIncreasePin = 4;
const int buttonDecreasePin = 3;
const int relayPin = A4;
const int ledPin = A0;

// Global Variables
int parameter = 55;                 // Current parameter
const int limitparameterUp = 90;    // Desired limit parameter
const int limitparameterDown = 50;  // Desired limit parameter

String str;

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonIncreasePin, INPUT);
  pinMode(buttonDecreasePin, INPUT);

  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, LOW);


  byte numDigits = 3;
  byte digitPins[] = { A1, A2, A3 };
  byte segmentPins[] = { 8, 6, 10, 12, 13, 7, 9, 11 };
  bool resistorsOnSegments = true;     // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE;  // See README.md for options
  bool updateWithDelays = false;       // Default 'false' is Recommended
  bool leadingZeros = false;           // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false;        // Use 'true' if your decimal point doesn't exist or isn't connected

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
               updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
}

void loop() {

  if (digitalRead(buttonIncreasePin) == HIGH) {
    increaseParameter();
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayPin, HIGH);  // Set output pin to HIGH
    delay(200);  // Debounce delay
  }

  // Check if the decrease button is pressed
  if (digitalRead(buttonDecreasePin) == HIGH) {
    decreaseParameter();
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayPin, LOW);  // Set output pin to HIGH
    delay(200);  // Debounce delay
  }
  digitalWrite(ledPin, LOW);


  // Check for serial input
  //  getSerialParam();
  //  relayControl();
  getData();
  //  sendSerial();

  sevseg.setNumber(temp, 2);
  //  Serial.println(parameter);
  sevseg.refreshDisplay();  // Must run repeatedly



  // This is code to display sensor parameter on seven segment
  // getData();
  // sevseg.setNumber(temp, 2);
  // Serial.println(temp);
  // sevseg.refreshDisplay();  // Must run repeatedly
}







/// END OF SEVEN SEGMENT///
void increaseParameter() {
  parameter += 5;
  if (parameter > limitparameterUp) {
    parameter = limitparameterUp;  // Set the parameter to the limit
  }
  Serial.println("Increased parameter: " + String(parameter));
}

void decreaseParameter() {
  parameter -= 5;
  if (parameter < limitparameterDown) {
    parameter = limitparameterDown;  // Set the parameter to the limit
  }
  Serial.println("Decreased parameter: " + String(parameter));
}

/// END OF PUSHBUTTON///

unsigned long previousMillis = 0;     // Variable to store the previous timestamp
const unsigned long interval = 2000;  // Interval in milliseconds between data retrievals


void getData() {
  unsigned long currentMillis = millis();  // Get the current timestamp

  if (currentMillis - previousMillis >= interval) {  // Check if the interval has passed
    previousMillis = currentMillis;                  // Update the previous timestamp

    sensors.requestTemperatures();      // Send the command to get temperatures
    temp = sensors.getTempCByIndex(0);  // Get the temperature from the first sensor
    Serial.println(temp);
  }
}

/// END OF Sensor///

void getSerialParam() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input == "parameter") {
      //      Serial.print("Enter new parameter: ");
      while (Serial.available() == 0) {
        // Wait for input
      }
      String newParameter = Serial.readStringUntil('\n');
      newParameter.trim();
      parameter = newParameter.toInt();
      //      Serial.print("Parameter set to: ");
      //      Serial.println(parameter);
    }
  }
}

void relayControl() {
  if (parameter < 60) {
    digitalWrite(relayPin, HIGH);  // Set output pin to HIGH
    //    Serial.println("Parameter is lower than 60");
  } else if (parameter > 80) {
    digitalWrite(relayPin, LOW);  // Set output pin to LOW
    //    Serial.println("Parameter is higher than 80");
  } else {
    //    Serial.println("Parameter is between 60 and 80");
  }
}

void sendSerial() {
  //  Serial.print(parameter);
  //  Serial.print(",");
  //  Serial.println(temp);
  str = String("Current Parameter= ") + String(parameter) + String(" Sensor Value= ") + String(temp);
  Serial.println(str);
}
