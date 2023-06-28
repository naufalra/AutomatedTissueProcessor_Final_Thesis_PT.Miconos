
void getSerial() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');  // Read the received data until newline character

    int delimiterIndices[6];  // Array to store delimiter indices
    //    int delimiterIndices[6];  // Array to store delimiter indices
    int numDelimiters = 0;  // Variable to keep track of the number of delimiters found

    for (int i = 0; i < data.length(); i++) {
      if (data.charAt(i) == ',') {
        delimiterIndices[numDelimiters] = i;  // Store delimiter index
        numDelimiters++;
      }
    }

    if (numDelimiters == 6) {

      //      String sensor1Data = data.substring(0, delimiterIndices[0]);  // Extract Sensor 1 data
      //      String sensor2Data = data.substring(delimiterIndices[0] + 1, delimiterIndices[1]);  // Extract Sensor 2 data
      //      String sensor3Data = data.substring(delimiterIndices[1] + 1, delimiterIndices[2]);  // Extract Sensor 3 data
      //      String sensor4Data = data.substring(delimiterIndices[2] + 1);  // Extract Sensor 4 data


      String sensor1Data = data.substring(0, delimiterIndices[0]);      // Extract Sensor 1 data
      String sensor2Data = data.substring(delimiterIndices[0] + 1, delimiterIndices[1]);      // Extract Sensor 2 data
      String sensor3Data = data.substring(delimiterIndices[1] + 1, delimiterIndices[2]);      // Extract Sensor 3 data
      String sensor4Data = data.substring(delimiterIndices[2] + 1, delimiterIndices[3]);      // Extract Sensor 4 data
      String sensor5Data = data.substring(delimiterIndices[3] + 1, delimiterIndices[4]);      // Extract Sensor 5 data
      String sensor6Data = data.substring(delimiterIndices[4] + 1, delimiterIndices[5]);      // Extract Sensor 6 data
      String sensor7Data = data.substring(delimiterIndices[5] + 1);      // Extract Sensor 7 data


      param = sensor1Data.toInt();  // Convert Sensor 1 data to integer
      sensor = sensor2Data.toInt();  // Convert Sensor 2 data to integer
      relay = sensor3Data.toInt();  // Convert Sensor 3 data to integer
      led = sensor4Data.toInt();  // Convert Sensor 4 data to integer
      kp = sensor5Data.toInt();  // Convert Sensor 1 data to integer
      ki = sensor6Data.toInt();  // Convert Sensor 2 data to integer
      kd = sensor7Data.toInt();  // Convert Sensor 3 data to integer



      Serial.print("Received Sensor 1 value: ");
      Serial.println(param);
      Serial.print("Received Sensor 2 value: ");
      Serial.println(sensor);
      Serial.print("Received Sensor 3 value: ");
      Serial.println(relay);
      Serial.print("Received Sensor 4 value: ");
      Serial.println(led);
      Serial.print("Received Sensor 5 value: ");
      Serial.println(kp);
      Serial.print("Received Sensor 6 value: ");
      Serial.println(ki);
      Serial.print("Received Sensor 7 value: ");
      Serial.println(kd);
    }
  }
}


//void getSerial() {
//  if (Serial.available() > 0) {
//    String data = Serial.readStringUntil('\n');  // Read the received data until newline character
//
//    int delimiterIndices[4];  // Array to store delimiter indices
//    int numDelimiters = 0;  // Variable to keep track of the number of delimiters found
//
//    for (int i = 0; i < data.length(); i++) {
//      if (data.charAt(i) == ',') {
//        delimiterIndices[numDelimiters] = i;  // Store delimiter index
//        numDelimiters++;
//      }
//    }
//
//    if (numDelimiters == 3) {
//      String sensor1Data = data.substring(0, delimiterIndices[0]);  // Extract Sensor 1 data
//      String sensor2Data = data.substring(delimiterIndices[0] + 1, delimiterIndices[1]);  // Extract Sensor 2 data
//      String sensor3Data = data.substring(delimiterIndices[1] + 1, delimiterIndices[2]);  // Extract Sensor 3 data
//      String sensor4Data = data.substring(delimiterIndices[2] + 1), delimiterIndices[3];  // Extract Sensor 4 data
//      String sensor5Data = data.substring(delimiterIndices[3] + 1);  // Extract Sensor 5 data
//
//      param = sensor1Data.toInt();  // Convert Sensor 1 data to integer
//      sensor = sensor2Data.toInt();  // Convert Sensor 2 data to integer
//      relay = sensor3Data.toInt();  // Convert Sensor 3 data to integer
//      led = sensor4Data.toInt();  // Convert Sensor 4 data to integer
//      kp = sensor5Data.toInt();  // Convert Sensor 4 data to integer
//
//
//      Serial.print("Received Sensor 1 value: ");
//      Serial.println(param);
//      Serial.print("Received Sensor 2 value: ");
//      Serial.println(sensor);
//      Serial.print("Received Sensor 3 value: ");
//      Serial.println(relay);
//      Serial.print("Received Sensor 4 value: ");
//      Serial.println(led);
//      Serial.print("Received Sensor 5 value: ");
//      Serial.println(kp);
//    }
//  }
//}
