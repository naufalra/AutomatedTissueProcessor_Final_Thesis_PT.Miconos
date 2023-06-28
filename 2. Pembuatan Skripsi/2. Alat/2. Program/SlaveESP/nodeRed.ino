//ESP8266WebServer server(80);

//void handleRoot() {
//  server.send(200, "text/plain", "hello from esp8266!");
//}
//
//
//
//void handleNotFound() {
//  String message = "File Not Found\n\n";
//  message += "URI: ";
//  message += server.uri();
//  message += "\nMethod: ";
//  message += (server.method() == HTTP_GET) ? "GET" : "POST";
//  message += "\nArguments: ";
//  message += server.args();
//  message += "\n";
//
//  for (uint8_t i = 0; i < server.args(); i++) {
//    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
//  }
//  server.send(404, "text/plain", message);
//}


void initWifi() {
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);

    Serial.print(".");
  }


  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot); // http://localIPAddress/

  // Parameter Server
  server.on("/parameter", []() // http://localIPAddress/parameter
  {
    //    int t = param;
    Param = String(param);
    server.send(200, "text/plain", Param);
  });

  //Sensor server
  server.on("/sensor", []()  // http://localIPAddress/sensor
  {
    //    int h = sensor;
    Sensor = String(sensor);
    server.send(200, "text/plain", Sensor);
  });

  // Relay Server
  server.on("/relay", []() // http://localIPAddress/relay
  {
    //    int t = param;
    Relay = String(relay);
    server.send(200, "text/plain", Relay);
  });

  //LED server
  server.on("/led", []()  // http://localIPAddress/led
  {
    //    int h = sensor;
    Led = String(led);
    server.send(200, "text/plain", Led);
  });




  //KP server
  server.on("/kp", []()  // http://localIPAddress/kp
  {
    //    int h = sensor;
    KP = String(kp);
    server.send(200, "text/plain", KP);
  });

  // KI Server
  server.on("/ki", []() // http://localIPAddress/ki
  {
    //    int t = param;
    KI = String(ki);
    server.send(200, "text/plain", KI);
  });

  //KD server
  server.on("/kd", []()  // http://localIPAddress/kd
  {
    //    int h = sensor;
    KD = String(kd);
    server.send(200, "text/plain", KD);
  });

  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}
