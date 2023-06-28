void otomatis() {
  if (digitalRead(buttonIncreasePin) == HIGH) {
    increaseParameter();
    digitalWrite(ledPin, HIGH);
    delay(50);  // Debounce delay
  }

  // Check if the decrease button is pressed
  if (digitalRead(buttonDecreasePin) == HIGH) {
    decreaseParameter();
    digitalWrite(ledPin, HIGH);
    delay(50);  // Debounce delay
  }
  digitalWrite(ledPin, LOW);

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


void manualOverrideRelay()
{
  if (digitalRead(buttonIncreasePin) == HIGH) {
    increaseParameter();
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayPin, HIGH);  // Set output pin to HIGH
    relaystate = 1;
    ledstate = 1;
    delay(100);  // Debounce delay
  }

  // Check if the decrease button is pressed
  if (digitalRead(buttonDecreasePin) == HIGH) {
    decreaseParameter();
    //    digitalWrite(ledPin, LOW);
    digitalWrite(relayPin, LOW);  // Set output pin to HIGH
    relaystate = 0;
    ledstate = 0;
    delay(100);  // Debounce delay
  }

  if (ledstate == 1) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }


  //  sevseg.setNumber(parameter, 0);
  //  //  Serial.println(parameter);
  //  sevseg.refreshDisplay();  // Must run repeatedly
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
