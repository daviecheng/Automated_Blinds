# Automatic_Blind_Turner

## Summary
> esp8266 wakes up every hour from deep sleep and adjusts the blinds according to the weather.

Inspired by Kevin Darrah's trigboard OpenWeather Project "Clear Skies" in this video here: https://www.youtube.com/watch?v=cD4gDeQ5jBI

Project uses his code found here: http://kevindarrah.com/micro/Pusher/trigBoardOpenWeather.zip .Open the link in a new window and refresh to download.

## Parts Used
NodeMCU ESP8266: https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B081CSJV2V/ref=sr_1_3?dchild=1&keywords=nodemcu+esp8266&qid=1629910947&sr=8-3

MG90S Micro Servo Motor: https://www.amazon.com/gp/product/B094J11DX6/ref=ppx_yo_dt_b_asin_title_o03_s00?ie=UTF8&psc=1

> The servo motor is motified for continous rotation and I cut off the plastic for the screws on both ends.

3.7 Lithium Ion Polymer Battery 900mAH: https://www.aliexpress.com/item/4000748499000.html?spm=a2g0s.9042311.0.0.195e4c4d181NYJ

Lithium Battery Charging Board: https://www.amazon.com/gp/product/B00LTQU2RK/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1

## Setup
Setup an account with https://openweathermap.org/ to get your apikey.

Download this project's code and insert your apikey and zipcode.

Upload code to ESP8266 and open the Arduino serial monitor.

Connect your internet to "AutoConnectAP" and confirm the connection with the serial monitor.

The weather should now be displayed on the serial monitor.

Configure the weather conditions and delays to fit your needs.

> Note: A servo write delay for a blind position is sometimes inaccurate shifting slightly from the desired position.

Watch Kevin Darrah's OpenWeather project video https://www.youtube.com/watch?v=cD4gDeQ5jBI for code explanations.

## 3D Printed Parts
Download the STL files for the project and attach the servo motor as shown in the "Pictures and Video" folder.

The STL files are designed to fit the blinds I have with a D-shaped rod. 

## Wiring Schematic
<img src="https://user-images.githubusercontent.com/84931559/130838155-1e125730-844e-46c5-9714-86559cf0846a.JPG">
