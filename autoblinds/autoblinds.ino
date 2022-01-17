/* Automatic Blind Turner Project
 *  8/24/2021   David Cheng
 *  Description: ESP8266 hourly checks weather with WiFi
 *               and adjusts blind position accordingly.
 *                          
 *  Inspired by Kevin Darrah's trigBoard OpenWeather Project "Clear Skies"
 *  http://kevindarrah.com/micro/Pusher/trigBoardOpenWeather.zip
 */


// Includes - may not all be needed
#include <FS.h>                   //this needs to be first, or it all crashes and burns...
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>          //https://github.com/bblanchon/ArduinoJson
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <EEPROM.h>
#include <Servo.h>

Servo myservo;

// PINS
#define SERVO_PIN 5
#define D0 16

// FUNCTIONS
void readFile();
void getWeather();
void saveConfigCallback();
boolean WiFiConnection();
void adjustServo();

//globals for credentials
char zipCode[10]= "yourzip";
char apiKey[40] = "yourapi";

String weatherCondition = "";
char timeOfDay;

//flag for saving data
bool shouldSaveConfig = false;

void setup()
{
  Serial.begin(115200); //debug
  pinMode(D0, WAKEUP_PULLUP); // connect D0 to RST to wake up
  
  Serial.println("Checking weather");
  readFile(); // variables we want to store
  WiFiConnection(); // get wifi connection
  getWeather();
  adjustServo();
  Serial.println("Going to deep sleep for 1 hr");
  ESP.deepSleep(36e8);  // deep sleep for 1 hr
//  ESP.deepSleep(3e7); // deep sleep for 30 seconds (debug)

}

void loop(){
}
