void adjustServo(){
  
  // Wear leveling to keep track of servo position
  EEPROM.begin(1);
  int prevMode = EEPROM.read(0);  

  int newMode;
  if(timeOfDay == 'd'){

    // Open fully for these conditions
    if(weatherCondition == "clear sky" || 
      weatherCondition == "few clouds" || 
      weatherCondition == "scattered clouds"){
      
      newMode = 2;
    }

    // Otherwise open halfway
    else{
      newMode = 1;
    }
  }

  // Close at night
  else{
      newMode = 0;
  }

  Serial.print("newMode: ");
  Serial.println(newMode);

  // Write to EEPROM memory only if mode is different
  if(prevMode != newMode) {
    Serial.println("Writing newMode to EEPROM memory");
    EEPROM.write(0, newMode); 
  }
  EEPROM.end();

  // Adjust servo position if needed
  myservo.attach(SERVO_PIN);
  for(int i = prevMode; i<newMode; i++){
    myservo.write(180);
    delay(300);
  }
  for(int i = newMode; i<prevMode; i++){
    myservo.write(0);
    delay(300); 
  }
  myservo.detach();
  
}
