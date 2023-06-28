unsigned long previousMillis = 0;     // Variable to store the previous timestamp
const unsigned long interval = 100;  // Interval in milliseconds between data retrievals

void getData() {
  unsigned long currentMillis = millis();  // Get the current timestamp

  if (currentMillis - previousMillis >= interval) {  // Check if the interval has passed
    previousMillis = currentMillis;                  // Update the previous timestamp

    sensors.requestTemperatures();      // Send the command to get temperatures
    temp = sensors.getTempCByIndex(0);  // Get the temperature from the first sensor
    //    Serial.println(temp);
  }
}

void sensorTest() {
  unsigned long currentMillis = millis();  // Get the current timestamp

  if (currentMillis - previousMillis >= interval) {  // Check if the interval has passed
    previousMillis = currentMillis;                  // Update the previous timestamp

    sensors.requestTemperatures();      // Send the command to get temperatures
    temp = sensors.getTempCByIndex(0);  // Get the temperature from the first sensor
    Serial.println(temp);
  }
}
