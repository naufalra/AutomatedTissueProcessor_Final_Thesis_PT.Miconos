const int relayPin = A4;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    if (command == '1') {
      digitalWrite(relayPin, HIGH);  // Turn on the relay
      Serial.println("Relay turned ON");
    } else if (command == '0') {
      digitalWrite(relayPin, LOW);   // Turn off the relay
      Serial.println("Relay turned OFF");
    }
  }
}
