# LED control from website


Turn an LED on or off from anywhere in the world from a website.
Main components:
1) Any Arduino
2) ESP8266 ESP-01 Wifi Module: https://techshopbd.com/product-categories/wifi/2583/esp8266-esp-01-wifi-module-techshop-bangladesh
3) LEDs and resistors

How it works?
1) A custom-built website contains a button, clicking on which changes a variable value from 1 to 0 and vice versa.
2) The Arduino connects to the ESP8266 using the SoftwareSerial library and sends a “GET” request to the web server to retrieve the state of the button on the website, either 1 or 0.
3) An LED connected to the Arduino is turned “ON” or “OFF” according to the value retrieved from the web server. 

ESP8266 ESP-01 Wifi module connections (connection diagram attached):

The ESP8266 wifi module runs on 3.3V, but the Arduino provides 5V. So, a voltage divider circuit had to be made to provide power and signal to the ESP8266 module. The TX of ESP8266 can be directly connected to the RX of Arduino, since it only transmits FROM the ESP8266, but the TX of Arduino must be connected to the RX of ESP8266 through a voltage divider circuit, using resistors.

For providing power to the ESP8266, a voltage regulator using LD1117V33 was used. It provides constant 3.3V, regardless of the input voltage (in this case it is an 9V battery). It should be noted here that, it could have been powered from the Arduino through the resistor-based voltage divider, but the Wifi module draws a lot of current, which cannot be provided by the Arduino. The connections are as follows:

ESP TX --> Arduino D10 (SoftwareSerial RX)

ESP RX --> voltage divider (resistor-based) --> Arduino D11 (SoftwareSerial TX)

ESP VCC & ESP CH_PD --> voltage divider (LD1117V33) --> Battery(+)

ESP GND --> Arduino GND and Battery(-)

AT commands have been used to configure and send and receive data using the ESP8266 module. Main configuration done was changing the default Baud Rate of the ESP8266 module to 9600, since SoftwareSerial library of Arduino misbehaves at higher Baud Rates. 


