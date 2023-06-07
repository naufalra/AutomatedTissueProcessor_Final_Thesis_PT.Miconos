const int relayPin = A4;
const int ledPin = A0;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, LOW);
  
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    if (command == '1') {
      digitalWrite(relayPin, HIGH);  // Turn on the relay
      Serial.println("Relay turned ON");
    } else if (command == '2') {
      digitalWrite(relayPin, LOW);   // Turn off the relay
      Serial.println("Relay turned OFF");
    } else if (command == '3') {
      digitalWrite(ledPin, HIGH);    // Turn on the LED
      Serial.println("LED turned ON");
    } else if (command == '4') {
      digitalWrite(ledPin, LOW);     // Turn off the LED
      Serial.println("LED turned OFF");
    }
  }
}
