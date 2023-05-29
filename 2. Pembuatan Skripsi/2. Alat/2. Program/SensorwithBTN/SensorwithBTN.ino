// Pin Definitions
const int buttonIncreasePin = A2;
const int buttonDecreasePin = A4;

// Global Variables
int value = 50;                 // Current value
const int limitValueUp = 100;   // Desired limit value
const int limitValueDown = 50;  // Desired limit value

//Sensor Setup
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS A5

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  sensors.begin();

  // Set pin modes for buttons
  pinMode(buttonIncreasePin, INPUT);
  pinMode(buttonDecreasePin, INPUT);

  Serial.print("Current Temp: ");
  Serial.println(value);
  Serial.println("======= Initializing ======");
}

void loop() {
  // Check if the increase button is pressed
  if (digitalRead(buttonIncreasePin) == HIGH) {
    increaseValue();
    delay(200);  // Debounce delay
  }

  // Check if the decrease button is pressed
  if (digitalRead(buttonDecreasePin) == HIGH) {
    decreaseValue();
    delay(200);  // Debounce delay
  }

  getData();
}

void increaseValue() {
  value += 5;
  if (value > limitValueUp) {
    value = limitValueUp;  // Set the value to the limit
  }
  Serial.println("Increased value: " + String(value));
}

void decreaseValue() {
  value -= 5;
  if (value < limitValueDown) {
    value = limitValueDown;  // Set the value to the limit
  }
  Serial.println("Decreased value: " + String(value));
}

void getData() {
  sensors.requestTemperatures();  // Send the command to get temperatures
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);
  Serial.println(tempC);
}
