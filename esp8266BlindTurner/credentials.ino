void readFile() {
  //read configuration from FS json
  Serial.println("mounting FS...");
  //SPIFFS.format();
  if (SPIFFS.begin()) {
    Serial.println("mounted file system");
    if (SPIFFS.exists("/config.json")) {
      //file exists, reading and loading
      Serial.println("reading config file");
      File configFile = SPIFFS.open("/config.json", "r");
      if (configFile) {
        Serial.println("opened config file");
        size_t size = configFile.size();
        // Allocate a buffer to store contents of the file.
        std::unique_ptr<char[]> buf(new char[size]);

        configFile.readBytes(buf.get(), size);
        DynamicJsonDocument jsonBuffer(1024);

        auto error = deserializeJson(jsonBuffer, buf.get());
        serializeJson(jsonBuffer, Serial);
        
        if (!error) { // originally "json.success()"
          Serial.println("\nparsed json");
          if (jsonBuffer.containsKey("zipCode") && jsonBuffer.containsKey("apiKey")) {
            strcpy(zipCode, jsonBuffer["zipCode"]);
            strcpy(apiKey, jsonBuffer["apiKey"]);
            Serial.println("\nkeys found - all good");
          }
          else {
            SPIFFS.format();
          }

        } else {
          Serial.println("failed to load json config");
        }
      }
    }
  } else {
    Serial.println("failed to mount FS");
  }
  //end read
}
