void initiate() {
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
