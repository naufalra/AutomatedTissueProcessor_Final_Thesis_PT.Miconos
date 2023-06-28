
//unsigned long mulaitimer = 0;     // Variable to store the previous timestamp
//const unsigned long waktukirim = 500;  // Interval in milliseconds between data retrievals

//void serialDebug() //THIS WORKED
//{
//  //  Serial.print(251);
//  Serial.print(parameter);
//  Serial.print(",");
//  Serial.print(temp);
//  Serial.print(",");
//  Serial.print(relaystate);
//  Serial.print(",");
//  Serial.println(ledstate);
//  //  Serial.println(252);
//}

void serialDebug() //THIS TRIAL
{
  //  Serial.print(251);
  Serial.print(parameter);
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.print(relaystate);
  Serial.print(",");
  Serial.print(ledstate);
  Serial.print(",");
  Serial.print(valKp);
  Serial.print(",");
  Serial.print(valKi);
  Serial.print(",");
  Serial.println(valKd);
  //  Serial.println(252);
}

void sendtoSlave() //THIS WORKED
{


  Serial.print(parameter);
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.print(relaystate);
  Serial.print(",");
  Serial.println(ledstate);

  //  sevseg.setNumber(parameter, 0);
  //  Serial.println(parameter);
  //  sevseg.refreshDisplay();  // Must run repeatedly
}

void sendtoSlavePID() //THIS WORKED
{
  //  getData();
  //  manualOverrideRelay();

  Serial.print(parameter);
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.print(relaystate);
  Serial.print(",");
  Serial.print(ledstate);
  Serial.print(",");
  Serial.print(Kp);
  Serial.print(",");
  Serial.print(Ki);
  Serial.print(",");
  Serial.println(Kd);

  //  unsigned long saatini = millis();  // Get the current timestamp
  //  if (saatini - mulaitimer >= waktukirim) {  // Check if the interval has passed
  //    mulaitimer = saatini;                  // Update the previous timestamp
  //    // Kirim data setiam 500ms
  //
  //  }

  //  sevseg.setNumber(parameter, 0);
  //  Serial.println(parameter);
  //  sevseg.refreshDisplay();  // Must run repeatedly
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
