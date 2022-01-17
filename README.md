# Automated Blinds

## Summary
> esp8266 hourly adjusts the blinds according to the current weather then goes back to deep sleep.

https://user-images.githubusercontent.com/84931559/130842516-919ab60b-0a5e-4cad-bdbc-19b171e53f98.mp4

Inspired by Kevin Darrah's trigboard OpenWeather Project "Clear Skies" in this video here: https://www.youtube.com/watch?v=cD4gDeQ5jBI

Project uses his code found here: http://kevindarrah.com/micro/Pusher/trigBoardOpenWeather.zip . Open the link in a new window and refresh to download.


## Setup
1. Setup an account with https://openweathermap.org/ to get your apikey.
2. Download project code and insert your apikey and zipcode.
3. Upload code to ESP8266 and open the Arduino serial monitor.
4. Connect your internet to "AutoConnectAP" and confirm the connection with the serial monitor.
5. The weather should now be displayed on the serial monitor.
6. Configure the weather conditions and delays to fit your needs.

> Note: I adjusted my servo motor adjusted for 360 rotation. Servo delay is used for different blind positions. Therefore, it can be slightly inaccurate at times.

Watch Kevin Darrah's OpenWeather project video https://www.youtube.com/watch?v=cD4gDeQ5jBI for code explanations.


## Wiring Schematic
<img src="https://user-images.githubusercontent.com/84931559/131257721-de98099c-e7d9-413c-b2f2-1179af0ac54d.JPG">
