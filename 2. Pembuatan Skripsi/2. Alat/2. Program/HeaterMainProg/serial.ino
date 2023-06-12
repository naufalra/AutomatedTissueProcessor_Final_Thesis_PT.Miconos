void sendSerial() {
  Serial.write(251);
  Serial.write(parameter);
  Serial.write(temp);
  Serial.write(relaystate);
  Serial.write(ledstate);
  Serial.write(252);
}



void serialDebug() {
  //  Serial.print(251);
  Serial.print(parameter);
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.print(relaystate);
  Serial.print(",");
  Serial.println(ledstate);
  //  Serial.println(252);
}


void old() {
  //  Serial.print(parameter);
  //  Serial.print(",");
  //  Serial.println(temp);
  //  str = String(parameter) + String("*") + String(temp) + String("*") + String(relaystate) + String("*") + String(ledstate);
  //  str = String("coming from arduino: ") + String("H= ") + String(parameter) + String("T= ") + String(temp);
  //  Serial.print(parameter);  Serial.print("*");
  //  Serial.print(temp); Serial.print("*");
  //  Serial.print(relaystate);  Serial.print("*");
  //  Serial.print(ledstate); Serial.println("*");
  //  Serial.println(str);
  //  Serial.write("kontrlol");
}
void serialSetParameter() {
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
