void getWeather() {
  //http://api.openweathermap.org/data/2.5/weather/?zip=yourzip,us&appid=yourkey

  const char* host = "api.openweathermap.org";
  const int httpsPort = 443;

  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  client.setInsecure();
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  String url = "http://api.openweathermap.org/data/2.5/weather/?zip=";
  url.concat(zipCode);
  url.concat(",us&appid=");
  url.concat(apiKey);
  Serial.println(url);
  client.print("GET " + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: ESP8266\r\n" +
               "Accept: application/json\r\n" +
               "Connection: close\r\n\r\n"
              );
  boolean gotHeaders = false;
  while (client.connected()) {
    String line = client.readStringUntil('\n');

    if (line == "\r") {
      Serial.println("headers received");
      gotHeaders = true;
      break;// does this really break the while loop?
    }
    yield();
  }
  if (gotHeaders) {
    String line = client.readStringUntil('\r');

    Serial.println(line);

    DynamicJsonDocument jsonBuffer(1024);

    auto root = deserializeJson(jsonBuffer, line);
 

    if (root) {  // originally "!root.success()"
      Serial.println("parseObject() failed");
      return;
    }
    weatherCondition = jsonBuffer["weather"][0]["main"].as<String>();
    timeOfDay = jsonBuffer["weather"][0]["icon"].as<String>().charAt(2);

    Serial.println(weatherCondition);
    Serial.println(timeOfDay);
  }
}
