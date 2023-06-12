

void getSerial() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');  // Read the received data until newline character
    
    int delimiterIndices[3];  // Array to store delimiter indices
    int numDelimiters = 0;  // Variable to keep track of the number of delimiters found
    
    for (int i = 0; i < data.length(); i++) {
      if (data.charAt(i) == ',') {
        delimiterIndices[numDelimiters] = i;  // Store delimiter index
        numDelimiters++;
      }
    }
    
    if (numDelimiters == 3) {
      String sensor1Data = data.substring(0, delimiterIndices[0]);  // Extract Sensor 1 data
      String sensor2Data = data.substring(delimiterIndices[0] + 1, delimiterIndices[1]);  // Extract Sensor 2 data
      String sensor3Data = data.substring(delimiterIndices[1] + 1, delimiterIndices[2]);  // Extract Sensor 3 data
      String sensor4Data = data.substring(delimiterIndices[2] + 1);  // Extract Sensor 4 data
      
      param = sensor1Data.toInt();  // Convert Sensor 1 data to integer
      sensor = sensor2Data.toInt();  // Convert Sensor 2 data to integer
      relay = sensor3Data.toInt();  // Convert Sensor 3 data to integer
      led = sensor4Data.toInt();  // Convert Sensor 4 data to integer
      
      
      Serial.print("Received Sensor 1 value: ");
      Serial.println(param);
      Serial.print("Received Sensor 2 value: ");
      Serial.println(sensor);
      Serial.print("Received Sensor 3 value: ");
      Serial.println(relay);
      Serial.print("Received Sensor 4 value: ");
      Serial.println(led);
    }
  }
}
