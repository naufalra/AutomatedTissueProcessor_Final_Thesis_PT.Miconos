// CONFIRMED WORKED 7/6/23

const int sensorPin = 0;  //The analog sensor is connected to analog pin 0 of the arduino

//ABCDEFG,dp REAL OG
const int numeral[10] = {
  B11111100,  //0
  B01100000,  //1
  B11011010,  //2
  B11110010,  //3
  B01100110,  //4
  B10110110,  //5
  B10111110,  //6
  B11100000,  //7
  B11111110,  //8
  B11110110,  //9
};

// //Modified
// const int numeral[10] = {
//   B11111110,  //0
//   B00000110,  //1
//   B01011011,  //2
//   B01001111,  //3
//   B01100110,  //4
//   B01101101,  //5
//   B01111110,  //6
//   B00000111,  //7
//   B01111111,  //8
//   B01110111,  //9
// };




//pins for decimal point and each segment
//dp, G, F, E, D, C, B, A
const int segmentPins[] = { 11, 9, 7, 13, 12, 10, 6, 8 };



const int numberofDigits = 2;

const int digitPins[numberofDigits] = { A2, A3 };  //digits 1, 2, 3, 4



// Pin Definitions
const int buttonIncreasePin = 4;
const int buttonDecreasePin = 3;

// Global Variables
int value = 50;                 // Current value
const int limitValueUp = 100;   // Desired limit value
const int limitValueDown = 50;  // Desired limit value

int savedValues[10];   // Array to store saved values
int currentIndex = 0;  // Current index in the savedValues array


//Sensor Setup
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 9

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);


  // for (int i = 0; i < 8; i++)
  //   pinMode(segmentPins[i], OUTPUT);  //set segment and DP pins to output

  //sets the digit pins as outputs
  for (int i = 0; i < numberofDigits; i++)
    pinMode(digitPins[i], OUTPUT);

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

  // Save the current value in the array
  savedValues[currentIndex] = value;

  // Increment the index
  currentIndex++;

  // Wrap around the index if it exceeds the array size
  if (currentIndex >= 10) {
    currentIndex = 0;
  }


  showNumber(savedValues);
  // Serial.println(savedValues);

  // getData();
}

void showNumber(int number) {
  if (number == 0)
    showDigit(0, numberofDigits - 1);  //display 0 in the rightmost digit
  else {
    for (int digit = numberofDigits - 1; digit >= 0; digit--) {
      if (number > 0) {
        showDigit(number % 10, digit);
        number = number / 10;
      }
    }
  }
}

//Displays given number on a 7-segment display at the given digit position
void showDigit(int number, int digit) {
  digitalWrite(digitPins[digit], HIGH);
  for (int segment = 1; segment < 8; segment++) {
    boolean isBitSet = bitRead(numeral[number], segment);

    isBitSet = !isBitSet;  //remove this line if common cathode display
    digitalWrite(segmentPins[segment], isBitSet);
  }
  delay(5);
  digitalWrite(digitPins[digit], HIGH);
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
